// 0040F2E0 AIPlay::AIPlay
//
// The scalar defaults precede the inline group and phase arrays in the
// original constructor. The canonical class keeps the proven flat layout.

AIPlay::AIPlay()
    : minimumNumberUnitsValue(1),
      maximumNumberUnitsValue(0xFF),
      typeValue(1),
      powerValue(0),
      overflowValue(1),
      intelligenceValue(0x32),
      deathPercentageValue(0x32) {
    for (int j = 0; j < 5; j++) {
        this->targetTypeValue[j] = 5;
        this->targetCharacteristicValue[j] = 5;
    }
}
