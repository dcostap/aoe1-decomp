void rge_write(int param1, void* data, int size);

class RGE_Color_Table {
public:
    char gap_00[0x4];
    char color_table_name[0x1E];
    short resource_id;
    char type;
    char map_color;
    short id;

    void save(int param1);
};

void RGE_Color_Table::save(int param1) {
    rge_write(param1, (char*)this + 4, 0x1E);
    rge_write(param1, (char*)this + 0x26, 2);
    rge_write(param1, (char*)this + 0x22, 2);
    rge_write(param1, (char*)this + 0x25, 1);
    rge_write(param1, (char*)this + 0x24, 1);
}
