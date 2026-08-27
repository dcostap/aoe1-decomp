#ifndef AOE1_T_HISTRY_H
#define AOE1_T_HISTRY_H

class TRIBE_History_Entry {
public:
    unsigned char population;
};

class TRIBE_History_Events {
public:
    unsigned char event;
    unsigned char _pad_0[3];
    long time;
    long world_time;
    TRIBE_History_Events* next;
};

class TRIBE_History_Info {
public:
    TRIBE_History_Entry* history;
    TRIBE_History_Events* events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;

    TRIBE_History_Info(int index);
    ~TRIBE_History_Info();
    void save(int file);
    void load(int file);
    void add_history_entry(unsigned char flag, unsigned char value);
    long get_history_entry_num();
    unsigned char get_history_entry(unsigned char mode, long index);
    void add_history_event(unsigned char event);
    long get_history_event_num();
    unsigned char get_history_event(long index, unsigned char& event,
                                    long& time);
    unsigned char get_history_event(long time, unsigned char& event);
};

typedef char t_histry_info_size_check[
    (sizeof(TRIBE_History_Info) == 0x14) ? 1 : -1];
typedef char t_histry_events_size_check[
    (sizeof(TRIBE_History_Events) == 0x10) ? 1 : -1];

#endif
