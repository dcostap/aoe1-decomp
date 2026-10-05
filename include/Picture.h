#ifndef AOE1_PICTURE_H
#define AOE1_PICTURE_H

#include "drawarea.h"
#include "picture_types.h"

class TPicture {
  public:
    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    unsigned char* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;

    TPicture(char* FileName, long res_id, int UseTrans, void* MapToPal, int ZeroIsTrans);
    TPicture(int infile, int UseTrans);
    TPicture();
    ~TPicture();

    void Save(int outfile);
    void Load(char* FileName, long res_id, int UseTrans, void* MapToPal, int ZeroIsTrans);
    void Init(BITMAPINFO256* FromInfo, unsigned char* FromBits, TRANSINFO* FromTrans);
    long AlignedWidth();
    void Draw(TDrawArea* DrawArea, long DestX, long DestY, int Mirror, int Flip);
    long Tile(
        TDrawArea* DrawArea, long DestX, long DestY, long DestWid, long DestHgt, long BlockWid, long BlockHgt,
        long SrcX, long SrcY, long SrcWid, long SrcHgt
    );
    unsigned char GetPixel(long x, long y, int Mirror, int Flip);
};

typedef char picture_size_check[(sizeof(TPicture) == 0x20) ? 1 : -1];

#endif
