#include "../include/aibitm.h"
#include "../include/aiblditm.h"
#include "../include/aimodule.h"
#include "../include/aibldmod.h"
#include "../include/utmarray.h"
#include "../include/airesitm.h"
#include "../include/aiconitm.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/tplayer.h"
#include "../include/taibldmd.h"
#include "../include/taimdmd.h"
#include <string.h>

// handwritten owner and is emitted by the TribeBuildAIModule virtual surface.

TribeBuildAIModule::TribeBuildAIModule(void* owner, int player)
    : BuildAIModule(owner, player), md(0)
{
}

TribeBuildAIModule::TribeBuildAIModule(int file, int player)
    : BuildAIModule(file, player), md(0)
{
}

TribeBuildAIModule::~TribeBuildAIModule()
{
}

void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* value)
{
    this->md = value;
}

int TribeBuildAIModule::loadBuildList(char* filename, RGE_Player* player)
{
    this->typesToIgnore.add(0x46);
    this->typesToIgnore.add(0x67);
    this->typesToIgnore.add(0x44);
    return BuildAIModule::loadBuildList(filename, player);
}

void TribeBuildAIModule::initialize()
{
    int bronzeAgeCount = 0;
    int transportCount = 0;
    int toolAgeCount = 0;
    int fishingBoatCount = 0;
    int resourceBuildingCount = 0;
    int firstMarkerIndex = -1;
    int secondMarkerIndex = -1;
    int thirdMarkerIndex = -1;
    int ironAgePresent = 0;
    int bronzeAgePresent = 0;
    int dockPresent = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    while (item != sentinel && item != 0) {
        if (item->buildCategory() == 0) {
            if (item->typeID() == 0x46) {
                ++bronzeAgeCount;
            }
            else if (item->typeID() == 0x2D) {
                ++transportCount;
            }
        }
        else if (item->buildCategory() == 2) {
            if (item->typeID() == 0x0D) {
                ++toolAgeCount;
            }
            else if (item->typeID() == 0x11 || item->typeID() == 0x12) {
                ++fishingBoatCount;
            }
            else if (item->typeID() == 0x13 || item->typeID() == 0xFA) {
                ++resourceBuildingCount;
            }
        }
        else if (item->buildCategory() == 1 || item->buildCategory() == 4) {
            if (item->typeID() == 0x65) {
                firstMarkerIndex = item->uniqueID();
            }
            else if (item->typeID() == 0x66) {
                secondMarkerIndex = item->uniqueID();
            }
            else if (item->typeID() == 0x67) {
                thirdMarkerIndex = item->uniqueID();
            }
            else if (item->typeID() == 5) {
                ironAgePresent = 1;
            }
            else if (item->typeID() == 7) {
                bronzeAgePresent = 1;
            }
            else if (item->typeID() == 8) {
                dockPresent = 1;
            }
        }

        item = item->next;
    }

    int count;
    int spacing;
    int index;

    if (transportCount < this->md->tacticalAI.strategicNumber(0xD4) &&
        this->md->tacticalAI.strategicNumber(0xD0) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD4) - transportCount;
        if (secondMarkerIndex != -1) {
            spacing = secondMarkerIndex / count;
        }
        else if (firstMarkerIndex != -1) {
            spacing = firstMarkerIndex / count;
        }
        else {
            spacing = 10;
        }

        index = spacing;
        while (count > 0) {
            this->insert(0x2D, -1, index);
            index += spacing;
            --count;
        }
    }

    if (toolAgeCount < this->md->tacticalAI.strategicNumber(0xD5) &&
        this->md->tacticalAI.strategicNumber(0xD1) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD5) - toolAgeCount;
        if (count > 0) {
            if (secondMarkerIndex != -1) {
                spacing = secondMarkerIndex / count;
            }
            else if (firstMarkerIndex != -1) {
                spacing = firstMarkerIndex / count;
            }
            else {
                spacing = 10;
            }

            index = spacing;
            while (count > 0) {
                this->insert(0x0D, -1, index);
                index += spacing;
                --count;
            }
        }
    }

    if (fishingBoatCount < this->md->tacticalAI.strategicNumber(0xD6) &&
        this->md->tacticalAI.strategicNumber(0xD2) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD6) - fishingBoatCount;
        if (firstMarkerIndex != -1) {
            spacing = (this->buildListLengthValue - firstMarkerIndex) / (count * 2);
            index = secondMarkerIndex;
        }
        else if (secondMarkerIndex != -1) {
            spacing = (this->buildListLengthValue - secondMarkerIndex) / (count * 2);
            index = -1;
        }
        else {
            spacing = 10;
            index = 0;
        }

        while (count > 0) {
            index += spacing;
            this->insert(0x11, -1, index);
            --count;
        }

        if (!dockPresent && thirdMarkerIndex != -1) {
            this->insertResearch(8, thirdMarkerIndex + 2);
        }
    }

    if (resourceBuildingCount < this->md->tacticalAI.strategicNumber(0xE0) &&
        this->md->tacticalAI.strategicNumber(0xDF) == 1 &&
        (thirdMarkerIndex != -1 || secondMarkerIndex != -1)) {
        count = this->md->tacticalAI.strategicNumber(0xE0) - resourceBuildingCount;
        if (thirdMarkerIndex != -1) {
            spacing = thirdMarkerIndex / count;
        }
        else {
            spacing = secondMarkerIndex / count;
        }

        index = spacing;
        while (count > 0) {
            this->insertResearch(0x13, index);
            index += spacing;
            --count;
        }

        if (!ironAgePresent && secondMarkerIndex != -1) {
            this->insertResearch(5, secondMarkerIndex + 5);
        }
        if (!bronzeAgePresent && thirdMarkerIndex != -1) {
            this->insertResearch(7, thirdMarkerIndex + 5);
        }
    }

    if (bronzeAgeCount == 0 &&
        this->md->tacticalAI.strategicNumber(0xB4) == 1) {
        item = this->buildList.next;
        int buildIndex = 0;
        int supportedCount = 0;
        int trainedCount = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == 0 && item->typeID() == 0x6D) {
                supportedCount += 4;
            }
            if (item->buildCategory() == 2) {
                ++trainedCount;
            }
            if (trainedCount > supportedCount) {
                int insertIndex;
                if (buildIndex > 1) {
                    insertIndex = buildIndex - 1;
                }
                else {
                    insertIndex = 1;
                }
                if (this->insert(0x46, -1, insertIndex) == 1) {
                    supportedCount += 4;
                }
            }
            if (supportedCount >
                this->md->tacticalAI.strategicNumber(0x98) + 50) {
                break;
            }

            item = item->next;
            ++buildIndex;
        }
    }

    int totalPercentage = this->md->tacticalAI.strategicNumber(0xA0);
    int divisionSize = this->md->tacticalAI.strategicNumber(0x9B) + 4;
    if (totalPercentage != 0) {
        item = this->buildList.next;
        ResourceItem resourceCount(4);
        resourceCount.setAllValues(0);
        int itemCount = 0;
        int divisionIndex = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == 6) {
                item = item->next;
                ++itemCount;
            }
            else {
                if (item->buildCategory() == 1 || item->buildCategory() == 4) {
                    this->md->aiPlayer->researchCost(
                        item->typeID(), -1, &resourceCount, 1);
                }
                else {
                    this->md->aiPlayer->objectCost(
                        item->typeID(), -1, &resourceCount, 1);
                }

                ++itemCount;
                if (itemCount >= divisionSize) {
                    int totalCost = 0;
                    int resource;
                    for (resource = 0; resource < 4; ++resource) {
                        totalCost += resourceCount.value(resource);
                    }

                    if (totalCost > 0) {
                        for (resource = 0; resource < 4; ++resource) {
                            this->insertGathererPercentage(
                                resource,
                                resourceCount.value(resource) * totalPercentage / totalCost,
                                divisionIndex);
                        }
                        resourceCount.setAllValues(0);
                        divisionIndex += divisionSize;
                        itemCount = 0;
                    }
                }

                item = item->next;
            }
        }
    }
}

void TribeBuildAIModule::skipNextBuildListItem()
{
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1) {
            if (item->typeID() != this->md->tacticalAI.strategicNumber(0xB1) ||
                item->buildCategory() != 0) {
                item->setBuildAttempts(this->md->tacticalAI.strategicNumber(0x72));
                item->setSkip(1);
                item->incrementSkipCycles();
                if (item->skipCycles() == this->md->tacticalAI.strategicNumber(0x92)) {
                    item->setPermanentSkip(1);
                }
                return;
            }
        }

        item = item->next;
    }
}

BuildItem* TribeBuildAIModule::nextBuildableItem(int category)
{
    int numGranaries = this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int numStoragePits = this->numberBuiltOrInProgressItemsOfType(0x44, 0);
    int numHouses = this->numberBuiltOrInProgressItemsOfType(0x46, 0);
    BuildItem* item = this->buildList.next;
    int realCount = 0;
    int count = 0;

    if (this->md->tacticalAI.strategicNumber(0x73) < 0)
        return 0;

    while (1) {
        if (item == &this->buildList || item == 0)
            return 0;
        if (item->buildCategory() == 1 || item->buildCategory() == 4) {
            if (this->isAgeResearch(item->typeID()) == 1) {
                switch (this->md->aiPlayer->researchState(item->typeID())) {
                case 0:
                case 1:
                    item->setBuilt(0);
                    item->setInProgress(0);
                    break;
                case 2:
                    item->setBuilt(0);
                    item->setInProgress(1);
                    break;
                case 3:
                    item->setBuilt(1);
                    item->setInProgress(0);
                    break;
                default:
                    break;
                }
            }
        }

        if (item->built() == 0 && item->inProgress() == 0) {
            ++realCount;
            int canBuild = 1;
            int strategy = this->md->tacticalAI.strategicNumber(0xA1);

            if (strategy == 1 && numStoragePits == 0 && numGranaries == 0)
                canBuild = 0;
            if (strategy == 2 && this->md->resourceAI.resource(1) < 250 && numGranaries == 0)
                canBuild = 0;
            if (strategy == 3 && numStoragePits == 0)
                canBuild = 0;
            if (strategy == 4 && (numStoragePits == 0 || numGranaries == 0))
                canBuild = 0;

            if (category == 0 && !canBuild && item->buildCategory() == 0 &&
                item->typeID() != 0x46 && item->typeID() != 0x6D &&
                item->typeID() != 0x67 && item->typeID() != 0x44) {
                goto next_item;
            }
            else {
                if (category == 0 && item->buildCategory() == 0 &&
                    (numStoragePits == 0 || numGranaries == 0) &&
                    numHouses >= this->md->tacticalAI.strategicNumber(0xAE) &&
                    item->typeID() != 0x6D && item->typeID() != 0x67 &&
                    item->typeID() != 0x44) {
                    goto next_item;
                }
                else {
                    if (item->buildCategory() == 5 && count == 0) {
                        this->md->tacticalAI.enableAttack(1);
                        item->setInProgress(0);
                        item->setBuilt(1);
                        goto next_item;
                    }
                    else if (item->buildCategory() == 6) {
                        if (count < 1) {
                            this->md->tacticalAI.setStrategicNumber(
                                item->typeID() + 0x9C, item->buildFrom());
                            item->setInProgress(0);
                            item->setBuilt(1);
                        }
                        goto next_item;
                    }
                    else if (category == 3 && count > 0) {
                        return 0;
                    }
                    else {
                        int buildCap = item->buildCap();
                        if (buildCap != -1) {
                            int currentCap = item->buildCap();
                            int numberBuilds = item->numberBuilds();
                            if (numberBuilds > currentCap)
                                goto next_item;
                        }

                        if (category == 1 &&
                            (item->buildCategory() == 1 || item->buildCategory() == 4) &&
                            this->md->aiPlayer->researchEverAvailable(item->typeID()) == 0) {
                            item->setInProgress(0);
                            item->setBuilt(1);
                        }
                        else {
                            if (item->buildCategory() == 4) {
                                ResourceItem itemCost(4);
                                this->md->aiPlayer->researchCost(
                                    item->typeID(), -1, &itemCost, 1);
                                if (this->md->aiPlayer->researchAvailable(item->typeID()) == 0 ||
                                    this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                                    return 0;
                                if (category != 1) {
                                    return 0;
                                }
                            }

                            if (item->skip() == 1 && item->buildAttempts() > 0 ||
                                item->permanentSkip() != 0) {
                                item->decrementBuildAttempts();
                                goto next_item;
                            }
                            else {
                                if (item->skip() == 1 && item->buildAttempts() <= 0) {
                                    item->setSkip(0);
                                    if (item->buildCategory() == 0 &&
                                        (item->typeID() == 0x67 || item->typeID() == 0x44)) {
                                        item->setBuildAttempts(
                                            this->md->tacticalAI.strategicNumber(0x72) - 1);
                                    }
                                }

                                if (this->md->player->attributes[0x0B] <
                                        this->md->player->attributes[0x20] ||
                                    item->buildCategory() != 2) {
                                    ++count;
                                }

                                if (category == 1 && item->buildCategory() != 1 &&
                                    item->buildCategory() != 4)
                                    goto next_item;
                                if (category != 1 && category != item->buildCategory())
                                    goto next_item;

                                if (category == 3 && item->buildCategory() != 3) {
                                    item->setBuildAttempts(0);
                                    return 0;
                                }

                                item->incrementBuildAttempts();
                                int buildAttempts = item->buildAttempts();
                                if (buildAttempts >
                                    this->md->tacticalAI.strategicNumber(0x72)) {
                                    if (item->skip() == 0 && item->permanentSkip() == 0) {
                                        if (category == 1 && item->buildCategory() == 4) {
                                            item->setBuildAttempts(0);
                                            return 0;
                                        }

                                        int strategic = this->md->tacticalAI.strategicNumber(0xB1);
                                        if (item->typeID() != strategic ||
                                            item->buildCategory() != 0) {
                                            item->setSkip(1);
                                            if (item->buildCategory() == 0 &&
                                                (item->typeID() == 0x67 ||
                                                 item->typeID() == 0x44)) {
                                                item->setBuildAttempts(
                                                    this->md->tacticalAI.strategicNumber(0x72) * 6);
                                            }
                                            else {
                                                item->setBuildAttempts(
                                                    this->md->tacticalAI.strategicNumber(0x72));
                                            }
                                            goto next_item;
                                        }
                                    }
                                }

                                if (category == 3 && item->buildCategory() == 3) {
                                    strncpy(this->currentBuildItemRequestedValue,
                                            item->name(), 0x3F);
                                    this->numberItemsIntoBuildListValue = item->uniqueID();
                                    strncpy(this->nextBuildItemRequestedValue,
                                            item->next->name(), 0x3F);
                                    this->numberItemsIntoBuildListValue = item->uniqueID();
                                    return item;
                                }

                                if (category == 1) {
                                    if (this->md->aiPlayer->researchAvailable(item->typeID()) != 0)
                                        goto cost_block;
                                }
                                else if (this->md->aiPlayer->objectAvailable(item->typeID()) != 0) {
                                    goto cost_block;
                                }
                                goto next_item;

cost_block:
                                {
                                    ResourceItem itemCost2(4);
                                    if (category == 1) {
                                        this->md->aiPlayer->researchCost(
                                            item->typeID(), -1, &itemCost2, 1);
                                    }
                                    else {
                                        this->md->aiPlayer->objectCost(
                                            item->typeID(), -1, &itemCost2, 1);
                                    }

                                    if (this->md->resourceAI.resourcesAvailable(&itemCost2)) {
                                        int found;
                                        if (category == 2 || category == 1) {
                                            found = (int)this->md->object(
                                                -1, item->buildFrom(), -1, -1, -1,
                                                -1, -1, -1, 2, -1);
                                        }
                                        else {
                                            found = this->md->constructionAI.canPlace(item);
                                        }
                                        if (found != 0) {
                                            strncpy(this->currentBuildItemRequestedValue,
                                                    item->name(), 0x3F);
                                            this->numberItemsIntoBuildListValue = item->uniqueID();
                                            strncpy(this->nextBuildItemRequestedValue,
                                                    item->next->name(), 0x3F);
                                            this->numberItemsIntoBuildListValue = item->uniqueID();
                                            return item;
                                        }
                                        item = item->next;
                                        goto loop_check;
                                    }
                                    item = item->next;
                                    goto loop_check;
                                }
                            }
                        }
                    }
                }
            }
        }

next_item:
        item = item->next;
loop_check:
        if (count <= this->md->tacticalAI.strategicNumber(0x73))
            continue;
        return 0;
    }
}

int TribeBuildAIModule::nextBuildListItemCategory()
{
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1 &&
            !item->permanentSkip()) {
            return item->buildCategory();
        }
        item = item->next;
    }

    return 0;
}

int TribeBuildAIModule::blockingResource()
{
    BuildItem& list = this->buildList;
    BuildItem* item = list.next;
    while (item != &list && item != 0 &&
           (item->built() || item->inProgress() || item->skip() == 1 || item->permanentSkip())) {
        item = item->next;
    }
    if (item == &list || item == 0) {
        return -1;
    }

    ResourceItem itemCost(4);
    if (item->buildCategory() == 1 || item->buildCategory() == 4) {
        this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
    }
    else {
        this->md->aiPlayer->objectCost(item->typeID(), -1, &itemCost, 1);
    }

    if (!this->md->resourceAI.resourcesAvailable(&itemCost)) {
        return this->md->resourceAI.unavailableResource(&itemCost);
    }
    return -1;
}

int TribeBuildAIModule::mostNeededResource(ResourceItem& item, int maxCount)
{
    item.setAllValues(0);

    BuildItem* buildItem = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;

    if (buildItem != sentinel) {
        while (buildItem != sentinel) {
            if (buildItem == 0) {
                break;
            }

            if (buildItem->built() == 0 &&
                buildItem->inProgress() == 0 &&
                buildItem->buildCategory() != 6) {
                int cap = buildItem->buildCap();
                if (cap == -1 ||
                    buildItem->numberBuilds() <= buildItem->buildCap()) {
                    if (buildItem->buildCategory() == 1 ||
                        buildItem->buildCategory() == 4) {
                        this->md->aiPlayer->researchCost(
                            buildItem->typeID(), -1, &item, 1);
                    } else {
                        this->md->aiPlayer->objectCost(
                            buildItem->typeID(), -1, &item, 1);
                    }

                    if (++count == maxCount) {
                        break;
                    }
                }
            }

            buildItem = buildItem->next;
        }
    }

    return count;
}

int TribeBuildAIModule::addItem(RGE_Static_Object* object, int flag)
{
    if (this->md->informationAI.isBuilding(object)) {
        this->md->constructionAI.setBuilt(object, 1);
    }

    if (flag == 0) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;

        if (item != sentinel) {
            while (item != sentinel) {
                if (item == 0) {
                    break;
                }

                if (item->typeID() == object->master_obj->id) {
                    if (item->built() == 0) {
                        item->setGameID(object->id);
                        item->setInProgress(0);
                        item->setBuilt(1);
                        item->incrementNumberBuilds();
                        if (item->typeID() == 0x114) {
                            this->md->tacticalAI.wonderBuiltValue = 1;
                        }
                        return 1;
                    }
                }

                item = item->next;
            }
        }
    }

    return 0;
}

int TribeBuildAIModule::addBuiltItem(RGE_Static_Object* object, int id)
{
    int found = 0;
    BuildItem* item = (BuildItem*)this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        if (item->typeID() == object->master_obj->id &&
            item->built() == 0 &&
            id != -1 &&
            item->uniqueID() == id) {
            item->setInProgress(found);
            found = 1;
            item->setBuilt(found);
            item->setGameID(object->id);
            item->incrementNumberBuilds();
            if (item->typeID() == 0x114) {
                this->md->tacticalAI.wonderBuiltValue = found;
            }
            strncpy(this->lastBuildItemRequestedValue, item->name(), 0x3F);
            this->numberItemsIntoBuildListValue = item->uniqueID();
        } else {
            item = (BuildItem*)item->next;
        }
    }

    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::removeBuiltItem(int id)
{
    BuildItem* item = this->buildList.next;
    int found = 0;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        if (item->gameID() == id && item->built() == 1) {
            item->setInProgress(found);
            item->setBuilt(found);
            item->setGameID(-1);
            item->setBuildAttempts(found);
            if (item->typeID() == 0x114) {
                this->md->tacticalAI.wonderBuiltValue = found;
            }
            found = 1;
        } else {
            item = item->next;
        }
    }

    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::cancelBuildItem(int action, int objId, int objectTypeId,
                                        float x, float y, int uniqueBuildId, int taskId)
{
    BuildItem* item;
    if (taskId != -1) this->md->detask(taskId);
    int moving = 0;
    int lotStatus = moving;
    unsigned char newLotStatus = 2;
    switch (action) {
    case -1:
        lotStatus = 1;
        moving = 0;
        newLotStatus = 0;
        break;
    case 8:
        moving = 1;
        lotStatus = moving;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        lotStatus = 1;
        moving = 0;
        break;
    }
    RGE_Static_Object* obj = this->md->object(objId);
    if (obj && moving == 1) {
        if (this->md->isMoveable(objId) == 1) {
            ConstructionItem* lot = this->md->constructionAI.lot(x, y);
            if (lot) {
                this->md->tacticalAI.clearArea(objId,
                    lot->x() - lot->xSize() * 0.5f,
                    lot->y() - lot->ySize() * 0.5f,
                    lot->x() - lot->xSize() * -0.5f,
                    lot->y() - lot->ySize() * -0.5f);
            } else {
                this->md->tacticalAI.clearArea(objId, x - 2.0f, y - 2.0f,
                                                x - -2.0f, y - -2.0f);
            }
        } else {
            this->md->constructionAI.incrementBuildAttempts(x, y, 10);
        }
    }
    this->md->constructionAI.unplaceStructure(x, y, lotStatus);
    item = this->specificBuildListItem(uniqueBuildId);
    if (item) {
        item->setInProgress(0);
        this->md->informationAI.removeLot(item->typeID(), (int)x, (int)y, newLotStatus);
        if (item->typeID() == 0x114) this->md->tacticalAI.wonderInProgressValue = 0;
    }
    return 1;
}

int TribeBuildAIModule::addTrainedUnit(int param1, int param2, int param3, int param4)
{
    BuildItem* item;

    item = this->specificBuildListItem(param3);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->setGameID(param4);
        item->incrementNumberBuilds();
    }
    this->md->detask(param2);
    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::cancelTrainUnit(int p1, int p2, int p3, int p4)
{
    int val = *(int*)(*(int*)(*(int*)((char*)this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory("Canceling training (WT=%ld) for item of type %d at building w/ gameID=%d.", val, p2, p3);

    BuildItem* item = (BuildItem*)this->specificBuildListItem(p4);

    if (item) {
        this->logCommonHistory("  Setting build item #%d in progress to FALSE.", item->uniqueID());
        item->setInProgress(0);
    } else {
        this->logCommonHistory("  ERROR!  Invalid build item.");
    }

    this->displayBuildList();
    return 1;
}

int TribeBuildAIModule::addResearch(int param1, int param2, int param3)
{
    BuildItem* item = this->specificBuildListItem(param3);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->incrementNumberBuilds();
    }
    this->md->detask(param2);
    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::cancelResearch(int p1, int p2, int p3, int p4)
{
    int val = *(int*)(*(int*)(*(int*)((char*)this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory("Canceling research (WT=%ld) for item of type %d, %d", val, p2, p3);

    BuildItem* item = (BuildItem*)this->specificBuildListItem(p4);

    if (item) {
        this->logCommonHistory("  Setting build item #%d in progress to FALSE", item->uniqueID());
        item->setInProgress(0);
    } else {
        this->logCommonHistory("  ERROR!  Invalid build item.");
    }

    this->displayBuildList();
    return 1;
}

int TribeBuildAIModule::isAgeResearch(int value)
{
    if (value == 0x65 || value == 0x66 || value == 0x67)
        return 1;
    return 0;
}

int TribeBuildAIModule::insert(int p1, int p2, int p3)
{
    int flags;
    int buildCat;

    switch (p1) {
    case 4:
    case 5:
    case 0x19:
    case 0x27:
    case 0x29:
        buildCat = 0x57;
        flags = 2;
        break;
    case 0x0B:
    case 0x23:
    case 0x24:
        buildCat = 0x31;
        flags = 2;
        break;
    case 0x53:
        buildCat = 0x6D;
        flags = 2;
        break;
    case 0x49:
    case 0x4B:
        buildCat = 0x0C;
        flags = 2;
        break;
    case 0x5D:
        buildCat = 0;
        flags = 2;
        break;
    case 0x7D:
        buildCat = 0x68;
        flags = 2;
        break;
    case 0x25:
    case 0x28:
    case 0x2E:
    case 0x12B:
        buildCat = 0x65;
        flags = 2;
        break;
    case 0x0D:
    case 0x0F:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0xFA:
        buildCat = 0x2D;
        flags = 2;
        break;
    case 0x2D:
    case 0x31:
    case 0x32:
    case 0x4F:
    case 0x67:
    case 0xC7:
    case 0x114:
    case 0x116:
    case 0x44:
    case 0x45:
    case 0x46:
        buildCat = -1;
        flags = 0;
        break;
    default:
        return 0;
    }

    if (p3 == -1) {
        BuildItem* item = this->buildList.next;
        int count = 0;

        while (item != &this->buildList && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }

        return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, count);
    }

    return this->insertItem(this->md->player, p1, 1, flags, buildCat, p2, p3);
}

int TribeBuildAIModule::insertResearch(int research, int index)
{
    if (research != 5 && (research <= 6 || research > 8)) {
        return 0;
    }

    if (index == -1) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;
        int count = 0;
        while (item != sentinel && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }
        return this->insertItem(this->md->player, research, 1, 1, 0x2d, 1, count);
    }
    return this->insertItem(this->md->player, research, 1, 1, 0x2d, 1, index);
}

int TribeBuildAIModule::insertGathererPercentage(int index, int percentage, int bronzeAgeIndex)
{
    return this->insertItem(this->md->player, index, 1, 6, percentage, 1, bronzeAgeIndex);
}

int TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int type, int flag)
{
    int count;
    if (flag == 0 && (type == 0x67 || type == 0x44)) {
        count = this->numberInProgressItemsOfType(type, 0);
        if (type == 0x67) {
            count += this->md->informationAI.numberStoragePits();
        } else {
            count += this->md->informationAI.numberGranaries();
        }
    } else {
        count = BuildAIModule::numberBuiltOrInProgressItemsOfType(type, flag);
    }
    return count;
}

int TribeBuildAIModule::allBuilt(int param_1, int param_2)
{
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (item != sentinel) {
        int bx = param_2;
        int bp = param_1;
        while (item != sentinel) {
            if (item == 0) {
                break;
            }
            if ((item->buildCategory() == bp || item->buildCategory() == bx) &&
                !item->built() && !item->inProgress()) {
                return 0;
            }
            item = item->next;
        }
    }
    return 1;
}

int TribeBuildAIModule::readyToResearch(int id, int ageResearch)
{
    unsigned char rState;

    if (ageResearch == 1) {
        if (id == 2) {
            rState = this->md->aiPlayer->researchState(0x65);
        } else {
            rState = id;
        }
        if (id == 3) {
            rState = this->md->aiPlayer->researchState(0x66);
        }
        if (id == 4) {
            rState = this->md->aiPlayer->researchState(0x67);
        }
    } else {
        rState = this->md->aiPlayer->researchState(id);
    }

    return rState == 1;
}

void TribeBuildAIModule::unskipBuildList(int limit67, int limit44)
{
    int lim67 = this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int lim44 = this->numberBuiltOrInProgressItemsOfType(0x44, 0);

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (item == sentinel) return;
    if (item == 0) return;

    for (;;) {
        if (item == 0) break;
        if (item->built() == 1) goto next;
        if (item->inProgress() == 1) goto next;
        if (lim67 > 0 && item->typeID() == 0x67) goto next;
        if (lim44 > 0 && item->typeID() == 0x44) goto next;

        item->setSkip(0);
        item->setBuildAttempts(0);
        item->setSkipCycles(0);
        item->setPermanentSkip(0);

next:
        item = item->next;
        if (item == sentinel) break;
    }
}

BuildItem* TribeBuildAIModule::buildItem(int type, int category1, int category2)
{
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (!item->built() && !item->inProgress() && item->typeID() == type) {
            if (item->buildCategory() == category1 || item->buildCategory() == category2) {
                return item;
            }
        }
        item = item->next;
    }

    return 0;
}
