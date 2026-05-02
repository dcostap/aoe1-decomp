class X { public:
    char gap_00[0x10];
    int field_10;
    int get_target_obj();
};
int X::get_target_obj() { return this->field_10; }
