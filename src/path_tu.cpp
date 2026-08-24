// Authentic owner wrapper for the PDB source module
// C:\\msdev\\work\\age1_x1\\Path.cpp.
//
// The include order follows the Path.cpp line and address bands.  The source
// owners keep standalone declarations for normal per-function checks; the
// PATH_TU_CONTEXT guard selects the complete module declaration surface here.
// The module uses the reviewed operator+ /GX flag context.

#define PATH_TU_CONTEXT 1
#include "../include/path_context.h"

#include "matching/0046A740_Path.cpp"
#include "matching/0046A7F0_Path.cpp"
#include "scratch/0046A810_operator.cpp"
#include "matching/0046A8E0_operator.cpp"
#include "scratch/0046A9E0_operator.cpp"
#include "accepted_drift/0046AAE0_operator.cpp"
#include "matching/0046AB60_insertAtCurrent.cpp"
#include "matching/0046AC10_insertAtEnd.cpp"
#include "matching/0046ACE0_contains.cpp"
#include "matching/0046ADA0_killPath.cpp"
#include "matching/0046ADB0_maxNumberOfWaypoints.cpp"
#include "matching/0046ADC0_numberOfWaypoints.cpp"
#include "matching/0046ADD0_timeStamp.cpp"
#include "matching/0046ADE0_setTimeStamp.cpp"
#include "matching/0046ADF0_length.cpp"
#include "matching/0046AE50_start.cpp"
#include "matching/0046AE60_goal.cpp"
#include "matching/0046AE70_waypoint.cpp"
#include "matching/0046AEA0_currentWaypoint.cpp"
#include "matching/0046AEC0_currentWaypointNumber.cpp"
#include "matching/0046AED0_setCurrentWaypointNumber.cpp"
#include "matching/0046AEE0_nextWaypoint.cpp"
#include "matching/0046AF10_previousWaypoint.cpp"
#include "matching/0046AF40_firstWaypoint.cpp"
#include "matching/0046AF60_lastWaypoint.cpp"
#include "matching/0046AF80_initToStart.cpp"
#include "matching/0046AF90_initToEnd.cpp"
#include "matching/0046AFA0_moveToNextWaypoint.cpp"
#include "matching/0046AFC0_moveToLastWaypoint.cpp"
#include "matching/0046AFE0_distanceToNextWaypoint.cpp"

#undef PATH_TU_CONTEXT
