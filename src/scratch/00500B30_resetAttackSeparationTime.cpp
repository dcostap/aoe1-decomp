// attempt 1: direct separation-time update with the debug-rand helper and the post-store clamp
// tried the natural remainder/sign-correction spellings and a few temp splits; size stayed 96 under /GX, so the remaining gap is still codegen-basin drift

int debug_rand(char* file, int line);

class TribeTacticalAIModule {
public:
    char gap_00[0x24C];
    int attack_separation_base;
    char gap_250[0x32C - 0x250];
    int attack_separation;
    char gap_330[0xD24 - 0x330];
    int randomizedAttackSeparationTime;

    void resetAttackSeparationTime();
};

void TribeTacticalAIModule::resetAttackSeparationTime() {
    char* file;
    int line;
    register int separation;
    register int random_value;
    int remainder;
    int signed_adjust;
    int value;

    file = (char*)"C:\\msdev\\work\\age1_x1\\taitacmd.cpp";
    line = 0x2D35;
    separation = this->attack_separation;
    if (separation > 0) {
        random_value = debug_rand(file, line);
        remainder = random_value % separation;
        signed_adjust = separation - remainder;
        value = remainder;
        value += this->attack_separation_base;
        value -= (signed_adjust >> 1);
        this->randomizedAttackSeparationTime = value;
    } else {
        this->randomizedAttackSeparationTime = this->attack_separation_base;
    }

    value = this->randomizedAttackSeparationTime;
    if (value < 0) {
        this->randomizedAttackSeparationTime = 0;
    }
}
