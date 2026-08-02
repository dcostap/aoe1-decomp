// VA: 004C7340 RGE_Static_Object::logDebug
// PDB source: stat_obj.cpp lines 4624-4650
// Attempt log:
// baseline: natural cdecl varargs logger with binary-proven object, world-time,
// global-file, and text-buffer surfaces; exact 213-byte match under default.rsp.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern int logDebugID;
extern FILE* debugOut;

class RGE_Game_World {
public:
    char gap_00[0x04];
    long world_time; // +0x04
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    char gap_00[0x04];
    int id; // +0x04
    char gap_08[0x04];
    RGE_Player* owner; // +0x0C

    void logDebug(char* format, ...);
};

void RGE_Static_Object::logDebug(char* format, ...)
{
    char textOut[1024];

    if (logDebugID == -1 || logDebugID == this->id) {
        if (debugOut == 0) {
            debugOut = fopen("c:\\aoeunit.txt", "w");
            if (debugOut == 0) {
                return;
            }
            fprintf(debugOut, "WORLD TIME: %ld\n", this->owner->world->world_time);
        }

        va_list args;
        va_start(args, format);
        vsprintf(textOut, format, args);
        va_end(args);

        if (strlen(textOut) != 0) {
            fprintf(debugOut, "UNIT #%5d: %s\n", this->id, textOut);
        } else {
            fprintf(debugOut, "UNIT #%5d\n", this->id);
        }
    }
}
