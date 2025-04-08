#ifndef _MIRONOV_TASK_H_
#define _MIRONOV_TASK_H_

#include <string>
#include <iostream>
using namespace std;

bool UserInput(const std::string &input) {
    // Если строка пустая - ввод некорректен
    if (input.empty())
        return false;

    // Проверяем, состоит ли строка только из цифр
    for (char c : input) {
        if (!isdigit(c)) {
            return false; // Если есть хотя бы один нецифровой символ, возвращаем false
        }
    }

    // Попытаться преобразовать введенное значение в тип int
    try {
        int number = stoi(input);
        // Если введенное значение отрицательное - ввод некорректен
        if (number < 1)
            return false;
    } catch (...) { // Если возникла ошибка в блоке try
        return false;
    }

    return true; // Если все проверки пройдены, возвращаем true
}

//функция ввода символа
char EnterChar(const string& label) {
    char ch;
    cout << label << " = ";
    cin >> ch;
    return ch;
}

//функция вывода символа и его кода ASCII
void PrintCharAndASCII(char ch) {
    cout << "Символ: " << ch << ", Код ASCII: " << (int)ch << endl;
}

//функция вывода суммы кодов ASCII символов
void PrintSumOfASCII(char ch1, char ch2) {
    cout << "Сумма кодов ASCII символов: " << (int)ch1 + (int)ch2 << endl;
}

#endif