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

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Main_View {
public:
    virtual ~RGE_Main_View();
    virtual void setup(void*, RGE_Main_View*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, RGE_Main_View*, RGE_Main_View*,
                                 RGE_Main_View*, RGE_Main_View*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int mode); // vtable slot +0x20

    void set_selection_area(long x0, long y0, long x1, long y1);
    virtual int command_place_multi_object(long a, long b, long c, long d, int mode);
};
#endif

int RGE_Main_View::command_place_multi_object(long a, long b, long c, long d, int mode) {
    set_selection_area(-1, -1, -1, -1);
    set_redraw(1);
    return 0;
}
