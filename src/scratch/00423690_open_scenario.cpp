// 00423690 RGE_Campaign::open_scenario
// Source: campaign.cpp lines 175-193

class RGE_Campaign {
public:
    int version;
    char name[256];
    int scenario_num;
    void* scenario_offsets;
    char filename[256];

    int open_scenario(long index);
};

extern int __cdecl _open(const char*, int);
extern int __cdecl _lseek(int, int, int);
extern int __cdecl rge_fake_open(int, int);

int RGE_Campaign::open_scenario(long index)
{
    if (index >= 0 && index < this->scenario_num) {
        int h = _open(this->filename, 0x8000);
        if (h >= 0) {
            int off = index;
            off <<= 6;
            off += index;
            off <<= 3;
            _lseek(h, *(int*)((char*)this->scenario_offsets + off + 4), 0);
            rge_fake_open(h, *(int*)((char*)this->scenario_offsets + off));
            return h;
        }
    }
    return -1;
}
