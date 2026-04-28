// 004CC9F0 TRIBE_History_Info::get_history_event
// Source: t_histry.cpp lines 198-211
// Size: 54 bytes, 0.0000% MATCH
//
// Attempt log:
// Probe 1: while(1)+break -> `je exit; jmp loop` control flow, mismatch
// Probe 2: while(node) -> `jne loop` back-edge, EXACT MATCH

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

    unsigned char get_history_event(long index, unsigned char& event, long& time);
};

unsigned char TRIBE_History_Info::get_history_event(long index, unsigned char& event, long& time)
{
    TRIBE_History_Events* node = this->events;

    if (node == 0)
        return 0;

    while (node != 0) {
        if (index == 0) {
            event = node->event;
            time = node->time;
            return 1;
        }
        node = node->next;
    }

    return 0;
}
