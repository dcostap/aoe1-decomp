// VA: 004F0BC0 TribeTacticalAIModule::clearArea (397 B)
// PDB source: taitacmd.cpp:3031-3093
// __thiscall, int clearArea(int, float, float, float, float)
//
// Attempt log:
// - Replaced the old raw helper scaffold with the period-typed object,
//   tactical-module, and passableTile surfaces. The binary selects the best
//   passable point around the four supplied area corners, then calls moveUnit.
// - Reordered the point and distance declarations to reproduce the original
//   stack homes; frame and call structure then aligned.
// - Reversed corner assignment order as a control-flow probe; it worsened the
//   switch and FPU layout, so it was restored.
// - Ordered switch arms by the original emitted block order. This produced an
//   exact match with the default VC5 flags.

#define VPAD(n) virtual void v##n();

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD(01) VPAD(02) VPAD(03) VPAD(04) VPAD(05) VPAD(06) VPAD(07) VPAD(08)
    VPAD(09) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15) VPAD(16)
    VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23) VPAD(24)
    VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31) VPAD(32)
    VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39) VPAD(40)
    VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47) VPAD(48)
    VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55) VPAD(56)
    VPAD(57) VPAD(58) VPAD(59) VPAD(60) VPAD(61) VPAD(62) VPAD(63) VPAD(64)
    VPAD(65) VPAD(66) VPAD(67) VPAD(68)
    virtual int passableTile(float x, float y, int flag);

    char gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;

    float distance_to_position(float x, float y, float z);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xec];
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xec];
    MainDecisionAIModule* md;

    int busyWithAction(int object_id, int action_id);
    int moveUnit(int object_id, float x, float y, int priority);
    int clearArea(int object_id, float x1, float y1, float x2, float y2);
};

int TribeTacticalAIModule::clearArea(int object_id, float x1, float y1,
                                     float x2, float y2)
{
    if (this->busyWithAction(object_id, -1) == 1) {
        RGE_Static_Object* object = this->md->object(object_id);
        if (object != 0) {
            float newX = -1.0f;
            float newY = -1.0f;
            float bestDistance = -1.0f;
            float tempX = -1.0f;
            float tempY = -1.0f;

            for (int i = 0; i < 8; i++) {
                switch (i) {
                case 0:
                    tempX = x1 - 2.0f;
                    tempY = y1 - 2.0f;
                    break;
                case 2:
                    tempX = x2 + 2.0f;
                    break;
                case 4:
                    tempY = y2 + 2.0f;
                    break;
                case 1:
                case 5:
                    tempX = (x2 + x1) * 0.5f;
                    break;
                case 6:
                    tempX = x1 - 2.0f;
                    break;
                case 3:
                case 7:
                    tempY = (y2 + y1) * 0.5f;
                    break;
                }

                if (object->passableTile(tempX, tempY, 1) != 0) {
                    float distance = object->distance_to_position(
                        tempX, tempY, object->world_z);
                    if (bestDistance == -1.0f || distance < bestDistance) {
                        bestDistance = distance;
                        newX = tempX;
                        newY = tempY;
                    }
                }
            }

            if (bestDistance != -1.0f) {
                this->moveUnit(object_id, newX, newY, 100);
                return 1;
            }
        }
    }
    return 0;
}
