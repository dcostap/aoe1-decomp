// VA: 004AD700 TRIBE_Screen_Sed::command_save
// Attempt log:
// initial natural implementation from packet/decompiler with /GX and local stubs.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" int __cdecl strcmp(const char*, const char*);

class TPanelSystem { public: int destroyPanel(char*); int setCurrentPanel(char*, int); };
extern TPanelSystem panel_system;
class TRegistry { public: int RegGetInt(int, char*); };
class TRIBE_Game { public: char gap[0x1ac]; TRegistry* registry; void show_status_message(int,char*,int); void close_status_message(); int start_menu(); int start_scenario_editor(char*, int); void close(); };
extern TRIBE_Game* rge_base_game;
class TRIBE_Screen_Sed_Open { public: char pad[0x490]; TRIBE_Screen_Sed_Open(); };
class RGE_Scenario { public: int active_player_count(); int any_player_count(); char* Get_scenario_name(); };
class T_Scenario { public:
#define VPAD(n) virtual void v##n();
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31)
    VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39)
    VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47)
    VPAD(48) VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55)
    VPAD(56)
#undef VPAD
    virtual unsigned char save(char*); void Save_victory_conditions_into_players(int); };
struct WorldHolder {
#define WPAD(n) virtual void w##n();
    WPAD(0) WPAD(1) WPAD(2) WPAD(3) WPAD(4) WPAD(5) WPAD(6) WPAD(7)
    WPAD(8) WPAD(9) WPAD(10) WPAD(11) WPAD(12) WPAD(13) WPAD(14) WPAD(15)
    WPAD(16) WPAD(17) WPAD(18) WPAD(19) WPAD(20) WPAD(21) WPAD(22) WPAD(23)
    WPAD(24) WPAD(25) WPAD(26) WPAD(27) WPAD(28) WPAD(29) WPAD(30) WPAD(31)
    WPAD(32) WPAD(33) WPAD(34) WPAD(35) WPAD(36) WPAD(37) WPAD(38) WPAD(39)
    WPAD(40) WPAD(41) WPAD(42) WPAD(43) WPAD(44) WPAD(45) WPAD(46) WPAD(47)
    WPAD(48) WPAD(49) WPAD(50) WPAD(51) WPAD(52) WPAD(53) WPAD(54) WPAD(55)
    WPAD(56)
#undef WPAD
    virtual unsigned char save(char*);
    char gap[0x5c - 4]; T_Scenario* scenario; };
class TRIBE_Screen_Sed {
public:
    char gap[0x4c0];
    unsigned char need_to_save_flag;
    char gap2[0x928 - 0x4c1];
    WorldHolder* world;
    void set_scenario_mode(int);
    void popupOKDialog(long, char*, long, long);
    void command_save_as(unsigned char);
    void command_save(unsigned char closeMenu, unsigned char postAction);
};

void TRIBE_Screen_Sed::command_save(unsigned char closeMenu, unsigned char postAction)
{
    char temp_name[260];

    this->set_scenario_mode(11);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
    } else if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
    } else {
        char* name = ((RGE_Scenario*)this->world->scenario)->Get_scenario_name();
        if (*name == 0) {
            this->command_save_as(postAction);
        } else {
            rge_base_game->show_status_message(0x450, 0, -1);
            if (closeMenu != 0) {
                panel_system.destroyPanel((char*)0x005843CC);
            }
            if (this->world->save(name) == 0) {
                rge_base_game->close_status_message();
                this->popupOKDialog(0x963, 0, 0x1c2, 100);
            } else {
                rge_base_game->close_status_message();
                sprintf(temp_name, (char*)0x00586D38, rge_base_game->registry->RegGetInt(0, (char*)0x0057FA58));
                if (strcmp(name, temp_name) != 0) {
                    this->need_to_save_flag = 0;
                }
                if (postAction == 1) {
                    if (rge_base_game->start_menu() == 0) {
                        rge_base_game->close();
                    } else {
                        panel_system.destroyPanel((char*)0x00584414);
                    }
                } else if (postAction == 2) {
                    TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
                    panel_system.setCurrentPanel((char*)0x005843FC, 0);
                } else if (postAction == 3) {
                    rge_base_game->start_scenario_editor(0, 0);
                }
            }
        }
    }
}
