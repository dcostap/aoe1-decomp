// VA: 004E4790 TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int, int)
// PDB source: taiinfmd.cpp lines 8565-8574
// Default flags. No inline asm/hacks.
//
// attempt log:
// - Earlier natural denominator split as `(mapX / 4) * mapY; denom = (denom + sign) >> 2` matched the prologue
//   but VC5 delayed the multiply/sign-adjust until after the y-quadrant division (88/105 equal, first mismatch 46).
// - Tried separate denom lines, local mapX/mapY temps, virtual class surface, parameter mutation, `/O1`, typed quadrantLog,
//   expression-form decompiler source, ternary/dependency tricks, and manual pointer access; most stayed in the same
//   scheduling basin or worsened register allocation.
// - Match breakthrough: keep the original left-associative source as one arithmetic expression,
//   `mapX / 4 * mapY / 4`. VC5 then emits the first signed `/4`, multiply by mapY, sign-adjust for the second `/4`,
//   and only then begins the y-quadrant division, exactly matching the original schedule.
// Result: MATCH locally with `python tools/check_function.py --va 004E4790`.

class QuadrantLog {
public:
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

class TribeInformationAIModule {
public:
    char gap_00[0x104];
    int mapX;
    int mapY;
    char gap_10c[0x2fc];
    QuadrantLog quadrantLog[4][4];

    int percentTilesExploredInPositionQuadrant(int param_1, int param_2);
};

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int param_1, int param_2) {
    if (mapX == -1) {
        return 0;
    }

    int qx = param_1 * 4 / mapX;
    int numTilesInQuadrant = mapX / 4 * mapY / 4;
    int qy = param_2 * 4 / mapY;

    return quadrantLog[qx][qy].numberExploredTiles * 100 / numTilesInQuadrant;
}
