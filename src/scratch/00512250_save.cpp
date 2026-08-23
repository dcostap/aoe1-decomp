// VA: 00512250 TRIBE_Player::save
// Straight save-order source from tplayer.cpp packet; parameter stack slot is
// intentionally reused as the one/zero presence flag, matching VC5's write to
// [esp+0Ch] while the original file handle stays in EDI.

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void __cdecl rge_write(int file, void* data, int size);

class RGE_Player {
public:
    virtual void vf00();
    void save(int file);
};

class TRIBE_Tech {
public:
    void save(int file);
};

class TRIBE_Player_Other {
public:
    void save(int file);
};

class TCommunications_Handler {
public:
    int checkSomething(void);
};

extern TCommunications_Handler* communications_handler;

class ScenarioObject {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void save(int file);
};

class TRIBE_Player : public RGE_Player {
public:
    char pad_04[0x48 - 0x04];
    unsigned char byte_48;
    char pad_49[0x220 - 0x49];
    TRIBE_Tech* tech;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    ScenarioObject* scenario_object;
    char pad_23C[0x83C - 0x23C];
    TRIBE_Player_Other* other;
    int field_840;
    int field_844;

    void save(int file);
};

void TRIBE_Player::save(int file) {
    int save_file;

    color_log(0x16, 0x16, 2);
    save_file = file;
    RGE_Player::save(save_file);
    color_log(0x16, 0x24, 2);

    rge_write(save_file, &byte_48, 1);
    rge_write(save_file, &field_228, 4);
    rge_write(save_file, &field_230, 4);
    rge_write(save_file, &field_224, 4);
    rge_write(save_file, &field_234, 4);
    tech->save(save_file);
    rge_write(save_file, &field_22C, 4);
    other->save(save_file);
    rge_write(save_file, &field_840, 4);
    rge_write(save_file, &field_844, 4);

    color_log(0x16, 0x4C, 2);
    if (*(int*)((char*)this + 4) == 1) {
        if (scenario_object != 0 && communications_handler->checkSomething() == 1) {
            file = 1;
            rge_write(save_file, &file, 4);
            scenario_object->save(save_file);
        } else {
            file = 0;
            rge_write(save_file, &file, 4);
        }
    }

    color_log(0x16, 0x5F, 2);
}
