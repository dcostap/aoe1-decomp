void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Color_Table {
public:
    char gap_00[0x04];
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];

    RGE_Color_Table(int fd);
};

class RGE_Game_World {
public:
    char gap_00[0x60];
    short color_table_num;      // +0x60
    char gap_62[0x02];
    RGE_Color_Table** color_tables; // +0x64

    void color_table_init(int fd);
};

void RGE_Game_World::color_table_init(int fd) {
    rge_read(fd, &color_table_num, 2);

    if (color_table_num > 0) {
        color_tables = (RGE_Color_Table**)calloc(color_table_num, 4);
        for (int i = 0; i < color_table_num; i++) {
            color_tables[i] = new RGE_Color_Table(fd);
        }
    }
}
