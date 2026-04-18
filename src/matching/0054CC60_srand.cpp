extern unsigned long holdrand;
void __cdecl srand(unsigned int seed) {
    holdrand = seed;
}
