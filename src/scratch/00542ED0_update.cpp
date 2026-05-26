// VA: 00542ED0 RGE_Game_World::update
// PDB source: World.cpp
// Attempt log:
// - initial reconstruction from packet asm; natural member calls and raw globals compiled but .text was 1168 vs target 1190, too short to compare.
// - added padded virtual surfaces for World slot +0x9C/+0xC4 and Player slots +0x7C/+0xEC; still compiled to 1168 bytes, indicating broad source/model drift remains.
// - give-up: behavior/call skeleton is sketched, but exact matching needs a fuller pass over the real World/player/chat helper surfaces and arithmetic/logging block shapes; no accepted_drift proposed without byte comparison.

extern unsigned long debug_timeGetTime(char* file, int line);
extern void debug_srand(char* file, int line, int seed);
extern int debug_rand(char* file, int line);
extern void debug_printf(char* fmt, ...);
extern void sprintf(void* dst, char* fmt, ...);
extern char* strcat(void* dst, char* src);
extern void free(void* p);
extern int __ftol(float);

#define WORLD_CPP ((char*)0x58ECD8)
#define rge_base_game (*(BaseGame**)0x62C574)
#define debug_random_on (*(int*)0x62C4D4)
#define debug_timeGetTime_on (*(int*)0x62C4E8)
#define do_fixed_update (*(int*)0x62C4E0)
#define fixed_update_time (*(int*)0x57F9E4)
#define visible_combats (*(short*)0x886C4C)
#define dword_62E660 (*(void**)0x62E660)
#define byte_62C524 (*(int*)0x62C524)
#define chat_time (*(int*)0x886C54)
#define chat_msg (*(char**)0x886C50)
#define dword_886C10 (*(int*)0x886C10)

class BaseGame { public: void add_to_timing(int, int); int get_player_count(); int get_player(int); };
class Comm { public: int DoCycle(int); void cycle2(); void cycle2(int); };
class ObjList { public: void update(); };
class SpriteList { public: void update(); };
class Scenario { public: void update(); };
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class PlayerObj { public: VPAD16(p0) VPAD8(p16) VPAD4(p24) VPAD1(p28) VPAD1(p29) VPAD1(p30) virtual void update_panel(); int relation(int); VPAD16(p32) VPAD8(p48) VPAD1(p56) VPAD1(p57) VPAD1(p58) virtual void vf_9c(char*, int); char gap[0x80-4]; unsigned char type; };
class SomeGlobal { public: void fn(); };

class World_542ED0 {
public:
    VPAD32(w0) VPAD4(w32) VPAD1(w36) VPAD1(w37) VPAD1(w38) virtual void vf_9c(char*, int, int); VPAD8(w40) VPAD1(w48) virtual void vf_c4();
    int time; int old_time; int delta; int pad10; int last_time; float speed; unsigned char flag1c; unsigned char retflag;
    char gap1e[0x3c-0x1e]; short player_count; char gap3e[2]; PlayerObj** players;
    char gap44[0x58-0x44]; Comm** comm_holder; Scenario* scenario; char gap60[0x78-0x60]; int seed; char gap7c[8]; float scaled_delta;
    char gap88[0xb0-0x88]; int cur_player; int player_ticks[16]; int prev_f4; int f8;

    void update_sounds(unsigned long t); void update_sprites(unsigned long t);
    unsigned char update();
};

unsigned char World_542ED0::update()
{
    char buf[256];
    unsigned long t0, t1, now;
    int cycle;
    int elapsed;
    int zero = 0;
    int i;

    t0 = debug_timeGetTime(WORLD_CPP, 0x68e);
    this->f8 = this->prev_f4;
    cycle = (*this->comm_holder)->DoCycle(this->time);
    t1 = debug_timeGetTime(WORLD_CPP, 0x690);
    rge_base_game->add_to_timing(0xe, (int)(t1 - t0));
    if (cycle == 0) {
        this->delta = 0;
        return this->retflag;
    }

    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if (do_fixed_update != 0) cycle = fixed_update_time;

    debug_srand(WORLD_CPP, 0x6a2, this->seed);
    now = debug_timeGetTime(WORLD_CPP, 0x6a4);
    this->update_sounds(now);
    this->update_sprites(now);

    if (cycle == -1) {
        if (this->last_time == 0) { zero = 1; elapsed = 0; }
        else elapsed = now - this->last_time;
        if ((unsigned int)elapsed > 100) elapsed = 100;
    } else elapsed = cycle;

    this->last_time = now;
    i = this->time;
    this->old_time = i;
    if (this->flag1c) {
        if (cycle != -1) this->flag1c = 0;
        this->time = i + (int)((double)elapsed * this->speed);
    } else {
        this->time = i + (int)((double)elapsed * this->speed);
    }
    this->delta = this->time - this->old_time;

    if (this->delta != 0 || zero) {
        (*this->comm_holder)->cycle2();
        this->scenario->update();
        this->scaled_delta = (double)this->delta * *(float*)0x577A14;
        dword_886C10 = dword_886C10 + 1;
        for (i = 0; i < this->player_count; ++i) {
            if (this->players[i] != 0) {
                this->player_ticks[i] += this->delta;
                this->players[i]->update_panel();
                ((ObjList*)((char*)this->players[i] + 0x58))->update();
            }
        }
        if (dword_62E660 != 0) ((SomeGlobal*)dword_62E660)->fn();
        now = debug_rand(WORLD_CPP, 0x6e2);
        for (i = 0; i < this->player_count; ++i) if (this->players[i]) ((ObjList*)this->players[i]->gap)->update();
        for (i = 0; i < this->player_count; ++i) if (this->players[i]) ((SpriteList*)this->players[i]->gap)->update();
        debug_srand(WORLD_CPP, 0x6f6, now);
        this->player_ticks[this->cur_player] = 0;
        this->cur_player++;
        if (this->cur_player >= this->player_count) this->cur_player = 0;
        this->vf_c4();
    }

    now = debug_rand(WORLD_CPP, 0x71a);
    this->seed = now;
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    (*this->comm_holder)->cycle2(now);

    if (byte_62C524 == 1) {
        if (this->retflag != 1) {
            if ((unsigned int)(this->time - chat_time) > 30000 || chat_time == 0) {
                if (chat_msg == 0) {
                    sprintf(buf, (char*)0x58EDF8, rge_base_game->get_player(this->time));
                    chat_msg = (char*)strcat(buf, (char*)0x58B900);
                    if (chat_msg == 0) return this->retflag;
                }
                int min = this->time / 1000 / 60;
                int sec = min;
                if (min > 59) {
                    int h = min / 60;
                    min = min - h * 60;
                    if (h > 59) sec = h - (h / 60) * 60;
                }
                if (chat_time == 0) this->vf_9c(chat_msg, 1, 1);
                else debug_printf((char*)0x58EDCC, chat_msg, sec, min, 0);
                for (i = 1; i < this->player_count; ++i) if (this->players[i]) this->players[i]->vf_9c(chat_msg, chat_time == 0 ? 1 : 0);
                chat_time = this->time + 1;
            }
        }
        if (this->retflag == 1 && byte_62C524 == 1 && chat_msg != 0) {
            debug_printf((char*)0x58EDC0, chat_msg);
            for (i = 1; i < this->player_count; ++i) if (this->players[i]) debug_printf(this->players[i]->type == 1 ? (char*)0x58EDAC : (char*)0x58ED98, chat_msg, i);
            free(chat_msg);
            chat_msg = 0;
        }
    }
    return this->retflag;
}
