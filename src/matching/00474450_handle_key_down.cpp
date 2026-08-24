// compact dropdown-key handler first
// expected basin: early open-state/key filter, then set_mode(2), else fall back to base panel handling

#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
    long handle_key_down(long key, short ch, int a3, int a4, int a5);
};

class TDropDownPanel : public TPanel {
public:
    char pad_00[0x78];
    int open_state;
    char pad_7C[0x88];
    int mode;

    long handle_key_down(long key, short ch, int a3, int a4, int a5);
    void set_mode(int mode);
};
#endif

long TDropDownPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    if (this->open_state != 0 && (key == 0x28 || key == 0x26) && this->mode == 1) {
        this->set_mode(2);
        return 1;
    }
    return TPanel::handle_key_down(key, ch, a3, a4, a5);
}
