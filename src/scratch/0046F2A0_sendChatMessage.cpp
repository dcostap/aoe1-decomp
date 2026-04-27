// VA: 0046F2A0 sendChatMessage (251B)
// player.cpp

#include <string.h>

extern int* rge_base_game;
void __cdecl sub_0054C1D0(char* buf, const char* msg, void* stackBuf);
int __cdecl sub_00422650(int* game);
int __cdecl sub_00422D90(int* game, int playerIdx);

class RGE_Player {
public:
    virtual ~RGE_Player();
    
    void sendChatMessage(const char* msg, int a2, int a3);
};

void RGE_Player::sendChatMessage(const char* msg, int a2, int a3) {
    char buf[0x400];
    sub_0054C1D0(buf, msg, (void*)&buf);
    
    if (strlen(msg) == 0) return;
    
    int count = sub_00422650(rge_base_game);
    for (int i = 1; i < count; i++) {
        int res = sub_00422D90(rge_base_game, i);
        if (res == a2) {
            break;
        }
    }
}
