// VA: 00484320 add_object_module (325B)
// rmm_dbct.cpp

class RGE_RMM_Database_Controller {
public:
    char gap4[0x30];
    int field_34;
    char gap38[0x4F1C];
    int field_4F54;
    char* field_4F58;
    
    void add_object_module();
};

void RGE_RMM_Database_Controller::add_object_module() {
    int count = field_34;
    char* arr = field_4F58;
    if (arr) {
        int* entry = (int*)(arr + count * 9 * 8);
        field_4F54 = count + 1;
    }
}
