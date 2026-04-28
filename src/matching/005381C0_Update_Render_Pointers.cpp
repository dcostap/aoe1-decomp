// 005381C0 Update_Render_Pointers (view.cpp:4254-4278)
// PDB source: view.cpp (RGE_View::Update_Render_Pointers)
//
// Attempt log:
// first pass: exact MATCH on first compile. Local TPanel/TDrawArea stubs with
// exact layout + natural control flow. 190 bytes, 0 diff, 2 masked relocations.

#include <stdlib.h>

// Local layout stubs. TPanel-sized base region (0x00-0xF3) + RGE_View fields.

struct TDrawArea_Stub {
    unsigned char _gap_00[0x08];
    unsigned char* Bits;            // +0x08
    unsigned char _gap_0C[0xB0];    // 0x0C-0xBB
    void** DisplayOffsets;          // +0xBC
};

class RGE_View {
public:
    // -- TPanel inherited region (0x00-0xF3) --
    unsigned char _gap_00[0x20];
    TDrawArea_Stub* render_area;    // +0x20 = TPanel::render_area
    unsigned char _gap_24[0x68];    // 0x24-0x8B
    int render_rect_left;           // +0x8C = TPanel::render_rect.left
    int render_rect_top;            // +0x90 = TPanel::render_rect.top
    int render_rect_right;          // +0x94 = TPanel::render_rect.right
    int render_rect_bottom;         // +0x98 = TPanel::render_rect.bottom
    unsigned char _gap_9C[0x28C];   // 0x9C-0x327

    // -- RGE_View fields --
    unsigned char* LastRenderBits;  // +0x328
    void** RenderOffsets;           // +0x32C
    int LastRenderSize;             // +0x330

    void Update_Render_Pointers();
};

void RGE_View::Update_Render_Pointers() {
    unsigned char* bits = render_area->Bits;

    if (LastRenderBits == bits) {
        int count = render_rect_bottom - render_rect_top + 1;
        if (LastRenderSize == count)
            return;
    }

    int count = render_rect_bottom - render_rect_top + 1;
    if (count <= 0 || bits == 0)
        return;

    if (count != LastRenderSize || RenderOffsets == 0) {
        if (RenderOffsets != 0)
            free(RenderOffsets);
        RenderOffsets = (void**)malloc(count * 4);
        LastRenderSize = count;
    }

    for (int i = 0; i < count; i++) {
        RenderOffsets[i] = (void*)((int)render_area->DisplayOffsets[i + render_rect_top] + render_rect_left);
    }
}
