// 004C1840 RGE_Static_Object::setup attempt
// initial source from packet: natural rge_read sequence and managed int-array append loops.

extern void rge_read(int file, void* buf, int len);
extern void* operator new(unsigned int);
extern void operator delete(void*);

#define save_game_version (*(float*)0x58EBCC)
#define VER_1 (*(float*)0x574724)
#define VER_2 (*(float*)0x574728)

#define VPAD1(n) virtual void v##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##a)
#define VPAD4(n) VPAD2(n) VPAD2(n##b)
#define VPAD8(n) VPAD4(n) VPAD4(n##c)
#define VPAD16(n) VPAD8(n) VPAD8(n##d)
#define VPAD32(n) VPAD16(n) VPAD16(n##e)
#define VPAD64(n) VPAD32(n) VPAD32(n##f)

struct Obj18 { void setup(int file, int x); };
struct Renderer { void set_static_object(void* obj); };
struct MasterSub { VPAD64(0) VPAD32(64) VPAD16(96) VPAD8(112) VPAD4(120) VPAD2(124) virtual void f126(void*); }; // +0x1f8 maybe unused
struct MasterObj {
    char pad0[0x24];
    void** terrain_table; // +24
    Renderer* rend28; Renderer* rend2c; Renderer* rend30; Renderer* rend34; // +28..34
    char pad38[4];
    MasterSub* sub3c;
};
struct World { char pad0[0x38]; int* arr38; char pad3c[4]; MasterObj** arr40; };

class RGE_Static_Object {
public:
    VPAD64(0) VPAD32(64) VPAD16(96) VPAD8(112)
    virtual int vf120(); // +0x1e0
    virtual Obj18* vf121(); // +0x1e4
    int field04; void* master08; MasterObj* master0c; void* terrain10; int field14; Obj18* obj18; int field1c; int field20; int field24;
    short s28,s2a,s2c,s2e; int f30; unsigned char b34,b35,b36,b37; int f38,f3c,f40,f44; unsigned char b48,b49,b4a,b4b; short s4c; unsigned char b4e,b4f;
    char pad50[4]; int* arr54; int count58; char pad5c[4]; int cap60; int* arr64; int count68; char pad6c[4]; int cap70; char pad74[4]; int f78; char pad7c[4]; int f80; char pad84[2]; unsigned char b86;
    int setup(int file, World* world);
};

int RGE_Static_Object::setup(int file, World* world) {
    int save_file = file;
    int temp1;
    int temp2;
    int numberUnits;
    int count;
    short s;
    int i;

    this->b4e = 10;
    rge_read(save_file, &temp1, 1);
    this->master0c = world->arr40[(unsigned char)temp1];
    rge_read(save_file, &s, 2);
    this->master08 = this->master0c->terrain_table[(short)s];
    rge_read(save_file, &s, 2);
    if (s >= 0) this->terrain10 = (void*)world->arr38[(short)s]; else this->terrain10 = 0;

    this->field14 = 0;
    rge_read(save_file, &temp1, 4);
    if (temp1 == -1) this->field20 = 0; else this->field20 = temp1;
    rge_read(save_file, &this->f30, 4);
    rge_read(save_file, &this->b48, 1);
    rge_read(save_file, &this->b49, 1);
    if (save_game_version >= VER_1) rge_read(save_file, &this->b4a, 1);
    rge_read(save_file, &this->b4b, 1);
    rge_read(save_file, &this->field04, 4);
    rge_read(save_file, &this->b35, 1);
    rge_read(save_file, &this->f38, 4);
    rge_read(save_file, &this->f3c, 4);
    rge_read(save_file, &this->f40, 4);
    rge_read(save_file, &this->s28, 2);
    rge_read(save_file, &this->s2a, 2);
    rge_read(save_file, &this->s2c, 2);
    rge_read(save_file, &this->s2e, 2);
    rge_read(save_file, &this->b37, 1);
    rge_read(save_file, &this->s4c, 2);
    rge_read(save_file, &this->f44, 4);
    rge_read(save_file, &this->b4f, 1);
    rge_read(save_file, &this->b34, 1);
    rge_read(save_file, &this->b86, 1);
    this->field1c = 0;
    rge_read(save_file, &this->f78, 4);
    rge_read(save_file, &this->f80, 4);

    if (save_game_version == VER_2) {
        rge_read(save_file, &numberUnits, 4); rge_read(save_file, &numberUnits, 4); rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &temp2, 4); rge_read(save_file, &temp1, 4); rge_read(save_file, &temp1, 4);
    }

    rge_read(save_file, &count, 4);
    i = 0;
    if (count > 0) {
        do {
            rge_read(save_file, &temp1, 4);
            int n = this->count68;
            int j = 0;
            if (n > 0) {
                int cap = this->cap70;
                while (j < cap) {
                    if (this->arr64[j] == temp1) goto found1;
                    ++j;
                    if (j >= n) break;
                }
            }
            if (this->count68 > this->cap70 - 1) {
                int newcap = this->count68 + 1;
                int* p = (int*)operator new(newcap * 4);
                if (p) {
                    int k = 0;
                    while (k < this->cap70 && k < newcap) { ++k; p[k-1] = this->arr64[k-1]; }
                    operator delete(this->arr64);
                    this->arr64 = p; this->cap70 = newcap;
                }
            }
            this->arr64[this->count68] = temp1;
            this->count68++;
found1:
            ++i;
        } while (i < count);
    }
    rge_read(save_file, &count, 4);
    i = 0;
    if (count > 0) {
        do {
            rge_read(save_file, &temp2, 4);
            int n = this->count58;
            int j = 0;
            if (n > 0) {
                int cap = this->cap60;
                while (j < cap) { if (this->arr54[j] == temp2) goto found2; ++j; if (j >= n) break; }
            }
            if (this->count58 > this->cap60 - 1) {
                int newcap = this->count58 + 1;
                int* p = (int*)operator new(newcap * 4);
                if (p) { int k=0; while (k < this->cap60 && k < newcap) { ++k; p[k-1] = this->arr54[k-1]; } operator delete(this->arr54); this->arr54=p; this->cap60=newcap; }
            }
            this->arr54[this->count58] = temp2;
            this->count58++;
found2:
            ++i;
        } while (i < count);
    }
    this->obj18 = this->vf121();
    this->obj18->setup(save_file, world->arr38[0]);
    this->master0c->sub3c->f126(this);
    if (this->b49) this->master0c->rend2c->set_static_object(this);
    else if (this->b4a) this->master0c->rend30->set_static_object(this);
    else this->master0c->rend28->set_static_object(this);
    this->field24 = this->vf120();
    this->b36 = 0;
    return 1;
}
