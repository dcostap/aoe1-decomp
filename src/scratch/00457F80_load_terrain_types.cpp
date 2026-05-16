// VA: 00457F80 RGE_Map::load_terrain_types
// Attempt log:
// initial rough reconstruction from packet: fopen/fscanf terrain records, fill terrain type table and borders/sounds.
// modeled initial 32 terrain enabled-byte clear at stride 0x198 and fopen/fclose/fscanf surfaces.
// modeled first terrain_count read, per-record giant fscanf, id range checks, terrain struct address formula, and 19 border-pair reads.
// modeled sound-id remap reads, color/passability/name/pict copies, animation/frame fields, and float-to-short frame-rate conversion path.
// current source reaches same 762B size but has broad frame/layout drift from offset 2: original `sub esp,5c`, rebuilt `sub esp,64`, indicating stack locals/record format are still wrong.
// many local widths/order and terrain field offsets are approximate; not accepted_drift-safe.

extern "C" void* __cdecl fopen(char*, char*);
extern "C" int __cdecl fscanf(void*, char*, ...);
extern "C" int __cdecl fclose(void*);
extern "C" int __cdecl atoi(char*);
extern "C" void __cdecl strcpy(char*, char*);
extern "C" int __cdecl terrain_name_fix(char*);
extern "C" short __cdecl float_to_short(float);

struct TerrainType { char enabled; char name[13]; char pict[13]; int slp; int sound; int terrain_to_draw; char low, med, high, cliff1, cliff2, passable, impassable, animated, frames, random; short border[16]; short sound_id; short border_num; short color1; short color2; float frame_rate; int delay; int frame_count; short frame_count2; char pad[0x198-0x48]; };
class RGE_Map { public:
    char gap[0x8c]; TerrainType terrain[32]; char gap2[0x8d90-0x32ec]; short terrain_count;
    void load_terrain_types(char*, void**);
};

void RGE_Map::load_terrain_types(char* filename, void** sounds)
{
    int i;
    for (i=0; i<32; ++i) this->terrain[i].enabled = 0;
    void* f = fopen(filename, (char*)0x0057F320);
    if (!f) return;
    fscanf(f, (char*)0x005804E8, &this->terrain_count);
    if ((short)(this->terrain_count - 1) < 0) { fclose(f); return; }
    int left = this->terrain_count;
    while (left--) {
        short id, sound_id, low, med, hi, lc, rc, pass, impass, anim, frames, random, draw, border_num;
        int slp, interval, infile;
        float frame_rate, delay;
        char name[20], pict[20];
        if (fscanf(f, (char*)0x00584B44, &id, name, pict, &slp, &sound_id, &low, &med, &hi, &lc, &rc, &pass, &impass, &anim, &frames, &interval, &random, &draw, &infile, &frame_rate, &delay) == -1) break;
        if (id < 0 || id >= 32) continue;
        TerrainType* t = &this->terrain[id];
        t->delay = 19;
        for (i=0; i<t->delay; ++i) {
            short a,b;
            fscanf(f, (char*)0x0058488C, &a, &b);
            t->border[i*2] = a;
            t->border[i*2+1] = b;
            t->border_num = 0;
        }
        short count;
        for (i=0; i<sound_id; ++i) {
            short idx, snd;
            fscanf(f, (char*)0x0058488C, &idx, &snd);
            t->border[idx] = snd;
        }
        t->sound = (sound_id >= 0) ? (int)sounds[sound_id] : 0;
        t->high = (char)hi; t->med = (char)med; t->low = (char)low; t->cliff1 = (char)lc; t->cliff2 = (char)rc;
        t->passable = (char)pass; t->impassable = (char)impass;
        terrain_name_fix(name); strcpy(t->name, name); strcpy(t->pict, pict);
        t->slp = slp; t->sound_id = 0; t->enabled = 1; t->color1 = (short)anim; t->color2 = (short)frames; t->animated=(char)random; t->frame_count=(short)draw;
        if (frame_rate == 0.0f) t->frame_count2 = 0; else t->frame_count2 = float_to_short(delay / frame_rate);
        t->frame_rate = frame_rate; t->frame_count = (int)delay; t->border_num = 0; t->random = 0; t->frames = 0; t->sound_id = (short)interval;
    }
    fclose(f);
}
