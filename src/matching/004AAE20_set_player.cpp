// 004AAE20 TRIBE_Screen_Sed::set_player
// Attempt log:
// 1: natural reconstruction from packet/Ghidra with exact member offsets and direct member calls.

typedef unsigned char uchar;

extern "C" int __cdecl atoi(const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
#define rge_base_game (*(RGE_Base_Game**)0x62C574)

class RGE_Player { public: void unselect_object(); };
class RGE_Base_Game {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set_player(short player);
    RGE_Player* get_player();
};

class TEditPanel {
public:
    char* currentLine();
    void set_text(char* s);
};

class TDropDownPanel {
public:
    int currentLineNumber();
    char* currentLine(int zero);
    void set_line(long line);
    void setCurrentLineNumber(long line);
    long get_line(char* s);
    long append_line(char* s, long v);
};

class TScenarioData {
public:
    char gap_00[0x40];
    void** players; // +40
    char gap_44[0x18];
    void* scenario; // +5c
};

class T_Scenario {
public:
    void Set_player_Food(long p, int v);
    void Set_player_Wood(long p, int v);
    void Set_player_Stone(long p, int v);
    void Set_player_Gold(long p, int v);
    int Get_player_Food(long p);
    int Get_player_Wood(long p);
    int Get_player_Stone(long p);
    int Get_player_Gold(long p);
};

class RGE_Scenario {
public:
    void SetPlayerName(long p, char* s);
    void Set_player_Type(long p, int v);
    void Set_player_Civ(long p, int v);
    void Set_player_AI(long p, char* s);
    void Set_BuildList(long p, char* s);
    void Set_CityPlan(long p, char* s);
    char* GetPlayerName(long p);
    int Get_player_Type(long p);
    int Get_player_Civ(long p);
    char* Get_player_AI(long p, long v);
    char* Get_BuildList(long p, long v);
    char* Get_CityPlan(long p, long v);
};

class TRIBE_Screen_Sed {
public:
    char gap_000[0x4B8];
    short player_num;
    char gap_4BA[0x5B4 - 0x4BA];
    TDropDownPanel* player_list; // +5b4
    char gap_5B8[0x5D8 - 0x5B8];
    TEditPanel* food;  // +5d8
    TEditPanel* wood;  // +5dc
    TEditPanel* stone; // +5e0
    TEditPanel* gold;  // +5e4
    TEditPanel* name;  // +5e8
    char gap_5EC[0x5F8 - 0x5EC];
    TDropDownPanel* type_drop; // +5f8
    TDropDownPanel* civ_drop;  // +5fc
    TDropDownPanel* buildList; // +600
    TDropDownPanel* cityPlan;  // +604
    TDropDownPanel* aiRules;   // +608
    char gap_60C[0x928 - 0x60C];
    TScenarioData* world; // +928

    void set_player(short player, uchar update, uchar refresh);
};

void TRIBE_Screen_Sed::set_player(short player, uchar update, uchar refresh)
{
    char str[30];
    long oldp = this->player_num - 1;
    if (oldp < 0) oldp = 0;

    rge_base_game->get_player()->unselect_object();

    if (update) {
        int v;
        v = atoi(this->food->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Food(oldp, v);
        *(float*)*(int*)((char*)this->world->players[this->player_num] + 0x50) = (float)v;

        v = atoi(this->wood->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Wood(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 4) = (float)v;

        v = atoi(this->stone->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Stone(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 8) = (float)v;

        v = atoi(this->gold->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Gold(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 12) = (float)v;

        ((RGE_Scenario*)this->world->scenario)->SetPlayerName(oldp, this->name->currentLine());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Type(oldp, this->type_drop->currentLineNumber());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Civ(oldp, this->civ_drop->currentLineNumber() + 1);
        ((RGE_Scenario*)this->world->scenario)->Set_player_AI(oldp, this->aiRules->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_BuildList(oldp, this->buildList->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_CityPlan(oldp, this->cityPlan->currentLine(0));
    }

    long p = player - 1;
    this->player_num = player;
    if (player != 0) {
        this->player_list->set_line(p);
        rge_base_game->set_player(player);
        if (refresh == 1) {
            int v;
            v = ((T_Scenario*)this->world->scenario)->Get_player_Food(p);
            sprintf(str, (char*)0x584610, v);
            this->food->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Wood(p);
            sprintf(str, (char*)0x584610, v);
            this->wood->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Stone(p);
            sprintf(str, (char*)0x584610, v);
            this->stone->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Gold(p);
            sprintf(str, (char*)0x584610, v);
            this->gold->set_text(str);
            this->name->set_text(((RGE_Scenario*)this->world->scenario)->GetPlayerName(p));
            this->type_drop->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Type(p));
            this->civ_drop->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Civ(p) - 1);

            v = this->aiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            if (v == -1) {
                this->aiRules->append_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0), 0);
                v = this->aiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            }
            this->aiRules->setCurrentLineNumber(v);

            v = this->buildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            if (v == -1) {
                this->buildList->append_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0), 0);
                v = this->buildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            }
            this->buildList->setCurrentLineNumber(v);

            v = this->cityPlan->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            if (v == -1) {
                this->cityPlan->append_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0), 0);
                v = this->cityPlan->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            }
            this->cityPlan->setCurrentLineNumber(v);
        }
    }
}
