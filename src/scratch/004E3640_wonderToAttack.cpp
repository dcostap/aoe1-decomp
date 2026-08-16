// Attempt log for 004E3640 TribeInformationAIModule::wonderToAttack
// try 1: natural decompiler-shaped loop with minimal local types; 464B, wrong prologue/register basin.
// try 2: avoid durable ObjectMemory* iterator local; use stack state/offset split closer to original; exact size but 82.18% diff, EBP=this/EDI=offset not original EBX=this/EBP=offset.
// try 3: explicit offset local and separate guards to probe register allocation; same as try2.
// try 4: /O1 flag produced too-small 407B object, rolled back.
// try 5: /GX produced identical mismatch to try3, rolled back.
// try 6: register offset local to probe EBP/EDI allocation; no codegen change.
// try 7: make player_id mutable local by assigning it to itself before loop; optimized away/no change.
// try 8: change offset back to ordinary int and declare before local_4 to test local order; no codegen change.
// try 9: reviewed loop forms (do/while already matches original bottom test; while would invert/top-check and was not kept).
// try 10: reviewed condition/floating compare polarity; current source matches original behavior but branch/register allocation remains wrong.
// left in scratch: best checked form has exact 505B size but persistent first-mismatch at prologue; VC5 keeps this in EBP and offset in EDI, original has this in EBX and offset in EBP. Calls/layout are plausible but broad register-basin diff remains.
// session probes: moving offset initialization before the guard improved the
// structural diff, but the period-plausible state/best-state/count declaration
// order with offset initialized in the positive scan arm was better: 505B,
// 86.00% shape, 53.38% exact-block coverage, 393 differing bytes. A third
// get_action result local produced a 479B function and was rolled back;
// declaration-only virtual surfaces were codegen-neutral. stdlib.h plus
// string.h matched the nearby taiinfmd CRT context and was retained; a natural
// self alias was codegen-neutral and was not retained. Remaining mismatch is
// the EBX-this/EBP-state register basin and associated local load order; all
// seven calls, frame, size, and observed field/call topology are aligned.
// r2 probe: direct typed importantObjectMemory[i] indexing followed exact
// same-TU donors; it improved block shape but gave 397 differing bytes.
// r2 probes: the proven InformationAIModule base, full RGE_Player vtable
// surface, hoisted locals, and a two-induction for loop were tested; the
// ABI/liveness forms were codegen duplicates and the for loop regressed.
// Current pass: raw 0x24-byte cursor expressions improved the broad diagnostic
// by four bytes. Main-agent review rejected that metric-only form because the
// typed ObjectMemory array owns the same proven fields. The typed indexed form
// remains the clean source. The saved-register basin is still unresolved.

#include <stdlib.h>
#include <string.h>

class ObjectMemory; class RGE_Static_Object; class RGE_Action; class RGE_Action_List;
class PlayerLike { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int playerAlive(int owner); };
class RGE_Action { public: virtual ~RGE_Action(); virtual void av0(); virtual void av1(); virtual void av2(); virtual void av3(); virtual void av4(); virtual short actionType(); char gap_04[8]; unsigned char state; char gap_0d[0x1f]; float timer; };
class RGE_Action_List { public: char gap[0xc]; unsigned char have_action(); RGE_Action* get_action(); };
class RGE_Static_Object { public: virtual ~RGE_Static_Object(); char gap_04[0x2c]; float hp; char gap_34[0x14]; unsigned char object_state; char gap_49[0x13b]; RGE_Action_List* action_list; };
class MainDecisionAIModule { public: virtual ~MainDecisionAIModule(); char gap_04[0xec]; PlayerLike* player; char gap_0f4[0x0c]; RGE_Static_Object* object(int id); };
class TribeMainDecisionAIModule : public MainDecisionAIModule {};
class ObjectMemory { public: int id; short type; short group; unsigned char x; unsigned char y; unsigned char z; unsigned char owner; short hitPoints; char gap_0e[0x16]; };
class TribeInformationAIModule { public: virtual ~TribeInformationAIModule(); char gap_04[0xfc]; TribeMainDecisionAIModule* md; char gap_104[0x0c]; int maxImportantObjectMemory; ObjectMemory* importantObjectMemory; ObjectMemory* wonderToAttack(int player_id); };

ObjectMemory* TribeInformationAIModule::wonderToAttack(int player_id)
{
    ObjectMemory* bestObject;
    int bestState;
    float bestTimer;
    float bestHitpoints;
    int i;

    bestObject = 0;
    bestState = -1;
    bestTimer = 0.0f;
    bestHitpoints = 0.0f;
    i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x114) {
                if (player_id == -1 || this->importantObjectMemory[i].owner == player_id) {
                    if (player_id != -1 || this->md->player->playerAlive(this->importantObjectMemory[i].owner)) {
                        RGE_Static_Object* obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            if (obj->object_state <= 2) {
                                if (obj->action_list->have_action()) {
                                    if (obj->action_list->get_action()->actionType() == 0x78) {
                                        int state = obj->action_list->get_action()->state;
                                        float timer = obj->action_list->get_action()->timer;
                                        float hp = obj->hp;
                                        if (bestObject == 0) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        } else if (bestState == 6 && state == 2) {
                                        } else if (bestState == 2 && state == 6) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        } else if (bestState == state) {
                                            if (bestState == 2 && bestHitpoints < hp) {
                                                bestObject = &this->importantObjectMemory[i];
                                                bestState = state;
                                                bestTimer = timer;
                                                bestHitpoints = hp;
                                            } else if (bestState == state && bestState == 6 && bestTimer < timer) {
                                                bestObject = &this->importantObjectMemory[i];
                                                bestState = state;
                                                bestTimer = timer;
                                                bestHitpoints = hp;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return bestObject;
}
