// 0040F460 AIPlay::addTargetCharacteristic

int AIPlay::addTargetCharacteristic(unsigned char characteristic) {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == 0 ||
            this->targetCharacteristicValue[i] == 5) {
            this->targetCharacteristicValue[i] = characteristic;
            return 1;
        }
    }
    return 0;
}
