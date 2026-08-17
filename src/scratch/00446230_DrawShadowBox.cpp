// VA: 00446230 TDrawArea::DrawShadowBox (271 B)
// PDB source: Drawarea.cpp, lines 4356-4409
//
// Baseline reconstruction: clip the requested rectangle to the draw area's
// clip rectangle and surface, then apply the configured shadow color table to
// each pixel in the resulting rectangle.
//
// Attempt log:
// - Replaced the prior FillRect/DrawBevel scaffold with the binary-supported
//   TDrawArea/RGE_Color_Table ownership and the AlignedWidth row scan.
// - Parameter-left clipping comparisons plus a negative invalid-rectangle
//   guard recovered the original prologue, CFG, call set, and most bytes.
// - Pointer/table declaration, address-term, and running-cursor variants were
//   duplicate or worse; best retained output is 273 bytes, 47 differing
//   positional bytes, with the residual confined to row-pointer scheduling.
// - Main-agent audit replaced the raw color-table vptr field with its canonical
//   virtual destructor surface; the validated gap is 48 bytes with unchanged
//   size, calls, frame, and instruction shape.
// - This session tested offset/left/Bits address-term order, table-first
//   assignment, scoped and top-reset pixel cursors, and a Color_Table* local;
//   cursor variants changed size/prologue or worsened the diff. The clean
//   source below remains the best natural reconstruction.
// - This session retested the row address expression, inner cursor scope and
//   declaration order, plus point-of-use Bits/row-address locals. The natural
//   canonical source remains the best living reconstruction; residual drift is
//   the row-base/pixel cursor register schedule and a two-byte tail shift.
// - This session moved the outer pixel declaration beside the row pointers;
//   it improved the unchanged-size result to 273 bytes/47 differing bytes.
//   A per-row for-initializer worsened it to 271 bytes/74 bytes. Sequential
//   start-offset and declaration-order rewrites were codegen duplicates.
// Main-agent audit confirmed canonical draw-area/color-table ownership and kept
// the natural typed row/pixel traversal.
// - Fresh pass: the exact-donor full TDrawArea/scalar-clip declaration surface
//   was codegen-identical to this local gap/ClipRect surface (47 bytes). Adding
//   the Drawarea stdlib/string header context worsened the result to 78 bytes;
//   it was removed.
// - Fresh row-pointer probes (table between pointer assignments and an explicit
//   x1-first offset assignment) were duplicate or worse. The remaining binary
//   lead is the original's row-base/pixel register rotation at +00C1, followed
//   by its two-byte tail layout difference; no further natural source axis was
//   supported by this pass.
// - Bounded fresh pass: mutating row_offset by x1 was a codegen duplicate;
//   72/96-case row-setup, declaration-order, and loop-shape labs produced only
//   the existing 273-byte or shorter 271-byte basins. Canonical object-table
//   locals, predecrement row tails, and the decompiler two-pointer topology
//   widened the mismatch (76/228/233 bytes); all were rolled back.
// - Final clean source remains the natural typed byte-table traversal at
//   273 bytes/47 differing bytes. The unresolved binary lead is specifically
//   VC5 pointer register coloring (original row base ECX, pixel EDX) plus the
//   two-byte tail shift; no behavior, call, layout, or ABI uncertainty remains.
// - Fresh worker pass tested a loop-local pixel cursor; it moved to a 271-byte
//   but 74-difference basin and was restored. The neighboring exact Flic draw
//   expression Bits + x1 + row_offset was also codegen-identical to the clean
//   source. The natural 273-byte/47-difference source remains authoritative.
// - Fresh structural probes tried direct typed row-start construction in each
//   orientation arm. This fixed the original row-start/pixel register roles
//   and reduced the resync cost, but remained a 271-byte/56-difference basin.
//   Loop-top pixel initialization, table-object ownership, and pointer-term
//   rewrites were worse or duplicate. The pinned natural source is restored.
// - Fresh claim validation confirmed the pinned 273-byte/47-difference basin.
//   A loop-top pixel reset remained 271 bytes/74 differences. A focused
//   counted-loop lab reached 271 bytes/45 differences, but added an initial
//   zero-count branch and changed the source-supported do-loop topology; it
//   was not retained. The natural pinned source remains authoritative.
// - Deep UI-type pass: inventory evidence confirms Bits is unsigned char* at
//   +0x08, shadow_color_table is RGE_Color_Table* at +0xC8, and table is an
//   unsigned char[256] at +0x28. No layout or helper-type uncertainty remains.
// - This pass tested 20 distinct loop, pointer-owner, declaration-scope,
//   update-order, scalar-width, and table-owner hypotheses, plus two combined
//   contexts. The scoped inner cursor forms moved to the 271-byte/74-difference
//   basin. Table-owner and row-scope variants were duplicate or worse.
// - Recomputing row_end, reversing row updates, and changing countdown tests
//   widened the result or changed control flow. The target keeps row base in
//   ECX, row end in ESI, and the inner pixel cursor in EDX. The prior cursor
//   source kept that schedule and was the best metric source before cleanup.
// - Translation-unit audit: scalar clip fields, the full TDrawArea field
//   surface, uchar pixel types, an unused DDSys global, memset pragma/prototype,
//   RGE_Color_Table class spelling, and nearby declarations were duplicate.
//   stdio, stdlib, string, windows, and game_types headers moved to 77-82
//   differences. Full palette methods moved to 82 differences. Imported API
//   declarations moved the tail to 48 differences. No tested context restored
//   the original row-base ECX and pixel EDX schedule. The baseline is restored.
// - Object audit confirms the VC5 target, 271-byte FPO body, no locals or SEH,
//   four long parameters, layouts, and AlignedWidth call. No inline record or
//   metadata supports another source owner for the row/pixel register swap.
// - Source-gate cleanup: the PDB-backed TDrawArea fields now own every member
//   from +0x38 through +0xC8, and RGE_Color_Table is a class with its named
//   vptr-backed fields. The byte cursors are replaced by a typed indexed row
//   loop. This is the clean semantic source even if its metric regresses.
// - Follow-up pass: direct Bits[row_offset + x] indexing removed the row
//   pointer and improved the typed source to a same-size 278-byte basin.
//   Direct table ownership reached same-size 271 bytes but lost the proven
//   saved-register prologue, so the typed table local remains the better
//   source shape.
// - A counted outer row loop matches the executable's row-count decrement and
//   reaches 271 bytes with 199 differing bytes. It keeps the table local and
//   direct Bits indexing. No row_start, row_end, pixel cursor, raw view, or
//   steering form is retained.
// - Fresh direct-index frontier: PDB symbols contain only this and four long
//   parameter records. No local record proves a row or pixel cursor. The exact
//   FillRect and Shape pixel-fill siblings support typed indexed loops, but
//   their cursor locals were not restored here.
// - Splitting the AlignedWidth result from its orientation multiply improved
//   the unchanged 271-byte result from 199 to 182 differing bytes. A named
//   aligned-width intermediate emitted the same bytes and was removed.
// - Direct Bits term reordering, explicit indexed row arithmetic, row-count
//   int width, table declaration order, and a while form were codegen
//   duplicates. A direct typed table owner lost the required saved-register
//   prologue and was removed.
// - Redundant late y guards and do-loop forms improved shape but moved strict
//   bytes or added guards. Mutating parameter homes for the row count widened
//   the function. The retained source is the smallest natural typed-index
//   form, with one AlignedWidth call, typed table ownership, and preserved
//   table-before-Bits fault order.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table() {}
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};

class TDrawSystem;
class BITMAPINFO256;
class IDirectDrawSurface;
class DrawAreaNode;
class TSpan_List_Manager;

struct _DDSURFACEDESC {
    unsigned char bytes[0x6C];
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    BITMAPINFO256* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    _DDSURFACEDESC SurfaceDesc;
    DrawAreaNode* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    RGE_Color_Table* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char _pad_end[3];

    long AlignedWidth();
    void DrawShadowBox(long x1, long y1, long x2, long y2);
};

void TDrawArea::DrawShadowBox(long x1, long y1, long x2, long y2)
{
    if (this->shadow_color_table != 0 && this->Bits != 0) {
        if (x1 < this->ClipRect.left) {
            x1 = this->ClipRect.left;
        }
        if (y1 < this->ClipRect.top) {
            y1 = this->ClipRect.top;
        }
        if (x2 > this->ClipRect.right) {
            x2 = this->ClipRect.right;
        }
        if (y2 > this->ClipRect.bottom) {
            y2 = this->ClipRect.bottom;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->Width) {
            x2 = this->Width - 1;
        }
        if (y2 >= this->Height) {
            y2 = this->Height - 1;
        }

        if (x2 < x1 || y2 < y1) {
            return;
        }

        {
            long orientation = this->Orien;
            long row_pitch = this->AlignedWidth();
            row_pitch *= orientation;
            unsigned char* table;
            long row_offset;

            if (orientation < 1) {
                row_offset = (y1 - this->Height + 1) * row_pitch;
            }
            else {
                row_offset = row_pitch * y1;
            }

            table = this->shadow_color_table->table;

            for (long rows = y2 - y1 + 1; rows > 0; rows--) {
                for (long x = x1; x <= x2; x++) {
                    this->Bits[row_offset + x] =
                        table[this->Bits[row_offset + x]];
                }
                row_offset += row_pitch;
            }
        }
    }
}
