// 00533760 RGE_View::~RGE_View (view.cpp:408-477)
// Attempt log:
// 1: Natural destructor with /GX: EH prologue matches, but pointer fields reloaded through ECX instead of original EDI locals; 64.10% diff.
// 2: Local pointer variables improved to 6.20%; remaining tail lacks explicit first TPanel dtor before compiler-emitted base dtor.
// 3: Explicitly call TPanel::~TPanel before leaving destructor body.

extern "C" void __cdecl free(void*);
extern "C" void __cdecl operator_delete(void*);
#ifndef RGE_VIEW_SHARED_CONTEXT
extern "C" int (__stdcall* const DeleteObject)(void*);
#endif
 #ifndef RGE_VIEW_SHARED_CONTEXT
extern void* MouseSystem;
 #endif

#ifndef RGE_VIEW_SHARED_CONTEXT
class TShape { public: ~TShape(); };
class TSpan_List_Manager { public: ~TSpan_List_Manager(); };
class DClipInfo_List { public: ~DClipInfo_List(); };
class TMousePointer { public: void set_game_mode(int); void set_game_enable(int); };
class TPanel { public: virtual ~TPanel(); };

class RGE_View : public TPanel {
public:
    char pad_004[0x15c - 4];
    void* red_pen;              // +15c
    char pad_160[0x164 - 0x160];
    TShape* border_line_shape;  // +164
    char pad_168[0x178 - 0x168];
    TSpan_List_Manager* Terrain_Clip_Mask; // +178
    TSpan_List_Manager* Terrain_Fog_Clip_Mask; // +17c
    TSpan_List_Manager* Master_Clip_Mask; // +180
    void* Tile_Edge_Tables;     // +184
    void* Black_Edge_Tables;    // +188
    char pad_18c[0x2c8 - 0x18c];
    void* Float_Scroll_Offsets; // +2c8
    char pad_2cc[0x2dc - 0x2cc];
    void* Blit_Queue;           // +2dc
    char pad_2e0[0x2fc - 0x2e0];
    void* pick_lists[5];        // +2fc
    char pad_310[0x32c - 0x310];
    void* RenderOffsets;        // +32c
    char pad_330[0x334 - 0x330];
    DClipInfo_List* prior_objs; // +334
    DClipInfo_List* futur_objs; // +338
    char pad_33c[0x354 - 0x33c];
    void* DispSel_List;         // +354

    virtual ~RGE_View();
    void delete_surfaces();
    void reset_overlay_sprites();
};
#endif

RGE_View::~RGE_View()
{
    TShape* shape = this->border_line_shape;
    if (shape != 0) {
        shape->~TShape();
        operator_delete(shape);
        this->border_line_shape = 0;
    }

    this->delete_surfaces();

    if (this->red_pen != 0) {
        DeleteObject(this->red_pen);
        this->red_pen = 0;
    }

    if (this->RenderOffsets != 0) {
        free(this->RenderOffsets);
    }

    TSpan_List_Manager* span = this->Terrain_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }
    span = this->Terrain_Fog_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }
    span = this->Master_Clip_Mask;
    if (span != 0) {
        span->~TSpan_List_Manager();
        operator_delete(span);
    }

    if (this->Tile_Edge_Tables != 0) free(this->Tile_Edge_Tables);
    if (this->Black_Edge_Tables != 0) free(this->Black_Edge_Tables);
    if (this->Float_Scroll_Offsets != 0) free(this->Float_Scroll_Offsets);
    if (this->Blit_Queue != 0) free(this->Blit_Queue);

    DClipInfo_List* clip = this->prior_objs;
    if (clip != 0) {
        clip->~DClipInfo_List();
        operator_delete(clip);
    }
    clip = this->futur_objs;
    if (clip != 0) {
        clip->~DClipInfo_List();
        operator_delete(clip);
    }

 #ifdef RGE_VIEW_SHARED_CONTEXT
    void** p = (void**)this->pick_lists;
 #else
    void** p = this->pick_lists;
 #endif
    int i = 5;
    do {
        if (*p != 0) free(*p);
        p++;
        i--;
    } while (i != 0);

    if (MouseSystem != 0) {
        ((TMousePointer*)MouseSystem)->set_game_mode(0);
        ((TMousePointer*)MouseSystem)->set_game_enable(0);
    }

    if (this->DispSel_List != 0) free(this->DispSel_List);

    this->reset_overlay_sprites();
    this->TPanel::~TPanel();
}
