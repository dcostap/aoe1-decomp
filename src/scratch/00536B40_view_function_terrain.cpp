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

#include <windows.h>
#include <string.h>

#ifndef RGE_VIEW_SHARED_CONTEXT
struct RGE_Tile {
    short screen_xpos;              // +0x00
    short screen_ypos;              // +0x02
    unsigned char tile_type;        // +0x04
    unsigned char terrain_flags;    // +0x05, low 5 bits terrain, high bits elevation-ish
    unsigned char draw_flags;       // +0x06, draw_tile uses low nibble
    unsigned char last_drawn_as;    // +0x07
    unsigned char last_drawn_shape; // +0x08
    unsigned char draw_as;          // +0x09, written before draw_tile
    unsigned char draw_attribute;   // +0x0A, bit 0x40 forces TileOffScreen redraw
    unsigned char last_drawn_shape2;// +0x0B
    unsigned char objects[12];      // +0x0C, RGE_Object_List inline prefix
};
typedef char assert_RGE_Tile_size[(sizeof(RGE_Tile) == 24) ? 1 : -1];

struct RGE_TileSize_Entry {
    char gap_00[2];
    short height;                   // map + 0x1A + tile_type*6
    char gap_04[2];
};
typedef char assert_RGE_TileSize_Entry_size[(sizeof(RGE_TileSize_Entry) == 6) ? 1 : -1];

struct RGE_Terrain_Type_Prefix {
    char gap_000[0xD1];
    unsigned char drawn;            // cleared/incremented at map + 0xD1 + type*0x198
    char gap_0D2[0x144 - 0xD2];
    short terrain_to_draw;          // +0x144, overrides tile low terrain when != -1
    char gap_146[0x198 - 0x146];
};
typedef char assert_RGE_Terrain_Type_Prefix_size[(sizeof(RGE_Terrain_Type_Prefix) == 0x198) ? 1 : -1];

class RGE_Player_Prefix {
public:
    virtual void pv00();
    virtual void pv04();
    virtual void pv08();
    virtual void pv0C();
    virtual void pv10();
    virtual void pv14();
    virtual void pv18();
    virtual void pv1C();
    virtual void pv20();
    virtual void pv24();
    virtual void pv28();
    virtual void pv2C();
    virtual void pv30();
    virtual void pv34();
    virtual void pv38();
    virtual void pv3C();
    virtual void pv40();
    virtual void pv44();
    virtual void pv48();
    virtual void pv4C();
    virtual void pv50();
    virtual void pv54();
    virtual void pv58();
    virtual void pv5C();
    virtual void pv60();
    virtual void pv64();
    virtual void pv68();
    virtual void pv6C();
    virtual void pv70();
    virtual void pv74();
    virtual void pv78();
    virtual void pv7C();
    virtual void pv80();
    virtual void pv84();
    virtual void pv88();
    virtual void pv8C();
    virtual void pv90();
    virtual void pv94();
    virtual void pv98();
    virtual long rollover_info(long object_id, long* facet, long* text_id); // +0x9C

    char gap_004[0x38 - 4];
    void* visible;                   // +0x38
    char gap_03C[0xD0 - 0x3C];
    unsigned long mutualExploredMask; // +0xD0
    unsigned long mutualVisibleMask;  // +0xD4
};

class TSpan_List_Manager;
class TDrawArea_Prefix;
struct Shape_Info;
struct DClipInfo_Node;
struct Tile_FogEdge_Table;

struct RGE_Map_Prefix {
    char gap_00[8];
    long map_width;                 // +0x08
    long map_height;                // +0x0C
    RGE_TileSize_Entry tilesizes[1];// +0x10, height at +0x1A for index via +0x0A into array
    char gap_after_tilesizes[0x8D8C - 0x16];
    RGE_Tile** map_row_offset;      // +0x8D8C
    short num_terrain;              // +0x8D90
    char gap_8D92[0x26];
    unsigned char map_visible_flag; // +0x8DB8
    unsigned char fog_flag;         // +0x8DB9
};

struct Panel_List_Node;
class TPanel_Prefix;

class RGE_View {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void game_mode_15_hook(); // +0xF8

    char gap_000[0x1C];
    TDrawArea_Prefix* render_area;  // +0x20
    char gap_024[0x58 - 0x24];
    Panel_List_Node* panel_list;    // +0x58
    char gap_05C[0x78 - 0x5C];
    void* some_pick_gate;           // +0x78
    char gap_07C[0x8C - 0x7C];
    RECT render_rect;               // +0x8C
    char gap_09C[0xC4 - 0x9C];
    long mouse_down_x;              // +0x0C4
    long mouse_down_y;              // +0x0C8
    char gap_0CC[0xF8 - 0x0CC];
    long calc_draw_count;           // +0x0F8
    char gap_0FC[4];
    RGE_Player_Prefix* player;      // +0x100
    RGE_Map_Prefix* map;            // +0x104
    short tile_wid;                 // +0x108 (used via movsx)
    char gap_10A[4];
    short tile_half_hgt;             // +0x10E
    char gap_110[6];
    short max_col_num;              // +0x116
    short max_row_num;              // +0x118
    char gap_11A[0x10];
    short start_map_col;            // +0x12A
    short start_map_row;            // +0x12C
    char gap_12E[2];
    long map_scr_x_offset;          // +0x130
    long map_scr_y_offset;          // +0x134
    char gap_138[8];
    unsigned char function_mode;    // +0x140
    char gap_141;
    unsigned char render_terrain_mode; // +0x142
    char gap_143[0x168 - 0x143];
    unsigned char scroll_action;    // +0x168
    char gap_169[3];
    long mouse_last_x;              // +0x16C
    long mouse_last_y;              // +0x170
    char gap_174[0x178 - 0x174];
    TSpan_List_Manager* Terrain_Clip_Mask; // +0x178
    TSpan_List_Manager* Terrain_Fog_Clip_Mask; // +0x17C
    TSpan_List_Manager* Master_Clip_Mask; // +0x180
    Tile_FogEdge_Table** Tile_Edge_Tables; // +0x184
    long** Black_Edge_Tables;       // +0x188
    char gap_18C[0x2A0 - 0x18C];
    long Limited_Render_Rect;       // +0x2A0
    long Use_Rect2;                 // +0x2A4
    RECT Render_Rect1;              // +0x2A8
    RECT Render_Rect2;              // +0x2B8
    char gap_2C8[0x2D8 - 0x2C8];
    long Queued_Blits;              // +0x2D8
    char gap_2DC[0x324 - 0x2DC];
    TDrawArea_Prefix* save_area1;   // +0x324
    unsigned char* LastRenderBits;  // +0x328
    void** RenderOffsets;           // +0x32C
    long LastRenderSize;            // +0x330
    void* prior_objs;               // +0x334
    void* futur_objs;               // +0x338
    long UC_ObjectTouched;          // +0x33C
    long UC_TouchedObj;             // +0x340
    unsigned long UC_StartTime;     // +0x344
    char gap_348[4];
    void* message_panel;            // +0x34C
    void* extra_sprites;            // +0x350
    char gap_354[4];
    long DispSel_List_Size;         // +0x358

    void update_display_selected_objects();
    void ProcessQueuedBlit(long wait);
    long get_tile_mask_num(long col, long row, long map_width, long map_height, unsigned long mask);
    void draw_tile(RGE_Tile* tile, unsigned char terrain, short screen_x, short screen_y,
                   short map_col, short map_row, unsigned char draw_as,
                   long normal_draw, long fog_draw);
    void reset_cyclic_overlay_sprites();
    void Add_GDI_Clip_Mask(DClipInfo_Node* node, TSpan_List_Manager* mask);
    void draw_object_outline();
    long Get_Cursor_Position(POINT* pt, long xoff, long yoff);
    long pick_touched_object(void* list, long x, long y, long a, long b, long* out_id);
    void get_string(long id, char* out, long lang_id);
    void Draw_GDI_Object(DClipInfo_Node* node, TDrawArea_Prefix* draw_area);
    void Update_Render_Pointers();
    long view_function_terrain(unsigned char mode, tagRECT rect);
};

typedef unsigned long VSpanMiniList;

class TShape {
public:
    long shape_count();
    void shape_draw(void* draw_area, long x, long y, long facet,
                    unsigned char flags, void* color_table);
};

struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;       // +0x00
    Ov_Sprite_Draw_Rec* prev;       // +0x04
    TShape* theShape;               // +0x08
    long thefacet;                  // +0x0C
    long world_x;                   // +0x10
    long world_y;                   // +0x14
    unsigned char flags;            // +0x18
    char gap_19[3];
    long drawLevel;                 // +0x1C
    long displayfunction;           // +0x20
    unsigned long LastDrawTime;     // +0x24
    unsigned long DrawTimeInterval; // +0x28
    void* colortable;               // +0x2C
};

class TDrawArea_Prefix {
public:
    char gap_00[0x08];
    unsigned char* Bits;            // +0x08
    char gap_0C[0x0C];
    long Width;                      // +0x18
    long Height;                     // +0x1C
    char gap_20[0x08];
    RECT ClipRect;                   // +0x28
    char gap_38[0x88];
    void** DisplayOffsets;          // +0xC0
    char gap_C0[0x0C];
    void* SavedMask;                // +0xCC donor from final restore
    void* CurrentMask;              // +0xD0 written to Master_Clip_Mask
    void PtrSpanCopy(TDrawArea_Prefix* dst, long x, long y, RECT* clip, unsigned char** lines);
    void DrawLine(long x1, long y1, long x2, long y2, unsigned char color);
    void FillRect(long left, long top, long right, long bottom, unsigned char color);
    void Unlock(const char* tag);
};

struct Tile_FogEdge_Table {
    void* normal_draw;
    void* fog_draw;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    void* Line_Head_Ptrs;           // +0x3C
    void* Line_Tail_Ptrs;           // +0x40
    char gap_44[0x58 - 0x44];
    long Min_Span_Px;               // +0x58
    long Max_Span_Px;               // +0x5C
    long Min_Line;                  // +0x60
    long Max_Line;                  // +0x64

    void SetSpanRegions(long left, long top, long right, long bottom);
    void AddMiniList(void* list, long x, long y);
    void SubtractMiniList(void* list, long x, long y);
    void AddSpan(long left, long right, long y);
    void Merge_n_Align(TSpan_List_Manager* a, TSpan_List_Manager* b);
    void AddShape_Align(long shape_base, Shape_Info* shape, long x, long y, long flag);
};

class RGE_Object_List {
public:
    void draw(void* draw_area, short x, short y, long through_fog);
};

struct Panel_List_Node {
    TPanel_Prefix* panel;
    Panel_List_Node* prev;
    Panel_List_Node* next;
};

class TPanel_Prefix {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void get_rect(RECT* out); // +0xB8
    char gap_04[0x38 - 4];
    long visible;                   // +0x38
    char gap_3C[0x6C - 0x3C];
    long gdi_enabled;               // +0x6C
    char gap_70[0xE0 - 0x70];
    long gdi_color;                 // +0xE0
};

struct Shape_Info {
    long Shape_Data_Offsets;        // +0x00 donor for final ASMDraw
    long Shape_Outline_Offset;      // +0x04
    char gap_08[8];
    long Width;                     // +0x10
    long Height;                    // +0x14
};

struct DClipInfo_Node {
    DClipInfo_Node* Next;           // +0x00, Y-line chain
    DClipInfo_Node* NextOnLevel;    // +0x04, draw-level chain
    char gap_08[4];
    Shape_Info* Shape;              // +0x0C
    long Draw_Level;                // +0x10
    long Draw_X;                    // +0x14
    long Draw_Y;                    // +0x18
    long Draw_Flag;                 // +0x1C
    long Shape_Base;                // +0x20
    void* Color_Table;              // +0x24
    void* Xform_Mask;               // +0x28
    long Node_Type;                 // +0x2C
};

class DClipInfo_List {
public:
    char gap_00[0x58];
    DClipInfo_Node** Draw_Clip_Nodes;    // +0x58, indexed by Y line
    DClipInfo_Node** Draw_Level_Head;    // +0x5C, indexed by draw level
    DClipInfo_Node** Draw_Level_Tail;    // +0x60, indexed by draw level
    char gap_64[4];
    long YLine_Size;                     // +0x68

    void ReclaimAllNodes();
    void SetCaptureLevel(long a, long b);
    DClipInfo_Node* AddGDINode(long type, long draw_level, long x1, long y1,
                               long x2, long y2, long x3, long y3, long x4,
                               long y4, long a10, long level2, long color,
                               long extra);
};

class RGE_Base_Game_Prefix {
public:
    char gap_000[0x1B0];
    long prog_mode;                 // +0x1B0
    long game_mode;                 // +0x1B4
    char gap_1B8[0xA08 - 0x1B8];
    long rollover;                  // +0xA08
};

class TMousePointer {
public:
    void Poll();
    long get_game_enable();
    void set_game_facet(long facet);
};

class TMessagePanel_Prefix {
public:
    void show_message(long kind, char* text, char a, char b, void* c, long d, long e);
    void remove_message();
};

#endif

extern TMousePointer* MouseSystem;
extern void* SDI_List;
extern long SDI_Capture_Info;
#ifndef RGE_VIEW_SHARED_CONTEXT
extern long fog_next_shape;
#endif
extern long view_debug_Objects;
extern long SDI_Draw_Level;
extern long SDI_Object_ID;
extern long view_debug_spans;
#ifndef RGE_VIEW_SHARED_CONTEXT
extern long view_debug_palette;
extern long frame_count;
#endif
extern long Clip_draw;
extern long Clip_remove;
#ifndef RGE_VIEW_SHARED_CONTEXT
extern RGE_Base_Game_Prefix* rge_base_game;
extern unsigned long unified_map_offsets[][1];
#endif
#ifndef RGE_VIEW_SHARED_CONTEXT
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, long line);
#endif
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
    long facet;
    long text_id;

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
        ((RGE_Terrain_Type_Prefix*)((char*)this->map + 0))[terrain_index].drawn = 0;
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

                terrain = tile->terrain_flags & 0x1f;
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
                            ((RGE_Terrain_Type_Prefix*)((char*)this->map))[terrain].drawn++;
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
                            this->Terrain_Clip_Mask->AddMiniList(normal_list, screen_x, screen_y);
                        }
                        if (fog_draw) {
                            this->Terrain_Fog_Clip_Mask->AddMiniList(fog_list, screen_x, screen_y);
                        }
                        if (black_list != 0) {
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->SubtractMiniList(black_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->SubtractMiniList(black_list, screen_x, screen_y);
                            }
                        }
                        if (full_visibility != 0) {
                            this->Terrain_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right, this->Render_Rect2.bottom);
                            this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right, this->Render_Rect2.bottom);
                            MapVis = 2;
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->AddMiniList(normal_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->AddMiniList(fog_list, screen_x, screen_y);
                            }
                            if (black_list != 0) {
                                if (normal_draw) {
                                    this->Terrain_Clip_Mask->SubtractMiniList(black_list, screen_x, screen_y);
                                }
                                if (fog_draw) {
                                    this->Terrain_Fog_Clip_Mask->SubtractMiniList(black_list, screen_x, screen_y);
                                }
                            }
                        }
                        {
                            short terrain_override = ((RGE_Terrain_Type_Prefix*)((char*)this->map))[terrain].terrain_to_draw;
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
                    short terrain_override = ((RGE_Terrain_Type_Prefix*)((char*)this->map))[terrain].terrain_to_draw;
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
                    ((RGE_Object_List*)tile->objects)->draw(
                        this->save_area1,
                        (short)screen_x,
                        (short)(((tile->terrain_flags >> 5) * this->tile_half_hgt) + screen_y),
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
            0, 0, 0, 0, 0, 0x28, 0xFF, 0);
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
                    _ASMSet_Color_Xform(node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    Shape_Info* shape = node->Shape;
                    _ASMDraw_Sprite(node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag & 0xFE);
                    clip = this->Terrain_Fog_Clip_Mask;
                    _ASMSet_Surface_Info(this->save_area1->DisplayOffsets, clip->Line_Head_Ptrs,
                        clip->Line_Tail_Ptrs, clip->Min_Span_Px, clip->Min_Line,
                        clip->Max_Span_Px, clip->Max_Line);
                    _ASMDraw_Sprite(node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag | 1);
                }
            }
        }
    }

    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    if (rge_base_game != 0 && rge_base_game->prog_mode == 4 && this->some_pick_gate != 0 &&
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
                    if (this->player->rollover_info(touched, &facet, &text_id) == 1) {
                        MouseSystem->set_game_facet(facet);
                        if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                            this->get_string(text_id, text, 0x7F);
                            ((TMessagePanel_Prefix*)this->message_panel)->show_message(0, text, 'p', 0, 0, 0, 0);
                        }
                    } else {
                        MouseSystem->set_game_facet(0);
                        if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                            ((TMessagePanel_Prefix*)this->message_panel)->remove_message();
                        }
                    }
                }
            } else if (this->UC_ObjectTouched != 0) {
                this->UC_ObjectTouched = 0;
                this->UC_TouchedObj = 0x80000000;
                MouseSystem->set_game_facet(0);
                if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                    ((TMessagePanel_Prefix*)this->message_panel)->remove_message();
                }
            }
        }
    }

    // Panel GDI capture nodes for active child panels.
    for (Panel_List_Node* pn = this->panel_list; pn != 0; pn = pn->next) {
        TPanel_Prefix* panel = pn->panel;
        if (panel->gdi_enabled != 0 && panel->visible != 0) {
            panel->get_rect(&pr);
            long x1 = pr.left - rect.left;
            long y1 = pr.top - rect.top;
            long x2 = pr.right - rect.left;
            long y2 = pr.bottom - rect.top;
            if (x1 < 0) x1 = 0;
            if (y1 < 0) y1 = 0;
            DClipInfo_Node* added = ((DClipInfo_List*)this->futur_objs)->AddGDINode(
                3, y1, x1, y1, x2, y2, y1, 0, 0, 0, 0, 0x1E, panel->gdi_color, 0);
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
    this->save_area1->CurrentMask = this->Master_Clip_Mask;

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
                    _ASMSet_Color_Xform(node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    Shape_Info* shape = node->Shape;
                    _ASMDraw_Sprite(node->Shape_Base, node->Draw_X, node->Draw_Y,
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

    this->render_area->Unlock(s_view__view_function_terrain);
    this->render_area->CurrentMask = this->render_area->SavedMask;
    {
#ifdef RGE_VIEW_SHARED_CONTEXT
        DClipInfo_List* tmp = this->futur_objs;
#else
        void* tmp = this->futur_objs;
#endif
        this->futur_objs = this->prior_objs;
        this->prior_objs = tmp;
    }

    return 0;
}
