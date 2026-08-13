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
// - direct member assignment in both TShape constructor arms removed the named pointer;
//   this improved the strict diff to 55 bytes and recovered the post-constructor block.
// - nested picture success under the nonnull allocation and unconditional shape clearing
//   removed the extra cleanup blocks; size and CFG became exact, with a 20-byte diff.
// - explicit destructor, union/file-size, and declaration-lifetime probes did not improve
//   codegen; the remaining drift is the four-byte file_name anchor and cleanup scheduling.
// - modeled the decompiler's named picture result and member assignment; emitted code
//   returned to the clean 20-byte result, so the local was not a useful source lead.
// - modeled a named shape result from the line-120 member assignment; diff widened to
//   28 bytes and lost the post-constructor block, so the clean direct-member form stays.
// - dossier, donor, ABI, and call-map evidence still show exact calls, frame, size, and
//   CFG; remaining drift is localized to file_name stack coloring and store scheduling.

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

    this->free_pic();

    if (this->pic_name[0] != 0) {
        sprintf(file_name + 4, "%s.shp", this->pic_name);
        this->shape = new TShape(file_name + 4, this->res_id);
    } else if (this->res_id != -1) {
        this->shape = new TShape("", this->res_id);
    } else {
        return 0;
    }

    if (this->shape && this->shape->is_loaded()) {
        this->pic_type = 1;
        this->own_pic = 1;
        return 1;
    }

    TShape* old_shape = this->shape;
    if (old_shape) {
        delete old_shape;
    }
    this->shape = 0;

    sprintf(file_name + 4, "%s.bmp", this->pic_name);
    this->pic = new TPicture(file_name + 4, -1, 0, 0, 0);

    if (this->pic) {
        if (this->pic->Dib) {
            this->pic_type = 0;
            this->own_pic = 1;
            return 1;
        }
        delete this->pic;
        this->pic = 0;
    }

    return 0;
}
