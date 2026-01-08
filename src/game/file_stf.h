#pragma once
#include "../common.h"

class DriveInformation       {
public:
    int initialDriveValue;                   // 0x0
    char initialDirectoryValue[256];         // 0x4
    int currentDriveValue;                   // 0x104
    char currentDirectoryValue[256];         // 0x108
    int driveValues[27];                     // 0x208

    DriveInformation();

    // --- Non-Virtual Members ---
    int initialDrive();
    char initialDriveAsLetter();
    char* initialDirectory();
    int currentDrive();
    char currentDriveAsLetter();
    char* currentDirectory();
    int numberDrives();
    int validDrive(int param_1);
    void checkDrives();
    int numberOfFilesWithFilename(char* param_1);
    int numberOfFilesWithAttribute(int param_1);
    int numberOfFilesWithFilenameOrAttribute(char* param_1, int param_2);
    int resetCurrentDriveAndDirectory();
    int resetCurrentDrive();
    int resetCurrentDirectory();
    int changeDrive(int param_1);
    int changeDirectory(char* param_1);
    void updateDirectory();
};

static_assert(sizeof(DriveInformation) == 0x274, "DriveInformation Size Mismatch");
static_assert(offsetof(DriveInformation, driveValues) == 0x208, "DriveInformation Offset Mismatch");

