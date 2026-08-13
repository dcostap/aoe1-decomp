// VA: 00460710 RGE_Moving_Object::firstTileAlongLine
// PDB donor: move_obj.cpp:2719-2771
// Attempt log:
// - Replaced the unrelated placeholder with the period-plausible line scan:
//   axis-based step count, floating-point stepping, duplicate-tile suppression,
//   terrain filtering, and the inherited passableTile virtual call.
// - Direct endpoint ownership plus the same-TU local declaration order recovered
//   the incoming coordinate homes, x87 axis predicate, sentinel-register setup,
//   and all six ordered call sites; the remaining drift begins at loop-tail
//   block layout and current/step load ordering.
// - Equivalent absolute-axis predicate reversal matched the original x87
//   compare polarity; moving sentinel initialization before the counter matched
//   the prologue. Explicit/compound/reversed accumulation spellings emitted the
//   same codegen group, so the natural compound form is retained.
// - The top-tested-for variant was larger and broadly shifted; restored the
//   negative guard plus do/while form. A four-case update-expression variant lab
//   likewise produced one 430-byte group (57 positional differing bytes).
// - Fresh pass: moving the current-coordinate declarations after the step
//   declarations recovered the original current homes and improved the diff to
//   53 bytes, but did not resolve the loop-tail topology. Initialized-for and
//   positive-guard loop forms shifted the function by 200-245 bytes; restored
//   the pinned natural source.
// - Paused after the bounded 10-hypothesis session: size/frame/calls are
//   430/0x1C/6 versus 441/0x1C/6. Remaining binary lead is the separate
//   nonpositive/loop-exhaustion epilogue topology and the localized operand
//   order at the first coordinate accumulation.

#include <math.h>

struct XYPoint {
    int x;
    int y;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

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
    virtual int passableTile(float x, float y, int mode);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int firstTileAlongLine(const XYPoint&, const XYPoint&, XYPoint&,
                                   int, int, int);

    char gap_04[8];
    RGE_Player* owner;
};

extern float DAT_00570B48;

int RGE_Moving_Object::firstTileAlongLine(const XYPoint& a,
                                           const XYPoint& b,
                                           XYPoint& result,
                                           int terrain1, int terrain2,
                                           int checkTerrain) {
    int lastX;
    int lastY;
    float xDistance = (float)(b.x - a.x);
    float yDistance = (float)(b.y - a.y);

    if ((xDistance == DAT_00570B48) &&
        (yDistance == DAT_00570B48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;
    RGE_Map* map;
    unsigned char tileType;

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
    x = (float)a.x;
    y = (float)a.y;
    map = this->owner->world->map;

    while (i < numSteps) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if ((tileX != lastX) || (tileY != lastY)) {
                lastX = tileX;
                lastY = tileY;
                tileType = map->get_terrain((short)tileX, (short)tileY);
                if (((int)tileType == terrain1 ||
                     (int)tileType == terrain2) &&
                    (checkTerrain == 1)) {
                    if (this->passableTile(x, y, 0) == 1) {
                        result.x = tileX;
                        result.y = tileY;
                        return 1;
                    }
                }
            }

        ++i;
    }

    return 0;
}
