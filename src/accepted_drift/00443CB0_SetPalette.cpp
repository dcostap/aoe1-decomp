// VA: 00443CB0 TDrawSystem::SetPalette (144 B)
// PDB source: Drawarea.cpp
// Sets the palette — loads entries from HPALETTE or zeroes them, then calls ModifyPalette

#ifndef DRAWAREA_CANONICAL_TU
#pragma pack(push, 1)
struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
#pragma pack(pop)

__declspec(dllimport) int __stdcall GetPaletteEntries(void* hPal, int start, int count, void* entries);

class TDrawSystem {
public:
    char gap_00[0x08];
    void* Pal;                      // +0x08
    char gap_0C[0x478 - 0x0C];

    void ModifyPalette(int start, int count, void* entries);
};
#endif

void __fastcall SetPalette(void* _this, int _, void* hPal)
{
    TDrawSystem* self = (TDrawSystem*)_this;
    tagPALETTEENTRY color_table[256];
    tagPALETTEENTRY* p;
    int count;
    
    self->Pal = hPal;
    
    if (hPal) {
        GetPaletteEntries(hPal, 0, 0x100, color_table);
    } else {
        p = color_table;
        count = 0x100;
        do {
            p->peRed = 0;
            p->peGreen = 0;
            p->peBlue = 0;
            p->peFlags = 0;
            p++;
            count--;
        } while (count != 0);
    }
    
    color_table[0].peRed = 0;
    color_table[0].peGreen = 0;
    color_table[0].peBlue = 0;
    color_table[0].peFlags = 0;
    
    color_table[255].peRed = 0xFF;
    color_table[255].peGreen = 0xFF;
    color_table[255].peBlue = 0xFF;
    color_table[255].peFlags = 0;
    
    self->ModifyPalette(0, 0x100, color_table);
}
