extern "C" void __cdecl free(void* block);

class RGE_Campaign {
public:
    char gap_00[0x108];
    void* scenario_offsets;

    ~RGE_Campaign();
};

RGE_Campaign::~RGE_Campaign() {
    if (this->scenario_offsets != 0) {
        free(this->scenario_offsets);
        this->scenario_offsets = 0;
    }
}
