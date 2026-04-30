// 0044E900 InfluenceMap::setCoverageCount(const XYPoint* param_1, const XYPoint* param_2, int param_3)
// Source: infmap.cpp lines 369-387
// Size: 221 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 TU-context drift (register allocation / prologue / computation order)

// Attempt log:
// Probe 1: const XYPoint& params, && chain, `:` range for, int x/y - 192 bytes (push ecx prologue)
//   - push ecx vs sub esp,8; different register allocation
// Probe 2: pointer params, temps for xRef/yRef/rows, sub esp,0Ch (3 locals vs 2)
//   - Almost matched size but 3 locals, extra load before pushes
// Probe 3: removed extra temps, just int x outer + int y inner - 192 bytes again (push ecx)
// Probe 4: added dummy locals for 2 locals - sub esp,8 but load before pushes
// Probe 5: int x,y,xRef,yRef,rows at top - sub esp,0Ch (5 locals)
// Probe 6+: variants of loop structure, continue vs nested if, various local arrangements
//
// Key findings:
// - InfluenceMap fields: vtable(+0x00), xSizeValue(+0x04), ySizeValue(+0x08),
//   xReferencePointValue(+0x0C), yReferencePointValue(+0x10), valueValue(+0x14),
//   rowValue(+0x18), coverageCountValue(+0x1C)
// - XYPoint(int x, int y) struct, referenced as pointers
// - Bounds checks via && chain or early returns both produce shared-fail blocks
// - ret 0Ch = 3 params: (XYPoint*, XYPoint*, int)
// - Inner loop: rowValue[y - yReferencePointValue][x - xReferencePointValue] >= param_3
// - coverageCountValue incremented when byte value >= threshold
// 
// Remaining drift (VC5 TU-context):
// - Prologue: push ecx vs sub esp,8 (local allocation style)
// - Register allocation: which regs hold this/param_1/param_2/x/y
// - Inner computation: lea reg,[reg*4] vs shl reg,2 for yRef*4
// - Array access order: (row - xRef)[x] vs row[(x - xRef)] 
//   (algebraically equivalent, different instruction sequence)
// - Early load of param_1 before register saves (instruction scheduling)

struct XYPoint {
    int x;
    int y;
};

class InfluenceMap {
public:
    void* vtable_ptr;               // +0x00
    int xSizeValue;                 // +0x04
    int ySizeValue;                 // +0x08
    int xReferencePointValue;       // +0x0C
    int yReferencePointValue;       // +0x10
    unsigned char* valueValue;      // +0x14
    unsigned char** rowValue;       // +0x18
    int coverageCountValue;         // +0x1C
    int connectionCountValue;       // +0x20
    unsigned char unchangeableLimitValue; // +0x24

    int setCoverageCount(const XYPoint* param_1, const XYPoint* param_2, int param_3);
};

int InfluenceMap::setCoverageCount(const XYPoint* param_1, const XYPoint* param_2, int param_3)
{
    int i;
    coverageCountValue = 0;

    if (param_1->x >= 0 && param_1->y >= 0 && param_1->x < xSizeValue && param_1->y < ySizeValue
        && param_2->x >= 0 && param_2->y >= 0 && param_2->x < xSizeValue && param_2->y < ySizeValue) {

        if (param_1->x <= param_2->x) {
            for (i = param_1->x; i <= param_2->x; i++) {
                if (param_1->y <= param_2->y) {
                    for (int j = param_1->y; j <= param_2->y; j++) {
                        if (rowValue[j - yReferencePointValue][i - xReferencePointValue] >= param_3) {
                            coverageCountValue++;
                        }
                    }
                }
            }
        }

        return coverageCountValue;
    }

    return 0;
}
