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

class ObjectMemory; class RGE_Static_Object; class RGE_Action; class RGE_Action_List;
class PlayerLike { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int playerAlive(int owner); };
class RGE_Action { public: virtual void av0(); virtual void av1(); virtual void av2(); virtual void av3(); virtual void av4(); virtual void av5(); virtual short actionType(); char gap_04[8]; unsigned char state; char gap_0d[0x1f]; float timer; };
class RGE_Action_List { public: char gap[0xc]; unsigned char have_action(); RGE_Action* get_action(); };
class RGE_Static_Object { public: char gap_00[0x30]; float hp; char gap_34[0x14]; unsigned char object_state; char gap_49[0x13b]; RGE_Action_List* action_list; };
class MainDecisionAIModule { public: char gap_000[0xf0]; PlayerLike* player; char gap_0f4[0x0c]; RGE_Static_Object* object(int id); };
class TribeMainDecisionAIModule : public MainDecisionAIModule {};
class ObjectMemory { public: int id; short type; short group; unsigned char x; unsigned char y; unsigned char z; unsigned char owner; short hitPoints; char gap_0e[0x16]; };
class TribeInformationAIModule { public: char gap_000[0x100]; TribeMainDecisionAIModule* md; char gap_104[0x0c]; int maxImportantObjectMemory; ObjectMemory* importantObjectMemory; ObjectMemory* wonderToAttack(int player_id); };

ObjectMemory* TribeInformationAIModule::wonderToAttack(int player_id)
{
    ObjectMemory* bestObject;
    float bestTimer;
    float hitpoints;
    int bestState;
    int i;
    int offset;
    int local_4;

    bestObject = 0;
    *(int*)&bestTimer = -1;
    hitpoints = 0.0f;
    i = 0;
    local_4 = 0;
    if (this->maxImportantObjectMemory > 0) {
        offset = 0;
        do {
            if (((ObjectMemory*)((char*)this->importantObjectMemory + offset))->type == 0x114) {
                if (player_id == -1 || ((ObjectMemory*)((char*)this->importantObjectMemory + offset))->owner == player_id) {
                    if (player_id != -1 || this->md->player->playerAlive(((ObjectMemory*)((char*)this->importantObjectMemory + offset))->owner)) {
                        RGE_Static_Object* obj = this->md->object(((ObjectMemory*)((char*)this->importantObjectMemory + offset))->id);
                        if (obj != 0) {
                            if (obj->object_state <= 2) {
                                if (obj->action_list->have_action()) {
                                    if (obj->action_list->get_action()->actionType() == 0x78) {
                                        bestState = obj->action_list->get_action()->state;
                                        float timer = obj->action_list->get_action()->timer;
                                        float hp = obj->hp;
                                        if (bestObject == 0) {
                                            bestObject = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                                            bestTimer = timer;
                                            i = bestState;
                                            hitpoints = hp;
                                        } else if (i == 6 && bestState == 2) {
                                        } else if (i == 2 && bestState == 6) {
                                            bestObject = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                                            bestTimer = timer;
                                            i = bestState;
                                            hitpoints = hp;
                                        } else if (i == bestState) {
                                            if (i == 2 && hitpoints < hp) {
                                                bestObject = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                                                bestTimer = timer;
                                                i = bestState;
                                                hitpoints = hp;
                                            } else if (i == bestState && i == 6 && bestTimer < timer) {
                                                bestObject = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                                                bestTimer = timer;
                                                i = bestState;
                                                hitpoints = hp;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            local_4++;
            offset += 0x24;
        } while (local_4 < this->maxImportantObjectMemory);
    }
    return bestObject;
}
