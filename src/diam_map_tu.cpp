// Authentic PDB-ordered wrapper for C:\\msdev\\work\\age1_x1\\diam_map.cpp.
//
// The reviewed diam_map context supports the constructor, destructor, setup,
// and accepted-drift set_bitmap owners as one source prefix. Later standalone
// owners use incompatible class declarations. Keep those owners blocked rather
// than add aliases, namespaces, dummy bodies, or manual vtables.
//
// The nearby compiler-generated vector deleting destructor at 00436910 has no
// source owner. It is recorded as blocked in the candidate proposal.

#include "../include/diam_map_context.h"

// PDB order: diam_map.cpp lines 40-221.
#include "matching/00436830_RGE_Diamond_Map.cpp"
#include "matching/00436930_RGE_Diamond_Map.cpp"
#include "matching/004369C0_setup.cpp"
#include "accepted_drift/00436A10_set_bitmap.cpp"
