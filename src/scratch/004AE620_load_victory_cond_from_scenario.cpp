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
// GIVEUP: left in scratch; exact calls, size, frame, CFG, and block topology match. Remaining drift is 14 local stack displacements.
// Managed claim notes: the natural source remains the 14-byte clean reconstruction.
// The first 20-probe checkpoint tested stack ownership, declaration order, field
// types, liveness, comma evaluation, register qualification, and aggregate forms.
// A typed amount/destination/text aggregate plus a separate scalar destination
// reduced the diagnostic drift to 9 bytes, but it required a redundant explicit
// field copy and was not retained as canonical source. Its only mismatch was
// spill scheduling: the original pushes the next getter argument, then spills
// the destination result; the aggregate copy stores it before that push.
// Reversions restored the natural source. Open lead: recover that spill timing
// through a period-plausible local ownership model, not a duplicate alias.

extern "C" char* __cdecl itoa(int, char*, int);

class RGE_Static_Obj;

struct VictoryTextBuffer {
    int amount;
    char str[40];
};

class TListLike { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void set_data(int); };
class TDropDownPanel { public: void set_line(long); void setCurrentLineNumber(int); int get_line(int); void setCurrentLineId(int); };
class TEditPanel { public: void set_text(char*); };
class RGE_View { public: void set_selection_area(long,long,long,long); };
class T_Scenario {
public:
    virtual void v0(); virtual void v1(); virtual void reset();
    int Get_victory_all_flag(); void SetSPWhich(int);
    int GetSPAmount(int); int GetSPPlayerID(int); int GetSPObjectType(int); RGE_Static_Obj* GetSPObject(int);
    RGE_Static_Obj* GetSPDestObjectID(int); int GetSPVictoryType(int); int GetSPAttribType(int);
    int GetSPAllFlag(int); void GetSPRectangle(int, float*, float*, float*, float*);
};
class World { public: char gap[0x5c]; T_Scenario* scenario; };

class TRIBE_Screen_Sed {
public:
    char gap0[0x480];
    RGE_Static_Obj* SelectedObject;
    RGE_Static_Obj* DestinationObject;
    float px1, py1, px2, py2;
    char gap498[0x4b8-0x498]; short player_num;
    char gap4ba[0x4c8-0x4ba]; RGE_View* main_view;
    char gap4cc[0x680-0x4cc]; TListLike* victory_and_or0; TListLike* victory_and_or1;
    char gap688[0x734-0x688]; TDropDownPanel* victory_drop_down; TDropDownPanel* victory_object_list;
    char gap73c[4]; TDropDownPanel* victory_enemy_player_list; TDropDownPanel* victory_attribute_list; TDropDownPanel* victory_ages_list; TDropDownPanel* victory_tech_list;
    char gap750[0x76c-0x750]; TEditPanel* victory_amount_input;
    char gap770[0x928-0x770]; World* world;
    void load_victory_cond_from_scenario(int index);
};

void TRIBE_Screen_Sed::load_victory_cond_from_scenario(int index)
{
    VictoryTextBuffer text;
    RGE_Static_Obj* destobj;
    int VictoryType;
    long x1, y1, x2, y2;
    RGE_Static_Obj* obj;

    int all = this->world->scenario->Get_victory_all_flag();
    if (all != 0) {
        this->victory_and_or0->set_data(0);
        this->victory_and_or1->set_data(1);
    } else {
        this->victory_and_or0->set_data(1);
        this->victory_and_or1->set_data(0);
    }

    if (index < 0) return;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    this->world->scenario->reset();
    this->world->scenario->SetSPWhich((int)this->player_num - 1);
    text.amount = this->world->scenario->GetSPAmount(index);
    itoa(text.amount, text.str, 10);
    this->victory_amount_input->set_text(text.str);
    this->victory_enemy_player_list->set_line(this->world->scenario->GetSPPlayerID(index) - 1);
    this->victory_object_list->setCurrentLineNumber(this->victory_object_list->get_line(this->world->scenario->GetSPObjectType(index)));
    obj = this->world->scenario->GetSPObject(index);
    destobj = this->world->scenario->GetSPDestObjectID(index);
    this->SelectedObject = obj;
    this->DestinationObject = destobj;
    VictoryType = this->world->scenario->GetSPVictoryType(index);
    int attrib = this->world->scenario->GetSPAttribType(index);
    this->world->scenario->GetSPRectangle(index, &this->px1, &this->py1, &this->px2, &this->py2);
    x1 = (long)this->px1; y1 = (long)this->py1; x2 = (long)this->px2; y2 = (long)this->py2;
    this->main_view->set_selection_area(-1,-1,-1,-1);
    if (this->px2 != 0.0f) this->main_view->set_selection_area(x1,y1,x2,y2);

    switch (VictoryType) {
    case 4:
        switch (attrib) {
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
        this->victory_attribute_list->setCurrentLineId(attrib);
        return;
    case 7:
        this->victory_drop_down->setCurrentLineNumber(18);
        this->victory_tech_list->setCurrentLineId(attrib);
        return;
    case 5:
        if (obj == 0) return;
        this->victory_drop_down->setCurrentLineNumber(9);
        break;
    case 1:
        if (destobj != 0) this->victory_drop_down->setCurrentLineNumber(5);
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
