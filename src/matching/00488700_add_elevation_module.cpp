extern float DAT_00571f48;
extern float DAT_00571f4c;
extern float DAT_00571f50;
extern float DAT_00571f54;
extern void* L;

extern int __cdecl debug_rand(char* file, int line);
extern void __cdecl Log(void* log, const char* fmt, ...);

class RGE_RMM_Database_Controller {
public:
    void add_elevation_module();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    char gap0[0x34];
    int map_type;
    char gap1[0x3FD4 - 0x38];
    int elevations[1];
    char gap2[0x491C - 0x3FD8];
    int count;

    void add_elevation_module();
};

void TRIBE_RMM_Database_Controller::add_elevation_module()
{
    RGE_RMM_Database_Controller::add_elevation_module();

    int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x243);
    float f = (DAT_00571f4c - (float)r * DAT_00571f48) * DAT_00571f50;
    if (map_type == 7)
        f *= DAT_00571f54;

    int i = 0;
    if (count > 0) {
        int* p = (int*)((char*)this + 0x3FD4);
        do {
            *p = (int)((float)*p * f);
            ++i;
            p = (int*)((char*)p + 0x18);
        } while (i < count);
    }

    int r2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x24b);
    Log(L, "Random Map elevation initilization, rand: %d", r2);
}
