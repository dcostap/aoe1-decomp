class RGE_Base_Game {
public:
    char gap_0[0x97F];
    char field_97F;
    char field_980;
    char field_981;
    void setMapSize(char a, char b, char c);
};

void RGE_Base_Game::setMapSize(char a, char b, char c) {
    this->field_97F = a;
    this->field_980 = b;
    this->field_981 = c;
}
