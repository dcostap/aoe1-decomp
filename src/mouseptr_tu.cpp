// Authentic Mouseptr.cpp owner wrapper.
//
// PDB source order is the address order below. The module starts with the
// TMousePointer constructor and ends with GetDDBltError at 0045C300.
// Each include owns one canonical VA exactly once. Padding, generated
// destructors, and the next RGE_Moving_Object module are not included.
//
// Canonical type ownership is in mouseptr_context.h. The class layout follows
// the original 0x254-byte TMousePointer, 0x100-byte TDrawArea, 0x47C-byte
// TDrawSystem, and 0x20-byte TShape surfaces.
//
// PDB-qualified owner sequence:
// TMousePointer::TMousePointer, ~TMousePointer, Shutdown_Mouse,
// Restore_Mouse, setup, set_game_mode, set_game_enable, get_game_enable,
// in_game_mode, set_game_window, LoadCursors, delete_surfaces,
// create_surfaces, update_mouse_position, draw, erase, set_facet,
// set_game_facet, off, on, reset, center, Poll, and GetDDBltError.
//
// PDB line bands used for the priority owners are LoadCursors 372-484,
// create_surfaces 528-559, update_mouse_position 567-717, and draw 724-875.
// The source order inside each priority body follows those line bands; no
// synthetic dummy function supplies translation-unit context.
//
// The module flag evidence is the original EH registration and cleanup in
// create_surfaces (0045B5D0). Use config/flags/mouseptr_module_gx.rsp:
// /nologo /c /O2 /Oy /GX. Per-function checker runs retain their mapped flags.
//
// Exact anchors: 0045B000, 0045B0A0, 0045B120, 0045B2A0-0045B2E0,
// 0045BF80, and 0045C010. The prioritized LoadCursors and update path remain
// scratch. create_surfaces, draw, set_facet, and set_game_facet retain their
// reviewed accepted-drift status and comments.

#include "../include/mouseptr_context.h"

#include "scratch/0045AE50_TMousePointer.cpp"
#include "matching/0045B000_TMousePointer.cpp"
#include "matching/0045B040_Shutdown_Mouse.cpp"
#include "matching/0045B0A0_Restore_Mouse.cpp"
#include "matching/0045B120_setup.cpp"
#include "matching/0045B290_set_game_mode.cpp"
#include "matching/0045B2A0_set_game_enable.cpp"
#include "matching/0045B2B0_get_game_enable.cpp"
#include "matching/0045B2C0_in_game_mode.cpp"
#include "matching/0045B2E0_set_game_window.cpp"
#include "matching/0045B310_LoadCursors.cpp"
#include "accepted_drift/0045B560_delete_surfaces.cpp"
#include "matching/0045B5D0_create_surfaces.cpp"
#include "matching/0045B760_update_mouse_position.cpp"
#include "accepted_drift/0045BA60_draw.cpp"
#include "matching/0045BD60_erase.cpp"
#include "matching/0045BE20_set_facet.cpp"
#include "accepted_drift/0045BE80_set_game_facet.cpp"
#include "matching/0045BEE0_off.cpp"
#include "matching/0045BF40_on.cpp"
#include "matching/0045BF80_reset.cpp"
#include "matching/0045BF90_center.cpp"
#include "matching/0045C010_Poll.cpp"
#include "matching/0045C300_GetDDBltError.cpp"
