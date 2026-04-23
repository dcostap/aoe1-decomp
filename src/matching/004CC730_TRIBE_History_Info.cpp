class TRIBE_History_Info {
public:
    void* history;
    void* events;
    int number_of_events;
    int number_of_entries;
    int max_number_of_entries;

    TRIBE_History_Info(int index);
    void load(int index);
};

TRIBE_History_Info::TRIBE_History_Info(int index) {
    this->history = 0;
    this->events = 0;
    this->number_of_entries = 0;
    this->number_of_events = 0;
    this->max_number_of_entries = 0;
    if (index >= 0) {
        load(index);
    }
}
