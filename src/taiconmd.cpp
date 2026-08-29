
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

int TribeConstructionAIModule::canPlace(BuildItem* item)
{
    if (this->xReferencePointValue <= 0.0 ||
        this->yReferencePointValue <= 0.0 ||
        (float)this->mapXSizeValue <= this->xReferencePointValue ||
        (float)this->mapYSizeValue <= this->yReferencePointValue) {
        return this->md->informationAI.influenceCanPlaceStructure(item);
    }

    if (item->typeID() == 0x2d) {
        return 1;
    }

    if (useInfluencePlacement == 1 || this->numberConstructionLotsValue == 0) {
        return this->md->informationAI.influenceCanPlaceStructure(item);
    }

    ConstructionItem tempLots;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;

    ConstructionItem* current = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (current != end && current != 0) {
        if (current->typeID() == item->typeID() ||
            (current->xSize() == item->xSize() &&
             current->ySize() == item->ySize() &&
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
    BuildItem* item, int builderID, PlacementState& state,
    unsigned long currentTime)
{
    if (this->xReferencePointValue <= 0.0 ||
        this->yReferencePointValue <= 0.0 ||
        (float)this->mapXSizeValue <= this->xReferencePointValue ||
        (float)this->mapYSizeValue <= this->yReferencePointValue) {
        return this->md->informationAI.influencePlaceStructure(
            item, builderID, -1, 0, 0, -1, -1, -1, -1, state, currentTime);
    }

    if (item->typeID() == 0x2d) {
        ConstructionItem* dock = this->placeDock(item);
        if (dock != 0) {
            return new ConstructionItem(dock);
        }
        return 0;
    }

    if (item->typeID() == 0x67 || item->typeID() == 0x44 ||
        item->typeID() == 0x4f || item->typeID() == 0xc7 ||
        item->typeID() == 0x45 || item->typeID() == 0x48 ||
        item->typeID() == 0x75 || item->typeID() == 0x9b ||
        useInfluencePlacement == 1 || this->numberConstructionLotsValue == 0) {
        return this->md->informationAI.influencePlaceStructure(
            item, builderID, -1, 0, 0, -1, -1, -1, -1, state, currentTime);
    }

    RGE_Static_Object* builder = this->md->object(
        -1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    if (builder == 0) {
        return 0;
    }

    RGE_Static_Object* builderObject = this->md->object(builderID);
    unsigned char builderZone = 0;
    if (builderObject != 0) {
        builderZone = builderObject->currentZone();
    }

    ConstructionItem tempLots;
    ConstructionItem* current = this->constructionLots.next;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;
    int numberTempLots = 0;
    int minBuildAttempts = -1;
    ConstructionItem* end = &this->constructionLots;

    while (current != end && current != 0) {
        if (item->typeID() == current->typeID() || current->typeID() == -1) {
            if (current->xSize() == item->xSize() &&
                current->ySize() == item->ySize() &&
                current->built() != 1 && current->inProgress() != 1) {
                int minX = (int)(current->x() - current->xSize());
                int minY = (int)(current->y() - current->ySize());
                int maxX = minX + (int)current->xSize();
                int maxY = minY + (int)current->ySize();

                if (minX >= 0 && minY >= 0 &&
                    maxX < this->mapXSizeValue && maxY < this->mapYSizeValue) {
                    for (int x = minX; x < maxX; ++x) {
                        for (int y = minY; y < maxY; ++y) {
                            if ((builderObject != 0 &&
                                 builderObject->lookupZone(x, y) != builderZone) ||
                                builder->passableTile(
                                    (float)x - -0.5f, (float)y - -0.5f, 1) == 0) {
                                goto skipPlace;
                            }
                        }
                    }

                    ConstructionItem* candidate = new ConstructionItem(current);
                    candidate->next = &tempLots;
                    candidate->prev = tempLots.prev;
                    tempLots.prev->next = candidate;
                    tempLots.prev = candidate;
                    numberTempLots++;
                    if (minBuildAttempts == -1 ||
                        minBuildAttempts > current->buildAttempts()) {
                        minBuildAttempts = current->buildAttempts();
                    }
                }
            }
        }
skipPlace:
        current = current->next;
    }

    if (minBuildAttempts >= 2 || minBuildAttempts == -1) {
        ConstructionItem* placed = this->md->informationAI.influencePlaceStructure(
            item, builderID, -1, 0, 0, -1, -1, -1, -1, state, currentTime);
        if (placed != 0) {
            return placed;
        }
    }

    if (numberTempLots == 0) {
        this->lastPlacementReturnCodeValue = PlacementFailed;
        return 0;
    }

    ConstructionItem* best = tempLots.next;
    ConstructionItem* next = best->next;
    if (item->typeID() == 0x48) {
        while (next != &tempLots && next != 0) {
            if (best->buildAttempts() > next->buildAttempts() + 5) {
                best = next;
            }
            next = next->next;
        }
    } else {
        while (next != &tempLots && next != 0) {
            best = this->compare(best, next);
            next = next->next;
        }
    }

    ConstructionItem* lot = this->lot(best->x(), best->y());
    lot->setInProgress(1);
    lot->incrementBuildAttempts();
    lot->setUniqueID(item->uniqueID());

    this->lastPlacementReturnCodeValue = PlacementOk;
    ConstructionItem* result = new ConstructionItem(lot);
    result->setTypeID(item->typeID());

    ConstructionItem* temporary = tempLots.next;
    while (temporary != &tempLots && temporary != 0) {
        ConstructionItem* following = temporary->next;
        delete temporary;
        temporary = following;
    }

    return result;
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
