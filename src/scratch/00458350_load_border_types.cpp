// 00458350 RGE_Map::load_border_types
// Attempt log:
// 1: packet/decompiler based implementation with local border-type layout and fscanf/fopen/fclose surfaces: compiles same size 679 but broad mismatch starts at prologue (0x54 frame vs original 0x58; EBP=this vs original EDI=this).
// 2: current behavior model covers clearing 16 border slots, fopen/fscanf/fclose, per-border table reads, string uppercase/copy, sound lookup, timing fields, and nested 19x12 tile table scan.
// 3: blocker: local variable layout and register basin are wrong from entry; original uses EDI as this and EBP as FILE*, with many exact stack offsets tied to scanf varargs. Rebuilt uses EBP as this and a different frame.
// 4: struct/local layout likely still imperfect (BorderType field packing and scanf argument order), causing broad mismatch; not accepted_drift-safe.
// 5: left in scratch after initial honest implementation/probes; no exact match.

extern "C" void* __cdecl fopen(char*, char*);
extern "C" int __cdecl fscanf(void*, char*, ...);
extern "C" int __cdecl fclose(void*);
extern "C" void __cdecl strupr(char*);
extern "C" long __cdecl atol(char*);

class RGE_Map {
public:
    char pad0[0x338c];
    struct BorderType {
        unsigned char used; char name[13]; char alt_name[13]; int sound; unsigned char frames; unsigned char animated; unsigned char tile_flag; unsigned char underlay; short terrain; short frame_count; short delay; int width; int height; short zero38; short zero3a; int zero3c; unsigned char b40; unsigned char b41; char pad42[0x59a-0x42]; unsigned char border_style; short sound_id; short extra;
    } borders[16];
    char pad8d8c[0x8d92 - 0x338c - 16*sizeof(BorderType)];
    short border_type_count;
    void load_border_types(char* filename, void** sounds);
};

void RGE_Map::load_border_types(char* filename, void** sounds)
{
    for (int i = 0; i < 16; ++i) {
        this->borders[15 - i].used = 0;
    }
    void* fp = fopen(filename, (char*)"rt");
    if (!fp) return;
    fscanf(fp, "%hd", &this->border_type_count);
    short count = this->border_type_count;
    if (--count < 0) { fclose(fp); return; }
    int outer = (int)count + 1;
    do {
        short border_num;
        short sound_id;
        short low_color;
        short med_color;
        short hi_color;
        short is_animated;
        short animation_frames;
        short tile_flag;
        short underlay_terrain;
        short border_style;
        short extra;
        char name[16];
        char alt_name[16];
        int width;
        int height;
        float frame_rate;
        float total_time;
        if (fscanf(fp, "%hd %s %s %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %f %f %hd %hd",
                   &border_num, name, alt_name, &sound_id, &low_color, &med_color, &hi_color,
                   &is_animated, &animation_frames, &tile_flag, &underlay_terrain, &border_style,
                   &width, &height, &frame_rate, &total_time, &extra, &extra) == -1) break;
        if (border_num >= 16 || border_num < 0) break;
        BorderType* bt = &this->borders[border_num];
        int sum = 0;
        short* p = (short*)((char*)bt + 0x42);
        for (int row = 0; row < 0x13; ++row) {
            for (int col = 0; col < 0x0c; ++col) {
                fscanf(fp, "%hd %hd", p, p + 1);
                p[1] = 0;
                sum += p[0] * p[1];
                p += 3;
            }
        }
        if (sound_id >= 0) bt->sound = (int)sounds[sound_id]; else bt->sound = 0;
        bt->frames = (unsigned char)is_animated;
        bt->animated = (unsigned char)animation_frames;
        bt->tile_flag = (unsigned char)tile_flag;
        strupr(name);
        char* dst = bt->name;
        char* src = name;
        while ((*dst++ = *src++) != 0) {}
        dst = bt->alt_name;
        src = alt_name;
        while ((*dst++ = *src++) != 0) {}
        bt->used = 1;
        bt->width = width;
        bt->underlay = (unsigned char)underlay_terrain;
        bt->terrain = border_style;
        if (frame_rate == 0.0f) bt->delay = 0; else bt->delay = (short)(long)(total_time / frame_rate);
        bt->height = height;
        bt->zero38 = 0;
        bt->zero3a = 0;
        bt->zero3c = 0;
        bt->b40 = 0;
        bt->b41 = 0;
        bt->border_style = (unsigned char)border_style;
        bt->sound_id = sound_id;
        bt->extra = extra;
    } while (--outer != 0);
    fclose(fp);
}
