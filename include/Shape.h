#ifndef AOE1_SHAPE_H
#define AOE1_SHAPE_H

typedef unsigned char byte;

typedef struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
} Shape_Header;

typedef struct Shape_File_Header {
    long version;
    long shape_num;
} Shape_File_Header;

typedef struct Shape_Offsets {
    long shape;
    long palette;
} Shape_Offsets;

typedef struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
} SLhape_File_Header;

typedef struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
} Shape_Info;

struct Shape_Payload {
    byte value;
};

struct Byte_Table {
    union {
        byte table[256];
        byte value[256];
    };
};

struct Shape_Byte_Table {
    byte table[256];
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3c];
    void* Line_Head_Ptrs;
    void* Line_Tail_Ptrs;
    char gap_44[0x0c];
    int Num_Lines;
    char gap_54[8];
    int Max_Span_Px;
};

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    byte* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    void* DrawSurface;
    char SurfaceDesc[0x6C];
    void* Node;
    char* Name;
    byte* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    void* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    byte TransColor;
    byte gap_FD[3];

    long AlignedWidth();
};

typedef tagRECT Rect;
typedef Shape_File_Header ShapeFile;
typedef Shape_Header TShapeHeader;

class DClipInfo_List {
public:
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline,
                     int draw_x, int draw_y, int draw_flag,
                     byte* color_table, int xform_mask,
                     int draw_level, int object_id);
};

class TShape {
public:
    byte* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;

    TShape();
    TShape(char* filename, long resource_id);
    ~TShape();

private:
    byte Check_shape(long index, char* name);

public:
    int is_loaded();
    byte shape_bounds(long index, short& width, short& height);
    long shape_count();
    byte shape_minmax(long& min_x, long& min_y, long& max_x, long& max_y,
                      long index);
    byte shape_check(long x, long y, long frame);

private:
    byte shape_draw_unclipped(TDrawArea*, long, long, long);
    byte shape_color_trans_unclipped(TDrawArea*, long, long, long, byte*);
    byte shape_shadow_unclipped(TDrawArea*, long, long, byte*);
    byte shape_draw_clipped(TDrawArea*, long, long, long, long, long, long);
    byte shape_color_trans_clipped(TDrawArea*, long, long, long,
                                   long, long, long, long, byte*);
    byte shape_shadow_clipped(TDrawArea*, long, long, long,
                              long, long, long, byte*);

public:
    byte shape_draw(TDrawArea*, long, long, long, byte, byte*);

private:
    byte shape_mirror_unclipped(TDrawArea*, long, long);
    byte shape_mirror_color_trans_unclipped(TDrawArea*, long, long,
                                            long, byte*);
    byte shape_mirror_shadow_unclipped(TDrawArea*, long, long, byte*);
    byte shape_mirror_clipped(TDrawArea*, long, long, long,
                              long, long, long);
    byte shape_mirror_color_trans_clipped(TDrawArea*, long, long, long,
                                          long, long, long, long, byte*);
    byte shape_mirror_shadow_clipped(TDrawArea*, long, long,
                                     long, long, long, long, byte*);

public:
    byte shape_mirror(TDrawArea*, long, long, long, byte, byte*);

private:
    byte shape_dithered_unclipped(TDrawArea*, long, long, long, long);
    byte shape_dithered_clipped(TDrawArea*, long, long, long, long,
                                long, long, long, long);

public:
    byte shape_dither(TDrawArea*, long, long, long, long, long);
};

#endif
