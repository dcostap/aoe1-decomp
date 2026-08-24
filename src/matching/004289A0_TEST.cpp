// 004289A0 TCommunications_Handler::TEST() — Com_hand.cpp:2276-2300
// Attempt 6: new + explicit dtor/operator_delete + /GX for EH frame

#include <new.h>

class TSound_Driver;

class TTaunt {
public:
    void* Audio[4];         // +0x00 (0x10)
    int LastAudioPlayed;    // +0x10
    char TBuff[255];        // +0x14
    char TauntDir[128];     // +0x113
    unsigned char _pad_0;   // +0x193
    int Mute;               // +0x194

    TTaunt(TSound_Driver* driver);
    int PlayTauntNo(int num);
    ~TTaunt();
};

extern "C" TSound_Driver* sound_driver;
extern "C" void __cdecl operator_delete(void* p);

extern "C" int __cdecl debug_rand(char* file, int line);

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    void Log(char* fmt, ...);  // variadic → __cdecl, this pushed on stack
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern "C" TDebuggingLog* L_global;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    int TEST();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::TEST()
{
    TTaunt* taunt;

    taunt = new TTaunt(sound_driver);

    {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x8F2);
        int log_val = (rand_val * 15) / 0x7FFF;
        L_global->Log("Playing Taunt #%d", log_val);
    }

    taunt->PlayTauntNo(4);

    if (taunt) {
        taunt->~TTaunt();
        operator_delete(taunt);
    }

    return 1;
}
