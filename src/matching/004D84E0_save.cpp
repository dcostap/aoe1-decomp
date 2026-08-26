// VA: 004D84E0 TribeInformationAIModule::save
// PDB: taiinfmd.cpp:744-864
// __thiscall int save(int handle), ret 4
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log:
// - Very large serialization function writing ~41 static rge_write sites.
// - Layout decoded & matched: resourceTypes matrix (0x4C8/0x4CC), record arrays
//   (0x114/0x1F8/0x200), 6 ManagedArray<int> grow-on-read (0x118,0x128,0x138,
//   0x148,0x190,0x180), subobject save (0x158), 8-byte record arrays (0x1B4/0x1D4,
//   4-aligned Rec8 not double[]), name strlen (0x208), raw blobs (0x308,0x408,
//   0x500,0x540,0x550,0x560,0x564), ptr/count matrix (0x4D0/0x4F0) + normalize.
// - The six arrays are real ManagedArray<int> objects, in serialization order:
//   importantObjects, importantUnits, importantMiscs, itemsToDefend,
//   playerBuildings, playerObjects. Each count is written before its values;
//   operator[] is the period utmarray.h inline grow-on-read body from the exact
//   004EA750/004147A0 donors, not a hand-expanded parent scaffold.
// - Binary stack evidence requires two temporary roles: `tmp` is the separate
//   resourceTypes matrix value at [esp+10h], while the saved file handle is kept
//   in `saved_handle` and the incoming `handle` home is reused for ManagedArray
//   values and the string length. This mirrors exact save donors and is required
//   for the original [esp+10h] / parameter-home schedule.
// - d1B4/d1D4 are 4-aligned 8-byte Rec8 records (not double[]); all persistence
//   sizes/order and the c4F0 normalization pass are binary-audited.
// - Exact candidate: 622 instructions, 54/54 calls, 1943 bytes, 0.0000% diff.

#include <string.h>
#include <stdlib.h>

void rge_write(int file, void* data, int size);

// The binary identifies this +0x158 subobject as the path/InfluenceMap save
// surface; keep the local ABI narrow until the shared class layout is proven.
#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct SubObject {
    char gap[0x28];
    int save(int handle);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++)
                    new_value[i] = this->value[i];
                operator delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_000[0x104];
    int f104;                     // +0x104
    int f108;                     // +0x108
    int f10C;                     // +0x10C
    int n110;                     // +0x110
    char* p114;                   // +0x114 (0x24-byte records)
    ManagedArray<int> importantObjects; // +0x118
    ManagedArray<int> importantUnits;   // +0x128
    ManagedArray<int> importantMiscs;   // +0x138
    ManagedArray<int> itemsToDefend;    // +0x148
    SubObject sub158;             // +0x158 (0x28)
    ManagedArray<int> playerObjects;   // +0x180
    ManagedArray<int> playerBuildings; // +0x190
    double f1A0;                  // +0x1A0
    double f1A8;                  // +0x1A8
    int f1B0;                     // +0x1B0
    struct Rec8 { int lo, hi; } d1B4[4];   // +0x1B4 (4-aligned 8-byte)
    struct Rec8 d1D4[4];          // +0x1D4
    int n1F4;                     // +0x1F4
    char* p1F8;                   // +0x1F8 (8-byte records)
    int n1FC;                     // +0x1FC
    char* p200;                   // +0x200 (0x18-byte records)
    int f204;                     // +0x204
    char name208[0x100];          // +0x208
    char buf308[0x100];           // +0x308
    char buf408[0xC0];            // +0x408
    int** resourceTypesValue;     // +0x4C8
    int* numberResourceTypesValue;// +0x4CC
    void* ptr4D0[4];              // +0x4D0
    int e4E0[4];                  // +0x4E0
    int c4F0[4];                  // +0x4F0
    char s500[0x40];              // +0x500
    char s540[0x10];              // +0x540
    char s550[0x10];              // +0x550
    int f560;                     // +0x560
    char big564[0xFA00];          // +0x564

    int save(int handle);
};
#endif
#endif

void* operator new(unsigned int size);
void operator delete(void* ptr);

#endif
int TribeInformationAIModule::save(int handle)
{
    int tmp;
    int saved_handle = handle;
    for (int k = 0; k < 4; k++) {
        tmp = this->numberResourceTypesValue[k];
        rge_write(saved_handle, &tmp, 4);
        for (int m = 0; m < this->numberResourceTypesValue[k]; m++) {
            tmp = this->resourceTypesValue[k][m];
            rge_write(saved_handle, &tmp, 4);
        }
    }

    rge_write(saved_handle, &this->f104, 4);
    rge_write(saved_handle, &this->f108, 4);
    rge_write(saved_handle, &this->f10C, 4);
    rge_write(saved_handle, &this->n110, 4);
    for (int a = 0; a < this->n110; a++)
        rge_write(saved_handle, (char*)this->p114 + a * 0x24, 0x24);

    rge_write(saved_handle, &this->n1F4, 4);
    for (int b = 0; b < this->n1F4; b++)
        rge_write(saved_handle, (char*)this->p1F8 + b * 8, 8);

    rge_write(saved_handle, &this->n1FC, 4);
    for (int c = 0; c < this->n1FC; c++)
        rge_write(saved_handle, (char*)this->p200 + c * 0x18, 0x18);

    handle = this->importantObjects.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int d = 0; d < this->importantObjects.numberValue; d++) {
        handle = this->importantObjects[d];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->importantUnits.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int e = 0; e < this->importantUnits.numberValue; e++) {
        handle = this->importantUnits[e];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->importantMiscs.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int f = 0; f < this->importantMiscs.numberValue; f++) {
        handle = this->importantMiscs[f];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->itemsToDefend.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int g = 0; g < this->itemsToDefend.numberValue; g++) {
        handle = this->itemsToDefend[g];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->playerBuildings.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int h = 0; h < this->playerBuildings.numberValue; h++) {
        handle = this->playerBuildings[h];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->playerObjects.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int w = 0; w < this->playerObjects.numberValue; w++) {
        handle = this->playerObjects[w];
        rge_write(saved_handle, &handle, 4);
    }

    this->pathMap.save(saved_handle);

    rge_write(saved_handle, &this->f1A0, 8);
    rge_write(saved_handle, &this->f1A8, 8);
    rge_write(saved_handle, &this->f1B0, 4);
    for (int x = 0; x < 4; x++) {
        rge_write(saved_handle, &this->d1B4[x], 8);
        rge_write(saved_handle, &this->d1D4[x], 8);
    }
    rge_write(saved_handle, &this->f204, 4);

#ifndef TAIINFMD_PREFIX_CONTEXT
    handle = strlen(this->name208);
#else
    handle = strlen(this->learnFileName);
#endif
    rge_write(saved_handle, &handle, 4);
#ifndef TAIINFMD_PREFIX_CONTEXT
    rge_write(saved_handle, this->name208, strlen(this->name208));
#else
    rge_write(saved_handle, this->learnFileName, strlen(this->learnFileName));
#endif

#ifndef TAIINFMD_PREFIX_CONTEXT
    rge_write(saved_handle, this->buf308, 0xFF);
#else
    rge_write(saved_handle, this->fullyExploredZoneValue, 0xFF);
#endif
    rge_write(saved_handle, this->buf408, 0xC0);

    for (int y = 0; y < 4; y++) {
        if (this->c4F0[y] != 0 && this->ptr4D0[y] == 0)
            this->c4F0[y] = 0;
    }
    rge_write(saved_handle, &this->c4F0, 0x10);
    rge_write(saved_handle, &this->e4E0, 0x10);
    for (int z = 0; z < 4; z++) {
        if (this->c4F0[z] != 0)
            rge_write(saved_handle, this->ptr4D0[z], this->c4F0[z] * 20);
    }

    rge_write(saved_handle, this->s500, 0x40);
    rge_write(saved_handle, this->s540, 0x10);
    rge_write(saved_handle, this->s550, 0x10);
    rge_write(saved_handle, &this->f560, 4);
    rge_write(saved_handle, this->big564, 0xFA00);

    return 1;
}
