// VA: 004E4040 TribeInformationAIModule::lookAtMap
// Attempt log:
// baseline: replaced the decompiler-shaped counter-only loop with the typed
// map, tile-list, influence-map, and important-object operations shown by the
// original call sites and field accesses.
// probe 2: restored direct mapRowOffset[y][x] ownership and the 0x28-byte
// InfluenceMap surface; size reached 379 bytes and the quadrant/counter
// offsets became correct.
// probe 3: confirmed the full InfluenceMap layout; diff improved to 341
// bytes. Calls, CFG count, and all three call targets are aligned.
// probes 4, 9: volatile/address-taken map locals were codegen duplicates.
// probes 5, 8: sinking x initialization changed register ownership and was
// rolled back. Probe 6: direct owner-chain map reload reached 381 bytes and
// worsened resynchronization, so the persistent typed map local remains.
// probe 10: direct quadrantLog indexing worsened the localized block and was
// rolled back.
// probe 13: map declaration initialization was a codegen duplicate.
// probe 14: removed the redundant mapYSize local and read the owning field
// directly for the guard, quadrant divisor, and inner-loop limit; this
// restored the original frame and all bytes.
// exact: the typed map/tile-list traversal is natural source and matches the
// original 379-byte function with all three direct calls aligned.
// BINARY NOTE: PDB ownership is TribeInformationAIModule::lookAtMap in
// taiinfmd.cpp, lines 8180-8222. The body ends at 004E41BA.
// BINARY NOTE: Exact anchors are pathMap.setValue, importantObject, and
// addImportantObject. The next PDB sibling starts at 004E41C0.
// Exact-finish: omitting the definition's empty parameter list stayed exact.
// Keeping the terrain local is required. Direct rereads changed the frame.

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

void TribeInformationAIModule::lookAtMap()
{
    RGE_Map* map = this->md->player->world->map;
    int x = 0;

    if (this->mapXSizeValue > 0) {
        do {
            int y = 0;

            if (this->mapYSizeValue > 0) {
                do {
                    int terrainType = map->mapRowOffset[y][x].terrainType & 0x1F;

                    if (this->mapXSizeValue != -1) {
                        int qx = (x * 4) / this->mapXSizeValue;
                        int qy = (y * 4) / this->mapYSizeValue;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }

                    this->pathMap.setValue(x, y, 0);

                    int forestTileCount = 0;
                    RGE_Object_List_Node* node =
                        map->mapRowOffset[y][x].objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->object;
                        int objectGroup = object->master_obj->object_group;

                        if (this->importantObject(objectGroup) == 1)
                            this->addImportantObject(object, 0);

                        if (objectGroup == 0x0F)
                            forestTileCount++;

                        node = node->next;
                    }

                    if (forestTileCount > 0 &&
                        (terrainType == 0x0A || terrainType == 0x13 ||
                         terrainType == 0x0D || terrainType == 0x14))
                        this->numberFoundForestTilesValue++;

                    ++y;
                } while (y < this->mapYSizeValue);
            }

            ++x;
        } while (x < this->mapXSizeValue);
    }
}
