extern "C" void __cdecl free(void*);

class RGE_Campaign_Info_dtor {
public:
    void dtor(void);
    char gap_00[0x108];
    void* scenario_info;
};

void RGE_Campaign_Info_dtor::dtor(void) {
    if (this->scenario_info) {
        free(this->scenario_info);
        this->scenario_info = 0;
    }
}
