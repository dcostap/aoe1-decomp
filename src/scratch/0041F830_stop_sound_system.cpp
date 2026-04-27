// VA: 0041F830 RGE_Base_Game::stop_sound_system (229 B)
// PDB source: basegame.cpp
// Packet-grounded: stop Chat, stop PanelSystem, restart world sounds, delete digital sounds, save volume, delete driver

extern void Chat_StopSoundSystem(int chat);
extern void TPanelSystem_stop_sound_system(int panel_sys);
extern void RGE_Sound_restart_sound(int sound, int driver);
extern void TDigital_dtor(int digital);
extern void operator_delete(void* p);
extern int free(void* p);
extern long TSound_Driver_get_volume(int driver);
extern int RegSetInt(void* registry, int val, const char* key, int data);
extern void TSound_Driver_dtor(int driver);

extern int chat_global;              // chat 62C4B8
extern int panel_system;           // 62E870
extern int sound_driver_addr;       // 62C4B0

struct Shim_1F830 {
    void* vtable;
    char p4[0x60 - 4];
    int sound_system;          // +0x60
    char p64[0x68 - 0x64];
    short sound_num;             // +0x68 (word)
    char p6A[0x6C - 0x6A];
    int* sounds;               // +0x6C (array of int pointers)
    char p70[0x1AC - 0x70];
    void* registry;              // +0x1AC
    char p1B0[0x3F4 - 0x1B0];
    int world;                 // +0x3F4
};

void RGE_Base_Game_stop_sound_system(Shim_1F830* self)
{
    int i;
    int snd;
    int w;
    
    if (chat_global)
        Chat_StopSoundSystem(chat_global);
    
    TPanelSystem_stop_sound_system(panel_system);
    
    w = self->world;
    if (w) {
        i = 0;
        while (i < *(short*)(w + 0x2C)) {
            RGE_Sound_restart_sound(
                *(int*)(*(int*)(w + 0x30) + i * 4), 0);
            i++;
        }
    }
    
    if (self->sounds) {
        for (i = 0; i < self->sound_num; i++) {
            snd = self->sounds[i];
            if (snd) {
                TDigital_dtor(snd);
                operator_delete((void*)snd);
            }
        }
        free(self->sounds);
        self->sounds = 0;
    }
    
    ((void(*)(void*))((int*)self)[0x5C/4])(self);  // virtual vt+0x5C
    
    if (self->sound_system) {
        RegSetInt(
            self->registry,
            1, "Sound Volume",
            -TSound_Driver_get_volume(self->sound_system));
        
        if (self->sound_system) {
            TSound_Driver_dtor(self->sound_system);
            operator_delete((void*)self->sound_system);
        }
        self->sound_system = 0;
        sound_driver_addr = 0;
    }
}
