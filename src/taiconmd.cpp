
#include "../include/taiconmd.h"

#include "../include/aiblditm.h"
#include "../include/ai_placement_state.h"
#include "../include/taimdmd.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"

extern int useInfluencePlacement;

TribeConstructionAIModule::TribeConstructionAIModule(void* pW, int pID)
    : ConstructionAIModule(pW, pID), md(0) {
}

TribeConstructionAIModule::TribeConstructionAIModule(int pID, int infile)
    : ConstructionAIModule(pID, infile), md(0) {
}

TribeConstructionAIModule::~TribeConstructionAIModule() {
}

void TribeConstructionAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

int TribeConstructionAIModule::canPlace(BuildItem* bi) {
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

ConstructionItem* TribeConstructionAIModule::placeStructure(BuildItem* bi, int builder, PlacementState& placementState, unsigned long startTime) {
    if (this->xReferencePointValue <= 0.0 ||
        this->yReferencePointValue <= 0.0 ||
        (float)this->mapXSizeValue <= this->xReferencePointValue ||
        (float)this->mapYSizeValue <= this->yReferencePointValue) {
        return this->md->informationAI.influencePlaceStructure(bi, builder, -1, 0.0f, 0, -1, -1, -1, -1, placementState,
                                                               startTime);
    }

    if (bi->typeID() == 0x2d) {
        ConstructionItem* dock = this->placeDock(bi);
        if (dock != 0) {
            return new ConstructionItem(dock);
        }
        return 0;
    }

    if (bi->typeID() == 0x67 ||
        bi->typeID() == 0x44 ||
        bi->typeID() == 0x4f ||
        bi->typeID() == 0xc7 ||
        bi->typeID() == 0x45 ||
        bi->typeID() == 0x48 ||
        bi->typeID() == 0x75 ||
        bi->typeID() == 0x9b ||
        useInfluencePlacement == 1 ||
        this->numberConstructionLotsValue == 0) {
        return this->md->informationAI.influencePlaceStructure(bi, builder, -1, 0.0f, 0, -1, -1, -1, -1, placementState,
                                                               startTime);
    }

    RGE_Static_Object* protoBuilder = this->md->object(-1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    if (protoBuilder == 0) {
        return 0;
    }

    RGE_Static_Object* builderObj = this->md->object(builder);
    unsigned char builderZone = 0;
    if (builderObj != 0) {
        builderZone = builderObj->currentZone();
    }

    ConstructionItem tempLots;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;

    ConstructionItem* current = this->constructionLots.next;
    int numberTempLots = 0;
    int minBuildAttempts = -1;

    while (current != &this->constructionLots && current != 0) {
        if ((bi->typeID() == current->typeID() ||
             current->typeID() == -1) &&
            current->xSize() == bi->xSize() &&
            current->ySize() == bi->ySize() &&
            current->built() != 1 &&
            current->inProgress() != 1) {
            int minX = (int)(current->x() - current->xSize());
            int minY = (int)(current->y() - current->ySize());
            int maxX = minX + (int)current->xSize();
            int maxY = minY + (int)current->ySize();

            if (minX >= 0 && minY >= 0 &&
                maxX < this->mapXSizeValue &&
                maxY < this->mapYSizeValue) {
                int i = minX;
                for (; i < maxX; ++i) {
                    int j = minY;
                    for (; j < maxY; ++j) {
                        if (builderObj != 0 &&
                            builderObj->lookupZone(i, j) != builderZone) {
                            goto next_lot;
                        }
                        if (protoBuilder->passableTile((float)i + 0.5f, (float)j + 0.5f, 1) == 0) {
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
            this->md->informationAI.influencePlaceStructure(bi, builder, -1, 0.0f, 0, -1, -1, -1, -1, placementState,
                                                            startTime);
        if (result != 0) {
            return result;
        }
    }

    if (numberTempLots != 0) {
        ConstructionItem* best = tempLots.next;
        ConstructionItem* candidate = best->next;

        if (bi->typeID() == 0x48) {
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
        selected->setUniqueID(bi->uniqueID());
        this->lastPlacementReturnCodeValue = PlacementOk;

        ConstructionItem* result = new ConstructionItem(selected);
        result->setTypeID(bi->typeID());

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

ConstructionItem* TribeConstructionAIModule::placeDock(BuildItem* bi) {
    ConstructionItem* result = this->md->informationAI.placeDock(bi, this->xReferencePointValue, this->yReferencePointValue, 1, 2);
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

void TribeConstructionAIModule::setBuilt(RGE_Static_Object* bo, int v) {
    ConstructionItem* item = this->constructionLots.next;
    while (item != &this->constructionLots && item != 0) {
        if (item->typeID() == bo->master_obj->id &&
            item->x() == bo->world_x && item->y() == bo->world_y) {
            item->setBuilt(v);
            return;
        }
        item = item->next;
    }

    this->md->informationAI.storeLot(bo->master_obj->id, (unsigned char)bo->world_x, (unsigned char)bo->world_y, 1);
}

ConstructionItem* TribeConstructionAIModule::compare(ConstructionItem* one, ConstructionItem* two) {
    // Read the first candidate before the second. A null first candidate faults first.
    int leftAttempts = one->buildAttempts();
    if (leftAttempts > two->buildAttempts()) {
        return two;
    }
    return one;
}
