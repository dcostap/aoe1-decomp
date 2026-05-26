// 004C2400 capture_frame_3d_square - rough reconstruction
// Attempts:
// - Packet shows a large render/capture routine: choose sprite/frame offsets depending on global game view mode and object flags; project four 3D square corners via camera/map transform; submit outline/poly draw call; handle special player-color/minimap/chat marker paths; finally restore/register screen state.
// - Modeled only the high-level offset/color/corner projection shape locally. Exact match needs real RGE_Static_Object/sprite/camera types and renderer function surfaces; current source is a notebook, not a match candidate.
struct Player { char pad[0x3c]; void* map; };
struct Sprite { char pad30[0x78]; unsigned char flagA8; unsigned char colorA9; int xAC; int yB0; int zB4; };
struct Obj { char pad0[4]; int player; char pad8[4]; Player* owner; char pad10[0x18]; short screen_x; short screen_y; char pad2c[0x0a]; unsigned char flags36; unsigned char flags37; char pad38[0x40]; int color78; };
extern int dword_62C50C; extern void* rge_base_game; extern int dword_86BBDC; extern int dword_86BBF8;
extern int __cdecl draw_poly_0053B220(int,...);
class Camera { public: void project(short*, short*, float, float, int, int, int); };
class RGE_Static_Object { public: int vptr; int owner_id; Sprite* sprite; Player* player; char pad10[0x18]; short sx; short sy; char pad2c[0x0a]; unsigned char flags36; unsigned char flags37; char pad38[0x40]; int color78; void capture_frame_3d_square(int,int); };
void RGE_Static_Object::capture_frame_3d_square(int xoff,int yoff){
    Camera* cam = *(Camera**)((char*)this->player->map+0x28);
    int x,y,z; unsigned char color;
    if (*(unsigned char*)((char*)rge_base_game+0x50)==3) { x=this->sprite->pad30[0]; y=this->sprite->pad30[4]; z=this->sprite->pad30[8]; }
    else { x=this->sprite->xAC; y=this->sprite->yB0; z=this->sprite->zB4; }
    if (dword_62C50C==1 && this->color78==this->owner_id && this->owner_id>=0) color=0; else if (!(this->flags36&1)) color=(*(unsigned char*)((char*)rge_base_game+0x50)==3)?0x74:((this->sprite->flagA8&1)&&*(int*)((char*)rge_base_game+0x1b0)==7?this->sprite->colorA9:0xff); else color=0xff;
    if (this->flags36&2) color=0x4a; if (this->flags36&4) color=0x97;
    short p[16]; int sx=xoff+this->sx, sy=yoff+this->sy;
    cam->project(&p[0],&p[1],(float)x,-(float)y,0,sx,sy); cam->project(&p[2],&p[3],(float)x,(float)y,0,sx,sy); cam->project(&p[4],&p[5],-(float)x,(float)y,0,sx,sy); cam->project(&p[6],&p[7],-(float)x,-(float)y,0,sx,sy);
    draw_poly_0053B220(1,sx,(int)p[0],(int)p[1],(int)p[2],(int)p[3],(int)p[4],(int)p[5],(int)p[6],(int)p[7],10,(int)color,dword_86BBDC);
}
