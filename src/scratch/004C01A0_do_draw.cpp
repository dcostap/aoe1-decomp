// VA: 004C01A0 RGE_Sprite::do_draw
// Attempt log:
// try 1: natural reconstruction from asm/PDB; models lazy TShape load, get_frame call,
// debug draw text, color table selection, and normal/transparent draw branches.
// try 2: regular `new TShape(...)` instead of placement construction restored the /GX EH
// prologue family; first mismatch moved from offset 0 to offset 28.
// try 3: identified early EBX load as the frame argument used by get_frame and changed
// get_frame to use the second long parameter; this natural source currently compiles to
// only 784 bytes, so check_function reports section-size shortfall before byte compare.
// GIVEUP: remaining source model is broad/incomplete. Parameter roles/order, exact TShape
// draw/draw_trans signatures, debug formatting strings, draw_context globals, color-table
// allocation/copy helper surface, and the transparent-vs-normal branch structure need donor
// source reconstruction. No inline asm used; not accepted_drift quality.

class TShape;
class TDrawArea;
class RGE_Color_Table;

extern "C" void addstring(char** dst, char* base, char* ext);
extern "C" unsigned long debug_timeGetTime(char* file, int line);
extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* p);
extern "C" void* malloc(unsigned int size);
inline void* operator new(unsigned int, void* p) { return p; }

extern int* g_draw_context;        // 86BBF8
extern int g_draw_level;           // 86BBEC
extern int debug_draw_flag;        // 62C498
extern int text_out_mode;          // 592A5C
extern void* g_command_manager;    // 62C574

extern "C" void debug_log_time(void* mgr, int id, int dt);
extern "C" void debug_draw_text(char* buf);
extern "C" void debug_draw_text2(char* buf);
extern "C" void format_debug(char* out, char* fmt, ...);

class TShape {
public:
    TShape(char* filename, long resource_id);
    void draw(long shade, long x, long y, long facet, unsigned char color_flag, void* color_table);
    void draw_trans(long shade, long x, long y, long facet, unsigned char color_flag, void* color_table);
};

class RGE_Sprite {
public:
    char pict_name[13]; char pad0[3];
    long resource_id;
    unsigned char loaded; char pad1[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag; char pad2;
    short box_x1, box_y1, box_x2, box_y2;
    short draw_list_num;
    void* draw_list;
    void* main_sound;
    unsigned char micro_man_sound; char pad3[3];
    void* sound_list;
    char name[21]; char pad4;
    short frame_num;
    short facet_num;

    unsigned char get_frame(long* facet, long frame, char** fname);
    void do_draw(long x, long y, long frame, long shade, RGE_Color_Table* color_table, TDrawArea* draw_area, unsigned char color_index);
};

void RGE_Sprite::do_draw(long x, long y, long frame, long shade, RGE_Color_Table* color_table, TDrawArea* draw_area, unsigned char color_index)
{
    char* fname = 0;
    char text[0x100];
    long facet;

    if (frame >= this->frame_num) {
        frame = 0;
    }

    if (this->shape == 0) {
        if (this->loaded == 0) {
            return;
        }
        addstring(&fname, this->pict_name, ".shp");
        unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1e8);
        TShape* shp = new TShape(fname, this->resource_id);
        this->shape = shp;
        unsigned long t2 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1ea);
        debug_log_time(g_command_manager, 0x0b, t2 - t);
        operator delete(fname);
    }

    int dl = this->draw_level;
    if (dl < (int)(color_index & 0xff)) {
        dl = (int)(color_index & 0xff);
    }
    g_draw_level = dl;
    g_draw_context[0x1b] = 0;
    if (this->box_x1 != 0) {
        g_draw_context[0x1b] = (int)&this->box_x1;
    }

    if (!this->get_frame(&facet, y, &fname)) {
        if (debug_draw_flag) {
            format_debug(text, "%s %d %d %d %d %d", this, x, y, fname, this->color_flag);
            if (text_out_mode) debug_draw_text(text); else debug_draw_text2(text);
        }
        if (this->color_table < 0) {
            void* table = 0;
            if (color_table != 0) {
                malloc((((short*)color_table)[0x13] + 1) << 4);
                table = (char*)color_table + 0x28;
            }
            this->shape->draw(color_index, x, y, facet, this->color_flag, table);
        } else {
            void* table = 0;
            if (this->color_tables[this->color_table] != 0) {
                malloc((this->color_table + 1) << 4);
                table = (char*)this->color_tables[this->color_table] + 0x28;
            }
            this->shape->draw(color_index, x, y, facet, this->color_flag, table);
        }
    } else {
        if (debug_draw_flag) {
            format_debug(text, "%s %d %d %d %d %d", this, x, y, fname, this->color_flag);
            if (text_out_mode) debug_draw_text(text); else debug_draw_text2(text);
        }
        if (this->color_table < 0) {
            void* table = 0;
            if (color_table != 0) {
                malloc((((short*)color_table)[0x13] + 1) << 4);
                table = (char*)color_table + 0x28;
            }
            this->shape->draw_trans(color_index, x, y, facet, this->color_flag, table);
        } else {
            void* table = 0;
            if (this->color_tables[this->color_table] != 0) {
                malloc((this->color_table + 1) << 4);
                table = (char*)this->color_tables[this->color_table] + 0x28;
            }
            this->shape->draw_trans(color_index, x, y, facet, this->color_flag, table);
        }
    }

    if (debug_draw_flag) {
        if (text_out_mode) debug_draw_text("RGE_Sprite::do_draw"); else debug_draw_text2("RGE_Sprite::do_draw");
    }
}
