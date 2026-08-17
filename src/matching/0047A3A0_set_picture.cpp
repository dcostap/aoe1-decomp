// TPicturePanel::set_picture
// VA: 0047A3A0
// PDB: Pnl_pic.cpp:93-99
//
// The method replaces the current shape, then marks the panel for redraw.
// TPicturePanel starts after the 0xF4-byte TPanel base.  The virtual surface
// keeps set_redraw at slot 8 (vtable offset 0x20).

class TShape;

class TPanel {
public:
    virtual ~TPanel();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void set_redraw(int mode);

    char gap_04[0xF0];
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    void* pic;
    TShape* shape;

    void free_pic();
    void set_picture(TShape* new_shape, long new_res_id);
};

void TPicturePanel::set_picture(TShape* new_shape, long new_res_id) {
    this->free_pic();
    this->shape = new_shape;
    this->res_id = new_res_id;
    this->own_pic = 0;
    this->set_redraw(1);
}
