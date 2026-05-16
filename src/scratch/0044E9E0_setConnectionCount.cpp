// 0044E9E0 InfluenceMap::setConnectionCount
// PDB: infmap.cpp:394-458, 498 bytes
// Attempt log:
// - v1: reconstructed from packet/decompiler with explicit loop locals and switch-neighbor walk.
// - v2: changed validation early returns to shared invalid epilogue and padded locals to 0x24 frame to match original shape.
// BLOCKER: behavior and core switch/neighbor logic are reconstructed, but rebuilt main .text is 480 bytes vs original 498 so check_function cannot compare. Remaining mismatch is broad source-shape/register-allocation: original loads param_1 before saving registers, keeps `this` in EDI, uses a 0x24 local frame with many named stack slots, and forms row access as `(j - yRef*4 + rowValue)`; rebuilt uses a 0x20 frame, different parameter/register topology, early compact invalid epilogue, and a different inner row-address sequence. Need a closer source topology for validation/setup and inner loop locals before exact matching.

typedef unsigned char uchar;
typedef unsigned int uint;
struct XYPoint { int x; int y; };

class InfluenceMap {
public:
    int gap0;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int gap14;
    uchar** rowValue;
    int gap1c;
    int connectionCountValue;
    int setConnectionCount(const XYPoint& p1, const XYPoint& p2, int threshold, int p4, int p5, int p6);
};

int InfluenceMap::setConnectionCount(const XYPoint& p1, const XYPoint& p2, int threshold, int p4, int p5, int p6)
{
    InfluenceMap* self = this;
    int xSize;
    int ySize;
    int xi;
    int y;
    int rowOffset;
    uchar** rowBase;
    int dx;
    int dummy;

    self->connectionCountValue = 0;
    xi = p1.x;
    if (xi < 0) goto invalid;
    if (p1.y < 0) goto invalid;
    xSize = self->xSizeValue;
    if (xi >= xSize) goto invalid;
    ySize = self->ySizeValue;
    if (p1.y >= ySize) goto invalid;
    if (p2.x < 0) goto invalid;
    if (p2.y < 0) goto invalid;
    if (p2.x >= xSize) goto invalid;
    if (p2.y >= ySize) goto invalid;

    if (xi > p2.x) goto done;
    do {
        y = p1.y;
        if (y > p2.y) goto next_x;
        rowBase = self->rowValue;
        dx = xi - self->xReferencePointValue;
        rowOffset = y * 4;
        do {
            uchar* row = *(uchar**)((char*)rowBase + rowOffset - (self->yReferencePointValue << 2));
            if ((int)(uint)row[dx] >= threshold) {
                int ny = y;
                int nx = xi;
                int nrowOffset = rowOffset;
                int dir = 0;
                do {
                    switch (dir) {
                    case 0: nx--;
                    case 7: ny--; nrowOffset -= 4; break;
                    case 1:
                    case 2: nx++; break;
                    case 3:
                    case 4: ny++; nrowOffset += 4; break;
                    case 5:
                    case 6: nx--; break;
                    }
                    if (p6 != 0 || (dir % 2) != 0) {
                        if (nx >= 0 && nx < xSize && ny >= 0 && ny < ySize) {
                            uchar* nrow = *(uchar**)((char*)rowBase + nrowOffset - (self->yReferencePointValue << 2));
                            if ((int)(uint)nrow[nx - self->xReferencePointValue] >= threshold) {
                                self->connectionCountValue++;
                            }
                        } else if ((p4 == 1 && (dir % 2) == 1) || (p5 == 1 && (dir % 2) == 0)) {
                            self->connectionCountValue++;
                        }
                    }
                    dir++;
                } while (dir < 8);
            }
            rowOffset += 4;
            y++;
        } while (y <= p2.y);
next_x:
        xi++;
    } while (xi <= p2.x);

done:
    return self->connectionCountValue;
invalid:
    dummy = 0;
    return dummy;
}
