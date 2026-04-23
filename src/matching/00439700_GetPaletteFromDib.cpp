extern "C" void* __cdecl DibOpenFile(char* path);
extern "C" void* __cdecl DibCreatePalette(void* dib);
extern "C" void __cdecl CreateIdentityPalette(void* palette);
extern "C" void __cdecl DibFree(void* dib);

void* __cdecl GetPaletteFromDib(char* path, int make_identity) {
    void* dib = DibOpenFile(path);
    if (dib == 0)
        return 0;

    void* palette = DibCreatePalette(dib);
    if (make_identity != 0)
        CreateIdentityPalette(palette);

    DibFree(dib);
    return palette;
}
