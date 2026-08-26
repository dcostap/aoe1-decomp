// VA: 0046D770 PathingSystem::printState
// PDB source: pathsys.cpp, lines 2233-2242
// Attempt log:
// - Replaced the prior placeholder with the binary-supported printState source
//   shape: two cdecl virtual debug calls followed by an indexed open-path scan.
// - Canonical ownership: MGP_openPaths is an 8-byte MGP_FloatHeap array at
//   +0x4F614, facetValue is [255][255] at +0x0C, and the counters/mask are the
//   named fields at +0x11DC2C/+0x11DC38/+0x11DCD8.
// - A natural MGP_FloatHeap* loop was exact-size but anchored at +0x4F61C;
//   the executable proves the source cursor is the interior y byte at +0x4F61D,
//   so the living source keeps that narrow, binary-supported cursor form.
// - Probe 1 baseline: natural typed record pointer and > 0 guard, 18 differing
//   bytes; the compiler added a redundant count test and used the record base.
// - Probe 2: one-based `i <= numberOpenPathsValue` guard corrected the branch
//   shape and mask offset; 6 differing bytes remained at the record cursor.
// - Probe 3: anchored the cursor at `MGP_openPaths[1].y` with proven byte/dword
//   offsets; exact 190-byte match.
// - Module closure repair: the PDB owner is protected (`IAE`), and the
//   canonical RGE_Static_Object virtual surface owns the slots through
//   0x140 before the derived variadic print slot at 0x144.

#include "../../include/pathsys_context.h"

void PathingSystem::printState(RGE_Moving_Object* obj)
{
    obj->print("    There are %d open paths and %d traversed paths.",
        this->numberOpenPathsValue, this->numberTraversedPathsValue);
    obj->print("    The open paths:");

    int i = 1;
    if (i <= this->numberOpenPathsValue) {
        unsigned char* path = &this->MGP_openPaths[1].y;
        do {
            unsigned char facet = this->facetValue[path[-1]][path[0]];
            if ((facet & 0xf8) == this->CurrentFacetMask) {
                facet &= 7;
            } else {
                facet = 0xff;
            }
            obj->print("      %5d: (%d, %d), total=%d, facet=%d.",
                i, path[-1], path[0], *(int*)(path + 3), facet);
            ++i;
            path += 8;
        } while (i <= this->numberOpenPathsValue);
    }
}
