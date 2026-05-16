// VA: 0041F920 RGE_Base_Game::restart_sound_system
// PDB: basegame.cpp lines 2815-2858 (138 bytes, 54 asm lines)
// Default flags.

extern int panel_system;
extern void* chat;

class RGE_Sound_RS {
public:
    void restart_sound(void* driver);
};

class TPanelSystem_RS {
public:
    int restart_sound_system();
};

class TChat_RS {
public:
    int RestartSoundSystem(void* driver);
};

class RGE_Base_Game_RS {
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
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual int vf8C(void);
    virtual void vf90(void);
    virtual int vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);

    char gap_04[0x60 - 4];
    void* sound_system;          // +0x60
    char gap_64[0x3F4 - 0x64];
    void* rge_world;             // +0x3F4

    int restart_sound_system();
};

int RGE_Base_Game_RS::restart_sound_system()
{
    if (this->sound_system != 0)
        goto done;

    if (this->vf8C() == 0)
        return 0;

    if (this->vf94() == 0)
        return 0;

    if (this->rge_world != 0) {
        int i = 0;
        if (*(short*)((char*)this->rge_world + 0x2C) > 0) {
            do {
                ((RGE_Sound_RS*)(*(void**)(*(int*)((char*)this->rge_world + 0x30) + i * 4)))->restart_sound(this->sound_system);
                i++;
            } while (i < (int)(short)*(short*)((char*)this->rge_world + 0x2C));
        }
    }

    ((TPanelSystem_RS*)&panel_system)->restart_sound_system();

    if (chat != 0) {
        ((TChat_RS*)chat)->RestartSoundSystem(this->sound_system);
    }

    this->vfB0();

done:
    return 1;
}
