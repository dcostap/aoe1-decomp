// VA: 0045B5D0 TMousePointer::create_surfaces
// Initial natural source from packet. Goal: match VC5 EH new+ctor shape in Mouseptr.cpp.
// try 1: natural source + /GX: exact through save-area init, drift began at cursor loop.
// try 2: use cursor name buffer directly (not +4) and nested positive Max_Cursors gate: fixed buffer LEAs, best edit diff so far.
// try 3: explicit cursor success/fail labels worsened max check/load and near branches; rolled back.
// try 4: use explicit cursor pointer local to mirror EBX traversal; no improvement.
// try 5: duplicate success returns in Mouse_Mode/Max_Cursors arms moved first mismatch to prologue guard; rolled back.
// tried flags /O1, no /Oy, /Ox, /Ob0: worse or same; kept /O2 /Oy /GX.
// tried NameBuf sizes 24/28/36/40: prologue/frame mismatches, worse; kept 32.
// session sa24b7b590_r1 probes 1-10: combined/nested guards, for/while/do loops,
// explicit success/failure labels, a result local, negative gates, and a bottom
// continue loop. The guarded do/while was the metric-best diagnostic (+6 bytes,
// diff 173), but emitted jge+jmp with the failure block before success; it did
// not preserve the oracle's jl backedge/common success tail. Restored this natural
// for-loop candidate after the 10-hypothesis budget; current rebuilt diff is 189
// bytes (419 vs 394), exact through offset +0xDB, with all 7 calls aligned.
// left in scratch: exact through offset 0xDB (save-area path); remaining cursor-loop drift is branch sizing/target selection and cursor-fail epilogue order, not accepted_drift-safe yet.
// fresh pass: pointer-backed guarded do/while reached diff 173 and +6 bytes, but changed the proven JL backedge to JGE+jmp.
// direct indexed, bottom-loop, labeled-tail, and result-local variants were tested; each was duplicate or structurally worse.
// restored the natural typed indexed for-loop; current best clean source remains diff 189 with all seven calls aligned.
// recovery probe: split the two negative cursor gates around a shared success label;
// the diff stayed 189 but size and CFG shape worsened, so the clean indexed source is restored.
// probe: use the donor-proven mutable TDrawArea name ABI for both surface allocations;
// no emitted bytes moved; retain the canonical typed constructor, with cursor-tail drift unchanged.
// shardA6 probe: adding donor-proven virtual TDrawArea cleanup changed sizeof from 0x100 to 0x104;
// operator-new size changed and diff worsened 189->190, so the clean surface ABI is restored.
// Fresh claim probe: an early success return for Mouse_Mode/Max_Cursors moved
// the first mismatch to the EH prologue and worsened the structural diff; rolled back.
// continuation sa-a6ac71bd-r1: nested guards, negative gates, explicit success
// labels, cursor-fail goto, scoped i/NameBuf, stdio.h, and corrected polymorphic
// TDrawArea size were duplicate or worse. The guarded do/while remains the best
// diagnostic at 400 bytes/diff 173, but its jge+jmp backedge is not oracle code.
// Clean source remains 419 bytes/diff 189, exact through +0xDB, seven calls aligned.
// revisit sa-6fc3a436-r1: typed TDrawArea::DrawSystem at offset 0 preserves the
// 0x100 allocation and all bytes. Natural loop and common-tail variants remain
// structural duplicates or worse; retain the indexed for-loop.
// revisit sa-903341f9-r1: the binary-supported direct indexed do/while with the
// typed DrawSystem owner improves 419/394 to 400/394 and 173 positional bytes.
// The remaining six bytes are VC5's jge-plus-jmp loop exit and block order.
// Pointer-backed, nested, explicit-label, early-return, and comma-increment
// variants were duplicate or worse. This direct do/while is now the pinned
// clean source until a new structural clue appears.
// Accepted-drift review: the rebuilt loop inverts the final `i < Max_Cursors`
// branch and adds an unconditional jump back to the body. The comparison,
// cursor update, seven calls, arguments, member accesses, and stores match.
// Constructor or Init failure still returns zero. Every other path returns one.
// EH state and chain restoration match on each exit.

extern "C" int sprintf(char* buffer, const char* format, ...);

class TDrawSystem;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap[0xFC];
    TDrawArea(char* name, int height);
    int Init(TDrawSystem* draw_system, int width, int height, int x, int y);
};

class TMousePointer {
public:
    int custom_draw;              // +0x00
    TDrawArea* render_area;       // +0x04
    TDrawArea* save_area;         // +0x08
    TDrawArea* primary_area;      // +0x0C
    int Num_Cursors;              // +0x10
    int Max_Cursors;              // +0x14
    TDrawArea* cursors[16];       // +0x18
    char gap_58[0x5C - 0x58];
    int Mouse_Mode;               // +0x5C
    int Max_CX;                   // +0x60
    int Max_CY;                   // +0x64

    int create_surfaces();
};

int TMousePointer::create_surfaces()
{
    int i;
    char NameBuf[32];

    if (this->custom_draw == 0) {
        return 1;
    }

    if (this->save_area == 0 && this->Max_CX > 0 && this->Max_CY > 0) {
        this->save_area = new TDrawArea("Mouse Save area", 0);
        if (this->save_area == 0) {
            return 0;
        }
        if (this->save_area->Init(this->render_area->DrawSystem, this->Max_CX, this->Max_CY, 0, 0) == 0) {
            return 0;
        }
    }

    if (this->Mouse_Mode == 0 && 0 < this->Max_Cursors) {
        i = 0;
        do {
            if (this->cursors[i] == 0) {
                sprintf(NameBuf, "Mouse Cursor #%d", i);
                this->cursors[i] = new TDrawArea(NameBuf, 0);
                if (this->cursors[i] == 0) {
                    return 0;
                }
                if (this->cursors[i]->Init(this->render_area->DrawSystem, this->Max_CX, this->Max_CY, 0, 0) == 0) {
                    return 0;
                }
            }
            ++i;
        } while (i < this->Max_Cursors);
    }

    return 1;
}
