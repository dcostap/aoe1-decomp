// VA: 00483020 RGE_RMM_Database_Controller ctor (466B)
// rmm_dbct.cpp
// EH frame (/GX)

class RGE_RMM_Database_Controller {
public:
    int* vtable;
    char gap4[0x10];
    int field_14;
    int field_18;
    char gap1C[0x18];
    int field_34;
    char gap38[0x4F18];
    int field_4F50;
    int field_4F54;
    char* field_4F58;
    
    RGE_RMM_Database_Controller();
};

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller() {
    vtable = 0;
    field_14 = 0;
    field_18 = 0;
    field_34 = 0;
    field_4F54 = 0;
    field_4F58 = 0;
}
