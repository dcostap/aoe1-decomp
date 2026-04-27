// VA: 0041F400 RGE_Base_Game::setup_sounds (347 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: calloc digital array, alloc 3 TDigitals (button1.wav, button2.wav, chatrcvd.wav), load each

extern void* calloc(int num, int size);
extern void* operator_new(unsigned int size);
extern int TDigital_ctor(void* dig, void* sound_driver, const char* name, int id);
extern int TDigital_load(void* dig, const char* param, int val);

struct Shim_1F400 {
    char p0[0x60];
    void* sound_system;        // +0x60
    char p64[0x68 - 0x64];
    short sound_num;           // +0x68 (word)
    char p6A[0x6C - 0x6A];
    void** sounds;             // +0x6C
};

int RGE_Base_Game_setup_sounds(Shim_1F400* self)
{
    void* d;
    void** arr;
    int i;
    
    self->sound_num = 3;
    arr = (void**)calloc(3, 4);
    self->sounds = arr;
    if (!arr)
        return 0;
    
    for (i = 0; i < self->sound_num; i++)
        arr[i] = 0;
    
    d = operator_new(0x3C);
    if (d)
        TDigital_ctor(d, self->sound_system, "button1.wav", 0xC47C);
    self->sounds[0] = d;
    
    d = operator_new(0x3C);
    if (d)
        TDigital_ctor(d, self->sound_system, "button2.wav", 0xC47D);
    self->sounds[1] = d;
    
    d = operator_new(0x3C);
    if (d)
        TDigital_ctor(d, self->sound_system, "chatrcvd.wav", 0xC47E);
    self->sounds[2] = d;
    
    for (i = 0; i < self->sound_num; i++) {
        if (self->sounds[i])
            TDigital_load(self->sounds[i], 0, -1);
    }
    
    return 1;
}
