#ifndef RGE_VIEW_SHARED_CONTEXT
class TMousePointer {
public:
    void set_game_enable(int enabled);
};

extern TMousePointer* MouseSystem;

class TPanel {
public:
    void set_focus(int focus);
};

class RGE_View {
protected:
    char gap_04[0x74];
    int game_enable;

    virtual void set_focus(int focus);
};
#endif

void RGE_View::set_focus(int focus) {
    this->TPanel::set_focus(focus);
    if (MouseSystem != 0) {
        MouseSystem->set_game_enable(game_enable);
    }
}
