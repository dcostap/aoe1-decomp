// VA: 004151B0 UnitAIModule::bestUnitToAttack (2136B)
// aiuaimod.cpp
// PDB OWNER: ?bestUnitToAttack@UnitAIModule@@UAEHHHPAM@Z
// PDB MODULE: aiuaimod.cpp, lines 2014-2462; body 004151B0-00415A07.
// `UnitAIModule::update` is a separate owner at 00413AB0-0041400B.
#include "../../include/game_globals.h"
#include "../../include/rge_base_game_global.h"
#include "../../include/aiuaimod_context.h"
// Attempt log:
// - Reconstructed the visible-unit scan, current-target retention, and score
//   passes from the executable. The current source is not exact.
// - BINARY NOTE: slot +10C is called without pushes for range tests.
// - BINARY NOTE: three later slot +10C calls push four path arguments.
//   The source uses a narrow casted surface for those calls.
// - BINARY NOTE: the +3C counter uses dword inc, so it is an int.
// - BINARY NOTE: the final group value is sign-extended to an int.
// - BINARY NOTE: the threat gate uses test and jle, which proves <= 0.
// - BINARY NOTE: the second scan stores the selected ID and building flag
//   into separate locals.
// - Tested 21 distinct hypotheses. Calls now align 49/49 and the frame is
//   0x38, but strict drift remains 1748 bytes (81.8352%).
// - Main remaining leads are table-symbol ownership, local-home coloring,
//   and the final x87 score-compare form.
// - Acceptance blocker: during score division by target hit points, the
//   executable keeps the numerator in x87 extended precision across the
//   hit-point test and uses FXCH/FDIV. The rebuild spills the numerator to a
//   32-bit float home before division. Boundary scores can select a different
//   target. The rebuild still differs in the related x87 spill and branch
//   topology.
// - BINARY NOTE: the current-target distance score is divided only when the
//   float distance is positive. This restores the +15665 guard and its two
//   denominator paths; the second scan uses distance only for range filtering.
// - Canonical prefix through this owner emits the same bytes as its standalone
//   build. The authentic score and x87 context does not change this function.
//   PDB FPO proves the public virtual UAE owner.
// - PDB and the 49 ordered calls prove this owner is bestUnitToAttack, not update.
// - Inclusive outer bounds and the candidate hit-point local improved structure.
//   Other x87, local-reuse, and ABI probes were restored when they moved bytes
//   farther from the executable.

extern int DAT_0087d7c8[5];
extern VisibleUnitEntry* DAT_0087d7e0[5];

#define VPAD1(n) virtual int vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

// The shipped call sites use this same slot with four explicit path arguments.
// Keep that narrow ABI separate from the no-argument weapon-range getter.
class RGE_Static_Object_Path_Query {
public:
    virtual ~RGE_Static_Object_Path_Query();
    VPAD32(1)
    VPAD16(33)
    VPAD8(49)
    virtual int inAttackRange(RGE_Static_Object* object);
    VPAD8(58)
    virtual float damageCapability();
    virtual float weaponRange(int a, int b, int c, int d);
    virtual float minimumWeaponRange();
    VPAD32(69)
    virtual int canPath(int id, float range);
};

// This beta call site uses the same slot without the later mode parameter.
class RGE_Static_Object_Range_Query {
public:
    virtual ~RGE_Static_Object_Range_Query();
    VPAD32(1)
    VPAD16(33)
    VPAD8(49)
    virtual int inAttackRange(RGE_Static_Object* object);
    VPAD8(58)
    virtual float damageCapability();
    virtual float weaponRange();
};

#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1

int UnitAIModule::bestUnitToAttack(int param_1, int param_2, float* param_3)
{
    float numberMovingTargets;
    int numberDamagingUnits;
    int largestThreatIsBuilding;
    int currentTargetIsBuilding;
    int i;
    int j;
    RGE_Game_World* world;
    int difficulty;
    int maxReactDistance;
    int modifier;
    int numberNonCurrentTargets;
    int currentTargetIsWall;
    int numberObjectsInRange;
    int closestEnemyDistance;
    float enemyDistance;
    float distance;
    int currentTarget;

    this->search();
    difficulty = this->objectValue->owner->world->difficultyLevel();

    if (((rge_base_game->scenarioGame() == 1) &&
         (rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->id != 1)) ||
        ((rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->type == 3) &&
         ((this->objectValue->owner->strategicNumber(0xDB) != 100) ||
          (this->objectValue->owner->strategicNumber(0xDA) != 100)))) {
        if (this->objectValue->owner->id > 1) {
            if (difficulty == 3) {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDB);
            } else {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDA);
            }
        } else {
            maxReactDistance = difficulty == 3 ? 75 : 50;
        }
        modifier = (int)((float)maxReactDistance *
                         this->objectValue->master_obj->field_28 * DAT_0056ebc4);
        if (modifier < 1) {
            modifier = 1;
        }
    } else {
        modifier = ((int)this->objectValue->master_obj->field_28) * 2;
    }

    numberNonCurrentTargets = -1;
    world = this->objectValue->owner->world;
    numberMovingTargets = 0;
    currentTargetIsBuilding = 0;
    numberObjectsInRange = 0;

    if (this->currentTargetValue != -1) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0 && target->master_obj->object_group == 0x1B) {
            numberObjectsInRange = 1;
        }
    }

    numberDamagingUnits = 0;
    largestThreatIsBuilding = 0;
    currentTargetIsWall = 0;
    enemyDistance = 100000.0f;
    closestEnemyDistance = 0;
    currentTarget = -1;

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (DAT_0087d7c8[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(DAT_0087d7e0[i][j].object_id);
                if (target != 0 && target->object_state <= 2 &&
                    this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 &&
                    ((param_1 != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) &&
                    ((target->master_obj->object_group != 3 ||
                      target->hitPoints > 1.0f ||
                      (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) &&
                    this->canAttackUnit(target) != 0 &&
                    (i != 3 ||
                     this->canAttackUnitAtNeutrality(
                         target->master_obj->object_group) != 0)) {
                    distance = this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance &&
                        modifier >= DAT_0087d7e0[i][j].distance) {
                        if (target->id != this->currentTargetValue) {
                            ++currentTargetIsWall;
                        }
                        if (target->master_obj->object_group != 3) {
                            ++numberDamagingUnits;
                        }
                        if (target->damageCapability() > DAT_0056ebc8) {
                            ++largestThreatIsBuilding;
                        }
                        if (target->master_obj->object_group != 3) {
                            if (distance <
                                ((RGE_Static_Object_Range_Query*)this->objectValue)
                                    ->weaponRange() - DAT_0056ebd4) {
                                ++closestEnemyDistance;
                            }
                            if (distance < enemyDistance) {
                                currentTarget = target->id;
                                enemyDistance = distance;
                            }
                        }
                    }
                }
                ++j;
            } while (j < DAT_0087d7c8[i]);
        }
    }

    if (this->currentTargetValue != -1 && param_2 == 0 &&
        this->currentActionValue == 600) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0) {
            int x = (int)target->world_x;
            int y = (int)target->world_y;
            unsigned char visible = this->visibleStatus(
                this->objectValue->owner->visible, y, x);
            if (currentTargetIsWall != 0) {
                if (visible != 0x0F) {
                    goto skipCurrentTarget;
                }
                if (this->objectValue->inAttackRange(target) != 1 &&
                    this->objectValue->canPath(
                        this->currentTargetValue,
                        ((RGE_Static_Object_Path_Query*)this->objectValue)
                            ->weaponRange(0, 0, -1, -1)) != 1) {
                    goto skipCurrentTarget;
                }
            }
            target = world->object(this->currentTargetValue);
            if (target != 0 && target->object_state == 2 &&
                this->objectValue->owner->isAlly(target->owner->id) == 0) {
                if (target->master_obj->id == 0x114) {
                    return target->id;
                }
                numberNonCurrentTargets = this->currentTargetValue;
                numberMovingTargets = target->damageCapability() * DAT_0056ebd8;
                numberObjectsInRange =
                    target->master_obj->calc_base_damage_ability(
                        (RGE_Master_Combat_Object*)this->objectValue->master_obj);
                numberMovingTargets =
                    (float)numberObjectsInRange * DAT_0056ebc0 + numberMovingTargets;
                if (target->hitPoints > DAT_0056ebc8) {
                    numberMovingTargets /= target->hitPoints;
                }
                distance = target->distance_to_object(this->objectValue);
                if (distance > DAT_0056ebc8) {
                    if (numberDamagingUnits < 2) {
                        numberMovingTargets /= distance;
                    } else {
                        numberMovingTargets /=
                            (float)numberDamagingUnits * distance * DAT_0056ebdc;
                    }
                }
                if (target->master_obj->object_group != 3) {
                    ++numberDamagingUnits;
                    currentTargetIsBuilding = 0;
                } else {
                    currentTargetIsBuilding = 1;
                }
                if (target->damageCapability() > DAT_0056ebc8) {
                    ++largestThreatIsBuilding;
                }
            }
        }
    }

skipCurrentTarget:
    if (numberDamagingUnits > 1) {
        RGE_Static_Object* target = world->object(currentTarget);
        if (target != 0) {
            if (this->objectValue->inAttackRange(target) == 1) {
                return currentTarget;
            }
            if (this->objectValue->canPath(
                    currentTarget,
                    ((RGE_Static_Object_Path_Query*)this->objectValue)
                        ->weaponRange(0, 0, -1, -1)) == 1) {
                return currentTarget;
            }
        }
    }

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (DAT_0087d7c8[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(DAT_0087d7e0[i][j].object_id);
                if (target != 0 && target->object_state <= 2 &&
                    this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 &&
                    ((param_1 != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) &&
                    ((target->master_obj->object_group != 3 ||
                      target->hitPoints > 1.0f ||
                      (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) &&
                    this->canAttackUnit(target) != 0 &&
                    (i != 3 ||
                     this->canAttackUnitAtNeutrality(
                         target->master_obj->object_group) != 0)) {
                    float distance = this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance &&
                        modifier >= DAT_0087d7e0[i][j].distance &&
                        (param_2 != 1 || this->objectValue->inAttackRange(target) != 0)) {
                        if (param_2 == 0 && this->objectValue->inAttackRange(target) == 0 &&
                            this->objectValue->canPath(
                                DAT_0087d7e0[i][j].object_id,
                                ((RGE_Static_Object_Path_Query*)this->objectValue)
                                    ->weaponRange(0, 0, -1, -1)) == 0) {
                            goto skipTarget;
                        }
                        float threat = target->damageCapability() * DAT_0056ebd8;
                        if (largestThreatIsBuilding <= 0 || threat != DAT_0056ebc8) {
                            float score =
                                (float)target->master_obj->calc_base_damage_ability(
                                    (RGE_Master_Combat_Object*)this->objectValue->master_obj) * DAT_0056ebc0 +
                                threat;
                            float hitPoints = target->hitPoints;
                            if (hitPoints > DAT_0056ebc8) {
                                score /= hitPoints;
                            }
                            if (DAT_0087d7e0[i][j].distance != 0) {
                                score /= (float)DAT_0087d7e0[i][j].distance;
                            }
                            if (numberDamagingUnits > 1) {
                                int distanceValue =
                                    DAT_0087d7e0[i][j].distance;
                                score /= (float)(distanceValue * distanceValue *
                                                  distanceValue);
                            }
                            int group = target->master_obj->object_group;
                            if (numberNonCurrentTargets == -1 ||
                                ((currentTargetIsBuilding != 0 || group != 3) &&
                                 (numberNonCurrentTargets == -1 ||
                                  ((currentTargetIsBuilding == 1 && group != 3) ||
                                   (float)score >
                                       (float)numberMovingTargets)))) {
                                numberNonCurrentTargets =
                                    DAT_0087d7e0[i][j].object_id;
                                currentTargetIsBuilding = (group == 3);
                                numberMovingTargets = score;
                            }
                        }
                    }
                }

skipTarget:
                ++j;
            } while (j < DAT_0087d7c8[i]);
        }
    }

    return numberNonCurrentTargets;
}
