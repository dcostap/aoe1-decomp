// attempt 1: size 80 (1 byte short)
// attempt 2: early returns, mismatch at 11 (layout)
// attempt 3: same as attempt 1, still 80
// attempt 4: force inner check, size 81, mismatch at 12 (jump offsets, cond shapes)
// attempt 5: fix idx/sum checks, size 80
// attempt 6: back to attempt 4 structure, fix idx to match original test edx,edx

class RGE_TimeSinceLastCall {
public:
    char gap_00[0x10C];
    unsigned long aTSLC[101];
    int Offset;
    char gap_2A4[0xC];
    unsigned long cps;

    unsigned long GetAvg(int count);
};

unsigned long RGE_TimeSinceLastCall::GetAvg(int count) {
    unsigned long sum = 0;
    int i;
    int idx;
    if (count >= 1 && count <= 100) {
        idx = Offset;
        i = 0;
        if (count > 0) {
            do {
                idx--;
                if (idx <= 0) idx = 100;
                sum += aTSLC[idx];
                if (sum >= 0x3E8) cps = i;
                i++;
            } while (i < count);
        }
        return sum / count;
    }
    return 0;
}
