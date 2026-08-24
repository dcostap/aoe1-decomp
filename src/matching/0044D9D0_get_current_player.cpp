#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Game_Info {
public:
    int field_0;
    int get_current_player();
};
#endif

int RGE_Game_Info::get_current_player() { return this->field_0; }
