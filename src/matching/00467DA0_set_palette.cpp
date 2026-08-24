// VA: 00467DA0, TEasy_Panel::set_palette, 321 bytes
// Source: Panel_ez.cpp lines 693-721
// FLAGS: /GX (SEH — uses new RGE_Color_Table(...))

#include <stddef.h>

typedef unsigned long DWORD;
typedef unsigned char BYTE;

#ifndef AOE1_PANEL_EZ_CONTEXT_H
struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
};

extern "C" int __cdecl stricmp(const char* str1, const char* str2);
extern "C" __declspec(dllimport) DWORD __stdcall GetPaletteEntries(
    void* hpal, DWORD iStartIndex, DWORD nEntries, tagPALETTEENTRY* lppe);
#endif

// TDrawArea forward declaration
struct TDrawArea;

// RGE_Color_Table (size 0x128, with compiler-added vtable pointer)
// Type dump shows vtable_ptr at +0x00, total 0x128.
// With virtual declared, VC5 adds its own vtable (4 bytes).
// So explicit data = 0x128 - 4 = 0x124.
#ifndef AOE1_PANEL_EZ_CONTEXT_H
class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();

    RGE_Color_Table(TDrawArea* draw_area, long shadow_amount, void* flag, tagPALETTEENTRY* palette_entries);

private:
    char pad_000[0x124];
};

// TPanelSystem class
class TPanelSystem {
public:
    void release_palette(void* palette);
    void* get_palette(char* name, long id);
};

extern TPanelSystem panel_system;

class TEasy_Panel {
public:
    char pad_000[0x20C];
    void* palette;                      // +0x20C
    char pad_210[0x23C];                // 0x210 to 0x44B
    RGE_Color_Table* shadow_color_table; // +0x44C
    long shadow_amount;                 // +0x450

    int set_palette(char* param_1, long param_2);
};
#endif

int TEasy_Panel::set_palette(char* param_1, long param_2)
{
    // Release existing palette
    if (this->palette != 0) {
        panel_system.release_palette(this->palette);
        this->palette = 0;
    }

    // Delete existing shadow color table
    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    // Check if param_2 is -1 (use default/none)
    if (param_2 == -1) {
        if (param_1 != 0 && *param_1 != '\0') {
            if (stricmp(param_1, "none") == 0) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    // Get palette from panel system
    void* p = panel_system.get_palette(param_1, param_2);
    this->palette = p;
    if (p == 0 || this->shadow_amount <= 0) {
        return 0;
    }

    // Read palette entries
    tagPALETTEENTRY palette_entries[256];
    if (GetPaletteEntries(p, 0, 0x100, palette_entries) != 0) {
        // Create shadow color table
        this->shadow_color_table = new RGE_Color_Table(
            *(TDrawArea**)((char*)this + 0x20),
            this->shadow_amount,
            0,
            palette_entries);
    }
    return 1;
}
