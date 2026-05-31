/* VA: 00447C60 _DSParseWaveResource */
/* Dsutil.c lines 338-411, 240 bytes */

typedef unsigned long DWORD;
typedef unsigned char BYTE;

typedef struct WAVEFORMAT {
    unsigned short wFormatTag;
    unsigned short nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    unsigned short nBlockAlign;
} WAVEFORMAT;

int __cdecl _DSParseWaveResource(void* pvRes, void** ppWaveHeader, BYTE** ppbData, DWORD* pdwDataSize)
{
    DWORD* pdw;
    DWORD dwRiff;
    DWORD dwLength;
    DWORD dwType;
    DWORD* pdwEnd;

    if (ppWaveHeader) {
        *ppWaveHeader = 0;
    }
    if (ppbData) {
        *ppbData = 0;
    }
    if (pdwDataSize) {
        *pdwDataSize = 0;
    }

    pdw = (DWORD*)pvRes;
    dwRiff = *pdw++;
    dwLength = *pdw++;
    dwType = *pdw++;

    if (dwRiff != 0x46464952) {
        return 0;
    }
    if (dwType != 0x45564157) {
        return 0;
    }

    pdwEnd = (DWORD*)((BYTE*)pdw + dwLength - 4);

    while (pdw < pdwEnd) {
        dwType = *pdw++;
        dwLength = *pdw++;

        switch (dwType) {
        case 0x61746164:
            if ((ppbData && !*ppbData) || (pdwDataSize && !*pdwDataSize)) {
                if (ppbData) {
                    *ppbData = (BYTE*)pdw;
                }
                if (pdwDataSize) {
                    *pdwDataSize = dwLength;
                }

                if (!ppWaveHeader || *ppWaveHeader) {
                    return 1;
                }
            }
            break;

        case 0x20746D66:
            if (ppWaveHeader && !*ppWaveHeader) {
                if (dwLength < 0x0e) {
                    return 0;
                }
                *ppWaveHeader = pdw;

                if ((!ppbData || *ppbData) && (!pdwDataSize || *pdwDataSize)) {
                    return 1;
                }
            }
            break;
        }

        pdw = (DWORD*)((BYTE*)pdw + ((dwLength + 1) & ~1));
    }

    return 0;
}
