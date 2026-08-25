// 004DE330 TribeInformationAIModule::higherPriorityObjectToDefend
// Source: taiinfmd.cpp lines 4527-4574
//
// BINARY NOTE: The original walks ObjectMemory entries at 0x24-byte stride.
// It rereads the world object, zone, speed, and range in this order.
// It uses four calls in the neighbor path and publishes the selected entry.
// The two priority predicates use the original strict comparison order.
//
// Current source recovery uses the registered information_dropsites TU and the
// reviewed declarations shared with 004DE1F0. Do not replace these with raw
// offsets, cached world reads, fake volatility, or hand-built dispatch tables.
//
// Fresh registered-context audit: the natural pointer form emits 362 bytes
// against the 364-byte original. It keeps the 0x10 frame, 113 instructions,
// all ten ordered calls, and the original call targets. The first mismatch is
// the entry/id hunk at +0x5D: VC5 emits base-plus-offset into ECX and id into
// EDX, while the executable keeps the base in EAX, entry in EDI, and id in
// ECX. Typed direct-id forms add 8 bytes and a 0x14 frame. Typed base aliases,
// pointer addition, entry references, declaration-order changes, register
// qualifiers, and const entry ownership are duplicate codegen in this TU.

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int objId, int type, int group)
{
    RGE_Static_Object* mainObj = this->md->object(objId);
    ObjectMemory* best;
    if (mainObj == 0)
        return 0;

    *(unsigned char*)&objId = mainObj->currentZone();
    best = 0;
    group = this->defendPriority(type, group);
    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* entry = &this->importantObjectMemory[i];
            int id = entry->id;
            if (id != -1) {
                int j = 0;
                int defendCount = this->itemsToDefend.numberValue;
                if (defendCount > 0) {
                    while (j < defendCount) {
                        if (j >= this->itemsToDefend.maximumSizeValue)
                            break;
                        if (this->itemsToDefend.value[j] == id) {
                            if (entry->attackAttempts <= 0) {
                                RGE_Static_Object* target = this->md->object(id);
                                if (target != 0) {
                                    if (*(unsigned char*)&objId != target->currentZone()) {
                                        XYPoint pt;
                                        pt.x = (int)target->world_x;
                                        pt.y = (int)target->world_y;
                                        if (mainObj->withinRangeOfZoneAtPoint(*(unsigned char*)&objId, mainObj->speed(), &pt) != 1)
                                            break;
                                    }
                                    int pri = this->defendPriority(
                                        this->importantObjectMemory[i].type,
                                        this->importantObjectMemory[i].group);
                                    if (group > pri) {
                                        group = pri;
                                        best = &this->importantObjectMemory[i];
                                    }
                                }
                            }
                            break;
                        }
                        j++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return best;
}
