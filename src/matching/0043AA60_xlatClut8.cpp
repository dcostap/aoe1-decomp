// STATUS: active lead
// loop body already matches exactly; the only remaining drift is the entry branch byte (`je` vs original `jbe`) after the initial `test ecx,ecx`
// next lead: keep the same unsigned count surface but phrase the guard as an explicit `<= 0` early return
static void __cdecl xlatClut8(unsigned char* bits, unsigned long count, unsigned char* clut) {
    if (count <= 0) {
        return;
    }
    do {
        *bits = clut[*bits];
        bits++;
        count--;
    } while (count != 0);
}
