class RGE_Player {
public:
    int computerPlayer(void);
};

class TRIBE_Action_Hunt {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual int set_state(int value);

    char gap_04[0x04];
    void* object;

    int stop(void);
};

struct HuntObjectPlayerHolder {
    char gap_00[0x0C];
    RGE_Player* player;
};

int TRIBE_Action_Hunt::stop(void) {
    if (((HuntObjectPlayerHolder*)this->object)->player->computerPlayer() == 0) {
        this->set_state(2);
        return 1;
    }
    this->set_state(1);
    return 1;
}
