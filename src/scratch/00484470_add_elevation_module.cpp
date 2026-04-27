// VA: 00484470 add_elevation_module (578B)
// rmm_dbct.cpp

class RGE_RMM_Database_Controller {
public:
    char gap4[0x10];
    int field_14;
    int field_18;
    char gap1C[0x18];
    int field_34;
    char gap38[0x4F1C];
    int field_4F54;
    char* field_4F58;
    
    void add_elevation_module();
};

void RGE_RMM_Database_Controller::add_elevation_module() {
    int count = field_34;
    char* arr = field_4F58;
    if (arr) {
        int* entry = (int*)(arr + count * 9 * 8 + 4);
        field_4F54 = field_14;
    }
}
