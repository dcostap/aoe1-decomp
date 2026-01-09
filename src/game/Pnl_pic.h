#pragma once
#include "common.h"

enum PictureType : unsigned int {
    Picture = 0,
    Shape = 1,
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];                       // 0xF4
    long res_id;                             // 0x100
    int size_from_pic;                       // 0x104
    int keep_loaded;                         // 0x108
    int own_pic;                             // 0x10C
    PictureType pic_type;                    // 0x110
    TPicture* pic;                           // 0x114
    TShape* shape;                           // 0x118

    virtual void draw();                                    // vt0[12]+0x30=0x47A630
    TPicturePanel();
    ~TPicturePanel();
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, long param_8, int param_9, int param_10);
    void set_picture(TShape* param_1, long param_2);
    int load_pic();
    void free_pic();
};

static_assert(sizeof(TPicturePanel) == 0x11C, "TPicturePanel Size Mismatch");

