#include "../include/ResourceItem.h"

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00411EC0
ResourceItem::ResourceItem() {
    int* piVar1;
    int iVar2;

    iVar2 = 8;
    this->next = nullptr;
    this->prev = nullptr;
    this->numberValue = 0;
    piVar1 = this->sortedValue;
    do {
        piVar1[-8] = -1;
        *piVar1 = -1;
        piVar1[8] = -1;
        piVar1 = piVar1 + 1;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00411F10
ResourceItem::ResourceItem(int param_1) {
    int* piVar1;
    int iVar2;

    iVar2 = 0;
    this->next = nullptr;
    this->prev = nullptr;
    this->numberValue = param_1;
    if (0 < param_1) {
        piVar1 = this->sortedValue;
        do {
            if (7 < iVar2) {
                return;
            }
            piVar1[-8] = 0;
            *piVar1 = -1;
            piVar1[8] = -1;
            iVar2 = iVar2 + 1;
            piVar1 = piVar1 + 1;
        } while (iVar2 < this->numberValue);
    }
    if (iVar2 < 8) {
        piVar1 = this->sortedValue + iVar2;
        iVar2 = 8 - iVar2;
        do {
            piVar1[-8] = -1;
            *piVar1 = -1;
            piVar1[8] = -1;
            piVar1 = piVar1 + 1;
            iVar2 = iVar2 - 1;
        } while (iVar2 != 0);
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00411F80
ResourceItem::ResourceItem(int param_1, int* param_2) {
    int* piVar1;
    int iVar2;

    iVar2 = 0;
    this->next = nullptr;
    this->prev = nullptr;
    this->numberValue = param_1;
    if (0 < param_1) {
        piVar1 = this->sortedValue;
        do {
            if (7 < iVar2) {
                return;
            }
            iVar2 = iVar2 + 1;
            piVar1[-8] = *param_2;
            *piVar1 = -1;
            piVar1[8] = -1;
            param_2 = param_2 + 1;
            piVar1 = piVar1 + 1;
        } while (iVar2 < this->numberValue);
    }
    if (iVar2 < 8) {
        piVar1 = this->sortedValue + iVar2;
        iVar2 = 8 - iVar2;
        do {
            piVar1[-8] = -1;
            *piVar1 = -1;
            piVar1[8] = -1;
            piVar1 = piVar1 + 1;
            iVar2 = iVar2 - 1;
        } while (iVar2 != 0);
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00411FF0
ResourceItem::ResourceItem(const ResourceItem& param_1) {
    int iVar1;
    int iVar4;

    iVar4 = 0;
    this->next = nullptr;
    this->prev = nullptr;
    iVar1 = param_1.numberValue;
    this->numberValue = iVar1;
    if (0 < iVar1) {
        do {
            if (7 < iVar4) {
                return;
            }
            this->valueValue[iVar4] = param_1.valueValue[iVar4];
            this->sortedValue[iVar4] = param_1.sortedValue[iVar4];
            this->sortedIndexValue[iVar4] = param_1.sortedIndexValue[iVar4];
            iVar4 = iVar4 + 1;
        } while (iVar4 < this->numberValue);
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412050
ResourceItem::ResourceItem(ResourceItem* param_1) {
    int iVar1;
    int iVar4;

    iVar4 = 0;
    this->next = nullptr;
    this->prev = nullptr;
    iVar1 = param_1->numberValue;
    this->numberValue = iVar1;
    if (0 < iVar1) {
        do {
            if (7 < iVar4) {
                return;
            }
            this->valueValue[iVar4] = param_1->valueValue[iVar4];
            this->sortedValue[iVar4] = param_1->sortedValue[iVar4];
            this->sortedIndexValue[iVar4] = param_1->sortedIndexValue[iVar4];
            iVar4 = iVar4 + 1;
        } while (iVar4 < this->numberValue);
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004120B0
ResourceItem::~ResourceItem() {}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004120C0
ResourceItem& ResourceItem::operator+=(const ResourceItem& param_1) {
    int iVar2;
    int* piVar1;

    if ((this->numberValue == param_1.numberValue) && ((iVar2 = 0, 0 < this->numberValue))) {
        piVar1 = this->valueValue;
        do {
            iVar2 = iVar2 + 1;
            *piVar1 = *piVar1 + param_1.valueValue[iVar2 - 1];
            piVar1 = piVar1 + 1;
        } while (iVar2 < this->numberValue);
    }
    return *this;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412100
int operator==(const ResourceItem& param_1, const ResourceItem& param_2) {
    int iVar1;
    int iVar3;
    const int* piVar2;

    iVar1 = param_1.numberValue;
    if (iVar1 != param_2.numberValue) {
        return 0;
    }
    iVar3 = 0;
    if (0 < iVar1) {
        piVar2 = param_1.valueValue;
        do {
            if (*piVar2 != param_2.valueValue[iVar3]) {
                return 0;
            }
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 1;
        } while (iVar3 < iVar1);
    }
    return 1;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412140
int operator!=(const ResourceItem& param_1, const ResourceItem& param_2) {
    int iVar1;
    int iVar3;
    const int* piVar2;

    iVar1 = param_1.numberValue;
    if (iVar1 != param_2.numberValue) {
        return 1;
    }
    iVar3 = 0;
    if (0 < iVar1) {
        piVar2 = param_1.valueValue;
        do {
            if (*piVar2 != param_2.valueValue[iVar3]) {
                return 1;
            }
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 1;
        } while (iVar3 < iVar1);
    }
    return 0;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412180
int ResourceItem::value(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberValue)) {
        return this->valueValue[param_1];
    }
    return -1;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004121A0
void ResourceItem::setValue(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < this->numberValue)) {
        this->valueValue[param_1] = param_2;
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004121C0
void ResourceItem::incrementValue(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < this->numberValue)) {
        this->valueValue[param_1] = this->valueValue[param_1] + param_2;
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x004121E0
void ResourceItem::setAllValues(int param_1) {
    int iVar1;
    int* piVar2;

    piVar2 = this->valueValue;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *piVar2 = param_1;
        piVar2 = piVar2 + 1;
    }
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412200
int ResourceItem::number() const {
    return this->numberValue;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412210
int ResourceItem::largestValueIndex(int param_1) {
    int iVar1;

    if (param_1 <= this->numberValue) {
        iVar1 = this->sortLarge();
        if (iVar1 == 1) {
            return this->sortedValue[param_1 + 7];
        }
    }
    return -1;
}

// Fully verified. Source of truth: airesitm.cpp.decomp @ 0x00412240
int ResourceItem::sortLarge() {
    int iVar1;
    int iVar3;
    int iVar4;
    int iVar5;
    int local_c;

    iVar4 = 0;
    if (0 < this->numberValue) {
        do {
            this->sortedValue[iVar4] = this->valueValue[iVar4];
            this->sortedIndexValue[iVar4] = iVar4;
            iVar4 = iVar4 + 1;
        } while (iVar4 < this->numberValue);
    }
    iVar4 = this->numberValue;
    local_c = 0;
    if (0 < iVar4) {
        do {
            iVar1 = local_c + 1;
            iVar5 = local_c;
            if (iVar1 < iVar4) {
                iVar3 = iVar1;
                do {
                    if (this->sortedValue[iVar5] < this->sortedValue[iVar3]) {
                        iVar5 = iVar3;
                    }
                    iVar3 = iVar3 + 1;
                } while (iVar3 < iVar4);
            }
            if (iVar5 != local_c) {
                iVar4 = this->sortedValue[local_c];
                this->sortedValue[local_c] = this->sortedValue[iVar5];
                this->sortedValue[iVar5] = iVar4;
                iVar4 = this->sortedIndexValue[local_c];
                this->sortedIndexValue[local_c] = this->sortedIndexValue[iVar5];
                this->sortedIndexValue[iVar5] = iVar4;
            }
            iVar4 = this->numberValue;
            local_c = iVar1;
        } while (iVar1 < iVar4);
    }
    return 1;
}
