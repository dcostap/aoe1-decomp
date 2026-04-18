class SomeClass {
public:
    int is_player_turn(int param);
    char pad[0xB0];
    int field_B0;
};
int SomeClass::is_player_turn(int param) {
    return this->field_B0 == param;
}
