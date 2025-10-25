#!/bin/bash
echo "Введите путь до папки"
read FILE_PATH
echo "Введите строку которая будет заменяться (чувствительно к регистру)"
read STR_ORG
echo "Введите строку которая будет заменять (чувствительно к регистру)"
read STR_FUT

if [ -z "$FILE_PATH" ] || [ -z "$STR_ORG" ] || [ -z "$STR_ORG" ]; then
    echo "ошибка - пустые строки"
    exit 1
fi
if [ ! -d "$FILE_PATH" ] && [ ! -f "$FILE_PATH" ]; then
    echo "ошибка - указанный файл не файл и  не директория"
    exit 1
fi
if [ ! -f "$FILE_PATH" ]; then
    echo "ошибка - по данному пути файла нет"
    exit 1
fi
if [ ! -w "$FILE_PATH" ]; then
    echo "ошибка - нет прав на запись файла"
    exit 1
fi
if [ ! -s "$FILE_PATH" ]; then
    echo "ошибка - файл пустой"
    exit 1
fi
if [ ! -w "files.log" ]; then
    echo "ошибка нет прав записывать в лог-файл"
    exit 1
fi
sed -i '' "s|$STR_ORG|$STR_FUT|g" "$FILE_PATH"

s=$(stat -f "%z" "$FILE_PATH")
t=$(stat -f "%Sm" "$FILE_PATH")
h=$(shasum -a 256 "$FILE_PATH" | awk '{print $1}')

echo "$FILE_PATH - $s - $t - $h - SHA256" >> files.log
