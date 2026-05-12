// VA: 00477AF0 TInputPanel::delete_character
// Source: Pnl_inp.cpp lines 663-760
// Attempt log:
// 1: initial reconstruction from packet/decompiler; close but start/p colored EBP/EBX opposite original.
// 2: mark start register no codegen change.
// 3: mark current pointer register no change.
// 4: declare current pointer before source-start pointer no change.
// 5: rewrite with literal decompiler pcVar names/order; only compare polarity/source spelling mismatches remain.
// 6: spell initial and LF-before tests with original operand order.

typedef unsigned long ulong;

extern "C" unsigned char* __cdecl _mbsncpy(unsigned char* dst, const unsigned char* src, unsigned int count);
extern "C" unsigned char* __cdecl _mbsninc(const unsigned char* str, unsigned int count);
extern "C" unsigned char* __cdecl _mbsinc(const unsigned char* str);
extern "C" unsigned char* __cdecl _mbsdec(const unsigned char* start, const unsigned char* cur);
extern ulong __cdecl debug_timeGetTime(char* file, int line);

class TInputPanel {
public:
    char gap_000[0x190];
    ulong caret_last_time;
    int draw_caret;
    char gap_198[0x1A0 - 0x198];
    unsigned char* input_buffer;
    unsigned char* input_buffer1;
    unsigned char* input_buffer2;
    short input_len;
    char gap_1AE[0x1B4 - 0x1AE];
    short input_pos;

    void reformat();
    void calc_cur_line_col();
    int delete_character();
};

int TInputPanel::delete_character()
{
    int bVar1;
    unsigned char* pcVar2;
    unsigned char* pcVar3;
    unsigned char* pcVar4;
    int move_back_one;

    if (this->input_pos >= this->input_len) {
        return 0;
    }

    pcVar3 = this->input_buffer1;
    bVar1 = 0;
    if (this->input_buffer == pcVar3) {
        pcVar4 = pcVar3;
        pcVar3 = this->input_buffer2;
    } else {
        pcVar4 = this->input_buffer2;
    }
    this->input_buffer = pcVar3;
    *pcVar3 = 0;

    pcVar2 = pcVar4;
    move_back_one = (int)pcVar3;
    if (0 < this->input_pos) {
        _mbsncpy(pcVar3, pcVar4, (int)this->input_pos);
        pcVar2 = _mbsninc(pcVar4, (int)this->input_pos);
        move_back_one = (int)_mbsninc(pcVar3, (int)this->input_pos);
    }

    if (*pcVar2 == '\r') {
        pcVar3 = _mbsinc(pcVar2);
        pcVar4 = (unsigned char*)1;
        if (*pcVar3 == '\n') {
            pcVar3 = _mbsinc(pcVar3);
            pcVar4 = (unsigned char*)2;
        }
    } else {
        if ((*pcVar2 == '\n') && (pcVar2 > pcVar4)) {
            pcVar4 = _mbsdec(pcVar4, pcVar2);
            if (*pcVar4 == '\r') {
                move_back_one = (int)_mbsdec(pcVar3, (unsigned char*)move_back_one);
                pcVar3 = _mbsninc(pcVar4, 2);
                pcVar4 = (unsigned char*)2;
                bVar1 = 1;
                goto do_copy;
            }
            pcVar3 = _mbsninc(pcVar4, 2);
        } else {
            pcVar3 = _mbsinc(pcVar2);
        }
        pcVar4 = (unsigned char*)1;
    }

do_copy:
    _mbsncpy((unsigned char*)move_back_one, pcVar3, ((int)this->input_len - (int)this->input_pos) + 1);
    if (bVar1) {
        --this->input_pos;
    }
    this->input_len -= (short)(int)pcVar4;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 0x2F6);
    return 1;
}
