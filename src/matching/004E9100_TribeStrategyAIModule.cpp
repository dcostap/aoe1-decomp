// VA: 004E9100 TribeStrategyAIModule constructor (315B)
// taistrmd.cpp
// EH frame (/GX)
//
// Attempt log:
// baseline reconstruction: period-plausible derived constructor with the
// proven StrategyAIModule base, three ManagedArray-like members, the
// VictoryConditionRuleSystem member, and named Waypoint fields (214-byte
// mismatch; array/member construction was initially modeled in the body).
// tried default-constructing the three destructible arrays and ordering their
// initializers after the scalar fields; mismatch fell to 7 bytes and the
// original call/frame topology aligned.
// moved difficultyLevel(0) into the member-initializer sequence; this placed
// the derived vptr store after the difficulty store and matched exactly.
// Canonical-context check: the shared PDB layout remains exact alone and in
// the complete ordered /GX prefix through the loading constructor.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
#include "../../include/taistrmd_context.h"

TribeStrategyAIModule::TribeStrategyAIModule(void* object, int parameter)
    : StrategyAIModule(object, parameter),
      md(0),
      currentVictoryConditionValue(-1),
      targetIDValue(-1),
      targetTypeValue(-1),
      secondTargetIDValue(-1),
      secondTargetTypeValue(-1),
      targetAttributeValue(-1),
      targetNumberValue(-1),
      victoryConditionChangeTimeout(0),
      vcRuleSet(),
      executingRules(),
      idleRules(),
      vcRules(),
      difficultyLevel(0)
{
    this->targetPoint1Value.x = -1.0f;
    this->targetPoint1Value.y = -1.0f;
    this->targetPoint1Value.z = -1.0f;
    this->targetPoint2Value.x = -1.0f;
    this->targetPoint2Value.y = -1.0f;
    this->targetPoint2Value.z = -1.0f;
    strcpy(this->ruleSetNameValue, "");
}
