// 00509490 TTaunt::PlayTauntStr
// Source: taunt.cpp lines 30-56
// Size: 156 bytes, no EH
//
// Attempt log:
// Probe 1: hardcoded lengths, 3 register saves -> 128 bytes, missing ebp push
// Probe 2-3: class layout issues + runtime strlen -> different structure
// Prior GIVEUP: codegen basin (register allocation for 4 callee-saves, strlen vs hardcoded, shared epilogue)
// Fresh pass 2026-05-19:
// try 1: natural implementation with strlen globals and int result local.

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);

extern const char DAT_00576548[];
extern const char DAT_00576550[];

#ifndef AOE1_TAUNT_CONTEXT_H
class TTaunt {
public:
    char gap_000[0x194];
    int Mute;

    int GetTauntNo(char* str);
    int PlayTauntNo(int taunt_no);
    int PlayTauntStr(char* str, unsigned char allow_mute);
};
#endif

int TTaunt::PlayTauntStr(char* str, unsigned char allow_mute)
{
    int taunt_no;

    if (_strnicmp(str, DAT_00576548, strlen(DAT_00576548)) == 0 && allow_mute) {
        this->Mute = 1;
    }

    if (_strnicmp(str, DAT_00576550, strlen(DAT_00576550)) == 0 && allow_mute) {
        this->Mute = 0;
    }

    if (this->Mute) {
        return 0;
    }

    taunt_no = this->GetTauntNo(str);
    if (taunt_no) {
        this->PlayTauntNo(taunt_no);
    }
    return taunt_no;
}
