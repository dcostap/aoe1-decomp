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
#include "../include/tech.h"
#include "../include/taibldmd.h"
#include "../include/taimdmd.h"
#include <string.h>

TribeBuildAIModule::TribeBuildAIModule(void* pW, int pID) : BuildAIModule(pW, pID), md(0) {
}

TribeBuildAIModule::TribeBuildAIModule(int pID, int infile) : BuildAIModule(pID, infile), md(0) {
}

TribeBuildAIModule::~TribeBuildAIModule() {
}

void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

int TribeBuildAIModule::loadBuildList(char* lName, RGE_Player* player) {
    this->typesToIgnore.add(MASTER_OBJECT_HOUSE);
    this->typesToIgnore.add(MASTER_OBJECT_STORAGE_PIT1);
    this->typesToIgnore.add(MASTER_OBJECT_GRANARY);
    return BuildAIModule::loadBuildList(lName, player);
}

void TribeBuildAIModule::initialize() {
    int houseCount = 0;
    int dockCount = 0;
    int fishingBoatCount = 0;
    int transportCount = 0;
    int warshipCount = 0;
    int toolAgeIndex = -1;
    int bronzeAgeIndex = -1;
    int ironAgeIndex = -1;
    int warshipUpgrade = 0;
    int triremeUpgrade = 0;
    int transportUpgrade = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    while (item != sentinel && item != 0) {
        if (item->buildCategory() == BUILD_CATEGORY_BUILDING) {
            if (item->typeID() == MASTER_OBJECT_HOUSE) {
                ++houseCount;
            } else if (item->typeID() == MASTER_OBJECT_DOCK_1) {
                ++dockCount;
            }
        } else if (item->buildCategory() == BUILD_CATEGORY_UNIT) {
            if (item->typeID() == MASTER_OBJECT_BOAT_FISHING1) {
                ++fishingBoatCount;
            } else if (item->typeID() == MASTER_OBJECT_BOAT_TRANSPORT1
                       || item->typeID() == MASTER_OBJECT_BOAT_TRANSPORT2) {
                ++transportCount;
            } else if (item->typeID() == MASTER_OBJECT_BOAT_WAR1 || item->typeID() == MASTER_OBJECT_BOAT_WAR4) {
                ++warshipCount;
            }
        } else if (item->buildCategory() == BUILD_CATEGORY_RESEARCH
                   || item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
            if (item->typeID() == TECH_TOOL_AGE) {
                toolAgeIndex = item->uniqueID();
            } else if (item->typeID() == TECH_BRONZE_AGE) {
                bronzeAgeIndex = item->uniqueID();
            } else if (item->typeID() == TECH_IRON_AGE) {
                ironAgeIndex = item->uniqueID();
            } else if (item->typeID() == TECH_MEDIUM_WAR_SHIP) {
                warshipUpgrade = 1;
            } else if (item->typeID() == TECH_TRIREME) {
                triremeUpgrade = 1;
            } else if (item->typeID() == TECH_HEAVY_TRANSPORT) {
                transportUpgrade = 1;
            }
        }

        item = item->next;
    }

    int count;
    int spacing;
    int index;

    if (dockCount < this->md->tacticalAI.strategicNumber(0xD4) && this->md->tacticalAI.strategicNumber(0xD0) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD4) - dockCount;
        if (bronzeAgeIndex != -1) {
            spacing = bronzeAgeIndex / count;
        } else if (toolAgeIndex != -1) {
            spacing = toolAgeIndex / count;
        } else {
            spacing = 10;
        }

        index = spacing;
        while (count > 0) {
            this->insert(MASTER_OBJECT_DOCK_1, -1, index);
            index += spacing;
            --count;
        }
    }

    if (fishingBoatCount < this->md->tacticalAI.strategicNumber(0xD5)
        && this->md->tacticalAI.strategicNumber(0xD1) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD5) - fishingBoatCount;
        if (count > 0) {
            if (bronzeAgeIndex != -1) {
                spacing = bronzeAgeIndex / count;
            } else if (toolAgeIndex != -1) {
                spacing = toolAgeIndex / count;
            } else {
                spacing = 10;
            }

            index = spacing;
            while (count > 0) {
                this->insert(MASTER_OBJECT_BOAT_FISHING1, -1, index);
                index += spacing;
                --count;
            }
        }
    }

    if (transportCount < this->md->tacticalAI.strategicNumber(0xD6)
        && this->md->tacticalAI.strategicNumber(0xD2) == 1) {
        count = this->md->tacticalAI.strategicNumber(0xD6) - transportCount;
        if (toolAgeIndex != -1) {
            spacing = (this->buildListLengthValue - toolAgeIndex) / (count * 2);
            index = bronzeAgeIndex;
        } else if (bronzeAgeIndex != -1) {
            spacing = (this->buildListLengthValue - bronzeAgeIndex) / (count * 2);
            index = -1;
        } else {
            spacing = 10;
            index = 0;
        }

        while (count > 0) {
            index += spacing;
            this->insert(MASTER_OBJECT_BOAT_TRANSPORT1, -1, index);
            --count;
        }

        if (!transportUpgrade && ironAgeIndex != -1) {
            this->insertResearch(TECH_HEAVY_TRANSPORT, ironAgeIndex + 2);
        }
    }

    if (warshipCount < this->md->tacticalAI.strategicNumber(0xE0) && this->md->tacticalAI.strategicNumber(0xDF) == 1
        && (ironAgeIndex != -1 || bronzeAgeIndex != -1)) {
        count = this->md->tacticalAI.strategicNumber(0xE0) - warshipCount;
        if (ironAgeIndex != -1) {
            spacing = ironAgeIndex / count;
        } else {
            spacing = bronzeAgeIndex / count;
        }

        index = spacing;
        //! @bug This block compares warshipCount with SN 0xE0, but each call passes research ID 19, Monotheism.
        //! insertResearch accepts only research 5, 7, and 8, so every call returns 0 and no item is inserted.
        while (count > 0) {
            this->insertResearch(TECH_MONOTHEISM, index);
            index += spacing;
            --count;
        }

        if (!warshipUpgrade && bronzeAgeIndex != -1) {
            this->insertResearch(TECH_MEDIUM_WAR_SHIP, bronzeAgeIndex + 5);
        }
        if (!triremeUpgrade && ironAgeIndex != -1) {
            //! @bug This anchor is the Iron Age entry's load-time index, but earlier inserts shift the list.
            //! Six or more splices then place Trireme before the Iron Age entry and break the dependency order.
            //! The same stale-anchor defect affects the Heavy Transport and Medium War Ship inserts above.
            this->insertResearch(TECH_TRIREME, ironAgeIndex + 5);
        }
    }

    if (houseCount == 0 && this->md->tacticalAI.strategicNumber(SNAutoBuilding) == 1) {
        item = this->buildList.next;
        int buildIndex = 0;
        int housingCapacity = 0;
        int trainedCount = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == BUILD_CATEGORY_BUILDING && item->typeID() == MASTER_OBJECT_TOWN_CENTER1) {
                housingCapacity += 4;
            }
            if (item->buildCategory() == BUILD_CATEGORY_UNIT) {
                ++trainedCount;
            }
            if (trainedCount > housingCapacity) {
                int insertIndex;
                if (buildIndex > 1) {
                    insertIndex = buildIndex - 1;
                } else {
                    insertIndex = 1;
                }
                if (this->insert(MASTER_OBJECT_HOUSE, -1, insertIndex) == 1) {
                    housingCapacity += 4;
                }
            }
            if (housingCapacity > this->md->tacticalAI.strategicNumber(SNHouseOverage) + 50) {
                break;
            }

            item = item->next;
            ++buildIndex;
        }
    }

    int totalPercentage = this->md->tacticalAI.strategicNumber(SNMaxBuildPlanGathererPercentage);
    int requiredPop = this->md->tacticalAI.strategicNumber(SNBuildPlanDivisions) + 4;
    if (totalPercentage != 0) {
        item = this->buildList.next;
        ResourceItem resourceCount(4);
        resourceCount.setAllValues(0);
        int itemCount = 0;
        int divisionSize = 0;

        while (item != sentinel && item != 0) {
            if (item->buildCategory() == BUILD_CATEGORY_GATHERER_PERCENTAGE) {
                item = item->next;
                ++itemCount;
            } else {
                if (item->buildCategory() == BUILD_CATEGORY_RESEARCH
                    || item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
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
                            this->insertGathererPercentage(
                                resource, resourceCount.value(resource) * totalPercentage / totalCost, divisionSize
                            );
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
            if (item->typeID() != this->md->tacticalAI.strategicNumber(SNUnskippableItemType)
                || item->buildCategory() != BUILD_CATEGORY_BUILDING) {
                item->setBuildAttempts(this->md->tacticalAI.strategicNumber(SNNumberBuildAttemptsBeforeSkip));
                item->setSkip(1);
                item->incrementSkipCycles();
                if (item->skipCycles() == this->md->tacticalAI.strategicNumber(SNNumberMaxSkipCycles)) {
                    item->setPermanentSkip(1);
                }
                return;
            }
        }

        item = item->next;
    }
}

BuildItem* TribeBuildAIModule::nextBuildableItem(int category) {
    int numStoragePits = this->numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_STORAGE_PIT1, BUILD_CATEGORY_BUILDING);
    int numGranaries = this->numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_GRANARY, BUILD_CATEGORY_BUILDING);
    int numHouses = this->numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_HOUSE, BUILD_CATEGORY_BUILDING);
    int count = 0;
    int realCount = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (this->md->tacticalAI.strategicNumber(SNMaxSkipsPerAttempt) < 0) {
        return 0;
    }

    do {
        if (item == sentinel || item == 0) {
            break;
        }

        if ((item->buildCategory() == BUILD_CATEGORY_RESEARCH
             || item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH)
            && this->isAgeResearch(item->typeID()) == 1) {
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
            int order = this->md->tacticalAI.strategicNumber(SNRequiredFirstBuilding);
            if (order == 1 && numGranaries == 0 && numStoragePits == 0) {
                canBuild = 0;
            }
            if (order == 2 && this->md->resourceAI.resource(RGE_RESOURCE_WOOD) < 250 && numStoragePits == 0) {
                canBuild = 0;
            }
            if (order == 3 && numGranaries == 0) {
                canBuild = 0;
            }
            if (order == 4 && (numGranaries == 0 || numStoragePits == 0)) {
                canBuild = 0;
            }

            if (category == BUILD_CATEGORY_BUILDING && !canBuild && item->buildCategory() == BUILD_CATEGORY_BUILDING
                && item->typeID() != MASTER_OBJECT_HOUSE && item->typeID() != MASTER_OBJECT_TOWN_CENTER1
                && item->typeID() != MASTER_OBJECT_STORAGE_PIT1 && item->typeID() != MASTER_OBJECT_GRANARY) {
                item = item->next;
                continue;
            }

            if (category == BUILD_CATEGORY_BUILDING && item->buildCategory() == BUILD_CATEGORY_BUILDING
                && (numGranaries == 0 || numStoragePits == 0) && numHouses >= this->md->tacticalAI.strategicNumber(0xAE)
                && item->typeID() != MASTER_OBJECT_TOWN_CENTER1 && item->typeID() != MASTER_OBJECT_STORAGE_PIT1
                && item->typeID() != MASTER_OBJECT_GRANARY) {
                item = item->next;
                continue;
            }

            if (item->buildCategory() == BUILD_CATEGORY_ENABLE_ATTACK && realCount == 0) {
                this->md->tacticalAI.enableAttack(1);
                item->setInProgress(0);
                item->setBuilt(1);
                item = item->next;
                continue;
            }

            if (item->buildCategory() == BUILD_CATEGORY_GATHERER_PERCENTAGE) {
                if (realCount < 1) {
                    this->md->tacticalAI.setStrategicNumber(item->typeID() + 0x9C, item->buildFrom());
                    item->setInProgress(0);
                    item->setBuilt(1);
                }
                item = item->next;
                continue;
            }

            if (category == BUILD_CATEGORY_LOAD_BUILD_LIST && realCount > 0) {
                return 0;
            }

            if (item->buildCap() != -1) {
                int buildCap = item->buildCap();
                if (item->numberBuilds() > buildCap) {
                    item = item->next;
                    continue;
                }
            }

            if (category == BUILD_CATEGORY_RESEARCH
                && (item->buildCategory() == BUILD_CATEGORY_RESEARCH
                    || item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH)
                && this->md->aiPlayer->researchEverAvailable(item->typeID()) == 0) {
                item->setInProgress(0);
                item->setBuilt(1);
                item = item->next;
                continue;
            }

            if (item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
                ResourceItem itemCost(4);
                this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
                if (!this->md->aiPlayer->researchAvailable(item->typeID())
                    || !this->md->resourceAI.resourcesAvailable(&itemCost) || category != BUILD_CATEGORY_RESEARCH) {
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
                if (item->buildCategory() == BUILD_CATEGORY_BUILDING
                    && (item->typeID() == MASTER_OBJECT_STORAGE_PIT1 || item->typeID() == MASTER_OBJECT_GRANARY)) {
                    item->setBuildAttempts(this->md->tacticalAI.strategicNumber(SNNumberBuildAttemptsBeforeSkip) - 1);
                }
            }

            if (this->md->player->attributes[PLAYER_ATTRIBUTE_POPULATION]
                    < this->md->player->attributes[PLAYER_ATTRIBUTE_POPULATION_LIMIT]
                || item->buildCategory() != BUILD_CATEGORY_UNIT) {
                ++realCount;
            }

            if (category == BUILD_CATEGORY_RESEARCH) {
                if (item->buildCategory() != BUILD_CATEGORY_RESEARCH
                    && item->buildCategory() != BUILD_CATEGORY_BLOCKING_RESEARCH) {
                    item = item->next;
                    continue;
                }
            } else if (item->buildCategory() != category) {
                item = item->next;
                continue;
            }

            if (category == BUILD_CATEGORY_LOAD_BUILD_LIST && item->buildCategory() != BUILD_CATEGORY_LOAD_BUILD_LIST) {
                item->setBuildAttempts(0);
                return 0;
            }

            item->incrementBuildAttempts();
            int buildAttempts = item->buildAttempts();
            if (buildAttempts > this->md->tacticalAI.strategicNumber(SNNumberBuildAttemptsBeforeSkip)
                && item->skip() == 0 && !item->permanentSkip()) {
                if (category == BUILD_CATEGORY_RESEARCH && item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
                    item->setBuildAttempts(0);
                    return 0;
                }

                if (item->typeID() != this->md->tacticalAI.strategicNumber(SNUnskippableItemType)
                    || item->buildCategory() != BUILD_CATEGORY_BUILDING) {
                    item->setSkip(1);
                    if (item->buildCategory() == BUILD_CATEGORY_BUILDING
                        && (item->typeID() == MASTER_OBJECT_STORAGE_PIT1 || item->typeID() == MASTER_OBJECT_GRANARY)) {
                        item->setBuildAttempts(
                            this->md->tacticalAI.strategicNumber(SNNumberBuildAttemptsBeforeSkip) * 6
                        );
                    } else {
                        item->setBuildAttempts(this->md->tacticalAI.strategicNumber(SNNumberBuildAttemptsBeforeSkip));
                    }
                    item = item->next;
                    continue;
                }
            }

            if (category == BUILD_CATEGORY_LOAD_BUILD_LIST && item->buildCategory() == BUILD_CATEGORY_LOAD_BUILD_LIST) {
                strncpy(this->currentBuildItemRequestedValue, item->name(), 63);
                this->numberItemsIntoBuildListValue = item->uniqueID();
                strncpy(this->nextBuildItemRequestedValue, item->next->name(), 63);
                this->numberItemsIntoBuildListValue = item->uniqueID();
                return item;
            }

            int available;
            if (category == BUILD_CATEGORY_RESEARCH) {
                available = this->md->aiPlayer->researchAvailable(item->typeID());
            } else {
                available = this->md->aiPlayer->objectAvailable(item->typeID());
            }
            if (available) {
                ResourceItem itemCost(4);
                if (category == BUILD_CATEGORY_RESEARCH) {
                    this->md->aiPlayer->researchCost(item->typeID(), -1, &itemCost, 1);
                } else {
                    this->md->aiPlayer->objectCost(item->typeID(), -1, &itemCost, 1);
                }

                if (this->md->resourceAI.resourcesAvailable(&itemCost)) {
                    int canBuildItem;
                    if (category == BUILD_CATEGORY_UNIT || category == BUILD_CATEGORY_RESEARCH) {
                        canBuildItem =
                            this->md->object(-1, item->buildFrom(), -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ACTIVE, -1)
                            != 0;
                    } else {
                        canBuildItem = this->md->constructionAI.canPlace(item);
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
    } while (realCount <= this->md->tacticalAI.strategicNumber(SNMaxSkipsPerAttempt));

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
    while (item != &list && item != 0
           && (item->built() || item->inProgress() || item->skip() == 1 || item->permanentSkip())) {
        item = item->next;
    }
    if (item == &list || item == 0) {
        return -1;
    }

    ResourceItem itemCost(4);
    if (item->buildCategory() == BUILD_CATEGORY_RESEARCH || item->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
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

            if (buildItem->built() == 0 && buildItem->inProgress() == 0
                && buildItem->buildCategory() != BUILD_CATEGORY_GATHERER_PERCENTAGE) {
                int cap = buildItem->buildCap();
                if (cap == -1 || buildItem->numberBuilds() <= buildItem->buildCap()) {
                    if (buildItem->buildCategory() == BUILD_CATEGORY_RESEARCH
                        || buildItem->buildCategory() == BUILD_CATEGORY_BLOCKING_RESEARCH) {
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
                        if (item->typeID() == MASTER_OBJECT_WONDER) {
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
    BuildItem* item = (BuildItem*) this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        if (item->typeID() == newItem->master_obj->id && item->built() == 0 && buildID != -1
            && item->uniqueID() == buildID) {
            item->setInProgress(found);
            found = 1;
            item->setBuilt(found);
            item->setGameID(newItem->id);
            item->incrementNumberBuilds();
            if (item->typeID() == MASTER_OBJECT_WONDER) {
                this->md->tacticalAI.wonderBuiltValue = found;
            }
            strncpy(this->lastBuildItemRequestedValue, item->name(), 63);
            this->numberItemsIntoBuildListValue = item->uniqueID();
        } else {
            item = (BuildItem*) item->next;
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
            if (item->typeID() == MASTER_OBJECT_WONDER) {
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

int TribeBuildAIModule::cancelBuildItem(
    int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID
) {
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
                this->md->tacticalAI.clearArea(
                    blockerID, lot->x() - lot->xSize() * 0.5f, lot->y() - lot->ySize() * 0.5f,
                    lot->x() - lot->xSize() * -0.5f, lot->y() - lot->ySize() * -0.5f
                );
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
        this->md->informationAI.removeLot(item->typeID(), (int) x, (int) y, newLotStatus);
        if (item->typeID() == MASTER_OBJECT_WONDER)
            this->md->tacticalAI.wonderInProgressValue = 0;
    }
    return 1;
}

int TribeBuildAIModule::addTrainedUnit(int uType, int location, int uniqueID, int gameID) {
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

int TribeBuildAIModule::cancelTrainUnit(int reason, int uType, int location, int uniqueID) {
    // md->player->world->world_time. This file does not include world.h; adding it changes
    // mostNeededResource (004D4F80), so the raw chain stays.
    int val = *(int*) (*(int*) (*(int*) ((char*) this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory(
        "Canceling training (WT=%ld) for item of type %d at building w/ gameID=%d.", val, uType, location
    );

    BuildItem* item = (BuildItem*) this->specificBuildListItem(uniqueID);

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

int TribeBuildAIModule::cancelResearch(int reason, int rType, int location, int uniqueID) {
    // md->player->world->world_time; see cancelTrainUnit.
    int val = *(int*) (*(int*) (*(int*) ((char*) this->md + 0xF0) + 0x3C) + 4);
    this->logCommonHistory("Canceling research (WT=%ld) for item of type %d, %d", val, rType, location);

    BuildItem* item = (BuildItem*) this->specificBuildListItem(uniqueID);

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
    if (rID == TECH_TOOL_AGE || rID == TECH_BRONZE_AGE || rID == TECH_IRON_AGE)
        return 1;
    return 0;
}

int TribeBuildAIModule::insert(int typeID, int buildCap, int insertionPoint) {
    int buildCategory;
    int buildFrom;

    switch (typeID) {
        case MASTER_OBJECT_SOLDIER_ARCHER1:
        case MASTER_OBJECT_SOLDIER_ARCHER2:
        case MASTER_OBJECT_SOLDIER_EL_ARCHER:
        case MASTER_OBJECT_SOLDIER_CAVALRY3_ARCH:
        case MASTER_OBJECT_SOLDIER_CHARIOT2:
            buildFrom = MASTER_OBJECT_RANGE1;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_SOLDIER_BALISTA:
        case MASTER_OBJECT_SOLDIER_CATAPULT1:
        case MASTER_OBJECT_SOLDIER_CATAPULT2:
            buildFrom = MASTER_OBJECT_SIEGE_WORKSHOP;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_MAN:
            buildFrom = MASTER_OBJECT_TOWN_CENTER1;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_SOLDIER_INF1:
        case MASTER_OBJECT_SOLDIER_INF3:
            buildFrom = MASTER_OBJECT_BARRACKS1;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_SOLDIER_PHAL1:
            buildFrom = MASTER_OBJECT_ACADEMY;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_PRIEST:
            buildFrom = MASTER_OBJECT_TEMPLE1;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_SOLDIER_CAVALRY1:
        case MASTER_OBJECT_SOLDIER_CHARIOT1:
        case MASTER_OBJECT_SOLDIER_ELEPHANT:
        case MASTER_OBJECT_SOLDIER_SCOUT:
            buildFrom = MASTER_OBJECT_STABLE;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_BOAT_FISHING1:
        case MASTER_OBJECT_BOAT_TRADE1:
        case MASTER_OBJECT_BOAT_TRANSPORT1:
        case MASTER_OBJECT_BOAT_TRANSPORT2:
        case MASTER_OBJECT_BOAT_WAR1:
        case MASTER_OBJECT_BOAT_WAR4:
            buildFrom = MASTER_OBJECT_DOCK_1;
            buildCategory = BUILD_CATEGORY_UNIT;
            break;
        case MASTER_OBJECT_DOCK_1:
        case MASTER_OBJECT_SIEGE_WORKSHOP:
        case MASTER_OBJECT_FARM:
        case MASTER_OBJECT_WATCH_TOWER:
        case MASTER_OBJECT_STORAGE_PIT1:
        case MASTER_OBJECT_SENTRY_TOWER:
        case MASTER_OBJECT_WONDER:
        case MASTER_OBJECT_GUARD_TOWER2:
        case MASTER_OBJECT_GRANARY:
        case MASTER_OBJECT_GUARD_TOWER:
        case MASTER_OBJECT_HOUSE:
            buildFrom = -1;
            buildCategory = BUILD_CATEGORY_BUILDING;
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

        return this->insertItem(this->md->player, typeID, 1, buildCategory, buildFrom, buildCap, count);
    }

    return this->insertItem(this->md->player, typeID, 1, buildCategory, buildFrom, buildCap, insertionPoint);
}

int TribeBuildAIModule::insertResearch(int typeID, int insertionPoint) {
    if (typeID != TECH_MEDIUM_WAR_SHIP && (typeID <= 6 || typeID > TECH_HEAVY_TRANSPORT)) {
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
        return this->insertItem(this->md->player, typeID, 1, BUILD_CATEGORY_RESEARCH, MASTER_OBJECT_DOCK_1, 1, count);
    }
    return this->insertItem(
        this->md->player, typeID, 1, BUILD_CATEGORY_RESEARCH, MASTER_OBJECT_DOCK_1, 1, insertionPoint
    );
}

int TribeBuildAIModule::insertGathererPercentage(int rType, int percentage, int insertionPoint) {
    return this->insertItem(
        this->md->player, rType, 1, BUILD_CATEGORY_GATHERER_PERCENTAGE, percentage, 1, insertionPoint
    );
}

int TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int type, int category) {
    int count;
    if (category == BUILD_CATEGORY_BUILDING && (type == MASTER_OBJECT_STORAGE_PIT1 || type == MASTER_OBJECT_GRANARY)) {
        count = this->numberInProgressItemsOfType(type, BUILD_CATEGORY_BUILDING);
        if (type == MASTER_OBJECT_STORAGE_PIT1) {
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
            if ((item->buildCategory() == second_category || item->buildCategory() == first_category) && !item->built()
                && !item->inProgress()) {
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
    int storage_pit_count =
        this->numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_STORAGE_PIT1, BUILD_CATEGORY_BUILDING);
    int granary_count = this->numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_GRANARY, BUILD_CATEGORY_BUILDING);

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    for (; item != sentinel && item != 0; item = item->next) {
        if (item->built() == 1)
            continue;
        if (item->inProgress() == 1)
            continue;
        if (storage_pit_count > 0 && item->typeID() == MASTER_OBJECT_STORAGE_PIT1)
            continue;
        if (granary_count > 0 && item->typeID() == MASTER_OBJECT_GRANARY)
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
