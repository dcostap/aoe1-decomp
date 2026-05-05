// attempt 1: natural mouse pointer setup with TShape load and cursor initialization
#include <stdio.h>

extern void* MouseSystem;
extern "C" void* __stdcall SetCursor(void*);
class TDrawSystem { public: char gap_00[0x10]; void* cursor; char gap_14[8]; long height; char gap_20[0x458]; unsigned char draw_type; };
class TDrawArea { public: TDrawSystem* draw_system; char gap_04[0x38]; long width; };
class TShape { public: char gap[0x18]; void* first_cursor; TShape(char*, int); int is_loaded(); long shape_count(); };
class TMousePointer {
public:
    int window; TDrawArea* draw_area; char gap_08[4]; void* old_cursor; long shape_count_value; long shape_number; char gap_18[0x40]; TShape* shape;
    char gap_5c[0xC4]; long draw_width; long draw_height; char gap_128[0xC]; long setup_done;
    int setup(int window, TDrawArea* draw_area, char* base, int palette, int shape_number);
    int set_shape(char* base, int palette, int zero);
    void hide(int); void show(int);
};

int TMousePointer::setup(int window, TDrawArea* draw_area, char* base, int palette, int shape_number) {
    char file_name[260];
    MouseSystem = this;
    this->window = window;
    this->draw_area = draw_area;
    if (window == 0) return 1;
    if (draw_area->draw_system->draw_type == 1) return 0;
    this->draw_width = draw_area->width;
    this->draw_height = draw_area->draw_system->height;
    this->old_cursor = draw_area->draw_system->cursor;
    SetCursor(0);
    sprintf(file_name, "%s.slp", base);
    this->shape = new TShape(file_name, palette);
    if (this->shape == 0) return 0;
    if (!this->shape->is_loaded()) return 0;
    if (this->shape->first_cursor == 0) return 0;
    this->shape_number = shape_number;
    if (shape_number < 1 || shape_number > 16) return 0;
    this->shape_count_value = this->shape->shape_count();
    if (this->shape_count_value > this->shape_number) return 0;
    if (!this->set_shape(base, palette, 0)) return 0;
    this->hide(0);
    this->show(0);
    this->setup_done = 1;
    return 1;
}
