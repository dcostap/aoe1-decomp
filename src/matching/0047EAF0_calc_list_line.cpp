// rdlg_lst.cpp:331-353, 108 bytes
// attempt 1: 96 bytes, offsets wrong
// attempt 2: 96 bytes, offsets wrong
// attempt 3: 93.5%, vfunc call pattern wrong
// attempt 4: 72.2%, vfunc slot at +0xDC not +0x13C
// attempt 5: 96 bytes, too small with 52 vfuncs
// attempt 6: 70.4%, vfunc slot correct, register basin diff
// attempt 7 (SparkleSquirrel): struct+local+natural form, 60.2%, still saving sel_id
// attempt 8: remove named 'entries' local, 50.9%, still saving sel_id
// attempt 9: (i*16+i)*6 expression, same 50.9%
// attempt 10: use real rdlg_list_info type with natural member access

struct rdlg_list_info {
    char text[100];
    short id;
};

class RGE_Dialog_List {
public:
    virtual short vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfAC();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbC();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfCC();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual short vf13C();
    char gap_04[0x4AC - 4];
    int list_type;          // +0x4AC
    short list_size;        // +0x4B0
    short list_line;        // +0x4B2
    rdlg_list_info* list_info;  // +0x4B4
    char** list_text;       // +0x4B8

    void calc_list_line();
};

void RGE_Dialog_List::calc_list_line() {
    list_line = -1;
    short sel_id = vf13C();
    if (sel_id != -1) {
        for (short i = 0; i < list_size; i++) {
            if (list_info[i].id == sel_id) {
                list_line = i;
                break;
            }
        }
    }
    if (list_line == -1) {
        list_line = 0;
    }
}
