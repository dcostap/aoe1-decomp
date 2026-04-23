#include <new>

class RGE_Map;
class RGE_Game_World;

class PathingSystem {
public:
    PathingSystem(int x_size, int y_size, int ai_ps, RGE_Map* map, RGE_Game_World* world);
};

extern PathingSystem aiPathSystem;

void E14() {
    new (&aiPathSystem) PathingSystem(0xFF, 0xFF, 1, 0, 0);
}
