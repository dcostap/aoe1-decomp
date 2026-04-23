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

unsigned char TRIBE_History_Info::get_history_event(long index, unsigned char& event, long& time) {
    TRIBE_History_Events* node = this->events;

    if (node == 0) {
        return 0;
    }
    while (1) {
        if (index == 0) {
            event = node->event;
            time = node->time;
            return 1;
        }
        node = node->next;
        if (node == 0) {
            return 0;
        }
    }
}
