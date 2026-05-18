// VA: 004A69B0 TRIBE_Screen_Name::action
// FLAGS: config/flags/004A69B0.rsp (/GX for EH frame around new+ctor)
// Attempt log:
// try 1: natural reconstruction from packet and sibling dialog action: create campaign/SP/dialog screens,
// player-name add/remove paths, tab-order refresh, and base TEasy_Panel fallback.
// try 2: added /GX response file because original has EH registration around new+ctor calls; current source still does not trigger the original EH prologue/state topology.
// try 3: modeled ok button branch: name-list get_line, -1 early return, base-game save_options, game-info set_person, allocate campaign selection screen, panel_system create/set-current. Broad mismatch remains.
// try 4: modeled cancel branch: save_options, allocate single-player menu, create/set-current. Object sizes 0x4cc/0x49c match original new sizes.
// try 5: modeled exit button as base-game quit_game and list double-click as recursive action(ok,1,0,0).
// try 6: modeled new-name dialog allocation size 0x4a4 with parent this and panel_system createPanel("New Name Dialog",...,0).
// try 7: modeled edit/delete-ish branch with get_line guard, sprintf into 256-byte local buffer, message_box, and return-1 behavior; exact resource/string call sequence remains wrong.
// try 8: modeled child-panel-name dispatch using TPanel::name() and strcmp against "New Name Dialog"/"Edit", with get_player_names/setup_tab_order side effects and panel_system current-panel calls.
// try 9: compared: exact size 914 but broad mismatch (69.4748% positional / 75.2735% edit). First mismatch at offset 0 because original EH registration prologue is missing in rebuilt; many later branches also differ.
// GIVEUP blockers: exact TRIBE_Screen_Name member layout/buttons at +0x480..+0x498, real TList/TPanel/TPanelSystem method signatures, resource-format/message_box call surface, and VC5 /GX constructor EH state topology around new+ctor calls. No inline asm used; no accepted_drift proposal.

#include <string.h>
#include <stdio.h>

void* operator new(unsigned int size);

class TPanel { public: char* name(); };
class TEditPanel : public TPanel { public: int get_line(); char* get_text(); char* get_line_text(int); };
class TButtonPanel : public TPanel {};
class TEasy_Panel : public TPanel {
public:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    long message_box(char* text, int id, int flags, int timeout);
};

class RGE_Game_Info { public: void delete_person(int); void add_new_person(char*); void set_person(int, char*); };
class RGE_Base_Game { public: char gap[4]; RGE_Game_Info* player_game_info; void save_options(); void quit_game(); };
extern RGE_Base_Game* rge_base_game;

class TPanelSystem { public: int createPanel(char*, TPanel*, int); int setCurrentPanel(char*); char* panel(char*); };
extern TPanelSystem panel_system;

class TRIBE_Screen_Campaign_Selection { public: char data[0x4cc]; TRIBE_Screen_Campaign_Selection(); };
class TribeSPMenuScreen { public: char data[0x49c]; TribeSPMenuScreen(); };
class TRIBE_Dialog_Name { public: char data[0x4a4]; TRIBE_Dialog_Name(TPanel*); };

static char s_campaign[] = "Campaign Selection Screen";
static char s_single[] = "Single Player Menu";
static char s_name[] = "Name Selection Screen";
static char s_new_name[] = "New Name Dialog";
static char s_delete[] = "Delete";
static char s_edit[] = "Edit";

class TRIBE_Screen_Name : public TEasy_Panel {
public:
    char gap_04[0x480 - 4];
    TEditPanel* name_list;       // +480
    TPanel* delete_button;       // +484? guessed
    TPanel* new_button;          // +488
    TPanel* edit_button;         // +48c
    TPanel* ok_button;           // +490
    TPanel* cancel_button;       // +494
    TPanel* exit_button;         // +498

    long action(TPanel* panel, long p2, unsigned long p3, unsigned long p4);
    void get_player_names();
    void setup_tab_order();
};

long TRIBE_Screen_Name::action(TPanel* panel, long p2, unsigned long p3, unsigned long p4)
{
    char str[256];
    if (panel) {
        if (panel == this->ok_button && p2 == 1) {
            int line = this->name_list->get_line();
            if (line == -1) return 1;
            rge_base_game->save_options();
            rge_base_game->player_game_info->set_person(line, this->name_list->get_line_text(line));
            TRIBE_Screen_Campaign_Selection* s = new TRIBE_Screen_Campaign_Selection;
            panel_system.createPanel(s_campaign, (TPanel*)s, 0);
            panel_system.setCurrentPanel(s_name);
            return 1;
        }
        if (panel == this->cancel_button && p2 == 1) {
            rge_base_game->save_options();
            TribeSPMenuScreen* s2 = new TribeSPMenuScreen;
            panel_system.createPanel(s_single, (TPanel*)s2, 0);
            panel_system.setCurrentPanel(s_name);
            return 1;
        }
        if (panel == this->exit_button) {
            rge_base_game->quit_game();
            return 1;
        }
        if (panel == this->name_list && p2 == 3) {
            this->action(this->ok_button, 1, 0, 0);
            return 1;
        }
        if (panel == this->new_button && p2 == 1) {
            TRIBE_Dialog_Name* d = new TRIBE_Dialog_Name(this);
            panel_system.createPanel(s_new_name, (TPanel*)d, 0);
            return 1;
        }
        if (panel == this->edit_button && p2 == 1) {
            if (this->name_list->get_line() == -1) return 1;
            sprintf(str, "%s", this->name_list->get_line_text(this->name_list->get_line()));
            this->message_box(str, 0x1c2, 0, 0x64);
            return 1;
        }
        if (panel->name() && strcmp(panel->name(), s_new_name) == 0) {
            if (p2 == 1) this->get_player_names();
            panel_system.createPanel(s_name, 0, 0);
            panel_system.setCurrentPanel(s_new_name);
            return 1;
        }
        if (panel->name() && strcmp(panel->name(), s_edit) == 0) {
            if (p2 == 0) {
                int line = this->name_list->get_line();
                if (line != -1) {
                    rge_base_game->player_game_info->delete_person(line);
                    this->get_player_names();
                }
            }
            panel_system.setCurrentPanel(s_edit);
            this->setup_tab_order();
            return 1;
        }
    }
    return TEasy_Panel::action(panel, p2, p3, p4);
}
