// VA: 0041F110 RGE_Base_Game::setup_music_system (442 B)
// PDB source: basegame.cpp
// EH-framed (FS:[0] prolog/epilog). Needs /GX rsp for EH frame.
// Packet-grounded structural first-pass

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int TRegistry_RegGetInt(void* reg, int a, const char* name);
extern int TMusic_System_dtor(void* ms);
extern int TMusic_System_ctor(void* ms, unsigned char type, void* inst, void* win, void* sound, const char* path);
extern int TMusic_System_set_music_type(void* ms, unsigned char type);
extern void TMusic_System_set_volume(void* ms, int vol, int flag);
extern int sprintf(char* buf, const char* fmt, ...);

struct Shim_1F110 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char p14[0x60 - 0x14];
    void* sound_system;        // +0x60
    void* music_system;        // +0x64
    char p68[0x1AC - 0x68];
    void* registry;            // +0x1AC
    char p1B0[0x1E8 - 0x1B0];
    char work_dir[32];         // +0x1E8
    char sounds_dir[32];       // roughly
};

int RGE_Base_Game_setup_music_system(Shim_1F110* self)
{
    int vol = -5000;
    
    if (!self->prog_info)
        return 1;
    
    if (!*(int*)((char*)self->prog_info + 0x8A4))
        return 1;
    
    int regVol = TRegistry_RegGetInt(self->registry, 1, "Music Volume");
    if (regVol != -1)
        vol = -regVol;
    
    if (vol < -0x26AB) {
        *(int*)((char*)self->prog_info + 0x8A4) = 0;
        if (self->music_system) {
            TMusic_System_dtor(self->music_system);
            operator_delete(self->music_system);
            self->music_system = 0;
        }
        return 1;
    }
    
    if (self->music_system)
        return 1;
    
    // Determine music type
    unsigned char musicType;
    if (*(int*)((char*)self->prog_info + 0x8AC))
        musicType = 1;
    else if (*(int*)((char*)self->prog_info + 0x8B4))
        musicType = 2;
    else if (*(int*)((char*)self->prog_info + 0x8B0))
        musicType = 4;
    else
        musicType = (-(*(int*)((char*)self->prog_info + 0x8B8) != 0) & 2) + 1;
    
    char pathBuf[260];
    char* soundsDir = (char*)self->prog_info + 0xE21;
    sprintf(pathBuf + 4, "%s\\%s", self->work_dir, soundsDir);
    
    void* ms = operator_new(0x3F8);
    if (ms) {
        TMusic_System_ctor(ms, musicType,
            *(void**)((char*)self->prog_info + 0x410),
            self->prog_window,
            self->sound_system,
            pathBuf + 4);
    }
    
    self->music_system = ms;
    
    if (ms && musicType == 1) {
        if (!*(int*)((char*)self->prog_info + 0x8AC)) {
            if (!*(int*)((char*)ms + 0x114) || *(int*)((char*)ms + 0x248) < 2) {
                if (!TMusic_System_set_music_type(ms, 2))
                    TMusic_System_set_music_type(self->music_system, 3);
            }
        }
    }
    
    if (self->music_system)
        TMusic_System_set_volume(self->music_system, vol, 1);
    
    return 1;
}
