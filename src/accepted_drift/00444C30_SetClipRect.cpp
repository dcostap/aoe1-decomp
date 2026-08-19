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
// This session reconfirmed that a direct tagRECT SpanList receiver regresses
// to 28 bytes, a Height/Num_Lines compare reversal reaches 23 bytes, and
// bottom/right argument locals are a codegen duplicate. The clean alias form
// is restored below.
// Remaining drift is localized register/load scheduling at the comparison, ctor
// arguments, SetSpanRegions/AddSpan argument setup, and final CurSpanList reload.
// Main-agent audit confirmed canonical draw-area/span-list ownership and retained
// the natural clip-region rebuild.
// Fresh session: the clean EH/GX source remains the best reconstruction at 21
// bytes: size 279, frame/saved-register shape and all seven direct calls match.
// Reusing the alias for ResetAll worsened to 107 bytes; localized constructor
// temporaries reproduced the prior 215-byte basin. A nested Num_Lines local,
// stdlib.h context, donor int ABI fields/parameters, and split declaration/init
// were emitted duplicates. An equal-height empty-arm guard reached 22 bytes.
// A nine-case focused variant lab was invalid without /GX (all variants were
// 224-byte functions), so it supplied no viable source lead.
// Paused after the fresh 10-hypothesis budget: strict drift is still localized
// to compare register bytes at +00444C70/+00444C73, ctor argument coloring near
// +00444CBC, and SetSpanRegions argument/receiver setup near +00444CE8.
// Wave20 ABI audit: the oracle's spanlist calls are int ABI (HH/HHHH/HHH),
// while SetClipRect itself remains the long-argument JJ/4 surface; correcting
// the local declarations fixes the decorated relocation identities but leaves
// the 21-byte scheduling drift unchanged.
// Wave20 probes: direct SetSpanRegions under the corrected ABI regressed to 28;
// carrying span_list through ResetAll regressed to 111; the ground-truth inline
// VSList composition and int Width/Height surface both emit the same 21-byte
// source basin. A focused int-ABI argument-shape lab found no closer natural
// candidate. Retained source is the canonical /GX composition and alias form.
// Close-session probes: reversing the manager-lines/Height compare worsened to
// 23 bytes; scalar ClipLeft/Top/Right/Bottom ownership was a 21-byte duplicate.
// The exact pointer-overload declaration was also a duplicate. Direct
// SetSpanRegions use regressed to 28 bytes, and combining it with an AddSpan
// alias entered a 218-byte structural basin. Splitting old/new manager aliases
// and direct member reads were 21-byte duplicates. Typed int constructor locals
// regressed to 215 bytes. The clean alias/tagRECT source is restored.
// Fresh claim probes: a custom-flag source-shape lab covered Width/Height type,
// constructor spelling, SetSpanRegions receiver, and manager field variants.
// All 24 invariant-valid variants stayed in the 21-byte alias basin or the
// known 28-byte direct-call basin. A second 96-variant lab found no change from
// register hints, int/long Num_Lines, or inherited versus inline VSList.
// A 256-sample ambient declaration sweep produced one unchanged 21-byte group.
// Real Windows RECT plus windows.h, string.h, and stdlib.h context also stayed
// in the same groups. Fresh receiver aliases, full Drawarea method declarations,
// and a direct-call reassignment found no closer natural source. The compare
// operand reversal remains 23 bytes. The clean 21-byte source is restored.
// Fresh claim probes: a local Height inside the non-null manager guard matched
// the original compare load colors, but total drift stayed 21 bytes. Local
// Width/Height constructor forms, long field types, fresh RECT/manager aliases,
// and equal-width ABI parameter reordering were duplicate or worse. Direct
// SetSpanRegions remained 28 bytes. The clean typed-RECT source is restored.
// ACCEPTED DRIFT: The 21 changed bytes only reverse the equality operands and
// schedule constructor and SetSpanRegions argument loads through other
// registers. Both builds push identical arguments in the same order and call
// the same seven functions. Member loads are from the same valid draw-area
// object, with no call or store between reordered loads. Used flags, memory
// effects, EH state, cleanup, and fault behavior match.

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;       // +0x00
    int* Zone_Size_Ptrs;          // +0x04
    int Used_Zones;               // +0x08
    int Max_Zones;                // +0x0C
    VSpan_Node* Free_Head;        // +0x10
    int Free_Pool_Zone;           // +0x14
    int Free_Pool_Index;          // +0x18
    int Total_Blocks;             // +0x1C
    int Free_Blocks;              // +0x20
    int Default_Grow_Size;        // +0x24
    int Element_Size;             // +0x28
    int Alloc_Count;              // +0x2C
    int Dealloc_Count;            // +0x30
    int NewZone_Count;            // +0x34
    int Reset_Count;              // +0x38

    ~TSpan_Node_List();
};

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;        // +0x00
    VSpan_Node** Line_Head_Ptrs;  // +0x3C
    VSpan_Node** Line_Tail_Ptrs;  // +0x40
    long* LeftMostPx;             // +0x44
    long* RightMostPx;            // +0x48
    long* Span_Count;             // +0x4C
    int Num_Lines;                // +0x50
    int Num_Pixels;               // +0x54
    int Min_Span_Px;              // +0x58
    int Max_Span_Px;              // +0x5C
    int Min_Line;                 // +0x60
    int Max_Line;                 // +0x64

    TSpan_List_Manager(int NumPixels, int NumLines);
    ~TSpan_List_Manager();
    void ResetAll();
    void SetSpanRegions(int left, int top, int right, int bottom);
    void AddSpan(int left, int right, int y);
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
    int Width;                    // +0x18
    int Height;                   // +0x1C
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
