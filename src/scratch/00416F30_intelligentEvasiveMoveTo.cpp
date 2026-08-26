// VA: 00416F30 UnitAIModule::intelligentEvasiveMoveTo (666 bytes)
// aiuaimod.cpp:3520-3629
//
// BINARY NOTE: The target is the UnitAIModule owner in the aiuaimod.cpp
// sequence. Its point probe, path retry, publication, and failure exits stay
// in this source. The unusual x87 order follows the executable.
//
// BINARY NOTE: This owner follows 004151B0 in the PDB order. The shared
// UnitAIModule declaration keeps the qualified owner and the 00413AB0 update
// owner canonical. Do not replace it with a local vtable scaffold.
//
// BINARY NOTE: The target has a 0x14 frame, four saved registers, 220
// instructions, and ten ordered calls. The current clean source keeps these
// properties, but the checker still reports a 445-byte positional mismatch.
//
// Attempt log:
// - Positive and early-return guard forms emitted the same code.
// - Declaration scope and order, pointZ scope, register forceFlag, and typed
//   self/object aliases did not change the 445-byte codegen basin or lost the
//   canonical virtual calls.
// - A final point.z reread reduced the frame and worsened the CFG. The source
//   keeps pointZ because the original has a separate point-z home.
// - The canonical shared context changed no bytes, but it restored the real
//   UnitAIModule owner. No inline assembly, volatility, config, or shared-file
//   edits were used.

#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

int UnitAIModule::intelligentEvasiveMoveTo(float x, float y, float z,
                                            int targetId, int forceFlag)
{
    float baseDistance;
    int facet;
    XYZPoint point;
    int pointZ;

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
    pointZ = (int)this->objectValue->world_z;
    point.z = pointZ;

    if (this->objectValue->canPathPoint(point, 1.0f, -1, 0, 0, -1, -1) == 0) {
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

            if (this->objectValue->canPathPoint(point, 1.0f, -1, 0, 0, -1, -1) == 1) {
                break;
            }
        }
    }

    if (this->objectValue->moveTo(
            (float)point.x - DAT_0056ebe4,
            (float)point.y - DAT_0056ebe4,
            z, 0.5f, pointZ) == 1) {
        this->setCurrentAction(0x262);
        this->setCurrentTarget(-1, x, y, z);
        return 1;
    }

    return 0;
}
