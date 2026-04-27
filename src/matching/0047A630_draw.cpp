// TPicturePanel::draw
// VA: 0047A630
// PDB: Pnl_pic.cpp:175-204

#include "..\..\include\game_globals.h"

class TDrawArea {
public:
    char gap_00[0x4];
    void* Lock(char* name, int mode);
    void Unlock(char* name);
};

class TPanel {
public:
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void enterCS(int unk);     // slot 10 = vtable+0x28
    virtual void leaveCS();            // slot 11 = vtable+0x2C
};

class TPicture {
public:
    char gap_00[0x4];
    void Draw(TDrawArea* dest, int x, int y, int srcX, int srcY);
};

class TShape {
public:
    unsigned char shape_draw(TDrawArea* dest, int x, int y, int zero, unsigned char flag, void* palette);
};

class TPicturePanel : public TPanel {
public:
    char gap_04[0x08];
    int posX;                 // +0x0C
    int posY;                 // +0x10
    char gap_14[0x0C];
    TDrawArea* draw_area;     // +0x20
    char gap_24[0x48];
    int field_6C;             // +0x6C
    int field_70;             // +0x70
    char gap_74[0x80];
    char pic_name[12];
    int res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    TPicture* pic;
    TShape* shape;

    virtual void draw();
    int load_pic();
    void free_pic();
};

void TPicturePanel::draw()
{
    if (!this->draw_area) return;
    if (!this->field_70) return;
    if (!this->field_6C) return;

    this->enterCS(0);

    if (!this->keep_loaded)
        this->load_pic();

    void* locked = this->draw_area->Lock("pnl_pic::draw", 1);
    if (locked) {
        if (this->pic_type == 0) {
            if (this->pic)
                this->pic->Draw(this->draw_area, this->posX, this->posY, 0, 0);
        } else {
            if (this->shape)
                this->shape->shape_draw(this->draw_area, this->posX, this->posY, 0, 0, 0);
        }
        this->draw_area->Unlock("pnl_pic::draw");
    }

    if (!this->keep_loaded)
        this->free_pic();

    this->leaveCS();
}
