// 0040F440 AIPlay::isTargetCharacteristic

int AIPlay::isTargetCharacteristic(unsigned char characteristic) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == characteristic)
            return 1;
    }
    return 0;
}
