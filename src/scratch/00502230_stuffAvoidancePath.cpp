// 00502230 TribeTacticalAIModule::stuffAvoidancePath
// PDB: taitacmd.cpp:12551-12604, 224 bytes
// void __thiscall stuffAvoidancePath(TacticalAIGroup* param_1, Path* param_2)
// ret 8 (2 params)
// FLAGS: default

class Waypoint {
public:
    int x;      // +0x00
    int y;      // +0x04
};

class Path {
public:
    float length();
    void initToStart();
    float distanceToNextWaypoint();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class TacticalAIGroup {
public:
    void addAttackWaypoint(int x, int y);
};

class TribeTacticalAIModule {
public:
    void stuffAvoidancePath(TacticalAIGroup* group, Path* path);
};

void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup* group, Path* path)
{
    float divisionLength = path->length() * 0.2f;
    if (divisionLength < 10.0f)
        divisionLength = 10.0f;

    path->initToStart();
    float accumDist = path->distanceToNextWaypoint();
    path->moveToNextWaypoint();

    int tooFew = 0;
    if (path->numberOfWaypoints() <= 5)
        tooFew = 1;

    int i = 1;
    int count = path->numberOfWaypoints() - 1;
    if (i < count) {
        do {
            if (tooFew) {
                if (accumDist < 5.0f)
                    goto skip;
            } else {
                if (accumDist < divisionLength)
                    goto skip;
            }

            {
                Waypoint* wp = path->currentWaypoint();
                group->addAttackWaypoint(wp->x, wp->y);
            }

skip:
            accumDist += path->distanceToNextWaypoint();
            path->moveToNextWaypoint();
            i++;
            count = path->numberOfWaypoints() - 1;
        } while (i < count);
    }
}
