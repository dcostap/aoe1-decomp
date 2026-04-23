class BaseItem {
public:
    char gap_00[0x8];
    int gameIDValue;
    char gap_0C[0x44];
    float xValue;
    float yValue;
    float zValue;

    friend int operator==(const BaseItem& lhs, const BaseItem& rhs);
};

int operator==(const BaseItem& lhs, const BaseItem& rhs) {
    if (lhs.gameIDValue == rhs.gameIDValue) {
        if (lhs.xValue == rhs.xValue) {
            if (lhs.yValue == rhs.yValue) {
                return 1;
            }
        }
    }
    return 0;
}
