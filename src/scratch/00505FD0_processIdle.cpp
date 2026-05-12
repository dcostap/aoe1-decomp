// 00505FD0 TribePriestUnitAIModule::processIdle
// Source: taiuaimd.cpp lines 1692-1756
// Attempt log:
// 1: initial natural source with virtual slots 0x40/0x70/0x9C/0xE0, base processIdle member, debug_rand, and intrinsic sqrt: wrong frame (sub 10), object field offset +0x10 from explicit vtable+virtual double count, early null return inline.
// 2: remove explicit object vtable field and wrap body in positive computerPlayer guard: shortened to 352 without local output.
// 3: restore 4-byte local output buffer: still 352.
// 4: return to early-return structure with corrected object offsets: exact object offsets but still sub esp,10; early fail inline.
// 5: move chooseSomething output local into narrow scope: fixed sub esp,0C and output address; 33.9% edit diff. Remaining branch layout differs (early fail inline vs shared tail) and later FPU/call scheduling shifted.
// 6: positive computerPlayer/target guards shortened to 352.
// 7: explicit goto shared ret5 with top declarations shortened to 336, wrong family.
// 8: corrected object getSpeed virtual slot to +0x10C; returned to best attempt-5 source family.
// 9: status local with `if (status != 6) { body } return 6` to try inline ret6 layout.

#include <math.h>
#pragma intrinsic(sqrt)

typedef unsigned int uint;

extern int __cdecl debug_rand(const char* file, int line);

class RGE_Game_World;
class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    int computerPlayer();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
};

class UnitAIModule_Object {
public:
    char gap_04[0x08];
    RGE_Player* player;
    char gap_10[0x28];
    float world_x;
    float world_y;
    int field_40;
    virtual void d000(); virtual void d004(); virtual void d008(); virtual void d00C();
    virtual void d010(); virtual void d014(); virtual void d018(); virtual void d01C();
    virtual void d020(); virtual void d024(); virtual void d028(); virtual void d02C();
    virtual void d030(); virtual void d034(); virtual void d038(); virtual void d03C();
    virtual void d040(); virtual void d044(); virtual void d048(); virtual void d04C();
    virtual void d050(); virtual void d054(); virtual void d058(); virtual void d05C();
    virtual void d060(); virtual void d064(); virtual void d068(); virtual void d06C();
    virtual void d070(); virtual void d074(); virtual void d078(); virtual void d07C();
    virtual void d080(); virtual void d084(); virtual void d088(); virtual void d08C();
    virtual void d090(); virtual void d094(); virtual void d098(); virtual void d09C();
    virtual void d0A0(); virtual void d0A4(); virtual void d0A8(); virtual void d0AC();
    virtual void d0B0(); virtual void d0B4(); virtual void d0B8(); virtual void d0BC();
    virtual void d0C0(); virtual void d0C4(); virtual void d0C8(); virtual void d0CC();
    virtual void d0D0(); virtual void d0D4(); virtual void d0D8(); virtual void d0DC();
    virtual void d0E0(); virtual void d0E4(); virtual void d0E8(); virtual void d0EC();
    virtual void d0F0(); virtual void d0F4(); virtual void d0F8(); virtual void d0FC();
    virtual void d100(); virtual void d104(); virtual void d108();
    virtual float getSpeed(); // +0x10C
};

class UnitAIModule {
public:
    virtual void d000(); virtual void d004(); virtual void d008(); virtual void d00C();
    virtual void d010(); virtual void d014(); virtual void d018(); virtual void d01C();
    virtual void d020(); virtual void d024(); virtual void d028(); virtual void d02C();
    virtual void d030(); virtual void d034(); virtual void d038(); virtual void d03C();
    virtual int findTarget(int a, int b, int c, int d, int e);      // +0x40
    virtual void d044(); virtual void d048(); virtual void d04C();
    virtual void d050(); virtual void d054(); virtual void d058(); virtual void d05C();
    virtual void d060(); virtual void d064(); virtual void d068(); virtual void d06C();
    virtual void command(int id, int flag);                         // +0x70
    virtual void d074(); virtual void d078(); virtual void d07C();
    virtual void d080(); virtual void d084(); virtual void d088(); virtual void d08C();
    virtual void d090(); virtual void d094(); virtual void d098();
    virtual void move(float x, float y, int z, int flag);            // +0x9C
    virtual void d0A0(); virtual void d0A4(); virtual void d0A8(); virtual void d0AC();
    virtual void d0B0(); virtual void d0B4(); virtual void d0B8(); virtual void d0BC();
    virtual void d0C0(); virtual void d0C4(); virtual void d0C8(); virtual void d0CC();
    virtual void d0D0(); virtual void d0D4(); virtual void d0D8(); virtual void d0DC();
    virtual int chooseSomething(int a, void* out);                   // +0xE0

    UnitAIModule_Object* obj;
    int processIdle(int param);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
};

int TribePriestUnitAIModule::processIdle(int param_1)
{
    if (!this->obj->player->computerPlayer()) {
        return 5;
    }

    int status = UnitAIModule::processIdle(1);
    if (status != 6) {

    int range = *(int*)0x87D7D8;
    int r = debug_rand((const char*)0x588AE8, 0x6AC) % (range + 2);
    if (range > 0 && r > range) {
        int local_4;
        int action = this->chooseSomething(1, &local_4);
        if (action != -1) {
            this->command(action, 0);
            return 6;
        }
    }

    int targetId = this->findTarget(-1, 2, -1, -1, 0);
    if (targetId == -1) {
        return 5;
    }

    RGE_Static_Object* target = this->obj->player->world->object(targetId);
    if (target == 0) {
        return 5;
    }

    float yDiff = target->world_y - this->obj->world_y;
    float xDiff = target->world_x - this->obj->world_x;
    float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
    float distanceDiff = this->obj->getSpeed() - dist;

    if (distanceDiff <= *(float*)0x5758C4) {
        return 5;
    }

    float nx = this->obj->world_x - (xDiff / dist) * distanceDiff;
    float ny = this->obj->world_y - (yDiff / dist) * distanceDiff;
    this->move(nx, ny, this->obj->field_40, 1);
    }
    return 6;
}
