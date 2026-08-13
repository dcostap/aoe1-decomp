// 004E2490 TribeInformationAIModule::addResourceObject
// Attempt log:
// baseline: rough typed reconstruction omitted the ftol calls and most resource bookkeeping.
// Current reconstruction uses the proven ResourceMemory ownership, array growth, and closest-dropsite fields.
// probe: removing a max-size local matched the 0xC frame and 90% instruction shape.
// probe: a natural while scan placed the duplicate-update block after insertion.
// probes: cursor and source-offset copy variants improved metrics but were not plausible living source.
// probe: moved the proven dropDistance cast from duplicate refresh to new-record initialization; original calls ftol for the new record and not the duplicate refresh.
// left in scratch: 17-call sequence and 0xC frame now match; the growth-copy preamble and remaining CFG/codegen drift remain unresolved.

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

struct RGE_Master_Static_Object {
    void* vtable;
    char gap04[0x10];
    short object_group;
};

struct RGE_Static_Object {
    void* vtable;
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap0c[0x2c];
    float world_x;
    float world_y;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char gap07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

extern float DAT_005755b8;
extern float DAT_005755bc;

struct TribeInformationAIModule {
    char gap000[0x100];
    void* md;
    char gap104[0x3cc];
    ResourceMemory* resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[16];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];

    float findClosestDropsite(RGE_Static_Object* obj, int mode, int* dropsiteID);
    int addResourceObject(RGE_Static_Object* obj);
};

int TribeInformationAIModule::addResourceObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int resourceType;

    if (group == 0x0f) {
        resourceType = 1;
    } else if (group == 8) {
        resourceType = 2;
    } else {
        resourceType = (group != 0x20) - 1 & 3;
    }

    if (this->numResources[resourceType] == this->maxResources[resourceType] ||
        this->resources[resourceType] == 0) {
        int newSize;
        if (this->maxResources[resourceType] == 0) {
            newSize = 100;
        } else {
            newSize = this->maxResources[resourceType] * 2;
        }

        ResourceMemory* temp = (ResourceMemory*)operator new(newSize * sizeof(ResourceMemory));
        if (temp == 0) {
            return 0;
        }

        int i = 0;
        if (this->resources[resourceType] != 0) {
            do {
                if (i >= this->maxResources[resourceType]) {
                    break;
                }
                temp[i].id = this->resources[resourceType][i].id;
                temp[i].x = this->resources[resourceType][i].x;
                temp[i].y = this->resources[resourceType][i].y;
                temp[i].gatherAttempts = this->resources[resourceType][i].gatherAttempts;
                temp[i].gatherValue = this->resources[resourceType][i].gatherValue;
                temp[i].valid = this->resources[resourceType][i].valid;
                temp[i].gone = this->resources[resourceType][i].gone;
                temp[i].dropDistance = this->resources[resourceType][i].dropDistance;
                temp[i].resourceType = this->resources[resourceType][i].resourceType;
                temp[i].dropsiteID = this->resources[resourceType][i].dropsiteID;
                i++;
            } while (this->resources[resourceType] != 0);
        }

        if (i < newSize) {
            int count = newSize - i;
            do {
                temp[i].id = -1;
                temp[i].x = 0;
                temp[i].y = 0;
                temp[i].gatherAttempts = 0;
                temp[i].gatherValue = 0xff;
                temp[i].valid = 0;
                temp[i].gone = 0;
                temp[i].dropDistance = 0xff;
                temp[i].resourceType = 0xff;
                temp[i].dropsiteID = -1;
                i++;
                count--;
            } while (count != 0);
        }

        if (this->resources[resourceType] != 0) {
            operator delete(this->resources[resourceType]);
        }
        this->resources[resourceType] = temp;
        this->maxResources[resourceType] = newSize;
    }

    int i = 0;
    while (i < this->maxResources[resourceType]) {
        if (this->resources[resourceType][i].id == obj->id) {
                int dropsiteID = -1;
                float distance = this->findClosestDropsite(obj, 1, &dropsiteID);
                this->resources[resourceType][i].gatherValue =
                    (int)(DAT_005755bc - distance * DAT_005755b8);
                this->resources[resourceType][i].dropsiteID = dropsiteID;

                group = obj->master_obj->object_group;
                if (group == 0x0f) {
                    int value = (int)distance;
                    if (this->closestDropsiteValue[1] <= value &&
                        this->closestDropsiteValue[1] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[1] = value;
                    this->closestDropsiteResourceID[1] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (group == 0x20) {
                    int value = (int)distance;
                    if (this->closestDropsiteValue[3] <= value &&
                        this->closestDropsiteValue[3] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[3] = value;
                    this->closestDropsiteResourceID[3] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (group == 8) {
                    int value = (int)distance;
                    if (this->closestDropsiteValue[2] <= value &&
                        this->closestDropsiteValue[2] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[2] = value;
                    this->closestDropsiteResourceID[2] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (group == 7) {
                    int value = (int)distance;
                    if (this->closestDropsiteValue[0] <= value &&
                        this->closestDropsiteValue[0] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[0] = value;
                    this->closestDropsiteResourceID[0] = this->resources[resourceType][i].id;
                    return 1;
                }
                return 1;
            }
        i++;
    }

    this->resources[resourceType][this->numResources[resourceType]].id = obj->id;
    this->resources[resourceType][this->numResources[resourceType]].x =
        (unsigned char)(int)obj->world_x;
    this->resources[resourceType][this->numResources[resourceType]].y =
        (unsigned char)(int)obj->world_y;
    this->resources[resourceType][this->numResources[resourceType]].gatherAttempts = 0;
    this->resources[resourceType][this->numResources[resourceType]].valid = 0;
    this->resources[resourceType][this->numResources[resourceType]].gone = 0;
    this->resources[resourceType][this->numResources[resourceType]].resourceType =
        (unsigned char)resourceType;

    int dropsiteID = -1;
    float distance = this->findClosestDropsite(obj, 1, &dropsiteID);
    this->resources[resourceType][this->numResources[resourceType]].dropDistance =
        (unsigned char)(int)distance;
    this->resources[resourceType][this->numResources[resourceType]].gatherValue =
        (int)(DAT_005755bc - distance * DAT_005755b8);
    this->resources[resourceType][this->numResources[resourceType]].dropsiteID = dropsiteID;
    this->numResources[resourceType]++;

    group = obj->master_obj->object_group;
    if (group == 0x0f) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[1] ||
            this->closestDropsiteValue[1] == -1) {
            this->closestDropsiteValue[1] = value;
            this->closestDropsiteResourceID[1] = obj->id;
            return 1;
        }
    } else if (group == 0x20) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[3] ||
            this->closestDropsiteValue[3] == -1) {
            this->closestDropsiteValue[3] = value;
            this->closestDropsiteResourceID[3] = obj->id;
            return 1;
        }
    } else if (group == 8) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[2] ||
            this->closestDropsiteValue[2] == -1) {
            this->closestDropsiteValue[2] = value;
            this->closestDropsiteResourceID[2] = obj->id;
            return 1;
        }
    } else if (group == 7) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[0] ||
            this->closestDropsiteValue[0] == -1) {
            this->closestDropsiteValue[0] = value;
            this->closestDropsiteResourceID[0] = obj->id;
            return 1;
        }
    }
    return 1;
}
