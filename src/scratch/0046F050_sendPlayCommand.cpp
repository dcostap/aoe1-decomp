// VA: 0046F050 RGE_Player::sendPlayCommand(int,int,int)
// Baseline reconstruction: send the command through the player's AI playbook,
// then serialize the selected object ids for the selected-unit command.
// Attempt log:
// - Natural typed reconstruction reached the correct 0x64 frame, 5 calls, and 237-byte boundary.
// - Corrected the playbook lookup from param_2 to param_3; this reduced the strict diff to 7 bytes.
// - Tried loop/declaration/register/layout/context variants; all retained the same 7-byte register-coloring drift.
// - Remaining drift is vtable register EBP versus EBX and loop counter EBX versus EBP; no opaque codegen scaffold retained.
// - Tried a natural indexed selected-list loop; VC5 canonicalized it to the same 7-byte output.
// - Corrected the proven unsigned-char return widths of the v_c4/v_d0 command slots; caller output stayed unchanged.

class AIPlay;
class AIPlayBook { public: AIPlay* play(int id); };
class RGE_Game_World { public: char gap_00[0xA0]; AIPlayBook* playbook; };

class RGE_Static_Object {
public:
    virtual void vf00();
    int id;
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Player {
public:
    VPAD8(0) VPAD4(8)
    virtual void send_signal(int player_id, int p1, int cmd, int a, int b, int f1, int f2, int f3, int f4, int one, int zero, int hundred);
    VPAD32(13) VPAD4(45)
    virtual unsigned char v_c4(int a, int* p, int b, int flag);
    VPAD2(50)
    virtual unsigned char v_d0(int a);

    char gap_04[0x38];
    RGE_Game_World* world;      // +0x3C
    char gap_40[0x0A];
    short id;                   // +0x4A
    char gap_4C[0xE8];
    RGE_Static_Object* sel_list[25]; // +0x134

    virtual void sendPlayCommand(int param_1, int param_2, int param_3);
};

void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3)
{
    int selectedUnits[25];
    int selectedCount;
    int* selectedUnit;
    RGE_Static_Object** source;

    this->v_d0(param_1);
    AIPlay* play = this->world->playbook->play(param_3);
    if (play == 0) {
        this->send_signal((int)this->id, param_1, 0x2d7, -1, -1,
                          0xbf800000, 0xbf800000, 0xbf800000, 0xbf800000, 1, 0, 100);
        return;
    }

    selectedCount = 0;
    selectedUnit = selectedUnits;
    source = this->sel_list;
    for (int n = 25; n != 0; ++source, --n) {
        RGE_Static_Object* object = *source;
        if (object != 0) {
            ++selectedCount;
            *selectedUnit = object->id;
            ++selectedUnit;
        }
    }

    if (selectedCount != 0) {
        this->v_c4(param_1, selectedUnits, selectedCount, 0x40000000);
        this->send_signal((int)this->id, param_1, 0x2d6, param_2, param_3,
                          0xbf800000, 0xbf800000, 0xbf800000, 0xbf800000, 1, 0, 100);
    }
}
