struct InnerType2 {
    char gap_00[0x04];
    unsigned char field_04;
};
struct InnerType1 {
    char gap_00[0x08];
    InnerType2* field_08;
};
struct QueueHost {
    void enqueue(InnerType1* item, int arg);
};
class CommandBuildingHost {
public:
    unsigned char command_building_make_tech(int arg);
    char gap_00[0x3C];
    char* field_3C;
    char gap_40[0xF0];
    InnerType1* field_130;
};
unsigned char CommandBuildingHost::command_building_make_tech(int arg) {
    InnerType1* item = this->field_130;
    if (item && item->field_08->field_04 == 0x50) {
        ((QueueHost*)*(void**)(this->field_3C + 0x58))->enqueue(item, arg);
        return 1;
    }
    return 0;
}
