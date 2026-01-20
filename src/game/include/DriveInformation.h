#pragma once
#include "common.h"

struct DriveInformation {
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];
};
static_assert(sizeof(DriveInformation) == 0x274, "Size mismatch");
