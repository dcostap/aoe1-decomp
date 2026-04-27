// VA: 0041F2D0 RGE_Base_Game::setup_shapes (289 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: calloc shape array, alloc 3 TShapes (groupnum.shp, waypoint.shp, moveto.shp)

extern void* calloc(int num, int size);
extern void* operator_new(unsigned int size);
extern int TShape_ctor(void* shape, const char* name, int id);

struct Shim_1F2D0 {
    char p0[0x58];
    short shape_num;           // +0x58 (word)
    char p5A[0x5C - 0x5A];
    void** shapes;             // +0x5C
};

int RGE_Base_Game_setup_shapes(Shim_1F2D0* self)
{
    void* s;
    void** arr;
    int i;
    
    self->shape_num = 3;
    arr = (void**)calloc(3, 4);
    self->shapes = arr;
    if (!arr)
        return 0;
    
    for (i = 0; i < self->shape_num; i++)
        arr[i] = 0;
    
    s = operator_new(0x20);
    if (s)
        TShape_ctor(s, "groupnum.shp", 0xC4E3);
    self->shapes[0] = s;
    
    s = operator_new(0x20);
    if (s)
        TShape_ctor(s, "waypoint.shp", 0xC4E4);
    self->shapes[1] = s;
    
    s = operator_new(0x20);
    if (s)
        TShape_ctor(s, "moveto.shp", 0xC4E5);
    self->shapes[2] = s;
    
    return 1;
}
