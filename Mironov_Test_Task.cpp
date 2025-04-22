#include "CUTE/cute/cute.h"
#include "CUTE/cute/cute_runner.h"
#include "CUTE/cute/cute_suite.h"
#include "CUTE/cute/cute_test.h"
#include "CUTE/cute/ide_listener.h"
//подключение модуля с тестируемыми методами
#include "Mironov_Task.h"

using namespace cute;

void testUserInput_Empty() {
  std::string str = "";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
  std::string str = "a";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_Negative() {
  std::string str = "-5";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_Valid() {
  std::string str = "10";
  bool expected = true;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testCountEven() {
  vector<int> nums{2, 3, 4};
  int expected = 2;
  int actual = CountEven(nums);
  ASSERT_EQUAL(expected, actual);
}

void testSumEven() {
  vector<int> nums{2, 3, 4};
  int expected = 6;
  int actual = SumEven(nums);
  ASSERT_EQUAL(expected, actual);
}

int main() {
  suite s;

  s.push_back(CUTE(testUserInput_Empty));
  s.push_back(CUTE(testUserInput_Letter));
  s.push_back(CUTE(testUserInput_Negative));
  s.push_back(CUTE(testUserInput_Valid));
  s.push_back(CUTE(testCountEven));
  s.push_back(CUTE(testSumEven));

  ide_listener<> listener;
  makeRunner(listener)(s, "All Even Task Tests");
  return 0;
}