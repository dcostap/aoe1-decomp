// 004B9070 shape_minmax (Shape.cpp:319-342)
// PDB source: Shape.cpp (TShape::shape_minmax)
//
// Attempt log:
// attempt 1: if/return; early returns inline, no shared epilogue. 85% diff.
// attempt 2: goto; still early returns, early pop edi in path2. 192/197 bytes.
// attempt 3: do-while(0); result in bl, extra ebx save. 197b but prologue wrong.
// attempt 4: nested if(facet>=0){if(!Check_shape){...}} return 0; EXACT MATCH.
// Key: nested if-guard instead of early return produces correct shared epilogue
// and prevents compiler from popping edi early in path2.

#include "../../include/shape_context.h"

unsigned char TShape::shape_minmax(long& out_minx, long& out_miny,
                                    long& out_maxx, long& out_maxy,
                                    long facet) {
    if (facet >= 0) {
        if (!Check_shape(facet, "RGL_shape_minxy")) {
            if (FShape != 0) {
                out_minx = -shape_info[facet].Hotspot_X;
                out_miny = -shape_info[facet].Hotspot_Y;
                out_maxx = shape_info[facet].Width - shape_info[facet].Hotspot_X - 1;
                out_maxy = shape_info[facet].Height - shape_info[facet].Hotspot_Y - 1;
            } else {
                shape_header = (Shape_Header*)(shape + offsets[facet].shape);
                out_minx = shape_header->xmin;
                out_miny = shape_header->ymin;
                out_maxx = shape_header->xmax;
                out_maxy = shape_header->ymax;
            }
            return 1;
        }
    }
    return 0;
}
