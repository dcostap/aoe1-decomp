// Keep the C++ owner surface shared with the later Dib.cpp definitions.  The
// old C-linkage shims made grouped compilation bind to four unrelated
// external symbols instead of the canonical owners.
struct tagBITMAPINFOHEADER;
extern tagBITMAPINFOHEADER* __cdecl DibOpenFile(char* path);
extern void* __cdecl DibCreatePalette(tagBITMAPINFOHEADER* dib);
extern void __cdecl CreateIdentityPalette(void* palette);
extern void __cdecl DibFree(tagBITMAPINFOHEADER* dib);

void* __cdecl GetPaletteFromDib(char* path, int make_identity) {
    tagBITMAPINFOHEADER* dib = DibOpenFile(path);
    if (dib == 0)
        return 0;

    void* palette = DibCreatePalette(dib);
    if (make_identity != 0)
        CreateIdentityPalette(palette);

    DibFree(dib);
    return palette;
}
