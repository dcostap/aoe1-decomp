// attempt 1: compile error on manual vtable call
// attempt 2: member offsets wrong, delete adds extra code
// attempt 3: operator delete, 80 bytes
// attempt 4-5: more cast errors
// attempt 6: virtual method at 0 offset, still 80 bytes
// attempt 7: try with padding virtuals

class TRegistry;

class TMusic_System {
public:
    char gap_00[0x254];
    int volume;

    ~TMusic_System();
};

class TRegistry {
public:
    int RegSetInt(int type, const char* name, int value);
};

void operator delete(void* p);

class RGE_Base_Game {
public:
    void* _vftable;
    char gap_04[0x5C];
    TMusic_System* music_system;
    char gap_68[0x144];
    TRegistry* registry;

    virtual void vf_0();
    virtual void vf_4();
    virtual void vf_8();
    virtual void vf_c();
    virtual void vf_10();
    virtual void vf_14();
    virtual void vf_18();
    virtual void vf_1c();
    virtual void vf_20();
    virtual void vf_24();
    virtual void vf_28();
    virtual void vf_2c();
    virtual void vf_30();
    virtual void vf_34();
    virtual void vf_38();
    virtual void vf_3c();
    virtual void vf_40();
    virtual void vf_44();
    virtual void vf_48();
    virtual void vf_4c();
    virtual void vf_50();
    virtual void vf_54();
    virtual void vf_58();
    virtual void vf_5c();
    virtual void vf_60();
    virtual void vf_64();
    virtual void vf_68();
    virtual void vf_6c();
    virtual void vf_70();
    virtual void vf_74();
    virtual void vf_78();
    virtual void vf_7c();
    virtual void vf_80();
    virtual void vf_84();
    virtual void vf_88();
    virtual void vf_8c();
    virtual void vf_90();
    virtual void vf_94();
    virtual void vf_98();
    virtual void vf_9c();
    virtual void vf_a0();
    virtual void vf_a4();
    virtual void vf_a8();
    virtual void virtual_ac();
    void shutdown_music_system();
};

void RGE_Base_Game::shutdown_music_system() {
    if (music_system == 0) return;
    virtual_ac();
    registry->RegSetInt(1, "Music Volume", -music_system->volume);
    TMusic_System* p = music_system;
    if (p != 0) {
        p->~TMusic_System();
        operator delete(p);
    }
    music_system = 0;
}
