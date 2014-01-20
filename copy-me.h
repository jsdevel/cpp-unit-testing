/*
Copyright 2014 Joseph Spencer.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#define assert(cond) \
  if(!(cond)){ \
    printf("Assertion failed for: %s", #cond); \
    throw 1; \
  }

#define fail(msg)   \
  cout << "Fail: " << #msg << '\n'; \
  throw 1;

#ifdef USE_AFTER
  #define __ADD_AFTER()             \
  try {                             \
    test::after();                  \
  } catch(...){}                    
#else
  #define __ADD_AFTER()
#endif

#ifdef USE_BEFORE
  #define __ADD_BEFORE()             \
  try {                             \
    test::before();                  \
  } catch(...){}                    
#else
  #define __ADD_BEFORE()
#endif

#define TEST(name)                  \
  cout << " |__ " << #name << '\n'; \
  __ADD_BEFORE()                    \
  test::name();                     \
  __ADD_AFTER()


