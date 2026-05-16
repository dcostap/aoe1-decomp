// VA: 00535610 RGE_View::draw_object_outline
// Source: view.cpp lines 2062-2207
// Attempt log:
// 1: broad natural reconstruction from packet: selected object, screen bounds, hit-test, bbox/project, draw outline/sprite and reset globals; after compile fixes object is too small (640 vs 665).
// 2: tried /Ob0 flag probe; no size change, flag removed.
// 3: tried /O1 /Oy flag probe; object shrank to 556 and failed configured size, flag removed.
// 4: reviewed original stack locals: eight short bbox/projection locals plus frame byte and coords; current source uses approximate uninitialized locals and wrong project signature.
// 5: reviewed original early screen bounds and hit-test call; current source matches behavior loosely but not exact argument/local shape.
// 6: original calls object vtable +24/+20/+34 and helper 00454690; current source fakes project/draw calls and misses exact helper surface.
// 7: original computes outline color from camera flags and selected result; modeled but scheduling/registers are likely wrong.
// 8: original special draw path depends on game mode/submode and view+174; modeled approximately.
// 9: final state remains too small (640 vs 665); no byte diff available.
// 10: left in scratch: needs real RGE_View/RGE_Static_Object draw/projection type surfaces and exact local short topology before matching.

#define g_game (*(Game**)0x0062C574)
#define g_outline_color (*(int*)0x0086BBF0)
#define g_outline_y (*(int*)0x0086BBE0)

class Player { public: int computerPlayer(); };
class GameMap { public: char gap[0x24]; void** objects; };
class Game { public: char gap0[0x1B4]; int mode; int submode; char gap1[0x240]; short selected_id; char gap2[0x40]; void** players; GameMap* getMap(); void getMouseMapPos(int*); };
class Drawable {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int draw(int, int, void*, int, int, int, int, int, int); // +20
    virtual void get_world_box(float*, float*, void*, int); // +24
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void draw_outline(int, int, int, void*, int, int, int, int); // +34
    char gap_04[0x18-4];
    int has_sprite;
    char gap_1C[0x64-0x1C];
    unsigned char player_id;
    char gap_65[0xA8-0x65];
    unsigned char flags_a8;
    unsigned char color_a9;
};
class RGE_View {
public:
    char gap0[0x20];
    int screen; // +20
    char gap24[0x8C-0x24];
    int minx; int miny; int maxx; int maxy;
    char gap9C[0xFC-0x9C];
    void* camera;
    char gap100[0x174-0x100];
    void* special;
    unsigned char hit_test(int,int,int,int,int*);
    int project(int*, int*, int, int, int, int);
    void draw_object_outline();
};

void RGE_View::draw_object_outline()
{
    int mouse[2];
    float wx, wy;
    short x1,y1,x2,y2,x3,y3,x4,y4;
    int sx, sy;
    unsigned char frame_color;

    short id = g_game->selected_id;
    if (id == -1) return;
    GameMap* map = g_game->getMap();
    Drawable* obj = (Drawable*)map->objects[id];
    if (!obj) return;
    g_game->getMouseMapPos(mouse);
    if (mouse[0] < this->minx || mouse[0] > this->maxx || mouse[1] < this->miny || mouse[1] > this->maxy) return;
    if (this->hit_test(mouse[0]-this->minx, mouse[1]-this->miny, 0x28, 0, (int*)&wx) != 0x33) return;
    obj->get_world_box(&wx, &wy, this->camera, 0);
    if (!this->project((int*)&wx, (int*)&wy, (int)&x1, (int)&y1, 1, 0)) return;
    obj->draw(mouse[0], mouse[1], g_game->getMap(), 0, 1, obj->player_id, 0, 1, 1);
    g_outline_color = 1;
    if (!obj->draw(mouse[0], mouse[1], 0, 0, 0, 0, 0, 0, 0)) {
        g_outline_color = 5;
    } else {
        int c = (((int*)this->camera)[1] >> 7) & 7;
        if (c < 4) c += 0x24; else c = 0x2c - c;
        g_outline_color = (c << 4) | 9;
    }
    sx = (x1 + x2) / 2 + y3;
    sy = (y1 + y2) / 2 + x3;
    if (obj->has_sprite) {
        g_outline_y = sy;
        int translucent = obj->flags_a8 & 1;
        frame_color = obj->draw(mouse[0], mouse[1], 0,0,0,0,0,0,0) ? 0x97 : obj->color_a9;
        if (g_game->mode == 8 && g_game->submode == 1 && this->special) {
            obj->draw_outline(this->screen, sx, sy, (void*)((int*)this->special)[3], *(unsigned char*)((char*)this->special+0x35), 0, translucent, frame_color);
        } else {
            obj->draw_outline(this->screen, sx, sy, g_game->getMap(), 0, 0, translucent, frame_color);
        }
    }
    g_outline_color = 0;
}
