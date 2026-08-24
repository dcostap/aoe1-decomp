// BINARY NOTE: The PDB decoration is
// ?key_down_action@TMessageDialog@@UAEJJFHHH@Z, so the second parameter is
// short and the function returns long.
#ifndef DLG_MSG_CANONICAL_TU
class TMessageDialog {
public:
    virtual ~TMessageDialog();
    long key_down_action(long p0, short p1, int p2, int p3, int p4);
};
#endif

long TMessageDialog::key_down_action(long p0, short p1, int p2, int p3, int p4) {
    return 0;
}
