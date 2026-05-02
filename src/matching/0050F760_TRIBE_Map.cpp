// VA: 0050F760 TRIBE_Map::TRIBE_Map (57 B)
// PDB source: tmap.cpp lines 127-131

class RGE_Sound;

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Map(char* param1, char* param2, char* param3, short param4, short param5, short param6, RGE_Sound** param7);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual ~TRIBE_Map();
    TRIBE_Map(char* param1, char* param2, char* param3, char* param4, short param5, short param6, short param7, RGE_Sound** param8);
};

TRIBE_Map::TRIBE_Map(char* param1, char* param2, char* param3, char* param4, short param5, short param6, short param7, RGE_Sound** param8)
    : RGE_Map(param1, param3, param4, param5, param6, param7, param8)
{
}
