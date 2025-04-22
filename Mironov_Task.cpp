#include <iostream>
#include "Mironov_Task.h"

using namespace std;

int main()
{
    char ch1, ch2;
    int choice;

    while (true) {
        cout << "1. Ввести первый символ" << endl;
        cout << "2. Ввести второй символ" << endl;
        cout << "3. Вывести каждый символ и его код ASCII" << endl;
        cout << "4. Вывести сумму кодов ASCII символов" << endl;
        cout << "5. Выход" << endl;
        if (!(cin >> choice)) {
            cout << "Неправильный ввод!" << endl;
            return 0;
        } else {
            switch (choice) {
                case 1:
                    ch1 = EnterChar("Введите первый символ");
                    break;
                case 2:
                    ch2 = EnterChar("Введите второй символ");
                    break;
                case 3:
                    PrintCharAndASCII(ch1);
                    PrintCharAndASCII(ch2);
                    break;
                case 4:
                    PrintSumOfASCII(ch1, ch2);
                    break;
                case 5:
                    return 0;
                default:
                    cout << "Неправильный ввод!" << endl;
                    return 0;
            }
        }
    }

    return 0;
}