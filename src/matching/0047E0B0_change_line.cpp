// attempt log:
// first pass: natural save/clear/restore spelling around the insert/delete helpers
// target shape: save sorted at 0x15C, zero it, call insert_line with four longs, restore on both exits

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    char gap_00[0x15C];
    int sorted;

    int insert_line(long a1, long a2, long a3, long a4);
    int delete_line(long line);

    int change_line(long a1, long a2, long a3, long a4);
};
#endif

int TTextPanel::change_line(long a1, long a2, long a3, long a4) {
    int saved_sorted = this->sorted;
    this->sorted = 0;

    if (insert_line(a1, a2, a3, a4) == 0) {
        this->sorted = saved_sorted;
        return 0;
    }

    delete_line(a1 + 1);
    this->sorted = saved_sorted;
    return 1;
}
