#include <stdio.h>
extern "C" int __cdecl vsprintf(char* dest, const char* fmt, char* args);

// compact debug logger first
// tried va_start/va_end and a direct stack-address cast for the varargs pack; mismatch stayed on the vsprintf arg-list stack slot
// tried changing textOut+4 to textOut (both vsprintf dest and virtual call arg); original uses plain textOut, not textOut+4
// MATCHED: changed textOut+4 to textOut in both vsprintf dest and virtual call arg — original uses plain textOut
class RGE_Static_Object {
public:
    void* vtable_ptr;
};

class UnitAIModule {
public:
    void* vtable_ptr;
    RGE_Static_Object* objectValue;

    void logDebug(char* param_1, ...);
};

void UnitAIModule::logDebug(char* param_1, ...) {
    char textOut[1024];
    if (this->objectValue != 0) {
        vsprintf(textOut, param_1, (char*)&param_1 + 4);
        ((void (*)(RGE_Static_Object*, char*))(*(void***)this->objectValue)[0x144 / 4])(this->objectValue, textOut);
    }
}
