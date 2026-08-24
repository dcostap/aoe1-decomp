#ifndef AOE1_TAUNT_CONTEXT_H
#define AOE1_TAUNT_CONTEXT_H

// Authentic source-module context for C:\\msdev\\work\\age1_x1\\taunt.cpp.
// Owner bodies are included by src/taunt_tu.cpp in PDB source-line order.

class TSound_Driver;

class TDigital {
public:
    char _gap_00[0x3C];

    TDigital(TSound_Driver* driver, const char* name, int flag);
    ~TDigital();
    int is_playing();
    void unload();
    int load(char* name, long param);
    int play();
};

class TTaunt {
public:
    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    union {
        char TauntDir[128];
        char TauntDir_0;
    };
    unsigned char _pad_193;
    int Mute;

    TTaunt(TSound_Driver* sound_driver);
    ~TTaunt();
    int PlayTauntStr(char* str, unsigned char allow_mute);
    int PlayTauntNo(int num);
    int GetTauntNo(char* text);
    char* GetTauntText(int id);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* driver);
};

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl atoi(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);

void __cdecl operator delete(void* ptr);

#endif
