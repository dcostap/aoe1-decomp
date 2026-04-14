class TRIBE_Panel_Time {
public:
    virtual ~TRIBE_Panel_Time();
    char gap_0[0xFC];
    int field_100;
    int get_clock_type();
};

int TRIBE_Panel_Time::get_clock_type() { return this->field_100; }
