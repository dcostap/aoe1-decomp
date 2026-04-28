void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Game_World {
public:
    char gap_00[0x50];
    short terrain_num;      // +0x50
    short terrain_size;     // +0x52
    float** terrains;       // +0x54

    void terrain_tables_init(int fd);
};

void RGE_Game_World::terrain_tables_init(int fd) {
    rge_read(fd, &terrain_num, 2);
    rge_read(fd, &terrain_size, 2);

    if (terrain_num > 0 && terrain_size > 0) {
        terrains = (float**)calloc(terrain_num, 4);
        rge_read(fd, terrains, terrain_num * 4);

        for (int i = 0; i < terrain_num; i++) {
            if (terrains[i] != 0) {
                terrains[i] = (float*)calloc(terrain_size, 4);
                rge_read(fd, terrains[i], terrain_size * 4);
            }
        }
    }
}
