class TRIBE_History_Info {
public:
    virtual ~TRIBE_History_Info();
    char gap_0[0x8];
    int field_C;
    int get_history_entry_num();
};

int TRIBE_History_Info::get_history_entry_num() { return this->field_C; }
