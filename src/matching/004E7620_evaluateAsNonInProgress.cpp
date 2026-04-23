class TRIBE_Player;

class VictoryConditionRuleSystem {
public:
    int evaluateAsNonInProgress(TRIBE_Player* player, int rule);
};

int VictoryConditionRuleSystem::evaluateAsNonInProgress(TRIBE_Player* player, int rule) {
    switch (rule) {
        case 1:
        case 2:
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
            return -2;
        default:
            return 0;
    }
}
