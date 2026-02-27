#pragma once
#include "common.h"

struct AIPlayPhaseCommand {
    uchar groupValue;
    uchar typeValue;
    int value1Value;
    int value2Value;
    int value3Value;

    AIPlayPhaseCommand();
    AIPlayPhaseCommand(uchar group, uchar type, int value1, int value2, int value3);
    AIPlayPhaseCommand(uchar group, char* typeName, int value1, int value2, int value3);
    char* nameType() const;

protected:
    uchar convertToIntType(char* typeName) const;
    char* convertToNameType(uchar type) const;
};
static_assert(sizeof(AIPlayPhaseCommand) == 0x10, "Size mismatch");
