// attempt 1: direct switch returning the observed string literal addresses
// goal: keep the simple jump-table basin and the default 0x586F18 path intact

class TribeSelectTribeScreen {
public:
    char* tribeName(int param_1);
};

char* TribeSelectTribeScreen::tribeName(int param_1) {
    switch (param_1) {
    case 0: return (char*)0x586F78;
    case 1: return (char*)0x586F6C;
    case 2: return (char*)0x586F60;
    case 3: return (char*)0x586F58;
    case 4: return (char*)0x586F50;
    case 5: return (char*)0x586F44;
    case 6: return (char*)0x586F3C;
    case 7: return (char*)0x586F30;
    case 8: return (char*)0x586F24;
    default: return (char*)0x586F18;
    }
}
