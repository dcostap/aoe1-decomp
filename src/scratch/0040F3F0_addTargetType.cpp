// 0040F3F0 AIPlay::addTargetType

int AIPlay::addTargetType(unsigned char type) {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == 0 ||
            this->targetTypeValue[i] == 5) {
            this->targetTypeValue[i] = type;
            return 1;
        }
    }
    return 0;
}
