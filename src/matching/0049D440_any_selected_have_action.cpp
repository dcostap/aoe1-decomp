// VA: 0049D440 TRIBE_Screen_Game::any_selected_have_action (101 B)
// PDB source: scr_game.cpp lines 5882-5902

#if !defined(SCR_GAME_TU_CONTEXT)
extern void* rge_base_game;
#endif
extern void* __fastcall get_player(void* game);
extern unsigned char __fastcall have_action(void* obj);

#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Screen_Game {
public:
    int any_selected_have_action();
};
#endif

int TRIBE_Screen_Game::any_selected_have_action() {
    void* player = get_player(rge_base_game);
    void** sel_list = (void**)((char*)player + 0x134);
    int slot = 0;
    int index = 0;
    while (slot < 25) {
        short count = *(short*)((char*)player + 0x19C);
        if (index >= count) {
            return 0;
        }
        void* obj = *sel_list;
        if (obj != 0) {
            unsigned char type = *(unsigned char*)((char*)(*(void**)((char*)obj + 8)) + 4);
            if (type >= 0x28 && type <= 0x50) {
                if (have_action(obj)) {
                    return 1;
                }
            }
            index++;
        }
        slot++;
        sel_list++;
    }
    return 0;
}
