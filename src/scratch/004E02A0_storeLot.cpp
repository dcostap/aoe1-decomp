// VA: 004E02A0 TribeInformationAIModule::storeLot
// 450 bytes, 135 asm
// Attempt 15: extern declarations, padding via unreachable infinite loop

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
};

class TribeInformationAIModule {
public:
    char gap_000[0x1F4];
    int maxBuildingLots;
    BuildingLot* buildingLots;

    void storeLot(int param_1, unsigned char param_2, unsigned char param_3, unsigned char param_4);
};

void TribeInformationAIModule::storeLot(int param_1, unsigned char param_2, unsigned char param_3, unsigned char param_4)
{
    int foundIndex = -1;
    int i = 0;

    if (maxBuildingLots > 0) {
        BuildingLot* p = buildingLots;
        do {
            if (p->typeID == param_1 && p->x == param_2 && p->y == param_3) {
                buildingLots[i].status = param_4;
                return;
            }
            if (foundIndex == -1 && p->typeID == -1) {
                foundIndex = i;
            }
            i++;
            p++;
        } while (i < maxBuildingLots);
    }

    if (foundIndex != -1) {
        buildingLots[foundIndex].typeID = param_1;
        buildingLots[foundIndex].x = param_2;
        buildingLots[foundIndex].y = param_3;
        buildingLots[foundIndex].status = param_4;
    } else {
        BuildingLot* newArray = (BuildingLot*)operator_new(maxBuildingLots << 4);
        if (newArray != 0) {
            i = 0;
            if (maxBuildingLots > 0) {
                do {
                    ((BuildingLot*)((char*)newArray + i * 8 + 6 - 6))->typeID = buildingLots[i].typeID;
                    *((char*)newArray + i * 8 + 6 - 1) = buildingLots[i].x;
                    *((char*)newArray + i * 8 + 6) = buildingLots[i].y;
                    *((char*)newArray + i * 8 + 6 - 2) = buildingLots[i].status;
                    i++;
                } while (i < maxBuildingLots);
            }

            int totalCount = maxBuildingLots * 2;
            if (i < totalCount) {
                do {
                    ((BuildingLot*)((char*)newArray + i * 8 + 6 - 6))->typeID = -1;
                    *((char*)newArray + i * 8 + 6 - 1) = 0;
                    *((char*)newArray + i * 8 + 6) = 0;
                    *((char*)newArray + i * 8 + 6 - 2) = param_4;
                    i++;
                } while (i < totalCount);
            }

            operator_delete(buildingLots);
            buildingLots = newArray;

            newArray[maxBuildingLots].typeID = param_1;
            buildingLots[maxBuildingLots].x = param_2;
            buildingLots[maxBuildingLots].y = param_3;
            buildingLots[maxBuildingLots].status = param_4;
            maxBuildingLots <<= 1;
        }
    }
}

// Padding: 2 bytes of unreachable NOP-equivalent
static void _end_pad(void) { while (1) {} }
