// VA: 004B9140 TShape::shape_check
// Attempt log:
// 1: direct reconstruction from packet/listing with local byte-stream decoder.
// 2: fixed TShape field layout after dump showed +14/+18/+1c were shifted by 4.
// 3: added explicit case 15 because original switch accepts 0..15 then case 15 returns false; now same-size 701B but broad mismatch.
// 4: dump shows exact prologue/early field layout through row table, but first real topology divergence is around row-byte pointer setup: original keeps EAX as stream pointer and ESI as row offset/index; rebuilt flips stream into ESI and uses EAX for opcode value, shifting the entire switch decoder and no-data decoder.
// 5: retain the established raw TShape offsets but type the per-frame record;
//    the original's x parameter home is reused as the stream opcode below.
// 6: a full typed TShape/SLhape_File_Header surface moved frame into ESI before
//    the prologue and shortened the function; rolled back to the proven offset
//    surface while keeping the typed per-frame ownership.
// 7: typed per-frame ownership plus x-home opcode reuse improved the positional
//    diff to 505 bytes, but the compiler still chose the wrong stream register.
// 8: an explicit data-offset row pointer was codegen-equivalent; no new lead.
// 9: donor-era <memory.h> changed the prologue basin and worsened the diff;
//    rolled back.
// 10: opcode variant lab: a scoped local copied through x retained 701 bytes
//     and reached 441 positional diff bytes, but is compiler-steering scaffolding;
//     the living source stays the natural typed/x-home form (684-byte output).
// left in scratch: canonical per-frame Shape_Info decoder and legacy walk are
// reconstructed; remaining drift is the stream pointer/register basin, switch
// case reload/coloring, and legacy tail layout. Not accepted_drift-safe.

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class TShape {
public:
    char* base0;          // +00
    char gap04[8];
    char* current;        // +0c
    char gap10[4];
    void* table14;        // +14
    char* shapeData;      // +18
    char* frames;         // +1c
    unsigned char Check_shape(long, char*);
    unsigned char shape_check(long x, long y, long frame);
};

unsigned char TShape::shape_check(long x, long y, long frame)
{
    if (frame < 0) return 0;
    if (Check_shape(frame, (char*)0x00587058)) return 0;

    char* base = this->shapeData;
    if (base != 0) {
        char* fr = this->frames + (frame << 5);
        Shape_Info* info = (Shape_Info*)fr;
        int px = info->Hotspot_X + x;
        int py = info->Hotspot_Y + y;
        int width = info->Width;
        if (px < 0 || py < 0 || px >= width || py >= info->Height) return 0;
        char* rowtab = base + info->Shape_Outline_Offset;
        int minx = *(short*)(rowtab + py * 4);
        int span = *(short*)(rowtab + py * 4 + 2);
        if (minx < 0 || px < minx || px > width - span) return 0;
        int* row = (int*)(base + info->Shape_Data_Offsets);
        unsigned char* p = (unsigned char*)(base + row[py]);
        while (minx < width) {
            if (px < minx) return 0;
            x = *p++;
            switch (x & 0xf) {
            case 0: case 4: case 8: case 12: {
                int n = ((unsigned int)x) >> 2;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 2: {
                int n = (((unsigned int)x) << 4) | *p++;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 1: case 5: case 9: case 13: {
                int n = ((unsigned int)x) >> 2;
                minx += n;
                break;
            }
            case 3: {
                int n = (((unsigned int)x) << 4) | *p++;
                minx += n;
                break;
            }
            case 6: {
                int n = ((unsigned int)x) >> 4;
                if (n == 0) n = *p++;
                minx += n;
                if (px < minx) return 1;
                p += n;
                break;
            }
            case 7: case 10: {
                int n = ((unsigned int)x) >> 4;
                if (n == 0) n = *p++;
                minx += n;
                if (px < minx) return 1;
                ++p;
                break;
            }
            case 11: case 14: {
                int n = ((unsigned int)x) >> 4;
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
    }

    char* rec = this->base0 + *(int*)((char*)this->table14 + frame * 8);
    this->current = rec;
    int minY = *(int*)(rec + 0x0c);
    int minX2 = *(int*)(rec + 8);
    int maxX2 = *(int*)(rec + 0x10);
    unsigned char* p = (unsigned char*)(rec + 0x18);
    int maxY2 = *(int*)(rec + 0x14);
    if (y < minY || y > maxY2 || x < minX2 || x > maxX2) return 0;
    if (minY < y) {
        int rows = y - minY;
        do {
            unsigned char done = 0;
            do {
                unsigned char c = *p++;
                if ((c & 1) == 1) {
                    c >>= 1;
                    if (c == 0) done = 1; else p += c;
                } else {
                    if ((c & 0xfe) == 0) done = 1; else ++p;
                }
            } while (!done);
            --rows;
        } while (rows != 0);
    }
    int curx = minX2;
    unsigned char done = 0;
    do {
        unsigned char c = *p++;
        if ((c & 1) == 1) {
            c >>= 1;
            if (c == 0) {
                int n = *p;
                curx += n;
                if (curx > x) return 0;
            } else {
                curx += c;
                if (curx > x) return 1;
                p += c;
            }
        } else {
            c >>= 1;
            if (c == 0) {
                done = 1;
            } else {
                curx += c;
                if (curx > x) return 1;
            }
            ++p;
        }
    } while (!done);
    return 0;
}
