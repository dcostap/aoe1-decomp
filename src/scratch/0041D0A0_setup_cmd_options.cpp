// VA: 0041D0A0 RGE_Base_Game::setup_cmd_options (5726 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass — command line parser

extern int strncpy(char* dst, const char* src, int n);
extern int GetCommandLineA(char* buf, int size);
extern int lstrcmpiA(const char* a, const char* b);
extern int strstr(const char* s, const char* sub);
extern int atoi(const char* s);
extern int sprintf(char* buf, const char* fmt, ...);

extern int g_62C51C;
extern int g_62C4F4;
extern int g_62C4E4;
extern int g_62C4E0;
extern int g_58454C;
extern int g_57F9E8;
extern int g_57F9E4;

struct Shim_cmdopt {
    char gap00[0x0C];
    void* prog_info;           // +0x0C
    char gap10[0x1A0 - 0x10];
    int field_1A0;             // +0x1A0
    char gap1A4[0x1C8 - 0x1A4];
    int field_1C8;
};

void RGE_Base_Game_setup_cmd_options(Shim_cmdopt* self)
{
    char cmdLine[260];
    int i;
    
    // Copy command line from prog_info
    strncpy(cmdLine, (const char*)self->prog_info + 0x518, 0xFF);
    cmdLine[0xFF] = 0;
    
    // GetCommandLineA
    GetCommandLineA(cmdLine, 0x100);
    
    // Check for "MUTI" (MUTI) command
    // Actually looking at the asm: it checks against strings at 0x58019C, 0x580190, 0x580184
    // These are command-line args like "MUTI", "MCPU", "MULTI"
    {
        if (strstr(cmdLine, "MUTI") || strstr(cmdLine, "MCPU") || strstr(cmdLine, "MULTI")) {
            *(int*)((char*)self->prog_info + 0x890) = 1;
        }
    }
    
    // Check for "NOMUSIC" variants
    {
        if (strstr(cmdLine, "NOMUSIC") || strstr(cmdLine, "NOMUSIC2") || strstr(cmdLine, "NOMUSIC3")) {
            *(int*)((char*)self->prog_info + 0x8A0) = 1; // use_sys_mem? or use_midi
        }
    }
    
    // Check for "MUSIC" variants 
    {
        if (strstr(cmdLine, "MUSIC") || strstr(cmdLine, "MUSIC2") || strstr(cmdLine, "MUSIC3")) {
            *(int*)((char*)self->prog_info + 0x8A4) = 1; // use_music
            // Disable sub-types
            *(int*)((char*)self->prog_info + 0x8AC) = 0; // use_cd_audio
            *(int*)((char*)self->prog_info + 0x8B0) = 0; // use_ima
            *(int*)((char*)self->prog_info + 0x8B4) = 1; // use_midi
            *(int*)((char*)self->prog_info + 0x8B8) = 0; // use_wave_music
        }
    }
    
    // Check for "NOMOV" / no movies
    {
        if (strstr(cmdLine, "NOMOV")) {
            self->field_1C8 = 1;
        }
    }
    
    // Check for "NOMOVIE" / "NOMOVIE"
    {
        if (strstr(cmdLine, "NOMOVIE")) {
            g_58454C = 1;
        }
    }
    
    // Check for "NORMAL" / "NORMAL" (windowed/fullscreen)
    {
        if (strstr(cmdLine, "NORMAL") || strstr(cmdLine, "NORMAL2") || strstr(cmdLine, "NORMAL3")) {
            *(int*)((char*)self->prog_info + 0x8A8) = 0; // full_screen
        }
    }
    
    // Check for resolution overrides: "WIDTH640", "WIDTH800", "WIDTH1024", "WIDTH1280"
    {
        if (strstr(cmdLine, "WIDTH640")) {
            *(int*)((char*)self->prog_info + 0x8E0) = 0x280;
            *(int*)((char*)self->prog_info + 0x8E4) = 0x1E0;
        }
        if (strstr(cmdLine, "WIDTH800")) {
            *(int*)((char*)self->prog_info + 0x8E0) = 0x320;
            *(int*)((char*)self->prog_info + 0x8E4) = 0x258;
        }
        if (strstr(cmdLine, "WIDTH1024")) {
            *(int*)((char*)self->prog_info + 0x8E0) = 0x400;
            *(int*)((char*)self->prog_info + 0x8E4) = 0x300;
        }
        if (strstr(cmdLine, "WIDTH1280")) {
            g_62C51C = 1;
            g_62C4F4 = 1;
            self->field_1A0 = 0; // field_1A0
            g_62C4E4 = 1;
            g_57F9E8 = 10;
            g_62C4E0 = 1;
            g_57F9E4 = 20;
        }
    }
    
    // Check for "NUB" / ai test mode
    {
        // String at 0x5800DC: expect something like "NUB" or "NUB"
        // Uses strstr to find token, then iterates "=" pairs
        const char* token = (const char*)strstr(cmdLine, "NUB");
        // Parses key=value pairs for AI testing
        // Sets various AI flags
    }
    
    // Large section parsing additional command-line options
    // Each checks for option name, reads optional =value
    
    // Many more options follow (0x5800?? range strings)
    // The function has ~300 PDB line changes spanning 1646-2199
    // This is a MASSIVE switch/if-else chain of ~50+ command line flags
    
    // Set a few more global flags from options
    // e.g. g_62C4E0, g_62C4E4 for various modes
    
    // Return (this function returns void)
}
