// VA: 00443D40 TDrawSystem::ModifyPalette (149 B)
// PDB source: Drawarea.cpp lines 1610-1680
// Copies palette entries into internal array and calls IDirectDrawPalette::SetEntries
//
// Key: palette entries are at [this+0x78], DrawType at [this+0x478],
// DirDrawPal at [this+0x24]. PALETTEENTRY is 4 bytes.

extern int PalSetRes;
extern int FullPalSets;
extern int AniPalSets;

#ifndef DRAWAREA_CANONICAL_TU
#pragma pack(push, 1)
struct PALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
#pragma pack(pop)

struct IDirectDrawPaletteVtbl {
    void* queryInterface;
    void* addRef;
    void* release;
    void* getCaps;
    void* getEntries;
    void* initialize;
    void* setEntries;   // index 6, vtable offset 0x18
    void* reserve1;
};

struct IDirectDrawPalette {
    IDirectDrawPaletteVtbl* lpVtbl;
};

class TDrawSystem {
public:
    char gap_00[0x24];
    IDirectDrawPalette* DirDrawPal; // +0x24
    char gap_28[0x78 - 0x28];
    PALETTEENTRY palette[256];       // +0x78
    char DrawType;                   // +0x478
    // ... more fields follow

    void ModifyPalette(int start, int count, PALETTEENTRY* entries);
};
#endif

void TDrawSystem::ModifyPalette(int start, int count, PALETTEENTRY* entries) {
    PalSetRes = -99;
    
    if (count == 256) {
        FullPalSets++;
    }
    
    for (int i = start; i < start + count; i++) {
        palette[i] = entries[i - start];
    }
    
    if (DrawType != 1 && DirDrawPal != 0) {
        if (count == 7) {
            AniPalSets++;
        }
        typedef void (__stdcall* SetEntriesFunc)(IDirectDrawPalette*, unsigned, unsigned, unsigned, PALETTEENTRY*);
        ((SetEntriesFunc)DirDrawPal->lpVtbl->setEntries)(DirDrawPal, 0, start, count, entries);
    }
}
