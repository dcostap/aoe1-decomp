// tried the natural destructor body; VC5 still sized it too small for the oracle's EH-framed body
// tried an explicit vftable surface next; the remaining gap stayed in the destructor basin / EH prolog family, not in the free_pic behavior
class TPicture;
class TShape;

class TPanel {
public:
    void* vtable_ptr;
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
    TPicture* pic;
    TShape* shape;

    ~TPicturePanel();
    void free_pic();
};

TPicturePanel::~TPicturePanel() {
    this->vtable_ptr = (void*)0x571750;
    this->free_pic();
}
