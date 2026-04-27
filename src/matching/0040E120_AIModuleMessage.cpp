// 0040E120 AIModuleMessage::~AIModuleMessage
// Source: aimodule.cpp lines 110-113
// public: virtual __thiscall AIModuleMessage::~AIModuleMessage(void)
//
// Attempt log:
// Probe 1: natural delete callbackShape + implicit member destruction, default flags
//   -> 96 bytes vs 110, missing EH prolog
// Probe 2: Added /GX per-function rsp, removed explicit vtable_ptr fields (conflicting with virtual keyword)
//   -> EXACT MATCH (0.0000%). /GX needed for EH prolog, implicit vptr from virtual keyword correct.
//
// Key lesson: do NOT declare explicit vtable_ptr when using virtual keyword — VC5
// adds the implicit vptr, and having both shifts all field offsets by +4.

#include "..\..\include\game_globals.h"

// AIModuleID size 0x48 (from inventory types dump)
// vtable_ptr is implicit via virtual destructor — do NOT declare it as a field
class AIModuleID {
public:
    int id;            // +0x4 (4)
    char name[64];     // +0x8 (0x40)

    virtual ~AIModuleID();
};

// AIModuleMessage size 0x138 (from inventory types dump)
// vtable_ptr is implicit — do NOT declare it as a field
class AIModuleMessage {
public:
    int id;                        // +0x4 (4)
    char text[128];                // +0x8 (0x80)
    int priority;                  // +0x88 (4)
    AIModuleID sender;             // +0x8C (0x48)
    AIModuleID recipient;          // +0xD4 (0x48)
    long data1;                    // +0x11C (4)
    long data2;                    // +0x120 (4)
    long data3;                    // +0x124 (4)
    AIModuleMessage* callbackMessage; // +0x128 (4)
    int timeStamp;                 // +0x12C (4)
    AIModuleMessage* next;         // +0x130 (4)
    AIModuleMessage* prev;         // +0x134 (4)

    virtual ~AIModuleMessage();
};

AIModuleMessage::~AIModuleMessage()
{
    delete this->callbackMessage;
}
