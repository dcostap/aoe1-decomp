// VA: 005410E0 RGE_Game_World::data_load_sprites
// Natural /GX load loop from World.cpp packet.
// Attempt: behavior/call surface modeled, but current rebuild is 336/348 bytes;
// register allocation differs early (f kept in EBP/this in ESI instead of original
// f in EBX/this in EDI with delayed ESI/EBP saves). Left in scratch for a focused
// register/liveness source-shape pass.
// FLAGS: config/flags/005410E0_data_load_sprites.rsp

#define S_R ((const char*)0x57F320)
#define S_HD_HD ((const char*)0x58488C)
#define S_HD ((const char*)0x5804E8)

typedef unsigned char uchar;

extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern "C" int __cdecl fscanf(void* file, const char* fmt, ...);
extern "C" int __cdecl fclose(void* file);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Sprite {
public:
    char pad[0x78];
    RGE_Sprite(short id);
    RGE_Sprite(void* file, short id, void* master_sprites);
};

class RGE_Game_World {
public:
    char pad_00[0x30];
    void* master_sprites;
    short sprite_count;
    short file_sprite_count;
    RGE_Sprite** sprites;

    uchar data_load_sprites(char* filename);
};

uchar RGE_Game_World::data_load_sprites(char* filename) {
    void* f;
    short id;
    int i;
    int j;
    RGE_Sprite* sprite;

    f = fopen(filename, S_R);
    if (f != 0) {
        if (fscanf(f, S_HD_HD, &sprite_count, &file_sprite_count) != -1) {
            sprites = (RGE_Sprite**)calloc(sprite_count, 4);
            i = 0;
            if (file_sprite_count > 0) {
                do {
                    if (fscanf(f, S_HD, &id) != -1) {
                        sprite = new RGE_Sprite(f, id, master_sprites);
                        sprites[id] = sprite;
                    }
                    ++i;
                } while (i < file_sprite_count);
            }
            j = 0;
            if (file_sprite_count > 0) {
                do {
                    if (sprites[j] == 0) {
                        sprites[j] = new RGE_Sprite((short)j);
                    }
                    ++j;
                } while (j < file_sprite_count);
            }
        } else {
            sprite_count = 0;
            sprites = 0;
        }
        fclose(f);
    }
    return 1;
}
