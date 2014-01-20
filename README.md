cpp-unit-testing
================

A single header file is all you need :)

The goal of this project is to allow testing of c++ to remain easy and flexible, without the need to install libraries.  You can simply copy the header file into your project to get started.

##Example
````cpp
#include <cstdio>
#include <iostream>
#include "../../src/cc/PWM.h"

using namespace std;

//Tell assert to call `before()` and `after()`;
#define USE_BEFORE 1
#define USE_AFTER 1
#include "helpers/assert.h"
namespace test {
  PWM * pwm;

  void before(){
    pwm = new PWM(5, 30, 1000);
  }

  void after(){
    pwm = 0;
  }

  void valid_pins_for_constructor_throw_no_error(){
    int pins [17] = {3, 5, 7, 8, 10, 11, 12, 13, 15, 16, 18, 19, 21, 22, 23, 24, 26};
    for(int i = 0;i<17;i++){
      PWM pwm(pins[i], 0, 1);
    }
  }

  void invalid_pins_for_constructor_throw_error(){
    int pins [5] = {1, 2, 0, 40, 50};
    for(int i = 0;i<5;i++){
      try {
        PWM pwm(pins[i], 0, 1);
        fail("didn't throw for pin");
      } catch(...){
        continue;
      }
    }
  }

  void changing_duty_cycle_to_value_greater_than_100_returns_100(){
    pwm->setDutyCycle(75);
    assert(pwm->getDutyCycle() == 75);
  }
}

int main(){
  TEST(valid_pins_for_constructor_throw_no_error);
  TEST(invalid_pins_for_constructor_throw_error);
  TEST(changing_duty_cycle_to_value_greater_than_100_returns_100);
}
````
