// VA: 004A54C0 fillPlayerColors (291B)
// scr_mps.cpp

class TribeMPSetupScreen {
public:
    char gap4[0x56C];
    int field_570;
    
    void fillPlayerColors();
};

void TribeMPSetupScreen::fillPlayerColors() {
    int* arr = (int*)field_570;
    if (arr) {
        int i = 8;
        while (i > 0) {
            arr[i - 1] = i;
            i--;
        }
    }
}
