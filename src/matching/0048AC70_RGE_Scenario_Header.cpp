extern "C" void __cdecl free(void* block);

class RGE_Scenario_Header {
public:
    virtual ~RGE_Scenario_Header();
    char gap_04[0x0C];
    char* description;
};

RGE_Scenario_Header::~RGE_Scenario_Header() {
    if (this->description != 0) {
        free(this->description);
        this->description = 0;
    }
}
