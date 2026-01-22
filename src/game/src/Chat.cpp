#include "../include/TChat.h"
#include <string.h>

TChat::TChat(void* p1) {
    memset(this, 0, sizeof(TChat));
    this->HostWnd = p1;
}
