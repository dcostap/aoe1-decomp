// 004372C0 RGE_Diamond_Map::draw (diam_map.cpp:426-510)

class TDrawArea {
public:
    char* Lock(char*, int);
    void Unlock(char*);
    int Copy(TDrawArea*, int, int, void*, int);
    int Clear(void*, int);
};

class TPanel {
public:
    virtual ~TPanel() {}
    char pad[0xF4];
};

class RGE_Diamond_Map : public TPanel {
public:
    void draw();

    /*+0xF4*/ void* world;
    /*+0xF8*/ void* player;
    /*+0xFC*/ void* map_data;
    /*+0x100*/ int all_visible;
    /*+0x104*/ int render_all;
    char pad_108[0x20];
    /*+0x128*/ void* map_image_lines;
    /*+0x12C*/ void* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    char pad_13C[0x13];
    /*+0x14F*/ unsigned char bg_color;
    char pad_150[0x18];
    /*+0x168*/ TDrawArea* save_area;
};

void RGE_Diamond_Map::draw()
{
    if (this->render_area == 0 || this->save_area == 0 || this->field_70 == 0 || this->field_6C == 0) {
        // early exit
        return;
    }

    if (this->map != 0 && this->player != 0 && this->map_image_lines != 0 && this->map_tile_rows != 0) {
        // full draw
        this->draw_selected_area();

        if (this->render_all) {
            if (this->field_88_8C != 0) {
                this->save_area->Copy(this->render_area, &this->field_88_8C, 0);
                this->clear_image();
            } else {
                this->save_area->Clear(0, this->bg_color);
            }
            this->draw_all_tiles();
            this->render_all = 0;
        } else {
            this->draw_explored_tiles();
        }

        this->copy_image();
        this->draw_objects();
        this->draw_selected_area();
        this->draw_view_rect();

        this->render_area->Lock("diam_map::draw", 1);
        this->draw_visible_object(0, 0, 0);
        this->render_area->Unlock("diam_map::draw");

        this->draw();
        this->player_tile_list->del_list();
    } else {
        // partial draw
        this->draw_selected_area();

        if (this->map_image_lines != 0) {
            this->clear_image();
            this->copy_image();
        } else if (this->field_88_8C != 0) {
            // copy from child
        } else {
            this->render_area->Clear(&this->clip_rect, this->bg_color);
        }

        this->draw();
    }
}
