# `src/view.cpp` source cleanup

## Assignment

- Owner: 24.
- Worker slot: 212.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Source owner: `src/view.cpp`.
- Report: this file.
- Header owner: owner 24 owns `include/view.h`.
- Header change: none.

This pass changes identifier spelling and source formatting only. It does not add
functions, remove functions, change declarations, change types, or change scope.
It does not change statements, calls, casts, relocations, call targets, or
expression order.

## Evidence and provenance

The original executable is the behavior oracle. The PDB and inventory are
reference evidence. This pass used these repository-local sources:

- `build/view_evidence/view_scoped_symbols.txt`.
- `inventory/functions/0053/*.txt` for the scoped function records.
- `inventory/types/dumps/RGE_View.txt` and related type records.
- The original assembly records in `inventory/functions/0053/`.
- `src/view.cpp` at the assignment base commit.
- `include/view.h` for the assigned declaration boundary.
- `workflow/docs/source_cleanup.md`.
- `workflow/docs/source_comments.md`.
- `workflow/docs/source_cleanup_owners.md`.
- `workflow/docs/resource_ids.md`.
- `workflow/docs/testing.md`.
- `workflow/decomp_notes/source_cleanup/wave04_assignments.md`.

The scoped PDB report records `this` in `ecx` for the member procedures. It also
records stack names, offsets, types, and source line spans. I matched each record
to its address, procedure, type, scope, and use. I did not copy a name from an
unrelated procedure.

The PDB uses mixed spelling. The source keeps that spelling where the record
proves the declaration. Examples include `WaitIfBusy`, `SDI`, `Clip_Mask`,
`Map_Width`, `TileVisibleMask`, `VisibleMask`, `Xpos`, `ObjectID`, `InitialSize`,
`New_Size`, and `HeadNode`.

A stack offset is not enough proof of a source declaration. Several optimized
procedures reuse one home for more than one value. I kept a descriptive source
name when the scope or declaration could not be mapped without guesswork.

## Name recovery

The following direct PDB mappings are applied or retained:

- Basic view setup: `render_area_in`, `parent_panel_in`, `x_in`, `y_in`,
  `wid_in`, `hgt_in`, `color_in`, `calc_draw_count_in`, `border_line_file`,
  `have_focus_in`, `id`, `duration`, `select_type`, `reset_type`, `xDelta`,
  `yDelta`, `WaitIfBusy`, and `draw_area_in`.
- Picking entry points: `pick_mode_in`, `select_level`, `picked_item`,
  `item_x`, `item_y`, `item_scr_x`, `item_scr_y`, `obj`, `confidence`,
  `find_col`, `find_row`, `scr_x`, `scr_y`, `drop`, `Xpos`, `Ypos`,
  `ignoreNeg`, `Xpos1`, `Ypos1`, `Xpos2`, `Ypos2`, `obj_list`, and
  `touched_object_id`.
- View traversal: `function_mode_in`, `function_parm_in`, `mouse_pos`,
  `start_mouse_pos`, `picked_item`, `item_x`, `item_y`, `item_scr_x`,
  `item_scr_y`, `orig_picked_obj`, `last_picked_obj`, `calc_sel_col1`,
  `calc_sel_row1`, `calc_sel_col2`, `calc_sel_row2`, `tile_screen_row`,
  `fog_flag`, and the other unique view-function records.
- Terrain traversal: `start_map_x`, `cols_2_scan`, `rows_2_scan`, `Map_Width`,
  `Map_Height`, `TileFoggedMask`, `TileVisibleMask`, `Full_Visibility`,
  `black_tile_mask_num`, `tile_mask_num`, `MapVis`, `clip_to`, `fog_draw`,
  `ResetALLCyclic`, `CPoint`, and `pText`.
- Terrain and cursor helpers: `terrain_type`, `map_col`, `map_row`, `norm_draw`,
  `fog_draw`, `draw_attribute`, `draw_normal`, `draw_fog`, `TileX`, `TileY`,
  `TileX4`, `TileY4`, `Point`, `adjustX`, `adjustY`, `Tile_X`, `Tile_Y`,
  `MapW`, `MapH`, `Search`, `bx1`, `by1`, `bx2`, and `by2`.
- Clip-list and GDI code: `SDI`, `Clip_Mask`, `VisibleMask`, `render_area`,
  `ObjectID`, `InFogOK`, `InitialSize`, `GrowSize`, `szitem`, `top_Yline`,
  `bottom_Yline`, `mxLevel`, `minLevel`, `maxLevel`, `New_Size`, `Ptrs`,
  `Zone_Size`, `Left`, `Top`, `Right`, `Bottom`, `ShapeBase`, `theShape`,
  `SortLine`, `Xpos`, `Ypos`, `DrawFlags`, `ColorTable`, `XformMask`,
  `DrawLevel`, `Object_ID`, `GDI_Type`, `X1`, `Y1`, `X2`, `Y2`, `X3`, `Y3`,
  `X4`, `Y4`, `DrawColor`, `SearchID`, `StartLevel`, `EndLevel`, `NodeType`,
  `xDelta`, `yDelta`, `theNode`, `HeadNode`, and `TailNode`.
- Overlay and paint code: `old_x`, `old_y`, `new_x`, `new_y`, `up_down`,
  `theShape`, `drawlevel`, `colorTable`, `dispFunc`, `DrawInterval`.

The list above describes recovered names. It does not claim that every other
identifier came from the original source. Existing source names remain when the
PDB record is absent, when the name belongs to a member or global, or when the
record cannot prove a stable declaration.

## Reused stack homes left unresolved

I did not force these PDB names into one declaration when the scoped record
shows a reused home:

- `Init_Tile_Edge_Tables`: `A6`/`B4`, `B1`/`A4`, and `A5`/`y` share homes.
- `CreateBlitQueue`: `nBlits` and `yd` share a home. The existing source keeps
  both source names because both declarations are already present.
- `draw`: `y_diff` and `old_map_scr_y_offset` share a home.
- `update`: `row_offset` and `col_adj` share a home. The source keeps its
  descriptive `col_adjust` and `row_adjust` names.
- `pick`, `pick_multi`, and `pick_weight`: the PDB records overlap parameters
  with later locals. Parameter names were recovered only where the parameter
  record is direct. Reused locals remain separate source names.
- `view_function_terrain`: `start_row`, `current_region`, `draw_normal`, and
  `draw_black` remain descriptive because their PDB homes also hold other
  values. `MapVis`, masks, dimensions, and other unique records were recovered.
- `Add_GDI_Clip_Mask`: `y1v`, `y2v`, `xl`, and related edge values use reused
  homes. The source keeps the existing edge names.
- `draw_terrain_obstruction_map`: `TileY` shares a home with `yl`. The source
  keeps the proven parameter spelling and does not invent a separate `yl`.
- `Pick_Tile`, `pick_objects`, `sprite_check`, `pick_multi_objects`,
  `pick_touched_object`, `get_tile_picture`, `hit_tile`, `hit_object`,
  `start_scroll_view`, `handle_scroll_view`, and `AddDrawNode` contain similar
  aliases. The source does not collapse or merge those declarations.

These are evidence limits. They are not missing cleanup work.

## Complete procedure coverage

The scoped report contains 85 procedure records. I inspected parameters, locals,
register records, and function statics for each record. The three parent-owned
or compiler-generated records inside larger procedures were reviewed but not
edited as independent source functions.

### `RGE_View` records

- `00533510 RGE_View`: constructor. No stack locals; `this` reviewed.
- `00533760 ~RGE_View`: destructor. No stack locals; `this` reviewed.
- `00533940 setup`: direct parameter and buffer names recovered.
- `00533AC0 set_focus`: direct parameter recovered.
- `00533AF0 Init_Tile_Edge_Tables`: reused homes left unresolved.
- `00533E10 update_display_selected_objects`: no stack symbols; existing names retained.
- `00533EC0 display_object_selection`: direct parameters recovered.
- `00533F70 set_rect`: direct parameters recovered.
- `00534100 delete_surfaces`: no stack symbols; existing names retained.
- `00534130 create_surfaces`: no stack symbols; existing names retained.
- `00534340 calc_draw_vars`: no stack symbols; existing names retained.
- `00534420 set_redraw`: direct parameter recovered.
- `00534440 set_world`: direct parameter recovered.
- `00534500 set_player`: direct parameter recovered.
- `00534530 set_selection_area`: direct parameters recovered.
- `005345D0 get_selection_area`: direct parameters recovered.
- `005346F0 CreateBlitQueue`: direct records reviewed; reused homes preserved.
- `00534A00 ProcessQueuedBlit`: `WaitIfBusy` recovered.
- `00534AE0 draw`: direct locals reviewed; reused homes preserved.
- `00535210 update`: reused homes preserved.
- `00535480 draw_view`: `function_mode_in`, `draw_area_in`, and `save_render_rect`
  reviewed and recovered.
- `00535610 draw_object_outline`: direct locals reviewed; existing names retained.
- `005358B0 draw_paint_brush`: direct locals reviewed; existing names retained.
- `005359E0 pick`: reused parameter and local homes reviewed.
- `00535A80 pick_multi`: reused parameter and local homes reviewed.
- `00535C70 pick`: no stack symbols; existing names retained.
- `00535CB0 pick_through_fog`: `obj` recovered.
- `00535CC0 pick_weight`: `obj` and `confidence` recovered; the reused
  `select_level` local remains separate.
- `00535DA0 get_tile_screen_coords`: direct parameters recovered.
- `00535EB0 get_center_screen_pos`: direct `scr_x` and `scr_y` recovered.
- `00535ED0 get_start_coords`: direct parameters reviewed; existing names retained.
- `00535F20 get_center_coords`: direct parameters reviewed; existing names retained.
- `00535F70 get_tile_sizes`: direct parameters recovered.
- `00535FC0 get_max_size`: direct parameters recovered.
- `00535FE0 view_function`: direct parameters and unique locals recovered.
- `00536B40 view_function_terrain`: unique names recovered; reused homes kept
  descriptive as listed above.
- `005381C0 Update_Render_Pointers`: no stack symbols; existing names retained.
- `00538280 Add_GDI_Clip_Mask`: `SDI` and `Clip_Mask` recovered; edge aliases
  remain unresolved.
- `00538410 draw_multi_object_outline`: empty source body; no stack symbols.
- `00538420 Draw_GDI_Object`: `SDI` and `render_area` recovered.
- `00538590 get_tile_mask_num`: `VisibleMask` recovered.
- `00538710 draw_tile`: direct parameters and supported locals reviewed.
- `00538B80 draw_terrain_shape`: direct parameters reviewed.
- `00538D60 draw_terrain_obstruction_map`: direct tile names reviewed; reused
  `TileY` home remains documented.
- `00538E60 Get_Cursor_Position`: `Point`, `adjustX`, and `adjustY` recovered.
- `00538F00 Pick_Tile`: direct parameters and supported locals reviewed.
- `00539030 get_tile_bounding_coords`: direct parameters reviewed.
- `005390D0 pick_objects`: `Xpos`, `Ypos`, and `ignoreNeg` recovered.
- `00539510 sprite_check`: direct parameters reviewed; reused locals preserved.
- `005396F0 pick_multi_objects`: `Xpos1`, `Ypos1`, `Xpos2`, `Ypos2`, and
  `ignoreNeg` recovered; the reused object home remains separate.
- `00539930 pick_touched_object`: direct parameters recovered.
- `00539AA0 get_tile_picture`: direct parameters and supported locals reviewed.
- `00539B90 get_border_picture`: direct parameters recovered.
- `00539C80 get_border_edge_pictures`: direct parameters recovered.
- `00539D90 hit_tile`: direct parameters and supported locals reviewed.
- `00539EC0 hit_object`: direct parameters and supported locals reviewed.
- `0053A0D0 start_scroll_view`: direct parameters reviewed; reused result home
  preserved.
- `0053A290 handle_scroll_view`: direct parameters reviewed; unique saved-view
  names recovered and reused mouse value preserved.
- `0053A9C0 end_scroll_view`: local `point` recovered.
- `0053AAF0 do_paint`: direct parameters reviewed.
- `0053AC40 reset_overlay_sprites`: no stack symbols; existing names retained.
- `0053AC70 reset_cyclic_overlay_sprites`: no stack symbols; existing names retained.
- `0053ACD0 add_overlay_sprite`: direct mixed-style parameters recovered.
- `0053AD50 Object_Was_Displayed`: `ObjectID` and `InFogOK` recovered.

### `DClipInfo_List` records

- `0053AD90 DClipInfo_List`: direct constructor parameters recovered.
- `0053AE50 ~DClipInfo_List`: no stack symbols; existing names retained.
- `0053AED0 SetCaptureLevel`: `minLevel` and `maxLevel` recovered.
- `0053AF00 SetNumZones`: `New_Size` and `Ptrs` recovered.
- `0053AF90 InitNewZone`: `Zone_Size` recovered.
- `0053B000 GetNode`: no stack symbols; existing names retained.
- `0053B070 SetDrawRegion`: `Left`, `Top`, `Right`, and `Bottom` recovered.
- `0053B0A0 AddDrawNode`: direct parameters reviewed; reused local homes
  preserved.
- `0053B220 AddGDINode`: direct parameters recovered.
- `0053B300 LocateIDbyDrawLevel`: direct parameters recovered.
- `0053B370 Scroll`: `xDelta` and `yDelta` recovered.
- `0053B490 FreeNode`: `theNode` recovered.
- `0053B4B0 FreeThread`: `HeadNode` and `TailNode` recovered.
- `0053B510 ReclaimAllNodes`: no stack symbols; existing names retained.
- `0053B590 ResetStats`: no stack symbols; existing names retained.

### Parent-owned or compiler-generated records

These records share the source line span of a larger procedure. They have no
independent PDB stack or register symbols. They were reviewed as ownership
records, not edited as source functions:

- `00536912 FUN_00536912`.
- `00536932 caseD_3`.
- `00536957 FUN_00536957`.
- `005396AD FUN_005396ad`.
- `0053A999 FUN_0053a999`.
- `0053B475 FUN_0053b475`.

## Formatting and behavior limits

The source uses 1TBS opening braces. `else` clauses use `} else {` when they
have a braced body. Wrapping changes do not move statements or declarations.
Standalone scopes remain standalone scopes. Mixed PDB spelling remains mixed.

No comments or resource IDs were added. No member, global, class, ABI, or header
name was changed. No stack variables were merged. No declarations were moved.

## Risks and owner request

The main risk is the optimized stack-home record. A later matching build must
confirm that each recovered name still belongs to the intended declaration.
The terrain and clip helpers have the highest alias density. Their unresolved
names are intentional.

Owner 24 should review this report and the source diff before integration. Do
not edit `include/view.h` from this worker branch. Apply this exact declaration
update in the owner worktree. Keep the declaration types and order unchanged.
Only add the parameter names shown here:

```cpp
long setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, unsigned char color_in, int calc_draw_count_in, char* border_line_file);
void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
virtual void set_redraw(TPanel::RedrawMode redraw_mode);
void set_world(RGE_Game_World* world_in);
void set_player(RGE_Player* player_in);
void set_selection_area(long sel_col1_in, long sel_row1_in, long sel_col2_in, long sel_row2_in);
int get_selection_area(long& sel_col1_in, long& sel_row1_in, long& sel_col2_in, long& sel_row2_in, int fix_coords);
void display_object_selection(int id, int duration, int select_type, int reset_type);
int Get_Cursor_Position(tagPOINT& Point, int adjustX, int adjustY);
virtual int pick_through_fog(RGE_Static_Object* obj);
virtual int pick_weight(RGE_Static_Object* obj, int confidence);
virtual int start_scroll_view(unsigned char scroll_action_in, long x, long y, int ctrl_key, int shift_key);
virtual int handle_scroll_view(long x, long y);
virtual int do_paint(long old_x, long old_y, long new_x, long new_y, int up_down);
void add_overlay_sprite(TShape* theShape, int facet, int x, int y, int flags, int drawlevel, unsigned char* colorTable, int dispFunc, unsigned long DrawInterval);
bool Object_Was_Displayed(int ObjectID, bool InFogOK);
unsigned char pick_multi(unsigned char select_level, long x1, long y1, long x2, long y2);
unsigned char pick(unsigned char function_mode_in, unsigned char select_level, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos, void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y);
unsigned char pick(unsigned char pick_mode_in, unsigned char select_level, long x, long y, RGE_Pick_Info* pick_info, RGE_Static_Object* last_picked_object);
void get_center_screen_pos(short* scr_x, short* scr_y);
void get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
void get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
void get_tile_sizes(short* wid, short* hgt, short* half_wid, short* half_hgt);
void get_max_size(short* col_num, short* row_num);
int get_tile_screen_coords(short find_col, short find_row, short* scr_x, short* scr_y, int drop);

protected:
virtual void set_focus(int have_focus_in);
void CreateBlitQueue(tagRECT& src_rect, tagRECT& dest_rect, int xDelta, int yDelta);
void ProcessQueuedBlit(int WaitIfBusy);
int draw_tile(RGE_Tile* tile, unsigned char terrain_type, short x, short y, short map_col, short map_row, unsigned char visible, int norm_draw, int fog_draw);
int Pick_Tile(long x, long y, int* Tile_X, int* Tile_Y);
void get_tile_bounding_coords(int Tile_X, int Tile_Y, int& bx1, int& by1, int& bx2, int& by2);
int pick_objects(int Xpos, int Ypos, int min_level, int max_level, int range, int max_confidence, int ignoreNeg);
int pick_multi_objects(int Xpos1, int Ypos1, int Xpos2, int Ypos2, int min_level, int max_level, int player, unsigned char select_level, int ignoreNeg);
int pick_touched_object(DClipInfo_List* obj_list, int Xpos, int Ypos, int min_level, int max_level, int& touched_object_id);
int sprite_check(unsigned char* Shape_Base, Shape_Info* Shape, int check_x, int check_y);
void draw_terrain_shape(int x, int y, TShape* shape, int index, unsigned char visible, unsigned char draw_attribute, int draw_normal, int draw_fog);
void draw_terrain_obstruction_map(int x, int y, TShape* shape, int index, int TileX, int TileY);
void draw_view(unsigned char function_mode_in, TDrawArea* draw_area_in);
long view_function_terrain(unsigned char function_mode_in, tagRECT save_render_rect);
long view_function(unsigned char function_mode_in, unsigned char function_parm_in, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos, void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y);
short get_tile_picture(unsigned char terrain_type, unsigned char tile_type, short map_col, short map_row);
short get_border_picture(unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row);
int get_border_edge_pictures(unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row, int& top_index, int& right_index, int& left_index, int& bottom_index);
RGE_Static_Object* hit_object(RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos, short* item_scr_x, short* item_scr_y, RGE_Static_Object* orig_picked_obj, unsigned char fog_flag);
int hit_tile(RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos);
void Add_GDI_Clip_Mask(DClipInfo_Node* SDI, TSpan_List_Manager* Clip_Mask);
void Draw_GDI_Object(DClipInfo_Node* SDI, TDrawArea* render_area);
int get_tile_mask_num(int map_col, int map_row, int map_width, int map_height, unsigned long VisibleMask);
```

Owner 24 must also name the affected `DClipInfo_List` declarations as follows:

```cpp
DClipInfo_List(int InitialSize, int GrowSize, int szitem, int top_Yline, int bottom_Yline, int mxLevel);
void SetDrawRegion(int Left, int Top, int Right, int Bottom);
void Scroll(int xDelta, int yDelta);
void SetCaptureLevel(int minLevel, int maxLevel);
DClipInfo_Node* AddGDINode(int GDI_Type, int SortLine, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, int DrawLevel, int DrawColor, int Object_ID);
void AddDrawNode(void* ShapeBase, Shape_Info* theShape, int SortLine, int Xpos, int Ypos, int DrawFlags, unsigned char* ColorTable, int XformMask, int DrawLevel, int Object_ID);
DClipInfo_Node* LocateIDbyDrawLevel(int SearchID, int StartLevel, int EndLevel, int NodeType);
void FreeNode(DClipInfo_Node* theNode);
int FreeThread(DClipInfo_Node* HeadNode, DClipInfo_Node* TailNode);

private:
void SetNumZones(int New_Size);
void InitNewZone(int Zone_Size);
```

The long declarations remain wrapped in the header when needed. This request
does not authorize any header layout or ABI change.

## Changed files

- `src/view.cpp`: recovered names and readable short-signature wrapping.
- `workflow/decomp_notes/source_cleanup/wave04/view.md`: evidence, coverage, risks, and
  the exact owner-24 header request.

No other file is part of this correction.

## Correction history

- Base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Initial cleanup commit: `e2182159345429652b16d887b8549fb63ad8cf15`.
- Correction commit: `dd1e6f50e70f9b242ce4ff651a83f8db4b8fd788`.
- This correction pass removed forced aliases from reused stack homes.
- It corrected `view_function_terrain`'s parameter to the PDB-backed
  `save_render_rect` name instead of using the local `panel_rect` record.
- It restored direct PDB spellings in the view, picking, cursor, GDI, overlay,
  and clip-list procedures.
- It applied the remaining 1TBS brace and `else` formatting changes.
- Final source commit: `321a8b461a41ed4d91faae9fa1634e3b2b7c1482`.
- The final source commit joins readable four-to-six parameter signatures and
  keeps long traversal and GDI signatures wrapped.
- Review correction: clarified the executable oracle and the reference-evidence
  role of the PDB and inventory.

## Exact non-execution statement

Compilation, matching, audits, and tests were not run.

Builds, compiler checks, audits, validation checks, tests, matching checks, and
game runs were not run. No compiler, linker, matcher, audit, test, or game
command was run in this worker slot.

The only review actions were evidence reading, source inspection, identifier
review, formatting review, and Git diff review. Final comparison remains the
owner and integration stage responsibility.
