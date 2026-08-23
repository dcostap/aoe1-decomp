// VA: 005405C0 command_place_multi_object (31B)
// PDB-qualified owner: public virtual int RGE_Main_View::command_place_multi_object(
//     long, long, long, long, int) in vw_main.cpp, lines 1915-1920.
// Original body bytes: 005405C0-005405DE inclusive; next symbol 005405E0.
//
// BINARY NOTE: The method clears the selection area, publishes redraw state,
// then returns zero. The vtable load follows the first call, so keep that
// reread and the call order.
//
// Exact baseline: 31 bytes, 14 instructions, two calls, no frame, saved ESI.
//
// Exact-finish audit:
// - The PDB virtual marker and reviewed set_redraw name both reproduce the
//   baseline bytes.
// - Removing either marker also reproduces the bytes, but the retained form
//   states the PDB owner and the proven vtable slot.

class RGE_Main_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void set_redraw(int mode); // vtable slot +0x20

    void set_selection_area(long x0, long y0, long x1, long y1);
    virtual int command_place_multi_object(long a, long b, long c, long d, int mode);
};

int RGE_Main_View::command_place_multi_object(long a, long b, long c, long d, int mode) {
    set_selection_area(-1, -1, -1, -1);
    set_redraw(1);
    return 0;
}
