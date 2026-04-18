class SomeClass {
public:
    char* get_scenario_name(int index);
    char pad[0x108];
    char* field_108;
};
// Array element size = shl 6 + original = 65 * index, then * 8 + 8
// Actually: edx = index*64 + index = index*65, then lea [eax+edx*8+8] = field_108 + index*65*8 + 8 = field_108 + index*520 + 8
char* SomeClass::get_scenario_name(int index) {
    return this->field_108 + index * 520 + 8;
}
