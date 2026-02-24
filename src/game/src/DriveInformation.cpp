// Auto-transliterated from src/game/decomp/file_stf.cpp.decomp
// ASM audited vs src/game/decomp/file_stf.cpp.asm where noted.

#include "../include/DriveInformation.h"

#include <direct.h>
#include <io.h>
#include <string.h>

// Offset: 0x00449750
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449750
char driveAsLetter(int param_1) {
    return (char)param_1 + '@';
}

// Offset: 0x00449760
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449760
int driveAsInt(char param_1) {
    // ASM uses MOVSX (sign-extend) on the incoming byte.
    return (int)(signed char)param_1 - 0x40;
}

// Offset: 0x00449770
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449770
DriveInformation::DriveInformation() {
    char cVar1;
    int iVar2;
    uint uVar3;
    uint uVar4;
    char* pcVar5;
    char* pcVar6;

    iVar2 = _getdrive();
    this->initialDriveValue = iVar2;
    this->currentDriveValue = iVar2;
    this->updateDirectory();

    uVar3 = 0xffffffff;
    pcVar5 = this->currentDirectoryValue;
    do {
        pcVar6 = pcVar5;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
    } while (cVar1 != '\0');

    uVar3 = ~uVar3;
    pcVar5 = pcVar6 - (int)uVar3;
    pcVar6 = this->initialDirectoryValue;

    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint*)pcVar6 = *(uint*)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
    }
}

// Offset: 0x004497C0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x004497C0
int DriveInformation::initialDrive() const {
    return this->initialDriveValue;
}

// Offset: 0x004497D0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x004497D0
char DriveInformation::initialDriveAsLetter() const {
    return (char)this->initialDriveValue + '@';
}

// Offset: 0x004497E0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x004497E0
char* DriveInformation::initialDirectory() {
    return this->initialDirectoryValue;
}

// Offset: 0x004497F0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x004497F0
int DriveInformation::currentDrive() const {
    return this->currentDriveValue;
}

// Offset: 0x00449800
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449800
char DriveInformation::currentDriveAsLetter() const {
    return (char)this->currentDriveValue + '@';
}

// Offset: 0x00449810
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449810
char* DriveInformation::currentDirectory() {
    return this->currentDirectoryValue;
}

// Offset: 0x00449820
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449820
int DriveInformation::numberDrives() const {
    return this->driveValues[0];
}

// Offset: 0x00449830
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449830
int DriveInformation::validDrive(int param_1) const {
    return this->driveValues[param_1];
}

// Offset: 0x00449840
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449840
void DriveInformation::checkDrives() {
    int iVar1;
    int* piVar2;
    int iVar3;

    this->driveValues[0] = 0;
    iVar3 = 1;
    piVar2 = this->driveValues;
    do {
        piVar2 = piVar2 + 1;
        iVar1 = _chdrive(iVar3);
        if (iVar1 == 0) {
            this->driveValues[0] = this->driveValues[0] + 1;
            *piVar2 = 1;
        } else {
            *piVar2 = 0;
        }
        iVar3 = iVar3 + 1;
    } while (iVar3 < 0x1b);

    _chdrive(this->currentDriveValue);
}

// Offset: 0x004498A0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x004498A0
int DriveInformation::numberOfFilesWithFilename(char* param_1) {
    int iVar2;
    int iVar3;
    struct _finddata_t fileInfo;

    intptr_t iVar1 = _findfirst(param_1, &fileInfo);
    if (iVar1 != -1) {
        iVar3 = 1;
        iVar2 = _findnext(iVar1, &fileInfo);
        while (iVar2 != -1) {
            iVar3 = iVar3 + 1;
            iVar2 = _findnext(iVar1, &fileInfo);
        }
        return iVar3;
    }
    return 0;
}

// Offset: 0x00449910
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449910
int DriveInformation::numberOfFilesWithAttribute(int param_1) {
    int iVar2;
    int iVar3;
    struct _finddata_t fileInfo;

    intptr_t iVar1 = _findfirst("*.*", &fileInfo);
    if (iVar1 == -1) {
        return 0;
    }
    iVar3 = 1;
    iVar2 = _findnext(iVar1, &fileInfo);
    while (iVar2 != -1) {
        if (((int)fileInfo.attrib & param_1) != 0) {
            iVar3 = iVar3 + 1;
        }
        iVar2 = _findnext(iVar1, &fileInfo);
    }
    return iVar3;
}

// Offset: 0x00449990
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449990
int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* param_1, int param_2) {
    int iVar2;
    int iVar3;
    struct _finddata_t fileInfo;

    // NOTE: ASM uses fileInfo+0x18 for strstr; this matches the name field in the repo's CRT struct layout.
    intptr_t iVar1 = _findfirst("*.*", &fileInfo);
    if (iVar1 == -1) {
        return 0;
    }
    iVar3 = 1;
    iVar2 = _findnext(iVar1, &fileInfo);
    while (iVar2 != -1) {
        if ((((int)fileInfo.attrib & param_2) != 0) || (strstr(fileInfo.name, param_1) != 0)) {
            iVar3 = iVar3 + 1;
        }
        iVar2 = _findnext(iVar1, &fileInfo);
    }
    return iVar3;
}

// Offset: 0x00449A20
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449A20
int DriveInformation::resetCurrentDriveAndDirectory() {
    int iVar1;

    iVar1 = this->resetCurrentDrive();
    if (iVar1 != 0) {
        iVar1 = this->resetCurrentDirectory();
        return iVar1;
    }
    return 0;
}

// Offset: 0x00449A40
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449A40
int DriveInformation::resetCurrentDrive() {
    int iVar1;

    iVar1 = this->changeDrive(this->initialDriveValue);
    return iVar1;
}

// Offset: 0x00449A50
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449A50
int DriveInformation::resetCurrentDirectory() {
    int iVar1;

    iVar1 = this->changeDirectory(this->initialDirectoryValue);
    return iVar1;
}

// Offset: 0x00449A60
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449A60
int DriveInformation::changeDrive(int param_1) {
    int iVar1;

    iVar1 = _chdrive(param_1);
    if (iVar1 == 0) {
        this->currentDriveValue = param_1;
        return 1;
    }
    return 0;
}

// Offset: 0x00449A90
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449A90
int DriveInformation::changeDirectory(char* param_1) {
    int iVar1;

    iVar1 = _chdir(param_1);
    if (iVar1 == 0) {
        this->updateDirectory();
        return 1;
    }
    return 0;
}

// Offset: 0x00449AC0
// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449AC0
void DriveInformation::updateDirectory() {
    char* pcVar1;

    // These buffers intentionally include a 4-byte prefix to match the original stack usage (+4) seen in ASM.
    char extension[0x104];
    char filename[0x104];
    char fullPath[0x108];

    _getcwd(fullPath + 4, 0x104);
    pcVar1 = this->currentDirectoryValue;
    _splitpath(fullPath + 4, extension, pcVar1, filename + 4, extension + 4);
    sprintf(pcVar1, "%s%s%s", pcVar1, filename + 4, extension + 4);
}

