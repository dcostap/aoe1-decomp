// TPicturePanel::load_pic
// VA: 0047A3E0
// PDB: Pnl_pic.cpp:105-147
// EH-framed (operator new), needs /GX
// Attempt log:
// - baseline: natural shape-first/BMP fallback with typed TShape/TPicture ownership;
//   frame and ordered calls matched, but the missing no-name/-1 early return left a
//   wrong fallback path and a 10-byte overflow.
// - corrected the executable's no-name/res_id==-1 early return; size became exact.
// - use this->shape for the failed-load test/cleanup, recovering the original reload,
//   destructor/delete call sites and 63-byte strict diff (best codegen checkpoint).
// - remaining drift is the four-byte file_name stack anchor, one extra shape null
//   compare before the member store, and the late cleanup tail; no further hypotheses
//   retained after the 10-probe budget.

#include "..\..\include\game_globals.h"
#include <string.h>

class TShape {
public:
    char gap_00[0x20];
    TShape(char* name, int res_id);
    ~TShape();
    int is_loaded();
};

class TPicture {
public:
    void* Dib;           // +0x00
    char gap_04[0x1C];
    TPicture(char* name, int param2, int param3, void* param4, int param5);
    ~TPicture();
};

class TPanel {
public:
    char gap_00[0xF4];
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    int res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    TPicture* pic;
    TShape* shape;

    int load_pic();
    void free_pic();
};

int TPicturePanel::load_pic()
{
    char file_name[80];
    TShape* new_shape;

    this->free_pic();

    if (this->pic_name[0] != 0) {
        sprintf(file_name + 4, "%s.shp", this->pic_name);
        new_shape = new TShape(file_name + 4, this->res_id);
    } else if (this->res_id != -1) {
        new_shape = new TShape("", this->res_id);
    } else {
        return 0;
    }

    this->shape = new_shape;
    if (this->shape && this->shape->is_loaded()) {
        this->pic_type = 1;
        this->own_pic = 1;
        return 1;
    }

    if (this->shape) {
        delete this->shape;
        this->shape = 0;
    }

    sprintf(file_name + 4, "%s.bmp", this->pic_name);
    TPicture* new_pic = new TPicture(file_name + 4, -1, 0, 0, 0);

    this->pic = new_pic;
    if (new_pic && new_pic->Dib) {
        this->pic_type = 0;
        this->own_pic = 1;
        return 1;
    }

    if (new_pic) {
        delete new_pic;
        this->pic = 0;
    }

    return 0;
}
