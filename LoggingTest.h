#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IHistoryMock.h"
#include "SimpleCalculator.h"

using namespace calc;

class LoggingTest : public ::testing::Test {
protected:
    IHistoryMock m_history;
    SimpleCalculator m_calc{m_history};
};

TEST_F(LoggingTest, Logging) {
    EXPECT_CALL(m_history, AddEntry("5 * 8 = 40"));
    ASSERT_EQ(m_calc.Multiply(5, 8), 40);

    EXPECT_CALL(m_history, AddEntry("10 + 1 = 11"));
    EXPECT_CALL(m_history, AddEntry("8 - 3 = 5"));
    ASSERT_EQ(m_calc.Add(10, 1), 11);
    ASSERT_EQ(m_calc.Subtract(8, 3), 5);

    EXPECT_CALL(m_history, GetLastOperations(2))
        .WillOnce(::testing::Return(std::vector<std::string>{"10 + 1 = 11", "8 - 3 = 5"}));
    
    auto history = m_history.GetLastOperations(2);
    ASSERT_EQ(history.size(), 2);
}