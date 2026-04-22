class TRIBE_Player;

class TRIBE_Panel_Inven {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    char gap_04[0xF4];
    TRIBE_Player* player;

    void save_info();
    void set_player(TRIBE_Player* player);
};

void TRIBE_Panel_Inven::set_player(TRIBE_Player* player) {
    this->player = player;
    save_info();
    vf20(1);
}
