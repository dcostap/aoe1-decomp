// EH-framed virtual destructor; natural source should yield vftable store, free_pic call, then TPanel dtor tail
// FLAGS: config/flags/0047A250_TPicturePanel.rsp

class TPicture;
class TShape;

class TPanel {
public:
    virtual ~TPanel();
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

    virtual ~TPicturePanel();
    void free_pic();
};

TPicturePanel::~TPicturePanel() {
    this->free_pic();
}
