#include "../include/common.h"
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>

// Fully verified. Source of truth: mystring.cpp.decomp @ 0x00462D70
void convert_us(char* param_1) {
    char* pcVar1;
    char cVar2;

    cVar2 = *param_1;
    while (cVar2 != '\0') {
        if (cVar2 == '_') {
            *param_1 = ' ';
        }
        pcVar1 = param_1 + 1;
        param_1 = param_1 + 1;
        cVar2 = *pcVar1;
    }
}

// Fully verified. Source of truth: mystring.cpp.decomp @ 0x00462D90
void unconvert_us(char* param_1) {
    char* pcVar1;
    char cVar2;

    cVar2 = *param_1;
    while (cVar2 != '\0') {
        if (cVar2 == ' ') {
            *param_1 = '_';
        }
        pcVar1 = param_1 + 1;
        param_1 = param_1 + 1;
        cVar2 = *pcVar1;
    }
}

// Fully verified. Source of truth: mystring.cpp.decomp @ 0x00462DB0
void addstring(char** param_1, char* param_2, char* param_3) {
    char cVar1;
    char* pcVar2;
    uint uVar3;
    uint uVar4;
    uint uVar5;
    char* pcVar6;

    uVar3 = 0xffffffff;
    pcVar6 = param_2;
    do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;

    uVar4 = 0xffffffff;
    pcVar6 = param_3;
    do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar4 - 1;

    pcVar2 = (char*)calloc((~uVar4) + uVar3, 1);
    pcVar6 = pcVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint32_t*)pcVar6 = *(uint32_t*)param_2;
        param_2 = param_2 + 4;
        pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *param_2;
        param_2 = param_2 + 1;
        pcVar6 = pcVar6 + 1;
    }
    pcVar6 = pcVar2 + uVar3;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint32_t*)pcVar6 = *(uint32_t*)param_3;
        param_3 = param_3 + 4;
        pcVar6 = pcVar6 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar6 = *param_3;
        param_3 = param_3 + 1;
        pcVar6 = pcVar6 + 1;
    }

    if (*param_1 != (char*)0x0) {
        free(*param_1);
    }
    *param_1 = pcVar2;
}

// Fully verified. Source of truth: mystring.cpp.decomp @ 0x00462E30
void getstring(char** param_1, char* param_2) {
    char cVar1;
    char* pcVar2;
    uint uVar3;
    uint uVar4;

    uVar3 = 0xffffffff;
    pcVar2 = param_2;
    do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    if (*param_1 != (char*)0x0) {
        free(*param_1);
    }
    pcVar2 = (char*)calloc(uVar3, 1);
    *param_1 = pcVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint32_t*)pcVar2 = *(uint32_t*)param_2;
        param_2 = param_2 + 4;
        pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *param_2;
        param_2 = param_2 + 1;
        pcVar2 = pcVar2 + 1;
    }
}

