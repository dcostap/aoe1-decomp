class PathingSystem {
public:
    int passable(void* object, float x, float y, int value);
};

extern PathingSystem aiPathSystem;
extern PathingSystem pathSystem;

class RGE_Moving_Object {
public:
    virtual int passableTile(float x, float y, int mode);
};

int RGE_Moving_Object::passableTile(float x, float y, int mode) {
    if (mode != 0) {
        return aiPathSystem.passable(this, x, y, 1);
    }
    return pathSystem.passable(this, x, y, 1);
}
