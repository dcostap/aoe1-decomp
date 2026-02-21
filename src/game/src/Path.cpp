#include "../include/Path.h"
#include <string.h>

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A740
Path::Path() {
    this->timeStampValue = 0;
    this->pathValue = nullptr;
    this->maxSizeValue = 0;
    this->currentSizeValue = 0;
    this->currentWaypointValue = 0;
    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->goalValue.x = 0.0f;
    this->goalValue.y = 0.0f;
    this->goalValue.z = 0.0f;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A740
Path::Path(int capacity) {
    this->timeStampValue = 0;
    this->pathValue = nullptr;
    this->maxSizeValue = 0;
    this->currentSizeValue = 0;
    this->currentWaypointValue = 0;
    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->goalValue.x = 0.0f;
    this->goalValue.y = 0.0f;
    this->goalValue.z = 0.0f;

    if (capacity == 0 || capacity > 0) {
        this->maxSizeValue = capacity;
        Waypoint* newPath = (Waypoint*)operator new(capacity * sizeof(Waypoint));
        // Copy existing waypoints (none in fresh construction, but matches decomp pattern)
        int i = 0;
        if (0 < this->currentSizeValue) {
            for (i = 0; i < this->currentSizeValue; i++) {
                newPath[i].x = this->pathValue[i].x;
                newPath[i].y = this->pathValue[i].y;
                newPath[i].z = this->pathValue[i].z;
                newPath[i].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
            }
        }
        if (this->pathValue != nullptr) {
            operator delete(this->pathValue);
        }
        this->pathValue = newPath;
    }
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A7F0
Path::~Path() {
    if (this->pathValue != nullptr) {
        operator delete(this->pathValue);
    }
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AC40
int Path::insertAtEnd(Waypoint wp) {
    if (this->currentSizeValue == this->maxSizeValue) {
        // Double the capacity
        this->maxSizeValue = this->maxSizeValue * 2;
        Waypoint* newPath = (Waypoint*)operator new(this->maxSizeValue * sizeof(Waypoint));
        for (int i = 0; i < this->currentSizeValue; i++) {
            newPath[i].x = this->pathValue[i].x;
            newPath[i].y = this->pathValue[i].y;
            newPath[i].z = this->pathValue[i].z;
            newPath[i].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
        }
        if (this->pathValue != nullptr) {
            operator delete(this->pathValue);
        }
        this->pathValue = newPath;
    }
    this->pathValue[this->currentSizeValue].x = wp.x;
    this->pathValue[this->currentSizeValue].y = wp.y;
    this->pathValue[this->currentSizeValue].z = wp.z;
    this->pathValue[this->currentSizeValue].facetToNextWaypoint = wp.facetToNextWaypoint;
    this->currentSizeValue = this->currentSizeValue + 1;
    return 1;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF80
void Path::initToStart() {
    this->currentWaypointValue = 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AFA0
int Path::moveToNextWaypoint() {
    int lastIdx = this->currentSizeValue - 1;
    if (this->currentWaypointValue < lastIdx) {
        this->currentWaypointValue = this->currentWaypointValue + 1;
        return 1;
    }
    this->currentWaypointValue = lastIdx;
    return 0;
}
