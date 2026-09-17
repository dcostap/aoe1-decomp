
#include "../include/file_stf.h"

#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __cdecl compareFilenameStrings(const void* e1, const void* e2) {
    return strcmp((const char*)e1, (const char*)e2);
}

char driveAsLetter(int d) {
    return (char)(d + 0x40);
}

int driveAsInt(char d) {
    return d - 64;
}

DriveInformation::DriveInformation() {
    int drive;

    drive = _getdrive();
    this->initialDriveValue = drive;
    this->currentDriveValue = drive;
    this->updateDirectory();
    strcpy(this->initialDirectoryValue, this->currentDirectoryValue);
}

int DriveInformation::initialDrive() const {
    return this->initialDriveValue;
}

char DriveInformation::initialDriveAsLetter() const {
    return (char)(this->initialDriveValue + 0x40);
}

char* DriveInformation::initialDirectory() {
    return this->initialDirectoryValue;
}

int DriveInformation::currentDrive() const {
    return this->currentDriveValue;
}

char DriveInformation::currentDriveAsLetter() const {
    return (char)(this->currentDriveValue + '@');
}

char* DriveInformation::currentDirectory() {
    return this->currentDirectoryValue;
}

int DriveInformation::numberDrives() const {
    return this->driveValues[0];
}

int DriveInformation::validDrive(int v) const {
    return this->driveValues[v];
}

void DriveInformation::checkDrives() {
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

int DriveInformation::numberOfFilesWithFilename(char* n) {
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst(n, &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        count++;
    }
    return count;
}

int DriveInformation::numberOfFilesWithAttribute(int a) {
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst("*.*", &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        if ((fileInfo.attrib & a) != 0) {
            count++;
        }
    }
    return count;
}

int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* n, int a) {
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst("*.*", &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        if ((fileInfo.attrib & a) != 0 ||
            strstr(fileInfo.name, n) != 0) {
            count++;
        }
    }
    return count;
}

int DriveInformation::resetCurrentDriveAndDirectory() {
    if (this->resetCurrentDrive() != 0) {
        return this->resetCurrentDirectory();
    }
    return 0;
}

int DriveInformation::resetCurrentDrive() {
    return this->changeDrive(this->initialDriveValue);
}

int DriveInformation::resetCurrentDirectory() {
    return this->changeDirectory(this->initialDirectoryValue);
}

int DriveInformation::changeDrive(int d) {
    if (_chdrive(d) == 0) {
        this->currentDriveValue = d;
        return 1;
    }
    return 0;
}

int DriveInformation::changeDirectory(char* d) {
    if (_chdir(d) == 0) {
        this->updateDirectory();
        return 1;
    }
    return 0;
}

void DriveInformation::updateDirectory() {
    char cDrive[3];
    char extension[256];
    char filename[256];
    char fullPath[260];

    _getcwd(fullPath, 0x104);
    _splitpath(fullPath, cDrive, this->currentDirectoryValue, filename, extension);
    sprintf(this->currentDirectoryValue, "%s%s%s", this->currentDirectoryValue, filename, extension);
}
