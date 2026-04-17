struct DClipInfo_Node {
    char gap_00[0x1C];
    unsigned char Draw_Flag;
};

class DClipInfo_List {
public:
    DClipInfo_Node* LocateIDbyDrawLevel(int id, int min_level, int max_level, int flags);
};

class RGE_View {
public:
    char gap_00[0x334];
    DClipInfo_List* prior_objs;

    bool Object_Was_Displayed(int id, bool allow_flagged);
};

bool RGE_View::Object_Was_Displayed(int id, bool allow_flagged) {
    DClipInfo_Node* node;

    node = prior_objs->LocateIDbyDrawLevel(id, 6, 0x28, 0);
    if (node == 0) {
        return false;
    }
    if (!allow_flagged && (node->Draw_Flag & 1) != 0) {
        return false;
    }
    return true;
}
