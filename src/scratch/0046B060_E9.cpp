#ifndef PATHSYS_TU_CONTEXT
class RGE_Map;
class RGE_Game_World;
class PathingSystem {
public:
    PathingSystem(int x_size, int y_size, int ai_ps, RGE_Map* map, RGE_Game_World* world);
};

extern PathingSystem pathSystem;
#endif

extern void* operator new(unsigned int, void* ptr);

void E9() {
    new (&pathSystem) PathingSystem(0xFF, 0xFF, 0, 0, 0);
}
