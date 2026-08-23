// 004AE620 TRIBE_Screen_Sed::load_victory_cond_from_scenario
// Attempt log:
// 1: natural source from packet/decompiler, preserving switch structure.
// 2: initial natural build had correct 880-byte size but broad mismatch (75.80% positional / 66.25% edit), first mismatch at frame size 0x44 vs original 0x48.
// 3: fixed TRIBE_Screen_Sed layout around +0x734..+0x928 (victory_tech_list/gap) after rebuilt used world at +0x924; this restored +0x928 and +0x76c accesses.
// 4: fixed T_Scenario vtable padding so reset dispatch is +0x08 like original instead of +0x04.
// 5: fixed victory_and_or virtual surface from two-arg set_data to one-arg virtual at +0xE0, removing extra zero pushes and matching the top branch structure.
// 6: increased temp string buffer to 44 bytes to recover the original 0x48 frame; best/current comparable build is 880 bytes, first mismatch only branch displacement at offset 87, but later layout still broad.
// 7: probed an extra savedAmount local and volatile variants to force original `[esp+34]` amount store before itoa; volatile perturbed badly, nonvolatile optimized away; rolled back.
// 8: Broad behavior/calls are represented: all-flag toggles, SetSPWhich, amount itoa/edit text, player/object dropdowns, selected/destination objects, rectangle/selection area, nested switch mapping to victory dropdown and attribute/tech/age special cases.
// 9: Corrected the typed dropdown layout: object +738, enemy +740, attribute +744, ages +748, tech +74c, amount input +76c, world +928. Restored enemy set_line.
// 10: Tested a common switch label, explicit shared-tail gotos, local declaration order, split amount liveness, and a carried dropdown pointer. These either optimized away or moved farther.
// 11: Restored the natural 40-byte string buffer and one Amount local. The current structural blocker is VC5 tail duplication: 19 emitted setCurrentLineNumber calls versus 6 original calls, plus the missing amount stack home.
// 12: Direct per-case line updates were a negative control; VC5 emitted 21 setter calls.
// 13: Reordered arms to the binary/PDB order 4,6,7,5,1,2,3,0; VC5 recovered the shared setter tail and all call counts.
// 14: Restored the shared final setter after the prior control-flow test omitted it; behavior and call order are now complete.
// 15: A 44-byte buffer recovered the proven 0x48 frame with the reordered switch.
// 16: Direct setter arms plus the reordered cases recovered exact size, frame, instruction count, CFG counts, and call order.
// 17: A 40-byte buffer confirmed the remaining frame/local-topology gap.
// 18: Moved case 0 last to match the original late outer-switch block.
// 19: Combined the original case order with the frame-correct buffer.
// 20: Reordered declarations to the packet's proven local order; VC5 emitted the same code.
// 21: Modeled the proven adjacent four-byte stack slot and 40-byte text buffer as a typed local aggregate; the string LEA now matches.
// 22: Made the adjacent slot an int field used as the itoa value; this restored the original dead local store and reduced the diff to 14 stack-displacement bytes.
// 23: Typed RGE_Static_Obj pointers and declaration reorders were neutral; reversed aggregate fields moved the string home and worsened the diff.
// The former clean source matched calls, size, frame, CFG, and block topology.
// It had 14 local stack-displacement differences.
// The first 20-probe checkpoint tested stack ownership, declaration order, field
// types, liveness, comma evaluation, register qualification, and aggregate forms.
// A typed amount/destination/text aggregate plus a separate scalar destination
// reduced the diagnostic drift to 9 bytes, but it required a redundant explicit
// field copy and was not retained as canonical source. Its only mismatch was
// spill scheduling: the original pushes the next getter argument, then spills
// the destination result; the aggregate copy stores it before that push.
// Reversions restored the natural source. Open lead: recover that spill timing
// through a period-plausible local ownership model, not a duplicate alias.
// Exact finish:
// - DIA gives Amount at -0x30, destobj at -0x2C, and str[40] at -0x28.
// - DIA gives x1, y1, x2, and y2 at -0x38 through -0x44.
// - The original case-1 block reads Amount. The case-3 block reads destobj.
// - Separate PDB-named locals plus the Amount predicate recover all 880 bytes.
// - Keeping either the aggregate or the destobj predicate leaves four bytes.
// ORIGINAL BUG: Case 1 tests Amount instead of destobj.
// Binary offsets +0x2E0 and +0x349 read the distinct PDB homes.
// The selected victory line can depend on the amount when no destination exists.
// Keep this shipped UI behavior instead of correcting the predicate.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::load_victory_cond_from_scenario(int index)
{
    char str[40];
    RGE_Static_Object* destobj;
    int Amount;
    int VictoryType;
    long x1, y1, x2, y2;
    RGE_Static_Object* obj;

    int all = this->world->scenario->Get_victory_all_flag();
    if (all != 0) {
        this->victory_and_or[0]->set_state(0);
        this->victory_and_or[1]->set_state(1);
    } else {
        this->victory_and_or[0]->set_state(1);
        this->victory_and_or[1]->set_state(0);
    }

    if (index < 0) return;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    this->world->scenario->reset();
    this->world->scenario->SetSPWhich((int)this->player_num - 1);
    Amount = this->world->scenario->GetSPAmount(index);
    itoa(Amount, str, 10);
    this->victory_amount_input->set_text(str);
    this->victory_enemy_player_list->set_line(this->world->scenario->GetSPPlayerID(index) - 1);
    this->victory_object_list->setCurrentLineNumber(this->victory_object_list->get_line(this->world->scenario->GetSPObjectType(index)));
    obj = this->world->scenario->GetSPObject(index);
    destobj = this->world->scenario->GetSPDestObjectID(index);
    this->SelectedObject = obj;
    this->DestinationObject = destobj;
    VictoryType = this->world->scenario->GetSPVictoryType(index);
    int AttributeType = this->world->scenario->GetSPAttribType(index);
    this->world->scenario->GetSPRectangle(index, &this->px1, &this->py1, &this->px2, &this->py2);
    x1 = (long)this->px1; y1 = (long)this->py1; x2 = (long)this->px2; y2 = (long)this->py2;
    this->main_view->set_selection_area(-1,-1,-1,-1);
    if (this->px2 != 0.0f) this->main_view->set_selection_area(x1,y1,x2,y2);

    switch (VictoryType) {
    case 4:
        switch (AttributeType) {
        case 0: this->victory_drop_down->setCurrentLineNumber(10); break;
        case 3: this->victory_drop_down->setCurrentLineNumber(11); break;
        case 1: this->victory_drop_down->setCurrentLineNumber(12); break;
        case 2: this->victory_drop_down->setCurrentLineNumber(13); break;
        case 4: this->victory_drop_down->setCurrentLineNumber(14); break;
        case 5:
            this->victory_drop_down->setCurrentLineNumber(15);
            this->victory_ages_list->setCurrentLineNumber(this->world->scenario->GetSPAmount(index)-1);
            return;
        case 6: this->victory_drop_down->setCurrentLineNumber(16); break;
        default: return;
        }
        break;
    case 6:
        this->victory_drop_down->setCurrentLineNumber(17);
        this->victory_attribute_list->setCurrentLineId(AttributeType);
        return;
    case 7:
        this->victory_drop_down->setCurrentLineNumber(18);
        this->victory_tech_list->setCurrentLineId(AttributeType);
        return;
    case 5:
        if (obj == 0) return;
        this->victory_drop_down->setCurrentLineNumber(9);
        break;
    case 1:
        // ORIGINAL BUG: PDB home -0x30 and the case-1 load use Amount.
        // The destination object does not select line 5 in this case.
        if (Amount != 0) this->victory_drop_down->setCurrentLineNumber(5);
        else if (obj != 0) this->victory_drop_down->setCurrentLineNumber(6);
        else if (this->world->scenario->GetSPAllFlag(index)) this->victory_drop_down->setCurrentLineNumber(7);
        else this->victory_drop_down->setCurrentLineNumber(8);
        break;
    case 2:
        this->world->scenario->GetSPRectangle(index, &this->px1, &this->py1, &this->px2, &this->py2);
        if (this->px2 > 0.0) this->victory_drop_down->setCurrentLineNumber(4);
        else this->victory_drop_down->setCurrentLineNumber(3);
        break;
    case 3:
        if (destobj != 0) this->victory_drop_down->setCurrentLineNumber(1);
        else this->victory_drop_down->setCurrentLineNumber(2);
        break;
    case 0:
        this->victory_drop_down->setCurrentLineNumber(0);
        break;
    default: return;
    }
}
