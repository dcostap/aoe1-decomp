
#include "../include/file_stf.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

extern "C" int __cdecl _getdrive(void);
extern "C" int __cdecl __chdrive(int drive);
extern "C" int __cdecl __chdir(const char* path);
extern "C" char* __cdecl strcpy(char* dst, const char* src);
extern char* getcwd(char* buffer, int size);
extern void splitpath(const char* path, char* drive, char* directory,
                      char* filename, char* extension);

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
        if (__chdrive(drive) == 0) {
            this->driveValues[0]++;
            this->driveValues[drive] = 1;
        } else {
            this->driveValues[drive] = 0;
        }
    }

    __chdrive(this->currentDriveValue);
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
    struct _finddata_t file_info;
    long h = _findfirst("*.*", &file_info);
    if (h == -1) {
        return 0;
    }
    int count = 1;
    if (_findnext(h, &file_info) == -1) {
        return count;
    }
    do {
        if ((file_info.attrib & attribute) ||
            strstr(file_info.name, filename)) {
            ++count;
        }
    } while (_findnext(h, &file_info) != -1);
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
    if (__chdrive(drive) == 0) {
        this->currentDriveValue = drive;
        return 1;
    }
    return 0;
}

int DriveInformation::changeDirectory(char* path)
{
    if (__chdir(path) == 0) {
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

    getcwd(fullPath, 0x104);
    splitpath(fullPath, cDrive, this->currentDirectoryValue, filename,
              extension);
    sprintf(this->currentDirectoryValue, "%s%s%s",
            this->currentDirectoryValue, filename, extension);
}
