// ACCEPTED_DRIFT: VC5 generates a redundant second null check at loop entry (while cur!=sentinel
// adds test esi,esi after the pre-loop null check). The original has one combined null check
// used by both the entry and the loop back-edge. The id parameter load (mov ebx,[esp+10h]) is
// also deferred past the null check in the rebuilt vs the original. Behavior is identical.
// Attempted: while(cur), while(1)+break, do-while, sentinel-at-top/null-inside, save_id.
// VA: 00409F50 specificBuildListItem (69B, aibldmod.cpp)

class BaseItem {
public:
    char gap_04[4];
    char gap_08[8];
    int uniqueID_;
    char gap_10[0x5C];
    BaseItem* next;
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BaseItem buildList;
    BaseItem* specificBuildListItem(int id);
};

extern int __fastcall BaseItem_uniqueID(BaseItem* p);

BaseItem* BuildAIModule::specificBuildListItem(int id)
{
    BaseItem* sentinel = &this->buildList;
    BaseItem* cur = sentinel->next;
    if (cur == sentinel) return 0;
    int save_id = id;
    if (cur == 0) return 0;
    while (cur != sentinel) {
        if (cur == 0) return 0;
        if (BaseItem_uniqueID(cur) == save_id) return cur;
        cur = cur->next;
    }
    return 0;
}
