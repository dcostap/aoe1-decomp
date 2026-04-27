// TRIBE_Action_Wonder::~TRIBE_Action_Wonder
// VA: 004D34F0
// PDB: tact_wnd.cpp:50-97
//
// FLAGS: /GX
//
// Attempt log:
// - draft 1: standalone class, no base → no EH/no base destructor call, 88.9%

#include "../../include/game_globals.h"

// Forward declare RGE_Action for proper inheritance
class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Base_Game_W {
public:
    char gap_00[0x3F4];
    void* world;
    void set_countdown_timer(short player_id, int timeout);
    void reset_countdown_timer(short player_id);
};

// Proper inheritance from RGE_Action
class TRIBE_Action_Wonder : public RGE_Action {
public:
    virtual ~TRIBE_Action_Wonder();
    virtual void d1();  virtual void d2();
    virtual void d3();  virtual void d4();
    virtual void d5();  virtual void d6();
    virtual void d7();  virtual void d8();
    virtual void d9();  virtual void d10();
    virtual void d11(); virtual void d12();
    virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16();
    virtual void d17(); virtual void d18();
    virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22();
    virtual void set_state(unsigned char s);

    char gap_04[4];
    void* field_08;
    unsigned char state;
};

TRIBE_Action_Wonder::~TRIBE_Action_Wonder()
{
    void* world = *(void**)((char*)rge_base_game + 0x3F4);

    if (*(unsigned char*)((char*)world + 0x1D) == 0) {
        void** players = *(void***)((char*)world + 0x40);
        short player_num = *(short*)((char*)world + 0x3C);
        int i;

        if (this->state == 2) {
            for (i = 1; i < player_num; i++) {
                if (i != *(short*)(*(int*)(*(int*)((char*)this->field_08 + 0x0C) + 0x00) + 0x4A)) {
                    void* node_vt = *(void**)this->field_08;
                    ((void (__stdcall *)(void*, int, int))((void**)node_vt)[0xDC/4])(players[i], 1, -1);
                }
            }
        }

        if (this->state == 6) {
            for (i = 1; i < player_num; i++) {
                if (i != *(short*)(*(int*)(*(int*)((char*)this->field_08 + 0x0C) + 0x00) + 0x4A)) {
                    void* node_vt = *(void**)this->field_08;
                    ((void (__stdcall *)(void*, int, int))((void**)node_vt)[0xDC/4])(players[i], 0, -1);
                }
            }
        }

        if (*(int*)((char*)world + 0x108) == 0) {
            int found = 0;
            void* action_obj = *(void**)((char*)this->field_08 + 0x0C);
            void* list_head = *(void**)(*(int*)((char*)action_obj + 0x28) + 4);
            void* node = list_head;

            while (node) {
                void* eax = *(void**)node;
                if (eax != (void*)this->field_08) {
                    void* ebp = *(void**)((char*)eax + 8);
                    if (*(short*)((char*)ebp + 0x10) == 0x114 &&
                        *(unsigned char*)((char*)eax + 0x48) >= 2) {
                        found = 1;
                        break;
                    }
                }
                node = *(void**)((char*)node + 4);
            }

            ((RGE_Base_Game_W*)rge_base_game)->reset_countdown_timer(
                *(short*)((char*)action_obj + 0x4A));

            if (found) {
                void* player_obj = *(void**)((char*)this->field_08 + 0x0C);
                short pid = *(short*)((char*)player_obj + 0x4A);
                ((RGE_Base_Game_W*)rge_base_game)->set_countdown_timer(pid, 2000);
            }
        }

        {
            void* action_node = this->field_08;
            short pid = *(short*)(*(int*)((char*)action_node + 0x0C) + 0x4A);
            int i2 = (int)*(float*)((char*)action_node + 0x38);
            int i1 = (int)*(float*)((char*)action_node + 0x3C);
            void* rge_vt = *(void**)rge_base_game;
            ((void (__stdcall *)(int, int, int, int, int))((void**)rge_vt)[0x40/4])(0x6E, pid, i2, i1, 0);
        }
    }
}
