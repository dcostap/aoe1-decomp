class BaseObject {
public:
    void* vftable;
    char gap_04[0x18];
    int gameIDValue;
};

int operator!=(const BaseObject& lhs, const BaseObject& rhs) {
    return lhs.gameIDValue != rhs.gameIDValue;
}
