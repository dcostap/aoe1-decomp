class RGE_Map;
class RGE_Game_World;

class PathingSystem {
public:
    void initialize(int x_size, int y_size, int ai_ps, RGE_Map* map, RGE_Game_World* world);
};

extern PathingSystem pathSystem;

void E9() {
    pathSystem.initialize(0xFF, 0xFF, 0, 0, 0);
}
