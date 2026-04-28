void __cdecl rge_read_uncompressed(int fd, void* buf, int count);
void* __cdecl malloc(int size);

class RGE_Scenario_Header {
public:
    void* vtable_ptr;        // +0x00
    int error_code;          // +0x04
    long version;            // +0x08
    unsigned long checksum;  // +0x0C
    char* description;       // +0x10

    RGE_Scenario_Header(int fd);
};

RGE_Scenario_Header::RGE_Scenario_Header(int fd) {
    int header_size;
    int desc_size;

    error_code = 0;
    version = 0;
    checksum = 0;
    description = 0;
    vtable_ptr = (void*)0x572120;

    rge_read_uncompressed(fd, &header_size, 4);
    rge_read_uncompressed(fd, &version, 4);

    if (version >= 2) {
        rge_read_uncompressed(fd, &checksum, 4);
    }

    rge_read_uncompressed(fd, &desc_size, 4);
    if (desc_size > 0) {
        description = (char*)malloc(desc_size);
        if (description == 0) {
            error_code = 1;
            return;
        }
        rge_read_uncompressed(fd, description, desc_size);
    } else {
        description = 0;
    }
}

void __cdecl rge_read_uncompressed(int fd, void* buf, int count) { }
void* __cdecl malloc(int size) { return 0; }
