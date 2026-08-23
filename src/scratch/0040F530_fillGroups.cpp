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
// - Tested explicit row cursors for the minimum-assignment loop. They made the
//   structural output worse (882-byte diff, 52.60% shape), so they were rolled back.
// - Named the surviving bucket unit ID before the overflow-mode calls. This
//   preserves the original spilled candidate value and improved the diff to 833.
// - Reordered that local and used a play declaration initializer. Both emitted
//   the same 833-byte result; the simple named-local form remains.
// - Removed the first minimum-scan unit pointer temporary and used the typed
//   bucket element directly. VC5 emitted the same 1112-byte code, so it was
//   rolled back; this access spelling is compiler-neutral in the current TU.
// - BINARY NOTE: 21 additional source probes kept the typed ABI and 22-call
//   surface but did not move the first play-home mismatch or reach exactness.
// - BINARY NOTE: direct maximum-left predicates improved block shape only when
//   combined with a final-loop rewrite; they added a call or a 0x4FC frame.
// - BINARY NOTE: a final-scan group local improved the diagnostic diff to 832
//   bytes and 72.33% shape, but moved the early this home and was rolled back.
// - BINARY NOTE: caching maximumNumberUnitsValue before numberInPlay added a
//   0x4FC frame. The original loads this byte before the call without a home.
// - Exact-finish probes: loop-scoped indices and scoped object storage emitted
//   the same 803-byte result. The full context header emitted 831 bytes.
//   Moving to typed unit cursors emitted 876 bytes. Scoped assignment state
//   emitted 804 bytes. Cached maximum bytes emitted 904 bytes. All were
//   restored.
// - BINARY NOTE: the restored source emits 365 instructions, 1157 bytes, a
//   0x4FC frame, and all 22 calls in the original order. The original emits
//   365 instructions, 1150 bytes, and a 0x4F8 frame. Drift starts at +0002.
// - BINARY NOTE: the local class declarations are guarded for the reviewed
//   aipbook_tu.cpp context. Standalone checking keeps the same ABI surface.
// - LIKELY INTENT: the remaining drift is source lifetime and register color,
//   not ownership or direct-call ABI. The clean baseline remains authoritative.

#ifndef AIPBOOK_CANONICAL_TU
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
#endif

int AIPlay::fillGroups(AIPlayStatus* playStatus, int* groupMembers,
                       int numberGroupMembers, RGE_Game_World* world) {
    AIPlay* play;
    int deviation;
    int i;
    int rVal;
    int unitsByTypeCount[6];
    int unitsByType[6][50];
    int j;
    AIPlayGroup* group;
    int minUnits;
    int numAssigned;
    int a;
    int smallestGroupSize;
    int k;
    RGE_Static_Object* object;

    play = world->playbook->play(playStatus->playNumberValue);

    if (play == 0) {
        return 0;
    }

    minUnits = 1;
    for (i = 0; i < 6; i++) {
        unitsByTypeCount[i] = 0;
    }

    if (numberGroupMembers > 0) {
        for (i = 0; i < numberGroupMembers; i++) {
            object = world->object(groupMembers[i]);
            if (object == 0) {
                minUnits = 0;
            } else {
                a = world->playbook->convertUnitToIntType(object);
                if (a < 0 || a >= 6) {
                    minUnits = 0;
                } else {
                    j = unitsByTypeCount[a];
                    unitsByType[a][j] = groupMembers[i];
                    unitsByTypeCount[a] = j + 1;
                }
            }
        }
    }

    i = 0;
    while (i < play->numberGroupsValue) {
        group = play->group(i);
        if (group == 0) {
            return 0;
        }

        j = 0;
        rVal = 0;
        do {
            a = group->minimum(j);
            if (a != 0) {
                numAssigned = 0;
                smallestGroupSize = unitsByTypeCount[j];
                for (k = 0; k < smallestGroupSize && numAssigned < a; k++) {
                    if (unitsByType[j][k] != -1) {
                        if (playStatus->addGrouping(
                                unitsByType[j][k], (unsigned char)i,
                                (unsigned char)j) == 1) {
                            numAssigned++;
                            unitsByType[j][k] = -1;
                            if (playStatus->numberInPlay() ==
                                play->maximumNumberUnitsValue) {
                                goto CountDeviation;
                            }
                        } else {
                            minUnits = 0;
                        }
                    }
                }
            }
            rVal += 50;
            j++;
        } while (rVal < 300);
        i++;
    }

    i = 0;
    rVal = 0;
    do {
        a = unitsByTypeCount[i];
        for (k = 0; k < a; k++) {
            if (unitsByType[i][k] == -1) {
                continue;
            }

            if (this->overflowValue == 1) {
                numAssigned = -1;
                smallestGroupSize = 0;

                for (j = 0; j < play->numberGroupsValue; j++) {
                    group = play->group(j);
                    if (group != 0) {
                        if (playStatus->numberOfTypeInGroup(j, i) <
                                group->maximum(i) &&
                            (numAssigned == -1 ||
                             playStatus->numberInGroup(j) <
                                 smallestGroupSize)) {
                            smallestGroupSize = playStatus->numberInGroup(j);
                            numAssigned = j;
                        }
                    }
                }

                if (numAssigned != -1) {
                    if (playStatus->addGrouping(
                            unitsByType[i][k], (unsigned char)numAssigned,
                            (unsigned char)i) == 1) {
                        unitsByType[i][k] = -1;
                        if (playStatus->numberInPlay() ==
                            play->maximumNumberUnitsValue) {
                            goto CountDeviation;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (this->overflowValue == 2) {
                for (j = 0; j < play->numberGroupsValue; j++) {
                    group = play->group(j);
                    if (group != 0) {
                        if (playStatus->numberOfTypeInGroup(j, i) <
                                group->maximum(i)) {
                            if (playStatus->addGrouping(
                                    unitsByType[i][k], (unsigned char)j,
                                    (unsigned char)i) == 1) {
                                unitsByType[i][k] = -1;
                                if (playStatus->numberInPlay() ==
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
        i++;
        rVal += 200;
    } while (i < 6);

CountDeviation:
    deviation = 0;
    i = 0;
    while (i < play->numberGroupsValue) {
        group = play->group(i);
        if (group != 0) {
            for (j = 0; j < 6; j++) {
                a = group->minimum(j);
                rVal = playStatus->numberOfTypeInGroup(i, j);
                if (rVal < a) {
                    deviation += a - rVal;
                }
            }
        }
        i++;
    }

    playStatus->deviationValue = (unsigned char)deviation;
    return minUnits;
}
