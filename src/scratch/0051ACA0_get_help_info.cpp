// TRIBE_Panel_Inven::get_help_info
// Returns help text for a screen position. Checks several x-band regions,
// formats the appropriate resource value into the output string.
// tried direct cast expressions instead of named val locals; VC5 still saves __ftol result in edi across get_string
// tried stdio include/prototype context; no change to the sprintf argument evaluation basin
// tried reference-parameter spelling and x-dependent -1 assignment; no change to the val/save basin
// tried dst/fmt temps; dst temp pushes val earlier but hoists *out_str into edi too early, so not kept
// tried pointer-parameter spelling (char**/long*) with *out_str/*out_val; it fixes the sprintf arg order/reload pattern but VC5 tail-merges the first two resource arms to 288 bytes
// tried #line donor line numbers, else-if nesting, return spelling, /GX, and stdio include with the pointer spelling; no change to the first-two-arm tail merge
// rapid natural probes: late-assigned val, one outer val, player local, per-branch values local all stayed tail-merged/smaller
// rapid pointer-style probes: inline float cast, later val assignment, id expressions, return-temp forms, volatile refs/pointers, nested else all still tail-merged when behavior stayed natural
// best local clue: making only the second arm assign out_val before sprintf prevents the merge and makes the first arm exact through its return, but it changes side-effect order so it was not kept
// tried source with a single final out_val assignment/return after the if-chain; natural and matches line-map intuition, but VC5 merged harder to 272 bytes
// tried explicit goto labels for the resource arms; still merged/shared enough to shrink to 304 bytes, so not kept
// tried sprintf prototype variants and common flag variants (/Ot,/Og,/Oi,/Ob,/O1,/Ox,/Gf); no improvement and no custom rsp kept
// tried second-arm page/out/id/return-result variations; most stayed 288, volatile local variants only reached 304/320 and were wrong-code-shape
// tried pasted lead: per-arm out_val assignment with one final return; still tail-merged to 288, not the missing shape
// tried pasted lead second-arm lvalue/base-call/long-val/immediate-label variants; all stayed 288
// tried debug-info flags /Zi,/Z7,/Zd; using temporary COFF text extractor shows /Zi,/Z7,/Zd still produce 288-byte merged outputs; /Og- gives 383-byte different basin
// tried get_string return/calling-convention surface; const return no change, cdecl changed size to 304 but wrong call convention/source model
// tried ref signature spelling, out_str[0], this->get_string, alternate float indexing, inline helper, and return/assign spellings; all still tail-merged to 288
// tried /Gy, /Ob0, /Gf-/GF, /Zi/Zd, /Ow-, /Oa-, /Op, /G3/G5, and /Og- probes; only /Og- prevents merging, but it falls into a larger 383-byte EBP-frame basin
// tried one-arm syntactic differences and comma/conditional call forms; VC5 canonicalized them back to the same 288-byte shared-tail family
// tried /Od and /O1 variants: /Od compiles to Rebuilt 326 (not matching; first mismatch at 0), while /O1 with prior probes collapsed further
// probing volatility/read-before-write variants on out_val in first/second arms gave 304/320 except when the second arm writes out_val before sprintf (not kept), which gave 326 with mismatch around 58/145 depending on extra first-arm noise
// added helper script tools/tmp_extract_coff_text.py to sidestep COFF parser debug-object issues

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" long __cdecl __ftol(void);

extern int TRIBE_Panel_Inven_vftable;

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    virtual void vf24(void);
    virtual void vf28(int mode);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void* rect);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(long w, long h);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual int vfBC(long x, long y);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);

    char* get_string(int string_id);
};

class TRIBE_Player {
public:
    char gap_00[0x50];
    float* float_values;
};

class TRIBE_Panel_Inven : public TPanel {
public:
    char gap_04[0xF0];
    void* pics;
    TRIBE_Player* player;
    short save_attr_num;
    short gap_FE;
    short* save_attr;

    unsigned char get_help_info(char** out_str, long* out_val, long x, long y);
};

unsigned char TRIBE_Panel_Inven::get_help_info(char** out_str, long* out_val, long x, long y) {
    if (*(int*)((char*)this + 0x6C) == 0)
        return 0;

    if (!this->vfBC(x, y))
        return 0;

    int pnl_x = *(int*)((char*)this + 0x0C);

    if (x < pnl_x + 0x37) {
        int val = (int)this->player->float_values[1];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4EE), val);
        *out_val = -1;
        return 1;
    }

    if (x < pnl_x + 0x6E) {
        int val = (int)this->player->float_values[0];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4ED), val);
        *out_val = -1;
        return 1;
    }

    if (x < pnl_x + 0xA5) {
        int val = (int)this->player->float_values[3];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4EF), val);
        *out_val = -1;
        return 1;
    }

    int val = (int)this->player->float_values[2];
    sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4F0), val);
    *out_val = -1;
    return 1;
}

