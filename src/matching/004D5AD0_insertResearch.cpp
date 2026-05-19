// TribeBuildAIModule::insertResearch
// VA: 004D5AD0
// Fresh 2026-05-19: replace placeholder with packet-derived natural member call.

class RGE_Player;

class BuildItem {
public:
    char gap_00[0x6c];
    BuildItem* next;
    int built() const;
};

class BuildAIModule {
public:
    char gap_000[0xf0];
    BuildItem buildList;
    char gap_160[0x45c];
    RGE_Player* player; // +0x5bc points to object whose +0xf0 is player in original packet? modeled locally below by MD
    int insertItem(RGE_Player* player, int objType, int count, int itemType, int p5, int buildCap, int index);
};

class TribeMD { public: char gap_000[0xf0]; RGE_Player* player; };

class TribeBuildAIModule {
public:
    char gap_000[0xf0];
    BuildItem buildList;
    char gap_160[0x45c];
    TribeMD* md; // +0x5bc
    int insertItem(RGE_Player* player, int objType, int count, int itemType, int p5, int buildCap, int index);
    int insertResearch(int research, int index);
};

int TribeBuildAIModule::insertResearch(int research, int index)
{
    if (research != 5 && (research <= 6 || research > 8)) {
        return 0;
    }

    if (index == -1) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;
        int count = 0;
        while (item != sentinel && item != 0 && item->built() == 1) {
            item = item->next;
            count++;
        }
        return this->insertItem(this->md->player, research, 1, 1, 0x2d, 1, count);
    }
    return this->insertItem(this->md->player, research, 1, 1, 0x2d, 1, index);
}
