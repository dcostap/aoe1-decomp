// VA: 00416F30 UnitAIModule::intelligentEvasiveMoveTo (666 bytes)
// aiuaimod.cpp:3520-3629
//
// Attempt log:
// - Reconstructed the binary-supported path probe with the UnitAIModule field
//   surface and RGE_Static_Object's typed canPath/moveTo virtual ABI.
// - The point passed to canPath is a by-value XYZPoint. Its z component is
//   the object's integer world-z; the final move uses that same point.z while
//   retaining the clamped floating x/y parameters for the current target.
// - Baseline: natural typed source was 666 bytes with a 0x10 frame, 578
//   positional differing bytes, and incorrect virtual-slot identities.
// - Reconstructed the upper clamp as `map_dimension - 0.5f`; this recovered
//   the original x87 compare/subtract topology and reduced the diff to 462.
// - Replaced the initial object vtable scaffold with an inherited 85-slot
//   surface plus explicit slots 0x154/0x198; an explicit slot-0x194
//   placeholder was needed so the XYZPoint overload calls the observed 0x198
//   slot. Ordered calls then matched all 10 sites.
// - The original prune branch increments facet and jumps to the switch top.
//   It does not call canPath. An explicit while/break models this CFG; a
//   do/while canPath condition does not.
// - Reusing the dead forceFlag home for point.z is supported by the original
//   write and final reload. It is codegen-equivalent to a pointZ local here.
// - A pointZ local restored the original 0x14 frame and 220 instructions.
//   Aggregate initialization, pointX/pointY locals, a field reference, and a
//   persistent object alias regressed the frame, calls, or source shape.
// - Reviewed rdata globals changed no emitted bytes. A while(1) loop was
//   better than for(;;); the two-variant lab found no exact result.
// - Final validated reconstruction: 666 bytes, 0x14 frame, 220 instructions,
//   10 ordered calls, 16 conditional branches, 11 jumps, 445 differing bytes
//   (66.8168%), and 95.45% shape. It remains in scratch because it is not an
//   exact match. No inline assembly or shared files changed.
// - Accepted-drift audit: do not promote this candidate. The changed x87 clamp,
//   conversion, and distance schedule can alter candidate points and path-call
//   arguments. Those values select the final move target and published action
//   state, so matching call count and frame do not prove equivalent behavior.

#include "../../include/game_globals.h"
#include "../../include/unit_ai_module.h"

struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;
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

// Slots 0..84 are the inherited RGE_Static_Object surface. The moving/path
// methods below are placed at the packet-proven slots 0x154 and 0x198.
class RGE_Static_Object_Base {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
};

class RGE_Static_Object : public RGE_Static_Object_Base {
public:
    virtual int moveTo(float, float, float, float, int);
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);

    long id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                    // +0x0C
    char gap_10[0x28];                    // +0x10..+0x37
    float world_x;                        // +0x38
    float world_y;                        // +0x3C
    float world_z;                        // +0x40

    float distance_to_position(float, float, float);
};

int UnitAIModule::intelligentEvasiveMoveTo(float x, float y, float z,
                                            int targetId, int forceFlag)
{
    XYZPoint point;
    float baseDistance;
    int facet;

    if (forceFlag == 0 && this->currentActionValue != -1) {
        return 0;
    }

    if (x < DAT_0056ebc8) {
        x = 0.0f;
    } else {
        if (x >= (float)this->objectValue->owner->world->map->map_width) {
            x = (float)this->objectValue->owner->world->map->map_width - DAT_0056ebd0;
        }
    }

    if (y < DAT_0056ebc8) {
        y = 0.0f;
    } else {
        if (y >= (float)this->objectValue->owner->world->map->map_height) {
            y = (float)this->objectValue->owner->world->map->map_height - DAT_0056ebd0;
        }
    }

    point.x = (int)x;
    point.y = (int)y;
    forceFlag = (int)this->objectValue->world_z;
    point.z = forceFlag;

    if (this->objectValue->canPath(point, 1.0f, -1, 0, 0, -1, -1) == 0) {
        facet = -1;
        baseDistance = this->objectValue->distance_to_position(
            x, y, this->objectValue->world_z);

        while (1) {
            ++facet;

            switch (facet) {
            case 0:
                point.x -= 2;
                point.y -= 2;
                break;
            case 1:
            case 2:
                point.x += 2;
                break;
            case 3:
            case 4:
                point.y += 2;
                break;
            case 5:
            case 6:
                point.x -= 2;
                break;
            case 7:
                point.y -= 2;
                break;
            default:
                return 0;
            }

            if (point.x < 0) {
                point.x = 0;
            } else {
                int width = this->objectValue->owner->world->map->map_width;
                if (point.x >= width) {
                    point.x = width - 1;
                }
            }

            if (point.y < 0) {
                point.y = 0;
            } else {
                int height = this->objectValue->owner->world->map->map_height;
                if (point.y >= height) {
                    point.y = height - 1;
                }
            }

            if (targetId == 0 &&
                this->objectValue->distance_to_position(
                    (float)point.x - DAT_0056ebe4,
                    (float)point.y - DAT_0056ebe4,
                    this->objectValue->world_z) < baseDistance) {
                ++facet;
                continue;
            }

            if (this->objectValue->canPath(point, 1.0f, -1, 0, 0, -1, -1) == 1) {
                break;
            }
        }
    }

    if (this->objectValue->moveTo(
            (float)point.x - DAT_0056ebe4,
            (float)point.y - DAT_0056ebe4,
            z, 0.5f, forceFlag) == 1) {
        this->setCurrentAction(0x262);
        this->setCurrentTarget(-1, x, y, z);
        return 1;
    }

    return 0;
}
