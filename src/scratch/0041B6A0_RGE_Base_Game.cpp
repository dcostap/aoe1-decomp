// VA: 0041B6A0 RGE_Base_Game::RGE_Base_Game (988 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass

extern void setVersion(void* self, float v);
extern void setScenarioGame(void* self, int v);
extern void setCampaignGame(void* self, int v);
extern void setSavedGame(void* self, int v);
extern void setSinglePlayerGame(void* self, int v);
extern void setMultiplayerGame(void* self, int v);
extern void setMapSize(void* self, int a, int b, int c);
extern void setAllowCheatCodes(void* self, int v);
extern void setCheatNotification(void* self, int v);
extern void setFullVisibility(void* self, int v);
extern void setFogOfWar(void* self, int v);
extern void setColoredChat(void* self, int v);
extern void setGameDeveloperMode(void* self, int v);
extern void setDifficulty(void* self, int v);
extern void setPlayerCDAndVersion(void* self, int idx, int v);
extern void setPlayerHasCD(void* self, int idx, int v);
extern void setPlayerVersion(void* self, int idx, int v);
extern void setPlayerTeam(void* self, int idx, int v);
extern void setPathFinding(void* self, unsigned char v);
extern void setMpPathFinding(void* self, unsigned char v);
extern void setNumberPlayers(void* self, int v);
extern void setScenarioName(void* self, const char* name);
extern int setup_registry(void* self);
extern int setup_debugging_log(void* self);
extern int setup(void* self);
extern void* LoadCursorA(void* inst, int id);
extern int GetCurrentDirectoryA(int size, char* buf);

extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name;
extern int draw_log;
extern int g_592A58; // AppInst
extern int g_62C4FCh;
extern int g_62C4B8; // chat
extern int g_62C4C0; // comm
extern int g_62C4A8; // Regs
extern int g_62C4B0; // sound_driver
extern int g_5B215Ch; // driveInfo
extern int g_62C4A0; // StringTable?

struct Shim_1B6A0_A {
    char gap00[4];
    int field_4;     // +0x04
    int field_8;     // +0x08
    void* prog_info; // +0x0C
    void* prog_window; // +0x10
    int field_14;    // +0x14
    int field_18;    // +0x18
    int field_1C;    // +0x1C
    int field_20;    // +0x20
    int field_24;    // +0x24
    int field_28;    // +0x28 (0xFFFFFFFF)
    int field_2C;    // +0x2C
    int field_30;    // +0x30
    int field_34;    // +0x34
    int field_38;    // +0x38
    int field_3C;    // +0x3C
    int error_code;  // +0x40
    int field_44;    // +0x44
    void* draw_system; // +0x48
    void* draw_area; // +0x4C
    unsigned char field_50; // +0x50 (2)
    char gap51[3];
    int mouse_inactive; // +0x54
    int field_58;    // +0x58 (short)
    void* shapes;    // +0x5C
    void* sound_system; // +0x60
    void* music_system; // +0x64
    short field_68;  // +0x68
    char gap6A[2];
    int field_6C;
    unsigned char field_70;
    char gap71[3];
    int field_74;
    int field_78;
    int field_7C;
    unsigned char field_80;
    char gap81[0x184 - 0x81];
    int field_184;
    int field_188;
    void* comm_handler; // +0x18C
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;    // +0x1A4
    int field_1A8;    // +0x1A8
    void* registry;   // +0x1AC
    int game_mode;    // +0x1B0
    int field_1B4;
    int field_1B8;
    int field_1BC;
    void* mouse_pointer; // +0x1C0
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    short field_1E0;
    int field_1E4;
    char work_dir[0x100]; // +0x1E8
    char language_dll[0x100]; // +0x2E8 (2ED)
};

void* RGE_Base_Game_ctor(Shim_1B6A0_A* self, void* prog_info, int param2)
{
    int i;
    
    self->field_4 = 0;
    self->field_28 = -1;
    self->field_2C = -1;
    self->field_30 = -1;
    self->field_34 = -1;
    *(int*)((char*)self + 0x9A8) = 0;
    *(void**)self = (void*)0x56EED0; // vtable
    
    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name = 0;
    draw_log = 0;
    
    setVersion(self, 3.0f);
    setScenarioGame(self, 0);
    setCampaignGame(self, 0);
    setSavedGame(self, 0);
    setSinglePlayerGame(self, 1);
    setMultiplayerGame(self, 0);
    setMapSize(self, 0x60, 0x60, 8);
    setAllowCheatCodes(self, 0);
    setCheatNotification(self, 1);
    setFullVisibility(self, 0);
    setFogOfWar(self, 1);
    setColoredChat(self, 1);
    setGameDeveloperMode(self, 0);
    setDifficulty(self, 0);
    
    // Player loop (0-8)
    for (i = 0; i < 9; i++) {
        setPlayerCDAndVersion(self, i, 0);
        setPlayerHasCD(self, i, 0);
        setPlayerVersion(self, i, 0);
        setPlayerTeam(self, i, 1);
    }
    
    setPathFinding(self, 0);
    setMpPathFinding(self, 0);
    setNumberPlayers(self, 4);
    setScenarioName(self, "");
    
    // globals
    extern void* rge_base_game;
    rge_base_game = self;
    
    self->prog_info = prog_info;
    self->prog_window = 0;
    self->field_14 = 0;
    self->field_18 = 1;
    self->field_1C = 0;
    self->field_24 = 0;
    g_62C4A0 = 0;
    self->field_38 = 0;
    self->error_code = 0;
    self->field_44 = 0;
    self->draw_system = 0;
    self->draw_area = 0;
    self->field_50 = 2;
    self->mouse_inactive = 0;
    *(int*)((char*)self + 0x5C) = 0;
    self->sound_system = 0;
    self->music_system = 0;
    self->field_68 = 0;
    self->field_6C = 0;
    self->field_70 = 0;
    self->field_74 = 0;
    self->field_78 = 0;
    self->field_7C = 0;
    self->field_80 = 0;
    self->field_184 = 0;
    self->field_188 = 0;
    self->comm_handler = 0;
    self->field_1A4 = 0;
    self->field_1A8 = 0;
    self->field_190 = 0;
    self->field_198 = 0;
    self->field_19C = 0;
    self->field_1A0 = 1;
    self->field_194 = 0;
    self->registry = 0;
    self->game_mode = 0;
    self->field_1B4 = 0;
    self->field_1B8 = 0;
    self->field_1BC = 0;
    self->mouse_pointer = 0;
    self->field_1C4 = 0;
    self->field_1C8 = 0;
    self->field_1CC = 1;
    self->field_1D0 = 1;
    
    self->field_1D4 = (int)LoadCursorA(0, 0x7F00);
    
    self->field_1E0 = 0;
    self->field_1E4 = 0;
    GetCurrentDirectoryA(0x105, self->work_dir);
    
    // Copy "language.dll" into +0x2ED
    {
        const char* src = "language.dll";
        char* dst = self->language_dll;
        int slen;
        for (slen = 0; src[slen]; slen++);
        for (i = 0; i <= slen; i++)
            dst[i] = src[i];
    }
    
    // +0x3FC = -1 (short)
    *(short*)((char*)self + 0x3FC) = -1;
    *(short*)((char*)self + 0x3FE) = -1;
    *(short*)((char*)self + 0x400) = -1;
    
    *(int*)((char*)self + 0x3F4) = 0;
    *(int*)((char*)self + 0x3F8) = 1;
    *(short*)((char*)self + 0x402) = 1;
    *(unsigned char*)((char*)self + 0x404) = 0;
    
    // Initialize timing slots
    *(int*)((char*)self + 0x504) = 0;
    *(int*)((char*)self + 0x508) = 0;
    *(int*)((char*)self + 0x50C) = 0;
    *(int*)((char*)self + 0x510) = 0;
    *(int*)((char*)self + 0x514) = 0;
    *(int*)((char*)self + 0x518) = 0;
    *(int*)((char*)self + 0x51C) = 0;
    *(int*)((char*)self + 0x520) = 0;
    *(int*)((char*)self + 0x524) = 0;
    *(int*)((char*)self + 0x8F4) = 0;
    
    // Clear 30 timing slots (each 0x20 bytes), starting at +0x528, array starting at +0x52C
    {
        int* p = (int*)((char*)self + 0x52C);
        int j;
        for (j = 0; j < 30; j++) {
            *(p - 1) = 0;
            p[0] = 0;
            p[1] = 0;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            p[2] = 0;
            p[3] = 0;
            p += 8;
        }
    }
    
    *(int*)((char*)self + 0x8E8) = 0;
    *(int*)((char*)self + 0x8EC) = 0;
    *(int*)((char*)self + 0x8F0) = 0;
    *(int*)((char*)self + 0x9AC) = 1;
    g_62C4FCh = 0;
    
    g_592A58 = *(int*)((char*)prog_info + 0x410);
    
    g_5B215Ch = 0;
    g_62C4B8 = 0;
    g_62C4C0 = 0;
    g_62C4A8 = 0;
    g_62C4B0 = 0;
    g_5B215Ch = 0;
    
    self->field_8 = 0;
    
    // Per-player global arrays init (9 elements)
    {
        int* p_base = (int*)((char*)self + 0x9B0);
        for (i = 0; i < 9; i++) {
            p_base[i] = 0;
            *(unsigned char*)((char*)self + 0xA15 + i) = 0;
        }
    }
    
    *(int*)((char*)self + 0x9FC) = 0;
    *(int*)((char*)self + 0xA08) = 1;
    *(int*)((char*)self + 0xA20) = 0;
    *(int*)((char*)self + 0xA0C) = 0x3F800000; // 1.0f
    *(int*)((char*)self + 0xA10) = 2;
    
    if (!setup_registry(self)) {
        self->error_code = 0x0E;
        return self;
    }
    
    g_62C4A8 = (int)self->registry;
    
    if (!setup_debugging_log(self)) {
        self->error_code = 0x0F;
        return self;
    }
    
    g_62C4FCh = self->field_1A4;
    
    if (param2) {
        if (!setup(self))
            if (!self->error_code)
                self->error_code = 1;
    }
    
    *(int*)((char*)self + 0x9D4) = 0;
    
    return self;
}
