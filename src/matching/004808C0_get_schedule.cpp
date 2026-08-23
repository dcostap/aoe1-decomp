#ifndef RMM_BASE_SHARED_CONTEXT
class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    char gap_0[0x18];
    float field_1C;
    float get_schedule();
};
#endif

float RGE_Random_Map_Module::get_schedule() {
#ifdef RMM_BASE_SHARED_CONTEXT
    return this->schedule;
#else
    return this->field_1C;
#endif
}
