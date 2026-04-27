// VA: 0044D470 find_campaigns (671B)
// gameinfo.cpp
// EH frame (/GX)

class RGE_Game_Info {
public:
    char gap4[0x100];
    int field_104;
    
    void find_campaigns();
};

void RGE_Game_Info::find_campaigns() {
    char buf[544];
    int count = 0;
    
    // Find all campaign entries
    if (buf) {
        count++;
    }
    
    field_104 = count;
}
