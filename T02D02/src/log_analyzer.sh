#!/bin/bash

echo "Введите полный путь до файла"
read FILE_PATH
EX=$(basename "$FILE_PATH" | cut -d'.' -f2)

if [ -z "$FILE_PATH" ]; then
    echo "ошибка: путь к файлу не указан"
    exit 1
fi
if [ ! -f "$FILE_PATH" ]; then
    echo "ошибка: файл по указанному пути не существует"
    exit 1
fi
if [ ! -r "$FILE_PATH" ]; then
    echo "ошибка: нет прав на чтение файла"
    exit 1
fi
if [ ! -s "$FILE_PATH" ]; then
    echo "ошибка: файл пустой"
    exit 1
fi
if [ '$EX' != "log" ]; then
    echo "ошибка: файл не лог"
    exit 1
fi



COUNT_LINES=$(wc -l < "$FILE_PATH")
UNI=$(cut -d" " -f1 "$FILE_PATH" | sort | uniq | wc -l)
COUNT_HASH=$(awk -F' [-—] ' '$4 != "NULL" && $4 != "" {print $4}' "$FILE_PATH" | sort | uniq | wc -l)
echo $COUNT_LINES $UNI $COUNT_HASH
