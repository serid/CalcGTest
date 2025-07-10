#include "LoggingTest.h"
#include "DivisionByZeroTest.h"

int main() {
    testing::InitGoogleTest();
    int _ = RUN_ALL_TESTS();
}