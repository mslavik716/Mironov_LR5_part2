#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
//подключение модуля с тестируемыми методами
#include "Mironov_Task.h"

using namespace cute;

//тест, проверяющий отсев пустых значений
void testUserInput_Empty() {
    // исходные данные
    string str = "";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL (expected, actual);
}

//тест, проверяющий отсев нецифровых символов
void testUserInput_Letter () {
    // исходные данные
    string str = "a";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL (expected, actual);
}

//тест, проверяющий отсев отрицательных значений
void testUserInput_NegativeValue () {
    // исходные данные
    string str = "-5";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput (str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL (expected, actual);
}

//тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
    // исходные данные
    string str = "5a";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

//тест, проверяющий ввод символа
void testEnterChar() {
    // исходные данные
    char expected = 'a';

    // получение значения с помощью тестируемого метода
    char actual = EnterChar("Введите символ");

    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL (expected, actual);
}

//тест, проверяющий вывод символа и его кода ASCII
void testPrintCharAndASCII() {
    // исходные данные
    char ch = 'a';

    // получение значения с помощью тестируемого метода
    PrintCharAndASCII(ch);
}

//тест, проверяющий вывод суммы кодов ASCII символов
void testPrintSumOfASCII() {
    // исходные данные
    char ch1 = 'a';
    char ch2 = 'b';

    // получение значения с помощью тестируемого метода
    PrintSumOfASCII(ch1, ch2);
}

int main() {
    // Создаем тестовый набор
    suite s;

    // Добавляем тестовую функцию в набор
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));
    s.push_back(CUTE(testEnterChar));
    s.push_back(CUTE(testPrintCharAndASCII));
    s.push_back(CUTE(testPrintSumOfASCII));

    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener) (s, "All Char Tests");

    return 0;
}