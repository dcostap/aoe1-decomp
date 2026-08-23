// 00523750 TRIBE_Game::show_status_message
// tribegam.cpp, 69 bytes. MATCH.
//
// Fix: both calls use the start of str, not str+4. The original LEA
// expressions occur at different stack depths but resolve to the same buffer
// address. The earlier scratch incorrectly compensated with str+4.

#include "../../include/tribegam_context.h"

#if 0
class RGE_Base_Game {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual int get_string(int string_id, char* buffer, int length);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(int string_id, char* param_2, long param_3);
    void show_status_message(char* param_1, char* param_2, long param_3);
};
#endif

void TRIBE_Game::show_status_message(int string_id, char* param_2, long param_3) {
    char str[0x100];
    this->get_string((long)string_id, str, 0x100);
    this->show_status_message(str, param_2, param_3);
}
