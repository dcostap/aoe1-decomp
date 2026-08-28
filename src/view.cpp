// Natural source reconstruction for view.cpp.
// This file deliberately consumes owner headers. It does not use a TU context.
#include <windows.h>
#include <ddraw.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/asp_list.h"
#include "../include/basegame.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/Mouseptr.h"
#include "../include/obj_list.h"
#include "../include/panel.h"
#include "../include/pathsys.h"
#include "../include/player.h"
#include "../include/pnl_msg.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/sprite.h"
#include "../include/visible.h"
#include "../include/view.h"
#include "../include/world.h"

// These records have no public owner outside view.cpp.  RGE_View exposes only
// pointers to them, so view.h keeps forward declarations.
class Tile_FogEdge_Table {
public:
    VSpanMiniList* normal_draw;
    VSpanMiniList* fog_draw;
};

class Tile_BlackEdge_Table {
public:
    VSpanMiniList* black_UNdraw;
};

class Blit_Queue_Entry {
public:
    tagRECT src;
    tagRECT dest;
};

class DisplaySelectedObjRec {
public:
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

class Ov_Sprite_Draw_Rec {
public:
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    TShape* theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    unsigned long LastDrawTime;
    unsigned long DrawTimeInterval;
    unsigned char* colortable;
};

class RGE_SPick_Info {
public:
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
    RGE_SPick_Info* next;
    RGE_SPick_Info* prev;
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

// 00533510 RGE_View::RGE_View
// Attempt log:
// initial constructor source from packet/decompiler; using /GX because original has EH registration.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);


RGE_View::RGE_View()
{
    this->cur_render_area = 0;
    this->calc_draw_count = 0;
    this->world = 0;
    this->player = 0;
    this->map = 0;
    this->tile_wid = 0;
    this->tile_hgt = 0;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    this->max_col_num = 0;
    this->max_row_num = 0;
    this->center_scr_col = 0;
    this->center_scr_row = 0;
    this->center_scr_col_offset = 0;
    this->center_scr_row_offset = 0;
    this->center_map_col = 0;
    this->center_map_row = 0;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->map_scr_x_offset = 0;
    this->map_scr_y_offset = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;
    this->render_terrain_mode = 0;
    this->save_area1 = 0;
    this->save_paint_terrain = -1;
    this->white_pen = 0;
    this->red_pen = 0;
    this->hollow_brush = 0;
    this->border_line_shape = 0;
    this->scroll_action = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->movable_object = 0;
    this->set_selection_area(-1,-1,-1,-1);
    this->Terrain_Clip_Mask = 0;
    this->Terrain_Fog_Clip_Mask = 0;
    this->Master_Clip_Mask = 0;
    this->LastRenderBits = 0;
    this->RenderOffsets = 0;
    this->LastRenderSize = 0;
    this->Tile_Edge_Tables = 0;
    this->Black_Edge_Tables = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->Float_Scroll_Offsets = 0;
    this->Float_Scroll_Offsets_Sz = 0;
    this->Queued_Blits = 0;
    this->Blit_Queue = 0;
    this->Blit_Queue_Size = 0;
    this->Current_Blit = 0;
    this->Blit_Offset_X = 0;
    this->Blit_Offset_Y = 0;
    this->prior_objs = 0;
    this->futur_objs = 0;
    for (int i = 0; i < 5; i++) {
        this->pick_lists[i] = 0;
        this->pick_list_size[i] = 0;
    }
    this->UC_ObjectTouched = 0;
    this->UC_TouchedObj = 0x80000000;
    this->UC_StartTime = 0;
    this->UC_ElapsedTime = 0;
    this->message_panel = 0;
    this->extra_sprites = 0;
    this->DispSel_List_Size = 0;
    this->DispSel_List_Max = 8;
    this->DispSel_List = (DisplaySelectedObjRec*)calloc(8, 0x14);
}

// 00533760 RGE_View::~RGE_View (view.cpp:408-477)
// Attempt log:
// 1: Natural destructor with /GX: EH prologue matches, but pointer fields reloaded through ECX instead of original EDI locals; 64.10% diff.
// 2: Local pointer variables improved to 6.20%; remaining tail lacks explicit first TPanel dtor before compiler-emitted base dtor.
// 3: Explicitly call TPanel::~TPanel before leaving destructor body.

extern "C" void __cdecl free(void*);
extern "C" void __cdecl operator_delete(void*);


RGE_View::~RGE_View()
{
    TShape* shape = this->border_line_shape;
    if (shape != 0) {
        shape->~TShape();
        operator_delete(shape);
        this->border_line_shape = 0;
    }

    this->delete_surfaces();

    if (this->red_pen != 0) {
        DeleteObject(this->red_pen);
        this->red_pen = 0;
    }

    if (this->RenderOffsets != 0) {
        free(this->RenderOffsets);
    }

    TSpan_List_Manager* span = this->Terrain_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }
    span = this->Terrain_Fog_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }
    span = this->Master_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }

    if (this->Tile_Edge_Tables != 0) free(this->Tile_Edge_Tables);
    if (this->Black_Edge_Tables != 0) free(this->Black_Edge_Tables);
    if (this->Float_Scroll_Offsets != 0) free(this->Float_Scroll_Offsets);
    if (this->Blit_Queue != 0) free(this->Blit_Queue);

    DClipInfo_List* clip = this->prior_objs;
    if (clip != 0) {
        clip->~DClipInfo_List();
        operator_delete(clip);
    }
    clip = this->futur_objs;
    if (clip != 0) {
        clip->~DClipInfo_List();
        operator_delete(clip);
    }

    void** p = (void**)this->pick_lists;
    int i = 5;
    do {
        if (*p != 0) free(*p);
        p++;
        i--;
    } while (i != 0);

    if (MouseSystem != 0) {
        ((TMousePointer*)MouseSystem)->set_game_mode(0);
        ((TMousePointer*)MouseSystem)->set_game_enable(0);
    }

    if (this->DispSel_List != 0) free(this->DispSel_List);

    this->reset_overlay_sprites();
    this->TPanel::~TPanel();
}

// VA: 00533940 RGE_View::setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char, int, char*)
// PDB source: view.cpp lines 488-526
// attempt 1: natural setup body with local sprintf buffer, new TShape, and pick-list calloc loop.
// attempt 2: add TPanel vptr context/sizeof(TShape)=0x20 and use one running pick-size pointer like original.
// attempt 3: use the start of the 260-byte local buffer; VC5 places it at the original stack window.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);


long RGE_View::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, unsigned char flag, int calc_count, char* shape_name)
{
    char str[260];

    TPanel::setup(draw, parent, x, y, w, h, flag);

    this->cur_render_area = 0;
    this->calc_draw_count = calc_count;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;

    this->white_pen = GetStockObject(6);
    this->red_pen = CreatePen(0, 1, 0xff);
    this->hollow_brush = GetStockObject(5);

    sprintf(str, "%s.shp", shape_name);
    this->border_line_shape = new TShape(str, -1);

    this->Init_Tile_Edge_Tables();

    int* pick_size = &this->pick_list_size[0];
    int i = 5;
    do {
        *(void**)(pick_size - 5) = calloc(0x40, 0x14);
        *pick_size = 0;
        pick_size++;
        i--;
    } while (i != 0);

    return 1;
}


void RGE_View::set_focus(int focus) {
    this->TPanel::set_focus(focus);
    if (MouseSystem != 0) {
        MouseSystem->set_game_enable(this->have_focus);
    }
}

// VA: 00533AF0 RGE_View::Init_Tile_Edge_Tables()
// Attempt log:
// 1: initial raw-offset reconstruction from the packet; call set and frame match.
// 2: typed table ownership and the two file-load/relocation passes are now the
//    living reconstruction. The downloaded pointer values are file-relative,
//    so the small integer relocation loop is required by the data format.
// 3: direct typed fields and indexed table roots introduced division and a
//    large prologue/layout drift; rolled back.
// 4: typed record members with fixed byte-offset roots preserved the 806-byte
//    basin (453 positional bytes, 133 edit bytes, 92.73% shape).
// 5: a scoped black-table alias reached the original 799-byte size but changed
//    liveness and raised positional drift to 481 bytes; rolled back.
// 6: reading through that alias worsened the second file block to 529 bytes;
//    rolled back.
// 7: a named black root-entry pointer changed the block shape but gave 455
//    positional bytes; rolled back as weaker than the typed baseline.
// 8: direct named RGE_View fields remained a 780-byte, 615-byte-diff basin;
//    restored the typed fixed-offset lvalues. No fake volatility or asm is used.
// 9: replaced the black serialized-root byte-offset loop with a typed
//    Tile_BlackEdge_Table** walk; the diff fell to 341 bytes and size to 800,
//    but the first structural hunk remains at the second relocation loop.
// 10: typed-base, do-while, separate-index, and array-index byte-offset
//     variants restored the original relocation block but stayed at 806 bytes
//     and 453-455 bytes; rolled back. The typed 0x11-root walk remains best.
// 11: Restored named file literals and RGE_View fields. The macro lvalues and
//     raw addresses were diagnostic forms, not living source ownership.
// 12: changed the edge predicate and bit locals to bool from the decompiler's
//     bool labels; VC5 expanded the frame to 0x24 and 930 bytes, so restored int
//     locals. The binary's dword homes are not source-level bool evidence here.
// 13-19: typed root indexing, scalar aliases, declaration order, address-add
//     spelling, width, comparison, and nested-guard variants did not improve
//     the typed root basin.
// 20: scoping the eight bit locals inside each edge pass recovered the original
//     dword homes and most late blocks. Best result is 800 bytes and 338 strict
//     changed bytes. The remaining structural hunk is the black-root relocation
//     loop, where the original uses a byte-offset lowering.
// 21-22: separate declaration statements and explicit do-while forms were
//     codegen duplicates. No policy-valid exact source was found in this pass.
// 23: a fresh finish pass tested raw base, raw field, pointer-alias, named
//     cursor, and int** root forms. None was exact. The typed 0x11-root walk
//     remains the smallest clean source at 338 changed bytes.
// 24: compiling the owner with the reviewed view.cpp header context did not
//     change its body. The PDB owner is protected; keep the IAEX access form.
// 25: exact-finish probes tested dword root loops, scoped lvalues, byte-buffer
//     fields, pointer widths, root-cursor scope, and receiver aliases. The
//     raw-root forms were 796-806 bytes with 450-455 changed bytes. A typed
//     alias basin reached 98.96% exact block coverage but changed the base
//     register and removed the proven black-field reload. Restore the pinned
//     800-byte typed-root source after each probe.
// BINARY NOTE: the target has integer arithmetic only. It has no x87 path.
// Accepted-drift review: the executable reloads Black_Edge_Tables and uses a
// byte offset for each of 17 roots. The rebuild carries a typed root pointer
// and count. No call occurs in this loop; both read, relocate, and write the
// same entries in order. The later drift only changes bit-test registers and
// equivalent base/index encodings. All 14 calls and table effects match.

extern "C" int __cdecl _open(const char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

static const char s_tile_file[] = "DATA2\\TILEEDGE.DAT";
static const char s_black_tile_file[] = "DATA2\\BLKEDGE.DAT";

void RGE_View::Init_Tile_Edge_Tables()
{
    int fd, len;
    int i, j;
    Tile_FogEdge_Table* fog_table;
    Tile_BlackEdge_Table* black_table;
    int base;
    int count;
    int ok;
    Tile_BlackEdge_Table** black_roots;

    fd = _open(s_tile_file, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); this->Tile_Edge_Tables = (Tile_FogEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,this->Tile_Edge_Tables,len); _close(fd);
        base = (int)this->Tile_Edge_Tables;
        for (i=0;i<0x44;i+=4)
            *(int*)((char*)this->Tile_Edge_Tables+i) += base;
        for (i=0;i<0x44;i+=4) {
            fog_table = *(Tile_FogEdge_Table**)((char*)this->Tile_Edge_Tables+i);
            for (j=0;j<0x2f;j++) {
                if (fog_table[j].normal_draw)
                    fog_table[j].normal_draw = (VSpanMiniList*)((char*)fog_table[j].normal_draw + base);
                if (fog_table[j].fog_draw)
                    fog_table[j].fog_draw = (VSpanMiniList*)((char*)fog_table[j].fog_draw + base);
            }
        }
    }
    fd = _open(s_black_tile_file, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); this->Black_Edge_Tables = (Tile_BlackEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,this->Black_Edge_Tables,len); _close(fd);
        base = (int)this->Black_Edge_Tables;
        black_roots = this->Black_Edge_Tables;
        for (i=0;i<0x11;i++,black_roots++)
            *black_roots = (Tile_BlackEdge_Table*)((char*)*black_roots + base);
        for (i=0;i<0x44;i+=4) {
            black_table = *(Tile_BlackEdge_Table**)((char*)this->Black_Edge_Tables+i);
            for (j=0;j<0x2f;j++) {
                if (black_table[j].black_UNdraw)
                    black_table[j].black_UNdraw = (VSpanMiniList*)((char*)black_table[j].black_UNdraw + base);
            }
        }
    }
    uchar* edge = this->EdgeNumber;
    for (i=0;i<0x100;i++) edge[i] = 0xff;
    count = 0;
    i = 0;
    do {
        int b0,b1,b2,b3,b4,b5,b6,b7;
        ok = 1;
        b0 = (i & 1) == 1;
        b1 = (i & 2) == 2;
        b2 = (i & 4) == 4;
        b3 = (i & 8) == 8;
        b4 = (i & 0x10) == 0x10;
        b5 = (i & 0x20) == 0x20;
        b6 = (i & 0x40) == 0x40;
        b7 = (i & 0x80) == 0x80;
        if (b7 && (b0 || b3)) ok = 0;
        if (b6 && (b2 || b3)) ok = 0;
        if (b5 && (b1 || b2)) ok = 0;
        if (b4 && (b0 || b1)) ok = 0;
        if (ok) edge[i] = (uchar)count++;
        i++;
    } while (i < 0x100);
    i = 0;
    do {
        if (edge[i] == 0xff) {
            int b0,b1,b2,b3,b4,b5,b6,b7;
            b0 = i & 1; b1 = i & 2; b2 = i & 4; b3 = i & 8; b4 = i & 0x10; b5 = i & 0x20; b6 = i & 0x40; b7 = i & 0x80;
            if (b7) { b3 = 0; b0 = 0; }
            if (b6) { b3 = 0; b2 = 0; }
            if (b5) { b2 = 0; b1 = 0; }
            if (b4) { b1 = 0; b0 = 0; }
            edge[i] = edge[b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0];
        }
        i++;
    } while (i < 0x100);
}

// VA: 00533E10 RGE_View::update_display_selected_objects
// view.cpp:711-759
// ACCEPTED_DRIFT 2026-05-20 Boss: exact size; reviewed nonzero diff as behavior-equivalent register allocation/encoding drift in the selected-object update loop. Control flow, calls, stack, memory targets, loop bounds, list-size updates, object lookup, and selected-bit effects are preserved; remaining differences are object/elapsed register coloring and equivalent byte RMW vs direct and/or encodings with shifted branch displacements.
//
// Attempt log (~10 probes):
// v0: struct-based entry, if-else-if-else — far off (prolog, pointer math, shared tail)
// v1: char* base+offset, do-while — better prolog, but add ecx,10h optimization
// v2: goto approach — first 32 bytes matching, rest alloc-basin drift
// v3: raw ptr arithmetic — prolog + test jle now matching
// v4: if (max>0) + inner offset decl — prolog perfect (push ebp; push esi; ...xor ebp, ebp; test ecx; jle)
// v5: goto with function-scope vars — prolog push ebx/ebp/esi
// v6: Ghidra-style else-if(bit8) pattern + shared tail — 80% matching
// v7: else-if(!(elapsed & 0x100)) with goto for set-flag-jump — 130/162 matching
// Fresh pass 2026-05-19:
// v8: hoisted obj initializer and elapsed declaration; no codegen change.
// v9: explicit objects-array local; no codegen change.
// v10: compound |= / &= selected updates; no codegen change.
// v11: selected byte pointer locals; no codegen change.
// v12: compute elapsed before object lookup; worsened badly to 149/162 positional and prologue drift; rolled back.
//
// Remaining diff (32 bytes, ~20%): register allocation swap
//   - obj in edi instead of edx (mov edi,[edi+edx*4] vs mov edx,[edi+edx*4])
//   - elapsed in edx instead of edi (mov edx,eax vs mov edi,eax)
//   - test dh,1 instead of test edi,100h (same test, different reg)
//   - RMW for selected instead of direct and/or [mem] — consequence of reg alloc
//   - All jump offsets differ slightly due to encoding
//
// This is benign VC5 register scheduling drift. Behavior and structure match.
// Parked in scratch.
// Retry 2026-05-20 Boss pass: revalidated baseline (162B, 33.3333% positional,
// 20.3704% edit, first mismatch +33). Tried 15 more probes: raw selected byte
// lvalues, explicit object-index/objects-array locals, computing elapsed before
// object lookup, char* entry/void* object raw addressing, reversed timeout compare,
// positive `elapsed & 0x100` test shape, /O2 without /Oy, /Ox, /Oa, /Og, /O1,
// volatile selected field, register elapsed, register obj, and split entry declaration.
// None changed the core allocation basin; volatile selected slightly improved metrics
// (32.7160% positional / 19.7531% edit) but only by changing byte-store lowering and
// was not kept. Baseline remains the cleanest behavior-equivalent source.
// ACCEPTED_DRIFT proposal: same control flow, calls, stack, memory targets, loop bounds,
// list-size updates, object lookups, and selected-bit effects. Remaining bytes are
// register allocation/encoding drift (object in EDI vs original EDX, elapsed in EDX vs
// original EDI, `test dh,1` vs `test edi,100h`, and read/modify/write selected byte vs
// direct `and/or [obj+36],cl`), with branch displacements shifted by those encodings.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);


void RGE_View::update_display_selected_objects(void) {
    unsigned long curTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x2CB);
    int i = 0;

    if (this->DispSel_List_Max <= 0)
        return;

    {
        int offset = 0;

        do {
            int* entry = (int*)((unsigned char*)this->DispSel_List + offset);
            if (entry[0]) {
                RGE_Static_Object* obj;
                obj = this->world->objectsValue[entry[1]];
                if (obj == 0) {
                    entry[0] = 0;
                    this->DispSel_List_Size = this->DispSel_List_Size - 1;
                } else {
                    unsigned long elapsed = curTime - (unsigned long)entry[2];
                    if (elapsed > (unsigned long)entry[3]) {
                        entry[0] = 0;
                        this->DispSel_List_Size = this->DispSel_List_Size - 1;
                    } else if (!(elapsed & 0x100)) {
                        obj->selected = obj->selected | ((unsigned char)entry[4]);
                        goto next_entry;
                    }
                    obj->selected = obj->selected & ~((unsigned char)entry[4]);
                }
            }
next_entry:
            ++i;
            offset += 0x14;
        } while (i < this->DispSel_List_Max);
    }
}

// 00533EC0 RGE_View::display_object_selection
// Source: view.cpp lines 765-804
// Attempt log:
// initial: 87% diff — missing vtable pointer, wrong field offsets.
// added virtuals to RGE_View: offsets correct, remaining diff 48%.
// split i to function scope, do-while loop: diff dropped to 15 edit bytes.
// tried swapping slot/key order; removing key local; function-scope slot init.
// Round2: tried stack-load forcing variants for param_4 (slot before key, declaration init,
// volatile key/slot/both, pointer alias, char* arithmetic, extra temp). All stayed in the
// same 163-byte shifted form: VC5 uses mov edi,ebp instead of original stack reload.
// ACCEPTED_DRIFT_CANDIDATE: exact size; remaining diff is localized register reuse of
// param_4 for slot initialization, shifting subsequent code by 2 bytes. Behavior/memory/calls match.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);


void RGE_View::display_object_selection(int param_1, int param_2, int param_3, int param_4)
{
    int found = 0;
    int i = 0;
    int* slot;

    if (this->DispSel_List_Max > 0) {
        int key = param_4;
        slot = (int*)param_4;
        int offset = 0;

        do {
            int* entry = (int*)((char*)this->DispSel_List + offset);
            if (*entry == 0) {
                found = 1;
                slot = entry;
            } else if (key != 0 && entry[4] == key) {
                entry[2] -= entry[3];
            }
            i++;
            offset += 0x14;
        } while (i < this->DispSel_List_Max);
    } else {
        slot = (int*)param_4;
    }

    if (found) {
        *slot = 1;
        slot[1] = param_1;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x31d);
        slot[2] = now;
        slot[3] = param_2;
        slot[4] = param_3;
        this->DispSel_List_Size++;
    }
}

// VA: 00533F70
// PDB: view.cpp lines 811-841
// RGE_View::set_rect(long a, long b, long c, long d)
// FLAGS: config/flags/00533F70_set_rect.rsp (/GX)


extern "C" void __cdecl operator_delete(void* ptr);
extern "C" void* __cdecl operator_new(unsigned int size);


void RGE_View::set_rect(long a, long b, long c, long d)
{
    this->TPanel::set_rect(a, b, c, d);
    this->calc_draw_vars();
    this->create_surfaces();

    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;

    delete this->Terrain_Clip_Mask;
    delete this->Terrain_Fog_Clip_Mask;
    delete this->Master_Clip_Mask;

    this->Terrain_Clip_Mask = new TSpan_List_Manager(c, d);
    this->Terrain_Fog_Clip_Mask = new TSpan_List_Manager(c, d);
    this->Master_Clip_Mask = new TSpan_List_Manager(c, d);

    if (MouseSystem != 0 && c > 0 && d > 0) {
        MouseSystem->set_game_window(a, b, a + c, b + d);
        MouseSystem->set_game_mode(1);
    }

    this->target08(2);
}


void RGE_View::delete_surfaces(void) {
    TDrawArea* area;

    area = save_area1;
    if (area != 0) {
        area->TDrawArea::~TDrawArea();
        operator_delete(area);
        save_area1 = 0;
    }
}

// VA: 00534130 RGE_View::create_surfaces
// Attempt log:
// initial natural implementation from packet with real constructors/destructors; relies on /GX EH lowering.


int RGE_View::create_surfaces()
{
    if (this->pnl_wid == 0 && this->pnl_hgt == 0) {
        return 1;
    }

    if (this->save_area1 == 0) {
        TDrawArea* area = new TDrawArea((char*)0x0058CD78, 0);
        this->save_area1 = area;
        if (area != 0) {
            area->Init(this->render_area->DrawSystem, this->pnl_wid,
                       this->pnl_hgt, 1, 0);
        }
    }

    if (this->save_area1 != 0 && this->pnl_hgt > 0) {
        this->save_area1->SetSize(this->pnl_wid, this->pnl_hgt, 1);
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);

        DClipInfo_List* p = this->prior_objs;
        if (p != 0) {
            delete p;
        }
        p = this->futur_objs;
        if (p != 0) {
            delete p;
        }

        int v = this->pnl_hgt + 0x1c2;
        this->prior_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->pnl_hgt + 0xf9, 0x28);
        this->futur_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->pnl_hgt + 0xf9, 0x28);

        this->prior_objs->SetDrawRegion(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);
        this->futur_objs->SetDrawRegion(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);
    }

    return this->save_area1 != 0;
}

// 00534340 RGE_View::calc_draw_vars
// PDB: view.cpp:916-942, 217 bytes
// __thiscall, void, ret
// FLAGS: default
//
// Attempt log:
// probe 1: class layout mismatch (160b vs 217b)
// probe 2-4: free fn / goto / all vars at top — 94-98% diff
// probe 5-6: nested blocks / __thiscall with class — 90%
// probe 7: inline checks, eager loads — 93%
// probe 8-9: vis before zero / literal 0 — 93%
// probe 10: declare pw/ph uninitialized, assign after checks — 90%
// probe 11: invert layout (success body first with &&, zero at end) — 36.9%
//   Key: layout now matches original (calc inline, zero after)
//   Remaining 80 bytes = register allocation drift only:
//   - visible in EDX vs EAX (8b 51 70 vs 8b 41 70)
//   - zero in EAX vs EBP (33 c0 vs 33 ed, no push ebp before xor)
//   - tile_wid divisor in EBP vs EDI (movsx ebp,dx vs movsx edi,ax)
//   - zero path pops ESI/EBP before stores vs after stores
//   All semantically equivalent, VC5 register allocation stable
// probe 12: if/else vs if+return — identical binary to probe 11
//
// left in scratch: remaining drift is VC5 register allocation —
// EAX/EBP/EDI register choices differ from original by 80 bytes (36.9%).
// Single-function scope cannot resolve. Needs TU context or register allocation control.
// probe 13: true TPanel base/polymorphic surface — emitted code unchanged.
// probe 14: short/int zero locals, register-qualified width locals, and natural
//   statement-order variants — unchanged or structurally worse.
// probe 15: exact tagRECT dword aggregate for render_rect — emitted code unchanged.
// final: retain the period-plausible inherited TPanel/tagRECT ownership; remaining
//   mismatch is isolated to VC5 register coloring and zero-path save/pop order.
// Session follow-up: named zero, direct-member width/height, and visible-local
// probes were rolled back; they were duplicate or farther.  Retain the clean
// named panel-width/height source and canonical RGE_View/TPanel/tagRECT surface.
// Main-agent audit confirmed canonical panel/view rectangle ownership and kept
// the natural visible/geometry branches.
// Matching-worker continuation: a nine-variant natural body lab (current,
// zero-local widths, inner/direct locals, declaration/order, math-order, and
// truthy guards) preserved the 217-byte size but produced only four codegen
// groups and no exact result.  The clean current source remains the best
// reconstruction; the remaining 80-byte gap is the stable EAX/EDX, EBP/EDI,
// and failure-tail register basin, likely requiring broader view.cpp TU context.
// fresh orch-view-01 pass: splitting the row-offset zero around max-column
//   changed size to 222 and 191-byte drift; restored clean.
// fresh pass: natural nested positive guards emitted the same 217/80-byte
//   codegen as clean; restored clean.
// fresh pass: reversed zero-comparison operands, leading short zero sentinel,
//   and chained offset assignment were duplicate or one byte farther; restored.
// fresh pass: explicit clear-draw-vars goto tail was 217/197 bytes; restored.
// fresh pass: one-sided panel-width/height local variants were 217/192 and
//   217/89 bytes; restored.
// fresh pass: 24-variant natural setup/math/local lab found 8 codegen groups,
//   10 size-eligible variants, and no exact match.
// fresh pass: broad period TPanel virtual surface changed output to 217/150;
//   retained minimal exact-donor-compatible surface and restored clean.
// Continuation sa-15c0371c-r1 (10-hypothesis budget):
// probe 62: removing the height local while keeping the clean statement order
//   worsened to 192 bytes; direct height rereads alone are not sufficient.
// probe 64: interleaving col-offset/max-col and row-offset/max-row changed the
//   zero register to EBX and grew to 222 bytes; restored.
// probe 66: combining that interleaving with direct typed pnl_hgt rereads gave
//   a natural 217-byte candidate at 61 differing bytes and 66.13% exact blocks.
//   It aligns the complete success tail from max-col onward; only zero/divisor
//   coloring and the clear-tail register lifetime remain.
// probes 67-75: explicit int/short zero locals, full RGE_View tail layout,
//   windows.h, declaration-order, and memory.h context were either worse or
//   codegen duplicates of the 61-byte candidate.
// final continuation source: retain the PDB-supported width local, direct
//   height rereads, and interleaved offset/max statements; do not retain
//   unused zero/header scaffolding. Remaining gap is stable EBP/EDI/EAX
//   allocation and clear-tail pop ordering.
// orch2 context probe: adding the exact set_rect donor's <new.h> context
//   emitted the same 217-byte code; restored because it did not change the
//   register basin.
// continuation sa61_calc_draw_vars: exact same-TU view.cpp donor
//   0053F6B0_handle_scroll_view confirms TPanel::pnl_wid/pnl_hgt are long;
//   normalized both local fields from int to long.  The rebuilt function
//   remains 217 bytes with the same 61-byte mismatch, CFG, memory effects,
//   and saved-register set.  Retain the canonical typed surface.
// Continuation sa1853792c_calc_draw_vars:
// probes 96-98: moving the proven width local into the success arm, changing
//   its type to long, and moving it to function scope were codegen duplicates.
// probe 99: truthy guards were a duplicate; probe 100: protected access and
//   the canonical RGE_View virtual surface were duplicates.
// probe 102: a natural height local after the row-offset store was a duplicate.
// probe 105: ungrouped center arithmetic was a duplicate; probe 106: long zero
//   literals were a duplicate; probe 107: natural implicit promotions were a
//   duplicate.  Restored the clean typed source after each diagnostic probe.
// final continuation: validated clean source remains 217 bytes with 61 strict
//   mismatches (66.13% exact blocks).  The first mismatch is the stable VC5
//   EBP/EDI zero-versus-divisor coloring and failure-tail pop order.
// Matching-worker fresh pass sa-6b1246ff: baseline reproduced 217 bytes,
//   61 strict mismatches, and 66.13% exact-block coverage.  Explicit int and
//   register-qualified zero locals were worse; a short zero local was a
//   codegen duplicate.  Complete same-TU TPanel and RGE_View data surfaces
//   were also duplicates.  Restored the clean natural source.  The remaining
//   gap is the known VC5 EBP/EDI allocator basin; broader view.cpp context is
//   still the useful next evidence.
// Matching-worker sa-90ba5ca0-r1 canonical-layout probes:
// probes 13-14: replaced the touched TPanel gaps with the inventory-proven
//   complete TPanel field surface, then replaced the RGE_View prefix gaps with
//   typed world/map and size fields.  Both rebuilt to the same 217-byte,
//   61-difference result.  Retain the stronger local layout declarations;
//   remaining drift stays in register coloring and the failure-tail lifetime.
// Fresh continuation sa-9bdbe17c-r1: direct typed pnl_wid reads, a mutable
// short zero local, and checked tile-width/height locals all reproduced the
// clean 217-byte/61-difference basin.  A long zero local worsened to 198
// differences.  A 256-sample ambient declaration context lab found five
// codegen groups but no exact result; it never changed the first zero-register
// mismatch.  Restored the pinned natural source.
// Matching-worker sa-69ff65e9-r1 deeper view-TU pass:
// The original PDB lists RGE_View::tile_wid/tile_hgt/tile_half_wid/
// tile_half_hgt as short fields at +0x108..+0x10E.  It lists TPanel::pnl_wid
// and pnl_hgt as long fields, and visible as int.  The target procedure has
// only the register symbol this.  The PDB has no named local for this body.
// Twenty new hypotheses tested those field types, tile local scopes, panel
// width/height lifetimes, zero lifetimes, inline accessors, return form, enum
// metadata, and complete RGE_View size.  The clean source stayed at 217 bytes,
// 61 differences, and 66.13% exact blocks.  The only farther variants were
// restored.  The remaining gap is the EBP zero versus EDI divisor color and
// the related clear-tail pop order.
// Source-gate audit: the living body uses named members and one carried width.
// It has no generic slots, raw addresses, cursor aliases, fake zero local, or
// no-effect scaffold.  The clear arm keeps the observed natural zero stores.
// Continuation sa-d08f1c06-r1 (PDB-supported zero-lifetime pass):
// probes 159-163 tested negative-guard, explicit invalid return, and nested
// positive guards.  VC5 canonicalized all three to the clean 217/61 basin.
// Probe 165 changed clear assignment order and was farther (same 61 bytes).
// Probe 167 carried both panel dimensions as locals; it grew to 222/191.
// Probes 169 and 185 joined width declaration/initialization (const and plain);
// both were clean-basin duplicates.  Probe 171 captured tile shorts and was
// farther at 71 bytes.  Probe 173 grouped the positive predicate and probe 177
// qualified the inherited visible field; both were duplicates.  Probe 175
// moved clear-offset stores first and was farther.  Probe 179 used a long
// height local and was 222/191.  Probe 181 used explicit success return and
// common clear block and was a duplicate.  No natural PDB-supported form moved
// the guard zero from EDI to the original EBP or changed the clear-tail pop.
// Restored the pinned clean source.  The remaining EBP zero and tail lifetime
// are not supported by a source-local natural control or declaration change.
// Matching-worker continuation sa-daa10f76-r1 (ten-hypothesis blocker pass):
// probe 1: a separately declared short zero with an assignment before the
// guard was a codegen duplicate at 217/61.  Probe 2: #line 916 restored the
// original line band but was also a 217/61 duplicate.  Probe 3: a
// register-qualified long panel-height local grew to 222/191.  Probe 4: a
// register-qualified short tile-width local was a 217/61 duplicate.  Probe
// 5: the four-byte visible field typed as long was a 217/61 duplicate.  Probe
// 6: explicit optimize("g", on) was a 217/61 duplicate.  Probe 7:
// optimize("y", off) produced a 217/127 body with a different frame, proving
// the pinned /Oy context is required.  Probe 8: optimize("t", on) was a
// 217/61 duplicate.  Probe 9: inline_depth(0) was a 217/61 duplicate.  Probe
// 10: a separately assigned int zero grew to 217/198 and lost all exact
// blocks.  Restored the pinned clean source after each probe and revalidated
// 217 bytes, 61 strict differences, and 66.13% exact-block coverage.
// The original still restores EDI before the eight clear-tail stores, while
// the clean rebuild keeps zero in EDI until after those stores.  This changes
// EDI at a faulting invalid-this store, so strict accepted drift is not proved.
// Recovered view.cpp TU pass: the shared 0x360 RGE_View surface, /GX module
// flags, and exact 00534100/00534130 prefixes keep the 217-byte, 61-difference
// basin. Earlier view.cpp owners are not yet on the shared surface.
// Continuation sa-5abaa990-r3: a right-to-left chained clear, a named validity
// result, and named width/quotient locals were duplicate or farther. None
// changed the EDI zero owner. Restored the 217-byte, 61-difference source.
// Matching-worker exact-finish sa-4f34b859-r1: the authentic view.cpp context
// gate was rechecked in the direct source module. Exact anchors 00534100,
// 00534130, 00535480, 00535EB0, 00535ED0, 00535F20, 00535F70, 00535FC0,
// 005381C0, 00538420, and 00538410 remain exact in that shared surface.
// The target stays 217 bytes with 62 instructions, no calls, no frame, four
// saved registers, and 61 strict differences. The first difference is the
// original EBP zero versus rebuilt EDI zero at +5. The original restores EDI
// before its eight clear-tail stores; the rebuild keeps the zero in EDI there.
// A register-qualified int zero and a register-qualified panel-width local
// both reproduced the clean 217/61 basin. Both were restored. No natural
// source-local change tested in this claim moved the EBP/EDI basin. Next
// evidence needs the omitted original view.cpp source or compiler context.
// Exact-finish blocker audit sa-1f3e151c: fresh validation in the current
// direct module context reproduced 217 bytes, 62 instructions, no calls,
// no frame, four saved registers, the matched calc_draw_vars owner, and 61
// strict differences. Three new natural liveness tests were duplicates:
// a short zero used only for guard and clear publication; success-arm short
// tile-width and tile-height locals; and their combination. Each was restored.
// BINARY NOTE: this body has no x87 work, calls, or Tile_Edge_Tables access.
// Its writable publication is limited to the proven short fields at +0x116
// through +0x124. The unresolved bytes are the original EBP zero versus the
// rebuild EDI zero and the original early EDI restore before clear stores.
// Do not add table access, x87 arithmetic, calls, or synthetic state to tune
// this register-allocation blocker.
// Continuation sa-7e3ccf7d-r1: fresh validation reproduced the pinned
// 217-byte body with 61 strict differences. DIA reports only the registered
// `this` symbol. It reports no source local or inline frame for this function.
// Exact same-TU donor 00539D90 has the original delayed-save prologue shape.
// Its mutable short local explains that donor's EBP zero, not this target.
// Fifteen new variant families tested output locals, divisor reuse, predicate
// locals, references, accessors, declaration order, chains, and register hints.
// They also tested the PDB-backed RGE_View and TPanel method surfaces.
// A 144-case VC5 flag classification produced three groups and no match.
// All size-valid natural forms kept the original blocker or moved farther.
// Adding exact predecessor 00533F70 changed later scheduling and size only.
// It kept the rebuilt EDI zero at the first guard. That owner is not in the
// current shared translation-unit map, so the experiment cannot support an
// exact claim. The pinned clean source remains the smallest supported form.
// Useful next evidence is the omitted original view.cpp source or a reviewed
// expansion of the translation-unit owner map. Do not add fake predecessor
// code, volatility, table reads, floating-point work, or raw register control.


void RGE_View::calc_draw_vars() {
    int pw;

    if (this->visible != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        pw = this->pnl_wid;

        this->center_scr_col_offset = 0;
        this->max_col_num = (short)(pw / (int)this->tile_wid);
        this->center_scr_row_offset = 0;
        this->max_row_num = (short)(this->pnl_hgt / (int)this->tile_hgt);
        this->center_scr_col = (this->render_rect.left - this->tile_half_wid) + (short)(pw / 2);
        this->center_scr_row = (this->render_rect.top - this->tile_half_hgt) + (short)(this->pnl_hgt / 2);
    } else {
        this->max_row_num = 0;
        this->max_col_num = 0;
        this->center_scr_col = 0;
        this->center_scr_row = 0;
        this->center_map_col = 0;
        this->center_map_row = 0;
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
    }
}


void RGE_View::set_redraw(TPanel::RedrawMode mode) {
    this->TPanel::set_redraw(mode);
    if (mode == 2) {
        render_terrain_mode = 0;
    }
}


void RGE_View::set_world(RGE_Game_World* world) {
    this->world = world;
    if (world != 0) {
        map = world->map;
        map->coordinate_map();
        tile_wid = map->tile_width;
        tile_hgt = map->tile_height;
        tile_half_wid = map->tile_half_height;
        tile_half_hgt = map->tile_half_width;
        elev_hgt = map->elev_height;
    } else {
        map = 0;
        tile_wid = 0;
        tile_hgt = 0;
        tile_half_wid = 0;
        tile_half_hgt = 0;
        elev_hgt = 0;
    }
    calc_draw_vars();
}


void RGE_View::set_player(RGE_Player* player) {
    this->player = player;
    last_view_x = (int)0xC61C3C00;
    last_view_y = (int)0xC61C3C00;
    redraw(2);
}

// 00534530 set_selection_area (157 bytes) — MATCHED
// PDB: view.cpp (RGE_View::set_selection_area)

void RGE_View::set_selection_area(long col1, long row1, long col2, long row2)
{
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, 0);
    }
    this->sel_col1 = col1;
    this->sel_row1 = row1;
    this->sel_col2 = col2;
    this->sel_row2 = row2;
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(col1, row1, col2, row2, 0x10);
    }
    this->redraw(1);
}

// 005345D0 get_selection_area (277 bytes)
// PDB: view.cpp (RGE_View::get_selection_area)
// Attempt log:
//   attempt 1: naive natural source with min/max normalize


int RGE_View::get_selection_area(long& col1, long& row1, long& col2, long& row2, int normalize)
{
    col1 = this->sel_col1;
    row1 = this->sel_row1;
    col2 = this->sel_col2;
    row2 = this->sel_row2;

    if (col1 == -1 && row1 == -1 && col2 == -1 && row2 == -1) {
        return 0;
    }

    if (col1 < 0) {
        col1 = 0;
    } else if (col1 >= this->map->map_width) {
        col1 = this->map->map_width - 1;
    }

    if (row1 < 0) {
        row1 = 0;
    } else if (row1 >= this->map->map_height) {
        row1 = this->map->map_height - 1;
    }

    if (col2 < 0) {
        col2 = 0;
    } else if (col2 >= this->map->map_width) {
        col2 = this->map->map_width - 1;
    }

    if (row2 < 0) {
        row2 = 0;
    } else if (row2 >= this->map->map_height) {
        row2 = this->map->map_height - 1;
    }

    if (normalize) {
        long c1 = col1;
        long c2 = col2;
        long r1 = row1;
        long r2 = row2;

        col1 = (c1 < c2) ? c1 : c2;
        row1 = (r1 < r2) ? r1 : r2;
        col2 = (c1 > c2) ? c1 : c2;
        row2 = (r1 > r2) ? r1 : r2;
    }

    return 1;
}

// VA: 005346F0 RGE_View::CreateBlitQueue
// Attempt log:
// v1 natural RECT/queue implementation with duplicated one-blit tail: compiled 780B but 94.49% positional, stack 0x14 not original 0x34.
// v2 single allocation/fill tail, top locals mirror packet names: undersized 736B under /O2, so tail sharing got closer structurally but not size.
// v3 /GX with v2: no change, still 736B; rolled back flag because no EH evidence.
// v4 /Od with v2: 780B same size but EBP-frame /Od family, 95.00% positional; rolled back flag.
// v5 kept v2 because it is cleaner and documents likely intended source, but it is not accepted-drift-safe.
// probe 6 structural/layout: restored the period TPanel render_rect at +8c/+90
// and the RGE_View queue-offset fields at +2ec/+2f0; the prior flat class put
// the panel rectangle at the wrong offsets and compiled the final assignments
// away.  The binary proves the final source is render_rect.left/top -> offsets.
// probe 7: a local yd initialized from param_4 was codegen-duplicate; retained
// only as the binary-supported vertical-delta naming clue.
// probe 8: a fixed-stride long* source-entry cursor moved to 0x2c frame / 783B
// and improved shape; direct byte-offset destination stores retained the
// original repeated queue-base reload schedule.
// probe 9: count=vBlits before off=0 reached 781B / 0x2c frame and improved
// resync; the loop counter stayed in the incoming dst-reference home.
// probe 10: hoisting count into an outer non-outside guard was one byte worse
// and lost an exact block; rolled back to probe 9.
// probe 12: removing the local yd copy and using the typed param_4 directly
// left the first hunk and all metrics unchanged; restored the clean source.
// probe 14: swapped loop counter initialization; output grew to 783B and was rolled back.
// probe 15: inlined boundary loads into the overlap predicate; VC5 emitted duplicate code.
// probe 16: used the binary's outside-marker slot directly; duplicate code.
// probe 18: boundary declaration order was duplicate; probe 19 sentinel order was worse and rolled back.
// probe 22: initialized the outside one-blit RECT from the already loaded boundary values;
// best current result is 780B, 0x24 frame, 671-byte positional diff, 61.44% shape.
// probe 23: a distinct outside marker was codegen-duplicate; retained for readable ownership.
// paused: calls, CFG counts, queue fields, clipping behavior, and output size align; frame and
// local/register topology remain structurally different. Next lead is expanded original locals.
// Reassessment pass sa-460299c2: 20 additional source hypotheses were compiled and checked.
// Decompiler-shaped locals and an explicit dword outside marker moved the frame to 0x2c but
// worsened size and shape. Aggregate RECT initialization, dead outside-arm assignments,
// scalar coordinate locals, typed queue cursors, explicit queue stores, queue ownership
// aliases, and declaration-order changes were duplicate or worse. Reversing the first two
// overlap predicates to source-left greater-than form improved shape only (62.29%). Writing
// vBlits greater-than allocated improved the best clean basin to 668 differing bytes and
// 62.71% shape, but the frame stayed 0x24. The pinned natural source remains the clean
// reconstruction. Calls are 2/2 aligned, size is 780, CFG counts are 23/23 conditions,
// 5/5 jumps, and 1/1 return; unresolved evidence is the original 0x34 local frame and
// register/stack topology. No policy-valid exact source was found.

// Follow-up sa-476ae437-r1: the original PDB locals show One_Blit as the
// outside marker, nBlits as the final count, and yd/nBlits sharing a home.
// Renaming roles alone was duplicate. Reusing nBlits for the absolute-y
// denominator before its count assignment reduced the mismatch to 664 bytes
// and raised shape to 68.94%; this is retained as the smallest supported
// lifetime model. Matching blt_deltaX/Y names and a PDB yd alias were
// duplicates. Reversing the first two overlap comparisons to source-bound
// greater-than form raised shape to 69.79% without changing the 664-byte
// mismatch. A local bounds RECT and SDK windows/tagRECT context were
// duplicates or worse. The capacity guard written as nBlits greater than
// allocated raised shape to 70.64%, exact-block coverage to 12.77%, and gave
// a 665-byte mismatch; this source form is retained because its cmp/jle
// direction matches the executable. Reversing allocation stores and adding a
// typed calloc result local were worse or codegen-duplicate. Final current
// result: 780 bytes, 0x24 frame versus original 0x34, 2/2 ordered calls,
// 23/23 conditions, 5/5 jumps, 1/1 return, 665 differing bytes. The blocker
// remains the original four boundary spill slots and prologue register/home
// topology. No accepted-drift residue is supported.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);


void RGE_View::CreateBlitQueue(tagRECT& param_1, tagRECT& param_2, int param_3, int param_4)
{
    int nBlits;
    int yd;
    tagRECT blt_src;
    int local_4;
    int One_Blit = 0;
    int vBlits;
    int blt_deltaX;
    int blt_deltaY;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar6;
    int xd;
    int off;
    int count;
    yd = param_4;
    if ((param_3 != 0) || (yd != 0)) {
        if (((iVar6 = param_1.top) > param_2.bottom) ||
            (((iVar1 = param_1.left, iVar1 > param_2.right ||
              (iVar2 = param_1.bottom, iVar2 < param_2.top)) ||
             (iVar3 = param_1.right, iVar3 < param_2.left)))) {
            One_Blit = 1;
            nBlits = 1;
            blt_src.left = iVar1;
            blt_src.top = iVar6;
            blt_src.right = iVar3;
            local_4 = iVar2;
        } else {
            nBlits = param_4;
            if (nBlits < 0) nBlits = -nBlits;
            xd = param_3;
            if (xd < 0) xd = -xd;
            vBlits = 9999;
            if (param_4 != 0) vBlits = (nBlits + (iVar2 - iVar6)) / nBlits;
            nBlits = 9999;
            if (param_3 != 0) nBlits = (xd + (iVar3 - iVar1)) / xd;
            blt_src.left = param_1.left;
            blt_src.top = param_1.top;
            blt_src.right = param_1.right;
            local_4 = param_1.bottom;
            blt_deltaX = 0;
            blt_deltaY = 0;
            if (vBlits < nBlits) {
                nBlits = vBlits;
                blt_deltaY = param_4;
                if (param_4 < 0) blt_src.top = param_4 + iVar2 + 1;
                else local_4 = param_4 + iVar6 - 1;
            } else {
                blt_deltaX = param_3;
                if (param_3 < 0) blt_src.left = param_3 + iVar3 + 1;
                else blt_src.right = param_3 + iVar1 - 1;
            }
        }

        if (nBlits > this->Blt_Queue_Allocated) {
            if (this->Blit_Queue != 0) free(this->Blit_Queue);
            this->Blit_Queue = 0;
        }
        if (this->Blit_Queue == 0) {
            this->Blit_Queue = (Blit_Queue_Entry*)calloc(nBlits, 0x20);
            this->Blt_Queue_Allocated = nBlits;
        }
        if (One_Blit) {
            this->Blit_Queue[0].src = param_1;
            this->Blit_Queue[0].dest = param_2;
        } else if (nBlits > 0) {
            count = nBlits;
            off = 0;
            do {
                long* plVar7 = (long*)((char*)this->Blit_Queue + off);
                plVar7[0] = blt_src.left;
                plVar7[1] = blt_src.top;
                plVar7[2] = blt_src.right;
                plVar7[3] = local_4;
                *(int*)((char*)this->Blit_Queue + off + 0x14) = blt_src.top - param_4;
                *(int*)((char*)this->Blit_Queue + off + 0x10) = blt_src.left - param_3;
                *(int*)((char*)this->Blit_Queue + off + 0x1c) = local_4 - param_4;
                *(int*)((char*)this->Blit_Queue + off + 0x18) = blt_src.right - param_3;
                blt_src.top += blt_deltaY;
                local_4 += blt_deltaY;
                blt_src.left += blt_deltaX;
                blt_src.right += blt_deltaX;
                if (blt_src.top < param_1.top) blt_src.top = param_1.top;
                if (blt_src.left < param_1.left) blt_src.left = param_1.left;
                if (blt_src.right > param_1.right) blt_src.right = param_1.right;
                if (local_4 > param_1.bottom) local_4 = param_1.bottom;
                off += 0x20;
                count--;
            } while (count != 0);
        }
        this->Queued_Blits = 1;
        this->Blit_Queue_Size = nBlits;
        this->Current_Blit = -1;
        this->Blit_Offset_X = this->render_rect.left;
        this->Blit_Offset_Y = this->render_rect.top;
    }
}

// RGE_View::ProcessQueuedBlit (00534A00)
// PDB source: view.cpp:1218-1318
// Size: 219 bytes
//
// Attempt log:
// - Old parked state: wrong ss slot mapping (src.right written to index 3),
//   missing src.bottom entry, ss[5]-induced sub esp,14h frame. Rewrote from scratch.
// - Canonical ownership (ground truth): render_area(TDrawArea*)@+0x20,
//   DrawSurface(IDirectDrawSurface*)@TDrawArea+0x3C; Queued_Blits@+0x2D8,
//   Blit_Queue@+0x2DC, Blit_Queue_Size@+0x2E0, Current_Blit@+0x2E8,
//   Blit_Offset_X@+0x2EC, Blit_Offset_Y@+0x2F0. Blit_Queue_Entry = 32B
//   { tagRECT src; tagRECT dest; }.
// - Vtable evidence: [vtable+0x34] = GetBltStatus(this,1) (2 args __stdcall),
//   [vtable+0x1C] = BltFast(this, dest.left+OX, dest.top+OY, DrawSurface,
//   &src, 16) (6 args __stdcall) — DirectDraw surface COM calls.
// - RECT math (binary-observed field processing order top,left,bottom,right):
//   src.top = st+OY, src.left = sl+OX, src.bottom = sb+OY+1, src.right = sr+OX+1;
//   dest coords = dl+OX, dt+OY. Final check loads Blit_Queue_Size first then
//   Current_Blit+1 (size on the left of the comparison).
// - Post-call dead store of the BltFast result into the force parameter home
//   ([esp+20h] = E+4) implies the original source reused the dead force param
//   as the call-result scratch (force = BltFast(...)).
// - Probe 1 (baseline): src.bottom=BltFast + left,top,right,bottom field order:
//   diff=197, shape=67.95%; store eliminated; field order left,top,right,bottom
//   (rebuilt preserved source order -> original wrote top,left,bottom,right).
// - Probe 2 (layout, current): top,left,bottom,right field order + force=BltFast:
//   diff=195, shape=73.08%; RECT region now matches; remaining drift is the
//   extra push ebx (vtable lands in ebx instead of edx -> one extra saved reg),
//   the &src lea/push interleave (rebuilt hoists &src before push 16), dest
//   register roles, the eliminated post-call param-slot store, and final-check
//   load order (size-first vs CB-first).
// - Left in scratch: pure VC5 register/scheduling/encoding drift inside the
//   isolated scratch TU; the post-call dead store is eliminated by VC5 here but
//   was kept in the original view.cpp TU (TU-context-sensitive DSE/scheduling).
// - Continuation: reversing the final bound comparison made the branch shape
//   worse without changing the byte diff; restored the clean source.
// - Continuation: adding the proven TPanel base improved shape but worsened the
//   byte diff; the SDK ddraw.h surface, four-dword RECT buffer, narrow surface
//   local, volatile RECT, CINTERFACE/lpVtbl calls, and unused-call-result forms
//   were duplicates or worse.
// - Main-agent normalization retained the proven TPanel inheritance and base
//   render-area ownership despite the slightly worse positional metric; the
//   shape improves and canonical source remains authoritative over register
//   steering in this unresolved function.
// - Session follow-up: the size-left final-bound spelling and a late typed
//   surface local were rolled back (the former worsened CFG and the latter was
//   a codegen duplicate).  Keep this canonical COM/RECT source; remaining
//   drift is the isolated VC5 save/register and argument scheduling basin.
// FLAGS: none. Inline asm forbidden.
// Best retained source: canonical typed COM/RECT reconstruction, 219 bytes,
// frame 0x10, 2/2 calls aligned, diff=199.
// Main-agent audit confirmed canonical panel/draw-area/DirectDraw ownership;
// no dead-store or COM scheduling steering survives.
// Matching-worker continuation: an early typed surface cache worsened the
// resync basin (203 differing bytes), while restoring the full donor TPanel
// virtual surface was a codegen duplicate.  Retain the clean 219-byte source;
// the unresolved gap remains the isolated COM vtable/save-register and
// parameter-home scheduling basin, not call/ABI/layout uncertainty.
// fresh orch-view-02 pass: a late source-RECT pointer and named destination
//   coordinate locals were codegen duplicates; restored clean.
// fresh pass: 16 natural RECT/call-form variants produced four groups and no
//   exact result; all 12 size-eligible variants retained the extra EBX save.
// fresh pass: debug-context flag lab (64 variants, /Zd /Zi /Z7) produced no
//   distinct winning group or exact match; default flags remain authoritative.
// fresh pass: volatile force preserved a post-call home store and improved
//   resync by one byte but grew to 221 bytes; diagnostic only, restored.
// fresh pass: reordered RECT stores, function-scope RECT/entry locals, flat
//   long[8] queue access, and reference-parameter RECT ABI were duplicates or
//   worse; canonical typed COM/RECT source retained.
// wave21 probe: replaced gap-only panel/view declarations with the proven
//   TPanel/RGE_View field ownership, including Blt_Queue_Allocated and the
//   render rectangles; emitted code was unchanged (219B, diff=199).
// wave21 probe: added the proven RGE_View virtual dispatch declarations to
//   restore the view.h-shaped derived context; emitted code was unchanged.
// sa-f48fba19-r1 pass: the full inferred TPanel/RGE_View virtual slot surface
//   was a codegen duplicate; a late TDrawArea receiver local, address-taken
//   force-result pointer, and named source-left temporary were also duplicates.
// sa-f48fba19-r1 pass: windows.h/standard RECT context reached the prior
//   diagnostic 195-byte group but worsened shape and retained EBX; DWORD
//   BltFast signedness was duplicate. A narrow volatile force-home store
//   improved resync but grew to 221 bytes, and a late queue-size local plus
//   short-circuit early guard were duplicates; all were rolled back.
// orch-00534A00-L pass: baseline after claim remained 219B, diff=199, with
//   2/2 ordered calls and an extra EBX save from the first paired hunk.
// orch-00534A00-L pass: assigning the result to src.bottom, using an entry
//   reference, reversing destination add operands, restoring 51 RGE_View
//   slots, and using C-interface lpVtbl calls were codegen duplicates.
// orch-00534A00-L pass: windows.h RECT context reached diff=195 but reduced
//   shape and resync. Restored the canonical local RECT source; blocker is
//   TU-sensitive VC5 save/register and COM argument scheduling.
// follow-534A00-r1: exact view.cpp TPanel virtual surface and reduced RGE_View
//   surface were duplicate; positive status-gate topology was also duplicate.
// follow-534A00-r1: donor RGE_View destructor, opaque BltFast source pointer,
//   full TDrawArea extent, and IDirectDrawSurface:IUnknown inheritance were
//   each codegen duplicates; restored canonical typed ownership after each.
// Paused: the remaining mismatch is the extra EBX save and COM argument/source
//   scheduling basin; no canonical ownership or virtual-slot uncertainty remains.
// sa09-ProcessQueuedBlit reassessment: pointer arithmetic, RECT/entry declaration
//   order, aggregate and zero RECT initialization, late surface/entry aliases,
//   discarded BltFast result, explicit queued guard, reversed bound terms, and
//   SDK DWORD coordinate types were duplicates or worse. Restored this clean
//   typed source; the first mismatch remains the extra EBX save at +0003.
// sa-f2967bfc-r1 continuation: protected access matched the original IAEXH
//   symbol but did not change codegen. A named BltFast flags value was also a
//   duplicate. Restored the canonical source; the extra EBX save remains.
// sa-d5f42b52-r1 continuation: source-RECT declaration order and function scope,
//   queue-entry pointer scope, an address-taken force result, and the proven
//   TPanel virtual surface were all codegen duplicates (219B, diff=199).
//   A natural five-form source lab (surface alias, entry reference, aggregate
//   RECT, and direct queue indexing) produced only two nonexact groups; all
//   size-eligible variants retained the extra EBX save. A 128-sample neutral
//   ambient declaration sweep also produced no new group. Restore the pinned
//   source; the isolated save/register and COM scheduling basin remains.
// sa-900450cb reassessment: destination-coordinate locals, string.h and
// windows.h context, a polymorphic TDrawArea, a full DirectDraw method surface,
// a named BltFast result, and size-left final-bound spelling were each natural
// probes. They were duplicate or worse (the headers reached diff=195 with
// weaker shape). Restored the pinned 219-byte source; extra EBX save remains.

// sa-cd1ad2b3-r1 strict-span audit: the 14 spans total 199 bytes. The first
//   span is the extra EBX save. It shifts every later branch and stack home.
//   The first paired body hunk then shows early &src materialization before
//   push 16. This keeps the source-top value in EBX instead of EBP. It also
//   changes RECT stores, the receiver color, and COM push order. The final
//   hunk is separate: VC5 removes the dead BltFast result store, loads
//   Current_Blit before Blit_Queue_Size, and swaps CMP operands. The epilogue
//   has the matching EBX pop and two trailing NOPs.
// sa-cd1ad2b3-r1 H1-H20: long result, area/surface pointer and reference
//   aliases, named index and offset locals, period header contexts, combined
//   status guard, delayed RECT pointer, int/unsigned RECT fields, nested
//   failure guards, explicit casts, increment spellings, and a named final
//   index were duplicate, worse, or invalid-context probes. No probe changed
//   the 219-byte clean source basin.
// sa-cd1ad2b3-r1 conclusion: extra EBX save, COM argument/source scheduling,
//   and dead-result-store behavior remain isolated VC5/TU-context drift.
//   Restore and retain the pinned natural typed source.

// sa-7575e400-r1 context follow-up: full adjacent TDrawArea declarations,
// adjacent CreateBlitQueue and matching pick bodies, ambient draw.cpp
// declarations, SDK aliases, HRESULT returns, and removed derived virtuals
// did not change the 219-byte target basin. The full TDrawArea surface grew
// the target to 223 bytes and 209 differing bytes. Native windows.h and the
// allocator/string header contexts reached the known 195-byte group but kept
// weaker shape and the extra EBX save. A size-minus-one final threshold kept
// 199 differing bytes and improved edit resync only; it did not improve the
// strict positional result. Long force, a RECT reference, and a const queue
// entry were duplicates or invalid ABI choices. All experiments were restored.
// Source-gate audit: keep the typed queue records and native DirectDraw slot
// order from the period VC4.2 headers. Ignore the BltFast result instead of
// aliasing the force home.
// Validation: the canonical interface keeps the two ordered calls at
// vslot+0x34 and vslot+0x1C. The source-gate build remains 219 bytes with a
// 195-byte mismatch; the old extra EBX save and scheduling drift remain.
//
// sa-0cd276c8-r1 continuation: H1-H25 retested address-taken RECT forms,
// full TDrawArea fields, direct queue indexing, array-word records, local
// declaration order, surface aliases, predicate spellings, nested bounds,
// named index and queue-size lifetimes, LONG member types, result-home forms,
// destination locals, and receiver-only aliases. All retained-size variants
// kept the 219-byte / 195-difference basin and 2/2 ordered virtual calls.
// A volatile result local was diagnostic only: it reached 183 differences and
// 76.00% shape but added unsupported memory effects, so it was removed.
// A focused five-variant manual-DirectDraw context lab produced two groups;
// the best remained 199 differences. The canonical source is restored.
// Evidence conclusion: the extra EBX save starts at +0003 and shifts all
// later homes and branches. The remaining differences alter instruction
// topology, register ownership, and call argument scheduling. They are broad,
// not a localized behavior-equivalent residue. No accepted-drift case is
// supported.

// sa-d3e4876f-r1 continuation: assigning the BltFast result to force was
// eliminated by VC5. The period drawarea header did not compile with the
// proven method arity. A minimal typed DirectDraw interface was a codegen
// duplicate. A full proven TPanel field surface was also a duplicate. Each
// was restored.
// Authentic-context audit: a temporary view.cpp wrapper included the real
// view prefix and defined the exact RGE_View member. It retained the extra
// EBX save and the same COM argument schedule. No config or anchor changed.
// Fresh validation remains MISMATCH: 215 rebuilt bytes versus 219 original,
// 195 differing bytes, 2/2 ordered calls, and first mismatch at +0003.

// sa-dfd48413-r1 exact-finish audit: translation_unit_prefixes.py rejects this
// target because view.cpp has no configured target owner. A generated wrapper
// using the current view prefix and native VC5 view flags compiled the target,
// but it is not an authentic context: the prefix omits PDB owners between
// calc_draw_vars and ProcessQueuedBlit, and its grouped anchors are not exact.
// Its target stayed in the 215-byte extra-EBX basin (191 common-byte changes,
// plus the four-byte boundary gap). Do not claim this wrapper as exact context.
// Missing evidence: the complete period view.cpp source prefix and a reviewed
// grouped-owner manifest that can validate exact anchors without config edits.



void RGE_View::ProcessQueuedBlit(int force)
{
    if (!this->Queued_Blits)
        return;

    if (force == 0) {
        if (this->render_area->DrawSurface->GetBltStatus(1))
            return;
    }

    this->Current_Blit++;
    if (this->Blit_Queue && this->Current_Blit >= 0 && this->Current_Blit < this->Blit_Queue_Size) {
        Blit_Queue_Entry* entry = &this->Blit_Queue[this->Current_Blit];
        tagRECT src;
        src.top = entry->src.top + this->Blit_Offset_Y;
        src.left = entry->src.left + this->Blit_Offset_X;
        src.bottom = entry->src.bottom + this->Blit_Offset_Y + 1;
        src.right = entry->src.right + this->Blit_Offset_X + 1;
        this->render_area->DrawSurface->BltFast(
            entry->dest.left + this->Blit_Offset_X,
            entry->dest.top + this->Blit_Offset_Y,
            this->render_area->DrawSurface, &src, 16);
        if (this->Current_Blit + 1 < this->Blit_Queue_Size)
            return;
    }
    this->Queued_Blits = 0;
}

// VA: 00534AE0 RGE_View::draw (view.cpp:1324-1904, 1835 bytes, __thiscall virtual)
// Attempt log:
//   - Canonical ownership (from asm/PDB/donors 00533760, 0053A9C0, 004777C0):
//     RGE_View : TPanel (vptr@+0); render_area@+0x20; screen_w@+0x14, screen_h@+0x18;
//     world@+0xFC; start_scr_col/row@0x126/0x128, start_map_col/row@0x12A/0x12C;
//     map_scr_x/y_offset@0x130/0x134; render_terrain_mode(byte)@0x142;
//     TSpan_List_Manager* clip masks @0x178/0x17C/0x180;
//     Limited_Render_Rect@0x2A0, Use_Rect2@0x2A4, Render_Rect1@0x2A8, Render_Rect2@0x2B8;
//     Float_X/Y_Delta@0x2D0/0x2D4, Queued_Blits@0x2D8; save_area1@0x324; prior_objs@0x334.
//     TPanel virtuals: draw_setup(int)@slot0x28, draw_finish()@slot0x2C.
//     TDrawArea: Width@0x18, Height@0x1C, ClipRect@0x28, DisplayOffsets@0xBC.
//   - Globals: view_debug_redraw_all@0x87D7A4, view_debug_ObstructionMap@0x87D7A8,
//     view_debug_palette@0x87D7B0, frame_count@0x87D7B8, tiles_drawn@0x87D7BC,
//     MouseSystem@0x62E660, rge_base_game@0x62C574.
//   - Prior diagnostic variant with a false screen_w/screen_h write and duplicate
//     clipping was rejected: it is not executable-supported source. The retained
//     reconstruction has one natural clipping pass and never writes those members.
//   - Materializing `redraw_all = view_debug_redraw_all` before tiles_drawn recovered
//     the original global-load-before-frame/store schedule (1764B; frame remained
//     0x50). Keeping raw screen_width/screen_height locals from the initial rectangle
//     setup through the two directional clips restored the proven 0x54 frame and
//     reached 1792B / 67.7% shape / 1498 strict diff while retaining 26/26 calls.
//   - Narrow `short` dx/dy locals were tested and rolled back: they changed the frame
//     to 0x50 and reduced structural shape despite a smaller size gap. Reordering
//     snapshot/map-offset declarations was mostly codegen-neutral.
//   - Late final clipping reads were changed back to direct `this->pnl_wid` /
//     `this->pnl_hgt` expressions, matching the binary's member rereads without
//     member writes. This retained 26/26 calls and frame 0x54, improved shape to
//     77.3% and resync similarity to 64.5% (1782B; 1501 strict diff); keep this
//     source-plausible candidate rather than the opaque metric-only variant.
//   - A named rge_base_game intermediate recovered the A1 global-load encoding but
//     did not improve whole-function structure, so it was rolled back. No volatility,
//     inline asm, fake stores, or opaque register-steering scaffolding is retained.
//   - Bounded pause: remaining structural drift is broad around VC5 register/local
//     liveness and clipping block layout; next lead is a focused natural-source
//     variant lab or full view.cpp TU context, not more false member writes.
//   - Continuation audit: authentic PDB order confirms draw (00534AE0) is the
//     first unleased normal view.cpp sibling after ProcessQueuedBlit. Snapshot
//     declaration and split-assignment permutations did not improve the clean
//     basin. Signed 16-bit displacement locals, with and without direct cast
//     call arguments, changed the frame to 0x50 and worsened structure (1695
//     strict bytes). Ghidra-shaped rounding through new_rect.left/top was a
//     codegen duplicate. Windows SDK RECT context changed the result to 1475
//     bytes (1794B) and was rejected. Clip-arm inversion preserved 1471 bytes
//     but did not recover the late fallback block. The clean source is restored.
//   - Session sa-3ce3c739-r1 (2026-08-06, 10+ probes): improved 1501 -> 1441 strict
//     (78.0% shape, -49B, frame 0x54, 26/26 calls; codegen-best diagnostic now 1441).
//     Retained changes (all natural, PDB/binary-supported):
//       * rounding tests spelled `dx <= 0` / `dy <= 0` instead of `dx < 1` ->
//         matches orig `test reg,reg; jg` form (was `cmp reg,1; jge`);
//       * clip_rect2 sub-if arms swapped to `if (clip_rect1.left != -1) {Use_Rect2/
//         Render_Rect2} else {Limited_Render_Rect/Render_Rect1}` -- PDB line map
//         (1765 test / 1768 else inline / 1773 if-arm out-of-line) proves this order;
//       * old_map_scr_x_offset declared BEFORE y -> VC5 spills map_scr_y_offset to
//         [esp+1Ch] like the original (was spilling x; 1484 -> 1444);
//       * snapshot declaration map_col-first -> original load order (1444 -> 1441).
//     Rejected/negative evidence:
//       * `short dx/dy` again collapses frame to 0x50 (map offsets both land in
//         callee-saved regs; the dedicated zero moves to ecx) -- binary proves 16-bit
//         dx/dy ops but the 0x54 frame needs the zero in edi with map_y spilled;
//         no source spelling found to reproduce that exact allocation.
//       * dy-before-dx computation order worsens (1643); rect declaration order and
//         snapshot declaration order are codegen-neutral; fuller TPanel/RGE_View
//         vtable/field surface (64 slots, virtual dtor, DispSel_List) is
//         codegen-duplicate -- the register basin is robust to TU class surface.
//     Current basin: zero register = esi (orig edi); start_map_col = bx (orig si);
//     map_y = [esp+1Ch] (orig same) but map_x = edi (orig ebx); dx/dy 32-bit in
//     ebx/eax (orig 16-bit dx/si); old_rect@[esp+54h]/clip_rect1@[esp+44h] slots
//     swapped vs orig; Render_Rect1 copy stays inline (orig out-of-line at 005351D1)
//     -> PtrClear2->Poll region +46B vs orig. These are one coherent allocator basin;
//     the remaining blocker is flipping zero-register choice, not more local shapes.
//   - BINARY NOTE: The original tests Float_X_Delta < 0 before the draw2 lock.
//     It skips that lock when the displacement is nonnegative but below Width.
//   - Session sa-7c437db9-r1: 21 meaningful probes reached the same allocator
//     basin. The best metric-only source is 1441 strict bytes but omits that
//     binary-proven guard. The retained source has 1471 strict bytes, 1792B,
//     frame 0x54, 26/26 calls, and 78.76% shape similarity.
//   - Tested and rejected: absolute global overlays, direct redraw tests, zero
//     locals, cold-copy gotos, snapshot permutations, narrow dx/dy types,
//     displacement aliases, lock flags, branch order, and sign spellings.
//   - Next lead: recover the original zero-register and rectangle-home colors
//     through full period view.cpp context. Do not add register-steering forms.
// FLAGS: none (default /O2 /Oy). Inline asm forbidden.


#define clear_rect clip_rect
#define field_8C render_rect_left
#define field_90 render_rect_top
#define clear_color color

void RGE_View::draw()
{
    tagRECT clip_rect2;
    tagRECT new_rect;
    tagRECT old_rect;
    tagRECT clip_rect1;
    int redraw_all = view_debug_redraw_all;

    tiles_drawn = 0;
    if (redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == 0) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clear_rect, this->clear_color);
        this->draw_finish();
        return;
    }

    short old_start_map_col = this->start_map_col;
    short old_start_map_row = this->start_map_row;
    short old_start_scr_col = this->start_scr_col;
    short old_start_scr_row = this->start_scr_row;
    this->Terrain_Clip_Mask->ResetAll();
    this->Terrain_Fog_Clip_Mask->ResetAll();
    this->Master_Clip_Mask->ResetAll();
    int old_map_scr_x_offset = this->map_scr_x_offset;
    int old_map_scr_y_offset = this->map_scr_y_offset;
    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;
    this->update();
    this->draw_setup(0);

    if (this->render_terrain_mode == 1) {
        if ((this->start_map_col == old_start_map_col && this->start_map_row == old_start_map_row) &&
            (this->start_scr_col == old_start_scr_col && this->start_scr_row == old_start_scr_row)) {
            goto label_done;
        }

        long dx = (short)this->map_scr_x_offset - old_map_scr_x_offset;
        long dy = (short)this->map_scr_y_offset - old_map_scr_y_offset;
        if (dx == 0 && dy == 0) goto label_done;

        int screen_width = this->pnl_wid;
        int screen_height = this->pnl_hgt;

        new_rect.left = (int)dx;
        new_rect.top = (int)dy;
        old_rect.left = 0;
        old_rect.top = 0;
        old_rect.right = screen_width - 1;
        old_rect.bottom = screen_height - 1;
        new_rect.right = old_rect.right + new_rect.left;
        new_rect.bottom = old_rect.bottom + new_rect.top;

        if (new_rect.bottom < 0 || new_rect.right < 0 || old_rect.bottom < new_rect.top || old_rect.right < new_rect.left) {
            this->render_terrain_mode = 0;
            goto label_done;
        }

        if ((dx & 7) != 0) {
            long t = dx;
            if (dx <= 0) t = dx + 7;
            long a = (t & ~7) - dx;
            dx += a;
            this->map_scr_x_offset += a;
        }
        if ((dy & 7) != 0) {
            long t = dy;
            if (dy <= 0) t = dy + 7;
            long a = (t & ~7) - dy;
            dy += a;
            this->map_scr_y_offset += a;
        }

        if (dx < 0) {
            old_rect.left = 0;
            old_rect.right = (int)dx + screen_width - 1;
            new_rect.left = -(int)dx;
        } else {
            old_rect.left = (int)dx;
            old_rect.right = screen_width - 1;
            new_rect.left = 0;
            screen_width = screen_width - old_rect.left;
        }
        new_rect.right = screen_width - 1;

        if (dy < 0) {
            old_rect.top = 0;
            old_rect.bottom = (int)dy + screen_height - 1;
            new_rect.top = -(int)dy;
        } else {
            old_rect.top = (int)dy;
            old_rect.bottom = screen_height - 1;
            new_rect.top = 0;
            screen_height = screen_height - old_rect.top;
        }
        new_rect.bottom = screen_height - 1;

        int xd = (int)dx;
        int yd = (int)dy;

        if (this->render_area->DrawSystem->DrawType == 1 || this->render_area->UsingVidMem == 0) {
            this->render_area->OverlayMemCopy(old_rect, new_rect, xd, yd,
                                               this->render_rect.left,
                                               this->render_rect.top);
            this->Queued_Blits = 0;
        } else {
            this->CreateBlitQueue(old_rect, new_rect, xd, yd);
            if (MouseSystem != 0) MouseSystem->Poll();
            if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);
        }

        this->prior_objs->Scroll(xd, yd);

        int fxd = this->Float_X_Delta + xd;
        this->Float_X_Delta = fxd;
        if (fxd >= this->save_area1->Width) {
            if (this->save_area1->Lock("view::draw", 1) != 0) {
                memcpy((void*)this->save_area1->DisplayOffsets[0],
                       (const void*)((int*)this->save_area1->DisplayOffsets[this->save_area1->Height - 1] + this->save_area1->Width),
                       this->Float_X_Delta - xd);
                this->Float_X_Delta -= this->save_area1->Width;
                this->Float_Y_Delta += 1;
                if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta = 0;
                this->save_area1->Unlock("view::draw");
            }
        } else {
            if (fxd < 0 && this->save_area1->Lock("view::draw2", 1) != 0) {
                this->Float_X_Delta += this->save_area1->Width;
                this->Float_Y_Delta -= 1;
                if (this->Float_Y_Delta < 0) this->Float_Y_Delta = this->save_area1->Height - 1;
                memcpy((void*)this->save_area1->DisplayOffsets[0],
                       (const void*)((int*)this->save_area1->DisplayOffsets[this->save_area1->Height - 1] + this->save_area1->Width),
                       this->Float_X_Delta);
                this->save_area1->Unlock("view::draw3");
            }
        }

        this->Float_Y_Delta += yd;
        if (this->Float_Y_Delta < 0) this->Float_Y_Delta += this->save_area1->Height;
        if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta -= this->save_area1->Height;

        this->save_area1->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

        if ((new_rect.left == 0) && (new_rect.right == this->pnl_wid - 1)) {
            clip_rect1.left = -1;
            if ((new_rect.top == 0) && (new_rect.bottom == this->pnl_hgt - 1)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                clip_rect2.right = this->pnl_wid - 1;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.bottom = this->pnl_hgt - 1;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else if (new_rect.left == 0) {
            clip_rect1.right = this->pnl_wid - 1;
            clip_rect1.left = new_rect.right + 1;
            clip_rect1.bottom = this->pnl_hgt - 1;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else {
            clip_rect1.right = new_rect.left - 1;
            clip_rect1.bottom = this->pnl_hgt - 1;
            clip_rect1.left = 0;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = new_rect.left;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = this->pnl_wid - 1;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = this->pnl_wid - 1;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        }

        if (clip_rect1.left != -1) {
            this->save_area1->PtrClear(&clip_rect1, 0);
            this->Limited_Render_Rect = 1;
            this->Render_Rect1 = clip_rect1;
        }
        if (clip_rect2.left != -1) {
            this->save_area1->PtrClear(&clip_rect2, 0);
            if (clip_rect1.left != -1) {
                this->Use_Rect2 = 1;
                this->Render_Rect2 = clip_rect2;
            } else {
                this->Limited_Render_Rect = 1;
                this->Render_Rect1 = clip_rect2;
            }
        }
    }

label_done:
    if (MouseSystem != 0) MouseSystem->Poll();
    if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);

    int gm = rge_base_game->game_mode;
    if ((gm >= 9 && gm <= 10) || gm == 0x13) {
        this->draw_paint_brush();
    }

    if (this->render_terrain_mode == 0) {
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);
        this->save_area1->PtrClear(&this->save_area1->ClipRect, 0);
    }

    this->draw_view(10, this->save_area1);
    this->render_terrain_mode = 1;
    this->draw_finish();
    frame_count++;
}

#undef clear_rect
#undef field_8C
#undef field_90
#undef clear_color

// 00535210 RGE_View::update
// Attempt log:
// 1: natural decompiler-shaped implementation with local RGE_View/RGE_Map/RGE_Tile layout: wrong field ordering caused +4 offsets and 0x18 frame; .text 576 < original 619.
// 2: fix view field offsets/order from asm: center_map at 0x122/0x124, start screen/map fields at 0x126..0x12c, last_view at 0x138/0x13c; offsets fixed but compiler still chooses 0x18 frame and EDI=player.
// 3: rewrite body closer to decompiler with named short temporaries instead of int-heavy expression staging: size improved 576 -> 592, offsets fixed, but frame still sub esp,18 and EDI holds player instead of original EBX; check cannot compare because .text < configured 619.
// 4: explicit default /O2 /Oy flags produced same 592-byte body; removed redundant flag file.
// 5: /O1 /Oy probe shrank body to 546 bytes, wrong direction; rolled back to default flags.
// 6: using exact field order is required: player 0x100, map 0x104, tile dims 0x10c/0x10e/0x110, max cols/rows 0x116/0x118, center_map 0x122/0x124, last_view 0x138/0x13c.
// 7: current blocker is source/FPU liveness basin: original uses only 0x0c locals, EBX=player then BX=center_scr_col, BP=center_scr_row, and keeps fractional deltas on FPU stack; rebuilt spills more and uses 0x18 locals.
// 8: broad mismatch is not accepted_drift-safe; although behavior surface is close, register/frame/FPU scheduling differs before the geometry calculations.
// 9: likely next probes: restructure first half to avoid preserving converted col/row as C locals, and model the two __ftol adjustment results as stack-reused int temporaries rather than named shorts.
// 10: left in scratch after honest attempts; no exact match.
// 11: fresh pass restored the period TPanel ownership: pnl_wid/pnl_hgt at +14/+18 and render_rect at +8c.
// 12: reused the center-map shorts for the projection and viewport bounds; calls, CFG, and all field offsets stayed aligned.
// 13: direct view_y and (view_x - view_y) projection expressions gave the best current result: 550 bytes, 0x14 frame, 517 strict diff.
// 14: split fractional terms and an explicit col adjustment improved shape but worsened resync; rolled back as unsupported codegen steering.
// 15: remaining blocker is the original 0x0c FPU/local lifetime and register coloring (original EBX=player; rebuilt EDI=player); calls and CFG match.
// 16: direct typed this->player ownership was a codegen duplicate; retained the cached player local and clean candidate.
// 17: direct center-map field reload improved strict diff to 507 but widened the frame to 0x18; rolled back.
// 18: direct center-map assignments with a short cached column improved strict diff to 498 and shape to 50.9%; retained.
// 19: explicit int col_adj for map indexing was a codegen duplicate; removed.
// 20: natural fractional isometric projections from center-map deltas reduced strict diff to 495, but frame remains 0x1c and structural shape is unresolved.
// 21: positive __ftol temporaries and decompiler-style short lifetimes improved shape but worsened strict diff to 535; rolled back.
// 22: a typed three-slot fraction aggregate improved size by 2 bytes but worsened strict diff to 509; rolled back.
// 23: moving tile-half-height outside the second __ftol reduced the frame to 0x18 but widened strict diff to 510; retained only as behavior evidence.
// 24: term-wise x87 products reached size 620 and strict diff 489, but the half-height remained inside __ftol; diagnostic only.
// 25: term-wise products with the post-__ftol half-height matched size 619, strict diff 507, and preserved the observed truncation behavior.
// 26: positive term-wise projection temporaries with explicit subtract-half source form are the current clean candidate: 607 bytes, strict diff 494, 0x18 frame.
// 27: the reviewed DAT_005776b4 value is 0.5f; replacing the unsupported 48.0f
//     scale preserved the natural typed projection but changed the candidate to
//     595 bytes / 507 strict bytes / 0x18 frame.
// 28: grouping the half-row and column deltas matched the isometric behavior but
//     moved to a 567-byte codegen basin. The term-wise source better preserves the
//     original x87 stack shape and remains the clean candidate.
// 29: int projection temporaries preserve the original full-width __ftol results;
//     this is a codegen duplicate of the term-wise candidate.
// 30: a literal 0.5f is a closer metric basin but loses the reviewed data symbol;
//     restored DAT_005776b4 and the typed source.
// 31: explicit half-scaled terms on both coordinate axes, with the PDB/decompiler
//     center-map assignment order, reached 600 bytes / 494 strict bytes / 46.11%
//     shape.  The original 0x0c frame and three reused dword homes remain absent.
// 32: grouped half-scaled row/column expressions reached 579 bytes / 497 strict
//     bytes; the separate term-wise products are closer to the original x87 shape.
// 33: full-width projection locals reached 607 bytes / 523 strict bytes; rolled back.
// 34: row and coordinate float locals, polymorphic player/map surfaces, full TPanel
//     virtual context, split map-row fetch, and function-scope declaration variants
//     were duplicate or farther.  Restored the minimal typed surface.
// 35: fresh validation of the pinned clean source stayed at 600 bytes / 494
//     strict bytes / 0x18 frame, with four direct __ftol calls and exact owner.
// 36: a six-variant source lab covered term-wise, asymmetric, grouped, and
//     early-publication forms.  No exact variant appeared; the pinned clean
//     algebra remained the closest positional basin.
// 37-43: canonical RGE_View tail, polymorphic RGE_Player/RGE_Map, an explicit
//     center-column adjustment, and decompiler declaration order did not recover
//     the 0x0C frame.  The canonical polymorphic pair reached 606 bytes / 530
//     strict bytes and was restored.
// 44: the original reads DAT_005776B4 twice, once per projection.  It leaves the
//     column delta unscaled.  A natural asymmetric source reached 594 bytes /
//     536 strict bytes, so the clean metric candidate was not behavior-safe.
// 45: row-first term order was a codegen duplicate of the asymmetric form.
// 46: the current source keeps the binary-proven asymmetric projection and the
//     two early center-screen publications before the second conversion.
//     This preserves partial update state and fault order; exactness remains
//     blocked by the frame/register/FPU basin.


void RGE_View::update()
{
    RGE_Player* p;
    short sVar6;
    short sVar7;
    short sVar8;
    short sVar9;
    short sVar10;
    RGE_Tile* tile;
    p = this->player;
    if (p && (p->view_x != this->last_view_x || p->view_y != this->last_view_y)) {
        sVar6 = (short)(int)p->view_x;
        this->center_map_col = sVar6;
        sVar7 = (short)(int)p->view_y;
        sVar6 = this->center_map_col;
        this->center_map_row = sVar7;
        sVar9 = (short)(this->render_rect.left + this->pnl_wid / 2) - this->tile_half_wid;
        sVar10 = (short)(this->render_rect.top + this->pnl_hgt / 2) - this->tile_half_hgt;
        this->last_view_x = p->view_x;
        this->last_view_y = p->view_y;
        // BINARY NOTE: the executable publishes these base coordinates before
        // the second conversion.  Keep the partial state on a conversion fault.
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        sVar7 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_wid) +
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_wid));
        sVar8 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_hgt) -
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_hgt));
        sVar9 -= sVar7;
        sVar10 -= sVar8 + this->tile_half_hgt;
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        tile = this->map->map_row_offset[this->center_map_row] + sVar6;
        this->map_scr_x_offset = (int)tile->screen_xpos - (int)sVar9;
        this->map_scr_y_offset = ((int)this->elev_hgt * tile->height +
                                  (int)tile->screen_ypos) - (int)sVar10;
        this->center_scr_col_offset = (short)((sVar6 + this->center_map_row) * this->tile_half_wid - sVar7);
        this->center_scr_row_offset = (short)((this->center_map_row - sVar6) * this->tile_half_hgt - sVar8 - this->tile_half_hgt);
        sVar7 = this->max_col_num / 2 + 2;
        this->start_map_row = this->center_map_row;
        this->start_map_row -= sVar7;
        this->start_map_col = sVar6 - sVar7;
        this->start_scr_col = (short)(sVar9 - sVar7 * this->tile_half_wid * 2);
        sVar6 = this->max_row_num / 2 + 1;
        this->start_map_col += sVar6;
        this->start_map_row -= sVar6;
        this->start_scr_row = (short)(sVar10 - sVar6 * this->tile_half_hgt * 2);
    }
}

// VA: 00535480
// PDB: view.cpp lines 1993-2056
// RGE_View::draw_view(unsigned char param_1, TDrawArea* param_2)

// Attempt log:
// - version 1: tagRECT sr + int l4 locals, separate Lock call from cur_render_area
//   -> 384 bytes vs 387, prologue reads param after sub esp (not before)
// - version 2: separate int locals (a,c,d,e)
//   -> reg allocation changed, similar mismatch
// - version 3: 5th local tmpR to force spill of right value
//   -> no improvement, still 384 bytes
// - version 4: inline member function (inside class body)
//   -> no .text section emitted (inlined)
// - version 5: else-branch with uninitialized locals mirroring original pattern
//   -> compiler warns+zeroes uninitialized reads, breaking the pattern
// - version 6: Ghidra-decompiler-style mapping (sr.top=left, sr.bottom=right, sr.right=top)
//   -> variant lab G0000 (rect_sr+da_yes): 384 bytes, edit diff=159
// - version 7: variant lab with int locals + tmpR + da/no-da variants
//   -> all 384 bytes, closest is G0000 with sub esp,10h prologue but xor eax,eax vs test eax,eax
// - variant lab with --flag-preset vc5-debug-context
//   -> no change in any variant
//
// Earlier gap: the first natural forms were 384 bytes and read param_2 after
// the frame setup. The current best is full size with 46 strict diff bytes.

// Current normal-source pass:
// - one function-scope tagRECT recovered the 0x10 frame and stack homes;
//   strict diff improved from 368 to 299 bytes.
// - compound self-subtraction for the left and top fields reproduced the
//   original subtract-to-zero code and reached 387 bytes / 53 diff bytes.
// - direct p2 guards, declaration placement, and a nested local scope were
//   codegen duplicates. Reversed saved top/bottom assignment was restored.
// - reversing the source top/bottom update order matched the original register
//   pair and reduced the best result to 46 diff bytes.
// - named area alias probe: preserving p2 in a typed local made 389 bytes /
//   318 strict diff bytes and lost call relocation alignment; restored p2 form.
// - direct cur_render_area assignment arms recovered the exact entry block and
//   reduced the strict diff to 20 bytes; direct terrain aggregate passing was
//   a codegen duplicate. A pointer-alias barrier grew the function to 403 bytes
//   and 313 diff bytes, so it was restored.
// - current best: calls, frame, size, CFG, and the first 0x24 bytes match.
//   Remaining drift is one delayed right-rectangle store, terrain call-setup
//   register coloring, and post-lock area-compare register coloring.
// - exact: placing the top-rectangle update before the right and bottom updates
//   reproduces all 387 bytes, including the delayed-register scheduling.


void RGE_View::draw_view(unsigned char p1, TDrawArea* p2)
{
    if (p2 == 0)
        this->cur_render_area = this->render_area;
    else
        this->cur_render_area = p2;

    {
        tagRECT save_render_rect;
        if (this->cur_render_area == this->save_area1) {
        save_render_rect.left = this->render_rect.left;
        save_render_rect.right = this->render_rect.right;
        save_render_rect.top = this->render_rect.top;
        save_render_rect.bottom = this->render_rect.bottom;

        this->render_rect.left -= save_render_rect.left;
        this->start_scr_col -= (short)save_render_rect.left;
        this->start_scr_row -= (short)save_render_rect.top;
        this->render_rect.top -= save_render_rect.top;
        this->render_rect.right -= save_render_rect.left;
        this->render_rect.bottom -= save_render_rect.top;
        this->map_scr_x_offset += save_render_rect.left;
        this->map_scr_y_offset += save_render_rect.top;
    }
    if (this->cur_render_area->Lock("view::draw_view", 1)) {
        if (p1 == 10) {
            this->view_function_terrain(10, save_render_rect);
        } else {
            this->view_function(p1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        this->cur_render_area->Unlock("view::draw_view");
    }
    if (this->cur_render_area == this->save_area1) {
        this->start_scr_col += (short)save_render_rect.left;
        this->start_scr_row += (short)save_render_rect.top;
        this->render_rect.right += save_render_rect.left;
        this->render_rect.bottom += save_render_rect.top;
        this->render_rect.left += save_render_rect.left;
        this->render_rect.top += save_render_rect.top;
        this->map_scr_x_offset -= save_render_rect.left;
        this->map_scr_y_offset -= save_render_rect.top;
        }
    }
    this->cur_render_area = 0;
}

// VA: 00535610 RGE_View::draw_object_outline
// Source: view.cpp lines 2062-2207
// Attempt log:
// 1: broad natural reconstruction from packet: selected object, screen bounds, hit-test, bbox/project, draw outline and reset globals; after compile fixes object was too small (640 vs 665).
// 2: tried /Ob0 flag probe; no size change, flag removed.
// 3: tried /O1 /Oy flag probe; object shrank to 556 and failed configured size, flag removed.
// 4: reviewed original stack locals: eight short bbox/projection locals plus frame byte and coords; current source uses approximate uninitialized locals and wrong project signature.
// 5: reviewed original early screen bounds and hit-test call; current source matches behavior loosely but not exact argument/local shape.
// 6: original calls object vtable +24/+20/+34 and helper 00454690; current source fakes project/draw calls and misses exact helper surface.
// 7: original computes outline color from camera flags and selected result; modeled but scheduling/registers are likely wrong.
// 8: original special draw path depends on game mode/submode and view+174; modeled approximately.
// 9: final state remains too small (640 vs 665); no byte diff available.
// 10: left in scratch: needs real RGE_View/RGE_Static_Object draw/projection type surfaces and exact local short topology before matching.
// 11: canonical structural reset: restored the period RGE_Base_Game/RGE_Player/master-object ABI, RGE_View/TPanel ownership, virtual alignment/check_placement/draw slots, and typed pick/alignment_box calls. The old fake getMap/project/draw wrappers were removed.
// 12: direct absolute global surfaces restored the original fixed-address relocations and 0x3C frame; typed call order/target multiset became exact (12/12), with the remaining gap localized after the alignment call.
// 13: removing the named draw_flag temporary let VC5 retain the master vtable in EBX as in the oracle; widening the placement result to short recovered the oracle's xor-cx/mov-cl/test-cx sequence and reduced the strict gap to 225 bytes.
// 14: donor-shaped output reconstruction uses get_tile screen coordinates plus alignment_box x4/y2/scr_x/y3/y4/y1/x2/tail and the proven y4/tail midpoint formulas. Final source is size/frame exact with 12/12 calls and 54.42% exact-block coverage; remaining drift starts at the screen-coordinate output LEAs and late local-home/register scheduling. Duplicate final x3/scr_y spelling was rolled forward as the same canonical basin.
// 15: tried the natural view.cpp line-order lead by computing outline centers before the sprite gate; size matched, but the first hunk moved earlier and diff worsened from 239 to 275, so rolled back.
// 16: tested alignment output ownership and donor draw-wall center algebra; output-home swaps reached 238 bytes but lost exact islands or changed later scheduling, so rolled back.
// 17: tested a named center-offset temporary; size reached 665 but block shape worsened to 78.14%, so rolled back.
// 18: tested local declaration removal and a variant spelling; compile repair restored the clean typed source. Remaining blocker is VC5 local-home scheduling after alignment.
// 19: widened world_time to unsigned long; this recovered the original SHR and reduced the strict diff from 239 to 238 bytes.
// 20: widened the derived shape selector to unsigned; this recovered the original JAE and reduced the diff to 237 bytes.
// 21: reused frame_color as a short alignment output; frame fell to 0x38 and drift grew to 247 bytes, so rolled back.
// 22: used the exact draw_wall_outline x-center algebra (x3 + (x4-y4)/2 + y4); strict diff improved to 233 bytes.
// 23: reordered center/frame declarations; emitted code was unchanged and the source order was restored.
// 24: changed get_tile output ownership to x1/scr_y; frame stayed 0x3C but drift grew to 249 bytes, so rolled back.
// 25: moved center updates before the sprite guard; size matched but drift grew to 274 bytes and exact blocks fell, so rolled back.
// 26: swapped get_tile output pointers; drift reached 232 bytes, but both emitted output LEAs aliased one home unlike the target, so rolled back.
// 27: used Ghidra-indicated x1/x2 tile outputs; this added a call and grew the frame to 0x40, so rolled back.
// 28: made frame_color branch-local; emitted code was unchanged and the function-scope declaration was restored.
// 29: final validation remains 666/665 bytes, 0x3C/0x3C frame, 12/12 ordered calls, and 233 strict diff bytes. Pinned as current clean.
// Behavior correction: the executable returns directly when
// get_tile_screen_coords fails. It does not clear fog_next_shape on that path.
// Accepted-drift review also remains blocked by the later draw_flag/global
// pointer-read order, which changes invalid-owner fault context.
// Recovered view.cpp TU pass: the shared 0x360 RGE_View surface, /GX module
// flags, and exact 00535480 prefix keep 666/665 bytes and 233 differences.
// The 12 calls remain ordered. The output homes and fault-order blocker remain.
// Continuation sa-5abaa990-r3: PDB lines 2110-2113 prove both center updates
// precede the sprite test. Lines 2116-2119 prove the SDI store and draw-flag
// read precede the placement-color test. Canonical x1..y4 output names and an
// explicit draw-flag local restore that source order and the original early
// master draw-flag read. The grouped result improves to 188 strict differences
// with 12/12 ordered calls, but grows to 673/665 bytes. The remaining blocker
// is a three-way scr_x/scr_y/frame-color stack-home cycle and later argument
// scheduling. The result is not exact; preserve these binary-backed order fixes.
// Exact-finish audit: the shared view.cpp baseline is 673/665 bytes with 188
// strict differences, a 0x3C frame, and 12/12 ordered calls. Removing the
// named draw_flag worsens the result to 274 bytes. Ghidra/donor x1/x2 output
// ownership, pick-info screen fields, typed overlap, declaration-order, and
// swapped-output probes were worse or codegen duplicates. All probes are
// restored. The remaining first hunk is the screen-output LEA/home cycle at
// 005356D6; no exact claim is made.


void RGE_View::draw_object_outline() {
    short placement;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
    short scr_x;
    short scr_y;
    unsigned char frame_color;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    short master_obj_id = rge_base_game->master_obj_id;
    if (master_obj_id == -1)
        return;

    RGE_Player* player = rge_base_game->get_player();
    RGE_Master_Static_Object* master = player->master_objects[(int)master_obj_id];
    if (master == 0)
        return;

    rge_base_game->get_mouse_pos(point);
    if (point.x < this->render_rect.left ||
        point.x > this->render_rect.right ||
        point.y < this->render_rect.top ||
        point.y > this->render_rect.bottom)
        return;

    unsigned short pick_result = (unsigned char)this->pick(
        0x28, 0, point.x - this->render_rect.left,
        point.y - this->render_rect.top,
        &pick_info, 0);
    if (pick_result != 0x33)
        return;

    master->alignment(pick_info.x, pick_info.y, this->world, 0);
    if (this->get_tile_screen_coords(
            (short)pick_info.x, (short)pick_info.y, &scr_x, &scr_y, 1) == 0)
        return;

    master->alignment_box(this->world, pick_info.x, pick_info.y,
                          x1, y1, x2, y2, x3, y3, x4, y4);

    placement = (unsigned char)master->check_placement(
        rge_base_game->get_player(), pick_info.x, pick_info.y,
        0, 1, master->elevation_flag, 0, 1, 1, 1);
    fog_next_shape = 1;
    if (placement == 0) {
        fog_next_shape = 5;
    } else {
        unsigned int shape = (this->world->world_time >> 7) & 7;
        if (shape < 4)
            shape += 0x24;
        else
            shape = 0x2C - shape;
        fog_next_shape = (shape << 4) | 9;
    }

    scr_x += ((int)x1 - (int)x3) / 2 + x3;
    scr_y += ((int)y2 - (int)y4) / 2 + y4;

    if (master->sprite != 0) {
        SDI_Draw_Line = (int)scr_y;
        int draw_flag = master->draw_flag & 1;

        if (placement == 0)
            frame_color = master->draw_color;
        else
            frame_color = 0x97;

        if (rge_base_game->game_mode == 8 &&
            rge_base_game->sub_game_mode == 1 &&
            this->movable_object != 0) {
            RGE_Static_Object* movable = this->movable_object;
            RGE_Color_Table* colors = movable->owner->color_table;
            master->draw(this->render_area, scr_x, scr_y, colors,
                         movable->facet, 0, draw_flag, frame_color);
        } else {
            RGE_Color_Table* colors = rge_base_game->get_player()->color_table;
            master->draw(this->render_area, scr_x, scr_y, colors,
                         0, 0, draw_flag, frame_color);
        }
    }

    fog_next_shape = 0;
}

// 005358B0 RGE_View::draw_paint_brush (view.cpp:2213-2265, 296B)
// Paints a terrain brush cursor at the mouse position, with grid snapping in editor mode.
// Attempt log:
// - baseline: natural mouse/pick records had a 0x1C frame and 176 strict diff bytes.
// - layout: restored the proven 20-byte RGE_Pick_Info. The original reads and
//   writes its x value as a float.
// - ABI: an unsigned-short pick result reproduces the original movzx ax,al and reduced
//   the mismatch to 8 bytes; named game_mode/brush_size fields are codegen-equivalent.
// - behavior/liveness probes: point.y address, local scope/order, and point.x temp reuse
//   did not improve the 8-byte result; the point.y cast and point.x reuse were rolled back.
// - left in scratch: 8 strict bytes, all localized to six FPU stack displacements and
//   two equivalent LEA SIB encodings; calls, frame, CFG, and behavior topology align.
// - Main-agent audit replaced numbered decompiler types with canonical
//   game/view ownership.
// Fresh continuation: named final bounds, declaration/type reorderings, and
// inline/compound arithmetic forms preserved the same 2-byte SIB drift.
// The period long selection/pick ABIs and inherited TPanel bounds ownership
// are now explicit; a focused eight-form final-expression lab also found no
// exact group. Retain the readable canonical source; only commutative LEA
// base/index encodings at 005359BE and 005359C4 remained.
// - Exact codegen: repeat the signed brush-half shift directly in all
//   four final long bounds instead of naming a shared half local; VC5 then
//   emits the original coordinate-base/index SIB bytes at both positive bounds.
//   Removing the now-unused half declaration preserved the exact result.
// - Main-agent audit reduced the redundant casts to `brushSize >> 1`; the
//   natural signed-short promotion remains exact.
// FLAGS: /nologo /c /O2 /Oy


void RGE_View::draw_paint_brush() {
    tagPOINT point;
    RGE_Pick_Info pick_info;

    set_selection_area(-1, -1, -1, -1);

    rge_base_game->get_mouse_pos(point);

    if (point.x < this->render_rect.left ||
        point.x > this->render_rect.right ||
        point.y < this->render_rect.top ||
        point.y > this->render_rect.bottom)
        return;

    unsigned short pickResult = (unsigned char)pick(
        0x28, 0, point.x, point.y, &pick_info, 0);

    if (pickResult != '3')
        return;

    short brushSize;
    if (rge_base_game->game_mode == 0x13) {
        int t1 = (int)(pick_info.x * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        pick_info.x = 1.0f - (float)v1;

        int t2 = (int)(pick_info.y * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        pick_info.y = 1.0f - (float)v2;

        brushSize = 3;
    } else {
        brushSize = rge_base_game->brush_size;
    }

    long cx = (long)pick_info.x;
    long cy = (long)pick_info.y;
    set_selection_area(cx - (brushSize >> 1),
                       cy - (brushSize >> 1),
                       cx + (brushSize >> 1),
                       cy + (brushSize >> 1));
}

// VA: 005359E0 RGE_View::pick
// Source: view.cpp lines 2272-2300
// Size: 151 bytes, __thiscall, ret 18h (6 params)
// Default flags: /nologo /c /O2 /Oy
// No inline asm/hacks.
//
// Previous history summary:
// - Attempts 1-10: named locals eliminated sub esp,10h; local int array restored size but
//   register allocation differed. memset/struct versions changed zeroing/register basin.
// - 2026-05-19 pass: tried register pi, named zero, explicit mask, store-order swaps,
//   register key, uchar signatures, memset, using pi for call args, /Ob0. No exact.
// - 2026-05-20 pass: width matrix for key/param2, object-first local, explicit mask,
//   /O2 without /Oy, /Ox, /Oa, /Og, /O1, void* result. Best positional probe still broad.
// - 2026-05-21 pass: object-first local, manual branch mask, register object/info,
//   uchar signatures, named zero, memset, alternate pointer order, member view_function
//   surface, direct uchar result masking. Best retained source casts view_function return
//   to unsigned char before comparisons: exact size 151B, 62.9139% positional / 58.2781%
//   edit, first mismatch +4.
//
// Current Luna retry (bounded probes):
// - baseline rebuilt after claim: exact size 151B, 65.5629% positional /
//   60.26% edit, first mismatch +4; current source is the retained prior best.
// - probe 1: restored the binary-proven Pick_Info/tagPOINT layout and natural
//   member view_function surface; it regressed to 169B and was rolled back.
// - probe 2: byte formals/direct uchar result kept size 151B but worsened to
//   91.3907% positional; the mode copy was optimized away. Rolled forward only
//   as the next focused condition-lifetime probe.
// - probe 3: consuming the mask condition from the mode local was codegen
//   duplicate; restored baseline.
// - probe 4: typed Pick_Info forced EBX/+22B and was rolled back.
// - probe 5: typed object formal was a codegen duplicate. Probe 6 removed the
//   early info alias; that was also a duplicate of the baseline.
// - probe 6: removing the info alias was a codegen duplicate. Probe 7 direct
//   member-call context corrected the conceptual relocation but regressed to
//   154B/83.1169%; rolled back for the final focused basin probes.
// - probe 7: register-qualified key/object hints were a codegen duplicate.
// - probe 8: direct branchless mask emitted setne/neg, regressed to 153B /
//   86.9281%; rolled back. Best retained state is the pre-claim 151B basin.
//
// Previous Boss retry (10 honest probes):
// 1: Revalidated retained baseline: exact size 151, 62.9139% positional / 58.2781% edit.
// 2: Rewrote object mask as `masked=obj; if (key=='(') masked=0;`: much worse (92% edit),
//    branch/spill family.
// 3: Added pinfo alias and named zero local: no improvement from baseline.
// 4: Modeled RGE_Pick_Info struct with typed fields: worsened badly; compiler emitted larger
//    typed/narrow stores and different frame.
// 5: Declared view_function as returning unsigned char: removed return mask but reg topology
//    regressed to older 88.7417% positional / 62.9139% edit family.
// 6: key as unsigned char formal: first mismatch moved to +7 but positional/edit worsened.
// 7: key and param_2 as unsigned char: same broad mismatch, worse edit.
// 8: Removed `(unsigned char)` cast on view_function return: regressed to older 88.7417%
//    positional family.
// 9: Tried equivalent mask spellings `key == '(' ? 0 : obj`, `-((uchar)key!='(')&obj`, and
//    `(uchar)(key-0x28) != 0 ? obj : 0`; all unchanged or worse.
// 10: Flag probe `/O2` without `/Oy`: no improvement, flag removed.
// 11: Named POINT-style locals instead of locals[4]: .text too short (144B), rejected.
// 2026-05-26 Boss retry: 11 more probes. Tried register result, explicit key byte local,
// obj as int, named zero, removing return mask, unsigned-char view_function/direct uchar
// result, for-loop zeroing, arithmetic mask spellings, unsigned/signed-char key formals,
// register pi, and pointer-increment zeroing. Best remains retained baseline: exact size
// 151B, 62.9139% positional / 58.2781% edit, first mismatch +4. Unsigned-char key got
// first 7 bytes to match but worsened the rest; for-loop zeroing made EAX=key but lost
// the EDI save/zeroing basin.
// GIVEUP: no accepted_drift proposal. Remaining mismatch is broad register/prologue/call setup
// topology (original EAX=key, ESI=obj then info, DL byte-mask, EDX result/zero, EDI=info;
// rebuilt keeps key in EDX/EAX, object/result/info in different registers and uses different
// zeroing/call-arg LEA registers), not localized harmless drift.

// Luna5359E0 continuation (2026-08-02):
// - canonical ABI/member-call and stack-home probes exposed the real
//   RGE_Pick_Info/view_function surface but initially worsened structure.
// - a focused source-shape lab found the natural memset(param_5,0,20),
//   picked-object local passed by address, and low-byte mask basin.
// - final control-flow probe used one if/else-if assignment chain and the
//   live return code. Current best is 151B with 16 positional bytes / 10.5960%
//   strict diff, 10 edit bytes / 6.62%, exact frame/call set, and first mismatch
//   at +1B. Remaining drift is early parameter/local scheduling, not localized
//   harmless codegen. The attempted register hint was a duplicate and is not
//   retained.
//
// Luna5359E0b continuation:
// - baseline check retained the pinned canonical source (151B, 16 bytes).
// - named tagPOINT locals recovered the natural two-point layout and reduced the
//   drift to 4 bytes; using their x-field bases recovered the two call LEAs.
// - assigning the two point coordinates as x=param_3/y=param_4 reproduced the
//   original local-byte layout and produced an exact 151B match.
// - final source is ordinary typed C++: tagPOINT locals, memset for the proven
//   20-byte Pick_Info block, direct member call, and natural result dispatch.



unsigned char RGE_View::pick(unsigned char param_1, unsigned char param_2,
                              long x, long y,
                              RGE_Pick_Info* param_5,
                              RGE_Static_Object* param_6) {
    RGE_Static_Object* picked = ((unsigned char)param_1 != '(') ? param_6 : 0;
    tagPOINT start_mouse_pos;
    tagPOINT mouse_pos;

    mouse_pos.x = x;
    mouse_pos.y = y;
    start_mouse_pos.x = x;
    start_mouse_pos.y = y;

    memset(param_5, 0, 20);

    long ret = this->view_function(
        param_1, param_2, &mouse_pos,
        &start_mouse_pos, (void**)&picked,
        (float*)((char*)param_5 + 0),
        (float*)((char*)param_5 + 4),
        (short*)((char*)param_5 + 8),
        (short*)((char*)param_5 + 0xA));
    unsigned char code = (unsigned char)ret;
    if (code == 0x34) {
        param_5->object = picked;
    } else if (code == 0x33) {
        param_5->tile = (RGE_Tile*)picked;
    }
    return code;
}

// 00535A80 RGE_View::pick_multi (view.cpp:2306-2370)
// Attempt log:
// 1: Natural decompiler-shaped implementation: 86.46% diff; RGE_Static_Object fields were 4 bytes early and parameter/register allocation differed.
// 2: Add object vptr pad fixed object_state/master offsets; diff still broad, first mismatch register allocation for params/count.
// 3: Register loop index/named coordinate locals made no codegen change.
// 4: Mutating x2/y2 into deltas made no codegen change.
// 5: Pointer-before-index swapped init order slightly but still wrong registers.
// 6: Register count did not change allocation.
// 7: Negated dy spelling no change.
// 8: Hoisting loop index before pick call improved to 40% positional / 21.6% edit and restored xor ESI/count EBP.
// 9: Register y1 local did not change EBX (still y2).
// 10: Volatile y2 worsened to 87.68% and first mismatch offset 1; rolled back.
// 11: Used the incoming y1 parameter directly in both rectangle calls, matching the packet's direct y1 home reloads; VC5 emitted the same 495-byte code.
// 12: Spelled the first direct selection block as an early failure break followed by picked_any=1; testing the call before the assignment was a natural source-order lead.
// 13: Replaced raw int pick-record access with a typed RGE_Pick_Obj_Info pointer and named confidence field; VC5 was a codegen duplicate.
// 14: Declared the y delta before the x delta to test y1/EBX liveness coloring; diff worsened by 5 bytes, so restored x delta first.
// 15: Reused y1 as the second-pass count and x2 as the selected-object home; this matched the observed parameter writes but was a codegen duplicate, so restored named locals.
// 16: Carried y2 through a named local across both passes; VC5 was a codegen duplicate.
// 17: Removed register qualifiers from count and loop index; both were codegen duplicates, and the natural unqualified locals remain.
// 18: Used a positive second-pass do-while predicate; rebuilt size grew to 501 bytes and strict diff to 276, so restored count != 0.
// 19: A separate remaining count, initialized after the second cursor setup,
// recovered the original second-pass stack-home and reduced the diff to 40.
// 20: Reusing y1 for the second result, and moving remaining before the score,
// were duplicates or regressions. The separate remaining form remains best.
// 21: Split delta declarations were a duplicate. dx >= dy reduced the diff to
// 39. An explicit sub-50 if/else grew the body to 497 bytes and was restored.
// 22: Restored the canonical TPanel base surface. VC5 emitted a duplicate.
// 23: A 4x4 call/coordinate variant lab and a 32-sample ambient-context lab
// emitted one 495-byte group. No alias, delta, or ambient form moved bytes.
// Bounded session probes: exact-source ABI correction fixed the two helper
// relocations but did not move bytes; parameter-home reuse, declaration-order,
// natural delta, header-context, and focused score-lifetime variants were
// codegen duplicates or regressed size. The retained source below is the
// simplest typed reconstruction: the PDB-proven picked_obj local is function
// scoped, while the score/count remain ordinary locals.
// Current pass: the retained typed source builds to 495 bytes with 9 aligned
// calls and no frame/EH. The best strict diff is 39 bytes (7.8788%), first
// mismatch +0x0e.
// Direct y1/x2 parameter-home reuse, a split 56-slot TPanel surface, coordinate
// aliases, and register-qualified locals were codegen duplicates. A bool flag,
// declaration-site pointer initialization, and explicit radius arms regressed.
// Left in scratch: rebuilt size/calls/frame match, with exact first-pass and
// later loop islands. The first mismatch remains the initial y-coordinate load:
// original keeps y1 in EBX, while rebuilt keeps y2. The radius block also uses
// a different coordinate register map. No policy-valid exact source was found.
// Current claim probes:
// 24: Replaced unnamed virtual slots and flat overlays with the period
//     RGE_View/TPanel, player, object, master, and world surfaces. Renamed the
//     virtual calls to pick_through_fog and pick_weight. The 495-byte,
//     39-byte-diff output was unchanged.
// 25: Made the Picked_Objects cursor function scoped. Codegen was unchanged.
// 26: Initialized that cursor at function entry to follow its earlier PDB
//     declaration. This moved the load before the helper call and regressed
//     to a 382-byte diff; it was restored.
// 27: Reordered the first-pass declarations. Codegen was unchanged.
// 28: Reused dead rectangle parameters for the second-pass count and selected
//     object. This reached 51 bytes and was restored.
// 29: Reversed the natural selected-object and score zero stores. This reached
//     the current 37-byte frontier and remains in the source.
// 30: Reused y1 only for the second-pass count. This reached 52 bytes and was
//     restored.
// 31: Added one natural y1 copy for the helper and delta. Codegen was a
//     duplicate of the 37-byte frontier.
// 32: Joined dx/dy declarations with their assignments. Codegen was unchanged.
// 33: Removed the repeated radius assignment. This made 493 bytes and 312
//     differing bytes, so it was restored.
// 34: Made the inner radius choice an explicit if/else. This made 497 bytes
//     and 309 differing bytes, so it was restored.
// 35: Moved the remaining-count declaration to function scope. Codegen was a
//     duplicate of the 37-byte frontier, so it was restored.
// 36: Added the full reviewed RGE_View size surface. Codegen was unchanged,
//     so the local class surface was restored.
// 37: Reused y1 as the second-pass result. This made 495 bytes and 211
//     differing bytes, so it was restored.
// 38: Mutated x2 and y2 into the coordinate deltas. This made 495 bytes and
//     56 differing bytes, so it was restored.
// 39: Staged the coordinate delta assignments. The live translation-unit
//     config changed during the check, so the source was restored before a
//     result was recorded.
// 40: Made the coordinate delta and radius locals long. Codegen was a
//     duplicate of the 37-byte frontier; the widths match the PDB/decompiler
//     long coordinate evidence.
// BINARY NOTE: The original stores the second-pass count in the y1 home and
// the selected object in the x2 home. The natural local form stores the count
// in the y2 home while preserving the selected-object home.
// BINARY NOTE: Fresh checks keep exact calls, x87 conversion order, object and
// player rereads, the 495-byte boundary, and the RGE_View owner symbol.
// BLOCKED: The target is not an owner in config/translation_units.json. A
// shared view.cpp wrapper would need a config owner and shared-header changes.
// Both changes are outside this task. The exact view anchors remain untouched.
// ACCEPTED DRIFT: The changed regions use different registers for x1, y1, x2,
// y2, dx, dy, and the second-pass counter. Both builds push identical helper
// arguments, compute the same wrapped coordinate differences and radius, and
// visit objects in the same order. Reordered reads are parameter or private
// stack reads. Calls, used flags, memory effects, returns, and fault behavior
// match.


unsigned char RGE_View::pick_multi(unsigned char p1, long x1, long y1, long x2, long y2)
{
    RGE_Pick_Obj_Info* pp;
    int i = 0;
    int picked_any = 0;
    int count;
    RGE_Static_Object* picked_obj;
    count = this->pick_multi_objects(x1, y1, x2, y2, 10, 20, this->player->id, p1, 1);
    if (count > 0) {
        pp = Picked_Objects;
        do {
            int idx = pp->object_id;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < 7) {
                    if (!this->player->select_one_object(obj,0)) break;
                    picked_any = 1;
                }
            }
            i++;
            ++pp;
        } while (i < count);
    }
    if (picked_any) return 1;

    long dx = x2 - x1;
    long dy = y2 - y1;
    long r = dx;
    if (dx >= dy) r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy) r = dx;
    } else r = 50;

    count = this->pick_objects(x1 + dx/2, y1 + dy/2, 10, 20, r, 4, 1);
    if (count) {
        picked_obj = 0;
        int bestScore = 0;
        int remaining;
        if (count > 0) {
            pp = Picked_Objects;
            remaining = count;
            do {
                int idx = pp->object_id;
                if (idx >= 0) {
                    RGE_Static_Object* obj = this->world->objectsValue[idx];
                    if (obj && obj->object_state < 7 && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->pick_through_fog(obj)) {
                            int vy = (int)obj->world_y;
                            int vx = (int)obj->world_x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f) goto next;
                        }
                        int score = this->pick_weight(obj, pp->confidence);
                        if (obj->owner == this->player) score += 5;
                        if (score > bestScore) { picked_obj = obj; bestScore = score; }
                    }
                }
next:
                ++pp;
                remaining--;
            } while (remaining != 0);
        }
        if (picked_obj && this->player->select_one_object(picked_obj,0)) return 1;
    }
    return 0;
}


unsigned char RGE_View::pick(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2, void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row) {
    return (unsigned char)view_function(a1, a2, p1, p2, out_obj, out_x, out_y, out_col, out_row);
}


int RGE_View::pick_through_fog(RGE_Static_Object* object) { return 0; }

// 00535CC0 pick_weight (view.cpp:2396-2440)
// PDB source: view.cpp (RGE_View::pick_weight)
//
// virtual int __thiscall RGE_View::pick_weight(RGE_Static_Object*, int)
// Returns: weight value (1-5, 0 = unselectable)
// ret 8 cleanup (2 params, thiscall)
//
// === Attempt log ===
// Baseline isolated source was structurally broad (198 differing bytes, 198-byte
// rebuilt body).  Reconstructing a separate select_level local, initialized before
// the touched-object test, recovered the original 211-byte size and the complete
// first 46-byte load/test block (probe 3).
// Probes 4-6: bool/initialized-result/local-declaration-order variants either
// regressed or were codegen duplicates.  A polymorphic TPanel/RGE_View surface and
// int/long result-width variants were also duplicates (probes 8-9).
// Probe 7: a named zero result was a duplicate, but is retained because the binary
// pre-zeroes EAX before the level dispatch and returns that zero on two arms.
// Probe 10: reversing the final case-2 equality to an explicit negative guard
// improved the isolated result to 207 bytes, 150 differing bytes, 88.57% shape,
// and 77.94% exact-block coverage.  The remaining first hunk is register coloring:
// rebuilt bVar1 is ECX while original is EDX; rebuilt dispatch value is EAX while
// original is ECX; original also hoists XOR EAX,EAX and keeps a branching case-2
// tail.  No calls, frame, or ABI/layout uncertainty remains.
// Fresh pass probe 1 rolled back: the natural nested level/predicate spelling
// restored the 211-byte size and improved positional diff to 139 bytes, but it
// changed the dispatch CFG to cmp/jne (72.46% shape, 57.35% blocks), farther
// from the original sub/dec/je dispatch than the switch basin.
// Fresh pass probe 2: the full proven TPanel/RGE_View and static-object surfaces
// were a codegen duplicate of the minimal shells; retained because ownership is
// more canonical, with no metric change.
// Fresh pass probe 3: next test mirrors the decompiler's proven source lifetime:
// save the object pointer, write the level through param_1 before the touched
// predicate, then use the saved pointer for the id comparison.
// Probe 3 rolled back: the explicit saved pointer forced an EBX save and a
// 211-byte/194-diff basin, so the compiler's existing parameter-home reuse is
// the better source reconstruction.
// Fresh pass probe 4: add the period RGE_View virtual surface (TPanel slots
// 0-47, view slots 48-55, pick_through_fog 56, pick_weight 57) without adding
// any function bodies, testing TU/vtable context rather than body control flow.
// Fresh pass probe 5: retain the saved object only for the proven id read, but
// express the observed byte write to the incoming parameter home directly.
// Probe 5 was a codegen duplicate of the clean 207-byte basin; the explicit
// byte-home form did not alter VC5's register family.
// Fresh pass probe 6: test a narrow register-qualified result local because the
// executable carries the predicate as a full-width EDX value across dispatch.
// Probe 6 was also a codegen duplicate; register qualification did not move the
// predicate from ECX or the level key from EAX.
// Fresh pass probe 7: move the proven zero result initialization to function
// entry, testing declaration/lifetime placement for the original pre-dispatch
// XOR EAX,EAX without retaining the duplicate raw alias experiment.
// Probe 7 was a codegen duplicate. The 108-variant fresh lab over level-home,
// zero-lifetime, and late predicate spellings produced eight nonexact groups;
// no exact or invariant-eligible variant was found. Final source below keeps
// the full proven layout/vtable context and natural nested predicates; remaining
// drift is the isolated VC5 register/dispatch basin (ECX/EAX vs EDX/ECX) plus
// the pre-dispatch zero/branch-tail topology.
// Main-agent normalization replaced the raw static-object vptr field with its
// canonical virtual destructor surface; emitted code is unchanged.
// Session normalization uses the canonical RGE_View, RGE_Static_Object, and
// RGE_Master_Static_Object names and a real unsigned-char level local; no
// parameter-home pointer alias remains.  The best natural source is retained
// below; remaining drift is the VC5 register/dispatch basin described above.
// Main-agent audit restored polymorphic master/panel ownership; the natural
// select-level switch remains authoritative.
// Matching-worker probe: mirrored the exact TRIBE_Main_View::pick_weight donor's
// int touched/result declaration and result-local fallthrough shape.  Cases 2
// and 3 assign the initialized result and return it after the switch, preserving
// the original shared zero tail.  This is a natural source form and matches all
// 211 bytes exactly.

// Fresh pass probe 2 uses the proven concrete RGE_View/TPanel and
// RGE_Static_Object data surfaces rather than the prior minimal helper shells.

int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    unsigned char select_level = param_1->master_obj->select_level;
    int touched;

    // Check touched state.
    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;

    // Switch on select_level (values 2,3,4 handled, default=1)
    switch ((int)(unsigned)select_level) {
        case 4:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2) return 4;
            if (param_2 == 3) return 3;
            return 2;
        case 3:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            break;
        case 2:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3)
                result = 2;
            break;
        default:
            return 1;
    }

    return result;
}

// 00535DA0 RGE_View::get_tile_screen_coords
// view.cpp:2447-2480, 269 bytes, __thiscall, ret 14h
// Attempt log:
//   baseline: canonical map/tile ownership and natural validation body; the
//     early-failure gotos caused short branches to a local failure block.
//   control-flow: nested positive guards below model the source-level success
//     region so VC5 can place the shared return-0 block after it, as in the
//     original long branches.
//   main-agent audit: restored canonical RGE_Map/TPanel polymorphic ownership;
//     emitted code remains exact.


int RGE_View::get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust) {
    if (out_x != 0) *out_x = 0;
    if (out_y != 0) *out_y = 0;

    if (col >= 0) {
        RGE_Map* pMap = this->map;
        if (col < pMap->map_width) {
            if (row >= 0) {
                if (row < pMap->map_height) {
                    RGE_Tile* pTile = pMap->map_row_offset[row] + col;
                    if (pTile != 0) {
                        int screen_x = pTile->screen_xpos - this->map_scr_x_offset;
                        int screen_y = pTile->screen_ypos;
                        screen_y += pMap->tilesizes[pTile->tile_type].y_delta;
                        screen_y -= this->map_scr_y_offset;

                        if (adjust != 0) {
                            if (pTile->tile_type != 0) screen_y += this->elev_hgt / 2;
                            if (pTile->tile_type == 6) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 5) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 3) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 0x0B) screen_y -= this->elev_hgt;
                        }

                        *out_x = (short)screen_x;
                        *out_y = (short)screen_y;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}


void RGE_View::get_center_screen_pos(short* row, short* col) {
    *row = center_scr_row;
    *col = center_scr_col;
}


void RGE_View::get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = start_map_col;
    }
    if (map_row != 0) {
        *map_row = start_map_row;
    }
    if (scr_col != 0) {
        *scr_col = start_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = start_scr_row;
    }
}


void RGE_View::get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = center_map_col;
    }
    if (map_row != 0) {
        *map_row = center_map_row;
    }
    if (scr_col != 0) {
        *scr_col = center_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = center_scr_row;
    }
}


void RGE_View::get_tile_sizes(short* width, short* height, short* half_width, short* half_height) {
    if (width != 0) {
        *width = tile_wid;
    }
    if (height != 0) {
        *height = tile_hgt;
    }
    if (half_width != 0) {
        *half_width = tile_half_wid;
    }
    if (half_height != 0) {
        *half_height = tile_half_hgt;
    }
}


void RGE_View::get_max_size(short* cols, short* rows) {
    *cols = max_col_num;
    *rows = max_row_num;
}

// 00535FE0 RGE_View::view_function (view.cpp:2562-3006)
// __thiscall, 2354 bytes (corpus range 00535FE0-00536911).
//
// NOTE (corpus split): the original function physically continues past the
// inventory boundary (00536911) with the tile_screen_row switch cases
// (00536912/00536932/00536957...) and the shared loop tail (00536992+), plus
// jump tables at 00536B04/00536B1C/00536B2C.  The corpus tracks those blocks
// separately as parent-owned fragments (00536912, 00536957) and the naked
// fragment 00536932 (caseD_3).  A faithful single-function reconstruction is
// therefore always flagged "code-overflow" by the checker (the original's own
// `ja 00536992`/`jne 00536A9E`/`je 005369DC` targets and the switch jump-table
// entries lie beyond the 2354-byte compared range).  This file keeps the full
// natural source so the parent (and its fragments) stay readable; the exact
// check cannot succeed until the corpus boundary question is resolved.
//
// Attempt log:
//   p1 baseline: full natural reconstruction from Ghidra packet + exact donors
//     (get_selection_area, get_visible, shadow_draw, normal_draw, get_list_info)
//     + type dumps (RGE_View/RGE_Map/RGE_Tile/RGE_Player/TDrawArea). 45.3% shape.
//   p2 types: fixed RGE_Tile_Set sizeof 0x198 (was 0xBA -> shifted all map offsets)
//     and RGE_View gap after y_max (started at 0x98, overlapped; now 0x9C). 53.6%.
//   p3 liveness: removed the `tile_ptr != 0` guard in the terrain-update block; the
//     original derefs tile_ptr unconditionally (mov bl,[ebp+5] at 0053660C). This
//     flipped the frame to 0x78 and raised shape to 62.9%.
//   p4 layout: reversed local declaration order - no emitted-code change (negative).
//   p5 control-flow: swapped function_parm/function_mode store order - slightly worse,
//     reverted (negative).
//   p6 flags: `register` on a1/a2 - no emitted-code change (negative).
//   p7 control-flow: restructured in-bounds check from if/else-if/else to
//     if/else-with-nested-continue so VC5 keeps the out-of-bounds mode check inline
//     (matches original B029/B030 blocks); 63.9%.
//   p8 context: changed the mode-chain conditions (0x28/0x3C/.../0x2C and the 0x0E
//     selection check) to read `this->function_mode` instead of the `a1` parameter.
//     The original reloads the member after the get_list_info call (mov al,[esi+140h]
//     at 00536062), so the source used member reads, not the param. This made the
//     ENTIRE prologue byte-identical and raised shape to 65.0% (first mismatch now
//     only the fog_flag local slot +0x90).
//   p9 layout: restored natural declaration order - no change (negative).
//   p10 control-flow: assigned direction before cur_col_num to match the
//     original PDB statement order at view.cpp:2634/2637; strict diff improved
//     2529 -> 2526 bytes, but edit/resync diff worsened. Rolled back to the
//     clean natural source; the structural stage and corpus-boundary block
//     remain unresolved.
//   continuation claim #1 layout: short list_size matched the observed
//     16-bit max-row arithmetic but enlarged the code; restored int.
//   claim #2 control-flow: direction-before-cur order was a codegen duplicate.
//   claim #3 layout: max_row_num2 = picked_type improved the short-list basin
//     to 2451 bytes; the alias is retained.
//   claim #4 layout: int list_size with that alias reached 2433 bytes.
//   claim #5 layout: reversing the two max-col assignments regressed to 2526;
//     restored the alias direction.
//   claim #6 abi: modeled the binary/decompiler bounds predicate as bool
//     in_bounds; this improved strict diff to 2424 bytes and is retained.
//   claim #7 abi: bool draw_flag was a 2448-byte regression; restored int.
//   claim #8 layout: short list_size with the bool/alias surface was 2432 bytes;
//     restored int.
//   claim #9 layout: cast the short max-row sum before the shift, matching the
//     observed 16-bit add/shift and reaching the current best, 2423 bytes.
//   Status: structurally faithful (frame/saved-regs/calls/prologue exact, 65% shape,
//     ~42% exact-block coverage); remaining drift is VC5 local-slot permutation
//     (picked_type/fog_flag/tile/tile_ptr/start_map_row2/direction/tile_screen_row/
//     last_picked_obj region) and ebx/ebp register roles. Exact check is BLOCKED by
//     the corpus split (see note above); further probing would be blind allocation tuning.
//   latest pass (sa-c5cf6e0b): twelve fresh hypotheses were compiled and checked.
//     Narrow list_size, signed fog_flag, narrow/full picked_type, narrow direction,
//     narrow col_num, short tile_screen_row, full max_row_num2, paired narrow types,
//     reordered initializers, a separate visibility local, and register hints for
//     the persistent short states all regressed or produced duplicate codegen.
//     The clean source remains best at 2423 strict-diff bytes, 65.02% shape,
//     41.72% exact-block coverage, frame 0x78, and all 15 calls aligned.
//     No hypothesis changed the corpus overflow. Restore the clean source before
//     pause; the remaining lead is the proven local-home/register basin, not ABI.
//   latest pass (sa-ac59df96):
//     H1 moved fog_flag beside visible; codegen duplicate.
//     H2 moved the mode-0B tile test inside the in-bounds arm; strict diff 2434,
//     shape 65.85%, then restored because natural strict bytes worsened.
//     H3 swapped tile and tile_ptr declarations; codegen duplicate.
//     H4 used one explicit visible_zero label; same 2434-byte result as H2,
//     restored because it was not the clean natural basin.
//     H5 widened last_picked_obj to int; strict diff 2436, shape 63.90%, restored.
//     H6 restored cur_col_num-before-direction assignment order; codegen duplicate.
//     H7 used a short list_size with a separate shift; strict diff 2432, restored.
//     H8 reordered inner coordinate declarations; codegen duplicate.
//     H9 marked view_function protected. Bytes stayed unchanged and the owner
//     symbol changed from QAE to the target's protected IAE decoration; retained.
//     H10 used the target's negative visibility guard; codegen duplicate.
//     Final clean: 2423 strict diff, 65.02% shape, 41.72% exact blocks, 15 calls,
//     frame 0x78. The target's 2354-byte corpus boundary still truncates the
//     natural function tail and prevents exact boundary validation.




#define RGE_VIEW_OBJECTS(tile) (&(tile)->objects)

long RGE_View::view_function(register unsigned char a1, register unsigned char a2, tagPOINT* p1, tagPOINT* p2,
                             void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row)
{
    unsigned char visible;
    short map_row;
    short map_col;
    short start_scr_col2;
    short start_scr_row2;
    short cur_col_num;
    short picked_type;
    unsigned char fog_flag;
    unsigned char tile;
    RGE_Tile* tile_ptr;
    short start_map_row2;
    short direction;
    unsigned char tile_screen_row;
    short last_picked_obj;
    RGE_Static_Object* terrain_type;
    unsigned char tile_type;
    unsigned char col_num;
    short row_num;
    long calc_sel_col1;
    long calc_sel_col2;
    long calc_sel_row1;
    long calc_sel_row2;
    RGE_Static_Object* orig_picked_obj;
    RGE_Static_Object* find_col;
    short find_row;
    short max_col_num2;
    short max_row_num2;
    int list_size;

    this->function_mode = a1;
    this->function_parm = a2;

    if (a1 == 0x0A && this->calc_draw_count != 0) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].drawn = 0;
        }
    }

    RGE_Tile_List_Node* list_node;
    int num_active;
    this->player->tile_list.get_list_info(list_node, num_active);

    fog_flag = 0x32;
    if (this->function_mode == 0x28 || this->function_mode == 0x3C || this->function_mode == 0x29 ||
        this->function_mode == 0x2A || this->function_mode == 0x2B || this->function_mode == 0x2C) {
        if (this->function_mode == 0x3C) {
            find_row = (short)(long)(*out_x);
            max_col_num2 = (short)(long)(*out_y);
        }
        *out_x = 0.0f;
        *out_y = 0.0f;
        *out_col = 0;
        *out_row = 0;
        if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B ||
            this->function_mode == 0x2C) {
            find_col = (RGE_Static_Object*)*out_obj;
        }
        *out_obj = 0;
        terrain_type = 0;
    }

    if (this->function_mode == 0x0E) {
        if (this->get_selection_area(calc_sel_col2, calc_sel_row2, calc_sel_row1, (long&)orig_picked_obj, 1) == 0) {
            return 0;
        }
    }

    start_scr_row2 = this->start_scr_col;
    start_map_row2 = this->start_map_col;
    direction = this->start_map_row;
    cur_col_num = this->start_scr_row;
    list_size = (short)(this->max_row_num + 6) << 1;
    picked_type = this->max_col_num + 4;
    max_row_num2 = picked_type;
    tile_screen_row = 4;
    calc_sel_col1 = 0;

    if ((short)list_size > 0) {
        do {
            map_row = start_scr_row2;
            start_scr_col2 = start_map_row2;
            map_col = direction;
            row_num = 0;
            if (picked_type > 0) {
                do {
                    bool in_bounds;
                    int draw_flag;
                    if (start_scr_col2 >= 0 && start_scr_col2 < this->map->map_width &&
                        map_col >= 0 && map_col < this->map->map_height) {
                        in_bounds = 1;
                    } else {
                        in_bounds = 0;
                        if (this->function_mode != 0x28 && this->function_mode != 0x2A) {
                            goto col_continue;
                        }
                    }
                    if (in_bounds) {
                        RGE_Visible_Map* vis = this->player->visible;
                        if (vis != 0 && this->map->map_visible_flag == 0) {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F) {
                                visible = 0x0F;
                            }
                        } else {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (visible == 0) {
                                visible = 0x80;
                            }
                        }
                    } else {
                        visible = 0;
                    }
                    if (this->function_mode == 0x0B) {
                        RGE_Tile* t = this->map->map_row_offset[map_col] + start_scr_col2;
                        if (t->draw_as == t->last_drawn_as) {
                            visible = 0;
                        }
                    }
                    if (visible != 0x0F && visible != 0x80) {
                        visible = 0;
                    }
                    if (visible == 0 && this->function_mode != 0x0E && this->function_mode != 0x28 &&
                        this->function_mode != 0x3C && this->function_mode != 0x2A) {
                        goto col_continue;
                    }
                    if (in_bounds) {
                        tile_ptr = this->map->map_row_offset[map_col] + start_scr_col2;
                        col_num = tile_ptr->tile_type;
                        last_picked_obj = (short)(cur_col_num -
                            tile_ptr->height * this->elev_hgt);
                    } else {
                        tile_ptr = 0;
                        col_num = 0;
                        last_picked_obj = cur_col_num;
                    }
                    switch (col_num) {
                    case 2:
                    case 6:
                    case 8:
                    case 10:
                    case 14:
                    case 15:
                    case 16:
                        last_picked_obj -= this->elev_hgt;
                        break;
                    }
                    draw_flag = map_row > this->render_rect.right || last_picked_obj > this->render_rect.bottom ||
                        map_row + this->map->tilesizes[col_num].width <= this->render_rect.left ||
                        last_picked_obj + this->map->tilesizes[col_num].height <= this->render_rect.top ||
                        (this->function_mode == 0x0E &&
                         (start_scr_col2 < calc_sel_col2 || start_scr_col2 > calc_sel_row1 ||
                          map_col < calc_sel_row2 || map_col > (int)orig_picked_obj));
                    if (this->function_mode == 0x0A || this->function_mode == 0x1E || this->function_mode == 0x1F ||
                        this->function_mode == 0x20 || this->function_mode == 0x15 || this->function_mode == 0x0B ||
                        this->function_mode == 0x0E) {
                        if (draw_flag == 0 &&
                            (this->function_mode == 0x0A || this->function_mode == 0x0B || this->function_mode == 0x0E)) {
                            tile_type = tile_ptr->terrain_type;
                            if (this->map->terrain_types[tile_type].terrain_to_draw != -1) {
                                tile_type = (unsigned char)this->map->terrain_types[tile_type].terrain_to_draw;
                            }
                            if (this->function_mode == 0x0A && this->calc_draw_count != 0 &&
                                (short)tile_type < this->map->num_terrain) {
                                this->map->terrain_types[tile_type].drawn++;
                            }
                            if (this->function_mode == 0x0B) {
                                tile_ptr->last_drawn_as = tile_ptr->draw_as;
                            }
                        }
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F ||
                                this->function_mode == 0x20 || this->function_mode == 0x15) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                if (this->function_mode == 0x1E) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x1F) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x20) {
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0, tile);
                                } else {
                                    if (this->function_mode != 0x15) {
                                        goto col_continue;
                                    }
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    RGE_VIEW_OBJECTS(tile_ptr)->normal_draw(this->cur_render_area, map_row, cur_col_num, tile);
                                }
                                fog_next_shape = 0;
                            }
                        }
                    } else {
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x29 || this->function_mode == 0x2A ||
                                this->function_mode == 0x2B || this->function_mode == 0x2C) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                RGE_Static_Object* obj = this->hit_object(tile_ptr, map_row, cur_col_num,
                                                                           start_scr_col2, map_col,
                                                                           (tagPOINT*)out_x, (tagPOINT*)out_obj,
                                                                           out_col, out_row, find_col, tile);
                                if (obj != 0) {
                                    if (this->function_mode == 0x2C) {
                                        fog_flag = 0x34;
                                    } else {
                                        if (find_col != 0 && obj == find_col && fog_flag == 0x34) {
                                            *out_obj = terrain_type;
                                            return 0x34;
                                        }
                                        if (terrain_type == 0 ||
                                            terrain_type->master_obj->select_level <= obj->master_obj->select_level ||
                                            (terrain_type == find_col && obj != find_col)) {
                                            *out_x = obj->world_x;
                                            *out_y = obj->world_y;
                                            fog_flag = 0x34;
                                            terrain_type = obj;
                                        }
                                    }
                                }
                            }
                        }
                        if (this->function_mode == 0x28 || (this->function_mode == 0x2A && fog_flag == 0x32)) {
                            if (this->hit_tile(tile_ptr, map_row, last_picked_obj, start_scr_col2, map_col, p1) != 0) {
                                if (tile_ptr == 0) {
                                    *out_x = (float)start_scr_col2;
                                    *out_y = (float)map_col;
                                } else {
                                    this->map->tile_map_coords((short)p1->x - map_row,
                                                               (short)p1->y - last_picked_obj,
                                                               tile_ptr, out_x, out_y);
                                    *out_x = (float)start_scr_col2 + *out_x;
                                    *out_y = (float)map_col + *out_y;
                                }
                                *out_col = map_row;
                                fog_flag = 0x33;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                            }
                        } else if (this->function_mode == 0x3C) {
                            if (start_scr_col2 == find_row && map_col == max_col_num2) {
                                *out_x = (float)start_scr_col2;
                                *out_y = (float)map_col;
                                *out_col = map_row;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                                return 0x33;
                            }
                        }
                    }
                col_continue:
                    map_row += this->tile_wid;
                    start_scr_col2++;
                    map_col++;
                    row_num++;
                } while (row_num < picked_type);
            }
            if (tile_screen_row == 1 && picked_type == max_row_num2) {
                tile_screen_row = 2;
            }
            switch (tile_screen_row) {
            case 1:
                picked_type++;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 2:
                picked_type--;
                start_scr_row2 += this->tile_half_wid;
                direction++;
                break;
            case 3:
                tile_screen_row = 4;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 4:
                start_scr_row2 += this->tile_half_wid;
                direction++;
                tile_screen_row = 3;
                break;
            }
            cur_col_num += this->tile_half_hgt;
            calc_sel_col1++;
        } while ((short)calc_sel_col1 < (short)list_size);
    }

    if (this->function_mode == 0x0A) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].frame_changed = 0;
        }
    }
    if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B) {
        if (fog_flag == 0x34) {
            *out_obj = terrain_type;
        }
    }
    return fog_flag;
}

#undef RGE_VIEW_OBJECTS

// 00536B40 RGE_View::view_function_terrain (view.cpp:3026-4250)
// Target is a large terrain-render pass. This scratch file intentionally starts
// with a tiny compileable owner plus an asm-guided roadmap so future work has a
// stable target to iterate instead of rediscovering the frame/offset surface.
//
// Original prologue/frame:
//   sub esp,110h; push ebx/ebp/esi/edi; this in ebp; return long.
//   arg1 unsigned char at [esp+124h] after saves, written to this+0x140.
//   arg2 RECT is present in the PDB signature but the early 0x110-frame region
//   does not consume it before the tile loops; verify later line bands before
//   assuming it is unused.
//
// Stable RGE_View offsets observed in the first source-line bands:
//   +0x0F8 calc_draw_count
//   +0x100 player
//   +0x104 map
//   +0x108 tile_wid
//   +0x116 max_col_num (short)
//   +0x118 max_row_num (short)
//   +0x12A start_map_col (short)
//   +0x12C start_map_row (short)
//   +0x130 map_scr_x_offset
//   +0x134 map_scr_y_offset
//   +0x140 function_mode
//   +0x142 render_terrain_mode
//   +0x2A0 Limited_Render_Rect
//   +0x2A4 Use_Rect2
//   +0x2B8/+0x2BC/+0x2C0/+0x2C4 Render_Rect2-ish bounds
//   +0x2D8 Queued_Blits
//   +0x338 futur_objs (DClipInfo_List*)
//   +0x358 DispSel_List_Size
//
// Stable RGE_Map offsets observed early:
//   +0x08 map_width, +0x0C map_height
//   +0x1A tilesizes[0].height as word with 6-byte stride/terrain tile-type index
//   +0x8D8C map_row_offset (RGE_Tile**)
//   +0x8D90 num_terrain (short)
//   +0x8DB8 map_visible_flag
//   +0x8DB9 fog_flag
//   terrain_types[0].tiles + drawn byte is addressed as map+0xD1 + type*0x198.
//
// Stable RGE_Tile offsets from the hot tile scan:
//   +0x00 screen_xpos (short), +0x02 screen_ypos (short), +0x04 tile_type
//   +0x05 terrain/type flags (low 5 bits used for terrain_types[].drawn)
//   +0x07 last_drawn_as, +0x08 last_drawn_shape, +0x0B last_drawn_shape2
//   Tile element stride is 24 bytes: row[i] is formed with lea edx,[col+col*2]
//   then [row+edx*8].
//
// External/global facts observed early:
//   update_display_selected_objects: 00533E10 thiscall, no args.
//   ProcessQueuedBlit: 00534A00 thiscall, one int arg.
//   get_tile_mask_num: 00538590 thiscall, args (col,row,map_width,map_height,mask).
//   DClipInfo_List::ReclaimAllNodes: 0053B510 thiscall.
//   MouseSystem global 0062E660; TMousePointer::Poll 0045C010.
//   SDI_List global 0086BBF8 receives this->futur_objs.
//   unified_map_offsets global 00886808 is indexed [row][col] as dword masks.
//
// Full direct-call inventory from original asm, grouped by likely subsystem:
//   terrain/view helpers: 00533E10 update_display_selected_objects,
//     00534A00 ProcessQueuedBlit, 00538590 get_tile_mask_num,
//     00538710 draw_tile (unclaimed), 0053AED0 SetCaptureLevel,
//     0053B220 AddGDINode, 00535610 draw_object_outline (unclaimed),
//     0053AC70 reset_cyclic_overlay_sprites, 00538E60 Get_Cursor_Position,
//     00539930 pick_touched_object (unclaimed), 00538280, 005381C0, 00538420.
//   span/shape/object draw: 004BDA00 SetSpanRegions (scratch),
//     004BE1F0 AddMiniList, 004BE240 SubtractMiniList, 004B9040 shape_count,
//     004B9440 shape_draw (unclaimed), 00463000 Obj_List::draw,
//     004BDB00/004BE5F0/004BDFA0 spanlist helpers.
//   asm sprite pipeline: 0056C720 _ASMSet_Surface_Info,
//     0056C760 _ASMSet_Color_Xform, 0056C7A0 _ASMSet_Xlate_Table,
//     0056C9A0 _ASMDraw_Sprite.
//   UI/mouse/debug: 0045C010 TMousePointer::Poll, 004231E0 debug_timeGetTime,
//     0045B2B0 get_game_enable, 0045BE80 set_game_facet (scratch),
//     00466840 get_string, 004792A0 show_message, 00479540 remove_message,
//     00445250, 00445840, 00445B80, 00444300.
//   span/GDI late helpers checked 2026-05-04: 00538280 Add_GDI_Clip_Mask
//     unclaimed, 005381C0 Update_Render_Pointers matching, 00538420
//     Draw_GDI_Object unclaimed, 004BDB00 AddSpan unclaimed,
//     004BE5F0 Merge_n_Align scratch, 004BDFA0 AddShape_Align scratch.
//   virtual calls: [edx+0xF8], [edx+0x9C], [edx+0xB8].
//
// Phase map from line records/decompiler, useful for incremental reconstruction:
//   3026-3208 setup: update selected list, seed scan bounds, clear
//     terrain_types[].drawn, cache mutual explored/visible masks, reclaim futur
//     DClipInfo nodes, compute Full_Visibility/TileVisibleMask.
//   3227-3569 terrain diamond scan: alternating row/column walk over
//     max_row*2+12 by max_col+5; polls mouse every fourth scanline, drains
//     queued blits on odd scanlines; computes tile screen box, visibility byte
//     (0, 0x0f, 0x80), cached-last-drawn fast path, mask numbers, clip mini-lists,
//     draw_tile, object-list draw, and TileOffScreen redraw path.
//   3583-3750 post-terrain: drain queued blits, mouse poll, temporary render
//     origin adjust by input RECT, selection rectangle GDI node, optional object
//     outline, game-mode virtual hook, cyclic/extra overlay sprite animation and
//     drawing, reset_cyclic_overlay_sprites if any cyclic sprite expired.
//   3750-3830 futur_objs Y-line bucket relink into Draw_Level_Head/Tail, reset
//     clip globals, clear terrain clip regions if needed.
//   3830-3960 build Master_Clip_Mask either by full-screen AddSpan when terrain
//     rendering is off, or Merge_n_Align plus futur/prior DClipInfo comparison;
//     exact node equality uses byte compare length 0x24 for sprite nodes and
//     0x14 for GDI nodes (computed as (node_type!=0 ? 0x14 : 0x24)).
//   3960-4250 final blit/draw: PtrSpanCopy save_area1 to render surface,
//     Update_Render_Pointers, set ASM surface from Master_Clip_Mask, draw level
//     buckets 6..40, shadowing flags, Draw_GDI_Object for GDI nodes, optional
//     span/palette debug, Unlock, restore draw-area mask pointer, swap
//     futur_objs/prior_objs, return 0.
//
// Implementation strategy notes:
//   * Match the early terrain diamond scan first; it owns most frame locals and
//     source-line bands through 005374F6. Keep direct this/map/tile member access
//     instead of over-caching pointers unless asm carries a pointer.
//   * Do not attempt to "fix" calls to asm_special sprite routines; declare them
//     as extern C helpers only when the body reaches the final draw phase.
//   * Several small normal callees remain unclaimed/scratch. Matching them first
//     is not required for object compilation, but their packets are good layout
//     donors for DClipInfo_Node, TSpan_List_Manager, and Shape_Info.
//
// attempted 2026-05-04: created compileable scratch owner and recorded the
// first-line-band frame/type roadmap. No behavioral implementation yet; expected
// check_function result is a broad mismatch, but the VA is now claimed in scratch
// with concrete offsets/calls to drive reconstruction.
// continued 2026-05-04: audited full decompiler phase structure and dependency
// statuses; recorded phase map and exact late-node byte-compare sizes.
// continued 2026-05-04: added concrete local prefix structs and implemented the
// setup plus outer terrain diamond scan through visibility-byte selection. This
// compiled to a 528-byte .text (still far below the 5760-byte original).
// continued 2026-05-04: fixed RGE_Tile offsets (+0x09 draw_as, +0x0A
// draw_attribute), added cached-last-drawn/mask-number/draw_tile/object-list
// skeleton, post-loop queued-blit drain, and typed DClipInfo_List relink phase.
// Later continued: added extra_sprites animation/removal skeleton, prior_objs,
// Master_Clip_Mask/TSpan_List_Manager surface, and the first master clip build
// family. Then added selection-rect/game-mode hooks, final debug span/palette
// tail, PtrSpanCopy/Update_Render_Pointers/Unlock/swap tail, and the
// futur/prior DClipInfo comparison skeleton with byte-compare lengths 0x24/0x14.
// Current check_function compile is clean with .text 4000 bytes; still too short
// for byte diff. Later work fixed prior_objs to +0x334 (not +0x33C), added the
// low-level terrain/fog sprite prepass, mouse rollover/touched-object skeleton,
// and panel GDI-node loop around 0053793B-00537C3B. Continued by replacing the
// rollover placeholder with a real player virtual at vtable +0x9C and adding
// final sprite shadowing flag handling. Current clean .text is 4304 bytes.
// Remaining largest missing behavioral surface is accurate TSpan/TDrawArea
// field offsets plus the exact tile clip-mask SetSpan/AddMiniList family.
// continued: implemented enough tile clip-mask and Full_Visibility handling for
// check_function to produce a real same-size diff. Current result is MISMATCH
// 85.1042%, first mismatch offset 2: original frame is sub esp,0x110 and keeps
// this in ebp, rebuilt frame is sub esp,0xF4 and keeps this in esi. This is now
// a prologue/register-allocation problem rather than a too-short scaffold; next
// work should reduce/tune source shape and frame locals against original stack
// slot topology instead of merely adding more behavior.
// probed `register long rows_2_scan`; no prologue/register/frame change (still
// sub esp,0xF4 and this in esi), so the ebp-this basin likely needs broader
// liveness/source topology changes rather than a single register hint.
// continuation 2026-08-13: corrected the tile-box visibility guard against
// render_rect and restored both black-mask subtraction lanes in full redraw;
// these are binary-backed behavior fixes, although the source remains nonexact.
// continuation: restored the TPanel +0xB4 virtual slot and modeled the
// RGE_View virtual surface through +0xF8. Calls now have exact 83/83 target
// parity, including virtual mode-15 and panel get-rect dispatch.
// continuation: the cyclic overlay draw uses the typed +0x20 render-area
// owner. A post-relink MapVis-order probe was rolled back after worse CFG and
// size metrics. Removing the unsupported base-game null guard improved size.
// current validated reconstruction remains in scratch: 5896-byte text versus
// the original 5760, frame 0xF4 versus 0x110, strict diff 5471 bytes, with
// structural reconstruction still blocked by early local/register topology.
//
// continuation 2026-08-17: completed 24 meaningful probes plus one unchanged
// validation check. The retained source is 5760 bytes with a 0x110 frame,
// exact 83/83 ordered calls, 68.01% shape similarity, and 4913 differing
// bytes. The first mismatch is +0x0A: the oracle clears EBX before saving ESI
// and EDI; VC5 clears EDI after those saves.
// BINARY NOTE: the +0x180 view field is Master_Clip_Mask. TSpan line heads and
// tails are +0x3C/+0x40, bounds are +0x58..+0x64, and TDrawArea dimensions
// are +0x18/+0x1C. These layouts restored exact size and many exact blocks.
// BINARY NOTE: PtrSpanCopy uses save_area1->ClipRect and the master line-head
// array. The future relink, low-level draw, mouse, and panel phases stay in
// the executable order.
// Probe facts: the natural cached-visibility rectangle branch, short-circuit
// TileVisibleMask initialization, memcmp node comparison, function-scope
// POINT/RECT/text locals, and direct save-area dimension rereads improved the
// result. Declaration initializers, pointer tile cursors, and early-bound
// invalid-map exits did not improve the retained exact source.
// Open lead: recover the original early local/register topology, especially
// the EBX zero color and the setup stack homes. Do not add padding or register
// hints without binary-supported source evidence.
// Context pass 2026-08-17: same-TU draw_view, view_function, constructor, and
// terrain donors confirm render_area +0x20, cur_render_area +0xF4, world +0xFC,
// function_parm +0x141, the paint fields +0x154..+0x164, blit fields
// +0x2C8..+0x2F0, and selection-list fields +0x354..+0x35C. A context-only
// class reconstruction added these real fields. It worsened shape to 60.40%
// and strict diff to 4939 bytes, so it was restored. The pinned class context
// remains the smaller source that emits 4913 differing bytes.
// BINARY NOTE: The original loads render_area (+0x20) for Draw_GDI_Object,
// DrawLine, FillRect, Unlock, and the final CurrentMask restore. It uses
// save_area1 (+0x324) as the PtrSpanCopy source and sprite surface owner.
// The late render-area correction is retained. It gives 22.24% exact blocks,
// 68.31% shape similarity, and 4920 differing bytes. The source still needs
// early local and register topology recovery.



extern const char s_C__msdev_work_age1_x1_view_cpp[];
extern const char s_view__view_function_terrain[];
extern "C" void __cdecl _ASMSet_Surface_Info(void* offsets, void* heads, void* tails,
                                              long min_span, long min_line,
                                              long max_span, long max_line);
extern "C" void __cdecl _ASMSet_Color_Xform(void* mask);
extern "C" void __cdecl _ASMSet_Xlate_Table(void* table);
extern "C" void __cdecl _ASMDraw_Sprite(long base, long x, long y, long width, long height,
                                         long data_offsets, long outline_offset, long flags);
extern "C" void __cdecl _ASMSet_Shadowing(long a, long b, long c, long d);

long RGE_View::view_function_terrain(unsigned char mode, tagRECT rect) {
    long scan = 0;
    long col;
    long row;
    unsigned long MapVis;
    long start_row;
    long col_num;
    long map_width;
    long map_height;
    long cols_2_scan;
    long rows_2_scan;
    unsigned long TileVisibleMask;
    unsigned long TileFoggedMask;
    unsigned long TileExploredMask;
    unsigned long row_index;
    POINT pt;
    RECT pr;
    char text[128];
    int facet;
    int text_id;

    if (this->DispSel_List_Size > 0) {
        this->update_display_selected_objects();
    }

    col_num = this->start_map_col;
    start_row = this->start_map_row;
    cols_2_scan = this->max_col_num + 5;
    rows_2_scan = this->max_row_num * 2 + 12;
    map_width = this->map->map_width;
    map_height = this->map->map_height;
    this->function_mode = mode;

    for (long terrain_index = 0; terrain_index < this->map->num_terrain; ++terrain_index) {
        this->map->terrain_types[terrain_index].drawn = 0;
    }

    TileExploredMask = this->player->mutualExploredMask;
    TileFoggedMask = this->player->mutualVisibleMask;
    SDI_List = this->futur_objs;
    ((DClipInfo_List*)this->futur_objs)->ReclaimAllNodes();

    MapVis = (unsigned long)-1;
    if (this->player->visible == 0 ||
        (TileVisibleMask = 0, this->map->map_visible_flag != 0)) {
        TileVisibleMask = 1;
    }

    for (scan = 0; scan < rows_2_scan; ++scan) {
        col = col_num;
        row = start_row;
        if (((scan & 3) == 3) && MouseSystem != 0) {
            MouseSystem->Poll();
        }
        row_index = scan & 1;
        if (row_index == 1 && this->Queued_Blits != 0) {
            this->ProcessQueuedBlit(0);
        }

        for (long inner = 0; inner < cols_2_scan; ++inner) {
            if (row >= 0 && col >= 0 && row < map_height && col < map_width) {
                RGE_Tile* tile = &this->map->map_row_offset[row][col];
                long screen_x = tile->screen_xpos - this->map_scr_x_offset;
                long screen_y = tile->screen_ypos - this->map_scr_y_offset;
                unsigned long mask = unified_map_offsets[row][col];
                unsigned char draw_as;

                if ((mask & TileFoggedMask) != 0) {
                    draw_as = 0x0f;
                } else if ((mask & TileExploredMask) != 0 || TileVisibleMask != 0) {
                    draw_as = (unsigned char)((-(int)(this->map->fog_flag != 0) & 0x71) + 0x0f);
                } else {
                    draw_as = 0;
                    tile->last_drawn_as = 0;
                }

                long fog_mask_num;
                long black_mask_num;
                long normal_draw;
                long fog_draw;
                unsigned char terrain;

                terrain = tile->terrain_type;
                fog_mask_num = -1;
                black_mask_num = -1;
                normal_draw = 0;
                fog_draw = 0;
                if (draw_as != 0) {
                    long screen_right = screen_x + this->tile_wid;
                    long screen_bottom = screen_y + this->map->tilesizes[tile->tile_type].height;
                    if (screen_x <= this->render_rect.right &&
                        screen_y <= this->render_rect.bottom &&
                        screen_right > this->render_rect.left &&
                        screen_bottom > this->render_rect.top) {
                        if (this->calc_draw_count != 0 && terrain < this->map->num_terrain) {
                            this->map->terrain_types[terrain].drawn++;
                        }

                        int full_visibility = 0;
                        int clip_to = 0;
                        if (this->render_terrain_mode != 0 && tile->last_drawn_as == draw_as) {
                            if (draw_as == 0x0f) {
                                if (this->map->fog_flag == 0) {
                                    fog_mask_num = 0;
                                } else {
                                    fog_mask_num = this->get_tile_mask_num(col, row, map_width, map_height, TileFoggedMask);
                                }
                                if (tile->last_drawn_shape != (unsigned char)fog_mask_num) {
                                    goto TileOffScreen;
                                }
                            }
                            if (draw_as == 0x0f || draw_as == 0x80) {
                                if (TileVisibleMask == 0) {
                                    black_mask_num = this->get_tile_mask_num(col, row, map_width, map_height,
                                                                              TileExploredMask);
                                } else {
                                    black_mask_num = 0;
                                }
                                if (tile->last_drawn_shape2 != (unsigned char)black_mask_num) {
                                    goto TileOffScreen;
                                }
                            }
                            if (this->Limited_Render_Rect == 0) {
                                goto TileOffScreen;
                            }
                            if (this->Use_Rect2 != 0 &&
                                (this->Render_Rect2.right < screen_x ||
                                 screen_right < this->Render_Rect2.left ||
                                 this->Render_Rect2.bottom < screen_y ||
                                 (full_visibility = 1, screen_bottom < this->Render_Rect2.top))) {
                                full_visibility = 0;
                            }
                            if (this->Render_Rect1.right < screen_x ||
                                screen_right < this->Render_Rect1.left ||
                                this->Render_Rect1.bottom < screen_y ||
                                screen_bottom < this->Render_Rect1.top) {
                                if (full_visibility == 0) {
                                    goto TileOffScreen;
                                }
                                full_visibility = 0;
                                clip_to = 2;
                            } else {
                                clip_to = 1;
                            }
                        }

                        Tile_FogEdge_Table* edge_table = this->Tile_Edge_Tables[tile->tile_type];
                        long* black_edges = (long*)this->Black_Edge_Tables[tile->tile_type];
                        if (this->map->fog_flag == 0) {
                            fog_mask_num = 0;
                        }
                        if (TileVisibleMask != 0) {
                            black_mask_num = 0;
                        }
                        if (fog_mask_num == -1) {
                            if (draw_as == 0x0f) {
                                fog_mask_num = this->get_tile_mask_num(col, row, map_width, map_height, TileFoggedMask);
                            } else {
                                fog_mask_num = 0;
                            }
                        }
                        if (black_mask_num == -1) {
                            if (draw_as != 0) {
                                black_mask_num = this->get_tile_mask_num(col, row, map_width, map_height,
                                                                          TileExploredMask);
                            } else {
                                black_mask_num = 0;
                            }
                        }
                        void* normal_list = edge_table[fog_mask_num].normal_draw;
                        void* fog_list = edge_table[fog_mask_num].fog_draw;
                        void* black_list = (void*)black_edges[black_mask_num];
                        if (draw_as == 0x80) {
                            fog_list = edge_table[0].normal_draw;
                            normal_draw = 0;
                            fog_draw = 1;
                        } else {
                            normal_draw = (normal_list != 0);
                            fog_draw = (fog_list != 0);
                        }
                        if (black_mask_num < 1 || black_list == 0) {
                            black_list = 0;
                        }
                        if (clip_to != (int)MapVis) {
                            if (clip_to == 0) {
                                this->Terrain_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
                                    this->render_rect.right, this->render_rect.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
                                    this->render_rect.right, this->render_rect.bottom);
                            }
                            if (clip_to == 1) {
                                this->Terrain_Clip_Mask->SetSpanRegions(this->Render_Rect1.left, this->Render_Rect1.top,
                                    this->Render_Rect1.right, this->Render_Rect1.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->Render_Rect1.left, this->Render_Rect1.top,
                                    this->Render_Rect1.right, this->Render_Rect1.bottom);
                            }
                            MapVis = clip_to;
                            if (clip_to == 2) {
                                this->Terrain_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                    this->Render_Rect2.right, this->Render_Rect2.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                    this->Render_Rect2.right, this->Render_Rect2.bottom);
                                MapVis = clip_to;
                            }
                        }
                        if (normal_draw) {
                            this->Terrain_Clip_Mask->AddMiniList(
                                (VSpanMiniList*)normal_list, screen_x, screen_y);
                        }
                        if (fog_draw) {
                            this->Terrain_Fog_Clip_Mask->AddMiniList(
                                (VSpanMiniList*)fog_list, screen_x, screen_y);
                        }
                        if (black_list != 0) {
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->SubtractMiniList(
                                    (VSpanMiniList*)black_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->SubtractMiniList(
                                    (VSpanMiniList*)black_list, screen_x, screen_y);
                            }
                        }
                        if (full_visibility != 0) {
                            this->Terrain_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right, this->Render_Rect2.bottom);
                            this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right, this->Render_Rect2.bottom);
                            MapVis = 2;
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->AddMiniList(
                                    (VSpanMiniList*)normal_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->AddMiniList(
                                    (VSpanMiniList*)fog_list, screen_x, screen_y);
                            }
                            if (black_list != 0) {
                                if (normal_draw) {
                                    this->Terrain_Clip_Mask->SubtractMiniList(
                                        (VSpanMiniList*)black_list, screen_x, screen_y);
                                }
                                if (fog_draw) {
                                    this->Terrain_Fog_Clip_Mask->SubtractMiniList(
                                        (VSpanMiniList*)black_list, screen_x, screen_y);
                                }
                            }
                        }
                        {
                            short terrain_override =
                                this->map->terrain_types[terrain].terrain_to_draw;
                            if (terrain_override != -1) {
                                terrain = (unsigned char)terrain_override;
                            }
                        }
                        tile->last_drawn_shape2 = (unsigned char)black_mask_num;
                        tile->last_drawn_shape = (unsigned char)fog_mask_num;
                        tile->last_drawn_as = draw_as;
                        tile->draw_as = draw_as;
                        tile->draw_attribute &= 0xbf;
                        this->draw_tile(tile, terrain, (short)screen_x, (short)screen_y,
                                        (short)col, (short)row, draw_as, normal_draw, fog_draw);
                    }
                }

TileOffScreen:
                if ((tile->draw_attribute & 0x40) == 0x40) {
                    short terrain_override =
                        this->map->terrain_types[terrain].terrain_to_draw;
                    if (terrain_override != -1) {
                        terrain = (unsigned char)terrain_override;
                    }
                    this->draw_tile(tile, terrain, (short)screen_x, (short)screen_y,
                                    (short)col, (short)row, draw_as, 1, 1);
                    tile->draw_attribute &= 0xbf;
                }

                if (view_debug_Objects == 0) {
                    SDI_Capture_Info = 1;
                    if (draw_as == 0) {
                        ((DClipInfo_List*)this->futur_objs)->SetCaptureLevel(0, 5);
                    }
                    if (draw_as != 0x0f) {
                        fog_next_shape = 1;
                    }
                    tile->objects.draw(
                        this->save_area1,
                        (short)screen_x,
                        (short)(tile->height * this->tile_half_hgt + screen_y),
                        draw_as == 0x80);
                    ((DClipInfo_List*)this->futur_objs)->SetCaptureLevel(0, 0x28);
                    fog_next_shape = 0;
                    SDI_Capture_Info = 0;
                }

                (void)MapVis;
            }
            ++col;
            ++row;
        }

        if (row_index == 1) {
            ++start_row;
        } else {
            --col_num;
        }
    }

    while (this->Queued_Blits != 0) {
        this->ProcessQueuedBlit(1);
    }
    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }

    this->render_rect.left += rect.left;
    this->render_rect.top += rect.top;
    this->render_rect.right += rect.left;
    this->render_rect.bottom += rect.top;

    SDI_Capture_Info = 1;
    if (this->scroll_action == 2) {
        ((DClipInfo_List*)this->futur_objs)->AddGDINode(
            4, 0x14,
            this->mouse_down_x - rect.left,
            this->mouse_down_y - rect.top,
            this->mouse_last_x - rect.left,
            this->mouse_last_y - rect.top,
            0, 0, 0, 0, 0, 0x28, 0xFF);
    }

    long gm = rge_base_game->game_mode;
    if (gm == 1 || (gm > 6 && gm < 9)) {
        this->draw_object_outline();
    }
    if (gm == 0x15) {
        this->game_mode_15_hook();
    }

    // Extra/cyclic overlay sprites. This keeps the natural linked-list mutation
    // shape from 005375FA-0053773B; exact work later should tune declaration
    // visibility and delete/operator surface if register pressure differs.
    {
        unsigned char reset_all_cyclic = 0;
        Ov_Sprite_Draw_Rec* sprite = (Ov_Sprite_Draw_Rec*)this->extra_sprites;
        if (sprite != 0) {
            unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp, 0xE3E);
            while (sprite != 0) {
                unsigned char remove_sprite = 0;
                if (sprite->theShape != 0) {
                    if (sprite->LastDrawTime == 0) {
                        sprite->LastDrawTime = now;
                    } else if ((sprite->displayfunction == 1 || sprite->displayfunction == 2) &&
                               now - sprite->LastDrawTime >= sprite->DrawTimeInterval) {
                        unsigned long elapsed = now - sprite->LastDrawTime;
                        do {
                            ++sprite->thefacet;
                            if (sprite->theShape->shape_count() <= sprite->thefacet) {
                                sprite->thefacet = 0;
                                if (sprite->displayfunction == 2) {
                                    remove_sprite = 1;
                                    reset_all_cyclic = 1;
                                }
                            }
                            elapsed -= sprite->DrawTimeInterval;
                            sprite->LastDrawTime += sprite->DrawTimeInterval;
                        } while (sprite->DrawTimeInterval <= elapsed);
                    }
                    if (!remove_sprite) {
                        SDI_Draw_Level = sprite->drawLevel;
                        SDI_Object_ID = -1;
                        sprite->theShape->shape_draw(this->render_area,
                            sprite->world_x - this->map_scr_x_offset,
                            sprite->world_y - this->map_scr_y_offset,
                            sprite->thefacet,
                            sprite->flags,
                            sprite->colortable);
                    }
                }
                if (remove_sprite) {
                    Ov_Sprite_Draw_Rec* next = sprite->next;
                    if (sprite->prev != 0) {
                        sprite->prev->next = sprite->next;
                    }
                    if (sprite->next != 0) {
                        sprite->next->prev = sprite->prev;
                    }
                    if (sprite->prev == 0) {
                        this->extra_sprites = sprite->next;
                    }
                    delete sprite;
                    sprite = next;
                } else {
                    sprite = sprite->next;
                }
            }
        }
        if (reset_all_cyclic) {
            this->reset_cyclic_overlay_sprites();
        }
    }

    SDI_Capture_Info = 0;
    this->render_rect.left -= rect.left;
    this->render_rect.top -= rect.top;
    this->render_rect.right -= rect.left;
    this->render_rect.bottom -= rect.top;

    // Relink the future object list from Y-line buckets into draw-level buckets.
    // This mirrors the compact 00537789-005377DD phase and gives the later
    // master-clip/draw phases a typed DClipInfo surface to grow from.
    {
        DClipInfo_List* list = (DClipInfo_List*)this->futur_objs;
        for (long y = 0; y < list->YLine_Size; ++y) {
            for (DClipInfo_Node* node = list->Draw_Clip_Nodes[y]; node != 0; node = node->Next) {
                long level = node->Draw_Level;
                DClipInfo_Node* tail = list->Draw_Level_Tail[level];
                if (tail == 0) {
                    list->Draw_Level_Head[level] = node;
                } else {
                    tail->NextOnLevel = node;
                }
                list->Draw_Level_Tail[level] = node;
            }
        }
    }

    Clip_draw = 0;
    Clip_remove = 0;
    if (MapVis != 0) {
        this->Terrain_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
            this->render_rect.right, this->render_rect.bottom);
        this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
            this->render_rect.right, this->render_rect.bottom);
    }

    // Draw captured terrain sprites through the normal and fog clip masks.
    {
        DClipInfo_List* list = (DClipInfo_List*)this->futur_objs;
        for (long level = 0; level < 6; ++level) {
            for (DClipInfo_Node* node = list->Draw_Level_Head[level]; node != 0; node = node->NextOnLevel) {
                if (node->Node_Type == 0) {
                    TSpan_List_Manager* clip = this->Terrain_Clip_Mask;
                    _ASMSet_Surface_Info(this->save_area1->DisplayOffsets, clip->Line_Head_Ptrs,
                        clip->Line_Tail_Ptrs, clip->Min_Span_Px, clip->Min_Line,
                        clip->Max_Span_Px, clip->Max_Line);
                    _ASMSet_Color_Xform((void*)node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    Shape_Info* shape = node->Shape;
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag & 0xFE);
                    clip = this->Terrain_Fog_Clip_Mask;
                    _ASMSet_Surface_Info(this->save_area1->DisplayOffsets, clip->Line_Head_Ptrs,
                        clip->Line_Tail_Ptrs, clip->Min_Span_Px, clip->Min_Line,
                        clip->Max_Span_Px, clip->Max_Line);
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag | 1);
                }
            }
        }
    }

    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    if (rge_base_game != 0 && rge_base_game->prog_mode == 4 && this->have_focus != 0 &&
        MouseSystem != 0 && MouseSystem->get_game_enable() != 0) {
        unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp, 0xF11);
        if (this->Get_Cursor_Position(&pt, -rect.left, -rect.top) != 0) {
            long touched = 0;
            if (this->pick_touched_object(this->futur_objs, pt.x, pt.y, 10, 0x28, &touched) == 1) {
                if (!(this->UC_ObjectTouched != 0 && this->UC_TouchedObj == touched)) {
                    if (this->UC_TouchedObj != touched) {
                        this->UC_StartTime = now;
                    }
                    this->UC_ObjectTouched = 1;
                    this->UC_TouchedObj = touched;
                    facet = 0;
                    text_id = 0;
                    if (this->player->get_mouse_pointer_action_vars(
                            touched, facet, text_id) == 1) {
                        MouseSystem->set_game_facet(facet);
                        if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                            this->get_string(text_id, text, 0x7F);
                            this->message_panel->show_message(
                                TMessagePanel::InfoMessage, text, 'p', 0,
                                0, 0, 0);
                        }
                    } else {
                        MouseSystem->set_game_facet(0);
                        if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                            this->message_panel->remove_message();
                        }
                    }
                }
            } else if (this->UC_ObjectTouched != 0) {
                this->UC_ObjectTouched = 0;
                this->UC_TouchedObj = 0x80000000;
                MouseSystem->set_game_facet(0);
                if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                    this->message_panel->remove_message();
                }
            }
        }
    }

    // Capture active child panels that need a redraw.
    for (PanelNode* pn = this->first_child_node; pn != 0;
         pn = pn->next_node) {
        TPanel* panel = pn->panel;
        if (panel->active != 0 && panel->need_redraw != TPanel::RedrawNone) {
            panel->get_true_render_rect(pr);
            long x1 = pr.left - rect.left;
            long y1 = pr.top - rect.top;
            long x2 = pr.right - rect.left;
            long y2 = pr.bottom - rect.top;
            if (x1 < 0) x1 = 0;
            if (y1 < 0) y1 = 0;
            DClipInfo_Node* added = ((DClipInfo_List*)this->futur_objs)->AddGDINode(
                3, y1, x1, y1, x2, y2, y1, 0, 0, 0, 0, 0x1E,
                panel->display_changed_count);
            if (added != 0) {
                DClipInfo_List* list = (DClipInfo_List*)this->futur_objs;
                DClipInfo_Node* tail = list->Draw_Level_Tail[0x1E];
                if (tail == 0) {
                    list->Draw_Level_Head[0x1E] = added;
                } else {
                    tail->NextOnLevel = added;
                }
                list->Draw_Level_Tail[0x1E] = added;
            }
        }
    }

    // Initial Master_Clip_Mask construction. The exact original has a large
    // futur/prior DClipInfo comparison when render_terrain_mode is enabled; this
    // preserves the two high-level source families so later work can fill that
    // comparison in place.
    if (this->render_terrain_mode == 0) {
        long y = 0;
        if (this->save_area1->Height > 0) {
            do {
                this->Master_Clip_Mask->AddSpan(0, this->save_area1->Width - 1, y);
                ++y;
            } while (y < this->save_area1->Height);
        }
        ((DClipInfo_List*)this->prior_objs)->ReclaimAllNodes();
    } else {
        this->Master_Clip_Mask->Merge_n_Align(this->Terrain_Clip_Mask, this->Terrain_Fog_Clip_Mask);
        Clip_draw = 0;
        Clip_remove = 0;
        if (this->Limited_Render_Rect != 0) {
            for (long y = this->Render_Rect1.top; y <= this->Render_Rect1.bottom && this->Render_Rect1.left >= 0; ++y) {
                this->Master_Clip_Mask->AddSpan(this->Render_Rect1.left, this->Render_Rect1.right, y);
            }
            if (this->Use_Rect2 != 0) {
                for (long y = this->Render_Rect2.top; y <= this->Render_Rect2.bottom && this->Render_Rect2.left >= 0; ++y) {
                    this->Master_Clip_Mask->AddSpan(this->Render_Rect2.left, this->Render_Rect2.right, y);
                }
            }
        }

        DClipInfo_List* future = (DClipInfo_List*)this->futur_objs;
        DClipInfo_List* prior = (DClipInfo_List*)this->prior_objs;
        for (long y = 0; y < future->YLine_Size; ++y) {
            for (DClipInfo_Node* f = future->Draw_Clip_Nodes[y]; f != 0; f = f->Next) {
                if (f->Draw_Level > 5) {
                    int different = 1;
                    DClipInfo_Node* p = prior->Draw_Clip_Nodes[y];
                    while (p != 0) {
                        long bytes = (f->Node_Type != 0) ? 0x14 : 0x24;
                        if (memcmp(&f->Shape, &p->Shape, bytes) == 0) {
                            different = 0;
                            ++Clip_remove;
                            p->Node_Type = -1;
                            break;
                        }
                        p = p->Next;
                    }
                    if (different) {
                        if (f->Node_Type == 0) {
                            this->Master_Clip_Mask->AddShape_Align(f->Shape_Base, f->Shape,
                                f->Draw_X, f->Draw_Y, ((f->Draw_Flag & 2) == 2));
                            ++Clip_draw;
                        } else {
                            this->Add_GDI_Clip_Mask(f, this->Master_Clip_Mask);
                        }
                    }
                }
            }
            for (DClipInfo_Node* p = prior->Draw_Clip_Nodes[y]; p != 0; p = p->Next) {
                if (p->Draw_Level > 5 && p->Node_Type != -1) {
                    int different = 1;
                    DClipInfo_Node* f = future->Draw_Clip_Nodes[y];
                    while (f != 0) {
                        long bytes = (p->Node_Type != 0) ? 0x14 : 0x24;
                        if (memcmp(&f->Shape, &p->Shape, bytes) == 0) {
                            different = 0;
                            break;
                        }
                        f = f->Next;
                    }
                    if (different) {
                        if (p->Node_Type == 0) {
                            this->Master_Clip_Mask->AddShape_Align(p->Shape_Base, p->Shape,
                                p->Draw_X, p->Draw_Y, ((p->Draw_Flag & 2) == 2));
                            ++Clip_draw;
                        } else {
                            this->Add_GDI_Clip_Mask(p, this->Master_Clip_Mask);
                        }
                    }
                }
            }
        }
    }

    this->render_rect.left += rect.left;
    this->render_rect.top += rect.top;
    this->render_rect.right += rect.left;
    this->render_rect.bottom += rect.top;
    this->save_area1->PtrSpanCopy(this->render_area, this->render_rect.left, this->render_rect.top,
                                  &this->save_area1->ClipRect,
                                  (unsigned char**)this->Master_Clip_Mask->Line_Head_Ptrs);
    this->Update_Render_Pointers();
    this->render_rect.left -= rect.left;
    this->render_rect.top -= rect.top;
    this->render_rect.right -= rect.left;
    this->render_rect.bottom -= rect.top;
    _ASMSet_Surface_Info(this->RenderOffsets, this->Master_Clip_Mask->Line_Head_Ptrs,
        this->Master_Clip_Mask->Line_Tail_Ptrs, this->Master_Clip_Mask->Min_Span_Px,
        this->Master_Clip_Mask->Min_Line, this->Master_Clip_Mask->Max_Span_Px,
        this->Master_Clip_Mask->Max_Line);
    this->save_area1->CurSpanList = this->Master_Clip_Mask;

    // Final draw-level walk skeleton (original levels 6..40, byte offset
    // 0x18..0xA0 through Draw_Level_Head). Surface setup/shadowing/PtrSpanCopy
    // still need to be inserted before this can approach the original tail.
    {
        DClipInfo_List* list = (DClipInfo_List*)this->futur_objs;
        for (long level = 6; level < 41; ++level) {
            for (DClipInfo_Node* node = list->Draw_Level_Head[level]; node != 0; node = node->NextOnLevel) {
                if (node->Node_Type == 0) {
                    int shadowing = 0;
                    unsigned long shadow_flags = node->Draw_Flag & 0xFFC;
                    if (shadow_flags != 0) {
                        if ((shadow_flags & 4) == 4) {
                            _ASMSet_Shadowing(0xFFFFFF, 0, 0xFFFF00FF, 0);
                        }
                        if ((shadow_flags & 8) == 8) {
                            unsigned long s = (shadow_flags >> 4);
                            _ASMSet_Shadowing(0xFF00FF00, (s << 16) | s, 0x00FF00FF, s << 8);
                        }
                        shadowing = 1;
                    }
                    _ASMSet_Color_Xform((void*)node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    Shape_Info* shape = node->Shape;
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                                    shape->Width, shape->Height,
                                    shape->Shape_Data_Offsets,
                                    shape->Shape_Outline_Offset,
                                    node->Draw_Flag & 3);
                    if (shadowing) {
                        _ASMSet_Shadowing(0xFF00FF, 0, 0xFF00FF00, 0);
                    }
                } else {
                    this->Draw_GDI_Object(node, this->render_area);
                }
            }
        }
    }

    if (view_debug_spans != 0 && this->render_terrain_mode != 0) {
        unsigned char color = (unsigned char)(frame_count % 0xDC + 0x10);
        long y = 0;
        if (this->render_area->Height > 0) {
            do {
                this->render_area->DrawLine(0, y, this->render_area->Width - 1, y, color);
                ++y;
            } while (y < this->render_area->Height);
        }
    }

    if (view_debug_palette != 0) {
        unsigned char row_base = 0;
        long y = 0x20;
        do {
            unsigned char palette_color = 0;
            long x = 0;
            do {
                this->render_area->FillRect(x, y, x + 0x1F, y + 0x0F,
                                           (unsigned char)(palette_color + row_base * 0x10));
                x += 0x20;
                ++palette_color;
            } while (x < 0x200);
            y += 0x10;
            ++row_base;
        } while (y < 0x120);
    }

    this->render_area->Unlock((char*)s_view__view_function_terrain);
    this->render_area->CurSpanList = this->render_area->SpanList;
    {
        DClipInfo_List* tmp = this->futur_objs;
        this->futur_objs = this->prior_objs;
        this->prior_objs = tmp;
    }

    return 0;
}

// 005381C0 Update_Render_Pointers (view.cpp:4254-4278)
// PDB source: view.cpp (RGE_View::Update_Render_Pointers)
//
// Attempt log:
// first pass: exact MATCH on first compile. Local TPanel/TDrawArea stubs with
// exact layout + natural control flow. 190 bytes, 0 diff, 2 masked relocations.


void RGE_View::Update_Render_Pointers() {
    unsigned char* bits = render_area->Bits;

    if (LastRenderBits == bits) {
        int count = render_rect.bottom - render_rect.top + 1;
        if (LastRenderSize == count)
            return;
    }

    int count = render_rect.bottom - render_rect.top + 1;
    if (count <= 0 || bits == 0)
        return;

    if (count != LastRenderSize || RenderOffsets == 0) {
        if (RenderOffsets != 0)
            free(RenderOffsets);
        RenderOffsets = (void**)malloc(count * 4);
        LastRenderSize = count;
    }

    for (int i = 0; i < count; i++) {
        RenderOffsets[i] = (void*)((int)render_area->DisplayOffsets[i + render_rect.top] + render_rect.left);
    }
}

// VA: 00538280 RGE_View::Add_GDI_Clip_Mask
// Source: view.cpp lines 4281-4335
// Size: 385 bytes
// Calling convention: __thiscall, ret 8
//
// Attempt log:
// Probes 1-22 (default flags /O2 /Oy): sub esp always 0x0C vs 0x08 needed.
// Various local layouts, arrays, switch, early returns, inline asm tricks all
// produced the same extra 4 bytes of stack.
//
// Probe 23 (all ints at function scope): **BREAKTHROUGH** sub esp=8 matches!
// But register coloring differs: original uses esi=node, my code uses ebp=node.
// First mismatch at offset 5 (mov ebp,[esp+14h] vs push esi).
//
// Probes 24-28: tried reordering decls, adding n=node local, removing nt var,
// reducing function-scope vars to 2. Register coloring unchanged (ebp=node).
// Node_Type 4 path also diverges structurally due to different variable
// management (original stores 4 derived values upfront to stack; my code
// computes some inline and uses different stack slots).
//
// Left in scratch: remaining mismatch is register coloring (ebp vs esi for node)
// combined with cascading block-shape differences in type 2/3 and type 4 paths.
// Core insight: function-scope ints (any number >= 2) produce sub esp,8 match.
// Probe 29: outer non-type-1 structure — 408-byte output/frame loss; rolled back.
// Probe 30: register-qualified node/span parameters — codegen duplicate; rolled back.
// Probe 31: cache initial Node_Type — codegen duplicate; rolled back.
// Probe 32: guarded type2/3 do/while — 398-byte output/frame loss; rolled back.
// Probe 33: branch-local span-manager aliases — codegen duplicate; rolled back.
// Probe 34: hoist all integer temporaries to function scope in old-TU style.
// This historical function-scope source emitted 402 bytes, 273 positional diff
// bytes, the exact 9-call set, the 0x8 frame, and 59.74% shape.
//
// Probes 35-39: nested else, type2 fallthrough, guarded do/while, and else-if
// forms either lost the 0x8 frame or reproduced the clean baseline. Rolled back.
// Probe 40: block-local lifetimes matched more block shapes but lost the frame;
// rolled back.
// Probes 41-42: compute type4 edge bounds before y normalization. The best
// diagnostic diff was 251, but it used a 0xC frame and lost block coverage.
// Rolled back. Current source is the validated typed baseline.
// Probe 43: natural type2/3 source-order fallthrough with a guarded do/while
// produced a 400-byte body and lost the required 0x8 frame; rolled back.
// Probe 44: reordered coordinate declarations; emitted code was unchanged.
// Probe 45: separate line-manager alias; emitted code was unchanged.
// Probe 46: switch dispatch; 408 bytes and 397 diff, rolled back.
// Probe 47: source-order type2 fallthrough with named type4 edge locals; 370
// bytes and no frame, rolled back.
// Probes 49-51: named/reused type4 inner edges improved the diagnostic diff to
// 248-249 and shape to 68.6%, but forced a 0xC frame and only 2% exact blocks;
// the source also depended on dead-local reuse. Restored the clean 0x8-frame
// typed baseline. Next lead remains the original node/manager register basin
// and type2/type4 block topology, not further register tuning at this stage.

// Follow-up probes 52-53: removing the type2/3 return and restoring source-order
// x/y loads with a guarded do/while produced 400 and 396 bytes without the frame.
// Probe 54: named type4 inner edges recovered the 0x8 frame, 150 instructions,
// 384 bytes, 68.67% exact blocks, and 94.67% shape.
// Probes 55-56: branch aliases and declaration-order changes were duplicates.
// Probe 57: mutating the type2 lower bound directly lost the frame and was rolled
// back. Probe 58: block-local type2/type4 lifetimes improved exact blocks to
// 79.33% and shape to 96.67%, while positional diff stayed 153 bytes.
// Probes 59-61: separate alias assignment, declaration order, and register hints
// were duplicates. Probes 62 and 66: in-place type4 edge masks changed the type2
// stack-home order and produced 390 bytes; rolled back.
// Probes 63-65: a function-scope manager alias, loop declaration movement, and a
// reference receiver were duplicates. Probe 67: x declaration initializers caused
// uninitialized warnings and lost the frame. Probe 68: mutating raw x locals
// produced 378 bytes without the frame; rolled back.
// Final validation after removing the unused padding declaration stayed at 384
// bytes, 153 positional diff bytes, 79.33% exact blocks, 96.67% shape, exact
// 9-call order, and the required 0x8 frame. The natural source remains in scratch.
// Original EBX/EDI roles and the type4 raw-edge schedule remain unresolved.
// Follow-up pass: typed mask aliases, an explicit non-line else arm, a typed
// manager reference, and natural type4 edge-order variants were tested. The
// aliases and else/reference forms were codegen duplicates. Edge-order and
// direct-expression forms reduced structural parity or lost the frame. The
// clean typed source remains the best natural reconstruction: 153-byte diff,
// exact 9-call order, 0x8 frame, and first mismatch at type2 manager/loop
// register assignment (+0x8E). Keep the source in scratch.
// Revisit pass: direct type2 x-local mutation, narrow x locals, a branch-local
// manager reference, and the period windows.h context were tested. The first,
// narrow, and context forms were worse or lost the frame; the manager form was
// a codegen duplicate. All experiments were restored. Final validation remains
// the clean typed source: 384/385 bytes, 153 positional diff bytes, exact calls,
// 0x8 frame, and first mismatch at +0x8E.
// Earlier accepted-drift review: the type-1 path was exact. Type-2/3 and type-4 used the same
// signed node reads, normalized bounds, nine calls, arguments, loop limits,
// post-call node-type reread, and returns. Values used after AddSpan are private
// copies in both builds. Remaining differences are register and stack-home
// assignment.
// Recovered view.cpp TU pass: exact 005381C0 precedes this owner on the shared
// RGE_View surface. The /GX grouped result remains 384/385 bytes with 153
// differences and all nine calls ordered.
// Exact finish: compute type-2 bounds directly from the node fields. Compute
// all four type-4 bounds before the vertical bounds.
// One `edge` scratch local spans both non-line arms. Type 2 stores its right
// bound there. Type 4 stores its left inner edge there.
// BINARY NOTE: removing that shared lifetime swaps three compiler stack homes.
// The result then differs by nine bytes. Sharing only xl and y1 is incidental.
// Narrowing `edge` past the type-1 return and initializing xl at first use both
// stay exact. The final source matches all 385 bytes and all nine direct calls.


void RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node* node, TSpan_List_Manager* span_mgr)
{
    if (node->Node_Type == 1) {
        span_mgr->AddLine_Align(node->x1, node->y1, node->x2, node->y2);
        span_mgr->AddLine_Align(node->x2, node->y2, node->x3, node->y3);
        span_mgr->AddLine_Align(node->x3, node->y3, node->x4, node->y4);
        span_mgr->AddLine_Align(node->x4, node->y4, node->x1, node->y1);
        return;
    }
    int edge;
    if (node->Node_Type == 2 || node->Node_Type == 3) {
        int y1v;
        int y2v;
        int tmp;
        int y;

        int xl = node->x1 & ~3;
        edge = node->x2 | 3;
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        if (y1v <= y2v) {
            y = y1v;
            do {
                span_mgr->AddSpan(xl, edge, y);
                y++;
            } while (y <= y2v);
        }
    }
    if (node->Node_Type == 4) {
        int y1v;
        int y2v;
        int x1v;
        int x2v;
        int tmp;
        int y;

        x1v = node->x1;
        x2v = node->x2;
        if (x1v > x2v) {
            tmp = x1v; x1v = x2v; x2v = tmp;
        }
        int xl = x1v & ~3;
        edge = x1v | 3;
        int right_edge = x2v & ~3;
        int xr = x2v | 3;
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        span_mgr->AddSpan(xl, xr, y1v);
        span_mgr->AddSpan(xl, xr, y2v);
        y = y1v + 1;
        for (; y < y2v; y++) {
            span_mgr->AddSpan(xl, edge, y);
            span_mgr->AddSpan(right_edge, xr, y);
        }
    }
}


void RGE_View::draw_multi_object_outline() {}

// VA: 00538420 RGE_View::Draw_GDI_Object(DClipInfo_Node*, TDrawArea*)
// PDB source: view.cpp lines 4347-4387
// attempt 1: direct decompiler-shaped control flow and typed fields.


void RGE_View::Draw_GDI_Object(DClipInfo_Node* node, TDrawArea* draw) {
    int i;

    if (node->Node_Type == 1) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y2, node->Draw_Flag);
        draw->DrawLine(node->x2, node->y2, node->x3, node->y3, node->Draw_Flag);
        draw->DrawLine(node->x3, node->y3, node->x4, node->y4, node->Draw_Flag);
        draw->DrawLine(node->x4, node->y4, node->x1, node->y1, node->Draw_Flag);
        return;
    }

    if (node->Node_Type == 2) {
        i = node->y1;
        if (i <= node->y2) {
            do {
                if (node->y3 != 0) {
                    draw->DrawLine(node->x1, i, node->x3, i, 0x4A);
                }
                if (node->y4 != 0) {
                    draw->DrawLine(node->x4, i, node->x2, i, 0x97);
                }
                i++;
            } while (i <= node->y2);
        }
    }

    if (node->Node_Type == 4) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y1, 0xFF);
        draw->DrawLine(node->x1, node->y2, node->x2, node->y2, 0xFF);
        draw->DrawLine(node->x1, node->y1, node->x1, node->y2, 0xFF);
        draw->DrawLine(node->x2, node->y1, node->x2, node->y2, 0xFF);
    }
}

// VA: 00538590 RGE_View::get_tile_mask_num
// PDB: view.cpp:4394-4439
// attempt 1: direct eight-neighbor reconstruction; right size but x/y register coloring swapped.
// attempt 2: decompiler-shaped scalar locals and fixed-address row pointer macro; still swapped x/y registers.
// attempt 3: introduce explicit col/row locals to probe VC5 register coloring; no change.
// attempt 4: mark col/row register locals; no change (and register parameters forced /O1 frame when paired with /O1 probe).
// attempt 5: use explicit negated OR boundary predicate like decompiler/original source; changed compares but not register coloring.
// attempt 6: swapped col/row local definitions as a register-allocation probe; load order moved but semantics wrong.
// attempt 7: swapped locals with row-first guard fixed initial load order but made body x/y swapped.
// attempt 8: keep a first-param guard temp while restoring col/row semantics; no register change.
// attempt 9: keep swapped local names but use row=first-arg as x and col=second-arg as y; behavior/call-free effects correct but VC5 still chooses first arg in EDX and second in EAX.
// tried fixed-address macro vs extern row array; macro reduced relocation noise but not register coloring.
// tried negated-OR guard, explicit locals, register locals, swapped local names, and /O1 probe; /O1 made an EBP frame and was discarded.
// left in scratch: remaining mismatch is broad x/y register coloring, external
// row-table relocation/context, and common-tail placement. The retained source
// uses the canonical typed extern row table (no absolute-address macro) and the
// natural interior/edge if/else; current default build is 398 bytes, 308
// positional bytes, 83.87% shape, with call-free behavior/layout reconstructed.
// probe 10: replace the legacy absolute map macro with the canonical typed row-table declaration.
// probe 11: remove row/col aliases and use the formal parameters directly.
// probe 12: register-qualified coordinate parameters — codegen duplicate; rolled back.
// probe 13: explicit common-tail goto for the binary-proven central-path jump.
// probe 14: positive interior block first, explicit goto, then boundary block; no change.
// continuation probes (sa-f0a10d2b-r1): row/col alias initialization order,
// same-TU polymorphic RGE_View/TPanel layout, nested positive guards, and
// first-formal register qualification all emitted the same 398-byte basin.
// Named central row-pointer locals worsened to 397 bytes and were rolled back.
// Variant labs over common-tail wrappers, row-table declarations, indexed vs
// pointer-add cell access, and algebraically reordered row expressions found
// no exact or size-matching candidate. A deliberately transposed access form
// did flip the entry colors but changed the physical neighbor orientation and
// is diagnostic only.
// continuation probe: an explicit jump from the final interior mask test to
// the shared return tail emitted the same 398-byte code; restored clean source.
// continuation probe (orch-538590-a): an explicit jump after the arms was a
// codegen duplicate and kept the 398-byte duplicated epilogue.
// continuation probe (orch-538590-a): a separate complementary edge guard
// reached the exact 382-byte size, but expanded CFG drift to 362 bytes and
// lost the strong central/body islands; restored the canonical if/else.
// left in scratch: canonical typed row-table source remains 398 bytes with
// 308 positional-byte drift (+16 tail), first mismatch at entry parameter
// coloring; original also retains a shared late return tail that VC5 does not
// select from the tested natural source forms.
// matching pass sa-092c01cf-r1: baseline rechecked at 398 bytes, 308 differing
// bytes, 83.87% shape, and no calls. Restored clean source after every probe.
// The absolute row-table plus swapped semantic aliases improved shape to
// 92.74% and exact blocks to 95%, but produced 399 bytes and transposed the
// proven coordinate ownership, so it was discarded. A common-tail goto was a
// codegen duplicate. Hoisting the x stride added 61 bytes. A pointer-to-pointer
// global added an EBP frame and 55 bytes. All four decompiler locals, a Windows
// SDK include, reordered guards, and a guarded done label were codegen-neutral
// or worse. No natural exact candidate was found; retain the canonical source.
// matching pass sa-3bf37621-r1: named col/row, bounds, and mask-number locals
// preserve the caller's (col,row,width,height,mask) ownership. This source
// compiles to the same clean basin as the pinned candidate.
// Accepted-drift baseline: interior reads remained N,E,S,W,NE,SE,SW,NW. Edge
// reads remained W,E,N,S,NW,SW,NE,SE. The old isolated rebuild removed two
// repeated edge tests and duplicated the return.
// Exact grouped finish: the PDB-ordered shared prefix and /GX module flags
// recover the original X/Y register roles, 382-byte boundary, and common return.
// Four independent diagonal guards retain both repeated edge tests. Splitting
// only the left or right pair is nonexact, so both source groups are required.
// Final grouped result: MATCH, 0.0000%, 120 instructions, and no calls or writes.


int RGE_View::get_tile_mask_num(int col, int row, int map_width,
                                int map_height, unsigned long mask)
{
    unsigned int mask_number = 0;

    if (0 < col && 0 < row && col < map_width - 1 && row < map_height - 1) {
        if ((unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number = 0x80;
        if ((unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if ((unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if ((unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number |= 0x10;
        if ((unified_map_offsets[row - 1][col + 1] & mask) == 0)
            mask_number |= 0x08;
        if ((unified_map_offsets[row + 1][col + 1] & mask) == 0)
            mask_number |= 0x04;
        if ((unified_map_offsets[row + 1][col - 1] & mask) == 0)
            mask_number |= 0x02;
        if ((unified_map_offsets[row - 1][col - 1] & mask) == 0)
            mask_number |= 0x01;
    } else {
        if (0 < col && (unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number = 0x10;
        int max_col = map_width - 1;
        if (col < max_col && (unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if (0 < row && (unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number |= 0x80;
        int max_row = map_height - 1;
        if (row < max_row && (unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if (0 < col && 0 < row &&
            (unified_map_offsets[row - 1][col - 1] & mask) == 0)
            mask_number |= 0x01;
        if (0 < col && row < max_row &&
            (unified_map_offsets[row + 1][col - 1] & mask) == 0)
            mask_number |= 0x02;
        if (col < max_col && 0 < row &&
            (unified_map_offsets[row - 1][col + 1] & mask) == 0)
            mask_number |= 0x08;
        if (col < max_col && row < max_row &&
            (unified_map_offsets[row + 1][col + 1] & mask) == 0)
            mask_number |= 0x04;
    }

    return this->EdgeNumber[mask_number];
}

// 00538710 RGE_View::draw_tile
// Attempt log:
// try 1-10: the prior raw-offset model used the wrong parameter ABI and fake
// resolve/draw helpers; it was 842B and missed the two border helpers and five
// draw_terrain_shape sites.
// probe 1 baseline: recorded the rough scaffold before replacing it.
// probe 2: canonicalized RGE_Tile/RGE_Map/RGE_Border_Set ownership, the exact
// view.cpp helper signatures, duplicated simple/composite border calls, and the
// two binary-proven neighbor-marking paths.
// probe 3: removed the persistent map alias; resync similarity improved and the
// terrain offset became the correct map-relative 0x198 stride.
// probe 4-6: tested cached border-byte/index widths and edge-output declaration
// order; the int low-nibble index plus one cached byte recovered exact size,
// frame, and the broadest exact-block basin.
// probe 7: moved flag/result/border initialization after the loaded guard and
// combined the two early failures; this recovered the original shared tail.
// probe 8: a pTile alias was a codegen duplicate and was removed from living
// source. probe 9: retained the binary-proven comma assignment in the combined
// terrain guard.
// probe 11: reversed the terrain-count guard operands to match the original
// AX-versus-memory compare; diff improved 1056 -> 1054 bytes and first-hunk
// compare shape now matches, but the EBX tile load still follows the pushes.
// best final check: 1135B rebuilt/original, 0x28 frame, all 11 direct calls and
// target relocations aligned, 1056 strict diff bytes, 69.90% shape similarity,
// 33.87% exact-block coverage. Remaining drift is broad entry/local register
// coloring and duplicated-tail scheduling; no call/layout/ABI blocker remains.
// continuation probes: a shared done label matched the original 3-return CFG
// and raised shape similarity to 80.27%, but reduced effective size by 21B.
// Direct tile border-byte reloads moved the entry tile load into EBX before the
// saved-register pushes, matching the original first hunk, but reduced the
// frame to 0x20 and lost structural islands. Direct indexed border fields gave
// a diagnostic 824B diff, but kept the 0x20 frame and swapped the EBP/EDI
// index/base roles. Restored the pinned 0x28-frame natural source.
// probes 12-16: signed neighbor locals, a cached border index, int draw_border,
// and split initialization were duplicates or lost structural islands.
// probes 17-19: direct indexed fields in only the late border path improved
// shape and exact blocks at the same frame; a Windows header and output-order
// permutation were codegen duplicates. Ambient declaration samples made two
// basins but changed the effective size and produced no exact candidate.
// continuation probes (sa-349a0cd7-r1): restoring the earlier natural
// three-return/pointer-alias source gave exact size but a 0x24 frame, 969
// differing bytes, and 67.79% shape; it was restored because its CFG basin
// was worse. Splitting draw_border initialization was a codegen duplicate.
// Direct tile border reloads recovered the EBX tile register but reduced the
// frame to 0x20 and shape to 63.20%; a late-only reload reduced shape to
// 64.27%, and a separate top-index copy was a duplicate. Delaying result
// initialization was also a duplicate. Narrow border_type gave 982 bytes,
// 0x24 frame, and 71.77% shape. A byte border_type plus an int top_index gave
// exact size and frame but only 71.65% shape. Direct initial border fields gave
// 1039 bytes, 0x24 frame, and 68.53% shape. All variants were restored.
// Current clean unresolved source remains 1108B effective code, 0x28 frame,
// 3 returns, 11 aligned direct calls, 1049 strict diff bytes, and 80.85%
// shape. Open lead: recover the original EBX tile plus delayed EDI save while
// retaining the current natural frame and late-path CFG.
// Current clean unresolved source: 1108B effective code, 0x28 frame, 3 returns,
// 11 aligned calls, 1049 strict diff bytes, and 80.85% shape similarity.


int RGE_View::draw_tile(RGE_Tile* tile, unsigned char terrain_type,
                        short x, short y, short map_x, short map_y,
                        unsigned char draw_attribute, int draw1, int draw2)
{
    unsigned char draw_border = tile->draw_attribute;
    int terrain_offset;
    int overlay_available;
    int terrain_draw;
    unsigned char border_info;
    int border_type;
    int left_index;
    int right_index;
    int bottom_index;
    int retval;
    int result = 0;

    if ((short)terrain_type >= this->map->num_terrain ||
        ((terrain_offset = (int)terrain_type * (int)sizeof(RGE_Tile_Set)),
         this->map->terrain_types[terrain_type].loaded == 0)) {
        return 0;
    }

    terrain_draw = 1;
    result = 0;
    overlay_available = 0;
    border_info = tile->border_type;
    border_type = border_info & 0x0F;

    if (border_type != 0) {
        RGE_Border_Set* border = &this->map->border_types[border_type];
        if (border->loaded != 0 && border->shape != 0) {
            if (border->border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    overlay_available = 1;
                    terrain_draw = border->draw_tile;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        &left_index, &bottom_index,
                        &right_index, &retval) != 0) {
                    overlay_available = 1;
                    terrain_draw = 1;
                }
            }
        }
    }

    if (View_Grid_Mode > 0 && (draw_border & 0xDF) == 0 &&
        ((((int)map_x / View_Grid_Mode) +
          ((int)map_y / View_Grid_Mode)) & 1) == 1) {
        draw_border |= 0x20;
    }

    if (view_debug_ObstructionMap != 0) {
        overlay_available = 0;
    }

    if (terrain_draw != 0) {
        TShape* shape = this->map->terrain_types[terrain_type].shape;
        short picture = this->get_tile_picture(
            terrain_type, tile->tile_type, map_x, map_y);
        if (shape != 0 && picture != -1) {
            if (view_debug_ObstructionMap != 0) {
                this->draw_terrain_obstruction_map(
                    x, y, shape, picture, map_x, map_y);
                return 1;
            }
            this->draw_terrain_shape(
                x, y, shape, picture, draw_attribute,
                draw_border, draw1, draw2);
            result = 1;
        }

        if (overlay_available == 0) {
            if (map_x > 0) {
                RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
                left->draw_attribute |= 0x40;
            }
            if (map_y < this->map->map_height - 1) {
                RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
                below->draw_attribute |= 0x40;
            }
        }
    }

    if (overlay_available == 0) {
        // BINARY NOTE: The zero-overlay path joins the final return epilogue.
        goto done;
    }

    {
        // BINARY NOTE: The late path reloads the indexed border record.
        TShape* shape = this->map->border_types[border_type].shape;
        if (shape != 0) {
            if (this->map->border_types[border_type].border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    retval = picture;
                } else {
                    goto mark_neighbors;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        &left_index, &bottom_index,
                        &right_index, &retval) == 0) {
                    goto mark_neighbors;
                }
                if (left_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, left_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (right_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, right_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (bottom_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, bottom_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (retval == -1) {
                    goto mark_neighbors;
                }
            }
            this->draw_terrain_shape(
                x, y, shape, retval, draw_attribute,
                draw_border, draw1, draw2);
        }
    }

mark_neighbors:
    if (map_x > 0) {
        RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
        left->draw_attribute |= 0x40;
    }
    if (map_y < this->map->map_height - 1) {
        RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
        below->draw_attribute |= 0x40;
    }

done:
    return result;
}

// 00538B80 RGE_View::draw_terrain_shape
// Attempt log:
// 1: Natural reconstruction from packet with local stubs for TShape/draw area/fog globals: broad diff; shape table pointer was at +0x1c and x/y offsets were swapped.
// 2: Fix TShape table offset and source x/y offset mapping: table offset fixed, but coordinate local scheduling/registers still wrong.
// 3: Seed draw_y/draw_x locals from params before table lookups: no codegen change.
// 4: Declare draw_x before draw_y to probe saved-register assignment: no useful change.
// 5: Move fog_next_shape assignment before shadow setup in early fog branch: slightly improved edit diff but still wrong top scheduling.
// 6: Use explicit byte-offset table arithmetic for shape frame info: no codegen change.
// 7: Tried /Ob0: no codegen change; removed flag.
// 8: Tried /O1: wrong-size 407-byte function; removed flag.
// 9: Tried /Od: broad 85.17% mismatch from first byte; removed flag.
// 10: Replaced the sketch with typed Shape_Info, RGE_Map, TDrawArea, and view clip-list fields. Restored original x/y for ordinary draws; typed baseline reached a 6-byte diff.
// 11: Declared draw_x before draw_y. VC5 then assigned EDI/EBP like the original; exact 472-byte match.
// Exact: the source uses named shape hotspots, map fog state, and terrain/fog span-list ownership.



void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2)
{
    int draw_x = x - shape->shape_info[frame].Hotspot_X;
    int draw_y = y - shape->shape_info[frame].Hotspot_Y;

    if ((fog_flag & 0x10) == 0x10) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0x00ff00ff, 0x28002800, 0xff00ff00, 0x00280028);
        shape->shape_draw(this->cur_render_area, draw_x, draw_y, frame, 0, 0);
        _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
        fog_next_shape = 0;
        return;
    }

    if ((fog_flag & 0x20) == 0x20) {
        _ASMSet_Shadowing(0x00ff00ff, 0x56005600, 0xff00ff00, 0x00560056);
    }

    if ((fog_flag & 0x80) == 0x80) {
        int c = fog_flag & 0x0f;
        int value = (((c << 16) + c) << 12) + 0x04000400;
        _ASMSet_Shadowing(0x00ff00ff, value, 0xff00ff00, value);
    }

    int one = 1;
    int zero = 0;
    if (this->map->fog_flag != 0 && vis == 0x80) {
        fog_next_shape = one;
    }

    if (draw2 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
        fog_next_shape = one;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);
        fog_next_shape = zero;
    }

    if ((fog_flag & 0xa0) != 0) {
        fog_next_shape = one;
    }

    if (draw1 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);
    }

    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
    fog_next_shape = zero;
}

// 00538D60 RGE_View::draw_terrain_obstruction_map
// view.cpp:4676-4707, 250 bytes, __thiscall
//
// Attempt log:
// - baseline: natural nested 4x4 obstruction-map draw with parameter reuse;
//   268 bytes and an 8-byte frame because the narrow obstruction result spilled.
// - widened the obstruction result to int; this recovered the original 250-byte
//   size/frame and the exact prologue plus pre-loop call sequence.
// - a positive `obstruction > 0` test recovered the original AND/JLE predicate.
// - local/parameter row-expression, declaration-scope, operand-order,
//   coordinate-term, and obstruction-shape variants emitted the same basin.
// - focused variant lab (18 natural setup/guard/coordinate spellings) found no
//   exact group; best remains 110 positional bytes (44%), 61 edit bytes.
// - paused: calls, stack cleanup, size/frame, and loop behavior align; remaining
//   drift starts at outer-loop LEA scheduling (original LEA/LEA/LEA versus the
//   compiler's early row add), then register/load ordering in the draw branch.
// - Session follow-up: canonical polymorphic TPanel context was retained;
//   named row and dead-frame-home reuse were duplicate probes.  The clean
//   source below preserves the natural parameter/field ownership and leaves
//   only the localized VC5 outer-loop LEA scheduling gap.
// Main-agent audit removed unused fake-size context and restored canonical
// draw-area ownership while retaining the ordinary nested obstruction loop.
// Matching-worker continuation: for-header, comma-sequenced, reversed-sum,
// and named row-base probes all emitted the same 250-byte basin.  The first
// remaining hunk is the outer-loop allocator choice: original computes the
// x*8 and x*4 LEAs before a separate row-sum LEA into EDX, while VC5 folds the
// row sum into ECX before those LEAs.  Calls, stack cleanup, layout, and the
// nested draw behavior remain aligned; retain the clean named-loop source.
// Fresh continuation: a distinct natural outer counter moves the first hunk
// past the x/y LEAs and improves the strict diff from 110 to 100 bytes; direct
// row, const-row, row-local, operand-order, register-hint, scoped-local,
// counted-for, and declaration-order variants otherwise remain duplicates.
// Final bounded best keeps the separate outer counter and scoped inner locals;
// the remaining blocker is the row-sum destination/register coloring at the
// first obstruction setup (original LEA into EDX versus rebuilt ADD into EAX).
// Fresh worker: direct/persistent row locals, inline row arithmetic, stdlib.h
// context, and a named tile_y4 all failed to improve the 100-byte basin (the
// named tile_y4 variant regressed to 110).  A focused eight-form natural setup
// lab found that assigning frame = tile_y + outer before the x/y offsets moves
// the emitted code to 100% block/call/size parity and only 2 positional bytes.
// Reordered/parenthesized y-coordinate terms were codegen duplicates; the
// remaining bytes are only the 00538E20 LEA SIB base/index order ([eax+ebx]
// original versus [ebx+eax] rebuilt).  Keep the row-first source as the best
// plausible reconstruction; no opaque register-forcing form was retained.
// Orch continuation: reversing both coordinate sums, grouping constants,
// materializing draw coordinates, widening offsets, and reversing each sum
// separately all emitted the same 250-byte basin.  ABI evidence supports the
// long shape_draw declaration; the only open drift remains two SIB bytes.


void RGE_View::draw_terrain_obstruction_map(
    int x, int y, TShape* shape, int frame, int tile_x, int tile_y)
{
    int outer;
    int tile_x4 = tile_x * 4;
    tile_y *= 4;

    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);

    TShape* obstruction_shape = rge_base_game->get_shape(0);
    for (outer = 0; outer < 4; ++outer) {
        int i = 0;
        frame = tile_y + outer;
        int x_offset = outer * 8;
        int y_offset = outer * 4;

        do {
            int obstruction = pathSystem.obstruction(i + tile_x4, frame);
            if (obstruction > 0) {
                obstruction_shape->shape_draw(this->cur_render_area,
                    x + 2 + x_offset,
                    y + 0x0D + y_offset,
                    obstruction - 1, 0, 0);
            }
            ++i;
            x_offset += 8;
            y_offset -= 4;
        } while (i < 4);

    }
}

// 00538E60 RGE_View::Get_Cursor_Position
// Source: view.cpp lines 4716-4741. 151 bytes. __thiscall, ret 0Ch.


int RGE_View::Get_Cursor_Position(tagPOINT& point, int offset_x, int offset_y) {
    GetCursorPos(&point);
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    if (draw_system->ScreenMode == 1) {
        ScreenToClient(draw_system->Wnd, &point);
        if (point.x > 0x7FFF)
            point.x -= 0x10000;
        if (point.y > 0x7FFF)
            point.y -= 0x10000;
    }
    point.x += offset_x;
    int new_x = point.x;
    point.y += offset_y;
    int new_y = point.y;

    if (new_x < this->render_rect.left || new_x > this->render_rect.right ||
        new_y < this->render_rect.top || new_y > this->render_rect.bottom)
        return 0;
    return 1;
}

// 00538F00 RGE_View::Pick_Tile (view.cpp:4748-4855, 301B)
// Converts screen-space coordinates to tile coordinates with isometric correction.
//
// Attempt log:
// - baseline: natural typed map/dimension ownership; 301B but VC5 used a 4B
//   push-local frame and a different early register coloring.
// - context/ABI/layout/declaration probes (canonical RGE_View/RGE_Map surface,
//   split declarations, and local ordering) were codegen duplicates.
// - binary stack evidence showed that VC5 homes bounding-coordinate outputs in
//   dead incoming-parameter slots. This is compiler allocation evidence, not a
//   reason to express source-level casts that overwrite parameter objects.
// - a focused 32-case natural-shape lab found only a diagnostic local-struct
//   variant with 301B/frame parity; it still diverged at the early view-top
//   register load and is not retained as source scaffolding.
// - this pass rechecked sum/order, map-pointer, declaration-scope, and six-way
//   local-order variants; they were duplicates or neutral.
// - a direct contiguous Map_Dims aggregate plus binary-observed output aliases
//   reached 301B/frame parity and 189B strict drift (88.98% shape), but the
//   parameter casts were compiler-steering rather than plausible living source;
//   aggregate initializer/order variants did not improve it and were rolled back.
// Main-agent audit restored four ordinary named bounding outputs and removed
// explicit parameter-home alias casts. Remaining gap is broad VC5 register/frame
// coloring, not an unresolved call set or bounding-box behavior.
// - continuation baseline revalidated the ordinary source at 283B (18B short).
// - staged dimension declaration/initializer and long-width probes were duplicate
//   or neutral; a separate named map-width/bx1/map-height order only moved one
//   diagnostic byte and worsened block shape.
// - a binary-backed two-int Map_Dims local restored the proven 8B frame and 301B
//   size; combining it with the observed parameter-home output aliases reached
//   189B strict drift / 88.98% shape. The alias/aggregate form remains diagnostic
//   only because it is compiler-steering rather than canonical source.
// - register-qualified view-top, a local map pointer, and aggregate declaration
//   reordering were codegen duplicates. Restored the natural named-dimension and
//   four bounding-output reconstruction; final validated lead is the same-TU
//   register/frame allocation around the early dimension loads.
// - ABI audit: declared the protected bounding helper with four int& outputs
//   and passed named locals by reference. The call now uses the original
//   ?get_tile_bounding_coords@RGE_View@@IAEXHHAAH000@Z relocation; frame and
//   emitted bytes stayed unchanged at 283B, so no lifetime variant was kept.
// - this pass tested natural two-slot dimension aggregates, scalar dimension
//   scratch reuse, declaration/assignment order, array storage, canonical
//   long map fields, and local map/reference aliases. The best diagnostic
//   shape was 301B/frame 8B/155 strict-drift bytes; its early dimension-load
//   register colors and later loop homes still differ. All probes were
//   restored to this ordinary named-dimension source.
// - continuation probes revisited a typed Map_Dims aggregate, natural helper
//   output owners, coordinate-local storage, and positive bound nesting. The
//   aggregate reached 301B/frame 8B/189 strict-drift bytes, but its early
//   divisor and register topology still differed. Policy-compliant exactness
//   was not found; the pinned named-dimension source is restored below.
// - worker pass: canonical tagRECT ownership for the +0x8C/+0x90 geometry,
//   full RGE_Map layout, nested positive bounds, explicit for-loop updates,
//   map-height/map-width output reuse, parameter-home aliases, canonical long
//   widths, and a map pointer local were tested. Geometry and map surfaces
//   were neutral; nested bounds reached size parity but lost block shape.
// - a dead map-width first helper output with split dimension declarations
//   reached 301B/frame 8B/155 strict drift and 56.14% exact blocks. Inline
//   dimension initialization gave the same result. An explicit <= branch
//   reached 153 drift bytes but reversed the observed branch shape, so it is
//   diagnostic only. Full parameter aliases were not better.
// - structured labs tested declaration order, helper output owner, and 512
//   ambient TU contexts. Eight codegen groups resulted; no exact result or
//   early view-top register recovery occurred. Ambient declarations changed
//   only later bytes and are not source evidence. Natural source is restored.
// - shape-priority continuation retained the binary-supported dead map_w first
//   output and the canonical long map dimensions. The natural while CFG is
//   301B with the original 8B frame, 90.68% shape, 56.14% exact blocks, and
//   155 strict drift bytes. The first mismatch is now the early view-top
//   register color at +0015, not the frame or function boundary.
// - explicit second-loop break and do-loop forms reached 151 strict drift and
//   92.24% shape with 116 instructions, but changed CFG from 9/4 to 10/3 and
//   reduced exact blocks to 53.51%. They are rejected as shape-only forms.
// - coordinate declaration/order, register qualification, long parameter
//   casts, canonical geometry ownership, and four local-order lab variants
//   did not recover the early colors. The natural while form remains current.
// - fresh exact-finish probes tested the decompiler-proven helper aliases:
//   map_height and the incoming long parameter homes receive the four bounding
//   outputs, while the found flag reuses col_out. Direct natural C++ casts
//   preserved the call target but emitted 283-287 bytes without the target's
//   8-byte frame. They were restored. The current source keeps the simpler
//   equivalent output locals until authentic source context supplies a better
//   allocation model.
// FLAGS: /nologo /c /O2 /Oy


int RGE_View::Pick_Tile(long px, long py, int* col_out, int* row_out) {
    int map_h;
    int map_w;
    int by1;
    int bx1;
    map_h = map->map_height;
    map_w = map->map_width;
    bx1 = (map_scr_x_offset - this->render_rect.left) + px;
    by1 = (map_scr_y_offset - this->render_rect.top) + py;

    if (bx1 < 0) {
        *col_out = -1;
        *row_out = -1;
        return 0;
    }

    if (bx1 >= map_w * tile_wid) {
        *col_out = map_w + 1;
        *row_out = map_h + 1;
        return 0;
    }

    int tcol = bx1 / tile_wid;
    int trow = by1 / tile_hgt;
    int diff = tcol - trow;
    tcol = tcol + trow;

    while (diff < 0 || tcol >= map_w) {
        tcol--;
        diff++;
    }

    while (diff >= map_h || tcol < 0) {
        tcol++;
        diff--;
    }

    int found = 1;
    do {
        int bound_row;
        int bound_top;
        int bound_left;
        get_tile_bounding_coords(tcol, diff, map_w,
                                 bound_row, bound_top, bound_left);
        if (by1 < bound_row) {
            tcol++;
            diff--;
        } else if (by1 > bound_left) {
            tcol--;
            diff++;
        } else {
            found = 0;
        }
    } while (found);

    tile_half_hgt = 0;
    tile_half_wid = 0;
    return 0;
}

// Worker pass sa-36bdddaa (2026-08-23):
// - The pinned natural source was restored after each probe.
// - Full TPanel/render_rect context, decompiler output aliases, map-local
//   declaration permutations, transform order, and period header context did
//   not recover the first ESI/ECX color mismatch.
// - Fresh validation remains a mismatch: 155 positional bytes, one direct
//   helper call, matching frame, and preserved loop and output behavior.
// - Anchor rechecks were blocked after another worker moved Add_GDI_Clip_Mask
//   from accepted_drift to matching while the TU resolver still names the old
//   path. No anchor source was changed here.

// 00539030 RGE_View::get_tile_bounding_coords
// view.cpp:4862-4947, 147 bytes, __thiscall, ret 18h


void RGE_View::get_tile_bounding_coords(int param_1, int param_2, int& param_3, int& param_4, int& param_5, int& param_6) {
    RGE_Tile* pRVar3 = this->map->map_row_offset[param_2];
    short sVar2 = pRVar3[param_1].screen_xpos;
    byte bVar1 = pRVar3[param_1].tile_type;
    param_3 = sVar2;
    param_5 = this->map->tilesizes[bVar1].width + sVar2 - 1;
    param_4 = pRVar3[param_1].screen_ypos - this->tile_half_hgt;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    param_6 = this->map->tilesizes[bVar1].height + param_4 - 1;
}

// 005390D0 RGE_View::pick_objects
// Attempt log:
// try 1-10: prior decompiler-shaped grid/object model was too short (674-688B) and
// used a fake pick_mask_test call; the binary actually walks prior_objs draw levels
// and calls RGE_View::sprite_check while maintaining sorted RGE_SPick_Info lists.
// probe 1 baseline: canonical ownership rewrite pending; prior source was not a
// behavior-backed reconstruction.
// probe 2: replaced the grid/object scaffold with the binary-backed draw-level
// scan, sprite_check call, free-list reuse, sorted insertion, and compact output;
// call set and size became structurally close.
// probe 3: removed artificial head[0] initialization; this recovered the
// compiler's overlapping count/list stack window and improved the diff.
// probe 4: separate validation guards, explicit level cursor, integer keep flag,
// and natural for loops recovered the 0x54 frame and many exact blocks.
// probe 5-7: tested declaration/context and a named pick_list_size[1..4] pointer;
// the contiguous member initialization improved resync similarity.
// probe 8: named all rectangle bounds reached exact size but worsened the
// register basin; restored direct canonical member expressions.
// probe 10: a named normalized hot_y lifetime worsened strict bytes; restored.
// probe 12: register total_picked was a codegen duplicate and was not retained.
// probe 14: paired entry hunk proved the original first test is x < 0; replacing
// the radius guard improved shape but worsened strict bytes and did not recover
// the pre-save x load. Restored the clean canonical source; first-hunk lead is
// exhausted without a natural typed declaration-order explanation.
// best retained check: 1048B rebuilt vs 1081B, 956 strict diff bytes, 65.98%
// shape similarity, exact frame/call set; remaining drift is broad prologue,
// register/liveness, and block-layout scheduling, not a call or layout blocker.
// worker pass: parameter-left upper viewport checks improve strict diff to 952
// bytes; coordinate aliases, scalar-home reuse, and ambient TU samples did not.


int RGE_View::pick_objects(int x, int y, int min_level, int max_level,
                           int radius, int priority, int skip_negative)
{
    RGE_SPick_Info* head[5];
    RGE_SPick_Info* tail[5];
    RGE_SPick_Info* freep[5];
    RGE_SPick_Info* found;
    RGE_SPick_Info* previous;
    RGE_SPick_Info* current;
    RGE_SPick_Info** head_ptr;
    DClipInfo_Node* node;
    int level;
    int confidence;
    int object_id;
    int selected_level;
    short draw_level;
    int i;
    int keep;
    int total_picked = 0;
    int* pick_sizes;

    if (radius < 0) {
        return 0;
    }
    if (max_level < min_level) {
        return 0;
    }
    // BINARY NOTE: The shipped code compares upper bounds with the parameter left.
    if (x < this->render_rect.left || x > this->render_rect.right ||
        y < this->render_rect.top || y > this->render_rect.bottom) {
        return 0;
    }
    if (0x28 < min_level || max_level < 0) {
        return 0;
    }

    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > 0x28) {
        max_level = 0x28;
    }

    y -= this->render_rect.top;
    x -= this->render_rect.left;

    pick_sizes = this->pick_list_size + 1;
    pick_sizes[0] = 0;
    pick_sizes[1] = 0;
    pick_sizes[2] = 0;
    pick_sizes[3] = 0;

    freep[1] = 0;
    freep[2] = 0;
    freep[3] = 0;
    freep[4] = 0;
    tail[1] = 0;
    tail[2] = 0;
    tail[3] = 0;
    tail[4] = 0;
    head[1] = 0;
    head[2] = 0;
    head[3] = 0;
    head[4] = 0;

    level = max_level;
    do {
        if (level < min_level) {
            int output_level = 1;
            head_ptr = head + 1;
            for (; output_level < 5; ++output_level, ++head_ptr) {
                current = *head_ptr;
                if (current != 0) {
                    RGE_Pick_Obj_Info* output = &Picked_Objects[total_picked];
                    do {
                        output->object_id = current->object_id;
                        output->confidence = current->confidence;
                        output->draw_level = current->draw_level;
                        output->draw_x = current->draw_x;
                        output->draw_y = current->draw_y;
                        ++total_picked;
                        ++output;
                        current = current->next;
                    } while (current != 0);
                }
            }
            return total_picked;
        }

        node = this->prior_objs->Draw_Level_Head[level];
        for (; node != 0; node = node->NextOnLevel) {
            confidence = 0;
            if (node->Node_Type == 0 &&
                (skip_negative == 0 || node->Object_ID >= 0)) {
                int node_y1 = node->y1;
                int node_x2 = node->x2;
                if (x < node->x1 - radius ||
                    y < node_y1 - radius ||
                    radius + node_x2 < x ||
                    node->y2 + radius < y) {
                    confidence = 0;
                } else {
                    confidence = 4;
                    if (node->x1 <= x && node_y1 <= y &&
                        x <= node_x2 && y <= node->y2) {
                        confidence = 3;
                        if ((node->Draw_Flag & 2) == 2) {
                            node_x2 -= x;
                        } else {
                            node_x2 = x - node->x1;
                        }
                        int mask = this->sprite_check(
                            node->Shape_Base, node->Shape,
                            node_x2, y - node_y1);
                        if (mask == 1) {
                            confidence = 2;
                        } else if (mask == 2) {
                            confidence = 1;
                        }
                    }
                }
            }

            if (confidence != 0 && confidence <= priority) {
                draw_level = node->y3;
                object_id = node->Object_ID;
                keep = 1;
                found = 0;
                int picked_level = 1;
                head_ptr = head + 1;
                do {
                    if (found == 0) {
                        current = *head_ptr;
                        if (current != 0) {
                            do {
                                if (current->object_id == object_id) {
                                    found = current;
                                    selected_level = picked_level;
                                    break;
                                }
                                current = current->next;
                            } while (current != 0);
                        }
                    }
                    ++picked_level;
                    ++head_ptr;
                } while (picked_level < 5);

                if (found != 0) {
                    if (selected_level < confidence ||
                        (selected_level == confidence &&
                         draw_level < found->draw_level)) {
                        keep = 0;
                    }

                    if (keep) {
                        if (head[selected_level] == found) {
                            head[selected_level] = found->next;
                        }
                        if (tail[selected_level] == found) {
                            tail[selected_level] = found->prev;
                        }
                        if (found->next != 0) {
                            found->next->prev = found->prev;
                        }
                        if (found->prev != 0) {
                            found->prev->next = found->next;
                        }
                        found->next = freep[selected_level];
                        found->prev = 0;
                        freep[selected_level] = found;
                    }
                }

                if (keep) {
                    current = freep[confidence];
                    if (current == 0) {
                        i = this->pick_list_size[confidence];
                        if (i == 0x40) {
                            keep = 0;
                        } else {
                            current = this->pick_lists[confidence] + i;
                            this->pick_list_size[confidence] = i + 1;
                        }
                    } else {
                        freep[confidence] = current->next;
                    }

                    if (keep) {
                        current->object_id = object_id;
                        current->confidence = (short)confidence;
                        current->draw_level = draw_level;
                        current->draw_x = (short)node->Draw_X;
                        current->draw_y = (short)node->Draw_Y;
                        head_ptr = head + confidence;
                        current->next = 0;
                        current->prev = 0;
                        found = *head_ptr;
                        if (found == 0) {
                            *head_ptr = current;
                            tail[confidence] = current;
                        } else {
                            do {
                                if (found->draw_level <= draw_level) {
                                    current->next = found;
                                    previous = found->prev;
                                    current->prev = previous;
                                    if (previous == 0) {
                                        *head_ptr = current;
                                        found->prev = current;
                                    } else {
                                        current->prev->next = current;
                                        found->prev = current;
                                    }
                                    break;
                                }
                                previous = found->next;
                                if (previous == 0) {
                                    found->next = current;
                                    current->prev = found;
                                    tail[confidence] = current;
                                    break;
                                }
                                found = previous;
                            } while (found != 0);
                        }
                    }
                }
            }

        }
        --level;
    } while (true);
}

// VA: 00539510 RGE_View::sprite_check
// view.cpp lines 5238-5347
// CANONICAL OWNER: this accepted-drift body is the only compiler-facing
// definition for VA 00539510. The historical src/scratch path was renamed
// here in commit 9a8c9ac3. Caller-only declarations in matching and scratch
// pick-object sources do not own this symbol. This target is not included by
// this direct source, so it has no wrapper owner.
// Attempt log:
// prior worker: natural switch source produced inline early returns and wrong info
// register (ESI not EDI), 86.9% positional diff.
// prior worker: shared labels/goto and explicit base/si locals moved the CFG but
// still colored info/base incorrectly; /O1, /Ox, /Ob0 did not help.
// probe 1 hypothesis: remove compiler-steering aliases and use the ordinary
// parameter/member expressions with a top-tested while loop.
// continuation: the exact Shape.cpp decoder donor uses a width-tested loop
// with a top x guard, and orders arms as 0-group, 2, 1-group, 3, then 6+.
// Restoring that source family, plus named rowtab/data-offset pointers,
// improved the size-preserving result from 303 to 277 strict bytes.
// register hints and a combined opcode read were duplicates; using shape as
// the cursor worsened the result. Keep the typed donor-shaped reconstruction.
// probe 2: combined width/x loop gate plus byte opcode; size moved closer but
// VC5 added an extra opcode reload and kept the parameter registers swapped.
// probe 3: split opcode read/increment; emitted code was unchanged.
// probe 4: explicit width-exhaustion return and separate switch-default tail
// restored exact size, but VC5 inverted the two identical return-1 blocks.
// probe 5: explicit ret0/ret1/default labels improved CFG coverage only.
// probe 6: infinite-loop/top-guard form removed the duplicated x check but
// shortened the function; probe 7 returned to the natural nested while form.
// probe 8: donor-era <memory.h> context was codegen-neutral here.
// probe 9: register annotation on info was codegen-neutral.
// probe 10: opcode type/read/switch variant lab found no exact or register-color
// lead; best invariant group retained the same info=ESI/shape=EDI basin.
// continuation probes: a separate next-cursor across each decoder arm worsened
// the structural diff; direct-info ownership, local declaration reordering, and
// parameter-home byte-store variants all emitted the 277-byte clean basin.
// probe 11: an early named shape_base alias was a natural liveness test for
// the oracle's ESI base/EDI info ownership; VC5 emitted identical code, so it
// was rolled back.
// continuation probes: a period-like TPanel base and protected/full virtual
// RGE_View surface improved only SIB bytes (275/274 diff), not register colors.
// A widened int opcode local reached a shorter 396-byte basin (260 diff), but
// retained EAX as the opcode and was not a natural exact reconstruction.
// A helper extraction did not inline and added a direct call. A const info
// pointer changed the decorated owner symbol. A 128-sample ambient declaration
// sweep produced no exact result; all variants kept the swapped pointer colors.
// Final clean source remains the typed decoder below. Next useful evidence is
// the original view.cpp class/TU context or a matching register-color donor.
// historical scratch state: canonical typed decoder and exact size/CFG family are
// reconstructed, but VC5 still colors info/shape opposite the oracle and emits
// a byte-opcode reload plus distinct return-tail drift. Not accepted_drift-safe.
// revisit: direct canonical Shape_Info field widths, scoped opcode/stream
// locals, and a branch-local shape-base alias all emitted the same 413-byte,
// 277-byte-diff basin. The next useful evidence remains the original view.cpp
// translation-unit context; retain this clean natural decoder.
// revisit validation: protected access matches the original IAEH decorated
// symbol but does not change body codegen. A decompiler-shaped while(start <= x)
// rewrite worsened the result to 282 bytes; restore the typed 277-byte basin.
// Accepted-drift audit: all coordinate and outline guards, row-table reads,
// opcode groups, extended-count reads, stream advances, width tests, and
// returns match. The function has no calls or non-stack writes. Malformed
// streams cause the same ordered reads. Remaining drift is private register
// coloring, return-tail placement, and internal switch-table placement.



int RGE_View::sprite_check(uchar* shape, Shape_Info* info, int x, int y)
{
    int width;
    int start;
    int right_pad;
    uchar* p;
    uchar code;
    unsigned int n;
    Shape_Info* shape_info = info;

    if (shape_info != 0) {
        if (x >= 0) {
                    width = shape_info->Width;
            if (x < width) {
                if (y >= 0) {
                    if (y < shape_info->Height) {
                        uchar* outline = shape + shape_info->Shape_Outline_Offset;
                        start = *(short*)(outline + y * 4);
                        right_pad = *(short*)(outline + y * 4 + 2);
                        if (start >= 0) {
                            if (x >= start) {
                                if (x <= width - right_pad) {
                                    int* data_offsets = (int*)(shape + shape_info->Shape_Data_Offsets);
                                    p = shape + data_offsets[y];
                                    if (start < width) {
                                        while (start < width) {
                                            if (x < start) {
                                                return 1;
                                            }
                                        code = *p++;
                                        switch (code & 0x0F) {
                                            case 0:
                                            case 4:
                                            case 8:
                                            case 12:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 2:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 1:
                                            case 5:
                                            case 9:
                                            case 13:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                break;
                                            case 3:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                break;
                                            case 6:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 7:
                                            case 10:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p++;
                                                break;
                                            case 11:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                break;
                                            case 14:
                                            case 15:
                                                goto ret0;
                                            default:
                                                return 1;
                                            }
                                        }
                                    }
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
ret0:
    return 0;
ret2:
    return 2;
}

// 005396F0 RGE_View::pick_multi_objects
// Attempt log:
// current pass: canonicalized the local world, master, player, and object
// overlays to the repository names and proven field ownership; matched the
// protected member access from the original decorated symbol. Split the
// viewport and level guards to follow the PDB bands; VC5 emitted the same
// 566-byte body.
// tested a loop-scoped object-id lifetime through duplicate suppression and
// output; it grew to 571B with a 0x10 frame and was restored. A canonical
// TPanel-base view surface moved 2 bytes farther and was restored.
// initial decompiler-shaped source from packet: behavior/field offsets plausible but broad mismatch; VC5 chose EBP=this and ECX=count while original has EBX=this and EBP=count.
// added local self alias and register num_picked; no register allocation improvement.
// changed early returns to shared goto fail; improved positional diff from 88.69% to 70.85% by avoiding inline early-return epilogues, kept.
// tried /O2 /Oy /Ob0; no codegen change from default, removed custom flag.
// tried /O1 /Oy; function shrank to 454B and failed section-size check, removed custom flag.
// tried /O2 /Oy /Og-; generated EBP frame and much worse 92.93% diff, removed custom flag.
// tried explicit self alias throughout instead of direct member access; no prologue/register improvement but kept as part of current best shared-fail source.
// tried register num_picked to force EBP=count; VC5 still used ECX for count and EBP for this.
// local/global layout facts verified against asm: RGE_View +8c/+90/+94/+98 bounds, +fc world, +334 prior_objs; DClipInfo_Node +4 next, +8 object id, +2c type, +30..+36 bounds, +14/+18 draw coords; object +48 state, master +8d select_level.
// left in scratch: remaining mismatch is not accepted-drift-safe. Current default build has correct broad behavior but wrong callee-saved register topology and block layout: original starts `push ebx; mov ebx,ecx; push ebp; push esi; xor ebp,ebp`, uses shared far fail epilogue at end, and later restores EBX/EBP around inner loops; rebuilt starts `push ebx; push ebp; mov ebp,ecx; ... xor ecx,ecx`, uses earlier fail block, and cascades broad branch/register differences.
// matching-worker probes: one short-circuit bounds guard plus the in-loop z<min return improved CFG/shape but not bytes; the typed RGE_Pick_Obj_Info global was codegen-neutral.
// matching-worker probe: natural RGE_Pick_Obj_Info output ownership recovered EBX=this and exact size, but retained a broad register/global-address mismatch; entry-plus-confidence cursor and field-cursor variants were worse or duplicate.
// matching-worker probes: reusing max_level as the node object-id home (with local or direct object expressions) caused a larger frame and broad regression; rolled back because the stack write can be compiler local-home reuse rather than source parameter mutation.
// matching-worker probe: restored the typed view.cpp donor context with an RGE_View : TPanel surface; VC5 emitted a codegen duplicate, so the prior clean source remains.
// matching-worker probe: moved the proven z>=min_level test outside the descending loop, matching the original pre-loop compare and shared count-return path; emitted code was an exact duplicate with no metric movement.
// matching-worker probe: a natural do-while duplicate scan removed the repeated output-pointer loop test; size reached 566B and strict diff improved to 420B, but register coloring remained broad.
// matching-worker diagnostics: direct confidence-field cursor plus the do-while scan reached 566B/417B, but raw field-pointer writes were rolled back in favor of the typed record source.
// matching-worker probes: self alias and register-qualified count were codegen duplicates; split record/confidence aliases regressed to 482B.
// final bounded best: natural typed record output, split viewport/level
// guards, and do-while duplicate scan; 566 rebuilt bytes, 420 strict diff,
// 72.09% shape, 34.30% exact-block coverage. Remaining drift is broad VC5
// register/block topology and global-address relocation, not safe localized drift.
// Main review replaced manual vptr fields with typed virtual ownership.
// matching-worker pass: same-TU draw_view proves the four +8c fields are one
// render_rect aggregate; this changed source ownership but was codegen-neutral.
// The target LEA/store pattern anchors the output cursor at confidence (+4),
// so the retained cursor is short* with a six-short stride and the object id
// store four bytes before it. This reduced strict diff to 417B at exact size.
// Tested node-id reuse through max_level: 566B/412B but a 0x10 frame and broad
// CFG loss; restored. Named bounds locals, absolute global, typed cursor alias,
// and declaration-order variants were worse or duplicates and were restored.
// Final claim validation: 566B, 0xC frame, 72.09% shape, 34.30% exact blocks,
// 417 strict diff; no accepted-drift proposal. Remaining register/block drift
// is broad and not policy-safe to call localized equivalent behavior.


int RGE_View::pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag)
{
    int num_picked = 0;
    int z;
    if (x2 < this->render_rect.left || x1 > this->render_rect.right ||
        y2 < this->render_rect.top || y1 > this->render_rect.bottom)
        return 0;
    if (min_level > 40 || max_level < 0)
        return 0;
    if (min_level < 0) min_level = 0;
    if (max_level > 40) max_level = 40;

    x1 -= this->render_rect.left;
    x2 -= this->render_rect.left;
    y1 -= this->render_rect.top;
    y2 -= this->render_rect.top;

    z = max_level;
    if (z >= min_level) {
        do {
            DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[z];
            if (node != 0) {
                // BINARY NOTE: the cursor names the confidence word at +4.
                short* out = &Picked_Objects[num_picked].confidence;
                do {
                    int ok = 0;
                    if (node->Node_Type == 0) {
                        int object_id = node->Object_ID;
                        if (object_id >= 0) {
                            if (x1 <= (int)node->x2 && x2 >= (int)node->x1 &&
                                y1 <= (int)node->y2 && y2 >= (int)node->y1) {
                                RGE_Static_Object* obj = this->world->objectsValue[object_id];
                                if (player_id == -1 || obj->owner->id == player_id) {
                                    if (obj->object_state == 2 && obj->master_obj->select_level >= select_level) {
                                        ok = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (ok != 0) {
                        int add = 1;
                        if (out > &Picked_Objects[0].confidence) {
                            int i = 0;
                            RGE_Pick_Obj_Info* p = Picked_Objects;
                            do {
                                if (p->object_id == node->Object_ID) {
                                    add = 0;
                                    if ((short)ok < Picked_Objects[i].confidence) {
                                        Picked_Objects[i].confidence = (short)ok;
                                    }
                                    break;
                                }
                                i++;
                                ++p;
                            } while (i < num_picked);
                        }
                        if (add) {
                            // BINARY NOTE: object_id is the dword before confidence.
                            *((int*)(out - 2)) = node->Object_ID;
                            out[0] = (short)ok;
                            out[1] = (short)ok;
                            out[2] = node->Draw_X;
                            out[3] = node->Draw_Y;
                            num_picked++;
                            out += 6;
                        }
                        if (out >= &Picked_Objects[64].confidence) return 0x40;
                    }
                    node = node->NextOnLevel;
                } while (node != 0);
            }
            z--;
        } while (z >= min_level);
    }
    return num_picked;
}

// VA: 00539930 RGE_View::pick_touched_object
// Source: view.cpp lines 5477-5550
// Attempt log:
// initial natural nested bounds/level scan from packet.
//
// BINARY NOTE: PDB names this owner RGE_View::pick_touched_object.
// BINARY NOTE: The body is 00539930-00539A94. Padding follows to 00539AA0.
// BINARY NOTE: PDB order puts this normal sibling after 005396F0.
// BINARY NOTE: 005396B0 has no PDB function entry. Treat it as data.
// BINARY NOTE: Both direct calls target the protected RGE_View::sprite_check.
// BINARY NOTE: The out-of-line 00539510 definition remains the canonical owner.
//
// Exact-finish note:
// The natural source matches 357 bytes and 109 instructions.
// Removing the x2 local changed 202 bytes and reduced the body to 353 bytes.
// The x2 local is required for the original load and register schedule.


int RGE_View::pick_touched_object(DClipInfo_List* list, int x, int y, int min_level, int max_level, int& out_object_id)
{
    out_object_id = 0;
    if (max_level >= min_level &&
        x >= this->render_rect.left && x <= this->render_rect.right &&
        y >= this->render_rect.top && y <= this->render_rect.bottom &&
        min_level <= 0x28 && max_level >= 0) {
        if (min_level < 0) {
            min_level = 0;
        }
        if (max_level > 0x28) {
            max_level = 0x28;
        }
        int found = 0;
        int level = max_level;
        if (level >= min_level) {
            do {
                DClipInfo_Node* node = list->Draw_Level_Head[level];
                if (node != 0) {
                    do {
                        if (node->Node_Type == 0) {
                            int flags = node->Draw_Flag;
                            int x1 = node->x1;
                            int y1 = node->y1;
                            int x2 = node->x2;
                            if ((flags & 2) == 2) {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x2 - x, y - y1) == 2) {
                                    found = 1;
                                    out_object_id = node->Object_ID;
                                }
                            } else {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x - x1, y - y1) == 2) {
                                    found = 1;
                                    out_object_id = node->Object_ID;
                                }
                            }
                        }
                        node = node->NextOnLevel;
                    } while (node != 0);
                }
                if (found == 1) {
                    return 1;
                }
                level--;
            } while (level >= min_level);
        }
    }
    return 0;
}

// 00539AA0 protected RGE_View::get_tile_picture
// PDB: view.cpp:5559-5610, ?get_tile_picture@RGE_View@@IAEFEEFF@Z.
// Body: 00539AA0-00539B8D. Padding: 00539B8E-00539B8F. Next: 00539B90.
// BINARY NOTE: The original writes rows and cols to the byte parameter homes.
// This source reuses those parameters for modulo remainders and preserves fault order.
// Exact-finish note: public access kept bytes exact but lost the PDB access qualifier.


short RGE_View::get_tile_picture(unsigned char param_1, unsigned char param_2, short param_3, short param_4) {
    RGE_Tile_Set* ts = &this->map->terrain_types[param_1];
    if (ts->shape == 0) return -1;

    RGE_TOB_Picts* tile = &ts->tiles[param_2];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        unsigned char rows = (unsigned char)ts->rows;
        unsigned char cols = (unsigned char)ts->cols;
        param_1 = rows;
        param_2 = cols;
        if (rows > 1 || cols > 1) {
            if (rows > 0) param_1 = (unsigned char)(param_4 % rows); else param_1 = 0;
            if (cols > 0) param_2 = (unsigned char)(param_3 % cols); else param_2 = 0;
            result = (unsigned short)param_1 * (unsigned short)cols + (unsigned short)param_2;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}

// 00539B90 RGE_View::get_border_picture
// PDB: view.cpp:5617-5671, ?get_border_picture@RGE_View@@IAEFEEEFF@Z.
// Body: 00539B90-00539C7E. Padding: 00539C7F. Next: 00539C80.
// BINARY NOTE: The protected access is part of the PDB-qualified member ABI.
// Exact-finish note: public access kept bytes exact but emitted the QAE symbol;
// the protected declaration is retained for the original IAE symbol.
// 239 bytes, __thiscall
// short get_border_picture(uchar terrain_type, uchar row_idx, uchar col_idx, short param_4, short param_5)


short RGE_View::get_border_picture(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5) {
    RGE_Border_Set* bt = &this->map->border_types[param_1];
    if (bt->shape == 0) return -1;

    RGE_TOB_Picts* tile = &bt->borders[param_2 - 1][param_3 + 0xB];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        short style = bt->border_style;
        if ((style == 0 && (param_3 == 0xB || param_3 == 0xC)) ||
            (style == 1 && (param_3 == 0x3 || param_3 == 0x2))) {
            result = param_5 % tile->count;
        } else if ((style == 0 && (param_3 == 0x9 || param_3 == 0xA)) ||
                   (style == 1 && (param_3 == 0x1 || param_3 == 0x4))) {
            result = param_4 % tile->count;
        } else {
            result = 0;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}

// 00539C80 RGE_View::get_border_edge_pictures
// PDB: view.cpp:5677-5703, ?get_border_edge_pictures@RGE_View@@IAEHEEEFFAAH000@Z.
// Body: 00539C80-00539D83. Padding: 00539D84-00539D8F. Next: 00539D90.
// 260 bytes, __thiscall, protected member with four int& outputs.
// BINARY NOTE: Output stores occur before the map shape read.
// BINARY NOTE: The four calls keep the protected get_border_picture ABI.
// int get_border_edge_pictures(uchar terrain_type, uchar row_idx, uchar edge_mask, short param_4, short param_5, int& out1, int& out2, int& out3, int& out4)


int RGE_View::get_border_edge_pictures(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5, int& param_6, int& param_7, int& param_8, int& param_9) {
    param_6 = -1;
    param_8 = -1;
    param_7 = -1;
    param_9 = -1;

    if (this->map->border_types[param_1].shape && param_3) {
        if (param_3 & 1) {
            short s = this->get_border_picture(param_1, param_2, 1, param_4, param_5);
            param_6 = (int)s;
        }
        if (param_3 & 2) {
            short s = this->get_border_picture(param_1, param_2, 4, param_4, param_5);
            param_9 = (int)s;
        }
        if (param_3 & 4) {
            short s = this->get_border_picture(param_1, param_2, 3, param_4, param_5);
            param_8 = (int)s;
        }
        if (param_3 & 8) {
            short s = this->get_border_picture(param_1, param_2, 2, param_4, param_5);
            param_7 = (int)s;
        }
        return 1;
    }
    return 0;
}

// 00539D90 RGE_View::hit_tile (view.cpp:5709-5753, 300B)
// Tests if the given screen-space point hits the visible tile area.
//
// Attempt log:
//   baseline: existing flat/member-source reconstruction was 408B (diff 396).
//   control-flow: positive nested bounds/terrain guards reached 300B (diff 271).
//   liveness/layout: conditionally assign tile_type in the null arm and use
//     signed short locals; this recovered the original BP terrain, DX tile,
//     incoming tile-home reuse, and exact entry bytes.
//   context: canonical RGE_View:TPanel surface and exact donor call symbols.
//   final layout: map-local tilesize ownership plus tilesizes[tile_type] fixed
//     the +4 folded base-index fact. Current best is 283B, strict diff 173,
//     shape 92.52%, with 85.98% exact-block coverage.
// Left in scratch after the bounded pass: the remaining drift begins at the
// first failure-branch displacement; original extracts tile_type before the
// map load and places the shared success/failure tails 17 bytes later.
// Main-agent audit replaced numbered/decompiler map and tile types plus the raw
// vptr field with canonical polymorphic RGE_Map ownership; metrics are unchanged.
//   continuation: direct this->map tilesize expressions, with the map local
//   delayed until after the screen bounds, recovered the original movsx-before-
//   map load.  Explicit labels retain the binary-proven separate shape-success,
//   outer-success, and shared-failure tails; this source now matches exactly.
// FLAGS: /nologo /c /O2 /Oy


int RGE_View::hit_tile(RGE_Tile* tile, short sx, short sy,
                        short a, short b, tagPOINT* pt)
{
    short terrain_type = 0;
    short tile_type;

    if (tile) {
        tile_type = tile->tile_type;
        terrain_type = tile->terrain_type & 0x1F;
    } else {
        tile_type = 0;
    }

    if (pt->x >= sx) {
        if (pt->x < sx + this->map->tilesizes[(int)tile_type].width &&
            pt->y >= sy &&
            pt->y < sy + this->map->tilesizes[(int)tile_type].height) {
            RGE_Map* map = this->map;
            if (terrain_type < map->num_terrain &&
                map->terrain_types[terrain_type].loaded) {
                TShape* sh = map->terrain_types[terrain_type].shape;
                short pic = this->get_tile_picture(terrain_type, (unsigned char)tile_type, a, b);

                if (sh == 0 || pic == -1)
                    goto outer_success;

                if (pt->y >= sy + this->map->tilesizes[(int)tile_type].height)
                    goto failure;
                if (!sh->shape_check(pt->x - sx, pt->y - sy, pic))
                    goto failure;
                goto shape_success;

            shape_success:
                return 1;
            outer_success:
                return 1;
            failure:
                return 0;
            }
            return 1;
        }
    }

    return 0;
}

// 00539EC0 RGE_View::hit_object
// Attempt log:
// initial natural decomp from packet produced same 517B size but broad shifted mismatch; frame was too small (0x10 vs 0x1c).
// hoisted get_frame temporaries to function scope; recovered original 0x1c frame and prologue through the first local-zero store.
// tried adding point/local aliases for parameter liveness; no improvement, kept only x/y aliases because they preserve param register loads.
// tried while-loop form instead of do/while; object grew/shrank badly and failed size-section check, rolled back.
// tried delayed cur assignment after first-null test; worsened early store/check scheduling, rolled back.
// tried signed char mode local vs unsigned mode local; no byte change.
// tried direct this->function_mode tests instead of a mode local; no byte change.
// tried /O1 custom flags; .text too small / wrong size, removed flag.
// tried /O2 /Oy /Og- custom flags; produced EBP frame and much worse diff, removed flag.
// tried combining picked-owner/select-level tests into && expressions; no byte change.
// left in scratch: behavior/calls/stack cleanup look plausible, but loop prologue scheduling differs: original stores sort result in two stack slots, loads x/y/point params, then enters loop; rebuilt hoists first node load/test before those param loads and uses different save-list stack slots (+1c/+28 vs original +20/+1c).
// session sa7b331c8e_r1 baseline: current natural candidate rebuilt at 517B/0x1c frame, diff 440; checker stage was structural reconstruction.
// changed special-mode source to a natural plus/comma-owner if/else; ordered box/select/hit calls then aligned 6/6 and diff reached 384 at 517B.
// removed the redundant pre-loop cursor guard (duplicate codegen); delayed cursor declaration worsened the prologue and was restored.
// swapped retained cleanup-head and loop-cursor roles; cursor now uses the oracle's +1c home, but VC5 keeps the retained head at +28 instead of oracle +20.
// corrected stat_obj donor ABI: hit_test takes five shorts and get_frame takes four short references; call relocation spellings now agree without code movement.
// modeled the binary-proven get_frame window with dword local_4 and the tile parameter home; the third-output LEA at +12 matches, but the initial node load still precedes oracle parameter preloads.
// bounded session exhausted at 10 meaningful hypotheses; leave this readable typed reconstruction in scratch. Remaining lead: recover the original list-head +20 home and parameter-preload loop scheduling before any register tuning.
// tried splitting the natural mode/owner collision predicate; call sites and block shape diverged badly, rolled back to the clean source.
// moved natural x/y aliases before the first-node guard; VC5 emitted duplicate code, so restored the clean reconstruction.
// natural for-condition with typed node assignment recovered 96% exact blocks but shifted the select-level compare; kept as the new source shape.
// reversed the select-level comparison to load the master object first; diff fell to 10 bytes with exact CFG and calls.
// direct comma-mode gating was behavior-plausible but lost size and block parity; rolled back.
// duplicated the ordinary hit arm was structurally poor; rolled back.
// retained the binary-backed ordinary-hit label join for mode '+' and non-special modes; exact 517B match.


extern "C" void __cdecl free(void*);

RGE_Static_Object* RGE_View::hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                        tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                        RGE_Static_Object* skip, unsigned char through_fog)
{
    short min_x;
    int local_4;
    RGE_Object_Node* first;
    short min_y;
    short max_y;
    RGE_Static_Object* picked = 0;
    if (&tile->objects != 0) {
        first = tile->objects.sort();
        RGE_Object_Node* cur = first;
        short sx = x;
        short sy = y;
        RGE_Static_Object* obj;
        for (; cur != 0 && (obj = cur->node) != 0; cur = cur->next) {
                if (obj->object_state < 7) {
                    if ((!through_fog || obj->master_obj->fog_flag) &&
                        obj->master_obj->select_level >= this->function_parm) {
                        if (this->function_mode == '+' || this->function_mode == ',') {
                            if (obj->owner == this->player) {
                            if (this->function_mode == ',') {
                                if (obj->box_hit_test(sx, sy, (short)p2->x, (short)p2->y,
                                                      (short)p1->x, (short)p1->y)) {
                                    if (!this->player->select_one_object(obj, 0)) break;
                                    picked = obj;
                                }
                            } else {
                                goto ordinary_hit;
                            }
                            }
                        } else {
ordinary_hit:
                            if (obj->hit_test(sx, sy, (short)p1->x, (short)p1->y, 5)) {
                            if (skip != 0 && obj == skip && picked != 0) {
                                return picked;
                            }
                            if (picked != 0 && obj->owner != this->player && picked->owner == this->player) goto next;
                            if (picked != 0 && obj->master_obj->select_level < picked->master_obj->select_level) goto next;
                            {
                                picked = obj;
                                if (!obj->get_frame(min_y, (short&)local_4, min_x, max_y)) {
                                    min_y = 0;
                                    local_4 = 0;
                                }
                                *out_x = (short)(obj->screen_x_offset + min_y + sx);
                                *out_y = (short)(obj->screen_y_offset + (short)local_4 + sy);
                            }
                            }
                        }
                    }
                }
next:
                ;
        }
        while (first != 0) {
            RGE_Object_Node* next_node = first->next;
            free(first);
            first = next_node;
        }
    }
    return picked;
}

// VA: 0053A0D0 RGE_View::start_scroll_view
// PDB: view.cpp:5854-5914
// Fresh reconstruction: the pick result is the period RGE_Pick_Info object;
// the view owns the mouse-down and scroll fields at their proven offsets.
// Prior worker notes remain useful evidence: the former volatile stub forced
// the right frame but did not reproduce the source-level register schedule.
//
// Attempt log (normal-53A0D0-r1):
// 1: natural typed Pick_Info and named view fields: 397 B, 16 calls, 4 fewer returns.
// 2: delayed result initialization: codegen duplicate.
// 3: reused the action parameter as the zero result: codegen duplicate.
// 4: volatile result restored four returns and reached 421 B; retained as diagnostic.
// 5: declaration-order change: codegen duplicate.
// 6: saved action local: codegen duplicate.
// 7: volatile action local: 425 B and worse block coverage; rolled back.
// 8: register-qualified action local: codegen duplicate; rolled back.
// 9: reused result for the first converted coordinate: 441 B, 335 strict diff.
// 10: reversed conversion order: 437 B, 338 strict diff; exact-codegen stage.
// Final: restored the clean natural source. Remaining lead is result-home and
// action-register scheduling. Diagnostic volatile forms are not retained.
// 11: use one saved action value for dispatch and scroll state; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the natural baseline remains.
// 12: direct final return instead of a synthetic result local; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the baseline was restored.
// 13: delayed result assignment remained a codegen duplicate.
// 14: volatile result plus saved action restored the target prologue, four
//     returns, and 437-byte size; result-home argument reload was one extra.
// 15: plain result removed that structure; rolled back.
// 16: hoisted col/row locals were a duplicate; rolled back.
// 17: plain col with volatile final result reached 421 B / 414 diff.
// 18: cached the volatile y conversion into plain col; reached 429 B / 66 diff.
// 19: a raw local read at +8 reached 437 B / 2 diff with exact calls,
//     returns, and all other bytes aligned. It has no proven field ownership.
// 20: named first view-y value was a codegen duplicate.
// 21: offset +4 collapsed the distinct late expression and regressed to 66.
// 22: alternate alias spelling also regressed to 66; restored the offset +8
//     diagnostic form as the best binary-supported reconstruction.
// 23: normalized the living source by removing codegen-only volatile/register
//     scheduling and the raw +8 read. Close scheduling evidence remains in
//     checkpoint probe-026.
// 24: restored the reviewed virtual ABI: start_scroll_view is vt[58], and the
//     full same-TU TPanel surface owns its fields through +0xF4. Body codegen
//     stayed in the natural 405-byte / 418-byte-diff basin.
// 25: a switch dispatch regressed ordered calls and was rolled back.
// 26: direct coordinate casts, delayed result assignment, a saved action local,
//     and positive success guards were codegen duplicates of the natural source.
// 27: model the return as a natural state result: declare it without an
//     initializer, assign zero after the action-specific branches, assign one
//     in the final success arm, and return it once. This gives an exact 437 B
//     MATCH with the canonical TPanel/RGE_View ABI and no codegen-only tricks.


int RGE_View::start_scroll_view(unsigned char action, long x, long y,
                                int p4, int p5)
{
    RGE_Pick_Info pick_info;
    int result;

    if (action == 3) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) != 0x33) {
            return 0;
        }
        long col = (long)pick_info.y;
        long row = (long)pick_info.x;
        this->set_selection_area(row, col, row, col);
    } else if (action == 9) {
        this->pick(0x28, 0, x, y, &pick_info, 0);
        this->real_old_map_col = (long)pick_info.x;
        this->real_old_map_row = (long)pick_info.y;
        if (!this->do_paint(x, y, x, y, 1)) {
            return 0;
        }
        this->set_redraw((TPanel::RedrawMode)1);
    }

    result = 0;
    this->scroll_action = action;
    this->mouse_last_x = x;
    this->mouse_down_x = x;
    this->mouse_last_y = y;
    this->mouse_down_y = y;
    this->capture_mouse();

    if (this->scroll_action == 1 || this->scroll_action == 2 ||
        this->scroll_action == 6 || this->scroll_action == 7 ||
        this->scroll_action == 8) {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == 2) {
        if (p5 == 0 && p4 == 0) {
            this->player->unselect_object();
        }
        this->set_redraw((TPanel::RedrawMode)1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - DAT_005776c0,
                                       pick_info.y - DAT_005776c0);
            this->set_redraw((TPanel::RedrawMode)1);
            result = 1;
        }
    }

    return result;
}

// VA: 0053A290 RGE_View::handle_scroll_view (view.cpp:5922-6155)
// __thiscall virtual (vtable slot 59), int (long param_1, long param_2), ret 8. 1801 bytes.
// Status: VERIFIED_LOGIC — post-review case-7 ordering corrected; non-exact tail merge.
//
// Attempt log (owner DS4-53A290, 2026-08-02):
// 1. baseline: natural reconstruction from packet/decomp + binary-verified details
//    (switch 2/6/7/8 + default edge scroll; RGE_View layout from matched 0053A9C0;
//    constants DAT_005776b4=0.5f / DAT_005776c0=-0.5f / DAT_005776c4=0.0625f;
//    is_inside at vtable slot 47, do_paint at slot 61). Size/frame exact 1801/0x24;
//    diff 1530 B; do_paint landed at slot 59 (+0xEC) and uVar8 local spilled to stack.
// 2. control-flow: added the two missing declarations so do_paint = slot 61; bVar7 block re-reads
//    this->scroll_action (member) so VC5 CSEs into al. Call set aligned (1 gap left);
//    still 1530 B due to uVar8 spill; switched switch() to this->scroll_action directly
//    and removed the uVar8 local: diff dropped to 104 B (dispatch now byte-exact).
// 3. control-flow: case7 warp mouse_last stores y-first (PDB line 6007 order): 96 B.
// 4. control-flow: case7 warp as if-body (PDB line order 5992/5994-6007/6044): no change.
// 5. variant: comma-expression one-liner in-bounds: no change (96 B).
// 6. variant: final check inverted to if-body form: no change.
// 7. variant: case7 in-bounds set_redraw BEFORE stores: broke the tail-merge with the
//    final block (final tail now byte-exact incl. mov eax,1 between pops); diff 43 B.
// 8. variant: stores-first again: tail-merge recurs (96 B) — merge is tied to the
//    scheduler NOT hoisting the call setup above the stores.
// 9. variant (kept, best): set_redraw BETWEEN the two mouse_last stores: 41 B strict
//    (98.17% sim, 1.69% edit); call lands between x-store and y-store.
//
// Remaining drift (all in case 7):
//  - in-bounds tail: rebuilt uses `mov eax,[esi]` where original uses `mov edx,[esi]`
//    (1 B), and the y-store/call order: rebuilt `call; mov [esi+170h],edi` vs original
//    `mov [esi+170h],edi; call [edx+20h]` (4 B).
//  - warp path: register cascade from the in-bounds block: rebuilt loads mouse_down_x
//    into edx (orig eax), panel into ecx (orig edx), lea/hwnd regs shifted; original
//    keeps ecx=mouse_down_y live and loads vtable into edx before the y store.
//  - PDB evidence: original in-bounds line 6044 = stores+set_redraw with setup hoisted
//    (`mov edx,[esi]; push 1; mov ecx,esi; stores; call`), i.e. natural stores-first
//    source + scheduler hoist; the tail-merge only happens when the setup is NOT hoisted.
// Next lead: find a source shape that keeps the in-bounds tail self-contained with
//    setup-first (e.g. a small helper call, pointer local plVar1, or moving the
//    y-store before set_redraw) so VC5 colors the vtable into edx and schedules both
//    stores before the call without merging; then the warp register cascade should
//    follow automatically.
// 10. liveness: TPanel pointer alias across case 7 redraw calls: emitted code unchanged (41 B).
// 11. context: stores-first plus explicit TPanel dispatch: tail merged, structural 96 B with one
//     missing vslot call; rolled back.
// 12. control-flow: dedicated case-7 success label: duplicate 96 B result; rolled back.
// 13. liveness: pointer local for the case-7 y destination: duplicate 96 B result; rolled back.
// 14. liveness: stores-first named result local: 93 B but still missing the case-7 vslot call;
//     rolled back in favor of the 41 B source.
// 15. liveness: named result local with the 41 B between-stores order: emitted code unchanged;
//     rolled back as a duplicate source shape.
// 16. abi: restored the binary-proven RGE_View set_redraw override; emitted code unchanged, kept
//     as the more accurate local class surface.
// 17. control-flow: comma expression sequencing y-store then redraw: tail merged, 96 B; rolled back.
// 18. layout: proven raw +0x170 y-store with stores-first order: tail merged, 96 B; rolled back.
// 19. variant: eight focused case-7 tail spellings (including stores-first, result/pointer locals,
//     do-store, comma-mode, and base dispatch); one invariant-eligible group, no exact. Current
//     between-stores spelling remains best at 41 strict bytes.
// Final bounded result: 10/10 meaningful hypotheses exhausted; leave scratch at validated 41 B.
// Logic review round 1 confirmed the between-stores spelling is behaviorally wrong at the
// virtual redraw boundary. Main-agent fix: store both mouse_last fields before set_redraw.
// VC5 tail-merges that corrected path with a later redraw/return tail: validated 1801B,
// 96 strict bytes, 35/36 static call sites (runtime case-7 redraw preserved). Semantic order
// takes precedence over the smaller matching-oriented diff; fresh blind review is required.

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

int RGE_View::handle_scroll_view(long param_1, long param_2)
{
    long point_x;                 // saved mouse_last_x
    float save_view_x;            // saved player view_x
    float save_view_y;            // saved player view_y
    long lVar12;                  // saved mouse_last_y (late)
    int iVar10;                   // deltas / ftol results
    tagPOINT point;
    RGE_Pick_Info pick_info;
    int bVar7;

    point_x = this->mouse_last_x;
    if (param_1 == this->mouse_last_x && param_2 == this->mouse_last_y) {
        return 0;
    }

    save_view_x = this->player->view_x;
    save_view_y = this->player->view_y;

    switch (this->scroll_action) {
    case 2:
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->bound_point(this->mouse_last_x, this->mouse_last_y);
            this->set_redraw((TPanel::RedrawMode)1);
        return 0;

    case 6:
        if (this->is_inside(param_1, param_2) != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - DAT_005776c0, pick_info.y - DAT_005776c0);
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
            return 0;
        }
            this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 7:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x -= sVar9;
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x += sVar9;
        }
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_y = this->mouse_down_y;
            this->mouse_last_x = this->mouse_down_x;
            this->set_redraw((TPanel::RedrawMode)1);
            return 1;
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 8:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x - (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x + (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        if (abs(param_2 - this->mouse_down_y) <= 8 && abs(param_1 - this->mouse_down_x) <= 8) {
            this->mouse_last_x = param_1;
            this->mouse_last_y = param_2;
        } else {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
        if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
            return 0;
        }
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }

    // scroll_action is not 2/6/7/8: edge-scroll handling shared by 0,1,3,4,5,9,10+
    if (this->scroll_action == 3 || this->scroll_action == 4 || this->scroll_action == 9) {
        if ((param_1 < this->clip_rect.left + 0x40 && param_1 < point_x) ||
            (param_1 > this->clip_rect.right - 0x40 && param_1 > point_x) ||
            (param_2 < this->clip_rect.top + 0x20 && param_2 < this->mouse_last_y) ||
            (param_2 > this->clip_rect.bottom - 0x20 && param_2 > this->mouse_last_y)) {
            bVar7 = 1;
        } else {
            bVar7 = 0;
        }
    } else {
        bVar7 = 1;
    }

    iVar10 = param_2 - this->mouse_last_y;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x - (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }
    iVar10 = param_1 - this->mouse_last_x;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x + (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }

    point_x = this->mouse_last_x;
    lVar12 = this->mouse_last_y;
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
    if (bVar7) {
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
    } else {
        this->mouse_down_x = param_1;
        this->mouse_down_y = param_2;
    }

    if (this->scroll_action == 3) {
        if (this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33 && this->player != 0) {
            this->set_selection_area(this->sel_col1, this->sel_row1,
                                     (long)pick_info.x, (long)pick_info.y);
        }
    } else if (this->scroll_action == 4) {
        if (this->player->selected_obj != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->selected_obj->teleport(pick_info.x, pick_info.y, 0);
            RGE_Static_Object* pRVar6 = this->player->selected_obj;
            unsigned char level;
            if (pRVar6->sprite_list != 0) {
                level = pRVar6->sprite_list->get_lowest_draw_level();
            } else if (pRVar6->sprite != 0) {
                level = pRVar6->sprite->get_lowest_draw_level();
            } else {
                level = 0x14;
            }
            if (level == 0) {
                this->set_redraw((TPanel::RedrawMode)2);
            } else {
        this->set_redraw((TPanel::RedrawMode)1);
            }
        }
    } else if (this->scroll_action == 9) {
        this->do_paint(point_x, lVar12, param_1, param_2, 2);
        this->set_redraw((TPanel::RedrawMode)1);
    }

    if (save_view_x != this->player->view_x || save_view_y != this->player->view_y) {
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }
    return 0;
}

// 0053A9C0 RGE_View::end_scroll_view (view.cpp:6161-6220)
// Using proper virtual method declarations for correct thiscall vtable dispatch.
// vtable: set_redraw at slot 8 (0x20), end_scroll_view at slot 60 (0xF0), do_paint at slot 61 (0xF4)

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

void RGE_View::end_scroll_view() {
    long min_x, max_x, min_y, max_y;

    switch (this->scroll_action) {
    case 2:
        if (this->mouse_down_x > this->mouse_last_x) {
            min_x = this->mouse_last_x;
            max_x = this->mouse_down_x;
        } else {
            min_x = this->mouse_down_x;
            max_x = this->mouse_last_x;
        }
        if (this->mouse_down_y > this->mouse_last_y) {
            min_y = this->mouse_last_y;
            max_y = this->mouse_down_y;
        } else {
            min_y = this->mouse_down_y;
            max_y = this->mouse_last_y;
        }
        this->pick_multi(4, min_x, min_y, max_x, max_y);
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 1:
    case 6:
    case 7:
    case 8: {
        tagPOINT pt;
        pt.x = this->mouse_down_x;
        pt.y = this->mouse_down_y;
        // render_area->Wnd at offset +4 is the HWND
        ClientToScreen(((void**)this->render_area)[1], &pt);
        SetCursorPos(pt.x, pt.y);
        break;
    }

    case 9:
        this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_down_x, this->mouse_down_y, 0);
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 3:
    case 4:
    case 5:
        break;
    }

    if (this->scroll_action == 1 || this->scroll_action == 2
        || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8)
    {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = 0;
}

// VA: 0053AAF0 RGE_View::do_paint | view.cpp:6226-6301
// compiles at original size. Conversion/local pick_info offsets fixed by using f0/y; remaining mismatch is mode-dispatch/source-shape (original subtract chain keeps game in ECX and brush in DX before dispatch).
// 1: Baseline exact calls/frame/size; mode dispatch starts at +64 with game in EAX and mode in ECX.
// 2: Direct global game-mode/field expressions — 208-byte diff; rolled back.
// 3: Reordered cached mode/brush/game declarations; pending checker result.
// 4: Polymorphic RGE_Base_Game surface was a codegen duplicate of baseline.
// 5: Cache mode/brush values without a game pointer local; pending checker result.
// 6: Compute cliff result before map call — codegen duplicate; rolled back.
// 7: Duplicate the two natural cliff-call arms so VC5 can join the final call — exact 332B.
// STATUS: exact under default /O2 /Oy; the duplicated arms are retained because the
// original has one joined virtual call with branch-specific push 1/0 topology.


int RGE_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5)
{
    RGE_Pick_Info pick_info;
    long new_col;
    long new_row;
    int mode;
    short brush;

    if (this->pick(0x28, 0, param_3, param_4, &pick_info, 0) != 0x33) {
        return 0;
    }

    new_col = (long)pick_info.x;
    new_row = (long)pick_info.y;
    this->pick(0x28, 0, param_1, param_2, &pick_info, 0);

    mode = rge_base_game->game_mode;
    brush = rge_base_game->brush_size;
    switch (mode) {
    case 9:
        if (param_5 != 0 && rge_base_game->terrain_id != -1) {
            this->map->do_terrain_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, brush,
                (unsigned char)rge_base_game->terrain_id);
        }
        break;
    case 10:
        if (param_5 != 0 && rge_base_game->elevation_height != -1) {
            this->map->do_elevation_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, brush,
                (unsigned char)rge_base_game->elevation_height);
        }
        break;
    case 0x13:
        if (rge_base_game->sub_game_mode == 1) {
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, 0, 1);
        } else {
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, 0, 0);
        }
        this->redraw(2);
        break;
    }

    this->real_old_map_row = new_row;
    this->real_old_map_col = new_col;
    return 1;
}


void RGE_View::reset_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        next = sprite->next;
        operator_delete(sprite);
        sprite = next;
    }
    extra_sprites = 0;
}


void RGE_View::reset_cyclic_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        if (sprite->displayfunction == 1) {
            if (sprite->prev != 0) {
                sprite->prev->next = sprite->next;
            }
            if (sprite->next != 0) {
                sprite->next->prev = sprite->prev;
            }
            if (sprite->prev == 0) {
                extra_sprites = sprite->next;
            }
            next = sprite->next;
            operator_delete(sprite);
            sprite = next;
        } else {
            sprite = sprite->next;
        }
    }
}


void RGE_View::add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags, int draw_level, unsigned char* color_table, int displayfunction, unsigned long draw_time_interval) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* head;

    sprite = (Ov_Sprite_Draw_Rec*)operator_new(0x30);
    if (sprite != 0) {
        head = extra_sprites;
        sprite->prev = 0;
        sprite->next = head;
        if (head != 0) {
            head->prev = sprite;
        }
        extra_sprites = sprite;
        sprite->theShape = shape;
        sprite->thefacet = facet;
        sprite->world_x = world_x;
        sprite->world_y = world_y;
        sprite->flags = flags;
        sprite->drawLevel = draw_level;
        sprite->colortable = color_table;
        sprite->displayfunction = displayfunction;
        sprite->DrawTimeInterval = draw_time_interval;
        sprite->LastDrawTime = 0;
    }
}


bool RGE_View::Object_Was_Displayed(int id, bool allow_flagged) {
    DClipInfo_Node* node;

    node = prior_objs->LocateIDbyDrawLevel(id, 6, 0x28, 0);
    if (node == 0) {
        return false;
    }
    if (!allow_flagged && (node->Draw_Flag & 1) != 0) {
        return false;
    }
    return true;
}

// STATUS: exact via variant lab
// constructor stayed byte-identical except VC5 kept loading/storing the 2nd and 3rd int params in source-order/field-order opposite the original prologue
// variant lab over early scalar field spellings found exact match with explicit offset stores written +0x24 then +0x28; VC5 schedules the loads/stores into the original +0x28 then +0x24 machine order

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);


DClipInfo_List::DClipInfo_List(int init_zone_size, int element_size, int default_grow_size, int ymin, int ymax, int max_draw_levels) {
    int yline_offset;
    int yline_size;

    Free_Pool_Zone = -1;
    Free_Pool_Index = -1;
    *(int*)((char*)this + 0x24) = element_size;
    *(int*)((char*)this + 0x28) = default_grow_size;
    yline_offset = -ymin;
    yline_size = (ymax - ymin) + 1;
    Zone_Ptrs = 0;
    Zone_Size_Ptrs = 0;
    Max_Zones = 8;
    Used_Zones = 0;
    Free_Head = 0;
    Total_Blocks = 0;
    Free_Blocks = 0;
    YLine_Offset = yline_offset;
    YLine_Size = yline_size;
    Max_Draw_Levels = max_draw_levels;
    SetCaptureLevel(0, max_draw_levels);
    Draw_Clip_Nodes = (DClipInfo_Node**)calloc(YLine_Size, 4);
    Draw_Level_Head = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1, 4);
    Draw_Level_Tail = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1, 4);
    ResetStats();
    SetNumZones(8);
    InitNewZone(init_zone_size);
    Select_Box = 0;
}

extern "C" void __cdecl free(void* block);


DClipInfo_List::~DClipInfo_List(void) {
    int i;

    i = 0;
    if (Used_Zones > 0) {
        do {
            if (Zone_Ptrs[i] != 0) {
                free(Zone_Ptrs[i]);
            }
            i = i + 1;
        } while (i < Used_Zones);
    }
    if (Zone_Ptrs != 0) {
        free(Zone_Ptrs);
    }
    if (Zone_Size_Ptrs != 0) {
        free(Zone_Size_Ptrs);
    }
    if (Draw_Clip_Nodes != 0) {
        free(Draw_Clip_Nodes);
    }
    if (Draw_Level_Head != 0) {
        free(Draw_Level_Head);
    }
    if (Draw_Level_Tail != 0) {
        free(Draw_Level_Tail);
    }
}


void DClipInfo_List::SetCaptureLevel(int min_level, int max_level) {
    int temp;

    if (min_level > max_level) {
        temp = min_level;
        min_level = max_level;
        max_level = temp;
    }
    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > Max_Draw_Levels) {
        max_level = Max_Draw_Levels;
    }
    Accept_Min_Level = min_level;
    Accept_Max_Level = max_level;
}

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);


void DClipInfo_List::SetNumZones(int num_zones) {
    DClipInfo_Node** new_zone_ptrs;
    int* new_zone_sizes;
    int i;

    if (num_zones >= Max_Zones) {
        new_zone_ptrs = (DClipInfo_Node**)calloc(num_zones, 4);
        new_zone_sizes = (int*)calloc(num_zones, 4);
        if (Zone_Ptrs != 0) {
            i = 0;
            if (Used_Zones > 0) {
                do {
                    new_zone_ptrs[i] = Zone_Ptrs[i];
                    new_zone_sizes[i] = Zone_Size_Ptrs[i];
                    i = i + 1;
                } while (i < Used_Zones);
            }
            free(Zone_Ptrs);
            free(Zone_Size_Ptrs);
        }
        Zone_Ptrs = new_zone_ptrs;
        Zone_Size_Ptrs = new_zone_sizes;
        Max_Zones = num_zones;
    }
}

extern "C" void* __cdecl malloc(unsigned int size);


void DClipInfo_List::InitNewZone(int zone_size) {
    int zone_index;
    unsigned int alloc_size;

    if (Used_Zones == Max_Zones) {
        SetNumZones(Used_Zones + 4);
    }
    zone_index = Used_Zones;
    Used_Zones = zone_index + 1;
    alloc_size = Element_Size * zone_size;
    Zone_Size_Ptrs[zone_index] = zone_size;
    Zone_Ptrs[zone_index] = (DClipInfo_Node*)malloc(alloc_size);
    NewZone_Count = NewZone_Count + 1;
    Total_Blocks = Total_Blocks + zone_size;
    Free_Blocks = Free_Blocks + zone_size;
    if (Free_Pool_Zone == -1) {
        Free_Pool_Zone = zone_index;
        Free_Pool_Index = 0;
    }
}


DClipInfo_Node* DClipInfo_List::GetNode(void) {
    DClipInfo_Node* node;

    if (Free_Blocks == 0) {
        InitNewZone(Default_Grow_Size);
    }
    node = Free_Head;
    if (node != 0) {
        Free_Head = node->Next;
        Free_Blocks = Free_Blocks - 1;
        return node;
    }
    node = Zone_Ptrs[Free_Pool_Zone] + Free_Pool_Index;
    Free_Blocks = Free_Blocks - 1;
    Free_Pool_Index = Free_Pool_Index + 1;
    if (Free_Pool_Index == Zone_Size_Ptrs[Free_Pool_Zone]) {
        Free_Pool_Zone = Free_Pool_Zone + 1;
        Free_Pool_Index = 0;
        if (Free_Pool_Zone == Used_Zones) {
            Free_Pool_Zone = -1;
        }
    }
    return node;
}


void DClipInfo_List::SetDrawRegion(int xmin, int ymin, int xmax, int ymax) {
    if (xmin <= xmax) {
        if (ymin <= ymax) {
            SD_XMin = xmin;
            SD_XMax = xmax;
            SD_YMin = ymin;
            SD_YMax = ymax;
        }
    }
}

// VA: 0053B0A0 DClipInfo_List::AddDrawNode
// PDB: view.cpp:6652-6736
// attempt 1: direct reconstruction from original asm/decompiler; behavior close but register allocation differs (shape/x swapped) and yline store delayed.
// attempt 2: use parameter slot for yline and compute bounds/hotspots in original source order; improved shape/x allocation but yline store still delayed and hotspot loads early.
// attempt 3: use compound yline += member spelling; no codegen change.
// attempt 4: delaying hotspot calculations worsened prologue/register allocation; rolled back.
// attempt 5: force yline parameter stack-slot store through cast assignment; no change.
// attempt 6: a volatile yline sum forced the original store schedule; diagnostic only.
// attempt 7: combine clipping predicates made no codegen change.
// attempt 8: split width/height temps before hotspot expressions; no codegen change.
// attempt 9: /Ob0 made no codegen change; /O1 produced a too-small 358-byte .text and was discarded.
// probe 10: inline visible bounds expressions — 343-byte diff; rolled back.
// probe 11: remove the cached Select_Box pointer so each member access reloads the field.
// probe 12: remove width/height temporaries but retain named right/bottom bounds.
// probe 13: split bound/hotspot declarations from assignments in original source order.
// probe 14: remove redundant Shape_Info* local — 387-byte output; rolled back.
// probe 15: short hotspot accumulators — 383-byte output; rolled back.
// probe 16: move the two natural null link stores before scalar node-field stores.
// probe 17: reverse bound/hotspot assignment order — 340-byte output; rolled back.
// probe 18: six-way variant lab over bound/hotspot statement order; no exact result,
// best emitted code unchanged at 38 positional bytes / 97.50% shape.
// probe 19: declaration initializers for bound and hotspot locals; codegen duplicate.
// probe 20: natural while traversal for the linked-node tail; codegen duplicate.
// probe 21: decompiler-supported for-loop update form for the same traversal; duplicate.
// probe 22: restored canonical Shape_Info long-field ownership; codegen duplicate.
// probe 23: reordered natural bound/hotspot local declarations to follow the original
// width/right/hotspot/bottom liveness schedule; emitted code was unchanged and rolled back.
// probe 24: direct Draw_Clip_Nodes[yline] indexing in the natural allocation/link path;
// emitted code was unchanged and rolled back.
// current claim probes: short hotspot/coordinate locals, mixed short/full locals, a focused
// arithmetic-order lab, parenthesized/split bound subtraction, long locals, direct shape
// reads, and entry-scope declarations all either duplicated the clean code or moved farther.
// worker pass: direct while(cur->Next) traversal improved the current 379-byte source
// by one positional byte and restored the original current-pointer reload.
// worker pass: complete DClipInfo_List fields, all local declaration and assignment
// orders, standard-header and ambient-context sweeps, and width/height locals did not
// change the bound/hotspot basin. Volatile member reads improved the metric to 26 bytes,
// but are not retained because they are compiler-steering barriers without behavior evidence.
// revisit: a distinct adjusted-yline local, used for both clipping and list indexing,
// recovers the original early parameter-home store and all bound/hotspot scheduling.
// Exact validation: 379/379 bytes, 100% shape, one aligned GetNode call, and the
// original owning symbol and boundary. No volatile access or compiler steering remains.


void DClipInfo_List::AddDrawNode(void* shape_base, Shape_Info* shape, int yline, int draw_x, int draw_y,
                                 int draw_flag, unsigned char* color_table, int xform_mask,
                                 int draw_level, int object_id)
{
    int yline_tmp = this->YLine_Offset + yline;

    if (draw_level > this->Accept_Max_Level)
        return;
    if (draw_level < this->Accept_Min_Level)
        return;

    Shape_Info* shp = shape;
    int right;
    int bottom;
    int hot_x;
    int hot_y;
    right = draw_x + shp->Width - 1;
    bottom = draw_y + shp->Height - 1;
    hot_x = draw_x + shp->Hotspot_X;
    hot_y = draw_y + shp->Hotspot_Y;

    if (!(draw_x <= this->SD_XMax && right >= this->SD_XMin &&
          draw_y <= this->SD_YMax && bottom >= this->SD_YMin &&
          yline_tmp >= 0 && yline_tmp < this->YLine_Size))
        return;

    DClipInfo_Node* node = this->GetNode();
    DClipInfo_Node** list = this->Draw_Clip_Nodes + yline_tmp;
    DClipInfo_Node* cur = *list;
    if (cur == 0) {
        *list = node;
    } else {
        while (cur->Next != 0)
            cur = cur->Next;
        cur->Next = node;
    }

    node->Next = 0;
    node->NextOnLevel = 0;
    node->Object_ID = object_id;
    node->Draw_Flag = draw_flag;
    node->Shape_Base = (unsigned char*)shape_base;
    node->Color_Table = color_table;
    node->Xform_Mask = xform_mask;
    node->Shape = shp;
    node->Draw_X = draw_x;
    node->Draw_Y = draw_y;
    node->Draw_Level = draw_level;
    node->Node_Type = 0;

    if (this->Select_Box != 0) {
        node->x1 = (short)(hot_x + this->Select_Box[0]);
        node->y1 = (short)(this->Select_Box[1] + hot_y);
        node->x2 = (short)(this->Select_Box[2] + hot_x);
        node->y2 = (short)(this->Select_Box[3] + hot_y);
        this->Select_Box = 0;
    } else {
        node->x1 = (short)draw_x;
        node->y1 = (short)draw_y;
        node->x2 = (short)(draw_x + shp->Width - 1);
        node->y2 = (short)(draw_y + shp->Height - 1);
    }

    node->x3 = (short)hot_x;
    node->y3 = (short)hot_y;
    node->x4 = 0;
    node->y4 = 0;
}

// 0053B220 DClipInfo_List::AddGDINode
// Source: view.cpp lines 6746-6793
// Size: 219 bytes
// NC: no custom flags (default /O2 /Oy)


DClipInfo_Node* DClipInfo_List::AddGDINode(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13)
{
    int iVar2 = YLine_Offset + param_2;

    if (param_11 > Accept_Max_Level || param_11 < Accept_Min_Level || iVar2 < 0 || iVar2 >= YLine_Size)
        return 0;

    DClipInfo_Node* node = GetNode();
    node->Next = Draw_Clip_Nodes[iVar2];
    Draw_Clip_Nodes[iVar2] = node;

    node->Object_ID = param_13;
    node->Draw_Flag = param_12;
    node->Node_Type = param_1;
    node->x1 = param_3;
    node->y1 = param_4;
    node->x2 = param_5;
    node->y2 = param_6;
    node->x3 = param_7;
    node->y3 = param_8;
    node->NextOnLevel = 0;
    node->Shape = 0;
    node->Draw_X = 0;
    node->Draw_Y = 0;
    node->Shape_Base = 0;
    node->Color_Table = 0;
    node->Xform_Mask = 0;
    node->Draw_Level = param_11;
    node->x4 = param_9;
    node->y4 = param_10;

    return node;
}

// VA: 0053B300 DClipInfo_List::LocateIDbyDrawLevel (103 B)
// PDB source: view.cpp lines 6800-6822
// Notes: current best is 14.56% positional diff (15/103 bytes), edit diff 5.
// All structural elements match: prologue, swap, clamp, validation, loop, inner walk, epilogue.
// Remaining diff is localized: original emits `mov edx,eax` before the `jg` low>high validation
// and therefore uses a shorter branch displacement; rebuilt delays `mov edx,eax` until after
// loading Draw_Level_Head/params. Current best also matches original bottom-loop `inc edx; add ecx,4` order.
// Tried before this pass: declaration order, variable naming (Ghidra-style), pointer walk vs indexed access,
// do-while vs for, temp variable styles; none fixed eax/edx swap / loop-counter scheduling.
// SpruceGlow tries 1-10: reversed initial low/high, mutate-parameter form, nested-if, goto, while/for pointer,
// param-order aliases, explicit level temp, object/node local aliases, and reversed compare forms. Mutating the
// incoming level parameters fixed the initial eax/edx register choice and improved to edit diff 7, but still
// delayed `mov edx,eax` and had bottom `add/inc` reversed.
// SpruceGlow tries 11-20: nested positive validation with mutated params is best (edit diff 5): it preserves the
// initial register choice and bottom `inc/add` order; remaining mismatch is only the delayed loop-counter copy
// (`mov edx,eax`) crossing the validation branch. Separate level-before-check, for-increment order, param-as-loop,
// preincrement pointer, goto/continue forms, and direct member indexing were worse or same.
// ACCEPTED_DRIFT: reviewed by Boss. Behavior is correct and drift is localized to
// movement of the loop-counter copy `mov edx,eax` from before to after the validated
// low<=high branch setup. The copied value is only used by the subsequent loop, all
// validation predicates/branch targets, loop body, memory reads, return paths, size,
// and epilogue are identical; remaining byte differences are the moved instruction
// and one short-branch displacement adjustment. No inline asm/hacks.


DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int level_a, int level_b, int node_type)
{
    if (level_a > level_b) {
        int temp = level_a;
        level_a = level_b;
        level_b = temp;
    }

    if (level_a < 0) {
        level_a = 0;
    }

    int max_levels = this->Max_Draw_Levels;
    if (level_b > max_levels) {
        level_b = max_levels;
    }

    if (level_a <= max_levels && level_b >= 0 && level_a <= level_b) {
        DClipInfo_Node** head_ptr = this->Draw_Level_Head + level_a;
        int level = level_a;
        do {
            DClipInfo_Node* node = *head_ptr;
            while (node) {
                if (node->Object_ID == object_id && node->Node_Type == node_type) {
                    return node;
                }
                node = node->NextOnLevel;
            }
            level++;
            head_ptr++;
        } while (level <= level_b);
    }

    return 0;
}


// 0053B370 DClipInfo_List::Scroll
// view.cpp:6829-6898, 261 bytes
//
// void __thiscall DClipInfo_List::Scroll(int scroll_x, int scroll_y)
// - ret 8 cleanup (2 stack params + this in ecx)
//
// === Attempt log ===
// 1: Natural loop structure (for i=0..remaining-1) — 90.4% pos diff
//    scroll_y→ebx (+callee-save prologue push) vs original scroll_y→edx (no push)
//    Loop register cascade throughout all phases
// 2: Local copies (cx/cy) — same result
// 3: Post-increment loop structure to match original — 93.1% pos diff, worse
//    Compiler generated extra xor ebp,ebp for NULL constant
// 4: Reconstructed original do/while/index topology — 176-byte diff, 90.2% shape.
// 5: Reordered positive locals and named reverse source index — 217-byte diff; rolled back.
// 6: Positive remaining local is initialized before the index — 221-byte diff; rolled back.
// 7: Reverse source index scoped to the guarded copy loop — 284-byte output; rolled back.
// 8: Reverse source index live across the negative guard — 284-byte output; rolled back.
// 9: Named reverse-copy value — 284-byte output and register cascade; rolled back.
// 10: Moved the first positive-loop i=0 before YLine_Size-scroll_y and reused i — 166-byte diff, recovering the early xor eax and two exact blocks; remaining drift starts in the negative-loop index setup.
// refill-r1: Exact view.cpp donors confirm the typed DClipInfo arrays and do/while idiom; the first-index guard `i + scroll_y >= 0` moved the negative block to 163 bytes, 94.00% shape, and 84.69% exact blocks.
// refill-r1: Member first-index guards and declaration order were tested without adding source-index locals; the focused eight-variant guard lab found no exact result and kept the same 261-byte size.
// refill-r1: A natural pretest while form reproduced the older 166-byte basin; restored the condition-only do/while reconstruction and retained the 163-byte first-index result.
// RESOLVED: TU-context register allocation cascade (scroll_y in ebx vs edx)
// Best retained source: typed same-TU DClipInfo layout with direct member arrays,
// natural do/while copies, and switch fall-through; 166-byte diff, 92.16% shape,
// exact original boundary. The positive-loop init now matches the early xor and
// remaining drift starts at negative-loop index setup and reverse-copy addressing.
// Full view.cpp context or a stronger source donor is the
// next lead; source-index locals add 23 bytes past the original boundary.
// continuation: the natural last-index guard `YLine_Size + scroll_y - 1 >= 0`
// reproduces the best 157-byte negative-block basin; direct `i >= neg` is
// readable but emits a 166-byte basin. Retain the binary-shaped member guard.
// shardC5-53B370: natural reverse-copy for-loop source grew 23 bytes and moved
// the checker to structural reconstruction; restored the do/while body.
// shardC5-53B370: explicit `YLine_Size - 1 >= neg` reproduces the prior
// 166-byte direct-bound basin; restored the 157-byte member-bound source.
// fresh-r1: Baseline rebuilt at 261 bytes with 157 positional mismatches; the
// positive copy and final node-walk regions remain exact, while drift starts
// at the negative-copy guard and source-index setup.
// fresh-r1: Ambient declaration, standard-header, unused type/member, and full
// DClipInfo method-surface context sweeps changed only the 152-157 byte basin;
// none matched. Direct negative bounds matched the compare shape but not the
// reverse source-address lowering.
// fresh-r1: Named reverse source cursors grew the function to 284 bytes and
// changed the loop schedule. The clean typed do/while reconstruction remains
// authoritative. Next evidence needed: full view.cpp TU context or a stronger
// exact source donor for the negative-copy lowering.
// revisit-r1: Direct natural bounds, typed source-index locals, declaration-order
// changes, equivalent coordinate spellings, and loop-form changes did not improve
// the clean 261-byte basin. Keep the typed do/while source and direct coordinates.
// revisit-r2: A natural reverse-copy source index (`source = YLine_Size - 1 +
// scroll_y`) with the direct `i >= -scroll_y` guard reproduces 260/261 bytes.
// The only remaining byte is the equivalent LEA base/index encoding at +0x63
// (`[esi+edx-1]` versus original `[edx+esi-1]`). Typed pointer cursors and
// declaration or expression-order variants were worse. Keep this source.
// revisit-r3: Rebuilt the clean source after 20 focused probes. Split bases,
// long types, subtraction trees, declaration order, direct indexing, gap-only
// class context, and <stddef.h> context did not change the one-byte result.
// Direct indexed reverse copy returned to the 166-byte mismatch basin.
// revisit-r4: Exact under the period view.cpp Windows context. Adding
// <windows.h> changes the clean source from the one-byte SIB mismatch to
// MATCH; the canonical expression remains `YLine_Size - 1 + scroll_y`.
// H1 parameter-first `scroll_y + (YLine_Size - 1)` without the header stayed
// at one byte, and H4 with the header was an exact codegen duplicate. This
// proves the header context controls the VC5 register basin, not arithmetic
// operand order. Exact same-TU donor 0053A9C0_end_scroll_view.cpp includes
// <windows.h>, and view.cpp uses period Windows types in adjacent code.
// BINARY NOTE: With the header, VC5 naturally assigns EDX as the base and ESI
// as the index for `lea esi,[edx+esi-1]`. Without it, it assigns the reverse
// SIB roles while preserving all behavior and later bytes.
// Reduction: removing <windows.h> restores the prior one-byte mismatch;
// changing only the commutative expression under the header changes no byte.
// Policy audit: default VC5 /O2 /Oy, natural typed arrays and loops, no inline
// assembly, register hints, volatility, raw cursors, or metric-only aliases.


void DClipInfo_List::Scroll(int scroll_x, int scroll_y)
{
    if (scroll_y > 0) {
        int i = 0;
        if (this->YLine_Size - scroll_y > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
                i = next;
            } while (i < this->YLine_Size - scroll_y);
        }

        i = this->YLine_Size - scroll_y;
        if (i < this->YLine_Size) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < this->YLine_Size);
        }
    }

    if (scroll_y < 0) {
        int neg = -scroll_y;
        int i = this->YLine_Size - 1;
        int source = this->YLine_Size - 1 + scroll_y;

        if (i >= neg) {
            do {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[source];
                i = i - 1;
                source = source - 1;
            } while (i >= neg);
        }

        i = 0;
        if (neg > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < neg);
        }
    }

    int i = 0;
    if (this->YLine_Size > 0) {
        do {
            DClipInfo_Node* node = this->Draw_Clip_Nodes[i];

            while (node != 0) {
                switch (node->Node_Type) {
                case 0:
                    node->Draw_X -= scroll_x;
                    node->Draw_Y -= scroll_y;
                    break;

                case 1:
                    node->y3 -= (short)scroll_y;
                    node->y4 -= (short)scroll_y;

                case 2:
                    node->x3 -= (short)scroll_x;
                    node->x4 -= (short)scroll_x;

                case 3:
                case 4:
                    node->x1 -= (short)scroll_x;
                    node->y1 -= (short)scroll_y;
                    node->x2 -= (short)scroll_x;
                    node->y2 -= (short)scroll_y;
                    break;
                }

                node = node->Next;
            }

            i = i + 1;
        } while (i < this->YLine_Size);
    }
}


void DClipInfo_List::FreeNode(DClipInfo_Node* node) {
    node->Next = Free_Head;
    Free_Head = node;
    Free_Blocks = Free_Blocks + 1;
}

int DClipInfo_List::FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail) {
    int count = 0;
    DClipInfo_Node* cur = head;
    if (head == 0) return 0;
    if (tail == 0) {
        do {
            tail = cur;
            ++this->Free_Blocks;
            ++count;
            cur = cur->Next;
        } while (cur != 0);
    } else {
        do {
            ++this->Free_Blocks;
            ++count;
            if (cur != tail) cur = cur->Next;
            else cur = 0;
        } while (cur != 0);
    }
    tail->Next = this->Free_Head;
    this->Free_Head = head;
    return count;
}

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);


void DClipInfo_List::ReclaimAllNodes(void) {
    memset(Draw_Clip_Nodes, 0, YLine_Size * 4);
    memset(Draw_Level_Head, 0, (Max_Draw_Levels * 4) + 4);
    memset(Draw_Level_Tail, 0, (Max_Draw_Levels * 4) + 4);
    Free_Head = 0;
    Free_Pool_Zone = 0;
    Free_Pool_Index = 0;
    Free_Blocks = Total_Blocks;
    Reset_Count = Reset_Count + 1;
}


void DClipInfo_List::ResetStats() {
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}
