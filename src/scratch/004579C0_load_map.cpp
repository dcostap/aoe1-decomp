// VA: 004579C0 RGE_Map::load_map
// Attempt log:
// initial packet reconstruction of old/new map tile formats with EH new zone list.
// tried /GX for original EH prologue around new RGE_Zone_Map_List; required to get same-size EH frame style.
// first compile used empty RGE_Zone_Map_List and mismatched operator new size 1 vs original 0x0c; added 0x0c pad and first mismatch moved to old/new-format branch distance.
// tried reusing fd parameter as one-byte read scratch to mirror original stack-slot-looking byte temp; register basin got much worse (first mismatch offset 31), rolled back to local unsigned char.
// current best is same-size 643 bytes, first mismatch offset 215, edit diff 15.7076%; remaining drift is broad in inner tile decode scheduling/loop local slots, not accepted_drift-safe.

extern "C" void __cdecl rge_read(int, void*, int);
extern float save_game_version;
extern float old_map_cutoff;

class RGE_Zone_Map_List { public: char pad[0x0c]; RGE_Zone_Map_List(int, void*); ~RGE_Zone_Map_List(); };
class RGE_Visibility_Map { public: void load(int); };
struct Tile { unsigned short a; unsigned short b; unsigned char c,d,e,f,g,h,i,j,k,l; int m; short n; char pad[2]; };
class RGE_Map {
public:
    char gap0[4]; Tile* tiles; int width; int height; char gap1[0x8d8c-0x10]; Tile** rows; char gap2[0x8db8-0x8d90];
    unsigned char flag1; unsigned char flag2; char gap3[0x8dc4-0x8dba]; RGE_Zone_Map_List* zone_map; RGE_Visibility_Map* visibility;
    void new_map(long,long); void load_map(int);
};

void RGE_Map::load_map(int fd)
{
    int local_10, w, x, y;
    unsigned char b;
    rge_read(fd, &local_10, 4);
    rge_read(fd, &w, 4);
    this->new_map(local_10, w);
    RGE_Zone_Map_List* old = this->zone_map;
    if (old != 0) { old->~RGE_Zone_Map_List(); operator delete(old); }
    RGE_Zone_Map_List* nz = new RGE_Zone_Map_List(fd, this);
    this->zone_map = nz;
    rge_read(fd, &this->flag1, 1);
    rge_read(fd, &this->flag2, 1);
    if (!(save_game_version < old_map_cutoff)) {
        y = 0;
        if (this->height > 0) {
            do {
                Tile* t = this->rows[y];
                x = 0;
                if (this->width > 0) {
                    do {
                        rge_read(fd, t, 2);
                        rge_read(fd, ((char*)t)+2, 2);
                        rge_read(fd, ((char*)t)+4, 1);
                        rge_read(fd, &b, 1);
                        t->d = (t->d ^ ((b ^ t->d) & 0x1f));
                        rge_read(fd, &b, 1);
                        t->d = (unsigned char)((b << 5) | (t->d & 0x1f));
                        rge_read(fd, &b, 1);
                        t->e = (t->e ^ ((b ^ t->e) & 0x0f));
                        rge_read(fd, &b, 1);
                        t->f = 0;
                        t->g = (char)0xff;
                        t->e = (unsigned char)((b << 4) | (t->e & 0x0f));
                        t->m = 0; t->n = 0; t->h = 0; t->i = 0; t->j = (char)0xff;
                        ++x; ++t;
                    } while (x < this->width);
                }
                ++y;
            } while (y < this->height);
        }
    } else {
        rge_read(fd, this->tiles, this->width * this->height * 24);
        y = 0;
        if (this->height > 0) {
            do {
                x = 0;
                if (this->width > 0) {
                    do {
                        this->rows[y][x].m = 0;
                        ++x;
                    } while (x < this->width);
                }
                ++y;
            } while (y < this->height);
        }
    }
    this->visibility->load(fd);
}
