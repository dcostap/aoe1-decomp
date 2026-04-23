// tried the direct need_to_save / popupYesNoCancelDialog / start_scenario_editor shape; still off in early branch layout
class TRIBE_Game {
public:
    int start_scenario_editor(char* scenario_filename, int mode);
};

extern TRIBE_Game* rge_base_game;
extern char s_NewSaveDialog[];

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_0[0x4BC];
    unsigned char field_4C0;
    unsigned char need_to_save();
    void popupYesNoCancelDialog(long text_id, char* panel_name, int param_4, int param_5);
    void command_new(void);
};

void TRIBE_Screen_Sed::command_new(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_NewSaveDialog, 0x1C2, 100);
        return;
    }
    rge_base_game->start_scenario_editor((char*)0, 0);
}
