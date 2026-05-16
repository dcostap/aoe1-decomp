// VA: 005159D0 TRIBE_Player::notify
// PDB: tplayer.cpp lines 2308-2395 (440 bytes, 129 asm lines)
// Default flags. No inline asm/hacks.

extern int* rge_base_game;

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, int seed);

extern int debug_random_on;
extern int g_save_rand3;
extern int g_save_rand4;

#pragma pack(push, 1)
class RGE_Static_Object_N;
class RGE_Game_World_N {
public:
    RGE_Static_Object_N* object(int id);
    char gap_00[0x30];
    void** sounds;
    char gap_34[0x48];
    short some_id;
};

class RGE_Static_Object_N {
public:
    char gap_00[0x30];
    int* unk;
    char gap_34[0x04];
    float pos_x;
    float pos_y;
};

class RGE_Sound_N {
public:
    void play(int on);
};

class Tribe_Game_N {
public:
    void add_notification_loc(int x, int y);
};

class RGE_Base_Game_N {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40(int a1, int a2, int a3, int a4, int a5);
    char gap_04[0x3F0];
    void* game_world;
};

class TRIBE_Player_N {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128(int, int, int, long, long, long);

    void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

void TRIBE_Player_N::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6)
{
    RGE_Static_Object_N* obj;

    switch (param_3) {
    case 0x201:
        if (*(int*)((char*)this + 0x228) == 0) {
            *(int*)((char*)this + 0x228) = 20;
            obj = ((RGE_Game_World_N*)*(void**)((char*)this + 0x3C))->object(param_4);
            if (obj != 0) {
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x920);
                int saved_rand = debug_random_on;
                debug_random_on = 0;
                g_save_rand3 = saved_rand;

                if ( ((RGE_Game_World_N*)*(void**)((char*)this + 0x3C))->some_id == *(short*)((char*)this + 0x4A) ) {
                    float f = *(float*)((char*)*(void**)((char*)this + 0x50) + 0x68);
                    short idx = (short)f;
                    void* sound = ((RGE_Game_World_N*)*(void**)((char*)this + 0x3C))->sounds[idx];
                    if (sound != 0) {
                        ((RGE_Sound_N*)sound)->play(1);
                    }
                    ((Tribe_Game_N*)rge_base_game)->add_notification_loc(
                        (int)obj->pos_x, (int)obj->pos_y);
                }

                debug_random_on = saved_rand;
                debug_srand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x931, r);
            }
        }
        break;

    case 0x20C:
        if (param_4 == 0x267) {
            ((RGE_Base_Game_N*)rge_base_game)->vf40(
                3, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        }
        break;

    case 0x207:
        ((RGE_Base_Game_N*)rge_base_game)->vf40(
            1, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        break;

    case 0x206:
        ((RGE_Base_Game_N*)rge_base_game)->vf40(
            2, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        break;
    }

    {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x949);
        int saved_rand2 = debug_random_on;
        g_save_rand4 = saved_rand2;
        debug_random_on = 0;

        if (*(void**)((char*)this + 0x238) != 0) {
            this->vf128(param_1, param_2, param_3, param_4, param_5, param_6);
        }

        debug_random_on = saved_rand2;
        debug_srand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x956, r);
    }
}
