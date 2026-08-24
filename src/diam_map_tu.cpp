// Authentic PDB-ordered wrapper for C:\\msdev\\work\\age1_x1\\diam_map.cpp.
//
// The reviewed diam_map context supports the constructor, destructor, setup,
// accepted-drift set_bitmap, and the two early scratch owners as one source
// prefix. The scratch owners stay observed until their body mismatches close.
// Later standalone owners use incompatible class declarations. Keep those
// owners blocked rather than add aliases, namespaces, dummy bodies, or manual
// vtables.
//
// The nearby compiler-generated vector deleting destructor at 00436910 has no
// source owner. It is recorded as a generated entry in the candidate proposal.

#include "../include/diam_map_context.h"

// PDB order: diam_map.cpp lines 40-569 for the recoverable owners.
// Flags: config/flags/00436930_RGE_Diamond_Map.rsp (/O2 /Oy /GX).
#include "matching/00436830_RGE_Diamond_Map.cpp"
#include "matching/00436930_RGE_Diamond_Map.cpp"
#include "matching/004369C0_setup.cpp"
#include "accepted_drift/00436A10_set_bitmap.cpp"
#include "scratch/00436C30_set_world.cpp"
#include "scratch/004374C0_clear_image.cpp"
