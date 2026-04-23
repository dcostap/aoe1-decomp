extern "C" void free(void* ptr);

struct TRIBE_History_Events {
    char gap_00[0x0C];
    TRIBE_History_Events* next;
};

class TRIBE_History_Info {
public:
    void* history;
    TRIBE_History_Events* events;

    ~TRIBE_History_Info();
};

TRIBE_History_Info::~TRIBE_History_Info() {
    TRIBE_History_Events* events;

    if (this->history != 0) {
        free(this->history);
    }
    while ((events = this->events) != 0) {
        this->events = events->next;
        free(events);
    }
}
