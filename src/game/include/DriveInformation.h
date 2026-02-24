#pragma once
#include "common.h"

// Offset: 0x00449750
char driveAsLetter(int param_1);
// Offset: 0x00449760
int driveAsInt(char param_1);

struct DriveInformation {
    // Offset: 0x00449770
    DriveInformation();

    // Offset: 0x004497C0
    int initialDrive() const;
    // Offset: 0x004497D0
    char initialDriveAsLetter() const;
    // Offset: 0x004497E0
    char* initialDirectory();

    // Offset: 0x004497F0
    int currentDrive() const;
    // Offset: 0x00449800
    char currentDriveAsLetter() const;
    // Offset: 0x00449810
    char* currentDirectory();

    // Offset: 0x00449820
    int numberDrives() const;
    // Offset: 0x00449830
    int validDrive(int param_1) const;
    // Offset: 0x00449840
    void checkDrives();

    // Offset: 0x004498A0
    int numberOfFilesWithFilename(char* param_1);
    // Offset: 0x00449910
    int numberOfFilesWithAttribute(int param_1);
    // Offset: 0x00449990
    int numberOfFilesWithFilenameOrAttribute(char* param_1, int param_2);

    // Offset: 0x00449A20
    int resetCurrentDriveAndDirectory();
    // Offset: 0x00449A40
    int resetCurrentDrive();
    // Offset: 0x00449A50
    int resetCurrentDirectory();

    // Offset: 0x00449A60
    int changeDrive(int param_1);
    // Offset: 0x00449A90
    int changeDirectory(char* param_1);

protected:
    // Offset: 0x00449AC0
    void updateDirectory();

public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];
};
static_assert(sizeof(DriveInformation) == 0x274, "Size mismatch");
