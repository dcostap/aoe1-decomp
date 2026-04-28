// 0051F560 Time_Line_Panel::record_special_event
// Size: 156 bytes
//
// Attempt log:
// Probe 1 (event_local, sizeof): 105 bytes diff, EBX for param_4
// Probe 2 (direct_ref): 136 bytes diff (function size grew), EBX for param_4
// Probe 3 (calloc decl explicit): same
// Probe 4 (long p4 = param_4 local): same
// Probe 5 (__cdecl calloc): same
// Probe 6 (*(unsigned char*)&param_4): same
// Probe 7 (no p4 local): same
// Probe 8 (extern "C" calloc): same
// Probe 9 (variant_lab attempt - template error): n/a
// Probe 10 (various small tweaks): same
//
// Remaining: 136 bytes diff (87.2%). VC5 uses EBX for param_4; original uses EDI.
// All source restructuring attempts produce same EBX allocation.
// VC5 register allocation invariant — cannot force EDI through source changes.
// Left in scratch.

struct TRIBE_History_Events {
    unsigned char event;
    char gap_01[3];
    long time;
    char gap_08[4];
    TRIBE_History_Events* next;
};

class TRIBE_History_Info {
public:
    char gap_00[4];
    TRIBE_History_Events* events;

    unsigned char get_history_event(long time, unsigned char& event);
};

struct Special_Events {
    long time_slice;                      // +0x00
    long X_line_pos;                      // +0x04
    long Y_line_pos;                      // +0x08
    long intermediate_y_line_segment;     // +0x0C
    unsigned char player_id;             // +0x10
    unsigned char player_color;          // +0x11
    unsigned char event;                  // +0x12
    char gap_13;
    long pop_total;                       // +0x14
    long field_18;                         // +0x18
    long field_1C;                         // +0x1C
    long field_20;                         // +0x20
    long field_24;                         // +0x24
    long field_28;                         // +0x28
    long field_2C;                         // +0x2C
    long field_30;                         // +0x30
    long field_34;                         // +0x34
    long field_38;                         // +0x38
    unsigned char field_3C;               // +0x3C
    char gap_3D[0x33];
    long field_70;                         // +0x70
    unsigned char field_74;               // +0x74
    char gap_75[0x33];
    long field_A8;                         // +0xA8
    Special_Events* next;                 // +0xAC
};

class Time_Line_Panel {
public:
    char gap_00[0x518];
    Special_Events* time_slice_events;    // +0x518

    void record_special_event(
        unsigned char param_1,
        TRIBE_History_Info* param_2,
        unsigned char param_3,
        long param_4,
        long param_5,
        long param_6,
        long param_7);
};

void* __cdecl calloc(int count, int size);

void Time_Line_Panel::record_special_event(
    unsigned char param_1,
    TRIBE_History_Info* param_2,
    unsigned char param_3,
    long param_4,
    long param_5,
    long param_6,
    long param_7)
{
    if (!param_2->get_history_event(param_4, *(unsigned char*)&param_4)) {
        return;
    }

    Special_Events* pSVar3 = (Special_Events*)calloc(1, 0xB0);
    pSVar3->X_line_pos = param_5;
    pSVar3->Y_line_pos = param_6;
    pSVar3->intermediate_y_line_segment = param_7;
    pSVar3->time_slice = param_4;
    pSVar3->player_id = param_1;
    pSVar3->player_color = param_3;
    pSVar3->event = (unsigned char)param_4;
    pSVar3->pop_total = 0;
    pSVar3->field_18 = 0;
    pSVar3->field_1C = 0;
    pSVar3->field_20 = 0;
    pSVar3->field_24 = 0;
    pSVar3->field_28 = 0;
    pSVar3->field_2C = 0;
    pSVar3->field_30 = 0;
    pSVar3->field_34 = 0;
    pSVar3->field_38 = 0;
    pSVar3->field_3C = 0;
    pSVar3->field_70 = 0;
    pSVar3->field_74 = 0;
    pSVar3->field_A8 = 0;
    pSVar3->next = this->time_slice_events;
    this->time_slice_events = pSVar3;
}
