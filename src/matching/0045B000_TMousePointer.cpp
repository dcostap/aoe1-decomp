class TShape {
public:
    void destroy(void);
};

void operator_delete(void* ptr);

class TMousePointer;
extern TMousePointer* MouseSystem;

class TMousePointer {
public:
    char gap_00[0x58];
    TShape* Cursor_Shape;

    void delete_surfaces(void);
    ~TMousePointer();
};

TMousePointer::~TMousePointer() {
    TShape* shape = this->Cursor_Shape;

    if (shape != 0) {
        shape->destroy();
        operator_delete(shape);
        this->Cursor_Shape = 0;
    }
    this->delete_surfaces();
    MouseSystem = 0;
}
