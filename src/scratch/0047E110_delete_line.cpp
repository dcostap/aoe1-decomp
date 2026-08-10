// 0047E110 TTextPanel::delete_line
// Baseline reconstruction: remove one linked-list text node, update the line
// counters, and refresh the panel.  The list/node offsets are binary-proven.
// Attempt log:
// - Baseline natural bounded list removal: size/calls/frame matched, but VC5
//   loaded the parameter after saving this and strength-reduced the index loop.
// - register-qualified parameter, split guards, function-scope locals, an
//   explicit index copy, and a shared fail label all emitted the same basin.
// - Natural-source variant lab (54 variants; size/frame/call-set gated) found
//   no exact group; full proven TPanel/TTextPanel layout also emitted the same
//   code. A while-loop and const-parameter loop probe were unchanged.
// - Fresh pass: explicit line decrement forms (predecrement, assignment, and
//   for-init), long/function-scope loop locals, derived-dtor/CRT-header context,
//   and a four-variant limit-local lab all stayed in the same countdown basin.
// - The flag lab found /Og-/Ot-/Ob0 unchanged or structurally wrong; no flag
//   lead is retained. The clean natural source remains the defensible candidate.
// - Restored clean source after the probes. Remaining drift is the entry
//   parameter scheduling plus incrementing-versus-countdown loop shape.
// - This assignment rechecked split negative/upper guards and an int-width
//   parameter; both were codegen duplicates. Restored the canonical long ABI.
// - Main-agent audit retained canonical linked-node ownership and the ordinary
//   bounded traversal; no countdown/codegen steering survives.
// - Fresh bounded pass: post-increment with explicit line decrement regressed
//   to the prior countdown basin; unsigned dword, function-scope initialization,
//   explicit int-bound cast, and long+decrement combinations were duplicates or
//   regressed. Short induction was the only prologue-closing lead, but its
//   required sign-extension added bytes; short+decrement was best at 139 bytes
//   (205-byte target, rebuilt 208), while unsigned-short and a guarded goto loop
//   were worse. Restored the natural int-counter source; remaining blocker is
//   the original pre-save parameter load plus separate dword counter coloring.

extern "C" void __cdecl free(void* block);

class TPanel {
public:
    virtual ~TPanel();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void redraw(int);
};

struct TextNode {
    char* text;
    char* text2;
    void* unknown_08;
    TextNode* next_node;
};

class TTextPanel : public TPanel {
public:
    char gap_04[0xF0];
    TextNode* list;
    short num_lines;
    char gap_FA[6];
    short cur_line;

    void calc_draw_info(int);
    int delete_line(long line);
};

int TTextPanel::delete_line(long line)
{
    if (line >= 0 && line <= this->num_lines - 1) {
        TextNode* deleted;

        if (line == 0) {
            deleted = this->list;
            this->list = deleted->next_node;
        } else {
            TextNode* node = this->list;
            int i = 0;
            for (; i != line - 1; ++i) {
                node = node->next_node;
            }
            deleted = node->next_node;
            node->next_node = deleted->next_node;
        }

        if (deleted != 0) {
            if (deleted->text != 0) {
                free(deleted->text);
            }
            if (deleted->text2 != 0) {
                free(deleted->text2);
            }
            free(deleted);
            --this->num_lines;

            short count = this->num_lines;
            if (count == 0) {
                this->cur_line = 0;
            } else if (this->cur_line >= count) {
                this->cur_line = count - 1;
            }

            this->calc_draw_info(1);
            this->redraw(1);
            return 1;
        }
    }
    return 0;
}
