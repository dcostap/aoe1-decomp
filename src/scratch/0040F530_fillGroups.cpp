// 0040F530 AIPlay::fillGroups
// aipbook.cpp, lines 465-640
//
// Attempt log:
// - Prior candidate used AIPlay/AIPlayStatus method stubs with the wrong owners.
//   It emitted 18 calls instead of the original 22 and was 122 bytes short.
// - Baseline: restore the call surface shown by the original assembly and the
//   same-TU donors: AIPlayBook::convertUnitToIntType, AIPlay::group,
//   AIPlayGroup::minimum/maximum, and AIPlayStatus grouping methods.
// - Rebuilt the first group scan as a while loop; this removed one duplicated
//   group call and aligned all 22 direct/virtual call sites.
// - Made minimum and deviation arithmetic int locals; this restored the 0x4F8
//   frame and the original zero-extension around AIPlayGroup::minimum.
// - Tested inline capacity predicates. They improved local block shape but
//   added four frame bytes and two bytes past the original boundary, so they
//   were rolled back.
// - Final validated state: 1112 rebuilt bytes, 0x4F8 frame, 22/22 calls, and
//   849 positional diff bytes. Remaining drift starts at the play local home
//   ([esp+10] versus original [esp+14]) and includes bucket index shape and
//   late register allocation. Source keeps named period-plausible ownership.
// - Store each accepted unit before incrementing its type count. This natural
//   order matches the original memory effects and improved the diff to 834.

class RGE_Static_Object {};

class AIPlayGroup {
public:
    unsigned char minimumValues[6];
    unsigned char maximumValues[6];

    unsigned char minimum(int index);
    unsigned char maximum(int index) const;
};

class AIPlay;

class AIPlayBook {
public:
    virtual ~AIPlayBook();
    virtual int convertTargetNameToIntType(char*) const;
    virtual int convertTargetCharacteristicNameToIntType(char*) const;
    virtual int convertUnitNameToIntType(char*) const;
    virtual int convertUnitToIntType(RGE_Static_Object*) const;

    AIPlay* play(int index);
};

class RGE_Game_World {
public:
    char gap_00[0xA0];
    AIPlayBook* playbook;

    RGE_Static_Object* object(int index);
};

class AIPlay {
public:
    char gap_00[0x41];
    unsigned char minimumNumberUnitsValue;
    unsigned char maximumNumberUnitsValue;
    unsigned char typeValue;
    unsigned char targetTypeValue[5];
    unsigned char targetCharacteristicValue[5];
    unsigned char powerValue;
    unsigned char overflowValue;
    unsigned char intelligenceValue;
    unsigned char deathPercentageValue;
    unsigned char numberGroupsValue;
    AIPlayGroup* group(int index);

    int fillGroups(class AIPlayStatus* status, int* units, int unitCount,
                   RGE_Game_World* world);
};

class AIPlayStatus {
public:
    char gap_00[0x190];
    int playNumberValue;
    char gap_194[0x30];
    unsigned char deviationValue;

    int addGrouping(int id, unsigned char groupID, unsigned char type);
    unsigned char numberInPlay();
    unsigned char numberInGroup(int groupID);
    unsigned char numberOfTypeInGroup(int groupID, int type);
};

int AIPlay::fillGroups(AIPlayStatus* status, int* units, int unitCount,
                       RGE_Game_World* world) {
    int unitsByTypeCount[6];
    int unitsByType[6][50];
    int minUnits;
    int groupIndex;
    int i;
    int type;
    int count;
    int j;
    int assigned;
    int bestGroup;
    int smallestGroupSize;
    int deviation;
    int minimum;
    unsigned char inType;
    unsigned char maximum;
    AIPlay* play;
    AIPlayGroup* group;
    int* unit;
    RGE_Static_Object* object;

    play = world->playbook->play(status->playNumberValue);

    if (play == 0) {
        return 0;
    }

    minUnits = 1;
    for (i = 0; i < 6; i++) {
        unitsByTypeCount[i] = 0;
    }

    if (unitCount > 0) {
        for (i = 0; i < unitCount; i++) {
            object = world->object(units[i]);
            if (object == 0) {
                minUnits = 0;
            } else {
                type = world->playbook->convertUnitToIntType(object);
                if (type < 0 || type >= 6) {
                    minUnits = 0;
                } else {
                    count = unitsByTypeCount[type];
                    unitsByType[type][count] = units[i];
                    unitsByTypeCount[type] = count + 1;
                }
            }
        }
    }

    groupIndex = 0;
    while (groupIndex < play->numberGroupsValue) {
        group = play->group(groupIndex);
        if (group == 0) {
            return 0;
        }

        for (type = 0; type < 6; type++) {
            minimum = group->minimum(type);
            if (minimum != 0) {
                assigned = 0;
                count = unitsByTypeCount[type];
                for (j = 0; j < count && assigned < minimum; j++) {
                    unit = &unitsByType[type][j];
                    if (*unit != -1) {
                        if (status->addGrouping(*unit,
                                                (unsigned char)groupIndex,
                                                (unsigned char)type) == 1) {
                            assigned++;
                            *unit = -1;
                            if (status->numberInPlay() ==
                                play->maximumNumberUnitsValue) {
                                goto CountDeviation;
                            }
                        } else {
                            minUnits = 0;
                        }
                    }
                }
            }
        }
        groupIndex++;
    }

    for (type = 0; type < 6; type++) {
        count = unitsByTypeCount[type];
        for (j = 0; j < count; j++) {
            unit = &unitsByType[type][j];
            if (*unit == -1) {
                continue;
            }

            if (this->overflowValue == 1) {
                bestGroup = -1;
                smallestGroupSize = 0;

                for (groupIndex = 0;
                     groupIndex < play->numberGroupsValue; groupIndex++) {
                    group = play->group(groupIndex);
                    if (group != 0) {
                        inType =
                            status->numberOfTypeInGroup(groupIndex, type);
                        maximum = group->maximum(type);
                        if (inType < maximum &&
                            (bestGroup == -1 ||
                             status->numberInGroup(groupIndex) <
                                 smallestGroupSize)) {
                            smallestGroupSize =
                                status->numberInGroup(groupIndex);
                            bestGroup = groupIndex;
                        }
                    }
                }

                if (bestGroup != -1) {
                    if (status->addGrouping(*unit,
                                            (unsigned char)bestGroup,
                                            (unsigned char)type) == 1) {
                        *unit = -1;
                        if (status->numberInPlay() ==
                            play->maximumNumberUnitsValue) {
                            goto CountDeviation;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (this->overflowValue == 2) {
                for (groupIndex = 0;
                     groupIndex < play->numberGroupsValue; groupIndex++) {
                    group = play->group(groupIndex);
                    if (group != 0) {
                        inType =
                            status->numberOfTypeInGroup(groupIndex, type);
                        maximum = group->maximum(type);
                        if (inType < maximum) {
                            if (status->addGrouping(
                                    *unit, (unsigned char)groupIndex,
                                    (unsigned char)type) == 1) {
                                *unit = -1;
                                if (status->numberInPlay() ==
                                    play->maximumNumberUnitsValue) {
                                    goto CountDeviation;
                                }
                                break;
                            } else {
                                minUnits = 0;
                            }
                        }
                    }
                }
            }
        }
    }

CountDeviation:
    deviation = 0;
    for (i = 0; i < play->numberGroupsValue; i++) {
        group = play->group(i);
        if (group != 0) {
            for (j = 0; j < 6; j++) {
                minimum = group->minimum(j);
                inType =
                    status->numberOfTypeInGroup(i, j);
                if (inType < minimum) {
                    deviation += minimum - inType;
                }
            }
        }
    }

    status->deviationValue = (unsigned char)deviation;
    return minUnits;
}
