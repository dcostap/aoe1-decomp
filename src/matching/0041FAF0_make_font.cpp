// VA: 0041FAF0 RGE_Base_Game::make_font (203 B)
// PDB source: basegame.cpp lines 2909-2930
//
// Attempt log:
// baseline: natural locale-string lookup, atoi/style parsing, and direct same-class
// make_font overload call; local virtual surface exposes the observed vslot +0x20.

extern "C" int __cdecl atoi(const char*);
extern "C" char* __cdecl strstr(const char*, const char*);

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual char* get_string(long id, char* buf, int maxlen);

    void* make_font(void* param1, char* name, int size, int weight, int italic);
    void* make_font(void* param1, long id, int italic);
};

void* RGE_Base_Game::make_font(void* param1, long id, int italic)
{
    char face_name[256];
    char point_size_str[10];
    char style[10];
    int point_size;
    int weight;

    this->get_string(id, face_name, 0x100);
    if (face_name[0] == 0)
        return 0;

    this->get_string(id + 1, point_size_str, 10);
    point_size = atoi(point_size_str);

    this->get_string(id + 2, style, 10);
    if (strstr(style, "B") != 0 || strstr(style, "b") != 0)
        weight = 700;
    else
        weight = 400;

    return this->make_font(param1, face_name, point_size, weight, italic);
}
