// 0045B310 TMousePointer::LoadCursors
// Attempt log:
// initial natural source from packet/decompiler: exact size but early EBX/EBP zero-register drift and broad tail layout drift (306 positional / 211 edit).
// tried explicit zero local/register and replacing literals: did not change early topology until loop shape changed.
// rewrote first shape-dimension scan to match original offset-counter form (shape in EDI, off in EDX, count in EBX); first mismatch moved to 0045B3B2 and diff improved to 256 positional / 150 edit.
// tried shared fail label and LoadOk=0/goto-done forms for early failure exits; either unchanged branch-distance drift or object shrank below configured size, rolled back.
// left in scratch: behavior/calls/size are close, but post-scan failure-tail placement and validation-loop layout still differ broadly; not accepted_drift-safe.

extern "C" int sprintf(char*, const char*, ...);
extern "C" void operator_delete(void*);

class TDrawArea {
public:
    void Clear(void* rect, int flags);
    void SetTrans(int on, unsigned char value);
    unsigned char* Lock(char* name, int write);
    void Unlock(char* name);
    void FillRect(long x, long y, long w, long h, unsigned char color);
};

class TShape {
public:
    char gap_00[0x18];
    void* FShape;          // +18
    void* shape_info;      // +1c
    TShape(char* filename, int file_id);
    ~TShape();
    int is_loaded();
    int shape_count();
    unsigned char shape_draw(TDrawArea* dst, long hot_x, long hot_y, int index, unsigned char flag, unsigned char* table);
};

class TMousePointer {
public:
    int custom_draw;          // +00
    TDrawArea* render_area;   // +04
    TDrawArea* save_area;     // +08
    TDrawArea* primary_area;  // +0c
    int Num_Cursors;          // +10
    int Max_Cursors;          // +14
    TDrawArea* cursors[16];   // +18
    TShape* Cursor_Shape;     // +58
    int Mouse_Mode;           // +5c
    int Max_CX;               // +60
    int Max_CY;               // +64
    char gap_68[0x88-0x68];
    int facet;                // +88
    int game_facet;           // +8c
    char gap_90[0x14c-0x90];
    char cursor_file[0x104];  // +14c
    int cursor_file_id;       // +250

    int LoadCursors(char* base, int file_id, int keep_name);
    int create_surfaces();
    void set_facet(int);
    void set_game_facet(int);
};

int TMousePointer::LoadCursors(char* base, int file_id, int keep_name)
{
    int LoadOk = 1;
    int count;
    register int zero = 0;
    TShape* old = this->Cursor_Shape;
    if (old != 0) {
        old->~TShape();
        operator_delete(old);
    }

    if (keep_name == zero) {
        this->cursor_file_id = file_id;
        sprintf(this->cursor_file, "%s.slp", base);
    }

    TShape* shape = new TShape(this->cursor_file, this->cursor_file_id);
    this->Cursor_Shape = shape;
    if (shape == 0) return 0;
    if (!shape->is_loaded()) return 0;
    if (this->Cursor_Shape->FShape == 0) return 0;

    count = this->Cursor_Shape->shape_count();
    this->Num_Cursors = count;
    this->Max_CX = zero;
    this->Max_CY = zero;
    if (count > zero) {
        TShape* sh = this->Cursor_Shape;
        int off = zero;
        int n = count;
        do {
            char* p = (char*)sh->shape_info + off;
            int w = *(int*)(p + 0x10);
            if (w > this->Max_CX) this->Max_CX = w;
            int h = *(int*)(p + 0x14);
            if (h > this->Max_CY) this->Max_CY = h;
            off += 0x20;
            n--;
        } while (n != 0);
    }

    if (this->Max_CX == zero || this->Max_CY == zero) return 0;
    this->Max_CX = 0x40;
    this->Max_CY = 0x30;
    if (this->save_area == 0) {
        if (!this->create_surfaces()) return 0;
    }
    this->set_facet(this->facet);
    this->set_game_facet(this->game_facet);

    if (this->Mouse_Mode == zero) {
        if (this->Num_Cursors > this->Max_Cursors) return 0;
        int i = zero;
        if (this->Num_Cursors > zero) {
            char* q = (char*)this->Cursor_Shape->shape_info + 0x14;
            do {
                if (*(int*)(q - 4) > this->Max_CX) return 0;
                if (*(int*)q > this->Max_CY) return 0;
                i++;
                q += 0x20;
            } while (i < this->Num_Cursors);
        }
        int cur = zero;
        if (this->Max_Cursors > zero) {
            int off = zero;
            TDrawArea** pp = this->cursors;
            do {
                (*pp)->Clear(0, zero);
                (*pp)->SetTrans(1, (unsigned char)zero);
                if (cur < this->Num_Cursors) {
                    if ((*pp)->Lock("mouseptr::LoadCursors", 1)) {
                        (*pp)->FillRect(0, 0, this->Max_CX, this->Max_CY, (unsigned char)zero);
                        char* si = (char*)this->Cursor_Shape->shape_info + off;
                        this->Cursor_Shape->shape_draw(*pp, *(long*)(si + 0x18), *(long*)(si + 0x1c), cur, (unsigned char)zero, 0);
                        (*pp)->Unlock("mouseptr::LoadCursors");
                    } else {
                        LoadOk = zero;
                    }
                }
                cur++;
                pp++;
                off += 0x20;
            } while (cur < this->Max_Cursors);
        }
    }
    return LoadOk;
}
