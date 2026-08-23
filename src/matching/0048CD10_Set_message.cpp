// 0048CD10 RGE_Scenario::Set_message (scenario.cpp:1160-1199, 273B)
// Sets a scenario string field by index (0-4). calloc+copy, free old.
// FLAGS: /nologo /c /O2 /Oy

#include <string.h>

void* __cdecl calloc(unsigned int n, unsigned int size);
void __cdecl free(void*);

#ifndef SCENARIO_TU
struct RGE_Scenario {
    char gap_00[0x1014];
    /* +0x1014 */ char* description;
    /* +0x1018 */ char* hints;
    /* +0x101C */ char* win_message;
    /* +0x1020 */ char* loss_message;
    /* +0x1024 */ char* historicle_notes;

    void Set_message(char* text, long field_index);
};
#endif

void RGE_Scenario::Set_message(char* text, long field_index) {
    long len;
    char* buf;

    if (text == 0) {
        len = 0;
    } else {
        len = strlen(text) + 1;
    }

    if (len > 0) {
        buf = (char*)calloc(len, 1);
    } else {
        buf = 0;
    }

    memcpy(buf, text, len);

    switch (field_index) {
    case 0:
        if (description != 0) {
            free(description);
        }
        description = buf;
        break;
    case 1:
        if (hints != 0) {
            free(hints);
        }
        hints = buf;
        break;
    case 2:
        if (win_message == 0) {
            free(0);
        }
        win_message = buf;
        break;
    case 3:
        if (loss_message != 0) {
            free(loss_message);
        }
        loss_message = buf;
        break;
    case 4:
        if (historicle_notes != 0) {
            free(historicle_notes);
        }
        historicle_notes = buf;
        break;
    default:
        if (buf != 0) {
            free(buf);
        }
        break;
    }
}
