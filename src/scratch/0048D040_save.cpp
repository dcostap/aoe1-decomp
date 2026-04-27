// VA: 0048D040 RGE_Scenario_File_Info::save
// PDB source: sceninfo.cpp

#include <stdlib.h>

extern "C" {
    int rge_open(char* filename, int mode, int share);
    void rge_write_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}

struct RGE_Scenario_Header {
    virtual void dummy() {}
    virtual void save(int fd) {}
};

class RGE_Scenario_File_Info {
public:
    char filename[0x104];
    int scenario_num;
    void* scenarios;

    void save();
};

void RGE_Scenario_File_Info::save()
{
    int fd = rge_open(filename, 0x8301, 0x180);
    if (fd == -1)
        return;

    rge_write_uncompressed(fd, &scenario_num, 4);

    if (scenario_num > 0) {
        int cnt = 0;
        int off = 0;
        while (cnt < scenario_num) {
            char* entry = (char*)scenarios;
            rge_write_uncompressed(fd, entry + off, 4);
            rge_write_uncompressed(fd, entry + off + 8, 0x104);
            RGE_Scenario_Header* h = *(RGE_Scenario_Header**)(entry + off + 4);
            h->save(fd);
            cnt++;
            off += 0x10C;
        }
    }

    rge_close(fd);
}
