// Canonical view.cpp context for the recovered RGE_View surface.
// Owners appear once and follow the original PDB source-line order.
// The omitted view.cpp owners still need conversion to this shared surface.
#define RGE_VIEW_SHARED_CONTEXT 1
#include "../include/view_tu_context.h"

#include "matching/00534100_delete_surfaces.cpp"
#include "matching/00534130_create_surfaces.cpp"
#include "scratch/00534340_calc_draw_vars.cpp"
#include "matching/00535480_draw_view.cpp"
#include "scratch/00535610_draw_object_outline.cpp"
#include "matching/00535EB0_get_center_screen_pos.cpp"
#include "matching/00535ED0_get_start_coords.cpp"
#include "matching/00535F20_get_center_coords.cpp"
#include "matching/00535F70_get_tile_sizes.cpp"
#include "matching/00535FC0_get_max_size.cpp"
#include "matching/005381C0_Update_Render_Pointers.cpp"
#include "matching/00538280_Add_GDI_Clip_Mask.cpp"
#include "matching/00538410_draw_multi_object_outline.cpp"
#include "matching/00538420_Draw_GDI_Object.cpp"
#include "matching/00538590_get_tile_mask_num.cpp"

#undef RGE_VIEW_SHARED_CONTEXT
