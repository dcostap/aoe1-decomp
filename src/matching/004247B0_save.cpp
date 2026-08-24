// 004247B0 RGE_Color_Table::save
// BINARY NOTE: color.cpp lines 329-335 define five direct writes in this
// order: name (0x1E), id (2), resource_id (2), map_color (1), type (1).
// Keep each address and call separate. This preserves write and fault order.

void rge_write(int param1, void* data, int size);

#ifndef COLOR_TU_CONTEXT
class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[0x1E];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;

    void save(int param1);
};
#endif

void RGE_Color_Table::save(int param1) {
    rge_write(param1, this->color_table_name, 0x1E);
    rge_write(param1, &this->id, 2);
    rge_write(param1, &this->resource_id, 2);
    rge_write(param1, &this->map_color, 1);
    rge_write(param1, &this->type, 1);
}
