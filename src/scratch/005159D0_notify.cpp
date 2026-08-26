// VA: 005159D0 TRIBE_Player::notify
// PDB: tplayer.cpp lines 2308-2395 (440 bytes, 129 asm lines)
// Default flags. No inline asm/hacks.

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
    virtual ~RGE_Base_Game_N();
    virtual int run(); virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int); virtual void set_player(short);
    virtual int get_error_code(); virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int); virtual char* get_string(long);
    virtual void notification(int, int, int, int, int);
    char gap_04[0x3F0];
    void* game_world;
};

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
extern RGE_Base_Game_N* rge_base_game;
#endif

class TRIBE_Player_N {
public:
    virtual void notifyAI(int, int, int, long, long, long);
    void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

#pragma pack(pop)

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
            ((RGE_Base_Game_N*)rge_base_game)->notification(
                3, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        }
        break;

    case 0x207:
        ((RGE_Base_Game_N*)rge_base_game)->notification(
            1, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        break;

    case 0x206:
        ((RGE_Base_Game_N*)rge_base_game)->notification(
            2, (int)(short)*(short*)((char*)this + 0x4A), 0, 0, 0);
        break;
    }

    {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x949);
        int saved_rand2 = debug_random_on;
        g_save_rand4 = saved_rand2;
        debug_random_on = 0;

        if (*(void**)((char*)this + 0x238) != 0) {
            this->notifyAI(param_1, param_2, param_3, param_4, param_5, param_6);
        }

        debug_random_on = saved_rand2;
        debug_srand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x956, r);
    }
}
