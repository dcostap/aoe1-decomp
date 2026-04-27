// VA: 0052DD10 pick_weight (265B)
// tvw_main.cpp

class TRIBE_Diamond_Map_View {
public:
    char gap4[0x100];
    
    int pick_weight(int obj);
};

int TRIBE_Diamond_Map_View::pick_weight(int obj) {
    int* objType = *(int**)((char*)obj + 8);
    if (!objType) return 0;
    
    unsigned char typeByte = *(unsigned char*)((char*)objType + 0x8D);
    short typeId = *(short*)((char*)objType + 0x10);
    
    // Compare against known types for weight
    if (typeId == 0x4F || typeId == 0xC7 || typeId == 0x45) {
        return typeByte;
    }
    
    return 0;
}
