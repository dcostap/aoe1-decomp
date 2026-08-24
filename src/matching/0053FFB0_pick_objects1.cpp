// target: VA 0053FFB0 RGE_Main_View::pick_objects1(long,long,RGE_Static_Object**,int)
// first pass: mirror the pick loop, stop-on-mismatch behavior, and duplicate-suppression check
// probe 1: direct compare against *objects caused an early pretest basin; try a saved first-result local instead
// probe 2: the wider local set moved VC5 into a worse prolog basin; try the literal decompiler shape with only the packed pick_info local
// probe 3: variant lab over pick_info.object vs pick_info.tile proved original uses object (+0x1C stack load); object_all and object_saved_local exact-matched

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_View {
public:
    unsigned char pick(unsigned char, unsigned char, long, long, RGE_Pick_Info*, RGE_Static_Object*);
};

class RGE_Main_View : public RGE_View {
public:
    int pick_objects1(long x, long y, RGE_Static_Object** objects, int max_count);
};
#endif

int RGE_Main_View::pick_objects1(long param_1, long param_2, RGE_Static_Object** param_3, int param_4) {
    RGE_Static_Object* pRVar2;
    int iVar3;
    RGE_Static_Object** ppRVar4;
    RGE_Pick_Info pick_info;

    ppRVar4 = param_3;
    pRVar2 = 0;
    iVar3 = 0;
    while (true) {
        if (iVar3 == param_4) {
            return iVar3;
        }
        if (this->pick(0x29, 0, param_1, param_2, &pick_info, pRVar2) != 0x34) {
            break;
        }
        if ((0 < iVar3) && (pick_info.object == *param_3)) {
            return iVar3;
        }
        *ppRVar4 = pick_info.object;
        iVar3 = iVar3 + 1;
        ppRVar4 = ppRVar4 + 1;
        pRVar2 = pick_info.object;
    }
    return iVar3;
}
