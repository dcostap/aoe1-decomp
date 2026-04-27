// VA: 00483A20 add_land_module (1853B)
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
    
    void add_land_module();
};

void RGE_RMM_Database_Controller::add_land_module() {
    int count = field_34;
    char* arr = field_4F58;
    if (arr) {
        int* entry = (int*)(arr + count * 9 * 8);
    }
    
    int dim1 = field_14;
    int dim2 = field_18;
    if (dim1 > 0 && dim2 > 0) {
        field_4F54 = dim1;
    }
}
