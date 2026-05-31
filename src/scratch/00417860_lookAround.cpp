// VA: 00417860 UnitAIModule::lookAround
// PDB: aiuaimod.cpp lines 3949-3987
// Attempt: implemented full decompiler behavior from packet; tuning against VC5 codegen.

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class UnitAIModule {
public:
    VPAD8(0)                    // slot 8 = +0x20
    virtual void look_around_setup();

    RGE_Static_Object* objectValue; // +0x04
    char gap_08[0x100];
    int lookAroundTimerValue;       // +0x108
    int lookAroundTimeoutValue;     // +0x10C

    void lookAround();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    VPAD32(p0)
    VPAD16(p32)
    VPAD8(p48)
    VPAD2(p56)
    virtual void signal(int obj_id, int owner_id, int command, int target_id, int a, int b); // slot 58 = +0xE8

    char gap_04[0x38];            // +0x04..+0x3B
    RGE_Game_World* world;        // +0x3C
    char gap_40[0x0A];            // +0x40..+0x49
    short id;                     // +0x4A
};

class RGE_Static_Object {
public:
    void* vtable;                  // +0x00
    int id;                        // +0x04
    char gap_08[0x04];             // +0x08
    RGE_Player* owner;             // +0x0C
    char gap_10[0x38];             // +0x10..+0x47
    unsigned char object_state;    // +0x48
};

int __cdecl debug_rand(char* file, int line);

void UnitAIModule::lookAround()
{
    RGE_Game_World* world;
    int ownerID;

    this->look_around_setup();

    int obj_id = this->objectValue->id;
    RGE_Player* owner = this->objectValue->owner;
    ownerID = owner->id;
    world = owner->world;

    for (int off = 0; off > -8; off -= 4) {
        for (int j = 0; j < *(int*)(0x87D7D8 + off); ++j) {
            RGE_Static_Object* obj = world->object(*(int*)(*(int*)(0x87D7F0 + off) + j * 8));
            if (obj != 0 && obj->object_state <= 2) {
                this->objectValue->owner->signal(obj_id, ownerID, 0x20D, obj->id, 0, 0);
            }
        }
    }

    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue = debug_rand((char*)0x57F980, 0xF92) % 1000 + 4000;
}
