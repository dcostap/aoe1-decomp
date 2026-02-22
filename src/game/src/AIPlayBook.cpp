#include "../include/AIPlayBook.h"

#include <stdio.h>
#include <string.h>

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004101B0
AIPlayBook::AIPlayBook() {
    this->numberPlaysValue = 0;
    this->plays = nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004101F0
AIPlayBook::~AIPlayBook() {
    if (this->plays != nullptr) {
        this->numberPlaysValue = 0;
        operator delete(this->plays);
        this->plays = nullptr;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411480
int AIPlayBook::convertTargetNameToIntType(char* param_1) {
    if (strcmp(param_1, "Any") == 0) {
        return 5;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004114E0
int AIPlayBook::convertTargetCharacteristicNameToIntType(char* param_1) {
    if (strcmp(param_1, "Stationary") == 0) {
        return 1;
    }
    if (strcmp(param_1, "Moving") == 0) {
        return 2;
    }
    if (strcmp(param_1, "Slow") == 0) {
        return 3;
    }
    if (strcmp(param_1, "Fast") == 0) {
        return 4;
    }
    if (strcmp(param_1, "Any") == 0) {
        return 5;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411650
int AIPlayBook::convertUnitNameToIntType(char* param_1) {
    (void)param_1;
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411660
int AIPlayBook::convertUnitToIntType(RGE_Static_Object* param_1) {
    (void)param_1;
    return -1;
}

int AIPlayBook::loadPlays(char* param_1) {
    if (param_1 == nullptr) {
        strncpy(this->nameValue, "NULL", sizeof(this->nameValue) - 1);
        this->nameValue[sizeof(this->nameValue) - 1] = '\0';
        return 0;
    }

    if (strcmp(param_1, "NONE") == 0) {
        strncpy(this->nameValue, "NONE", sizeof(this->nameValue) - 1);
        this->nameValue[sizeof(this->nameValue) - 1] = '\0';
        return 0;
    }

    strncpy(this->nameValue, param_1, sizeof(this->nameValue) - 1);
    this->nameValue[sizeof(this->nameValue) - 1] = '\0';

    FILE* file = fopen(this->nameValue, "r");
    if (file == nullptr) {
        return 0;
    }

    if (this->plays != nullptr) {
        operator delete(this->plays);
        this->plays = nullptr;
    }
    this->numberPlaysValue = 0;
    fclose(file);

    // TODO: STUB: Full .ply parsing from aipbook.cpp.decomp @ 0x00410220 is not transliterated yet.
    return 1;
}
