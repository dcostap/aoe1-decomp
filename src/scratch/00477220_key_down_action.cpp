// VA: 00477220 TInputPanel::key_down_action
// PDB source: Pnl_inp.cpp
// Attempt log:
// - broad switch reconstruction from packet: cursor movement/edit commands/delegates.
// - default /O2 reconstruction compiles but .text is 1248 vs target 1289, too short for extraction; missing exact switch table/body topology and several original cases.
// - tried /Od diagnostically: compares but 83.40% positional diff from offset 0 due EBP frame, confirming original is optimized /O2.
// - restored default flags. Give-up: needs a faithful full key switch reconstruction with original case labels/table and exact helper/vtable surfaces; no accepted_drift proposed.

extern int _mbslen(char* s);

class TInputPanel_477220 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void redraw(int);
    char gap04[0xF8-4]; short line_count; short page_top; short cur_line; short cursor; char gap104[0x19c-0x104]; int mode; char gap1a0[0x1b0-0x1a0]; int insert_mode;
    char* get_text(int i); void scroll(int,int,int); void calc_input_pos(); void page_up(); void paste(); void copy(); void del_word(int); void action10(int); long key_down_action(long key, short, int, int, int);
};

static int done(TInputPanel_477220* p) { p->calc_input_pos(); p->redraw(1); return 1; }

long TInputPanel_477220::key_down_action(long key, short, int p3, int p4, int p5)
{
    int len;
    switch (key) {
    case 0x21: // pgup-ish
        if (line_count < 1) return 1;
        if (cursor > 0) { cursor--; return done(this); }
        if (cur_line <= 0) return 1;
        cur_line--; cursor = (short)_mbslen(get_text(cur_line)); return done(this);
    case 0x23:
        if (line_count < 1) return 1;
        len = _mbslen(get_text(cur_line));
        if (cursor < len) { cursor++; return done(this); }
        if (cur_line >= line_count - 1) return 1;
        cur_line++; cursor = 0; return done(this);
    case 0x24:
        if (line_count < 1) return 1;
        if (cur_line <= 0) return 1;
        cur_line--; if (cursor > _mbslen(get_text(cur_line))) cursor = (short)_mbslen(get_text(cur_line)); return done(this);
    case 0x25:
        if (line_count < 1) return 1;
        if (cur_line >= line_count - 1) return 1;
        cur_line++; if (cursor > _mbslen(get_text(cur_line))) cursor = (short)_mbslen(get_text(cur_line)); return done(this);
    case 0x26:
        if (line_count < 1) return 1;
        if (p4) { if (cursor==0 && cur_line==0) return 1; cur_line=0; cursor=0; return done(this); }
        if (cursor==0) return 1; cursor=0; return done(this);
    case 0x27:
        if (line_count < 1) return 1;
        if (p4) { if (cur_line == line_count-1 && cursor == _mbslen(get_text(cur_line))) return 1; cur_line=line_count-1; cursor=(short)_mbslen(get_text(cur_line)); return done(this); }
        if (cursor == _mbslen(get_text(cur_line))) return 1; cursor=(short)_mbslen(get_text(cur_line)); return done(this);
    case 0x28:
        if (line_count < 1) return 1;
        if (cur_line <= 0) return 1;
        if (cur_line < page_top || cur_line > *(short*)((char*)this+0xfe)) cur_line = page_top;
        if (cur_line == page_top) { scroll(5,0,1); cur_line = page_top; }
        cursor = (short)_mbslen(get_text(cur_line)); return done(this);
    case 0x29:
        if (line_count < 1) return 1;
        if (cur_line >= line_count-1) return 1;
        if (cur_line < page_top || cur_line > *(short*)((char*)this+0xfe)) cur_line = *(short*)((char*)this+0xfe);
        if (cur_line == *(short*)((char*)this+0xfe)) { scroll(4,0,1); cur_line = *(short*)((char*)this+0xfe); }
        cursor = (short)_mbslen(get_text(cur_line)); return done(this);
    case 0x2e: page_up(); return 1;
    case 0x30: if (p5) { paste(); return 1; } if (!p4) { insert_mode = !insert_mode; return 1; } break;
    case 0x31: copy(); return 1;
    case 0x32: if (mode == 7) { action10(10); return 1; } if (*(void**)((char*)this+0x40)) { void* o=*(void**)((char*)this+0x40); (*(void (__stdcall**)(void*,void*,int,int,int))((char*)*(void**)o+0xB4))(o,this,0,0,0); return 1; } break;
    case 0x33: if (*(void**)((char*)this+0x40)) { void* o=*(void**)((char*)this+0x40); (*(void (__stdcall**)(void*,void*,int,int,int))((char*)*(void**)o+0xB4))(o,this,1,0,0); return 1; } break;
    default: if (p4) { paste(); return 1; } break;
    }
    return 0;
}
