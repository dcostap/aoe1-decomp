// From taiinfmd.cpp

int __stdcall importantUnit(int type_id) {
    if (type_id != 0 && type_id != 3 && type_id != 4 && type_id != 0x18 &&
        type_id != 0x15 && type_id != 6 && type_id != 0x19 && type_id != 0x11 &&
        type_id != 0x1A && type_id != 0xC && type_id != 0x23 && type_id != 0x17 &&
        type_id != 0x24 && type_id != 0x1C && type_id != 0x12 && type_id != 0xD &&
        type_id != 2 && type_id != 0x14 && type_id != 0x1B && type_id != 0x16 &&
        type_id != 0x27) {
        return 0;
    }
    return 1;
}
