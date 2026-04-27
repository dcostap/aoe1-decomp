// first pass: seek to the 'data' chunk, then descend into it with mmioDescend
// tried stdcall imports and the obvious parent/data pointer layout; the remaining mismatch stayed in the stack-arg indexing around the success path
// current best lead: the third-arg load still wants a different caller stack shape than the natural 3-pointer spelling
// First-pass skeleton/partial — needs proper implementation

struct MMIOINFO {
    int handle;
};

struct MMCKINFO {
    int ckid;
};

struct MMCKINFO_PARENT {
    char gap_00[0xC];
    int ckid;
};

extern "C" long __stdcall mmioSeek(int handle, long offset, int origin);
extern "C" long __stdcall mmioDescend(int handle, MMCKINFO* ck, MMCKINFO_PARENT* parent, unsigned int flags);

unsigned int __cdecl _WaveStartDataRead(MMIOINFO* io, MMCKINFO_PARENT* parent, MMCKINFO* ck) {
    if (mmioSeek(io->handle, parent->ckid + 4, 0) == -1) {
        return 1;
    }

    ck->ckid = 0x61746164;
    return (unsigned int)mmioDescend(io->handle, ck, parent, 0x10);
}
