// 0040F360 AIPlay::setName

void AIPlay::setName(char* name) {
    if (name) {
        strncpy(this->nameValue, name, 64);
    }
}
