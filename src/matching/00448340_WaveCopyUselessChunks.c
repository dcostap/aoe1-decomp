/* VA: 00448340 _WaveCopyUselessChunks */
/* Dsutil.c lines 1102-1173 */

typedef unsigned int UINT;
typedef long LONG;
typedef struct DSUTIL_WAVECOPY_MMCKINFO {
    unsigned int ckid;
    unsigned int cksize;
    unsigned int fccType;
    unsigned int dwDataOffset;
    unsigned int dwFlags;
} DSUTIL_WAVECOPY_MMCKINFO;

typedef LONG (__stdcall *MMIOSEEK)(HMMIO, LONG, int);
typedef int (__stdcall *MMIODESCEND)(HMMIO, DSUTIL_WAVECOPY_MMCKINFO*, const DSUTIL_WAVECOPY_MMCKINFO*, UINT);
typedef int (__stdcall *MMIOASCEND)(HMMIO, DSUTIL_WAVECOPY_MMCKINFO*, UINT);

#define mmioSeek_abs (*(MMIOSEEK*)0x88A928)
#define mmioDescend_abs (*(MMIODESCEND*)0x88A92C)
#define mmioAscend_abs (*(MMIOASCEND*)0x88A934)

int __cdecl riffCopyChunk(HMMIO dst, HMMIO src, DSUTIL_WAVECOPY_MMCKINFO* ck);

int __cdecl _WaveCopyUselessChunks(HMMIO* hmmio, DSUTIL_WAVECOPY_MMCKINFO* ck, DSUTIL_WAVECOPY_MMCKINFO* parent, HMMIO* src)
{
    int result;
    MMIODESCEND descend;

    if (mmioSeek_abs(*hmmio, parent->dwDataOffset + 4, 0) == -1) {
        result = 0xE102;
    } else {
        descend = mmioDescend_abs;
        result = 0;
        while (descend(*hmmio, ck, parent, 0) == 0) {
            if (ck->dwDataOffset + ck->cksize > parent->cksize + parent->dwDataOffset) {
                break;
            }
            if (ck->ckid != 0x20444150) {
                if (ck->ckid == 0x50534944 || ck->ckid == 0x74736c70) {
                    riffCopyChunk(*hmmio, *src, ck);
                }
            }
            mmioAscend_abs(*hmmio, ck, 0);
        }
    }

    mmioSeek_abs(*hmmio, parent->dwDataOffset + 4, 0);
    return result;
}
