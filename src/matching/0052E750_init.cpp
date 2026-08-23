// VA: 0052E750 TRIBE_World::init(char*, TSound_Driver*, TCommunications_Handler*)
// BINARY NOTE: the direct call target is RGE_Game_World::init with the same
// three-argument surface.  The prior placeholder target_method changed only
// relocation identity.  The canonical base declaration now reports MATCH.

typedef unsigned char uchar;

class TSound_Driver;
class TCommunications_Handler;

class RGE_Game_World {
public:
    virtual uchar init(char* file, TSound_Driver* sound,
                       TCommunications_Handler* communications);
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual uchar init(char* file, TSound_Driver* sound,
                       TCommunications_Handler* communications);
};

uchar TRIBE_World::init(char* file, TSound_Driver* sound,
                        TCommunications_Handler* communications)
{
    return RGE_Game_World::init(file, sound, communications);
}
