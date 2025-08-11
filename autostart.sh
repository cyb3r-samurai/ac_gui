#!/bin/bash

MAX_RESTARTS=200  # Максимальное количество перезапусков
RESTART_DELAY=5  # Задержка перед перезапуском (секунды)
RESTARTS=0

while [ $RESTARTS -lt $MAX_RESTARTS ]; do
    echo "Запуск программы (попытка $((RESTARTS+1))/$MAX_RESTARTS)"
    ./build/Qt_6_4_2_qt6-Release/AC  # Замените на вашу программу

    EXIT_CODE=$?
    echo "Программа завершилась с кодом $EXIT_CODE"

    if [ $EXIT_CODE -eq 0 ]; then
        echo "Нормальное завершение. Выход."
        exit 0
    fi

    RESTARTS=$((RESTARTS+1))
    echo "Перезапуск через $RESTART_DELAY сек..."
    sleep $RESTART_DELAY
done

echo "Достигнуто максимальное количество перезапусков ($MAX_RESTARTS). Выход."
exit 1
