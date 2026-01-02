#pragma once
#include "../common.h"

class DriveInformation {
public:
    int initialDriveValue;                   // 0x0
    char initialDirectoryValue[256];         // 0x4
    int currentDriveValue;                   // 0x104
    char currentDirectoryValue[256];         // 0x108
    int driveValues[27];                     // 0x208

    DriveInformation();
    virtual int initialDrive();
    virtual char initialDriveAsLetter();
    virtual char* initialDirectory();
    virtual int currentDrive();
    virtual char currentDriveAsLetter();
    virtual char* currentDirectory();
    virtual int numberDrives();
    virtual int validDrive(int param_1);
    virtual void checkDrives();
    virtual int numberOfFilesWithFilename(char* param_1);
    virtual int numberOfFilesWithAttribute(int param_1);
    virtual int numberOfFilesWithFilenameOrAttribute(char* param_1, int param_2);
    virtual int resetCurrentDriveAndDirectory();
    virtual int resetCurrentDrive();
    virtual int resetCurrentDirectory();
    virtual int changeDrive(int param_1);
    virtual int changeDirectory(char* param_1);
    virtual void updateDirectory();
};

static_assert(sizeof(DriveInformation) == 0x274, "DriveInformation Size Mismatch");
static_assert(offsetof(DriveInformation, driveValues) == 0x208, "DriveInformation Offset Mismatch");

