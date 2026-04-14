class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    char gap_0[0x18];
    float field_1C;
    float get_schedule();
};

float RGE_Random_Map_Module::get_schedule() { return this->field_1C; }
