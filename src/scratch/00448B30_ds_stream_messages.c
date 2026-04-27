// Dsutil.c:1684-1718, 105 bytes
// attempt 1: __ftol(double) with cmp dispatch -> 61.9%, __ftol pattern wrong (extra stack)
// attempt 2: __ftol(void) + msg-=0x500 + cmp dispatch -> 65.7%, jne vs je + __ftol stack
// attempt 3: goto restructuring -> no change (65.7%)
// attempt 4: no temp var, double __ftol -> worse (68.6%)
// attempt 5: val*100/total single expr -> 65.7% same
// attempt 6: float cast instead of double -> 65.7% same
// paused: 65.7% best, remaining gap is VC5 codegen-family (jne vs je dispatch, __ftol stack reuse)
extern unsigned int DAT_00888480;
extern unsigned int DAT_008884A4;
extern unsigned int DAT_00888454;
extern void ds_stream_stop(void);
extern int __ftol(void);

int ds_stream_messages(int param1, int msg) {
    int result;
    unsigned int val, total;
    msg -= 0x500;
    if (msg == 0) {
        ds_stream_stop();
        return 0;
    }
    if (msg != 2) {
        return 0;
    }
    val = DAT_008884A4;
    total = DAT_00888480;
    if (val > total) {
        val -= total;
        DAT_008884A4 = val;
    }
    result = __ftol((double)(val * 100 / total));
    if (result != DAT_00888454) {
        DAT_00888454 = result;
    }
    return 0;
}
