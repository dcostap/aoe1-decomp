// Attempt log:
// Function signature based on assembly analysis
// 
// Key findings:
// - param_1 is accessed as [param_1 + 0x238] to get logging module
// - This means param_1 is an object pointer, NOT a format string
// - Ghidra decompiler incorrectly shows char* param_1
// - Actual signature: void logMessage(void* obj_ptr, char* format, ...)
//
// MISMATCH NOTES:
// - Original: 81 bytes, loads param from [esp+408h] AFTER buffer allocation
// - Compiled: 80 bytes, loads param from [esp+4] BEFORE buffer allocation
// - This is a compiler optimization difference
// - Cannot prevent without inline asm (forbidden by project rules)
// - Functionally equivalent but byte-identical: NO
//
// STATUS: Paused in scratch due to byte-identical mismatch

#include <stdarg.h>
#include <stdio.h>

class AIModule {
public:
    void logCommonHistory(char* module, char* message);
};

extern "C" int __cdecl vsprintf(char* buffer, const char* format, va_list argptr);

void logMessage(void* obj_ptr, char* format, ...) {
    char textOut[1024];
    
    // Get the logging module from the object at offset 0x238
    void* loggingModule = *(void**)((char*)obj_ptr + 0x238);
    
    if (loggingModule != 0) {
        va_list args;
        va_start(args, format);
        
        // vsprintf writes to textOut + 4
        vsprintf(textOut + 4, format, args);
        
        va_end(args);
        
        // Call logCommonHistory with the formatted message
        ((AIModule*)loggingModule)->logCommonHistory((char*)loggingModule, textOut + 4);
    }
}
