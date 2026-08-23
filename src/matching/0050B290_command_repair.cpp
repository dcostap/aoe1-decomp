// VA: 0050B290 TRIBE_Command::command_repair
// PDB: tcommand.cpp lines 1666-1716.
// Exact code needs target, command, then count packet writes.

#include <windows.h>
#include <stdio.h>
#include "../../include/tcommand_context.h"

extern "C" void* __cdecl calloc(size_t count, size_t size);

void TRIBE_Command::command_repair(
    RGE_Static_Object** objects,
    short count,
    RGE_Static_Object* target)
{
    int object_count = (int)count;
    int size = object_count * 4 + sizeof(TRIBE_Command_Repair);
    if (objects && count >= 1) {
        TRIBE_Command_Repair* packet =
            (TRIBE_Command_Repair*)calloc(1, size);
        int* object_ids = (int*)(packet + 1);
        if (packet) {
            for (int i = 0; i < object_count; ++i) {
                if (objects[i]) {
                    object_ids[i] = objects[i]->id;
                } else {
                    object_ids[i] = -1;
                }
            }
            packet->target.id = target->id;
            packet->command = 0x6E;
            packet->unit_num = (unsigned char)count;
            L->Log("      >SEND CMD REPAIR (CNT=%d)", object_count);
            this->submit(packet, size);
        }
    }
}
