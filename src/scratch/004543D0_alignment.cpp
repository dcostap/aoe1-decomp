// VA: 004543D0 alignment (690B)
// m_s_obj.cpp, lines 1021-1088
// RGE_Master_Static_Object::alignment (vt[9], offset 0x24)
// Returns uchar, always 1

class RGE_Game_World;
class RGE_Map;

class RGE_Master_Static_Object {
public:
    // vtable slot 0: destructor
    virtual ~RGE_Master_Static_Object();
    // vt[1]: copy_obj
    virtual void copy_obj(RGE_Master_Static_Object* src);
    // vt[2]: modify
    virtual void modify(float val, unsigned char op);
    // vt[3]: modify_delta
    virtual void modify_delta(float val, unsigned char op);
    // vt[4]: modify_percent
    virtual void modify_percent(float val, unsigned char op);
    // vt[5]: save
    virtual void save(int param_1);
    // vt[6]: make_new_obj
    virtual void* make_new_obj(void* player, float x, float y, float z);
    // vt[7]: make_new_master
    virtual void* make_new_master();
    // vt[8]: check_placement
    virtual unsigned char check_placement(void* player, float x, float y, int* arr,
        unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8,
        unsigned char p9, unsigned char p10);
    // vt[9]: alignment
    virtual unsigned char alignment(float& param_1, float& param_2, RGE_Game_World* param_3, unsigned char param_4);

    // layout: 0xB8 bytes
    char gap_00[0x30];
    float radius_x;       // +0x30
    float radius_y;       // +0x34
    float radius_z;       // +0x38
    char gap_3C[0x7C];
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;         // +0x28
};

class RGE_Map {
public:
    char gap_00[0x8];
    int map_width;        // +0x8
    int map_height;       // +0xC
};

unsigned char RGE_Master_Static_Object::alignment(float& param_1, float& param_2, RGE_Game_World* param_3, unsigned char param_4)
{
    float map_w = (float)param_3->map->map_width - 0.00001f;
    float map_h = (float)param_3->map->map_height - 0.00001f;

    float left = param_1 - radius_x;
    float right = param_1 + radius_x;
    float top = param_2 - radius_y;
    float bottom = param_2 + radius_y;

    if (left < 0.0f) {
        float adj = -left;
        param_1 += adj;
        right += adj;
        left = 0.0f;
    }

    if (top < 0.0f) {
        float adj = -top;
        param_2 += adj;
        bottom += adj;
        top = 0.0f;
    }

    if (right >= map_w) {
        float adj = map_w - right;
        param_1 += adj;
    }

    if (bottom >= map_h) {
        float adj = map_h - bottom;
        param_2 += adj;
    }

    if (param_4 == 0)
        return 1;

    // Sub-pixel alignment
    if (param_1 < 0.0f) param_1 = -param_1;
    if (param_2 < 0.0f) param_2 = -param_2;
    if (right < 0.0f) right = -right;
    if (bottom < 0.0f) bottom = -bottom;

    int ix = (int)param_1;
    float dx = param_1 - (float)ix;

    int iy = (int)param_2;
    float dy = param_2 - (float)iy;

    int ir = (int)right;
    float dr = right - (float)ir;

    int ib = (int)bottom;
    float db = bottom - (float)ib;

    float f1 = 1.0f - dr;
    float f2 = 1.0f - db;

    float sum1 = f1 + dx;
    if (sum1 < 1.0f) {
        param_1 = param_1;
    } else if (dx <= f1) {
        param_1 = param_1 - (1.0f - f1);
    } else {
        param_1 = (1.0f - dx) + param_1;
    }

    float sum2 = f2 + dy;
    if (sum2 >= 1.0f) {
        if (f2 < dy) {
            float temp = param_2;
            param_2 = (1.0f - dy) + temp;
        } else {
            param_2 = param_2 - (1.0f - f2);
        }
    }

    return 1;
}
