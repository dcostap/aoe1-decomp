typedef void* HGLOBAL;
typedef void* HMMIO;
extern "C" __declspec(dllimport) HGLOBAL __stdcall GlobalFree(HGLOBAL hMem);
extern "C" __declspec(dllimport) int __stdcall mmioClose(HMMIO hmmio, unsigned int flags);

int _WaveCloseReadFile(HMMIO* hmmio, HGLOBAL* pwav) {
    if (*pwav != 0) {
        GlobalFree(*pwav);
        *pwav = 0;
    }
    if (*hmmio != 0) {
        mmioClose(*hmmio, 0);
        *hmmio = 0;
    }
    return 0;
}
