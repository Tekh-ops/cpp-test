# Hey There Fellow Developer

## This is just a Demo C++ project of getting a Bank Account details and Unit Testing with Google Test

### GTEST Link
You can checkout Google Test [Here](https://github.com/google/googletest).

# How to Configure Google Test in VS code

1. Start with a clean directory:

```
/home/user/Desktop/projects/cpp/ # your project lives here
```
2. Add your cmake file(CMakeLists.txt), your source files, and test file. The directory now looks like this:

```
└─cpp/
    ├─ CMakeLists.txt
    ├─ myfunctions.h
    └─ mytests.cpp
```

3. Clone and add googletest to this directory:
```
└─cpp/
    ├─ googletest/
    ├─ CMakeLists.txt
    ├─ myfunctions.h
    └─ mytests.cpp
```

4. Open your CMakeLists.txt and enter the following:
```
cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(mytests mytests.cpp) # add this executable

target_link_libraries(mytests PRIVATE gtest) # link google test to this executable
```

5. Contents of myfunctions.h for the example
```
#ifndef _ADD_H
#define _ADD_H

int add(int a, int b)
{
    return a + b;
}

#endif
```
6. Contents of mytests.cpp for the example:
```
#include <gtest/gtest.h>
#include "myfunctions.h"

TEST(myfunctions, add)
{
    GTEST_ASSERT_EQ(add(10, 22), 32);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Now you just have to run the tests. There are multiple ways to do that.

In the terminal, create a build/ dir in your project root directory:
```
mkdir build
```

Your directory should now look like this:
```
└─cpp/
    ├─ build/
    ├─ googletest/
    ├─ CMakeLists.txt
    ├─ myfunctions.h
    └─ mytests.cpp
```

Next go into the build directory:
```
cd build
```

Then run:
```
cmake ..
make
./mytests
```