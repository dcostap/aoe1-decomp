// VA: 004E4040 TribeInformationAIModule::lookAtMap
// BLOCKER: Persistent structural mismatch.

class RGE_Static_Object;
class RGE_Object_List_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_List_Node* next;
};

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrain;
    char gap_06[0x10 - 0x06];
    RGE_Object_List_Node* objects;
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    int md;
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10C[0x560 - 0x10C];
    int numberFoundForestTilesValue;

    void lookAtMap(void);
    int importantObject(int group);
    int addImportantObject(void* obj, int value);
};

void TribeInformationAIModule::lookAtMap(void)
{
    int local_18 = 0;
    if (this->mapXSizeValue > 0) {
        int numberTreesOnTile = 0;
        int gMap = 0;
        do {
            int iVar5 = this->mapYSizeValue;
            int local_c = 0;
            if (iVar5 > 0) {
                int tileType = 0;
                do {
                    if (this->mapXSizeValue != -1) {
                        int iVar4 = gMap / this->mapXSizeValue;
                        ++((int*)this)[(tileType / iVar5 + iVar4 * 4 + 0x56) * 3];
                    }
                    ++local_c;
                    tileType += 4;
                } while (local_c < iVar5);
            }
            ++local_18;
            numberTreesOnTile += 0x18;
            gMap += 4;
        } while (local_18 < this->mapXSizeValue);
    }
}
