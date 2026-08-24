// VA: 004B9140 TShape::shape_check
// Attempt log:
// 1: The initial typed overlay matched calls and frame shape, but differed by 503 bytes.
// 2: The string literal removed a raw address. Relocations changed; code bytes did not.
// 3: Typed row arrays worsened the overlay by two bytes.
// 4: Nested guards matched the original size and CFG better than early returns.
// 5: The canonical TShape surface worsened the prologue, but removed invented fields.
// 6: Shape_Info pointer declaration forms were duplicates under that surface.
// 7: A four-variant ownership lab found one 688-byte basin and no exact result.
// 8: The nearby sprite decoder supported typed row arrays. They improved canonical output.
// 9: An ordinary opcode local reached 701 bytes, but moved the stream register basin.
// 10: The decompiler-supported default-only switch worsened size and block coverage.
// 11: A named legacy Shape_Header improved the mismatch to 527 bytes.
// 12: bool flags and unsigned count locals emitted duplicate code.
// 13: <memory.h> context moved the mismatch to 501 bytes and restored exact blocks.
// 14: Direct row-offset access under that context reached the best 499-byte mismatch.
// 15: Direct FShape base ownership was codegen-equivalent to the typed owner.
// Current clean model: canonical TShape and records, natural guards, typed row ownership,
// a real packed-payload stream pointer, and no raw address or explicit home reuse.
// Remaining drift is the stream pointer basin, switch register coloring, and legacy tail.
// Result remains unresolved. It is not accepted_drift-safe.
//
// sa-513701e4-r1 (2026-08-22):
// - Direct nested data-offset addressing, declaration-order changes, branch-local
//   stream cursors, and the decompiler's two-cursor SLP walk were codegen duplicates.
// - Char and int opcode locals moved to shorter or different basins and worsened
//   strict drift or size. Unsigned offset fields were also codegen-equivalent.
// - Direct legacy ymax access improved strict drift by one byte, but lost shape and
//   exact blocks. Function-scope curx and one shared done flag were duplicates.
// - The Ghidra packet confirms the original EAX stream cursor, x-home opcode, and
//   separate legacy cursor/flag topology. Natural source variants did not recover it.
//
// continuation Shape-prefix audit:
// - PDB locals identify one shared uchar `command`, uchar `done`, and long `r`.
//   Using that natural shared command improved strict drift from 499 to 498 bytes.
// - Typed data-table indexing, nested offset expressions, branch-local cursors,
//   and FShape->Version ownership were duplicate or worse. The EAX cursor basin
//   remains unresolved, so this owner stays outside the prefix wrapper.

#include <memory.h>

#ifndef AOE1_SHAPE_CONTEXT_H
struct Shape_Info {
    long Shape_Data_Offsets;
    long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct Shape_File_Header {
    long version;
    long shape_num;
};

struct Shape_Offsets {
    long shape;
    long palette;
};

struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

class TShape {
public:
    unsigned char* shape;             // +00
    int load_type;                    // +04
    int load_size;                    // +08
    Shape_Header* shape_header;       // +0c
    Shape_File_Header* head;          // +10
    Shape_Offsets* offsets;           // +14
    SLhape_File_Header* FShape;       // +18
    Shape_Info* shape_info;           // +1c
    unsigned char Check_shape(long, char*);
    unsigned char shape_check(long x, long y, long frame);
};
#endif

unsigned char TShape::shape_check(long x, long y, long frame)
{
    unsigned char* p;
    unsigned char command;

    if (frame < 0) return 0;
    if (Check_shape(frame, "RGL_shape_draw")) return 0;

    unsigned char* base = (unsigned char*)this->FShape;
    if (base != 0) {
        Shape_Info* info;
        int px;
        int py;
        int width;
        info = &this->shape_info[frame];
        px = info->Hotspot_X + x;
        py = info->Hotspot_Y + y;
        width = info->Width;
        if (px < 0 || py < 0 || px >= width || py >= info->Height) return 0;
        int row_offset = py * 4;
        unsigned char* rowtab = base + info->Shape_Outline_Offset;
        int minx = *(short*)(rowtab + row_offset);
        int span = *(short*)(rowtab + row_offset + 2);
        if (minx < 0 || px < minx || px > width - span) return 0;
        unsigned char* data = base + info->Shape_Data_Offsets;
        int data_offset = *(int*)(data + row_offset);
        p = base + data_offset;
        while (minx < width) {
            if (px < minx) return 0;
            command = *p++;
            switch (command & 0xf) {
            case 0: case 4: case 8: case 12: {
                unsigned int n = ((unsigned int)command) >> 2;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 2: {
                unsigned int n = (((unsigned int)command) << 4) | *p++;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 1: case 5: case 9: case 13: {
                unsigned int n = ((unsigned int)command) >> 2;
                minx += n;
                break;
            }
            case 3: {
                unsigned int n = (((unsigned int)command) << 4) | *p++;
                minx += n;
                break;
            }
            case 6: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0) n = *p++;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 7: case 10: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0) n = *p++;
                minx += n;
                if (px < minx) return 1;
                ++p;
                break;
            }
            case 11: case 14: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0) n = *p++;
                minx += n;
                if (px < minx) return 1;
                break;
            }
            case 15:
                return 0;
            default:
                return 0;
            }
        }
                return 0;
            } else {
                Shape_Header* header = (Shape_Header*)(this->shape + this->offsets[frame].shape);
                this->shape_header = header;
                int minY = header->ymin;
                int minX2 = header->xmin;
                int maxX2 = header->xmax;
                p = (unsigned char*)(header + 1);
                int maxY2 = header->ymax;
                if (y < minY || y > maxY2 || x < minX2 || x > maxX2) return 0;
                if (minY < y) {
                    int rows = y - minY;
                    do {
                        unsigned char done = 0;
                        do {
                            command = *p++;
                            if ((command & 1) == 1) {
                                command >>= 1;
                                if (command == 0) done = 1; else p += command;
                            } else {
                                if ((command & 0xfe) == 0) done = 1; else ++p;
                            }
                        } while (!done);
                        --rows;
                    } while (rows != 0);
                }
                long r = minX2;
                unsigned char done = 0;
                do {
                    command = *p++;
                    if ((command & 1) == 1) {
                        command >>= 1;
                        if (command == 0) {
                            int n = *p;
                            r += n;
                            if (r > x) return 0;
                        } else {
                            r += command;
                            if (r > x) return 1;
                            p += command;
                        }
                    } else {
                        command >>= 1;
                        if (command == 0) {
                            done = 1;
                        } else {
                            r += command;
                            if (r > x) return 1;
                        }
                        ++p;
                    }
                } while (!done);
            }
    return 0;
}
