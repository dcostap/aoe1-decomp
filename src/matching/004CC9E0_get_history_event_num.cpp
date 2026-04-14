class TRIBE_History_Info {
public:
    virtual ~TRIBE_History_Info();
    char gap_0[0x4];
    int field_8;
    int get_history_event_num();
};

int TRIBE_History_Info::get_history_event_num() { return this->field_8; }
