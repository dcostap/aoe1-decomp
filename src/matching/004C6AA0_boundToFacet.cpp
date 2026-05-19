// VA: 004C6AA0 boundToFacet (162B)
// stat_obj.cpp

extern "C" double __cdecl atan2(double, double);

class RGE_Static_Object {
public:
    char gap_00[0x10];
    void* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    int boundToFacet(float x, float y, int facet_num);
};

int RGE_Static_Object::boundToFacet(float x, float y, int facet_num)
{
    int best = -1;
    float best_diff = 0.0f;
    float angle = (float)atan2(this->world_y - y, this->world_x - x);
    if (angle < 0.0f) {
        angle = angle - -6.2831855f;
    }
    float cur = 0.0f;
    if (facet_num == -1) {
        facet_num = (int)*(short*)((char*)this->sprite + 0x60);
    }
    float step = 6.2831855f / (float)facet_num;
    for (int i = 0; i < facet_num; i++) {
        float diff = angle - cur;
        if (diff < 0.0f) {
            diff = -diff;
        }
        if (best == -1 || diff < best_diff) {
            best_diff = diff;
            best = i;
        }
        cur = cur + step;
    }
    return best;
}
