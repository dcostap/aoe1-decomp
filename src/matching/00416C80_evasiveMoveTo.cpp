// VA: 00416C80 UnitAIModule::evasiveMoveTo (674 bytes)
// aiuaimod.cpp lines 3453-3514.
//
// Attempt log:
// - The old scratch was a decompiler-shaped raw-vtable version. It passed the
//   receiver explicitly, used the wrong unsigned absolute-value arithmetic for
//   the jitter, and introduced a second slot-114 call at the rotated loop tail.
// - Current reconstruction restores the period typed object surface, signed
//   power-of-two remainder expressions, direct map ownership, and positive
//   guard/ordinary top-tested retry structure. The two incoming float homes are
//   intentionally mutated because the oracle writes them at +4/+8.
// - Typed player/world/map ownership plus shared DAT_0056ebc8/DAT_0056ebd0
//   constants reproduce the direct FPU memory operands; immediate 0.0f stores
//   remain separate. Final check: MATCH, 674/674 bytes, default flags.

#include "../../include/game_globals.h"
#include "../../include/unit_ai_module.h"

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
    virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
    virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C();
    virtual void vf110();
    virtual int passableTile(float x, float y, int mode);
    virtual void vf118(); virtual void vf11C(); virtual void vf120(); virtual void vf124();
    virtual void vf128(); virtual void vf12C(); virtual void vf130(); virtual void vf134();
    virtual void vf138(); virtual void vf13C(); virtual void vf140(); virtual void vf144();
    virtual void vf148(); virtual void vf14C(); virtual void vf150();
    virtual int moveTo(float x, float y, float z, float mode, int flag);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

extern "C" int __cdecl debug_rand(const char* file, int line);

int UnitAIModule::evasiveMoveTo(float x, float y, float z, int flag)
{
    if (flag != 0 || this->currentActionValue == -1) {
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

        int i = 0;
        while (i < 5) {
            if (this->objectValue->passableTile(x, y, 0) == 1) {
                break;
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xD9F) % 2) {
                x += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA0) % 4);
            } else {
                x -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA2) % 4);
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA3) % 2) {
                y += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA4) % 4);
            } else {
                y -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA6) % 4);
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
            ++i;
        }

        if (this->objectValue->moveTo(x, y, z, 0.0f, flag) == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, x, y, z);
            return 1;
        }
    }
    return 0;
}
