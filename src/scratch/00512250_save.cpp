// VA: 00512250 TRIBE_Player::save
// Straight save-order source from tplayer.cpp packet; parameter stack slot is
// intentionally reused as the one/zero presence flag, matching VC5's write to
// [esp+0Ch] while the original file handle stays in EDI.

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void __cdecl rge_write(int file, void* data, int size);

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
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
    virtual void load(); virtual void initialize(); virtual void setup(); virtual void clear();
    virtual void reset(); virtual void update(); virtual void save_info(); virtual void load_info();
    virtual void scenario_save(); virtual void scenario_load(); virtual void scenario_postload();
    virtual void set_player(); virtual void set_object(); virtual void set_state();
    virtual void destroy(); virtual void save(int file);
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
#endif

extern TCommunications_Handler* communications_handler;

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
