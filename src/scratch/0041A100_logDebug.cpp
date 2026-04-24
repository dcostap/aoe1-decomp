#include <stdio.h>
extern "C" int __cdecl vsprintf(char* dest, const char* fmt, char* args);

// compact debug logger first
// tried va_start/va_end and a direct stack-address cast for the varargs pack; mismatch stayed on the vsprintf arg-list stack slot
// current lead: the function is otherwise right; the remaining drift is the local-stack shape around the vsprintf call
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
        vsprintf(textOut + 4, param_1, (char*)&param_1 + 4);
        ((void (*)(RGE_Static_Object*, char*))(*(void***)this->objectValue)[0x144 / 4])(this->objectValue, textOut + 4);
    }
}
