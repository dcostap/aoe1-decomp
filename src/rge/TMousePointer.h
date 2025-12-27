#pragma once

#include <windows.h>

#pragma pack(push, 1)

class TDrawArea;

class TMousePointer {
public:
    // Size: 0x254
    char Name[32];
    int Type;
    int Visible;
    int X;
    int Y;
    int Width;
    int Height;
    int HotX;
    int HotY;
    TDrawArea *DrawArea;
    void *Surface;
    void *BackSurface;
    void *SaveSurface;
    int SaveX;
    int SaveY;
    int SaveWidth;
    int SaveHeight;
    int SaveActive;
    int SaveVisible;
    int SaveType;
    int SaveHotX;
    int SaveHotY;
    int SaveDrawArea;
    int SaveSurfacePtr;
    int SaveBackSurfacePtr;
    int SaveSaveSurfacePtr;
    
    // ... many more fields ...
    char padding[0x254 - 100]; // Placeholder for now

    TMousePointer(int custom_type);
    ~TMousePointer();

    int setup(int custom_mouse, TDrawArea *draw_area, char *cursor_file, int resource_id, int count);
};

#pragma pack(pop)
