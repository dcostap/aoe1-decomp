// VA: 0046FC40 load_master_object (617B)
// player.cpp
// EH frame (/GX), jump table

class RGE_MasterObject {
public:
    int field_0;
    
    RGE_MasterObject(int a1, int a2, int a3);
};

class RGE_Player {
public:
    char gap4[0x84];
    int field_88;
    
    void load_master_object(int fd, int index);
};

void* __cdecl operator_new(unsigned size);

void RGE_Player::load_master_object(int fd, int index) {
    index &= 0xFF;
    
    switch (index - 10) {
    case 0:  // 10
    case 11: // 21
    case 12: // 22
    case 13: // 23
    case 14: // 24
    case 15: // 25
    case 16: // 26
    case 17: // 27
    case 34: // 44
        {
            RGE_MasterObject* obj = new RGE_MasterObject(fd, 1, 1);
            if (obj) {
                // Store
            }
        }
        break;
    default:
        break;
    }
}
