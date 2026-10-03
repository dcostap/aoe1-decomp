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

TribeBuildAIModule::TribeBuildAIModule(void* pW, int pID)
    : BuildAIModule(pW, pID), md(0) {
}

TribeBuildAIModule::TribeBuildAIModule(int pID, int infile)
    : BuildAIModule(pID, infile), md(0) {
}

TribeBuildAIModule::~TribeBuildAIModule() {
}

void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

int TribeBuildAIModule::loadBuildList(char* lName, RGE_Player* player) {
    this->typesToIgnore.add(0x46);
    this->typesToIgnore.add(0x67);
    this->typesToIgnore.add(0x44);
    return BuildAIModule::loadBuildList(lName, player);
}

void TribeBuildAIModule::initialize() {
    int bronzeAgeIndex = 0;
    int transportCount = 0;
    int toolAgeIndex = 0;
    int fishingBoatCount = 0;
    int resource_building_count = 0;
    int warshipCount = -1;
    int triremeUpgrade = -1;
    int transportUpgrade = -1;
    int ironAgeIndex = 0;
    int warshipUpgrade = 0;
    int dockCount = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    while (item != sentinel && item != 0) {
        if (item->buildCategory() == 0) {
            if (item->typeID() == 0x46) {
                ++bronzeAgeIndex;
            } else if (item->typeID() == 0x2D) {
                ++transportCount;
            }
        } else if (item->buildCategory() == 2) {
            if (item->typeID() == 0x0D) {
                ++toolAgeIndex;
            } else if (item->typeID() == 0x11 || item->typeID() == 0x12) {
                ++fishingBoatCount;
            } else if (item->typeID() == 0x13 || item->typeID() == 0xFA) {
                ++resource_building_count;
            }
        } else if (item->buildCategory() == 1 || item->buildCategory() == 4) {
            if (item->typeID() == 0x65) {
                warshipCount = item->uniqueID();
            } else if (item->typeID() == 0x66) {
                triremeUpgrade = item->uniqueID();
            } else if (item->typeID() == 0x67) {
                transportUpgrade = item->uniqueID();
            } else if (item->typeID() == 5) {
                ironAgeIndex = 1;
            } else if (item->typeID() == 7) {
                warshipUpgrade = 1;
            } else if (item->typeID() == 8) {
                dockCount = 1;
            }
        }

        item = item->next;
    }

    int count;
    int spacing;
    int index;

    if (transportCount < this->md->tacticalAI.strategicNumber(0xD4) && this->md->tacticalAI.strategicNumber(0xD0) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD4) - transportCount;
        if (triremeUpgrade != -1) {
            spacing = triremeUpgrade / count;
        } else if (warshipCount != -1) {
            spacing = warshipCount / count;
        } else {
            spacing = 10;
        }

        index = spacing;
        while (count > 0) {
            this->insert(0x2D, -1, index);
            index += spacing;
            --count;
        }
    }

    if (toolAgeIndex < this->md->tacticalAI.strategicNumber(0xD5) && this->md->tacticalAI.strategicNumber(0xD1) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD5) - toolAgeIndex;
        if (count > 0) {
            if (triremeUpgrade != -1) {
                spacing = triremeUpgrade / count;
            } else if (warshipCount != -1) {
                spacing = warshipCount / count;
            } else {
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

    if (fishingBoatCount < this->md->tacticalAI.strategicNumber(0xD6) && this->md->tacticalAI.strategicNumber(0xD2) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD6) - fishingBoatCount;
        if (warshipCount != -1) {
            spacing = (this->buildListLengthValue - warshipCount) / (count * 2);
            index = triremeUpgrade;
        } else if (triremeUpgrade != -1) {
            spacing = (this->buildListLengthValue - triremeUpgrade) / (count * 2);
            index = -1;
        } else {
            spacing = 10;
            index = 0;
        }

        while (count > 0) {
            index += spacing;
            this->insert(0x11, -1, index);
            --count;
        }

        if (!dockCount && transportUpgrade != -1) {
            this->insertResearch(8, transportUpgrade + 2);
        }
    }

    if (resource_building_count < this->md->tacticalAI.strategicNumber(0xE0) &&
        this->md->tacticalAI.strategicNumber(0xDF) == 1 && (transportUpgrade != -1 || triremeUpgrade != -1)) {
        count = this->md->tacticalAI.strategicNumber(0xE0) - resource_building_count;
        if (transportUpgrade != -1) {
            spacing = transportUpgrade / count;
        } else {
            spacing = triremeUpgrade / count;
        }

        index = spacing;
        while (count > 0) {
            this->insertResearch(0x13, index);
            index += spacing;
            --count;
        }

        if (!ironAgeIndex && triremeUpgrade != -1) {
            this->insertResearch(5, triremeUpgrade + 5);
        }
        if (!warshipUpgrade && transportUpgrade != -1) {
            //! @bug This anchor is the Iron Age entry's load-time index, but earlier inserts shift the list.
            //! Six or more splices then place Trireme before the Iron Age entry and break the dependency order.
            //! The same stale-anchor defect affects the Heavy Transport and Medium War Ship inserts above.
            this->insertResearch(7, transportUpgrade + 5);
        }
    }

    if (bronzeAgeIndex == 0 && this->md->tacticalAI.strategicNumber(0xB4) == 1) {
        item = this->buildList.next;
        int buildIndex = 0;
        int houseCount = 0;
        int trainedCount = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == 0 && item->typeID() == 0x6D) {
                houseCount += 4;
            }
            if (item->buildCategory() == 2) {
                ++trainedCount;
            }
            if (trainedCount > houseCount) {
                int insertIndex;
                if (buildIndex > 1) {
                    insertIndex = buildIndex - 1;
                } else {
                    insertIndex = 1;
                }
                if (this->insert(0x46, -1, insertIndex) == 1) {
                    houseCount += 4;
                }
            }
            if (houseCount > this->md->tacticalAI.strategicNumber(0x98) + 50) {
                break;
            }

            item = item->next;
            ++buildIndex;
        }
    }

    int totalPercentage = this->md->tacticalAI.strategicNumber(0xA0);
    int requiredPop = this->md->tacticalAI.strategicNumber(0x9B) + 4;
    if (totalPercentage != 0) {
        item = this->buildList.next;
        ResourceItem resourceCount(4);
        resourceCount.setAllValues(0);
        int itemCount = 0;
        int divisionSize = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == 6) {
                item = item->next;
                ++itemCount;
            } else {
                if (item->buildCategory() == 1 || item->buildCategory() == 4) {
                    this->md->aiPlayer->researchCost(item->typeID(), -1, &resourceCount, 1);
                } else {
                    this->md->aiPlayer->objectCost(item->typeID(), -1, &resourceCount, 1);
                }

                ++itemCount;
                if (itemCount >= requiredPop) {
                    int totalCost = 0;
                    int resource;
                    for (resource = 0; resource < 4; ++resource) {
                        totalCost += resourceCount.value(resource);
                    }

                    if (totalCost > 0) {
                        for (resource = 0; resource < 4; ++resource) {
                            this->insertGathererPercentage(resource,
                                                           resourceCount.value(resource) * totalPercentage / totalCost, divisionSize);
                        }
                        resourceCount.setAllValues(0);
                        divisionSize += requiredPop;
                        itemCount = 0;
                    }
                }

                item = item->next;
            }
        }
    }
}

void TribeBuildAIModule::skipNextBuildListItem() {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1) {
            if (item->typeID() != this->md->tacticalAI.strategicNumber(0xB1) || item->buildCategory() != 0) {
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

BuildItem* TribeBuildAIModule::nextBuildableItem(int category) {
    int numStoragePits =
        this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int numGranaries =
        this->numberBuiltOrInProgressItemsOfType(0x44, 0);
    int numHouses =
        this->numberBuiltOrInProgressItemsOfType(0x46, 0);
    int count = 0;
    int realCount = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (this->md->tacticalAI.strategicNumber(0x73) < 0) {
        return 0;
    }

    do {
        if (item == sentinel || item == 0) {
            break;
        }

        if ((item->buildCategory() == 1 || item->buildCategory() == 4) && this->isAgeResearch(item->typeID()) == 1) {
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
            }
        }

        if (item->built() == 0 && item->inProgress() == 0) {
            ++count;

            int canBuild = 1;
            int order = this->md->tacticalAI.strategicNumber(0xA1);
            if (order == 1 && numGranaries == 0 && numStoragePits == 0) {
                canBuild = 0;
            }
            if (order == 2 && this->md->resourceAI.resource(1) < 250 && numStoragePits == 0) {
                canBuild = 0;
            }
            if (order == 3 && numGranaries == 0) {
                canBuild = 0;
            }
            if (order == 4 && (numGranaries == 0 || numStoragePits == 0)) {
                canBuild = 0;
            }

            if (category == 0 && !canBuild && item->buildCategory() == 0 &&
                item->typeID() != 0x46 && item->typeID() != 0x6D && item->typeID() != 0x67 && item->typeID() != 0x44) {
                item = item->next;
                continue;
            }

            if (category == 0 && item->buildCategory() == 0 && (numGranaries == 0 || numStoragePits == 0) &&
                numHouses >= this->md->tacticalAI.strategicNumber(0xAE) &&
                item->typeID() != 0x6D && item->typeID() != 0x67 && item->typeID() != 0x44) {
                item = item->next;
                continue;
            }

            if (item->buildCategory() == 5 && realCount == 0) {
                this->md->tacticalAI.enableAttack(1);
                item->setInProgress(0);
                item->setBuilt(1);
                item = item->next;
                continue;
            }

            if (item->buildCategory() == 6) {
                if (realCount < 1) {
                    this->md->tacticalAI.setStrategicNumber(item->typeID() + 0x9C, item->buildFrom());
                    item->setInProgress(0);
                    item->setBuilt(1);
                }
                item = item->next;
                continue;
            }

            if (category == 3 && realCount > 0) {
                return 0;
            }

            if (item->buildCap() != -1) {
                int buildCap = item->buildCap();
                if (item->numberBuilds() > buildCap) {
                    item = item->next;
                    continue;
                }
            }

            if (category == 1 && (item->buildCategory() == 1 || item->buildCategory() == 4) &&
                this->md->aiPlayer->researchEverAvailable(item->typeID()) == 0) {
                item->setInProgress(0);
                item->setBuilt(1);
                item = item->next;
                continue;
            }

            if (item->buildCategory() == 4) {
                ResourceItem itemCost(4);
                this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
                if (!this->md->aiPlayer->researchAvailable(item->typeID()) ||
                    !this->md->resourceAI.resourcesAvailable(&itemCost) || category != 1) {
                    return 0;
                }
            }

            if ((item->skip() == 1 && item->buildAttempts() > 0) || item->permanentSkip()) {
                item->decrementBuildAttempts();
                item = item->next;
                continue;
            }

            if (item->skip() == 1 && item->buildAttempts() <= 0) {
                item->setSkip(0);
                if (item->buildCategory() == 0 && (item->typeID() == 0x67 || item->typeID() == 0x44)) {
                    item->setBuildAttempts(this->md->tacticalAI.strategicNumber(0x72) - 1);
                }
            }

            if (this->md->player->attributes[11] < this->md->player->attributes[32] || item->buildCategory() != 2) {
                ++realCount;
            }

            if (category == 1) {
                if (item->buildCategory() != 1 && item->buildCategory() != 4) {
                    item = item->next;
                    continue;
                }
            } else if (item->buildCategory() != category) {
                item = item->next;
                continue;
            }

            if (category == 3 && item->buildCategory() != 3) {
                item->setBuildAttempts(0);
                return 0;
            }

            item->incrementBuildAttempts();
            int buildAttempts = item->buildAttempts();
            if (buildAttempts > this->md->tacticalAI.strategicNumber(0x72) && item->skip() == 0 && !item->permanentSkip()) {
                if (category == 1 && item->buildCategory() == 4) {
                    item->setBuildAttempts(0);
                    return 0;
                }

                if (item->typeID() != this->md->tacticalAI.strategicNumber(0xB1) || item->buildCategory() != 0) {
                    item->setSkip(1);
                    if (item->buildCategory() == 0 && (item->typeID() == 0x67 || item->typeID() == 0x44)) {
                        item->setBuildAttempts(this->md->tacticalAI.strategicNumber(0x72) * 6);
                    } else {
                        item->setBuildAttempts(this->md->tacticalAI.strategicNumber(0x72));
                    }
                    item = item->next;
                    continue;
                }
            }

            if (category == 3 && item->buildCategory() == 3) {
                strncpy(this->currentBuildItemRequestedValue, item->name(), 63);
                this->numberItemsIntoBuildListValue = item->uniqueID();
                strncpy(this->nextBuildItemRequestedValue, item->next->name(), 63);
                this->numberItemsIntoBuildListValue = item->uniqueID();
                return item;
            }

            int available;
            if (category == 1) {
                available =
                    this->md->aiPlayer->researchAvailable(item->typeID());
            } else {
                available =
                    this->md->aiPlayer->objectAvailable(item->typeID());
            }
            if (available) {
                ResourceItem itemCost(4);
                if (category == 1) {
                    this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
                } else {
                    this->md->aiPlayer->objectCost(item->typeID(), -1, &itemCost, 1);
                }

                if (this->md->resourceAI.resourcesAvailable(&itemCost)) {
                    int canBuildItem;
                    if (category == 2 || category == 1) {
                        canBuildItem = this->md->object(-1, item->buildFrom(), -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ACTIVE, -1) != 0;
                    } else {
                        canBuildItem =
                            this->md->constructionAI.canPlace(item);
                    }

                    if (canBuildItem) {
                        strncpy(this->currentBuildItemRequestedValue, item->name(), 63);
                        this->numberItemsIntoBuildListValue = item->uniqueID();
                        strncpy(this->nextBuildItemRequestedValue, item->next->name(), 63);
                        this->numberItemsIntoBuildListValue = item->uniqueID();
                        return item;
                    }
                }

                item = item->next;
                continue;
            }
        }

        item = item->next;
    } while (realCount <= this->md->tacticalAI.strategicNumber(0x73));

    return 0;
}

int TribeBuildAIModule::nextBuildListItemCategory() {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1 && !item->permanentSkip()) {
            return item->buildCategory();
        }
        item = item->next;
    }

    return 0;
}

int TribeBuildAIModule::blockingResource() {
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
    } else {
        this->md->aiPlayer->objectCost(item->typeID(), -1, &itemCost, 1);
    }

    if (!this->md->resourceAI.resourcesAvailable(&itemCost)) {
        return this->md->resourceAI.unavailableResource(&itemCost);
    }
    return -1;
}

int TribeBuildAIModule::mostNeededResource(ResourceItem& itemCost, int countNum) {
    itemCost.setAllValues(0);

    BuildItem* buildItem = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;

    if (buildItem != sentinel) {
        while (buildItem != sentinel) {
            if (buildItem == 0) {
                break;
            }

            if (buildItem->built() == 0 && buildItem->inProgress() == 0 && buildItem->buildCategory() != 6) {
                int cap = buildItem->buildCap();
                if (cap == -1 || buildItem->numberBuilds() <= buildItem->buildCap()) {
                    if (buildItem->buildCategory() == 1 || buildItem->buildCategory() == 4) {
                        this->md->aiPlayer->researchCost(buildItem->typeID(), -1, &itemCost, 1);
                    } else {
                        this->md->aiPlayer->objectCost(buildItem->typeID(), -1, &itemCost, 1);
                    }

                    if (++count == countNum) {
                        break;
                    }
                }
            }

            buildItem = buildItem->next;
        }
    }

    return count;
}

int TribeBuildAIModule::addItem(RGE_Static_Object* newItem, int gameStarted) {
    if (this->md->informationAI.isBuilding(newItem)) {
        this->md->constructionAI.setBuilt(newItem, 1);
    }

    //! @bug The gameStarted guard skips the only setGameID write during play.
    //! An unfinished building's row keeps gameID -1 (the strategy "unitId") until completion.
    //! removeBuiltItem() can then never match the row if the site dies unfinished.
    if (gameStarted == 0) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;

        if (item != sentinel) {
            while (item != sentinel) {
                if (item == 0) {
                    break;
                }

                if (item->typeID() == newItem->master_obj->id) {
                    if (item->built() == 0) {
                        item->setGameID(newItem->id);
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

int TribeBuildAIModule::addBuiltItem(RGE_Static_Object* newItem, int buildID) {
    int found = 0;
    BuildItem* item = (BuildItem*)this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        if (item->typeID() == newItem->master_obj->id && item->built() == 0 && buildID != -1 &&
            item->uniqueID() == buildID) {
            item->setInProgress(found);
            found = 1;
            item->setBuilt(found);
            item->setGameID(newItem->id);
            item->incrementNumberBuilds();
            if (item->typeID() == 0x114) {
                this->md->tacticalAI.wonderBuiltValue = found;
            }
            strncpy(this->lastBuildItemRequestedValue, item->name(), 63);
            this->numberItemsIntoBuildListValue = item->uniqueID();
        } else {
            item = (BuildItem*)item->next;
        }
    }

    this->md->tacticalAI.updateNeededResources();
    return 1;
}

//! @bug Destruction releases only the build list here; lot history stays claimed.
//! cancelBuildItem() releases lots, but only build-command placement failures reach it.
//! canPlace() then returns 0 for the type and the AI never constructs it again.
int TribeBuildAIModule::removeBuiltItem(int id) {
    BuildItem* item = this->buildList.next;
    int found = 0;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        //! @bug This match requires built == 1, so a destroyed unfinished site never resets the row.
        //! The row keeps inProgress = 1 and the AI never builds that item again.
        //! A dead wonder site also leaves wonderInProgressValue set, which blocks all construction.
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

int TribeBuildAIModule::cancelBuildItem(int reason, int blockerID, int blockerType,
                                        float x, float y, int uniqueID, int builderID) {
    BuildItem* item;
    if (builderID != -1)
        this->md->detask(builderID);
    int moving = 0;
    int decrementWallBuild = moving;
    unsigned char newLotStatus = 2;
    switch (reason) {
    case -1:
        decrementWallBuild = 1;
        moving = 0;
        newLotStatus = 0;
        break;
    case 8:
        moving = 1;
        decrementWallBuild = moving;
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
        decrementWallBuild = 1;
        moving = 0;
        break;
    }
    RGE_Static_Object* obj = this->md->object(blockerID);
    if (obj && moving == 1) {
        if (this->md->isMoveable(blockerID) == 1) {
            ConstructionItem* lot = this->md->constructionAI.lot(x, y);
            if (lot) {
                this->md->tacticalAI.clearArea(blockerID, lot->x() - lot->xSize() * 0.5f, lot->y() - lot->ySize() * 0.5f,
                                               lot->x() - lot->xSize() * -0.5f, lot->y() - lot->ySize() * -0.5f);
            } else {
                this->md->tacticalAI.clearArea(blockerID, x - 2.0f, y - 2.0f, x + 2.0f, y + 2.0f);
            }
        } else {
            this->md->constructionAI.incrementBuildAttempts(x, y, 10);
        }
    }
    this->md->constructionAI.unplaceStructure(x, y, decrementWallBuild);
    item = this->specificBuildListItem(uniqueID);
    if (item) {
        item->setInProgress(0);
        this->md->informationAI.removeLot(item->typeID(), (int)x, (int)y, newLotStatus);
        if (item->typeID() == 0x114)
            this->md->tacticalAI.wonderInProgressValue = 0;
    }
    return 1;
}

int TribeBuildAIModule::addTrainedUnit(int uType, int location, int uniqueID,
                                       int gameID) {
    BuildItem* item;

    item = this->specificBuildListItem(uniqueID);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->setGameID(gameID);
        item->incrementNumberBuilds();
    }
    this->md->detask(location);
    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::cancelTrainUnit(int reason, int uType, int location,
                                        int uniqueID) {
    int val = *(int*)(*(int*)(*(int*)((char*)this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory("Canceling training (WT=%ld) for item of type %d at building w/ gameID=%d.", val, uType, location);

    BuildItem* item = (BuildItem*)this->specificBuildListItem(uniqueID);

    if (item) {
        this->logCommonHistory("  Setting build item #%d in progress to FALSE.", item->uniqueID());
        item->setInProgress(0);
    } else {
        this->logCommonHistory("  ERROR!  Invalid build item.");
    }

    this->displayBuildList();
    return 1;
}

int TribeBuildAIModule::addResearch(int uType, int location, int uniqueID) {
    BuildItem* item = this->specificBuildListItem(uniqueID);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->incrementNumberBuilds();
    }
    this->md->detask(location);
    this->md->tacticalAI.updateNeededResources();
    return 1;
}

int TribeBuildAIModule::cancelResearch(int reason, int rType, int location,
                                       int uniqueID) {
    int val = *(int*)(*(int*)(*(int*)((char*)this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory("Canceling research (WT=%ld) for item of type %d, %d", val, rType, location);

    BuildItem* item = (BuildItem*)this->specificBuildListItem(uniqueID);

    if (item) {
        this->logCommonHistory("  Setting build item #%d in progress to FALSE", item->uniqueID());
        item->setInProgress(0);
    } else {
        this->logCommonHistory("  ERROR!  Invalid build item.");
    }

    this->displayBuildList();
    return 1;
}

int TribeBuildAIModule::isAgeResearch(int rID) {
    if (rID == 0x65 || rID == 0x66 || rID == 0x67)
        return 1;
    return 0;
}

int TribeBuildAIModule::insert(int typeID, int buildCap, int insertionPoint) {
    int flags;
    int buildCategory;

    switch (typeID) {
    case 4:
    case 5:
    case 0x19:
    case 0x27:
    case 0x29:
        buildCategory = 0x57;
        flags = 2;
        break;
    case 0x0B:
    case 0x23:
    case 0x24:
        buildCategory = 0x31;
        flags = 2;
        break;
    case 0x53:
        buildCategory = 0x6D;
        flags = 2;
        break;
    case 0x49:
    case 0x4B:
        buildCategory = 0x0C;
        flags = 2;
        break;
    case 0x5D:
        buildCategory = 0;
        flags = 2;
        break;
    case 0x7D:
        buildCategory = 0x68;
        flags = 2;
        break;
    case 0x25:
    case 0x28:
    case 0x2E:
    case 0x12B:
        buildCategory = 0x65;
        flags = 2;
        break;
    case 0x0D:
    case 0x0F:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0xFA:
        buildCategory = 0x2D;
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
        buildCategory = -1;
        flags = 0;
        break;
    default:
        return 0;
    }

    if (insertionPoint == -1) {
        BuildItem* item = this->buildList.next;
        int count = 0;

        while (item != &this->buildList && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }

        return this->insertItem(this->md->player, typeID, 1, flags, buildCategory, buildCap, count);
    }

    return this->insertItem(this->md->player, typeID, 1, flags, buildCategory, buildCap, insertionPoint);
}

int TribeBuildAIModule::insertResearch(int typeID, int insertionPoint) {
    if (typeID != 5 && (typeID <= 6 || typeID > 8)) {
        return 0;
    }

    if (insertionPoint == -1) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;
        int count = 0;
        while (item != sentinel && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }
        return this->insertItem(this->md->player, typeID, 1, 1, 0x2d, 1, count);
    }
    return this->insertItem(this->md->player, typeID, 1, 1, 0x2d, 1, insertionPoint);
}

int TribeBuildAIModule::insertGathererPercentage(int rType, int percentage,
                                                 int insertionPoint) {
    return this->insertItem(this->md->player, rType, 1, 6, percentage, 1, insertionPoint);
}

int TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int type, int category) {
    int count;
    if (category == 0 && (type == 0x67 || type == 0x44)) {
        count = this->numberInProgressItemsOfType(type, 0);
        if (type == 0x67) {
            count += this->md->informationAI.numberStoragePits();
        } else {
            count += this->md->informationAI.numberGranaries();
        }
    } else {
        count = BuildAIModule::numberBuiltOrInProgressItemsOfType(type, category);
    }
    return count;
}

int TribeBuildAIModule::allBuilt(int category1, int category2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (item != sentinel) {
        int first_category = category2;
        int second_category = category1;
        while (item != sentinel) {
            if (item == 0) {
                break;
            }
            if ((item->buildCategory() == second_category || item->buildCategory() == first_category) &&
                !item->built() && !item->inProgress()) {
                return 0;
            }
            item = item->next;
        }
    }
    return 1;
}

int TribeBuildAIModule::readyToResearch(int id, int ageResearch) {
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

void TribeBuildAIModule::unskipBuildList(int builtSP, int builtG) {
    int storage_pit_count = this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int granary_count = this->numberBuiltOrInProgressItemsOfType(0x44, 0);

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    for (; item != sentinel && item != 0; item = item->next) {
        if (item->built() == 1)
            continue;
        if (item->inProgress() == 1)
            continue;
        if (storage_pit_count > 0 && item->typeID() == 0x67)
            continue;
        if (granary_count > 0 && item->typeID() == 0x44)
            continue;

        item->setSkip(0);
        item->setBuildAttempts(0);
        item->setSkipCycles(0);
        item->setPermanentSkip(0);

    }
}

BuildItem* TribeBuildAIModule::buildItem(int typeID, int category1, int category2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (!item->built() && !item->inProgress() && item->typeID() == typeID) {
            if (item->buildCategory() == category1 || item->buildCategory() == category2) {
                return item;
            }
        }
        item = item->next;
    }

    return 0;
}
