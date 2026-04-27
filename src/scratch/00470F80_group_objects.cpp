// VA: 00470F80 group_objects (305B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x28];
    int* field_28;
    char gap2C[0x170];      // up to +0x19C
    short groupCount;       // +19C
    char groupSlots[0x80];  // +19E
    
    int group_objects(int groupNum);
};

int RGE_Player::group_objects(int groupNum) {
    if (groupCount == 0) return 0;
    
    if (groupNum == -1) {
        // Auto-assign group
        int slot = 0x0B;
        while (slot < 0x7F) {
            if (!groupSlots[slot]) {
                break;
            }
            slot++;
        }
        groupNum = slot;
        
        if (slot >= 0x7F) {
            // No free slot - group is full, reset
            // Clear all group slots
            // Set groupCount = 0
            groupNum = 0;
        }
    }
    
    return groupNum;
}
