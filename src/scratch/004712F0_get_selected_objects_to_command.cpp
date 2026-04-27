// VA: 004712F0 get_selected_objects_to_command (313B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x130];
    int** selectedObjects;  // +134
    short selectedCount;    // +19C
    
    int get_selected_objects_to_command(int* outArr, short* outCount, int commandType);
};

void* __cdecl malloc4(unsigned size);

int RGE_Player::get_selected_objects_to_command(int* outArr, short* outCount, int commandType) {
    *outArr = 0;
    *outCount = 0;
    
    if (selectedCount == 0) return 0;
    
    int* buf = (int*)malloc4(selectedCount * 4);
    
    return 1;
}
