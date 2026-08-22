// 0045B310 TMousePointer::LoadCursors
// Attempt log:
// initial natural source from packet/decompiler: exact size but early EBX/EBP zero-register drift and broad tail layout drift (306 positional / 211 edit).
// tried explicit zero local/register and replacing literals: did not change early topology until loop shape changed.
// rewrote first shape-dimension scan to match original offset-counter form (shape in EDI, off in EDX, count in EBX); first mismatch moved to 0045B3B2 and diff improved to 256 positional / 150 edit.
// tried shared fail label and LoadOk=0/goto-done forms for early failure exits; either unchanged branch-distance drift or object shrank below configured size, rolled back.
// fresh baseline: 294 positional bytes, exact size, all 16 calls, and 87.37% exact blocks.
// reversed the validation height comparison; emitted order moved farther, rolled back.
// tried one shared failed label; emitted code was unchanged, rolled back.
// tried nested positive success guards; size grew by 14 and block coverage fell, rolled back.
// tried typed Shape_Info bounds with a combined predicate; no positional gain, then a height temp worsened size, rolled back.
// tried typed Shape_Info validation records with an explicit shared failure label; the tail moved to the end, but the validation field schedule changed and the diff worsened to 304/91%, rolled back.
// tried a positive Num_Cursors <= Max_Cursors guard with LoadOk failure assignment; size grew 41 bytes and a call crossed the boundary, rolled back.
// tried typed Shape_Info field iteration; direct Width/Height fields changed the first paired hunk and worsened the diff to 304, rolled back.
// kept a typed Shape_Info height pointer and field-first Width/Height predicates; the validation memory schedule now matches, but the failure tail remains misplaced.
// tried routing the same typed validation failures and early exits through a source-level load_failed tail; VC5 emitted the identical early return block (294-byte diff), rolled back.
// left in scratch: behavior/calls/size are close, but post-scan failure-tail placement and validation-loop layout still differ broadly; not accepted_drift-safe.
// revisit: replaced the direct operator_delete helper with natural typed delete; emitted bytes were unchanged.
// revisit: typed both Shape_Info walks and canonicalized Shape_Info ownership/long fields; emitted bytes were unchanged.
// revisit: a top-tested while scan improved the diagnostic diff to 72 but moved shape_info setup before the proven count guard; restored the guarded do-loop for fault order.
// BLOCKER: the validation loop reads width, height, then Max_CY in the
// executable. The rebuild reads width, Max_CY, then height. Its validation
// failures also use an earlier epilogue instead of the executable's shared
// tail. Malformed Shape_Info fault context and cleanup topology differ.
// current worker: combining early guards, explicit shared labels, positive
// guards, and a result-owned return did not change emitted bytes (294 diff).
// A full nested goto form reduced diff to 279 but produced an invalid early
// success path. A guarded top-tested validation loop reduced diff to 233 and
// moved Shape_Info setup before the count test. It changes malformed-input
// fault order. Restored the guarded do-loop. No accepted drift is safe.

extern "C" int sprintf(char*, const char*, ...);

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

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
    Shape_Info* shape_info; // +1c
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
    TShape* old = this->Cursor_Shape;
    if (old != 0) {
        delete old;
    }

    if (keep_name == 0) {
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
    this->Max_CX = 0;
    this->Max_CY = 0;
    if (count > 0) {
        TShape* sh = this->Cursor_Shape;
        int off = 0;
        int n = count;
        do {
            Shape_Info* p = (Shape_Info*)((char*)sh->shape_info + off);
            int w = p->Width;
            if (w > this->Max_CX) this->Max_CX = w;
            int h = p->Height;
            if (h > this->Max_CY) this->Max_CY = h;
            off += 0x20;
            n--;
        } while (n != 0);
    }

    if (this->Max_CX == 0 || this->Max_CY == 0) return 0;
    this->Max_CX = 0x40;
    this->Max_CY = 0x30;
    if (this->save_area == 0) {
        if (!this->create_surfaces()) return 0;
    }
    this->set_facet(this->facet);
    this->set_game_facet(this->game_facet);

    if (this->Mouse_Mode == 0) {
        if (this->Num_Cursors > this->Max_Cursors) return 0;
        int i = 0;
        if (this->Num_Cursors > 0) {
            Shape_Info* info = (Shape_Info*)this->Cursor_Shape->shape_info;
            long* height = &info->Height;
            do {
                if (height[-1] > this->Max_CX || *height > this->Max_CY) return 0;
                i++;
                height += 8;
            } while (i < this->Num_Cursors);
        }
        int cur = 0;
        if (this->Max_Cursors > 0) {
            int off = 0;
            TDrawArea** pp = this->cursors;
            do {
                (*pp)->Clear(0, 0);
                (*pp)->SetTrans(1, (unsigned char)0);
                if (cur < this->Num_Cursors) {
                    if ((*pp)->Lock("mouseptr::LoadCursors", 1)) {
                        (*pp)->FillRect(0, 0, this->Max_CX, this->Max_CY, (unsigned char)0);
                        Shape_Info* si = (Shape_Info*)((char*)this->Cursor_Shape->shape_info + off);
                        this->Cursor_Shape->shape_draw(*pp, si->Hotspot_X, si->Hotspot_Y, cur, (unsigned char)0, 0);
                        (*pp)->Unlock("mouseptr::LoadCursors");
                    } else {
                        LoadOk = 0;
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
