struct HistoryEntry {
    unsigned char population;
};

class TRIBE_History_Info {
public:
    HistoryEntry* history;
    char gap_04[0x08];
    int number_of_entries;

    unsigned char get_history_entry(unsigned char mode, long index);
};

unsigned char TRIBE_History_Info::get_history_entry(unsigned char mode, long index) {
    if ((index < this->number_of_entries) && (index >= 0) && (mode == 0)) {
        return this->history[index].population;
    }
    return 0;
}
