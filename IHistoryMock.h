#pragma once

#include <gmock/gmock.h>

#include "IHistory.h"

using namespace calc;

class IHistoryMock : public IHistory {
public:
    MOCK_METHOD(void, AddEntry, (const std::string&), (override));
    MOCK_METHOD((std::vector<std::string>), GetLastOperations, (size_t), (const, override));
};