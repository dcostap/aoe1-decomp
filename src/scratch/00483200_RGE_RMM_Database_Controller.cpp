// VA: 00483200 ~RGE_RMM_Database_Controller dtor (213B)
// rmm_dbct.cpp

class RGE_RMM_Database_Controller {
public:
    int* vtable;
    char gap4[0x4F50];
    int field_4F54;
    char* field_4F58;
    
    ~RGE_RMM_Database_Controller();
};

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    vtable = (int*)0x571E88;
    
    int count = field_4F54;
    if (count > 0) {
        char* arr = field_4F58;
        if (arr) {
            for (int i = 0; i < count; i++) {
                // Cleanup
            }
        }
    }
}
