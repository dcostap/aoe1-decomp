// STATUS: blocked
// tried the earlier natural clamp shape; mismatch started near the prologue register setup
// switched to the Ghidra-style iVar3/iVar1 shape; first mismatch moved deeper into the swap/clamp register choreography at 0053B30D
// BLOCKER: behavior matches, but VC5 still carries the clamped minimum level in edx/eax opposite the original's eax/edx split, shifting the middle search loop register shape
// NOTE: bounds clamp and list walk are understood; remaining drift is register-choice/source-shape only

struct DClipInfo_Node {
    DClipInfo_Node* Next;
    DClipInfo_Node* NextOnLevel;
    int Object_ID;
    char gap_0C[0x20];
    int Node_Type;
};

class DClipInfo_List {
public:
    char gap_00[0x4C];
    int Max_Draw_Levels;
    char gap_50[0x08];
    DClipInfo_Node** Draw_Level_Head;

    DClipInfo_Node* LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type);
};

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type) {
    int iVar1;
    DClipInfo_Node* pDVar2;
    int iVar3;
    DClipInfo_Node** ppDVar4;

    iVar3 = min_level;
    if (iVar3 > max_level) {
        iVar3 = max_level;
        max_level = min_level;
    }
    if (iVar3 < 0) {
        iVar3 = 0;
    }
    iVar1 = this->Max_Draw_Levels;
    if (iVar1 < max_level) {
        max_level = iVar1;
    }
    if (((iVar3 <= iVar1) && (-1 < max_level)) && (iVar3 <= max_level)) {
        ppDVar4 = this->Draw_Level_Head + iVar3;
        do {
            for (pDVar2 = *ppDVar4; pDVar2 != 0; pDVar2 = pDVar2->NextOnLevel) {
                if ((pDVar2->Object_ID == object_id) && (pDVar2->Node_Type == node_type)) {
                    return pDVar2;
                }
            }
            iVar3 = iVar3 + 1;
            ppDVar4 = ppDVar4 + 1;
        } while (iVar3 <= max_level);
    }
    return 0;
}
