struct XYZPoint { float x, y, z; };
class Path;

class RGE_Static_Object {
public:
    virtual Path * findAvoidancePath(XYZPoint &, float, int);
};

Path * RGE_Static_Object::findAvoidancePath(XYZPoint &a, float b, int c) {
    return 0;
}
