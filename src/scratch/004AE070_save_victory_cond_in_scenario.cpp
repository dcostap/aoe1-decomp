// 004AE070 TRIBE_Screen_Sed::save_victory_cond_in_scenario
// Attempt log:
// 1: direct reconstruction from packet/decompiler: save all/conquest flags, read UI amount/dropdowns/selection rectangle, clear slot, switch 0..18 storing SP victory condition fields.
// 2: first build reached exact 1375-byte size and matched the first 120 bytes, through the all/conquest flag saves and index<0 test; mismatch began at branch displacement because later body layout differs.
// 3: added explicit case 0 so VC5 keeps the original 0..18 jump-table shape instead of subtracting 1 and switching over 1..18; improved diff from 62.84% to 46.18% positional.
// 4: tried decompiler-style temp split for enemy-player line (`tmp`, `player = tmp + 1`) and changed objectType long/int; no register allocation improvement.
// 5: tried `register` on amount/player; no codegen change.
// 6: best exact-size source still has local/register topology mismatch after atoi/dropdowns: original keeps amount in EBX, selected-player+1 in EBP, and object type in the incoming parameter home, while rebuilt keeps amount in the param home, player in EBX, and object type in EBP.
// 7: remaining mismatch is broad switch-case register and block-layout drift despite behavior-like call sequence and exact size; not accepted_drift-safe.
// 8: replaced the decompiler temporary with direct int locals for amount, kind, player, and object type; size and strict diff stayed unchanged, with only neutral block-shape movement.
// 9: changed switch arms to natural breaks with one final return and guarded the selected-object arms; VC5 emitted duplicate code, so the missing case-6/case-9 call sites remain.
// 10: explicit early returns and direct null returns in selected-object arms were codegen duplicates; rolled back.
// 11: long dropdown/object locals and case-local aliases did not change the clean emission; a case-9 alias changed layout but left two merged calls, so rolled back.
// 12: an eight-variant direct/alias lab over cases 3, 5, and 9 found no exact call set; alias forms were less plausible and were discarded.
// 13: direct SetSPAmount in case 3 moved the diff to 764 bytes but broke the original shared amount-tail shape; restored the clean goto source.
// 14: paused with exact size/frame and canonical field ownership; structural blocker is VC5 merging two equivalent switch-arm call tails.

extern "C" int __cdecl atoi(const char*);

class TButtonPanel { public: int get_state(); };
class TEditPanel { public: char* currentLine(); };
class TDropDownPanel { public: long get_line(); long get_id(); };
class RGE_View { public: void get_selection_area(long*, long*, long*, int*, int); };
class RGE_Static_Object;
class T_Scenario {
public:
    void Set_victory_all_flag(int);
    void Set_Multi_Conquest(int);
    void ClearSPVictoryCondition(int);
    void SetSPRectangle(int,float,float,float,float);
    void SetSPObjectType(int,int);
    void SetSPPlayerID(int,int);
    void SetSPAllFlag(int,int);
    void SetSPAttribType(int,int);
    void SetSPVictoryType(int,int);
    void SetSPObject(int,RGE_Static_Object*);
    void SetSPDestObjectID(int,RGE_Static_Object*);
    void SetSPAmount(int,int);
};
class World { public: char gap[0x5c]; T_Scenario* scenario; };

class TRIBE_Screen_Sed {
public:
    char gap0[0x480];
    RGE_Static_Object* SelectedObject;
    RGE_Static_Object* DestinationObject;
    float px1, py1, px2, py2;
    char gap498[0x4C8-0x498]; RGE_View* main_view;
    char gap4CC[0x668-0x4CC]; TButtonPanel* victory_cond_on0;
    char gap66C[0x684-0x66C]; TButtonPanel* victory_and_or1;
    char gap688[0x6F0-0x688]; TButtonPanel* victory_cond_type4;
    char gap6F4[0x734-0x6F4]; TDropDownPanel* victory_drop_down;
    TDropDownPanel* victory_object_list;
    char gap73C[0x740-0x73C]; TDropDownPanel* victory_enemy_player_list;
    TDropDownPanel* victory_attribute_list;
    TDropDownPanel* victory_ages_list;
    TDropDownPanel* victory_tech_list;
    char gap750[0x76C-0x750]; TEditPanel* victory_amount_input;
    char gap770[0x928-0x770]; World* world;
    void save_victory_cond_in_scenario(int index);
};
#define SCEN (this->world->scenario)

void TRIBE_Screen_Sed::save_victory_cond_in_scenario(int index)
{
    if (this->victory_and_or1->get_state())
        SCEN->Set_victory_all_flag(1);
    else
        SCEN->Set_victory_all_flag(0);

    if (!this->victory_cond_on0->get_state() && this->victory_cond_type4->get_state())
        SCEN->Set_Multi_Conquest(0);
    else
        SCEN->Set_Multi_Conquest(1);

    if (index < 0) return;

    int amount;
    int kind;
    int player;
    int objectType;
    long x1, y1, x2; int y2;
    amount = atoi(this->victory_amount_input->currentLine());
    kind = this->victory_drop_down->get_line();
    player = this->victory_enemy_player_list->get_line() + 1;
    objectType = this->victory_object_list->get_id();
    this->main_view->get_selection_area(&x1, &y1, &x2, &y2, 1);
    this->px1 = (float)x1;
    this->py1 = (float)y1;
    this->px2 = (float)x2;
    this->py2 = (float)y2;
    SCEN->ClearSPVictoryCondition(index);

    switch (kind) {
    case 0:
        break;
    case 1:
        if (this->SelectedObject && this->DestinationObject) {
            SCEN->SetSPVictoryType(index,3);
            SCEN->SetSPObject(index,this->SelectedObject);
            SCEN->SetSPDestObjectID(index,this->DestinationObject);
        }
        break;
    case 2:
        if (this->SelectedObject) {
            SCEN->SetSPVictoryType(index,3);
            SCEN->SetSPObject(index,this->SelectedObject);
            SCEN->SetSPRectangle(index,this->px1,this->py1,this->px2,this->py2);
        }
        break;
    case 3:
        SCEN->SetSPVictoryType(index,2);
        SCEN->SetSPObjectType(index,objectType);
        goto set_amount;
    case 4:
        SCEN->SetSPVictoryType(index,2);
        SCEN->SetSPObjectType(index,objectType);
        SCEN->SetSPAmount(index,amount);
        SCEN->SetSPRectangle(index,this->px1,this->py1,this->px2,this->py2);
        break;
    case 5:
        if (player >= 1 && player <= 8 && amount) {
            SCEN->SetSPVictoryType(index,1);
            SCEN->SetSPPlayerID(index,player);
            SCEN->SetSPObjectType(index,objectType);
            SCEN->SetSPAmount(index,amount);
        }
        break;
    case 6:
        if (!this->SelectedObject) break;
        SCEN->SetSPVictoryType(index,1);
        SCEN->SetSPObject(index,this->SelectedObject);
        break;
    case 7:
        if (player >= 1 && player <= 8) {
            SCEN->SetSPVictoryType(index,1);
            SCEN->SetSPPlayerID(index,player);
            SCEN->SetSPObjectType(index,objectType);
            SCEN->SetSPAllFlag(index,1);
        }
        break;
    case 8:
        if (player >= 1 && player <= 8) {
            SCEN->SetSPVictoryType(index,1);
            SCEN->SetSPPlayerID(index,player);
        }
        break;
    case 9:
        if (!this->SelectedObject) break;
        SCEN->SetSPVictoryType(index,5);
        SCEN->SetSPObject(index,this->SelectedObject);
        break;
    case 10: SCEN->SetSPVictoryType(index,4); objectType = 0; goto attrib_amount;
    case 11: SCEN->SetSPVictoryType(index,4); objectType = 3; goto attrib_amount;
    case 12: SCEN->SetSPVictoryType(index,4); objectType = 1; goto attrib_amount;
    case 13: SCEN->SetSPVictoryType(index,4); objectType = 2; goto attrib_amount;
    case 14: SCEN->SetSPVictoryType(index,4); objectType = 4; goto attrib_amount;
    case 15:
        SCEN->SetSPVictoryType(index,4);
        SCEN->SetSPAttribType(index,5);
        SCEN->SetSPAmount(index,this->victory_ages_list->get_line()+1);
        break;
    case 16: SCEN->SetSPVictoryType(index,4); objectType = 6; goto attrib_amount;
    case 17:
        SCEN->SetSPVictoryType(index,6);
        objectType = this->victory_attribute_list->get_id();
attrib_amount:
        SCEN->SetSPAttribType(index,objectType);
set_amount:
        SCEN->SetSPAmount(index,amount);
        break;
    case 18:
        SCEN->SetSPVictoryType(index,7);
        objectType = this->victory_tech_list->get_id();
        SCEN->SetSPAttribType(index,objectType);
        break;
    default:
        break;
    }

    return;
}
