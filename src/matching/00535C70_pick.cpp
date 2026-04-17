struct tagPOINT {
    long x;
    long y;
};

class RGE_View {
public:
    long view_function(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2, void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row);
    unsigned char pick(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2, void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row);
};

unsigned char RGE_View::pick(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2, void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row) {
    return (unsigned char)view_function(a1, a2, p1, p2, out_obj, out_x, out_y, out_col, out_row);
}
