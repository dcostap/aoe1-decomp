// VA: 00460570 RGE_Moving_Object::canLinePath
// Attempt log:
// 1: placeholder four-int Manhattan model was unrelated to the six-parameter
//    movement line scan.
// 2: reconstructed the binary-supported float stepping, duplicate-tile
//    suppression, passableTile vslot +114 call, and max-distance stop test.
//    Natural VC5 casts are intentional: the oracle invokes __ftol directly
//    from ST0 and reuses the incoming coordinate homes as current positions.
// 3-5: inlined the distance expression and tested an explicit receiver alias;
//      neither changed the emitted code or the receiver register basin.
// 6-9: tested declaration scope/order, virtual declaration, and register
//      qualifiers; the compiler retained the same 0x18-frame basin.
// 10: restored the natural positive-step do/while and abs-axis predicate;
//     this improves CFG/size but leaves the receiver/local-home drift.
// 11: ABI review proved passableTile takes float coordinates. Passing the
//     current float positions improved the size gap and reduced the diff to
//     342 bytes. Scoped scan locals improved bytes to 307 but harmed CFG;
//     restore the natural function-scope source. Remaining blocker is the
//     original 0x14 frame with EBX=this versus the rebuilt 0x18 frame/home.

#include <math.h>

extern float DAT_00570B48;

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

    virtual int canLinePath(int, int, int, int, float, int);
};

int RGE_Moving_Object::canLinePath(int x1, int y1, int x2, int y2,
                                   float maxDistance, int terrain) {
    int lastX;
    int lastY;
    float x;
    float y;
    float xDistance = (float)(x2 - x1);
    float yDistance = (float)(y2 - y1);

    if ((xDistance == DAT_00570B48) &&
        (yDistance == DAT_00570B48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;

    if (fabs(xDistance) < fabs(yDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;

    x = (float)x1;
    y = (float)y1;
    lastX = -999;
    lastY = -999;

    if (numSteps > 0) {
        do {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if (tileX != lastX || tileY != lastY) {
                if (this->passableTile(x, y, terrain) == 0) {
                    return 0;
                }

                lastX = tileX;
                lastY = tileY;
                if ((float)sqrt(((float)x2 - x) * ((float)x2 - x) +
                                ((float)y2 - y) * ((float)y2 - y)) <=
                    maxDistance) {
                    return 1;
                }
            }

            ++i;
        } while (i < numSteps);
    }

    return 1;
}
