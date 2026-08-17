// VA: 004603B0 RGE_Moving_Object::canLinePath
// move_obj.cpp:2600-2655
// Attempt log:
// 1: replaced the unrelated Manhattan placeholder with the period-plausible
//    XYPoint line scan shared by the adjacent integer overload.  The source
//    keeps the typed point references, direct passableTile dispatch, duplicate
//    tile suppression, and binary-observed distance stop test.
// 2: pointer versus const-reference spellings emitted the same code; retained
//    the PDB-decorated reference surface.
// 3-5: the binary pushes current float x/y coordinates to passableTile, not
//    the integer __ftol results.  The corrected float,float,int ABI improved
//    behavioral fidelity but exposed a different VC5 local/register basin.
// 6-7: rewrote the abs-axis predicate to the oracle's test-ah/je topology;
//    the second form matches the x-axis fall-through and y-axis late arm.
// 8-9: named start coordinates are supported by the decompiler's initial
//    field loads; receiver aliases/register qualification were codegen-neutral
//    and are not retained.
// 10: replaced the guarded do/while with a natural counted for loop.  This
//     recovered one initial jle, one bottom jl, matching frame size and nearly
//     matching effective function size; remaining drift is the VC5 receiver /
//     local-home allocation basin.
// 12: removed named start-coordinate locals and used direct XYPoint fields;
//     this changed only relocation bytes and did not move the structural hunk.
// 13: tested the donor-backed XYPoint pointer ABI; VC5 emitted the same code
//     under the current loop shape, so the PDB-decorated references remain.
// 14: tested the adjacent do/while source family; it lost 12 code bytes and
//     one CFG return, so the counted for loop is retained.
// 15: computed both point deltas directly before scan locals; this changed only
//     relocation bytes and did not move the first paired hunk.
// 16: named natural start/end coordinate locals; VC5 emitted the same code,
//     so the clean counted-loop source is retained.  The first gap remains the
//     receiver/local-home ordering before the saved-register prologue.
// 17: reversed the natural distance-stop predicate to maxDistance >= distance;
//     VC5 added 12 bytes and worsened the loop tail, so the original distance <=
//     maxDistance form is retained.
// 18: moved duplicate-tile state updates before passableTile, matching the
//     adjacent integer overload; this recovered the target size, frame, and
//     all but four bytes.
// 19: declared current x/y after xStep/yStep, matching the exact same-TU scan
//     donor; this recovered the x87 operand order and an exact 442-byte match.

#include <math.h>

struct XYPoint {
    int x;
    int y;
};

extern float DAT_00570b48;

class RGE_Moving_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual int passableTile(float, float, int);

    virtual int canLinePath(const XYPoint&, const XYPoint&, float, XYPoint&, int);
};

int RGE_Moving_Object::canLinePath(const XYPoint& a, const XYPoint& b,
                                   float maxDistance, XYPoint& result,
                                   int terrain) {
    int lastX;
    int lastY;
    float xDistance;
    float yDistance;
    int startX = a.x;
    int endX = b.x;
    int startY = a.y;
    int endY = b.y;

    xDistance = (float)(endX - startX);
    yDistance = (float)(endY - startY);

    if ((xDistance == DAT_00570b48) &&
        (yDistance == DAT_00570b48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    lastY = -999;
    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;
    x = (float)startX;
    y = (float)startY;

    for (; i < numSteps; ++i) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if (tileX != lastX || tileY != lastY) {
                lastX = tileX;
                lastY = tileY;
                if (this->passableTile(x, y, terrain) == 0) {
                    result.x = tileX;
                    result.y = tileY;
                    return 0;
                }

                if ((float)sqrt(((float)b.x - x) * ((float)b.x - x) +
                                ((float)b.y - y) * ((float)b.y - y)) <=
                    maxDistance) {
                    return 1;
                }
            }

    }

    return 1;
}
