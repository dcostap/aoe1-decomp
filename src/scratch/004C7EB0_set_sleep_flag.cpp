// VA: 004C7EB0 | RGE_Static_Object::set_sleep_flag(uchar) | stat_obj.cpp:5037-5064 | 115 bytes
//
// Attempt log:
// [1] VTableProxy approach. Branch order wrong (set before unsleep).
// [2] Fixed branch order. 47% diff. Main issues: register swap (ecx/edi vs edi/ecx
//     for field50/owner), xor eax,eax before funcDC, different vtable slot register.
// [3] Extra temp locals made it worse (extra ebx save). Reverting to [2].
//
// Remaining gap is register allocation in the unsleep path:
// - Original: edi=field50, ecx=owner, ebp=owner_vtable
// - Rebuilt:  ecx=field50, edi=owner, ebp=owner_vtable
// This swaps which register holds field50 vs owner, cascading through the
// vtable call setups. Also: extra xor eax,eax before funcDC call.

#include "../../include/game_types.h"

struct PlayerVTableProxy {
    virtual void _d00(); virtual void _d01(); virtual void _d02(); virtual void _d03();
    virtual void _d04(); virtual void _d05(); virtual void _d06(); virtual void _d07();
    virtual void _d08(); virtual void _d09(); virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void _d40(); virtual void _d41(); virtual void _d42(); virtual void _d43();
    virtual void _d44(); virtual void _d45(); virtual void _d46(); virtual void _d47();
    virtual void _d48(); virtual void _d49(); virtual void _d50(); virtual void _d51();
    virtual void _d52(); virtual void _d53(); virtual void _d54();
    virtual int funcDC(void* obj, int zero, int doppleFlag);
    virtual int funcE0(void* obj, int sleepFlag, int doppleFlag, int field50);
};

class RGE_Static_Object {
public:
    void** vtable;
    char _gap_04[0x08];
    class RGE_Player* owner;
    char _gap_10[0x39];
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    char _gap_4C[0x04];
    int player_object_node;

    void set_sleep_flag(unsigned char newFlag);
};

void RGE_Static_Object::set_sleep_flag(unsigned char newFlag) {
    if (sleep_flag == newFlag) return;

    if (newFlag == 0) {
        if (goto_sleep_flag != 0) {
            sleep_flag = 0;
            goto_sleep_flag = 0;
            return;
        }

        int oldField = player_object_node;
        PlayerVTableProxy* p = (PlayerVTableProxy*)owner;
        p->funcE0(this, (int)(unsigned char)sleep_flag, (int)dopple_flag, oldField);

        sleep_flag = 0;
        player_object_node = p->funcDC(this, 0, (int)dopple_flag);
        return;
    }

    goto_sleep_flag = 1;
    sleep_flag = newFlag;
}
