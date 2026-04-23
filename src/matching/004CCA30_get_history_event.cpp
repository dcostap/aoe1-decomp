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

unsigned char TRIBE_History_Info::get_history_event(long time, unsigned char& event) {
    TRIBE_History_Events* node = this->events;

    while (node != 0) {
        if (node->time == time) {
            event = node->event;
            return 1;
        }
        node = node->next;
    }
    return 0;
}
