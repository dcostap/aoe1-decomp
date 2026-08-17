// VA: 004E0670 TribeInformationAIModule::setupWalls
// PDB: taiinfmd.cpp:5918-6326
//
// Baseline reconstruction: the function lays out the four possible gate
// rectangles, then traces one of three wall perimeters.  XYPoint follows the
// taiinfmd.cpp local/source convention (y at offset 0, x at offset 4).
// Attempt log:
// - baseline: typed gate arrays and natural perimeter loops; frame was 0x30,
//   and the mode-2 source was two call sites short.
// - restored the binary-proven final mode-2 y-minus pass (62/62 calls).
// - kept the mode-1 parameter-home/unsigned-count reconstruction; it moved the
//   first setup hunk deeper but did not settle register coloring.
// - a direct min/max point rewrite was structurally worse and was reverted.
// - separated the mode-2 inner counter as iVar10; no frame change, small gain.
// - diagnostic grouping of six independent points plus local_4 into an invented
//   aggregate recovered the 0x34 frame, but was compiler-steering scaffolding;
//   the main-agent audit removed it and restored ordinary PDB-style locals.
// - a gate-base local and register-qualified parameter probes were codegen
//   duplicates and were not retained as matching evidence.
// - corrected all insideGate/storeLot coordinate argument order from the
//   original push sequence; resync improved to 60.36%.
// - tested the mode-3 outer counter in the proven param_7 home; VC5 emitted
//   identical code, so the natural local counter remains retained.
// - tested using the mapped mode-2 realMinDC.x for the perimeter start; size
//   moved 4 bytes closer but positional diff worsened, so rolled it back.
// - flattened all repeated mode-2 guards and used max.x as each inner count;
//   this reached the exact 2253-byte size and a 1737-byte strict diff.
// - a canonical x,y WallPoints aggregate plus local_4 recovered the 0x34
//   frame, exact mapBound pointer windows, and 78.9% shape, but strict diff
//   worsened to 2065; it was rejected as compiler-steering scaffolding.
// Current normalized pause: exact 2253-byte size, natural 0x30 frame, and
// 62/62 ordered calls. Remaining drift is prologue allocation and local colors;
// the original keeps param_1 in EBX and param_4 in EDI.

struct XYPoint {
    int y;
    int x;
};

class TribeInformationAIModule {
public:
    char gap_000[0x1B0];
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];

    int mapBound(XYPoint* point);
    int insideGate(int gate, int y, int x);
    void storeLot(int type, unsigned char y, unsigned char x, unsigned char state);
    void setupWalls(int param_1, int param_2, int param_3, int param_4,
                    int param_5, int param_6, int param_7, int param_8);
};

extern int debug_rand(char* file, int line);

void TribeInformationAIModule::setupWalls(int param_1, int param_2, int param_3, int param_4,
                                           int param_5, int param_6, int param_7, int param_8)
{
    XYPoint realMaxF4;
    XYPoint realMax;
    XYPoint realMin;
    XYPoint realMinDC;
    XYPoint min;
    XYPoint max;
    int count;
    int iVar10;

    if (param_8 == 1 && param_6 > 0) {
        this->numberGatesValue = param_6;

        int slot = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x1731) % 4;
        int half = param_7 / 2;

        this->minGatePosition[slot].y = param_1 - half;
        this->minGatePosition[slot].x = param_2 - param_4 * 2;
        this->maxGatePosition[slot].y = param_1 + half;
        this->maxGatePosition[slot].x = param_2;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].y = param_1 + half;
        this->minGatePosition[slot].x = param_2;
        this->maxGatePosition[slot].y = param_4;
        this->maxGatePosition[slot].x = param_2 + param_4 * 2;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].y = param_1;
        this->minGatePosition[slot].x = param_2 - half;
        this->maxGatePosition[slot].y = param_1 + param_4 * 2;
        this->maxGatePosition[slot].x = param_2 + half;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].y = param_1 - param_4 * 2;
        this->minGatePosition[slot].x = param_2 - half;
        this->maxGatePosition[slot].y = param_1;
        this->maxGatePosition[slot].x = param_2 + half;

        if (param_6 > 0) {
            XYPoint* gate = this->maxGatePosition;
            count = param_6;
            do {
                this->mapBound(gate - 4);
                this->mapBound(gate);
                ++gate;
                --count;
            } while (count != 0);
        }
    }

    if (param_5 == 0) {
        param_5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x176A) % 3;
    }

    if (param_5 == 1) {
        if (param_3 <= param_4) {
            int old_x = param_3 + param_2;
            int old_y = param_1 - param_2;
            param_2 = param_2 - param_3;
            param_4 = old_y;
            count = (param_4 - param_3 + 3U) / 3;
            param_3 = old_x;

            do {
                realMinDC.x = param_2;
                min.y = param_4 + param_2;
                this->mapBound(&realMinDC);

                max.y = param_4 + param_3;
                min.x = param_3;
                this->mapBound(&min);

                int y = realMinDC.y;
                int x = realMinDC.x;

                if (y < min.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                    } while (y < min.y);
                }
                if (x < min.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                    } while (x < min.x);
                }
                if (min.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                    } while (min.y < y);
                }
                if (realMinDC.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                    } while (realMinDC.x < x);
                }

                param_2 -= 3;
                param_3 += 3;
                --count;
            } while (count != 0);
            return;
        }
    } else if (param_5 == 2) {
        param_8 = param_3;
        if (param_3 <= param_4) {
            param_7 = param_3 + param_2;
            int old_y = param_1 - param_2;
            int offset = param_2 - param_3;
            max.y = (param_4 - param_3) + 1;
            int x = offset;
            param_3 = param_3 * 2;

            do {
                realMin.y = offset + old_y;
                realMin.x = offset;
                this->mapBound(&realMin);

                max.y = param_8 + 1;
                realMax.x = param_2 - 1 + max.y;
                realMax.y = realMax.x + old_y;
                this->mapBound(&realMax);

                realMinDC.y = x + old_y;
                realMinDC.x = x;
                this->mapBound(&realMinDC);

                realMaxF4.x = param_7;
                realMaxF4.y = param_7 + old_y;
                this->mapBound(&realMaxF4);

                int y = realMinDC.y;
                int i = param_8;

                if (param_3 > 0) {
                    iVar10 = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                        --iVar10;
                    } while (iVar10 != 0);
                }
                if (param_3 > 0) {
                    max.x = param_3;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = param_3;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = param_8;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }

                max.x = max.y;
                if (param_3 >= 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_3;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = max.y;
                if (param_3 >= 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_8;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_3;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_8;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }

                param_8 += 2;
                offset -= 2;
                --x;
                ++param_7;
                param_3 += 4;
                --max.y;
            } while (max.y != 0);
            return;
        }
    } else if (param_5 == 3) {
        int half = param_3 / 2;
        if (half <= param_4) {
            int old_y = param_3 + param_2;
            int old_x = param_1 - param_2;
            param_8 = half + param_2;
            param_3 = param_2 - param_3;
            count = (param_4 - half) + 1;
            param_1 = old_y;
            param_2 = param_2 - half;
            param_4 = old_x;

            do {
                realMinDC.x = param_3;
                realMinDC.y = param_3 + param_4;
                this->mapBound(&realMinDC);

                realMaxF4.x = param_1;
                realMaxF4.y = param_1 + param_4;
                this->mapBound(&realMaxF4);

                min.x = param_2;
                min.y = param_2 + param_4;
                this->mapBound(&min);

                max.x = param_8;
                max.y = param_8 + param_4;
                this->mapBound(&max);

                int y = realMinDC.y;
                int x = min.x;
                if (y < min.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --x;
                    } while (y < min.y);
                }
                if (y < max.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                    } while (y < max.y);
                }
                if (x < realMinDC.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        ++x;
                    } while (x < realMinDC.x);
                }
                if (x < max.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                    } while (x < max.x);
                }
                if (max.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        ++x;
                    } while (max.y < y);
                }
                if (min.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                    } while (min.y < y);
                }
                if (max.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --x;
                    } while (max.x < x);
                }
                if (min.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                    } while (min.x < x);
                }

                --param_2;
                param_3 -= 2;
                param_1 += 2;
                ++param_8;
                --param_7;
                --count;
            } while (count != 0);
        }
    }
}
