// VA: 00483600 calc_land_start (1056B)
// rmm_dbct.cpp

class RGE_RMM_Database_Controller {
public:
    char gap4[0x4F50];
    int field_4F54;
    char* field_4F58;
    char gap4F5C[0x4];
    int field_4F60;
    
    void calc_land_start();
};

int __cdecl sub_004230A0(int val);

void RGE_RMM_Database_Controller::calc_land_start() {
    int val = sub_004230A0(0x1C3);
    
    if (field_4F54 > 0) {
        field_4F60 = val;
    }
}
