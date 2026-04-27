// VA: 00483430 generate (264B)
// rmm_dbct.cpp
// EH frame (/GX)

class RGE_RMM_Database_Controller {
public:
    int* vtable;
    char gap4[0x4F4C];
    int* field_4F50;
    int field_4F54;
    char* field_4F58;
    
    void generate();
};

void* __cdecl operator_new(unsigned size);

void RGE_RMM_Database_Controller::generate() {
    void* buf = operator_new(0x12CC);
    if (buf) {
        field_4F50 = (int*)buf;
    }
}
