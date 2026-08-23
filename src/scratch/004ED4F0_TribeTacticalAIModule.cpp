// 004ED4F0 TribeTacticalAIModule::TribeTacticalAIModule(int,int)
// Source: taitacmd.cpp lines 1803-2027
// Ghidra-body compileable baseline. Not exact yet; intended as a fuller journey
// starting point than a hand-summarized skeleton.
// Attempt log:
// - 2026-05-04: replaced the earlier partial skeleton with the full Ghidra
//   approximated body (lines 1803-2027), adjusted just enough to compile as C++:
//   EH scaffolding removed, base/member ctors expressed via initializer list,
//   vtable store uses *(int*)this = 0x575788, and groups.next/prev modeled.
// - FLAGS: /GX retained for original EH-framed constructor
//   (config/flags/004ED4F0_TribeTacticalAIModule.rsp).
// - 2026-05-04 continued: original constructs groups/neededResources inside
//   the body after many stores, not in initializer-list order.  Switched those
//   members to raw storage and call their constructors manually in-body.
// - Stack-frame note: packet uses a 0x24 byte local area.  The Ghidra locals only
//   induced 0x20; a volatile padding local did not change VC5's allocation, so
//   this remains tied to the missing EH registration/state slot.
// - Switched the TacticalAIModule base to raw storage plus an explicit in-body
//   constructor call.  This better matches the original's source order (save this
//   in ESI, push file/player args, then call base ctor) and avoids C++'s forced
//   base-initializer scheduling.
// - Tried wrapping the body in __try/__finally to force FS:[0] setup.  It did
//   produce an EH-looking prologue, but with an EBP frame and much worse edit diff
//   (~103%), so rolled back.  A declared-but-undefined FakeDtor guard also did
//   not produce the original C++ EH registration sequence and slightly worsened
//   diff, so it is removed.  The dead `eh_state` local from Ghidra likewise had
//   no benefit after removing the guard, so it is gone.  The first 0x100 bytes are mostly aligned after
//   ignoring the missing 21-byte EH prefix; a local issue remains that VC5 hoists
//   ResourceItem's `push 4` before the final +0xD50..+0xD64 zero stores.
// - Marked ManagedIntArray::value volatile: this prevents VC5 from turning the
//   duplicate-scan loop into a single incrementing pointer walk.  The rebuilt
//   loop now reloads the array base for indexed comparisons, much closer to the
//   original `[base+eax*4]` family.  Marking numberValue and desiredNumberValue
//   volatile too (but not maximumSizeValue) improves the repeated list loader
//   substantially; current best is ~85.19% positional / ~60.77% edit.
// - Flag probes /O2 /GX, /O2 /Oy- /GX, /O1 /Oy /GX, and /O1 /GX produced the
//   same metrics; this is source/type/EH-context work, not a simple flag issue.
// - Rewriting equivalent bounds checks with the induction variable on the left
//   (`i >= max`, `i >= newMax`) is a small edit-diff win for all inlined list
//   loaders.
// - Comparing against the saved temp local (`local_28`) instead of the raw read
//   buffer (`local_2c`) is a larger win and better expresses the original's
//   store-to-local after each read.  Removing the no-op FakeDtor guard gave a
//   good baseline (~84.79% positional / ~57.98% edit).
// - Variant not kept: modeling full virtual inheritance/interface like smaller
//   matched AI ctors improves edit diff (~56.44%) but emits an early automatic
//   vptr store/zero after the base ctor and still no EH prefix; it contradicts
//   the packet where the TribeTacticalAIModule vptr is written much later at
//   004ED741.  Raw class + manual vptr remains the better positional baseline.
// - Variant not kept: making groups/neededResources real typed members with
//   destructors improved edit diff to ~66.93%, but forced their constructors to
//   run before the base ctor and before all zeroing, contradicting original order.
//   Keep raw storage as the behavioral/scheduling baseline unless a TU-context
//   trick can recover EH without auto-member construction.
// - Fixed one Ghidra-local artifact in the compileable body: old gatherer reads
//   now use tempUD.data4/data5 instead of uninitialized stack aliases. Duplicate
//   checks use the raw read buffer (`local_2c`) as in Ghidra/original asm; using
//   the saved add temp/local id instead produced the same current metrics.
//   Current validation after layout/FPU/list-predicate fixes: compiles cleanly,
//   84.95% positional / 55.95% edit.
// - Probe not kept: removing volatile from numberValue/desiredNumberValue worsened
//   the loader family (edit diff ~58.98%), so the earlier volatile surface stays.
// - Probe not kept: an explicit volatile `eh_state` local with byte writes at
//   the Ghidra EH-state transitions worsened edit diff (~58.84%) and still did
//   not recover the real FS:[0] registration prefix; rolled back.
// - Probe not kept: making maximumSizeValue volatile only slightly helped
//   positional diff but badly worsened edit diff (~68.91%), so max stays plain.
// - Corrected PlacementState/AttackState active offsets from type dumps and
//   changed the legacy-version clearing loops to raw dword zeroing.  This fixes
//   real field offsets (+0xF60/+0xFD4) and improves edit diff to ~56.54%.
// - Version gates use float literals for original dword FPU constants.  For
//   `constant <= save_game_version` gates, spelling as `!(save_game_version < C)`
//   preserves the original `test ah,1` branch family; direct `C <= save` emitted
//   `test ah,41h` and worsened the diff.  The 6.2/7.04 old-layout gates also
//   need the negated form to keep the read block before the zero-fill block.
// - Rewriting ManagedArray grow checks as `count > max - 1` instead of
//   `max + -1 < count` preserves the original jle-skip compare family and trims
//   edit diff slightly.
// - Natural-lifetime probe: made TacticalAIModule, TacticalAIGroup, and
//   ResourceItem typed bases/members, and moved their construction to the
//   initializer list. Removed the manual derived-vptr store. This is retained
//   as the one constructor-order test for the current session.
// - Kept the typed TacticalAIModule base but restored raw placement storage for
//   group/resource objects. This retained compiler EH setup, removed automatic
//   lifetime reordering, and improved the structural diff to 5325 bytes.
// - A novtable derived-class context removed the compiler's early vptr store,
//   but moved the first mismatch and worsened the structural diff. Rolled back.
// - Tested moving lastGroupRebalanceTime initialization after the explicit
//   Group constructor; it worsened the diff by 5 bytes and was rolled back.
// - Declaring the proven derived virtual destructor preserved the clean metrics
//   and improved one local alignment, but did not change the structural basin.
// - Removing the decompiler tempUD self-assignment shortened the function but
//   worsened the structural diff; restored the prior source.
// - 2026-08-17 claim pass: ran 22 distinct source, ABI, liveness, control-flow,
//   and flag probes. No probe reached exactness. The clean baseline remains
//   5325 differing bytes (90.9945%), 84.93% shape, 0x24 frame, and 104/104
//   ordered calls. The main blocker is the derived vptr store at +0x2F and the
//   missing original EH-state store at [esp+0x3C].
// - Evidence: __declspec(novtable), flattened placement construction, alternate
//   loop forms, scalar/pointer volatility axes, unsuffixed/direct version gates,
//   and /O1, /Oy- flag variants all remained nonexact. Restore the clean source
//   before further work. Next lead: recover VC5's original constructor EH state
//   and delayed derived-vptr scheduling without manual assembly.
// - 2026-08-22 claim pass: modeled ManagedIntArray as a natural zeroing,
//   delete-and-zero member; modeled groups and neededResources as their proven
//   inline objects. Declaration-order construction improved the clean diff from
//   5325 to 5186 bytes and moved the first mismatch from the prologue to the
//   late inline-object/vptr transition. The retained fields are nonvolatile;
//   volatile probes were metric-only and were removed.

#include "..\..\include\game_globals.h"

extern "C" int __cdecl rge_read(int file, void* dst, int size);
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);
extern float save_game_version;
#ifndef TAITACMD_SHARED_CONTEXT
class TribeMainDecisionAIModule;

class TacticalAIModule { public: virtual ~TacticalAIModule(); char base[0xEC]; TacticalAIModule(void* owner, int player); };
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedIntArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedIntArray() {
        if (this->value != 0) {
            operator_delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};
struct UnitData { int id; int data1; int data2; int data3; int data4; int data5; };
struct OldUnitData { int data1; int data2; int data3; int data4; int data5; };
class TacticalAIGroup { public: virtual ~TacticalAIGroup(); TacticalAIGroup* next; TacticalAIGroup* prev; char bytes[0x324]; TacticalAIGroup(); static void load(TacticalAIGroup* self, int file); };
class ResourceItem { public: virtual ~ResourceItem(); char bytes[0x6C]; ResourceItem(int count); static void setValue(ResourceItem* self, int index, int value); };
TacticalAIGroup* createGroup(void* self, int arg);
struct PlacementState { char pad_000[0x114]; int active; char pad_118[0x18]; };
struct AttackState { char pad_00[0x28]; int active; };

class TribeTacticalAIModule : public TacticalAIModule {
public:
    void* md; ManagedIntArray civilians; ManagedIntArray civilianExplorers; ManagedIntArray soldiers; ManagedIntArray ungroupedSoldiers;
    ManagedIntArray boats; ManagedIntArray warBoats; ManagedIntArray fishingBoats; ManagedIntArray tradeBoats; ManagedIntArray transportBoats; ManagedIntArray artifacts;
    int sn[226]; UnitData gatherers[50]; int numberGatherersValue; int desiredNumberGatherersValue; TacticalAIGroup groups;
    int groupIDValue; int numberGroupsValue; unsigned long lastGroupAttackTime; unsigned long lastGroupRebalanceTime; unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime; unsigned long lastScalingUpdateValue; int numberBuildUpdatesSkipped; int randomizedAttackSeparationTime;
    ManagedIntArray playersToAttack; ManagedIntArray playersToDefend; ManagedIntArray workingArea; ManagedIntArray unitsTaskedThisUpdate;
    int actualGathererDistribution[4]; int desiredGathererDistribution[4]; int neededResourceValue[4]; int resourceDifferenceValue[4]; ResourceItem neededResources;
    int attackEnabledValue; int updateArea; int firstNeededResourceUpdateDone; int numberStoragePitsBuilt[4]; int numberGranariesBuilt[4]; int wonderInProgressValue; int wonderBuiltValue;
    PlacementState placementStateValue; int nextCivilianToTaskValue; int nextIdleSoldierGroupToTaskValue; int nextActiveSoldierGroupToTaskValue; int builtFirstStoragePit; int builtFirstGranary;
    unsigned long lastBuildTime; unsigned long lastAttackResponseBuildInsertionTime; unsigned long lastCoopTributeDemandTime; unsigned long lastCoopTributeGiftTime; unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge; unsigned long lastUngroupedSoldierTaskTime; AttackState attackStateValue; int hitsByPlayer[9]; int lastUpdateAreaTimeValue; int averageUpdateAreaTimeValue; int updateAreaAverageCount; int updateAreaAverageTotal;
    virtual ~TribeTacticalAIModule();
    TribeTacticalAIModule(int param_1, int param_2);
};
#endif

TribeTacticalAIModule::TribeTacticalAIModule(int param_1, int param_2)
    : TacticalAIModule(0, param_1),
      md(0),
      civilians(),
      civilianExplorers(),
      soldiers(),
      ungroupedSoldiers(),
      boats(),
      warBoats(),
      fishingBoats(),
      tradeBoats(),
      transportBoats(),
      artifacts(),
      lastGroupRebalanceTime(0),
      playersToAttack(),
      playersToDefend(),
      workingArea(),
      unitsTaskedThisUpdate(),
      neededResources(4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  TacticalAIGroup *pTVar5;
  int iVar6;
  int i;
  int tempInt;
  int file;
  int local_2c;
  int local_28;
  OldUnitData tempUD;

  tempUD.data1 = (int)this;
  TacticalAIGroup *group = &this->groups;
  this->groups.next = group;
  this->groups.prev = group;
  this->attackEnabledValue = 0;
  this->updateArea = 0;
  this->firstNeededResourceUpdateDone = 0;
  this->wonderInProgressValue = 0;
  this->wonderBuiltValue = 0;
  this->nextCivilianToTaskValue = -1;
  this->nextIdleSoldierGroupToTaskValue = -1;
  this->nextActiveSoldierGroupToTaskValue = -1;
  this->builtFirstStoragePit = 0;
  this->builtFirstGranary = 0;
  this->lastBuildTime = 0;
  this->lastAttackResponseBuildInsertionTime = 0;
  this->lastCoopTributeDemandTime = 0;
  this->lastCoopTributeGiftTime = 0;
  this->lastCoopAttackDemandTime = 0;
  this->zoomingToNextAge = 0;
  this->lastUngroupedSoldierTaskTime = 0;
  this->lastUpdateAreaTimeValue = -1;
  this->averageUpdateAreaTimeValue = -1;
  this->updateAreaAverageCount = 0;
  this->updateAreaAverageTotal = 0;
  file = param_2;
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->civilians).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->civilians).maximumSizeValue) break;
          if ((this->civilians).value[iVar1] == local_2c) goto LAB_004ed829;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->civilians).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilians).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar2;
          (this->civilians).maximumSizeValue = iVar6;
        }
      }
      (this->civilians).value[(this->civilians).numberValue] = local_28;
      (this->civilians).numberValue = (this->civilians).numberValue + 1;
LAB_004ed829:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->civilianExplorers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->civilianExplorers).maximumSizeValue) break;
          if ((this->civilianExplorers).value[iVar1] == local_2c) goto LAB_004ed92c;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->civilianExplorers).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilianExplorers).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilianExplorers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilianExplorers).maximumSizeValue);
          }
          operator_delete((this->civilianExplorers).value);
          (this->civilianExplorers).value = piVar2;
          (this->civilianExplorers).maximumSizeValue = iVar6;
        }
      }
      (this->civilianExplorers).value[(this->civilianExplorers).numberValue] = local_28;
      (this->civilianExplorers).numberValue = (this->civilianExplorers).numberValue + 1;
LAB_004ed92c:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(file,&this->numberGatherersValue,4);
  rge_read(file,&this->desiredNumberGatherersValue,4);
  if (save_game_version < 7.19f) {
    piVar2 = &this->gatherers[0].data1;
    iVar6 = 0x32;
    if (save_game_version < 7.17f) {
      do {
        rge_read(file,&tempUD.data1,0x10);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = tempUD.data4;
        piVar2[3] = -1;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      do {
        rge_read(file,&tempUD.data1,0x14);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = tempUD.data4;
        piVar2[3] = tempUD.data5;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
                    /* language.dll match for 0x4b0: "Ready" */
    rge_read(file,this->gatherers,0x4b0);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->soldiers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->soldiers).maximumSizeValue) break;
          if ((this->soldiers).value[iVar1] == local_2c) goto LAB_004edb26;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->soldiers).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->soldiers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar2;
          (this->soldiers).maximumSizeValue = iVar6;
        }
      }
      (this->soldiers).value[(this->soldiers).numberValue] = local_28;
      (this->soldiers).numberValue = (this->soldiers).numberValue + 1;
LAB_004edb26:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (!(save_game_version < 2.3f)) {
    rge_read(file,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(file,&local_2c,4);
        iVar6 = (this->ungroupedSoldiers).numberValue;
        iVar1 = 0;
        local_28 = local_2c;
        if (0 < iVar6) {
          do {
            if (iVar1 >= (this->ungroupedSoldiers).maximumSizeValue) break;
            if ((this->ungroupedSoldiers).value[iVar1] == local_2c) goto LAB_004edc44;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar6);
        }
        if (iVar6 > (this->ungroupedSoldiers).maximumSizeValue - 1) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar1 = 0;
            if (0 < (this->ungroupedSoldiers).maximumSizeValue) {
              do {
                if (iVar1 >= iVar6) break;
                iVar3 = iVar1 + 1;
                piVar2[iVar1] = (this->ungroupedSoldiers).value[iVar1];
                iVar1 = iVar3;
              } while (iVar3 < (this->ungroupedSoldiers).maximumSizeValue);
            }
            operator_delete((this->ungroupedSoldiers).value);
            (this->ungroupedSoldiers).value = piVar2;
            (this->ungroupedSoldiers).maximumSizeValue = iVar6;
          }
        }
        (this->ungroupedSoldiers).value[(this->ungroupedSoldiers).numberValue] = local_28;
        (this->ungroupedSoldiers).numberValue = (this->ungroupedSoldiers).numberValue + 1;
LAB_004edc44:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->boats).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->boats).maximumSizeValue) break;
          if ((this->boats).value[iVar1] == local_2c) goto LAB_004edd4b;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->boats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->boats).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->boats).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->boats).maximumSizeValue);
          }
          operator_delete((this->boats).value);
          (this->boats).value = piVar2;
          (this->boats).maximumSizeValue = iVar6;
        }
      }
      (this->boats).value[(this->boats).numberValue] = local_28;
      (this->boats).numberValue = (this->boats).numberValue + 1;
LAB_004edd4b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->warBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->warBoats).maximumSizeValue) break;
          if ((this->warBoats).value[iVar3] == local_2c) goto LAB_004ede4c;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->warBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->warBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->warBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->warBoats).maximumSizeValue);
          }
          operator_delete((this->warBoats).value);
          (this->warBoats).value = piVar2;
          (this->warBoats).maximumSizeValue = iVar6;
        }
      }
      (this->warBoats).value[(this->warBoats).numberValue] = iVar1;
      (this->warBoats).numberValue = (this->warBoats).numberValue + 1;
LAB_004ede4c:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->fishingBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->fishingBoats).maximumSizeValue) break;
          if ((this->fishingBoats).value[iVar3] == local_2c) goto LAB_004edf51;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->fishingBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->fishingBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->fishingBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->fishingBoats).maximumSizeValue);
          }
          operator_delete((this->fishingBoats).value);
          (this->fishingBoats).value = piVar2;
          (this->fishingBoats).maximumSizeValue = iVar6;
        }
      }
      (this->fishingBoats).value[(this->fishingBoats).numberValue] = iVar1;
      (this->fishingBoats).numberValue = (this->fishingBoats).numberValue + 1;
LAB_004edf51:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->tradeBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->tradeBoats).maximumSizeValue) break;
          if ((this->tradeBoats).value[iVar3] == local_2c) goto LAB_004ee056;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->tradeBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->tradeBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->tradeBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->tradeBoats).maximumSizeValue);
          }
          operator_delete((this->tradeBoats).value);
          (this->tradeBoats).value = piVar2;
          (this->tradeBoats).maximumSizeValue = iVar6;
        }
      }
      (this->tradeBoats).value[(this->tradeBoats).numberValue] = iVar1;
      (this->tradeBoats).numberValue = (this->tradeBoats).numberValue + 1;
LAB_004ee056:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->transportBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->transportBoats).maximumSizeValue) break;
          if ((this->transportBoats).value[iVar3] == local_2c) goto LAB_004ee15b;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->transportBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->transportBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->transportBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->transportBoats).maximumSizeValue);
          }
          operator_delete((this->transportBoats).value);
          (this->transportBoats).value = piVar2;
          (this->transportBoats).maximumSizeValue = iVar6;
        }
      }
      (this->transportBoats).value[(this->transportBoats).numberValue] = iVar1;
      (this->transportBoats).numberValue = (this->transportBoats).numberValue + 1;
LAB_004ee15b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (!(save_game_version < 1.4f)) {
    rge_read(file,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(file,&local_2c,4);
        iVar1 = local_2c;
        iVar6 = (this->artifacts).numberValue;
        iVar3 = 0;
        if (0 < iVar6) {
          do {
            if (iVar3 >= (this->artifacts).maximumSizeValue) break;
            if ((this->artifacts).value[iVar3] == local_2c) goto LAB_004ee277;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        if (iVar6 > (this->artifacts).maximumSizeValue - 1) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (this->artifacts).maximumSizeValue) {
              do {
                if (iVar6 <= iVar3) break;
                iVar4 = iVar3 + 1;
                piVar2[iVar3] = (this->artifacts).value[iVar3];
                iVar3 = iVar4;
              } while (iVar4 < (this->artifacts).maximumSizeValue);
            }
            operator_delete((this->artifacts).value);
            (this->artifacts).value = piVar2;
            (this->artifacts).maximumSizeValue = iVar6;
          }
        }
        (this->artifacts).value[(this->artifacts).numberValue] = iVar1;
        (this->artifacts).numberValue = (this->artifacts).numberValue + 1;
LAB_004ee277:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  iVar6 = param_2;
  rge_read(file,&param_1,4);
  iVar1 = 0;
  if (0 < param_1) {
    piVar2 = this->sn;
    do {
      rge_read(file,piVar2,4);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToAttack).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->playersToAttack).maximumSizeValue) break;
          if ((this->playersToAttack).value[iVar3] == local_2c) goto LAB_004ee3b4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->playersToAttack).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToAttack).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToAttack).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToAttack).maximumSizeValue);
          }
          operator_delete((this->playersToAttack).value);
          (this->playersToAttack).value = piVar2;
          (this->playersToAttack).maximumSizeValue = iVar6;
        }
      }
      (this->playersToAttack).value[(this->playersToAttack).numberValue] = iVar1;
      (this->playersToAttack).numberValue = (this->playersToAttack).numberValue + 1;
LAB_004ee3b4:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToDefend).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->playersToDefend).maximumSizeValue) break;
          if ((this->playersToDefend).value[iVar3] == local_2c) goto LAB_004ee4b9;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->playersToDefend).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToDefend).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToDefend).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToDefend).maximumSizeValue);
          }
          operator_delete((this->playersToDefend).value);
          (this->playersToDefend).value = piVar2;
          (this->playersToDefend).maximumSizeValue = iVar6;
        }
      }
      (this->playersToDefend).value[(this->playersToDefend).numberValue] = iVar1;
      (this->playersToDefend).numberValue = (this->playersToDefend).numberValue + 1;
LAB_004ee4b9:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->workingArea).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->workingArea).maximumSizeValue) break;
          if ((this->workingArea).value[iVar3] == local_2c) goto LAB_004ee5be;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->workingArea).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->workingArea).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->workingArea).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->workingArea).maximumSizeValue);
          }
          operator_delete((this->workingArea).value);
          (this->workingArea).value = piVar2;
          (this->workingArea).maximumSizeValue = iVar6;
        }
      }
      (this->workingArea).value[(this->workingArea).numberValue] = iVar1;
      (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ee5be:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->unitsTaskedThisUpdate).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->unitsTaskedThisUpdate).maximumSizeValue) break;
          if ((this->unitsTaskedThisUpdate).value[iVar3] == local_2c) goto LAB_004ee6c3;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->unitsTaskedThisUpdate).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->unitsTaskedThisUpdate).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((this->unitsTaskedThisUpdate).value);
          (this->unitsTaskedThisUpdate).value = piVar2;
          (this->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
        }
      }
      (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar1;
      (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004ee6c3:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  iVar6 = param_2;
  piVar2 = this->actualGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->desiredGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->neededResourceValue;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->resourceDifferenceValue;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberStoragePitsBuilt;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberGranariesBuilt;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0;
  do {
    rge_read(file,&local_2c,4);
    ResourceItem::setValue(&this->neededResources,iVar1,local_2c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  rge_read(file,&this->groupIDValue,4);
  piVar2 = &this->numberGroupsValue;
  rge_read(file,piVar2,4);
  iVar1 = 0;
  if (0 < *piVar2) {
    do {
#ifdef TAITACMD_SHARED_CONTEXT
      pTVar5 = this->createGroup(0);
#else
      pTVar5 = createGroup(this,0);
#endif
      if (pTVar5 != (TacticalAIGroup *)0x0) {
        TacticalAIGroup::load(pTVar5,file);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *piVar2);
  }
  rge_read(file,&this->lastGroupAttackTime,4);
  if (!(save_game_version < 2.4f)) {
    rge_read(file,&this->lastGroupRebalanceTime,4);
  }
  rge_read(file,&this->lastAttackResponseTime,4);
  rge_read(file,&this->lastBoatAttackResponseTime,4);
  rge_read(file,&this->lastScalingUpdateValue,4);
  rge_read(file,&this->numberBuildUpdatesSkipped,4);
  rge_read(file,&this->randomizedAttackSeparationTime,4);
  if (!(save_game_version < 2.2f)) {
    rge_read(file,&this->attackEnabledValue,4);
  }
  rge_read(file,&this->updateArea,4);
  if (!(save_game_version < 6.1f)) {
    rge_read(file,&this->wonderInProgressValue,4);
    rge_read(file,&this->wonderBuiltValue,4);
  }
  if (!(save_game_version < 6.2f)) {
    rge_read(file,&this->placementStateValue,0x130);
  }
  else {
    piVar2 = (int *)&this->placementStateValue;
    for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  (this->placementStateValue).active = 0;
  if (!(save_game_version < 6.3f)) {
    rge_read(file,&this->nextCivilianToTaskValue,4);
  }
  if (!(save_game_version < 6.4f)) {
    rge_read(file,&this->nextIdleSoldierGroupToTaskValue,4);
    rge_read(file,&this->nextActiveSoldierGroupToTaskValue,4);
  }
  if (!(save_game_version < 6.9f)) {
    rge_read(file,&this->builtFirstStoragePit,4);
    rge_read(file,&this->builtFirstGranary,4);
  }
  if (!(save_game_version < 6.95f)) {
    rge_read(file,&this->lastBuildTime,4);
    rge_read(file,&this->lastAttackResponseBuildInsertionTime,4);
    rge_read(file,&this->lastCoopTributeDemandTime,4);
  }
  if (!(save_game_version < 7.18f)) {
    rge_read(file,&this->lastCoopTributeGiftTime,4);
  }
  if (!(save_game_version < 6.96f)) {
    rge_read(file,&this->zoomingToNextAge,4);
  }
  if (!(save_game_version < 6.98f)) {
    rge_read(file,&this->lastCoopAttackDemandTime,4);
  }
  if (!(save_game_version < 6.993f)) {
    rge_read(file,&this->lastUngroupedSoldierTaskTime,4);
  }
  if (!(save_game_version < 7.04f)) {
    rge_read(file,&this->attackStateValue,0x2c);
  }
  else {
    piVar2 = (int *)&this->attackStateValue;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  (this->attackStateValue).active = 0;
  if (save_game_version < 7.15f) {
    piVar2 = this->hitsByPlayer;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(file,this->hitsByPlayer,0x24);
  }
}
