// 004A6050 ~TRIBE_Screen_Wait
// 143 bytes, __thiscall, TRIBE_Screen_Wait destructor
// probe 2: /GX EH, delete panels, loop through settingText array

class TPanel;
class TTextPanel;

void TPanel_delete_panel(void* self, TPanel** target);
void TScreenPanel_dtor(void* self);

class TRIBE_Screen_Wait {
public:
    TPanel* message;
    TPanel* close_button;
    TTextPanel* scenarioName;
    TTextPanel* settingText[20];

    void dtor();
};

void TRIBE_Screen_Wait::dtor() {
    TPanel_delete_panel(this, &message);
    TPanel_delete_panel(this, &close_button);
    TPanel_delete_panel(this, (TPanel**)&scenarioName);
    for (int i = 0; i < 20; i++) {
        TPanel_delete_panel(this, (TPanel**)&settingText[i]);
    }
    TScreenPanel_dtor(this);
}
