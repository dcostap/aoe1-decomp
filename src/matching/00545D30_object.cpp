class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x88];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

RGE_Static_Object* RGE_Game_World::object(int index) {
    int neg_index;
    if (index < 0) {
        neg_index = -index;
        if (neg_index < this->maxNumberNegativeObjectsValue) {
            return this->negativeObjectsValue[neg_index];
        }
    }
    if (index > -1 && index < this->maxNumberObjectsValue) {
        return this->objectsValue[index];
    }
    return 0;
}
