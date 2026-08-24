// VA: 0046F140 RGE_Player::sendPlayCommand(int,int*,int,int,int)
// Exact MATCH. Key fixes: padded virtual slots to +0x30/+0xC4/+0xD0, use play(param_5),
// gate command on param_3, and order the two post-command arguments as (param_4,param_5)
// so VC5 right-to-left pushes match original `push ebp; push eax`.

#ifndef PLAYER_GROUPED_TU
class AIPlay;
class AIPlayBook { public: AIPlay* play(int id); };
class RGE_Game_World { public: char gap_00[0xA0]; AIPlayBook* playbook; };

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
    VPAD4(13) VPAD2(17)
    virtual void sendPlayCommand(int, int*, int, int, int);
    VPAD16(20) VPAD8(36) VPAD4(44) VPAD1(48)
    virtual void v_c4(int a, int* p, int b, int flag);
    VPAD2(50)
    virtual void v_d0(int a);

    char gap_04[0x38];
    RGE_Game_World* world;      // +0x3C
    char gap_40[0x0A];
    short id;                   // +0x4A

};
#endif

#ifndef PLAYER_GROUPED_TU
void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5)
{
    this->v_d0(param_1);
    AIPlay* play = this->world->playbook->play(param_5);
    if (play == 0) {
        this->send_signal((int)this->id, param_1, 0x2d7, -1, -1,
                          0xbf800000, 0xbf800000, 0xbf800000, 0xbf800000, 1, 0, 100);
        return;
    }
    if (param_3 != 0) {
        this->v_c4(param_1, param_2, param_3, 0x40000000);
        this->send_signal((int)this->id, param_1, 0x2d6, param_4, param_5,
                          0xbf800000, 0xbf800000, 0xbf800000, 0xbf800000, 1, 0, 100);
    }
}
#else
void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3,
                                 int param_4, int param_5)
{
    this->command_destroy_group(param_1);
    AIPlay* play = this->world->playbook->play(param_5);
    if (play == 0) {
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d7, -1, -1,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }
    if (param_3 != 0) {
        this->command_create_group(param_1, param_2, param_3, 2.0f);
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d6, param_4,
                              param_5, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0,
                              100);
    }
}
#endif
