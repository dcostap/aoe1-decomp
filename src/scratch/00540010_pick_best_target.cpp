// VA: 00540010 pick_best_target (823B)
// vw_main.cpp

class TRIBE_View_World {
public:
    char gap4[0x100];
    
    int pick_best_target(int* out);
};

int TRIBE_View_World::pick_best_target(int* out) {
    if (out) {
        *out = 0;
    }
    
    return 0;
}
