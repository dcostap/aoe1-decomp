// VA: 00446370 TDrawArea::SetPalette (61 B)
// PDB source: Drawarea.cpp
// Sets entry 0 to black, entry 255 to white, then calls ModifyPalette

#ifndef DRAWAREA_CANONICAL_TU
struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem {
public:
    void ModifyPalette(int start, int count, tagPALETTEENTRY* entries);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;   // +0x00

    void SetPalette(tagPALETTEENTRY* entries);
};
#endif

void TDrawArea::SetPalette(tagPALETTEENTRY* entries)
{
    entries[0].peRed = 0;
    entries[0].peGreen = 0;
    entries[0].peBlue = 0;
    entries[0].peFlags = 0;

    entries[255].peRed = 0xFF;
    entries[255].peGreen = 0xFF;
    entries[255].peBlue = 0xFF;
    entries[255].peFlags = 0;

    this->DrawSystem->ModifyPalette(0, 256, entries);
}
