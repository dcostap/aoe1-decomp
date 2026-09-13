
#include "../include/taiconmd.h"

#include "../include/aiblditm.h"
#include "../include/ai_placement_state.h"
#include "../include/taimdmd.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"

extern int useInfluencePlacement;

TribeConstructionAIModule::TribeConstructionAIModule(void* owner, int player)
    : ConstructionAIModule(owner, player), md(0)
{
}

TribeConstructionAIModule::TribeConstructionAIModule(int player, int file)
    : ConstructionAIModule(player, file), md(0)
{
}

TribeConstructionAIModule::~TribeConstructionAIModule()
{
}

void TribeConstructionAIModule::setMainDecisionAI(
    TribeMainDecisionAIModule* value)
{
    this->md = value;
}

int TribeConstructionAIModule::canPlace(BuildItem* bi)
{
    if (this->xReferencePointValue <= 0.0 ||
        this->yReferencePointValue <= 0.0 ||
        (float)this->mapXSizeValue <= this->xReferencePointValue ||
        (float)this->mapYSizeValue <= this->yReferencePointValue) {
        return this->md->informationAI.influenceCanPlaceStructure(bi);
    }

    if (bi->typeID() == 0x2d) {
        return 1;
    }

    if (useInfluencePlacement == 1 || this->numberConstructionLotsValue == 0) {
        return this->md->informationAI.influenceCanPlaceStructure(bi);
    }

    ConstructionItem tempLots;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;

    ConstructionItem* current = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (current != end && current != 0) {
        if (current->typeID() == bi->typeID() ||
            (current->xSize() == bi->xSize() &&
             current->ySize() == bi->ySize() &&
             current->typeID() == -1)) {
            if (!current->built() && !current->inProgress()) {
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}

ConstructionItem* TribeConstructionAIModule::placeStructure(
    BuildItem* item, int builder_id, PlacementState& state,
    unsigned long time)
{
    if (this->xReferencePointValue <= 0.0 ||
        this->yReferencePointValue <= 0.0 ||
        (float)this->mapXSizeValue <= this->xReferencePointValue ||
        (float)this->mapYSizeValue <= this->yReferencePointValue) {
        return this->md->informationAI.influencePlaceStructure(
            item, builder_id, -1, 0.0f, 0, -1, -1, -1, -1, state, time);
    }

    if (item->typeID() == 0x2d) {
        ConstructionItem* dock = this->placeDock(item);
        if (dock != 0) {
            return new ConstructionItem(dock);
        }
        return 0;
    }

    if (item->typeID() == 0x67 ||
        item->typeID() == 0x44 ||
        item->typeID() == 0x4f ||
        item->typeID() == 0xc7 ||
        item->typeID() == 0x45 ||
        item->typeID() == 0x48 ||
        item->typeID() == 0x75 ||
        item->typeID() == 0x9b ||
        useInfluencePlacement == 1 ||
        this->numberConstructionLotsValue == 0) {
        return this->md->informationAI.influencePlaceStructure(
            item, builder_id, -1, 0.0f, 0, -1, -1, -1, -1, state, time);
    }

    RGE_Static_Object* protoBuilder = this->md->object(
        -1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    if (protoBuilder == 0) {
        return 0;
    }

    RGE_Static_Object* builder = this->md->object(builder_id);
    unsigned char builderZone = 0;
    if (builder != 0) {
        builderZone = builder->currentZone();
    }

    ConstructionItem tempLots;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;

    ConstructionItem* current = this->constructionLots.next;
    int numberTempLots = 0;
    int minBuildAttempts = -1;

    while (current != &this->constructionLots && current != 0) {
        if ((item->typeID() == current->typeID() ||
             current->typeID() == -1) &&
            current->xSize() == item->xSize() &&
            current->ySize() == item->ySize() &&
            current->built() != 1 &&
            current->inProgress() != 1) {
            int minX = (int)(current->x() - current->xSize());
            int minY = (int)(current->y() - current->ySize());
            int maxX = minX + (int)current->xSize();
            int maxY = minY + (int)current->ySize();

            if (minX >= 0 && minY >= 0 &&
                maxX < this->mapXSizeValue &&
                maxY < this->mapYSizeValue) {
                int x = minX;
                for (; x < maxX; ++x) {
                    int y = minY;
                    for (; y < maxY; ++y) {
                        if (builder != 0 &&
                            builder->lookupZone(x, y) != builderZone) {
                            goto next_lot;
                        }
                        if (protoBuilder->passableTile(
                                (float)x + 0.5f, (float)y + 0.5f, 1) == 0) {
                            goto next_lot;
                        }
                    }
                }

                ConstructionItem* copy = new ConstructionItem(current);
                copy->next = &tempLots;
                copy->prev = tempLots.prev;
                tempLots.prev->next = copy;
                ++numberTempLots;
                tempLots.prev = copy;

                if (minBuildAttempts == -1 ||
                    current->buildAttempts() < minBuildAttempts) {
                    minBuildAttempts = current->buildAttempts();
                }
            }
        }

    next_lot:
        current = current->next;
    }

    if (minBuildAttempts >= 2 || minBuildAttempts == -1) {
        ConstructionItem* result =
            this->md->informationAI.influencePlaceStructure(
                item, builder_id, -1, 0.0f, 0, -1, -1, -1, -1, state,
                time);
        if (result != 0) {
            return result;
        }
    }

    if (numberTempLots != 0) {
        ConstructionItem* best = tempLots.next;
        ConstructionItem* candidate = best->next;

        if (item->typeID() == 0x48) {
            while (candidate != &tempLots && candidate != 0) {
                if (best->buildAttempts() >
                    candidate->buildAttempts() + 5) {
                    best = candidate;
                }
                candidate = candidate->next;
            }
        } else {
            while (candidate != &tempLots && candidate != 0) {
                best = this->compare(best, candidate);
                candidate = candidate->next;
            }
        }

        ConstructionItem* selected = this->lot(best->x(), best->y());
        selected->setInProgress(1);
        selected->incrementBuildAttempts();
        selected->setUniqueID(item->uniqueID());
        this->lastPlacementReturnCodeValue = PlacementOk;

        ConstructionItem* result = new ConstructionItem(selected);
        result->setTypeID(item->typeID());

        ConstructionItem* old = tempLots.next;
        while (old != &tempLots && old != 0) {
            ConstructionItem* next = old->next;
            delete old;
            old = next;
        }
        return result;
    }

    this->lastPlacementReturnCodeValue = PlacementFailed;
    return 0;
}

ConstructionItem* TribeConstructionAIModule::placeDock(BuildItem* item)
{
    ConstructionItem* result = this->md->informationAI.placeDock(
        item, this->xReferencePointValue, this->yReferencePointValue, 1, 2);
    if (result != 0) {
        result->next = &this->randomConstructionLots;
        ConstructionItem* tail = this->randomConstructionLots.prev;
        result->prev = tail;
        tail->next = result;
        this->randomConstructionLots.prev = result;
        this->numberRandomConstructionLotsValue++;
        this->lastPlacementReturnCodeValue = PlacementOk;
        return result;
    }

    this->lastPlacementReturnCodeValue = PlacementFailed;
    return 0;
}

void TribeConstructionAIModule::setBuilt(RGE_Static_Object* object, int built)
{
    ConstructionItem* item = this->constructionLots.next;
    while (item != &this->constructionLots && item != 0) {
        if (item->typeID() == object->master_obj->id &&
            item->x() == object->world_x && item->y() == object->world_y) {
            item->setBuilt(built);
            return;
        }
        item = item->next;
    }

    this->md->informationAI.storeLot(
        object->master_obj->id, (unsigned char)object->world_x,
        (unsigned char)object->world_y, 1);
}

ConstructionItem* TribeConstructionAIModule::compare(
    ConstructionItem* left, ConstructionItem* right)
{
    // Read left first. A null left faults before a null right.
    int leftAttempts = left->buildAttempts();
    if (leftAttempts > right->buildAttempts()) {
        return right;
    }
    return left;
}
