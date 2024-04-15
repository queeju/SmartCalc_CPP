#include <gtest/gtest.h>

#include "src/controller/calcController.h"
#include "src/model/credModel.h"
#include "src/model/deposModel.h"

#define ACC 0.01
#define TOL 1e-13

TEST(ModelTest, Test_1) {
  std::string str = "2+3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_2) {
  std::string str = "-2+3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -2 + 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_3) {
  std::string str = "2-3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 - 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_4) {
  std::string str = "2+3*76";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + 3 * 76.0;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_5) {
  std::string str = "2+3*sin(0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + 3 * sin(0.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_6) {
  std::string str = "cos(1/3)+3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(1 / 3.0) + 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_7) {
  std::string str = "log(10)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(10);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_8) {
  std::string str = "ln(5) / 2 * 3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log(5) / 2.0 * 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_9) {
  std::string str = "2.5+3.7";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2.5 + 3.7;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_10) {
  std::string str = "6.8-3.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 6.8 - 3.2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_11) {
  std::string str = "4.2*2.3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4.2 * 2.3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_12) {
  std::string str = "9.6/3.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 9.6 / 3.2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_13) {
  std::string str = "1+3.5/7*2.1-23.98789798";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 1 + 3.5 / 7 * 2.1 - 23.98789798;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_14) {
  std::string str = "12.3-4.1*6.2/2+1.5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 12.3 - 4.1 * 6.2 / 2 + 1.5;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_15) {
  std::string str = "0.5*4.7-2.8/1.3+5.9-3.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 0.5 * 4.7 - 2.8 / 1.3 + 5.9 - 3.2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_16) {
  std::string str = "10.5/2.1-3.2*1.6+7.8/4.1-2.3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 10.5 / 2.1 - 3.2 * 1.6 + 7.8 / 4.1 - 2.3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_17) {
  std::string str = "9.4+3.7*2.1-5.6/1.4+8.2-6.9*3.3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 9.4 + 3.7 * 2.1 - 5.6 / 1.4 + 8.2 - 6.9 * 3.3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_18) {
  std::string str = "2-(5.234/8.124)+34234*(8.324-0.012341)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 - (5.234 / 8.124) + 34234 * (8.324 - 0.012341);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_19) {
  std::string str = "6.8+(3.2/(1.5-0.7))-4.9";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 6.8 + (3.2 / (1.5 - 0.7)) - 4.9;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_20) {
  std::string str = "2*(4.7-(1.8/(0.5+2.3)))+6.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * (4.7 - (1.8 / (0.5 + 2.3))) + 6.2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_21) {
  std::string str = "12.6-((3.1+1.2)*(2.5-0.9))/(5.3+2.4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 12.6 - ((3.1 + 1.2) * (2.5 - 0.9)) / (5.3 + 2.4);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_22) {
  std::string str = "(8.4+2.7)*(1.6-(3.9-1.1)/0.7)-5.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = (8.4 + 2.7) * (1.6 - (3.9 - 1.1) / 0.7) - 5.2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_23) {
  std::string str = "2^(3-1)+0.7235749*3^(1/2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(2, (3 - 1)) + 0.7235749 * pow(3, (1.0 / 2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_24) {
  std::string str = "4.5^(2-1)+1.2*2.5^(1/3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(4.5, (2 - 1)) + 1.2 * pow(2.5, (1.0 / 3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_25) {
  std::string str = "2.1^(3-2)+0.5*3.7^(1/4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(2.1, (3 - 2)) + 0.5 * pow(3.7, (1.0 / 4));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_26) {
  std::string str = "(1.5+0.7)^(4-2)-2.9*3.1^(1/3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow((1.5 + 0.7), (4 - 2)) - 2.9 * pow(3.1, (1.0 / 3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_27) {
  std::string str = "3.2^(2-1)-(1.8+0.3)*2.5^(1/2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(3.2, (2 - 1)) - (1.8 + 0.3) * pow(2.5, (1.0 / 2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_28) {
  std::string str = "4.5^(2-1)+1.2*2.5^(1/3) + 6 mod 5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(4.5, (2 - 1)) + 1.2 * pow(2.5, (1.0 / 3)) + fmod(6, 5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_29) {
  std::string str = "2.1^(3-2)+0.5*3.7^(1/4) + 9.8 mod 4.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = pow(2.1, (3 - 2)) + 0.5 * pow(3.7, (1.0 / 4)) + fmod(9.8, 4.2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_30) {
  std::string str = "(1.5+0.7)^(4-2)-2.9*3.1^(1/3) + 15.2 mod 6.4";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      pow((1.5 + 0.7), (4 - 2)) - 2.9 * pow(3.1, (1.0 / 3)) + fmod(15.2, 6.4);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_31) {
  std::string str = "3.2^(2-1)-(1.8+0.3)*2.5^(1/2) + 12.7 mod 3.9";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      pow(3.2, (2 - 1)) - (1.8 + 0.3) * pow(2.5, (1.0 / 2)) + fmod(12.7, 3.9);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_32) {
  std::string str = "5.9^(3-2)+(0.6+1.4)*2.7^(1/3) + 7.5 mod 3.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      pow(5.9, (3 - 2)) + (0.6 + 1.4) * pow(2.7, (1.0 / 3)) + fmod(7.5, 3.2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_33) {
  std::string str = "cos(0)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(0);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_34) {
  std::string str = "2 + cos(1.57)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + cos(1.57);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_35) {
  std::string str = "cos(3.14) - 1";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(3.14) - 1;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_36) {
  std::string str = "2 * cos(0.5) + 1.5 * cos(1.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * cos(0.5) + 1.5 * cos(1.2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_37) {
  std::string str = "cos(0.25) + cos(0.75) - cos(1.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(0.25) + cos(0.75) - cos(1.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_38) {
  std::string str = "sin(0)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = sin(0);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_39) {
  std::string str = "2 + sin(1.57)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + sin(1.57);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_40) {
  std::string str = "sin(3.14) - 1";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = sin(3.14) - 1;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_41) {
  std::string str = "2 * sin(0.5) + 1.5 * sin(1.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * sin(0.5) + 1.5 * sin(1.2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_42) {
  std::string str = "sin(0.25) + sin(0.75) - sin(1.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = sin(0.25) + sin(0.75) - sin(1.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_43) {
  std::string str =
      "tan(0.5) + 2 * sin(0.3) - 4 / cos(0.25) + 5.5 mod 3 ^ (1.2 + 0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      tan(0.5) + 2 * sin(0.3) - 4 / cos(0.25) + fmod(5.5, pow(3, 1.2 + 0.5));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_44) {
  std::string str =
      "2 * tan(0.75) + sin(0.4) - 8 mod cos(0.6) + 2.5 ^ (1.2 - 0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      2 * tan(0.75) + sin(0.4) - fmod(8, cos(0.6)) + pow(2.5, 1.2 - 0.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_45) {
  std::string str =
      "tan(1.5) - 3 * sin(0.6) + 6 / cos(0.4) - 4 mod 2 ^ (0.8 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      tan(1.5) - 3 * sin(0.6) + 6 / cos(0.4) - fmod(4, pow(2, 0.8 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_46) {
  std::string str =
      "3 * tan(0.9) + 5 * sin(0.2) - 9 / cos(0.8) + 7.7 mod 4 ^ (0.6 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      3 * tan(0.9) + 5 * sin(0.2) - 9 / cos(0.8) + fmod(7.7, pow(4, 0.6 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_47) {
  std::string str =
      "tan(1.2) - 2 * sin(0.9) + 7 / cos(0.5) - 8.8 mod 2 ^ (1.3 + 0.4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      tan(1.2) - 2 * sin(0.9) + 7 / cos(0.5) - fmod(8.8, pow(2, 1.3 + 0.4));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_48) {
  std::string str = "2 + acos(0.5) - 1 * 3 / acos(0.2) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + acos(0.5) - 1 * 3 / acos(0.2) + fmod(4, pow(2, 0.6 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_49) {
  std::string str = "4 * acos(0.8) + 2.5 / acos(0.3) - 5 mod 2 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 * acos(0.8) + 2.5 / acos(0.3) - fmod(5, pow(2, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_50) {
  std::string str =
      "acos(0.4) - 2 * acos(0.6) + 3 / acos(0.1) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      acos(0.4) - 2 * acos(0.6) + 3 / acos(0.1) + fmod(6, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_51) {
  std::string str =
      "acos(0.9) + 3 * acos(0.2) - 2 / acos(0.5) + 5 mod 3 ^ (0.6 - 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      acos(0.9) + 3 * acos(0.2) - 2 / acos(0.5) + fmod(5, pow(3, 0.6 - 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_52) {
  std::string str = "2 * acos(0.7) + 1 / acos(0.4) - 4 mod 2 ^ (0.9 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * acos(0.7) + 1 / acos(0.4) - fmod(4, pow(2, 0.9 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_53) {
  std::string str = "2 + asin(0.5) - 1 * 3 / asin(0.2) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + asin(0.5) - 1 * 3 / asin(0.2) + fmod(4, pow(2, 0.6 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_54) {
  std::string str = "4 * asin(0.8) + 2.5 / asin(0.3) - 5 mod 2 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 * asin(0.8) + 2.5 / asin(0.3) - fmod(5, pow(2, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_55) {
  std::string str =
      "asin(0.4) - 2 * asin(0.6) + 3 / asin(0.1) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      asin(0.4) - 2 * asin(0.6) + 3 / asin(0.1) + fmod(6, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_56) {
  std::string str =
      "asin(0.9) + 3 * asin(0.2) - 2 / asin(0.5) + 5 mod 3 ^ (0.6 - 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      asin(0.9) + 3 * asin(0.2) - 2 / asin(0.5) + fmod(5, pow(3, 0.6 - 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_57) {
  std::string str = "2 * asin(0.7) + 1 / asin(0.4) - 4 mod 2 ^ (0.9 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * asin(0.7) + 1 / asin(0.4) - fmod(4, pow(2, 0.9 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_58) {
  std::string str = "2 + atan(0.5) - 1 * 3 / atan(0.2) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + atan(0.5) - 1 * 3 / atan(0.2) + fmod(4, pow(2, 0.6 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_59) {
  std::string str = "4 * atan(0.8) + 2.5 / atan(0.3) - 5 mod 2 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 * atan(0.8) + 2.5 / atan(0.3) - fmod(5, pow(2, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_60) {
  std::string str =
      "atan(0.4) - 2 * atan(0.6) + 3 / atan(0.1) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      atan(0.4) - 2 * atan(0.6) + 3 / atan(0.1) + fmod(6, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_61) {
  std::string str =
      "atan(0.9) + 3 * atan(0.2) - 2 / atan(0.5) + 5 mod 3 ^ (0.6 - 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      atan(0.9) + 3 * atan(0.2) - 2 / atan(0.5) + fmod(5, pow(3, 0.6 - 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_62) {
  std::string str = "2 * atan(0.7) + 1 / atan(0.4) - 4 mod 2 ^ (0.9 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * atan(0.7) + 1 / atan(0.4) - fmod(4, pow(2, 0.9 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_63) {
  std::string str = "2 + sqrt(9) - 1 * 3 / sqrt(16) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + sqrt(9) - 1 * 3 / sqrt(16) + fmod(4, pow(2, 0.6 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_64) {
  std::string str = "4 * sqrt(25) + 2.5 / sqrt(36) - 5 mod 2 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 * sqrt(25) + 2.5 / sqrt(36) - fmod(5, pow(2, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_65) {
  std::string str =
      "sqrt(16) - 2 * sqrt(64) + 3 / sqrt(81) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(16) - 2 * sqrt(64) + 3 / sqrt(81) + fmod(6, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_66) {
  std::string str =
      "sqrt(81) + 3 * sqrt(36) - 2 / sqrt(25) + 5 mod 3 ^ (0.6 - 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(81) + 3 * sqrt(36) - 2 / sqrt(25) + fmod(5, pow(3, 0.6 - 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_67) {
  std::string str = "2 * sqrt(49) + 1 / sqrt(64.0324) - 4 mod 2 ^ (0.9 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * sqrt(49) + 1 / sqrt(64.0324) - fmod(4, pow(2, 0.9 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_68) {
  std::string str =
      "sqrt(23) + 1.5 * sqrt(16174) - 2 / sqrt(9) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(23) + 1.5 * sqrt(16174) - 2 / sqrt(9) + fmod(4, pow(2, 0.6 + 0.3));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_69) {
  std::string str = "2 * sqrt(25) + sqrt(23) / 4.5 - 6 mod 3 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * sqrt(25) + sqrt(23) / 4.5 - fmod(6, pow(3, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_70) {
  std::string str =
      "sqrt(16.23) + 3.5 * sqrt(23) - 5 / sqrt(36) + 7 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(16.23) + 3.5 * sqrt(23) - 5 / sqrt(36) + fmod(7, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_71) {
  std::string str = "2 + 3 - 4 * 5 / 6 mod 7 ^ (cos(0.5) + sin(0.2))";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + 3 - 4 * 5 / fmod(6, pow(7, cos(0.5) + sin(0.2)));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_72) {
  std::string str =
      "sqrt(9) + 5 - tan(0.7) * acos(0.3) / (sin(0.5) mod cos(0.2)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(9) + 5 - tan(0.7) * acos(0.3) / pow(fmod(sin(0.5), cos(0.2)), 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_73) {
  std::string str =
      "3 * (atan(0.8) + sin(0.3)) - sqrt(16) / (cos(0.5) mod asin(0.2)) ^ 3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      3 * (atan(0.8) + sin(0.3)) - sqrt(16) / pow(fmod(cos(0.5), asin(0.2)), 3);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_74) {
  std::string str =
      "tan(0.6) + (sin(0.7) mod cos(0.8)) * sqrt(25) / atan(0.9) ^ (3 - 1)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      tan(0.6) + fmod(sin(0.7), cos(0.8)) * sqrt(25) / pow(atan(0.9), 3 - 1);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_75) {
  std::string str =
      "(sqrt(16) mod cos(0.2)) + tan(0.3) * sin(0.5) / acos(0.7) ^ sqrt(9)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      fmod(sqrt(16), cos(0.2)) + tan(0.3) * sin(0.5) / pow(acos(0.7), sqrt(9));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_76) {
  std::string str =
      "3 - sqrt(25) * cos(0.8) / (atan(0.2) mod sin(0.4)) ^ (sqrt(16) - 2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      3 - sqrt(25) * cos(0.8) / pow(fmod(atan(0.2), sin(0.4)), sqrt(16) - 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_77) {
  std::string str =
      "atan(0.5) + sqrt(36) * sin(0.7) / (cos(0.3) mod tan(0.4)) ^ (sqrt(9) + "
      "1)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = atan(0.5) +
               sqrt(36) * sin(0.7) / pow(fmod(cos(0.3), tan(0.4)), sqrt(9) + 1);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_78) {
  std::string str =
      "cos(0.5) - (sqrt(25) mod sin(0.8)) * tan(0.7) / acos(0.3) ^ (2 - "
      "sqrt(16))";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(0.5) - fmod(sqrt(25), sin(0.8)) * tan(0.7) /
                              pow(acos(0.3), 2 - sqrt(16));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_79) {
  std::string str =
      "(sqrt(16) mod sin(0.2)) + cos(0.4) * tan(0.6) / acos(0.8) ^ (sqrt(9) + "
      "3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = fmod(sqrt(16), sin(0.2)) +
               cos(0.4) * tan(0.6) / pow(acos(0.8), sqrt(9) + 3);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_80) {
  std::string str =
      "sqrt(9) - (cos(0.3) mod tan(0.8)) * sin(0.6) / atan(0.2) ^ (sqrt(25) - "
      "2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = sqrt(9) - fmod(cos(0.3), tan(0.8)) * sin(0.6) /
                             pow(atan(0.2), sqrt(25) - 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_81) {
  std::string str = "ln(2) + 3 - 4 * ln(5) / 6 mod 7 ^ (ln(0.5) + ln(0.2))";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log(2) + 3 - fmod(4 * log(5) / 6, pow(7, log(0.5) + log(0.2)));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_82) {
  std::string str = "ln(9) + 5 - ln(0.7) * ln(0.3) / (ln(0.5) mod ln(0.2)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      log(9) + 5 - log(0.7) * log(0.3) / pow(fmod(log(0.5), log(0.2)), 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_83) {
  std::string str =
      "3 * (ln(0.8) + ln(0.3)) - ln(16) / (ln(0.5) mod ln(0.2)) ^ 3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      3 * (log(0.8) + log(0.3)) - log(16) / pow(fmod(log(0.5), log(0.2)), 3);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_84) {
  std::string str =
      "ln(0.6) + (ln(0.7) mod ln(0.8)) * ln(25) / ln(0.9) ^ (3 - 1)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      log(0.6) + fmod(log(0.7), log(0.8)) * log(25) / pow(log(0.9), 3 - 1);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_85) {
  std::string str = "log(2) + 3 - 4 * log(5) / 6 mod 7 ^ (log(0.5) + log(0.2))";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      log10(2) + 3 - fmod(4 * log10(5) / 6, pow(7, log10(0.5) + log10(0.2)));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_86) {
  std::string str =
      "log(9) + 5 - log(0.7) * log(0.3) / (log(0.5) mod log(0.2)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(9) + 5 -
               log10(0.7) * log10(0.3) / pow(fmod(log10(0.5), log10(0.2)), 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_87) {
  std::string str =
      "3 * (log(0.8) + log(0.3)) - log(16) / (log(0.5) mod log(0.2)) ^ 3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 3 * (log10(0.8) + log10(0.3)) -
               log10(16) / pow(fmod(log10(0.5), log10(0.2)), 3);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_88) {
  std::string str =
      "log(0.6) + (log(0.7) mod log(0.8)) * log(25) / log(0.9) ^ (3 - 1)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(0.6) + fmod(log10(0.7), log10(0.8)) * log10(25) /
                                pow(log10(0.9), 3 - 1);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_89) {
  std::string str =
      "2 + sin(0.5) - cos(0.2) * tan(0.3) / (sqrt(4) mod ln(2)) ^ atan(0.7)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + sin(0.5) -
               cos(0.2) * tan(0.3) / pow(fmod(sqrt(4), log(2)), atan(0.7));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_90) {
  std::string str =
      "3 * acos(0.5) + asin(0.3) - atan(0.2) / (ln(3) mod sqrt(9)) ^ log(0.8)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 3 * acos(0.5) + asin(0.3) -
               atan(0.2) / pow(fmod(log(3), sqrt(9)), log10(0.8));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_91) {
  std::string str =
      "tan(0.4) + sqrt(16) * log(0.6) / (asin(0.7) mod acos(0.8)) ^ ln(2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = tan(0.4) +
               sqrt(16) * log10(0.6) / pow(fmod(asin(0.7), acos(0.8)), log(2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_92) {
  std::string str =
      "4 - ln(3) + sin(0.6) * cos(0.7) / (tan(0.8) mod sqrt(25)) ^ atan(0.9)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 - log(3) +
               sin(0.6) * cos(0.7) / pow(fmod(tan(0.8), sqrt(25)), atan(0.9));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_93) {
  std::string str =
      "log(2) + atan(0.3) - sqrt(9) * cos(0.5) / (asin(0.7) mod tan(0.9)) ^ "
      "ln(4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(2) + atan(0.3) -
               sqrt(9) * cos(0.5) / pow(fmod(asin(0.7), tan(0.9)), log(4));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_94) {
  std::string str = "-2+3";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -2 + 3;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_95) {
  std::string str = "4 - -5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 - -5;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_96) {
  std::string str = "-3 * 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -3 * 2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_97) {
  std::string str = "7 / -2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 7 / -2.0;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_98) {
  std::string str = "-(4 + 3) * -2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -(4 + 3) * -2;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_99) {
  std::string str = "2.5 + 3.7 * -4.2 / 1.3 - 2.8 ^ -1.5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2.5 + 3.7 * -4.2 / 1.3 - pow(2.8, -1.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_100) {
  std::string str = "-(7.2 + 3.9) * (1.6 - 4.7) + 9.8 / -2.1";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -(7.2 + 3.9) * (1.6 - 4.7) + 9.8 / -2.1;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_101) {
  std::string str = "5.2 * (2.1 - 3.7) / -1.8 + 4.3 ^ -0.5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 5.2 * (2.1 - 3.7) / -1.8 + pow(4.3, -0.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_102) {
  std::string str = "-3.5 / -(1.2 + 0.7 * -2.3) ^ 0.6 + 4.1";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -3.5 / pow(-(1.2 + 0.7 * -2.3), 0.6) + 4.1;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_103) {
  std::string str =
      "-2.5 * cos(1.2) + sqrt(3.7) / sin(0.8) - log(2.1) + atan(1.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -2.5 * cos(1.2) + sqrt(3.7) / sin(0.8) - log10(2.1) + atan(1.5);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_104) {
  std::string str = "tan(2.7) / -sin(1.5) + 3.2 * log(0.9) - 1.8 ^ cos(0.6)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = tan(2.7) / -sin(1.5) + 3.2 * log10(0.9) - pow(1.8, cos(0.6));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_105) {
  std::string str = "acos(0.4) - tan(1.7) * sqrt(2.9) / sin(0.5) + log(1.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = acos(0.4) - tan(1.7) * sqrt(2.9) / sin(0.5) + log10(1.2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_106) {
  std::string str =
      "log(2.5) + sin(1.3) * cos(0.9) - 2.1 ^ sqrt(1.8) / tan(0.7)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      log10(2.5) + sin(1.3) * cos(0.9) - pow(2.1, sqrt(1.8)) / tan(0.7);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_107) {
  std::string str =
      "-sin(2.3) / sqrt(1.6) + 4.9 * log(3.5) - 2.1 mod 0.8 * atan(1.4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      -sin(2.3) / sqrt(1.6) + 4.9 * log10(3.5) - fmod(2.1, 0.8) * atan(1.4);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_108) {
  std::string str =
      "tan(1.8) / cos(2.5) - 3.6 * sqrt(1.9) + 4.2 mod 0.7 * sin(0.6)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      tan(1.8) / cos(2.5) - 3.6 * sqrt(1.9) + fmod(4.2, 0.7) * sin(0.6);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_109) {
  std::string str =
      "log(0.5) + atan(2.3) * cos(1.9) - sqrt(2.6) ^ sin(0.4) / 3.2 mod 0.9";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(0.5) + atan(2.3) * cos(1.9) -
               fmod(pow(sqrt(2.6), sin(0.4)) / 3.2, 0.9);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_110) {
  std::string str =
      "asin(0.3) - log(1.9) / cos(1.5) + sqrt(20000.3456) ^ atan(0.9)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      asin(0.3) - log10(1.9) / cos(1.5) + pow(sqrt(20000.3456), atan(0.9));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_111) {
  std::string str =
      "log(0.8) + sqrt(1.5) * atan(2.6) - sin(1.7) ^ cos(0.5) / 3.1 mod 0.6";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = log10(0.8) + sqrt(1.5) * atan(2.6) -
               fmod(pow(sin(1.7), cos(0.5)) / 3.1, 0.6);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_112) {
  std::string str =
      "-cos(1.2) / sqrt(2.3) + log(1.8) * tan(2.4) - (3.5 mod 0.7) ^ asin(0.6)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = -cos(1.2) / sqrt(2.3) + log10(1.8) * tan(2.4) -
               pow(fmod(3.5, 0.7), asin(0.6));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_113) {
  std::string str = "6.8-3.2 / 0";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_114) {
  std::string str = "10 / (2 - 2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_115) {
  std::string str = "0 * 2 / 0";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_116) {
  std::string str = "1 / (2 - 2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_117) {
  std::string str = "0 / (3.2 - 3.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_118) {
  std::string str = "5.7 / (3.2 * 0) + sin(1.5) * tan(0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_119) {
  std::string str = "8.4 / (2 - 2) - sqrt(9.5) + 10 mod 0";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_120) {
  std::string str = "0 / (7.3 - 7.3) * ln(2) + cos(0.8)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_121) {
  std::string str = "sqrt(6.2) / (-1 + 1) + log(100) - asin(1)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_122) {
  std::string str = "tan(0.6) * (9 / 0) - 10 mod 0 + cos(1.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_123) {
  std::string str = "2 + sqrt(-9) - 1 * 3 / sqrt(-16) + 4 mod 2 ^ (0.6 + 0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_124) {
  std::string str =
      "4 * sqrt(25) + 2.5 / sqrt(-1 * 36) - 5 mod 2 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_125) {
  std::string str =
      "sqrt(16) - 2 * sqrt(64) + 3 / sqrt(80 - 81) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_126) {
  std::string str = "(asin(0.7) mod acos(0.8)) ^ ln(-2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_127) {
  std::string str = "4 - ln(3 * -1) + sin(0.6) * cos(0.7)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_128) {
  std::string str = "ln(2) + 3 - 4 * ln(5 - 5.9) / 6";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_129) {
  std::string str = "(asin(0.7) mod acos(0.8)) ^ log(-2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_130) {
  std::string str = "4 - log(3 * -1) + sin(0.6) * cos(0.7)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_131) {
  std::string str = "ln(2) + 3 - 4 * log(5 - 5.9) / 6";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_132) {
  std::string str = "sqrt(9) + 5 - tan(0.7) * acos(1 + 0.3) / (sin(0.5)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_133) {
  std::string str = "acos(-1 - 0.4) - tan(1.7) * sqrt(2.9) / sin(0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_134) {
  std::string str = "3 * acos(0.5 * 3) + asin(0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_135) {
  std::string str = "sqrt(9) + 5 - tan(0.7) * asin(1 + 0.3) / (sin(0.5)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_136) {
  std::string str = "asin(-1 - 0.4) - tan(1.7) * sqrt(2.9) / sin(0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_137) {
  std::string str = "3 * asin(0.5 * 3) + asin(0.3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_138) {
  std::string str = "sqrt(9) + 5 - z(0.7) / (sin(0.5)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_139) {
  std::string str = "rt(9) + 5 - (sin(0.5)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_140) {
  std::string str = "9 + 5 - (sin(0.5)) $ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_141) {
  std::string str = "srt(9) + 5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_142) {
  std::string str = "7 / sin(0.4) * srt(9) + 5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_143) {
  std::string str = "7 / sin(0.4) + 5 sctukgqnl%-+*/^";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_144) {
  std::string str = "sctukgqnl%-+*/^";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_145) {
  std::string str = "2*(4.7-(1.8/(0.5+2.3))))+6.2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_146) {
  std::string str = "12.6-(3.1+1.2)*(2.5-0.9))/(5.3+2.4)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_147) {
  std::string str = "9) + 5.432423";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_148) {
  std::string str = "5 - tn(0.7)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_149) {
  std::string str = "5 - 3 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_150) {
  std::string str = "5 - 3 3 * 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_151) {
  std::string str =
      "tan(0.5) + 2 * sin(0.3) - 4 6 / cos(0.25) + 5.5 mod 3 ^ (1.2 + 0.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_152) {
  std::string str = "5 - 3 / 2 *";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_153) {
  std::string str = "5 - 3 / 2 * 4.5 / sqrt(34) +";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_154) {
  std::string str = "5 - 3 / 2.3.4 * 4.5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_155) {
  std::string str = "5 - 3 / 2.3.(4 * 4.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_156) {
  std::string str = "5 - 3 / 2.3 .sin(4 / 4.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_157) {
  std::string str = "5x";
  double x = 2.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 5 * 2.0;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_158) {
  std::string str = "1 + 5x";
  double x = 2.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 1 + 5 * 2.0;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_159) {
  std::string str = "2 + cos(x)";
  double x = 1.57;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + cos(x);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_160) {
  std::string str = "cos(x)";
  double x = 1.57;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = cos(x);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_161) {
  std::string str =
      "tan(0.5) + 2 * sin(x) - 4 6 / cos(0.25) + 5.5 mod 3 ^ (1.2 + 0.5)";
  double x = 0.3;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_162) {
  std::string str = "4 * sqrt(x) + 2.5 / sqrt(36) - x mod 2 ^ (0.7 - 0.2)";
  double x = 25.9;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 4 * sqrt(x) + 2.5 / sqrt(36) - fmod(x, pow(2, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_163) {
  std::string str =
      "sqrt(16) - 2 * sqrt(x) + x / sqrt(81) + 6 mod 4 ^ (0.8 + 0.2)";
  double x = 36.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(16) - 2 * sqrt(x) + x / sqrt(81) + fmod(6, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_164) {
  std::string str = "5 - 3 / 2.x.4 * 4.5";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_165) {
  std::string str = "5 - 3 / x.3.(4 * 4.5)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_166) {
  std::string str =
      "0000000890 + 0000000890 + 0000000890 + 0000000890 + 0000000890 + "
      "0000000890 + 0000000890 + 0000000890 + 0000000890 + 0000000890 + "
      "0000000890 + 0000000890 + 0000000890 + 0000000890 + 0000000890 + "
      "0000000890 + 0000000890 + 0000000890 + 0000000890 + 123456.7";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 140366.7;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_167) {
  std::string str = "2 * sqrt(25) + sqrt(23) / 4.5 - + 6 mod 3 ^ (0.7 - 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 * sqrt(25) + sqrt(23) / 4.5 - fmod(6, pow(3, 0.7 - 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_168) {
  std::string str =
      "sqrt(16.23) + + 3.5 * sqrt(23) - 5 / sqrt(36) + 7 mod 4 ^ (0.8 + 0.2)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(16.23) + 3.5 * sqrt(23) - 5 / sqrt(36) + fmod(7, pow(4, 0.8 + 0.2));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_169) {
  std::string str = "+2 + 3 - 4 * 5 / 6 mod 7 ^ (cos(0.5) + sin(0.2))";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = 2 + 3 - 4 * 5 / fmod(6, pow(7, cos(0.5) + sin(0.2)));
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_170) {
  std::string str =
      "sqrt(+9) + 5 - tan(0.7) * acos(0.3) / (sin(0.5) mod cos(0.2)) ^ 2";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp =
      sqrt(9) + 5 - tan(0.7) * acos(0.3) / pow(fmod(sin(0.5), cos(0.2)), 2);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_171) {
  std::string str = "";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_172) {
  std::string str = ")2-3(";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_173) {
  std::string str = "(2-3)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = (2 - 3);
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_174) {
  std::string str = ")2-3(";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_175) {
  std::string str = "atan(0.5) + sqrt(36) * sin(0.7) / 5-35.8()";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_176) {
  std::string str = "cos(0.5) - ()sqrt(25)";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_177) {
  std::string str = "2-3 / (0) ";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_178) {
  std::string str = "2-3 / (0) *2 ";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_179) {
  std::string str = "2-3 /(5* (0)) *2 ";
  double x = 0.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.Calculate();
  double res = calc_controller.result();
  bool err = calc_controller.error();
  ASSERT_TRUE(err);
}

TEST(ModelTest, Test_180) {
  std::string str = "x-8";
  double x = 5.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = x - 8;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(ModelTest, Test_181) {
  std::string str = "x+8";
  double x = 5.0;
  s21::CalcController calc_controller;
  calc_controller.HandleInput(str);
  calc_controller.set_x(x);
  calc_controller.Calculate();
  double res = calc_controller.result();
  double exp = x + 8;
  ASSERT_NEAR(res, exp, TOL);
}

TEST(CredTest, Annuity_1) {
  double loan = 120000;
  double interest = 5;
  double term = 36;
  bool flagDiff = false;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);
  double monthly = cred_calc.monthly();
  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_monthly = 3596.51;
  double exp_overpayment = 9474.36;
  double exp_total = 129474.36;
  ASSERT_NEAR(monthly, exp_monthly, ACC);
  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(CredTest, Annuity_2) {
  double loan = 300000;
  double interest = 13;
  double term = 6;
  bool flagDiff = false;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);
  double monthly = cred_calc.monthly();
  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_monthly = 51912.86;
  double exp_overpayment = 11477.16;
  double exp_total = 311477.16;
  ASSERT_NEAR(monthly, exp_monthly, ACC);
  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(CredTest, Annuity_3) {
  double loan = 500000;
  double term = 50;
  double interest = 12.5;
  bool flagDiff = false;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);
  double monthly = cred_calc.monthly();
  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_monthly = 12880.05;
  double exp_overpayment = 144002.50;
  double exp_total = 644002.5;
  ASSERT_NEAR(monthly, exp_monthly, ACC);
  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(CredTest, Annuity_4) {
  double loan = 150000;
  double term = 5;
  double interest = 15;
  bool flagDiff = false;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);
  double monthly = cred_calc.monthly();
  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_monthly = 31134.32;
  double exp_overpayment = 5671.60;
  double exp_total = 155671.6;
  ASSERT_NEAR(monthly, exp_monthly, ACC);
  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(CredTest, Diff_1) {
  double loan = 500000;
  double term = 12;
  double interest = 10;
  bool flagDiff = true;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);
  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_overpayment = 26974.89;
  double exp_total = 526974.89;

  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(CredTest, Diff_2) {
  double loan = 1200000;
  double term = 36;
  double interest = 15;
  bool flagDiff = true;

  s21::CredCalc cred_calc(loan, interest, term);
  cred_calc.calculateCredit(flagDiff);

  double overpayment = cred_calc.overpayment();
  double total = cred_calc.total();

  double exp_overpayment = 277109.57;
  double exp_total = 1477109.57;

  ASSERT_NEAR(overpayment, exp_overpayment, ACC);
  ASSERT_NEAR(total, exp_total, ACC);
}

TEST(DeposTest, SimpleTest) {
  double init_investment = 100000;
  double contribution = 0;
  double term = 36;
  double rate = 15;
  bool compound = 0;

  s21::DeposCalc depos_calc(init_investment, contribution, term, rate);
  depos_calc.calculateDeposit(compound);

  double end_balance = depos_calc.end_balance();
  double total_contribs = depos_calc.total_contribs();
  double total_interest = depos_calc.total_interest();

  double exp_end_balance = 145000;
  double exp_total_contribs = 0;
  double exp_total_interest = 45000;

  ASSERT_NEAR(end_balance, exp_end_balance, ACC);
  ASSERT_NEAR(total_contribs, exp_total_contribs, ACC);
  ASSERT_NEAR(total_interest, exp_total_interest, ACC);
}

TEST(DeposTest, Compound_1) {
  double init_investment = 100000;
  double contribution = 10000;
  double term = 12;
  double rate = 12;
  bool compound = 1;

  s21::DeposCalc depos_calc(init_investment, contribution, term, rate);
  depos_calc.calculateDeposit(compound);

  double end_balance = depos_calc.end_balance();
  double total_contribs = depos_calc.total_contribs();
  double total_interest = depos_calc.total_interest();

  double exp_end_balance = 240775.78;
  double exp_total_contribs = 120000;
  double exp_total_interest = 20775.78;

  ASSERT_NEAR(end_balance, exp_end_balance, ACC);
  ASSERT_NEAR(total_contribs, exp_total_contribs, ACC);
  ASSERT_NEAR(total_interest, exp_total_interest, ACC);
}

TEST(DeposTest, Compound_2) {
  double init_investment = 100000;
  double contribution = 0;
  double term = 36;
  double rate = 15;
  bool compound = 1;

  s21::DeposCalc depos_calc(init_investment, contribution, term, rate);
  depos_calc.calculateDeposit(compound);

  double end_balance = depos_calc.end_balance();
  double total_contribs = depos_calc.total_contribs();
  double total_interest = depos_calc.total_interest();

  double exp_end_balance = 156394.38;
  double exp_total_contribs = 0;
  double exp_total_interest = 56394.38;

  ASSERT_NEAR(end_balance, exp_end_balance, ACC);
  ASSERT_NEAR(total_contribs, exp_total_contribs, ACC);
  ASSERT_NEAR(total_interest, exp_total_interest, ACC);
}