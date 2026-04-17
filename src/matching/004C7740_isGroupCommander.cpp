class RGE_Static_Object {
public:
    char gap_00[0x04];
    int id;
    char gap_08[0x70];
    int groupCommanderValue;

    int isGroupCommander(void);
};

int RGE_Static_Object::isGroupCommander(void) {
    return id == groupCommanderValue;
}
