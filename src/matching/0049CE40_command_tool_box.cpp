class RGE_Base_Game { public: int multiplayerGame(); virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(int a,int b); };
extern RGE_Base_Game* rge_base_game;
class RGE_Panel_Tool_Box { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(int mode); char pad_04[0x6C-4]; void* field_6C; };
class TRIBE_Screen_Game { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(int mode);
    virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(int a, int b);
    char pad_04[0x14-4]; int field_14; int field_18; char pad_1C[0x57C-0x1C]; RGE_Panel_Tool_Box* tool_box;
    void command_tool_box(); };
void TRIBE_Screen_Game::command_tool_box() {
    if (rge_base_game->multiplayerGame() == 0) {
        RGE_Panel_Tool_Box* tb = this->tool_box;
        if (tb->field_6C != 0) tb->vf14(0); else tb->vf14(1);
        this->vf50(this->field_14, this->field_18);
        rge_base_game->vf10(0, 0);
        this->vf20(1);
    }
}
