// VA: 00446340 TDrawArea::GetPalette (40 B)
// PDB source: Drawarea.cpp
// Copies palette entries from DrawSystem to the output buffer

#include <string.h>

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem {
public:
    char gap_00[0x78];
    tagPALETTEENTRY Palette[256];  // +0x78
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;   // +0x00

    void GetPalette(tagPALETTEENTRY* entries);
};

void TDrawArea::GetPalette(tagPALETTEENTRY* entries)
{
    for (int i = 0; i < 256; ++i)
        entries[i] = this->DrawSystem->Palette[i];
}
