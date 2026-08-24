// VA: 0052DE20 command_make_do (28B)
// PDB: tvw_main.cpp, TRIBE_Main_View, lines 731-769
//
// The shipped owner is a thin derived override.  Its body forwards to the
// inherited RGE_Main_View implementation with the PDB-qualified short flag.
// The old scratch placeholder called a non-existent target and had no return.

#ifndef TVW_MAIN_SHARED_CONTEXT
class RGE_Main_View {
public:
    virtual int command_make_do(long, long, int, short);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual int command_make_do(long, long, int, short);
};
#endif

int TRIBE_Main_View::command_make_do(
    long x, long y, int mode, short flag) {
    return RGE_Main_View::command_make_do(x, y, mode, flag);
}
