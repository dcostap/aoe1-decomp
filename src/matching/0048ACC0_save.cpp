// 0048ACC0 RGE_Scenario_Header::save
// Size: 150 bytes

#include <string.h>

void rge_write_uncompressed(int fd, void* data, int size);

#ifndef SCENARIO_TU
class RGE_Scenario_Header {
public:
    virtual long get_size();

    char pad_04[4];
    int version;                 // +0x08
    int checksum;                // +0x0C
    char* description;           // +0x10

    void save(int fd);
};
#endif

void RGE_Scenario_Header::save(int fd) {
    int header_size;
    int desc_len;

    header_size = this->get_size();
    rge_write_uncompressed(fd, &header_size, 4);
    rge_write_uncompressed(fd, &this->version, 4);
    if (this->version >= 2) {
        rge_write_uncompressed(fd, &this->checksum, 4);
    }

    if (this->description != 0) {
        desc_len = strlen(this->description) + 1;
    } else {
        desc_len = 0;
    }
    rge_write_uncompressed(fd, &desc_len, 4);
    if (this->description != 0) {
        rge_write_uncompressed(fd, this->description, desc_len);
    }
}
