// 0040F3D0 AIPlay::isTargetType

int AIPlay::isTargetType(unsigned char type) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == type)
            return 1;
    }
    return 0;
}
