// VA: 0041F030 RGE_Base_Game::setup_sound_system (224 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: check use_sound, alloc TSound_Driver, ctor, active check, set volume

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int TSound_Driver_ctor(void* driver, void* hwnd, const char* dir);
extern int TSound_Driver_dtor(void* driver);
extern int TSound_Driver_active(void* driver);
extern int Registry_GetInt(void* registry, int def, const char* key);
extern void Sound_Driver_set_volume(void* driver, int vol);
extern void BaseGame_virtual_call(void* self);

struct Shim_0041F030 {
    char pad0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char pad14[0x1AC - 0x14];
    void* registry;            // +0x1AC
    char pad1B0[0x60 - 0x1B0];
    void* sound_system;        // +0x60
};

int RGE_Base_Game_setup_sound_system(Shim_0041F030* self)
{
    void* driver;
    void* info;
    int active;
    
    info = self->prog_info;
    if (*(int*)((char*)info + 0x8A8) == 0)
        return 1;
    
    driver = operator_new(0x69C);
    if (driver)
        TSound_Driver_ctor(driver, self->prog_window, (char*)info + 0xE21);
    
    self->sound_system = driver;
    if (driver) {
        active = TSound_Driver_active(driver);
        if (active == 0) {
            if (self->sound_system) {
                TSound_Driver_dtor(self->sound_system);
                operator_delete(self->sound_system);
            }
            self->sound_system = 0;
            return 1;
        }
    }
    
    *(void**)0x62C4B0 = self->sound_system;
    Registry_GetInt(self->registry, 1, "Sound_Volume");
    if (self->sound_system)
        Sound_Driver_set_volume(self->sound_system, 1);
    
    return 1;
}
