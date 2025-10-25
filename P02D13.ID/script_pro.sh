#!/bin/bash

# Массив для хранения скомпилированных файлов
compiled_files=()

# Функция для проверки утечек с таймаутом
check_leaks() {
    local exe="$1"
    local timeout=10 # Таймаут в секундах
    
    echo "Проверяю утечки для $exe..."
    
    # Запускаем leaks с таймаутом
    leaks_output=$(timeout $timeout leaks -atExit -- "$exe" 2>&1)
    
    if [ $? -eq 124 ]; then
        echo "Ошибка: проверка утечек для $exe превысила таймаут ($timeout секунд)"
        return 1
    fi
    
    if echo "$leaks_output" | grep -q "LEAK:"; then
        echo "Обнаружены утечки памяти в $exe!"
        echo "$leaks_output"
        return 1
    fi
    
    # Обработка предупреждений MallocStackLogging
    if echo "$leaks_output" | grep -q "MallocStackLogging"; then
        echo "Предупреждение: сообщения MallocStackLogging в $exe"
        echo "$leaks_output"
    fi
    return 0
}

# Копирование файла .clang-format
echo "Копирую .clang-format..."
cp materials/linters/.clang-format src/ || {
    echo "Ошибка: не удалось скопировать файл .clang-format"
    exit 1
}

# Проверка форматирования (только просмотр изменений)
echo "Проверка форматирования (просмотр)..."
clang-format -n src/*.c || {
    echo "Ошибка при проверке форматирования"
    exit 1
}

# Применение форматирования
echo "Применение форматирования..."
clang-format -i src/*.c || {
    echo "Ошибка при применении форматирования"
    exit 1
}

# Компиляция всех .c файлов
echo "Компиляция файлов..."
for file in src/*.c; do
    # Правильно получаем имя файла без расширения
    filename=$(basename "$file" .c)
    echo "Компилирую $filename..."
    gcc -Werror -Wextra -Wall -std=c11 -lncurses "$file" -o "src/$filename.out" || {
        echo "Ошибка компиляции файла $file:"
        echo "--------------------------------"
        gcc -Werror -Wextra -Wall -std=c11 -lncurses"$file" -o "src/$filename.out" 2>&1
        echo "--------------------------------"
        exit 1
    }
    compiled_files+=("src/$filename.out") # Добавляем в массив
done

# Удаление скопированного файла
echo "Удаляю .clang-format..."
rm src/.clang-format || {
    echo "Ошибка: не удалось удалить файл .clang-format"
    exit 1
}

# Запуск cppcheck
echo "Запуск cppcheck..."
cppcheck src/ || {
    echo "Ошибка при выполнении cppcheck"
    exit 1
}

# Проверка утечек памяти для всех исполняемых файлов
echo "Проверка утечек памяти..."
for exe in "${compiled_files[@]}"; do
    check_leaks "$exe" || {
        echo "Ошибка при проверке утечек в $exe"
        break
    }
done

# Гарантированное удаление скомпилированных файлов
trap 'rm -f "${compiled_files[@]}"' EXIT

echo "Все операции выполнены успешно!"
