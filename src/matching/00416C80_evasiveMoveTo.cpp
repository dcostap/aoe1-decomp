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
#include "../../include/aiuaimod_context.h"

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
