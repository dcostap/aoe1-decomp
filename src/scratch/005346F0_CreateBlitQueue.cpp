// VA: 005346F0 RGE_View::CreateBlitQueue
// Attempt log:
// v1 natural RECT/queue implementation with duplicated one-blit tail: compiled 780B but 94.49% positional, stack 0x14 not original 0x34.
// v2 single allocation/fill tail, top locals mirror packet names: undersized 736B under /O2, so tail sharing got closer structurally but not size.
// v3 /GX with v2: no change, still 736B; rolled back flag because no EH evidence.
// v4 /Od with v2: 780B same size but EBP-frame /Od family, 95.00% positional; rolled back flag.
// v5 kept v2 because it is cleaner and documents likely intended source, but it is not accepted-drift-safe.
// scratch give-up: first-pass source understands clipping, allocation, one-blit, queue loop, and final fields, but VC5 local/frame and block-shape basin is still wrong.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);

struct tagRECT { long left; long top; long right; long bottom; };
struct Blit_Queue_Entry { tagRECT src; tagRECT dest; };

class RGE_View {
public:
    char gap_000[0x8c];
    int Blit_Offset_X;
    int Blit_Offset_Y;
    char gap_094[0x244];
    int Queued_Blits;
    Blit_Queue_Entry* Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    void CreateBlitQueue(tagRECT& src, tagRECT& dst, int xd, int yd);
};

void RGE_View::CreateBlitQueue(tagRECT& param_1, tagRECT& param_2, int param_3, int param_4)
{
    int One_Blit;
    int vBlits;
    int blt_deltaY = 0;
    int blt_deltaX;
    int local_24;
    tagRECT blt_src;
    int local_4;
    int outside;

    outside = 0;
    if ((param_3 != 0) || (param_4 != 0)) {
        int iVar6 = param_1.top;
        int iVar1;
        int iVar2;
        int iVar3;
        if ((param_2.bottom < iVar6) ||
            (((iVar1 = param_1.left, param_2.right < iVar1 ||
              (iVar2 = param_1.bottom, iVar2 < param_2.top)) ||
             (iVar3 = param_1.right, iVar3 < param_2.left)))) {
            outside = 1;
            vBlits = 1;
            blt_src.left = param_1.left;
            blt_src.top = param_1.top;
            blt_src.right = param_1.right;
            local_4 = param_1.bottom;
        } else {
            int yd_abs = param_4;
            if (yd_abs < 0) yd_abs = -yd_abs;
            int xd_abs = param_3;
            if (xd_abs < 0) xd_abs = -xd_abs;
            One_Blit = 9999;
            vBlits = 9999;
            if (param_4 != 0) One_Blit = (yd_abs + (iVar2 - iVar6)) / yd_abs;
            if (param_3 != 0) vBlits = (xd_abs + (iVar3 - iVar1)) / xd_abs;
            blt_src.left = param_1.left;
            blt_src.top = param_1.top;
            blt_src.right = param_1.right;
            local_4 = param_1.bottom;
            local_24 = 0;
            blt_deltaX = 0;
            if (One_Blit < vBlits) {
                vBlits = One_Blit;
                blt_deltaX = param_4;
                if (param_4 < 0) blt_src.top = param_4 + iVar2 + 1;
                else local_4 = param_4 + iVar6 - 1;
            } else {
                local_24 = param_3;
                if (param_3 < 0) blt_src.left = param_3 + iVar3 + 1;
                else blt_src.right = param_3 + iVar1 - 1;
            }
        }

        if (this->Blt_Queue_Allocated < vBlits) {
            if (this->Blit_Queue != 0) free(this->Blit_Queue);
            this->Blit_Queue = 0;
        }
        if (this->Blit_Queue == 0) {
            this->Blit_Queue = (Blit_Queue_Entry*)calloc(vBlits, 0x20);
            this->Blt_Queue_Allocated = vBlits;
        }
        if (outside) {
            this->Blit_Queue[0].src = param_1;
            this->Blit_Queue[0].dest = param_2;
        } else if (vBlits > 0) {
            int off = 0;
            int count = vBlits;
            do {
                Blit_Queue_Entry* e = (Blit_Queue_Entry*)((char*)this->Blit_Queue + off);
                e->src.left = blt_src.left;
                e->src.top = blt_src.top;
                e->src.right = blt_src.right;
                e->src.bottom = local_4;
                e->dest.top = blt_src.top - param_4;
                e->dest.left = blt_src.left - param_3;
                e->dest.bottom = local_4 - param_4;
                e->dest.right = blt_src.right - param_3;
                blt_src.top += blt_deltaX;
                local_4 += blt_deltaX;
                blt_src.left += local_24;
                blt_src.right += local_24;
                if (blt_src.top < param_1.top) blt_src.top = param_1.top;
                if (blt_src.left < param_1.left) blt_src.left = param_1.left;
                if (blt_src.right > param_1.right) blt_src.right = param_1.right;
                if (local_4 > param_1.bottom) local_4 = param_1.bottom;
                off += 0x20;
                count--;
            } while (count != 0);
        }
        this->Queued_Blits = 1;
        this->Blit_Queue_Size = vBlits;
        this->Current_Blit = -1;
        this->Blit_Offset_X = this->Blit_Offset_X;
        this->Blit_Offset_Y = this->Blit_Offset_Y;
    }
}
