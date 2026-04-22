class TShape {
public:
    void* shape;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    void* shape_info;

    TShape();
};

TShape::TShape() {
    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;
    shape_info = 0;
    load_type = -1;
    load_size = 0;
}
