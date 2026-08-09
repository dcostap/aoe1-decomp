// VA: 00444C30 TDrawArea::SetClipRect (279 B)
// Attempt log:
// Baseline scaffold had free helper calls and no C++ EH/new surface.  The
// executable shows the Drawarea.cpp member plus the real TSpan_List_Manager
// constructor/destructor/method calls, so this reconstruction uses those
// period-plausible class surfaces and the proven +28 ClipRect/+CC SpanList
// ownership.
// FLAGS: config/flags/00444C30_SetClipRect.rsp (/GX; original has C++ EH/new state)
// Probe: natural member/new/delete reconstruction reached size 279, all 7 calls,
// and diff 28; reversed the manager-lines/height compare to preserve its observed
// load family, and used the member guard to retain the binary's redundant null test.
// Probe: PDB/inventory long spellings and the full 0x100-byte TDrawArea surface
// emitted unchanged code; these are retained as canonical ownership context.
// Probe: a per-row pointer alias improved diff to 26 but moved the AddSpan manager
// load before all pushes and was rolled back to the direct member call.
// Probe: two 32-variant natural source-shape labs (one with /GX) found no exact;
// local call aliases only changed scheduling, so the direct typed member form stays.
// Session probes: a narrow SetSpanRegions receiver alias reduced drift to 21
// bytes and made the AddSpan tail exact; argument-local, reference-receiver,
// comparison-reversal, and temporary-order variants were worse or duplicate.
// This session confirmed direct receiver use regresses to 28 bytes; restoring
// the alias, reusing span_list, and modeling ClipRect as tagRECT all remain at
// the same 21-byte localized SetSpanRegions setup drift.
// Remaining drift is localized register/load scheduling at the comparison, ctor
// arguments, SetSpanRegions/AddSpan argument setup, and final CurSpanList reload.
// Main-agent audit confirmed canonical draw-area/span-list ownership and retained
// the natural clip-region rebuild.

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;       // +0x00
    int* Zone_Size_Ptrs;          // +0x04
    long Used_Zones;              // +0x08
    long Max_Zones;               // +0x0C
    VSpan_Node* Free_Head;        // +0x10
    long Free_Pool_Zone;          // +0x14
    long Free_Pool_Index;         // +0x18
    long Total_Blocks;             // +0x1C
    long Free_Blocks;             // +0x20
    long Default_Grow_Size;        // +0x24
    long Element_Size;             // +0x28
    long Alloc_Count;              // +0x2C
    long Dealloc_Count;            // +0x30
    long NewZone_Count;            // +0x34
    long Reset_Count;              // +0x38

    ~TSpan_Node_List();
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    VSpan_Node** Line_Head_Ptrs;  // +0x3C
    VSpan_Node** Line_Tail_Ptrs;  // +0x40
    long* LeftMostPx;             // +0x44
    long* RightMostPx;            // +0x48
    long* Span_Count;             // +0x4C
    long Num_Lines;               // +0x50
    long Num_Pixels;              // +0x54
    long Min_Span_Px;             // +0x58
    long Max_Span_Px;             // +0x5C
    long Min_Line;                // +0x60
    long Max_Line;                // +0x64

    TSpan_List_Manager(long NumPixels, long NumLines);
    ~TSpan_List_Manager();
    void ResetAll();
    void SetSpanRegions(long left, long top, long right, long bottom);
    void AddSpan(long left, long right, long y);
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void* DrawSystem;             // +0x00
    void* Wnd;                    // +0x04
    unsigned char* Bits;          // +0x08
    void* BitmapInfo;             // +0x0C
    void* Bitmap;                 // +0x10
    void* OldBitmap;              // +0x14
    long Width;                   // +0x18
    long Height;                  // +0x1C
    long Pitch;                   // +0x20
    long Orien;                   // +0x24
    tagRECT ClipRect;              // +0x28
    void* DrawDc;                 // +0x38
    void* DrawSurface;            // +0x3C
    char SurfaceDesc[0x6C];       // +0x40
    void* Node;                   // +0xAC
    char* Name;                   // +0xB0
    unsigned char* LastBits;      // +0xB4
    long LastPitch;               // +0xB8
    void** DisplayOffsets;        // +0xBC
    void** CurDisplayOffsets;     // +0xC0
    void** FloatOffsets;          // +0xC4
    void* shadow_color_table;     // +0xC8
    TSpan_List_Manager* SpanList; // +0xCC
    TSpan_List_Manager* CurSpanList; // +0xD0
    long Float_X_Delta;           // +0xD4
    long Float_Y_Delta;           // +0xD8
    long DisplayOffsetsSz;        // +0xDC
    long FloatOffsetsSz;           // +0xE0
    long SystemMemOnly;           // +0xE4
    long UsingVidMem;             // +0xE8
    long UseTrans;                // +0xEC
    long IsPrimarySurface;        // +0xF0
    long Restored;                // +0xF4
    long ExtendedLines;           // +0xF8
    unsigned char TransColor;     // +0xFC
    unsigned char gap_FD[0x03];

    void SetClipRect(long left, long top, long right, long bottom);
};

void TDrawArea::SetClipRect(long left, long top, long right, long bottom)
{
    TSpan_List_Manager* span_list = this->SpanList;

    this->ClipRect.left = left;
    this->ClipRect.top = top;
    this->ClipRect.right = right;
    this->ClipRect.bottom = bottom;

    if (span_list != 0 && span_list->Num_Lines != this->Height) {
        if (this->SpanList != 0) {
            delete this->SpanList;
        }
        this->SpanList = 0;
    }

    if (this->SpanList == 0) {
        span_list = new TSpan_List_Manager(this->Width, this->Height);
        this->SpanList = span_list;
    }

    this->SpanList->ResetAll();
    span_list = this->SpanList;
    span_list->SetSpanRegions(this->ClipRect.left, this->ClipRect.top,
                              this->ClipRect.right, this->ClipRect.bottom);

    int y = this->ClipRect.top;
    if (y <= this->ClipRect.bottom) {
        do {
            this->SpanList->AddSpan(this->ClipRect.left, this->ClipRect.right, y);
            ++y;
        } while (y <= this->ClipRect.bottom);
    }

    this->CurSpanList = this->SpanList;
}
