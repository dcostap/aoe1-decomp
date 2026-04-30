// attempt 17: separate ifs instead of compound || condition

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object() {}
    virtual void v001(void) = 0;
    virtual void v002(void) = 0;
    virtual void v003(void) = 0;
    virtual void v004(void) = 0;
    virtual void v005(void) = 0;
    virtual void v006(void) = 0;
    virtual void v007(void) = 0;
    virtual void v008(void) = 0;
    virtual void v009(void) = 0;
    virtual void v010(void) = 0;
    virtual void v011(void) = 0;
    virtual void v012(void) = 0;
    virtual void v013(void) = 0;
    virtual void v014(void) = 0;
    virtual void v015(void) = 0;
    virtual void v016(void) = 0;
    virtual void v017(void) = 0;
    virtual void v018(void) = 0;
    virtual void v019(void) = 0;
    virtual void v020(void) = 0;
    virtual void v021(void) = 0;
    virtual void v022(void) = 0;
    virtual void v023(void) = 0;
    virtual void v024(void) = 0;
    virtual void v025(void) = 0;
    virtual void v026(void) = 0;
    virtual void v027(void) = 0;
    virtual void v028(void) = 0;
    virtual void v029(void) = 0;
    virtual void v030(void) = 0;
    virtual void v031(void) = 0;
    virtual void v032(void) = 0;
    virtual void v033(void) = 0;
    virtual void v034(void) = 0;
    virtual void v035(void) = 0;
    virtual void v036(void) = 0;
    virtual void v037(void) = 0;
    virtual void v038(void) = 0;
    virtual void v039(void) = 0;
    virtual void v040(void) = 0;
    virtual void v041(void) = 0;
    virtual void v042(void) = 0;
    virtual void v043(void) = 0;
    virtual void v044(void) = 0;
    virtual void v045(void) = 0;
    virtual void v046(void) = 0;
    virtual void v047(void) = 0;
    virtual void v048(void) = 0;
    virtual void v049(void) = 0;
    virtual void v050(void) = 0;
    virtual void v051(void) = 0;
    virtual void v052(void) = 0;
    virtual void v053(void) = 0;
    virtual void v054(void) = 0;
    virtual void v055(void) = 0;
    virtual void v056(void) = 0;
    virtual void v057(void) = 0;
    virtual void v058(void) = 0;
    virtual void v059(void) = 0;
    virtual void v060(void) = 0;
    virtual void v061(void) = 0;
    virtual void v062(void) = 0;
    virtual void v063(void) = 0;
    virtual void v064(void) = 0;
    virtual void v065(void) = 0;
    virtual void v066(void) = 0;
    virtual void v067(void) = 0;
    virtual void v068(void) = 0;
    virtual void v069(void) = 0;
    virtual void v070(void) = 0;
    virtual void v071(void) = 0;
    virtual void v072(void) = 0;
    virtual void v073(void) = 0;
    virtual void v074(void) = 0;
    virtual void v075(void) = 0;
    virtual void v076(void) = 0;
    virtual void v077(void) = 0;
    virtual void v078(void) = 0;
    virtual void v079(void) = 0;
    virtual void v080(void) = 0;
    virtual void v081(void) = 0;
    virtual void v082(void) = 0;
    virtual void v083(void) = 0;
    virtual void v084(void) = 0;
    virtual void v085(void) = 0;
    virtual void v086(void) = 0;
    virtual void v087(void) = 0;
    virtual void v088(void) = 0;
    virtual void v089(void) = 0;
    virtual void v090(void) = 0;
    virtual void v091(void) = 0;
    virtual void v092(void) = 0;
    virtual void v093(void) = 0;
    virtual void v094(void) = 0;
    virtual void v095(void) = 0;
    virtual void v096(void) = 0;
    virtual void v097(void) = 0;
    virtual void v098(void) = 0;
    virtual void v099(void) = 0;
    virtual void v100(void) = 0;
    virtual void v101(void) = 0;
    virtual void v102(void) = 0;
    virtual void v103(void) = 0;
    virtual void v104(void) = 0;
    virtual void v105(void) = 0;
    virtual void v106(void) = 0;
    virtual void v107(void) = 0;
    virtual void v108(void) = 0;
    virtual void v109(void) = 0;
    virtual void v110(void) = 0;
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2);

    char gap_04[0x84];
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int obj_id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;

    void processAddWaypointCommand(int object_id, char* waypoints, int count);
};

void RGE_Player::processAddWaypointCommand(int object_id, char* waypoints, int count) {
    RGE_Static_Object* object = this->world->object(object_id);
    if (object == 0) return;
    if (count <= 0) return;
    do {
        object->addUserDefinedWaypoint((XYZBYTEPoint*)waypoints, 1);
        waypoints += 3;
        count--;
    } while (count != 0);
}
