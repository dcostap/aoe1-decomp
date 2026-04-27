// VA: 004832E0 save (336B)
// rmm_dbct.cpp

class RGE_RMM_Database_Controller {
public:
    char gap4[0x4F50];
    int field_4F54;
    char* field_4F58;
    
    void save(int fd);
};

int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_RMM_Database_Controller::save(int fd) {
    int count = field_4F54;
    rge_write(fd, &count, 8);
}
