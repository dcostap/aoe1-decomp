// 004DE600 TribeInformationAIModule::checkDefend
//
// BINARY NOTE: The executable rereads the object master, owner, and the
// defended-list fields along each special master-id arm. Keep those reads and
// the common append tail in their original order.
//
// BINARY NOTE: The fallback group dispatch has separate strategicNumber,
// contains, and resize call sites for groups 8 and 32. Keep both paths even
// when VC5 can merge equivalent source tails.
//
// Context: registered information_dropsites declarations.
//
// Recovery notes:
// - The registered class surface places md at +0x100, itemsToDefend at
//   +0x148, and tacticalAI at md +0x1146C. Exact neighboring anchors
//   004DE4A0 and 004DAFF0 validate this ownership and direct-call surface.
// - The target boundary is 747 bytes. The source preserves the master-id
//   dispatch, owner guard, defense-list scan, growth check, candidate
//   publication, state increment, and all logical direct call paths.
// - Fresh validation keeps the correct 747-byte boundary and owner symbol,
//   but VC5 merges the group-8 and group-32 strategic/contains/resize tails.
//   It emits 10 of 13 ordered calls, with first mismatch at +0x4B.
// - A one-sided alias experiment emitted all 13 calls, but grew to 907 bytes
//   and crossed the original boundary. It is rejected as codegen-only drift.
//   Explicit parameter-home publication grew to 959 bytes and is also
//   rejected. The clean registered-context source remains the smallest
//   natural reconstruction until new evidence explains this VC5 merge.

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

int TribeInformationAIModule::checkDefend(RGE_Static_Object* obj)
{
    int group = obj->master->object_group;
    int owner = obj->owner->id;
    int id;
    int tmp;

    switch (obj->master->id) {
    case 109: {
        if (owner != this->md->player->id)
            goto checkDefend_fail;
        if (this->md->tacticalAI.strategicNumber(0x38) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 45: {
        if (owner != this->md->player->id)
            goto checkDefend_fail;
        if (this->md->tacticalAI.strategicNumber(0x46) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9f: {
        if (this->md->tacticalAI.strategicNumber(0x37) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9e:
    case 0xa3: {
        if (this->md->tacticalAI.strategicNumber(0x36) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    default:
        switch (group) {
        case 7:
            if (this->md->tacticalAI.strategicNumber(0x34) <= 0)
                goto checkDefend_fail;
            this->itemsToDefend.add(obj->id);
            return 1;
        case 8: {
            int result8 = this->md->tacticalAI.strategicNumber(0x33);
            if (result8 <= 0)
                goto checkDefend_fail;
            tmp = obj->id;
            ManagedArray<int>* list8 = &this->itemsToDefend;
            if (list8->contains(tmp) == 1)
                return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (numValues > this->itemsToDefend.maximumSizeValue - 1)
                list8->resize(numValues + 1);
            list8->value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        case 32: {
            int result32 = this->md->tacticalAI.strategicNumber(0x32);
            if (result32 <= 0)
                goto checkDefend_fail;
            tmp = obj->id;
            if (this->itemsToDefend.contains(tmp) == 1)
                return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (numValues > this->itemsToDefend.maximumSizeValue - 1)
                this->itemsToDefend.resize(numValues + 1);
            this->itemsToDefend.value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        default:
            goto checkDefend_fail;
        }
    }

checkDefend_fail:
    return 0;
}
