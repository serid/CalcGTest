#pragma once

#include <gtest/gtest.h>

#include "InMemoryHistory.h"
#include "SimpleCalculator.h"

using namespace calc;

class DivisionByZeroTest : public ::testing::Test {
protected:
    InMemoryHistory m_history;
    SimpleCalculator m_calc{m_history};
};

TEST_F(DivisionByZeroTest, DivisionByZero) {
    EXPECT_EXIT(m_calc.Divide(3, 0), ::testing::KilledBySignal(8), "");
}