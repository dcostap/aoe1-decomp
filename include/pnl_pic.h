#ifndef AOE1_PNL_PIC_H
#define AOE1_PNL_PIC_H

#include "panel.h"
#include "Shape.h"
#include "Picture.h"

class TPicturePanel : public TPanel {
public:
    enum PictureType {
        Picture = 0,
        Shape = 1
    };

    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    PictureType pic_type;
    TPicture* pic;
    TShape* shape;

    TPicturePanel();
    virtual ~TPicturePanel();
    virtual void draw();
    long setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, char* pic_name_in, long res_id_in, int size_from_pic_in, int keep_loaded_in);
    void set_picture(TShape* pic_in, long res_id_in);

protected:
    int load_pic();
    void free_pic();
};

typedef char pnl_pic_picture_panel_size_check[
    (sizeof(TPicturePanel) == 0x11C) ? 1 : -1];

#endif
