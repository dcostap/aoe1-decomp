int WaveCloseReadFile(HMMIO* hmmio, HGLOBAL* pwav) {
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
