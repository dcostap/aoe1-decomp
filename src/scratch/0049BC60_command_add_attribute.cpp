class RGE_Player {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void command_add_attribute(int param_1, float param_2);
};

class RGE_Base_Game {
public:
    int get_paused(void);
    int allowCheatCodes(void);
    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

void __stdcall command_add_attribute(int param_1) {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->allowCheatCodes() != 0) {
            RGE_Player* player = rge_base_game->get_player();
            player->command_add_attribute(param_1, 1000.0f);
        }
    }
}
