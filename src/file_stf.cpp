
#include "../include/file_stf.h"

#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __cdecl compareFilenameStrings(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
}

char driveAsLetter(int value)
{
    return (char)(value + 0x40);
}

int driveAsInt(char value)
{
    return value - 64;
}

DriveInformation::DriveInformation()
{
    int drive;

    drive = _getdrive();
    this->initialDriveValue = drive;
    this->currentDriveValue = drive;
    this->updateDirectory();
    strcpy(this->initialDirectoryValue, this->currentDirectoryValue);
}

int DriveInformation::initialDrive() const
{
    return this->initialDriveValue;
}

char DriveInformation::initialDriveAsLetter() const
{
    return (char)(this->initialDriveValue + 0x40);
}

char* DriveInformation::initialDirectory()
{
    return this->initialDirectoryValue;
}

int DriveInformation::currentDrive() const
{
    return this->currentDriveValue;
}

char DriveInformation::currentDriveAsLetter() const
{
    return (char)(this->currentDriveValue + '@');
}

char* DriveInformation::currentDirectory()
{
    return this->currentDirectoryValue;
}

int DriveInformation::numberDrives() const
{
    return this->driveValues[0];
}

int DriveInformation::validDrive(int index) const
{
    return this->driveValues[index];
}

void DriveInformation::checkDrives()
{
    int drive;

    this->driveValues[0] = 0;
    for (drive = 1; drive <= 0x1A; ++drive) {
        if (_chdrive(drive) == 0) {
            this->driveValues[0]++;
            this->driveValues[drive] = 1;
        } else {
            this->driveValues[drive] = 0;
        }
    }

    _chdrive(this->currentDriveValue);
}

int DriveInformation::numberOfFilesWithFilename(char* filename)
{
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst(filename, &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        count++;
    }
    return count;
}

int DriveInformation::numberOfFilesWithAttribute(int attribute)
{
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst("*.*", &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        if ((fileInfo.attrib & attribute) != 0) {
            count++;
        }
    }
    return count;
}

int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* filename,
                                                            int attribute)
{
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst("*.*", &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        if ((fileInfo.attrib & attribute) != 0 ||
            strstr(fileInfo.name, filename) != 0) {
            count++;
        }
    }
    return count;
}

int DriveInformation::resetCurrentDriveAndDirectory()
{
    if (this->resetCurrentDrive() != 0) {
        return this->resetCurrentDirectory();
    }
    return 0;
}

int DriveInformation::resetCurrentDrive()
{
    return this->changeDrive(this->initialDriveValue);
}

int DriveInformation::resetCurrentDirectory()
{
    return this->changeDirectory(this->initialDirectoryValue);
}

int DriveInformation::changeDrive(int drive)
{
    if (_chdrive(drive) == 0) {
        this->currentDriveValue = drive;
        return 1;
    }
    return 0;
}

int DriveInformation::changeDirectory(char* path)
{
    if (_chdir(path) == 0) {
        this->updateDirectory();
        return 1;
    }
    return 0;
}

void DriveInformation::updateDirectory()
{
    char cDrive[3];
    char extension[256];
    char filename[256];
    char fullPath[260];

    _getcwd(fullPath, 0x104);
    _splitpath(fullPath, cDrive, this->currentDirectoryValue, filename,
              extension);
    sprintf(this->currentDirectoryValue, "%s%s%s",
            this->currentDirectoryValue, filename, extension);
}
