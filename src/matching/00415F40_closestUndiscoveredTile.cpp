struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Visible_Map;

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float los;
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual unsigned char vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual float vf34(float param_1, float param_2, float param_3);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual float vf74(int param_1, void* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual void vf78(long param_1);
    virtual unsigned char vf7C(void);
    virtual void vf80(short param_1, float param_2);
    virtual void vf84(float param_1, unsigned char param_2, unsigned char param_3);
    virtual int vf88(int param_1, int param_2);
    virtual unsigned char vf8C(float param_1);
    virtual int vf90(void);
    virtual void vf94(long param_1, unsigned char param_2);
    virtual void vf98(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void vf9C(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void vfA0(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void vfA4(void);
    virtual void vfA8(RGE_Static_Object* param_1);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(float param_1);
    virtual RGE_Static_Object* vfB8(void);
    virtual RGE_Master_Static_Object* vfBC(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void vfC0(void* param_1, short param_2, unsigned char param_3);
    virtual void vfC4(RGE_Static_Object* param_1);
    virtual unsigned char vfC8(void);
    virtual RGE_Static_Object* vfCC(void);
    virtual void vfD0(RGE_Static_Object* param_1);
    virtual void vfD4(void);
    virtual int vfD8(RGE_Player* param_1, unsigned char param_2, int param_3);
    virtual void vfDC(RGE_Player* param_1, unsigned char param_2, int param_3);
    virtual void* vfE0(void);
    virtual int vfE4(RGE_Static_Object* param_1);
    virtual unsigned char vfE8(void);
    virtual void vfEC(unsigned char param_1);
    virtual float vfF0(RGE_Static_Object* param_1);
    virtual float vfF4(void);
    virtual float vfF8(void);
    virtual float vfFC(void);
    virtual float vf100(void);
    virtual float vf104(RGE_Static_Object* param_1);
    virtual float vf108(void);
    virtual float vf10C(void);
    virtual float vf110(void);
    virtual int passableTile(float param_1, float param_2, int param_3);
    virtual unsigned char vf118(void);
    virtual int vf11C(void);
    virtual float vf120(void);
    virtual float vf124(void);
    virtual float vf128(void);
    virtual void vf12C(unsigned char param_1);
    virtual unsigned char vf130(void);
    virtual unsigned char vf134(void);
    virtual unsigned char vf138(int param_1);
    virtual unsigned char vf13C(int param_1);
    virtual unsigned char vf140(void);
    virtual void vf144(const char* param_1, ...);
    virtual void vf148(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int vf14C(float param_1, float param_2, float param_3, int param_4);
    virtual int vf150(int param_1, int param_2);
    virtual int vf154(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual int vf158(int param_1, float param_2, int param_3);
    virtual int vf15C(int param_1, int param_2);
    virtual int vf160(int param_1, int param_2);
    virtual int vf164(int param_1, int param_2);
    virtual int vf168(int param_1, int param_2);
    virtual int vf16C(int param_1, int param_2);
    virtual int vf170(int param_1, int param_2);
    virtual int vf174(int param_1, int param_2);
    virtual int vf178(int param_1, int param_2);
    virtual int vf17C(int param_1, int param_2, int param_3);
    virtual int vf180(int param_1, int param_2);
    virtual int vf184(int param_1, float param_2, float param_3, float param_4);
    virtual int vf188(float param_1, float param_2, float param_3, int param_4);
    virtual int vf18C(void);
    virtual int vf190(void);
    virtual int vf194(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6);
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    unsigned char lookupZone(int param_1, int param_2);
    unsigned char currentZone(void);
};

class UnitAIModule {
public:
    void* vtable_ptr;
    RGE_Static_Object* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    void* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    void* notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;

    unsigned char visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
    int inWaypointQueue(int param_1, int param_2) const;
    int closestUndiscoveredTile(int* param_1, int* param_2, int param_3);
};

extern int __cdecl debug_rand(char* param_1, int param_2);

int UnitAIModule::closestUndiscoveredTile(int* param_1, int* param_2, int param_3) {
    RGE_Static_Object* object;
    RGE_Visible_Map* visible;
    RGE_Map* map;
    unsigned char currentZone;
    int bestDistance;
    int currX;
    int currY;
    int searchRadius;
    int lowX;
    int highX;
    int highY;
    int lowY;
    int x;
    int y;
    int distance;

    if (this->currentOrderValue == 0x2C1) {
        if (this->currentTargetXValue != -1.0f) {
            if (this->currentTargetYValue != -1.0f) {
                return 0;
            }
        }
    }

    object = this->objectValue;
    bestDistance = -1;
    currX = (int)object->world_x;
    currY = (int)object->world_y;
    searchRadius = (int)object->master_obj->los + 3;
    lowX = (int)(object->world_x - (float)searchRadius);
    highX = (int)(object->world_x + (float)searchRadius);
    lowY = (int)(object->world_y - (float)searchRadius);
    highY = (int)(object->world_y + (float)searchRadius);
    map = object->owner->world->map;
    visible = object->owner->visible;

    if (lowX < 0) {
        lowX = 0;
    }
    if (highX > map->map_width - 1) {
        highX = map->map_width - 1;
    }
    if (lowY < 0) {
        lowY = 0;
    }
    if (highY > map->map_height - 1) {
        highY = map->map_height - 1;
    }

    const int randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xB2E) % 3;
    currentZone = this->objectValue->currentZone();

    for (y = lowY; y <= highY; ++y) {
        for (x = lowX; x <= highX; ++x) {
            if (this->visibleStatus(visible, x, y) == 0) {
                if (currentZone == this->objectValue->lookupZone(x, y)) {
                    if (this->objectValue->passableTile((float)x, (float)y, 0) != 0) {
                        if ((param_3 == 0) || (this->inWaypointQueue(x, y) == 0)) {
                            distance = (x - currX) * (x - currX) + (y - currY) * (y - currY);
                            if (this->currentTargetXValue != -1.0f) {
                                distance =
                                    (x - (int)this->currentTargetXValue) * (x - (int)this->currentTargetXValue) +
                                    distance +
                                    (y - (int)this->currentTargetYValue) * (y - (int)this->currentTargetYValue);
                            }
                            if ((bestDistance == -1) || (bestDistance + randSelect > distance)) {
                                bestDistance = distance;
                                *param_1 = x;
                                *param_2 = y;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bestDistance != -1) {
        XYZPoint point;

        object = this->objectValue;
        point.x = *param_1;
        point.y = *param_2;
        point.z = (int)object->world_z;
        return object->canPath(point, object->master_obj->los - 1.0f, -1, (float*)&param_1, 0, -1, -1);
    }

    return 0;
}
