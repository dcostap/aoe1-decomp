// VA: 00482B70 RGE_RMM_Database_Controller ctor2 (1185B)
// rmm_dbct.cpp
// EH frame (/GX)

class RGE_RMM_Database_Controller {
public:
    char gap4[0x4F50];
    int field_4F54;
    char* field_4F58;
    
    RGE_RMM_Database_Controller(int a1, int a2);
};

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int a1, int a2) {
    field_4F54 = 0;
    field_4F58 = 0;
}
