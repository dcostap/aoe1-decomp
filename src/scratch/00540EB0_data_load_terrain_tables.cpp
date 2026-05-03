// 00540EB0 RGE_Game_World::data_load_terrain_tables
// World.cpp:422-460, 282 bytes

extern "C" void* __cdecl fopen(const char* path, const char* mode);
extern "C" int __cdecl fscanf(void* stream, const char* format, ...);
extern "C" int __cdecl fclose(void* stream);
extern "C" void* __cdecl calloc(unsigned count, unsigned size);

class RGE_Game_World {
public:
    char _gap_00[0x50];
    short terrain_num;
    short terrain_size;
    float** terrains;

    unsigned char data_load_terrain_tables(char* filename);
};

unsigned char RGE_Game_World::data_load_terrain_tables(char* filename)
{
    void* f = fopen(filename, "r");
    if (f == 0)
        return 1;

    if (fscanf(f, "%hd %hd", &this->terrain_num, &this->terrain_size) == -1) {
        this->terrain_num = 0;
        this->terrains = 0;
        fclose(f);
        return 1;
    }

    // Store pointers for terrain members (matching original's register allocation)
    short* terrain_num_ptr = &this->terrain_num;
    short* terrain_size_ptr = &this->terrain_size;

    this->terrains = (float**)calloc(*terrain_num_ptr, 4);

    for (short outer = 0; outer < *terrain_num_ptr; outer++) {
        int type_temp;
        short index;

        if (fscanf(f, "%hd %hd", &type_temp, &index) != -1) {
            float* row = (float*)calloc(*terrain_size_ptr, 4);
            this->terrains[type_temp] = row;

            for (short si = 0; si < index; si++) {
                short local_6;
                fscanf(f, "%hd", &local_6);
                fscanf(f, "%f", &row[local_6]);
            }
        }
    }

    fclose(f);
    return 1;
}
