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

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A9E0
Path& Path::operator=(const Path& other) {
    int currentMax = this->maxSizeValue;
    int otherMax = other.maxSizeValue;
    if (otherMax > currentMax) {
        this->maxSizeValue = otherMax + currentMax;
        Waypoint* newPath = (Waypoint*)operator new((otherMax + currentMax) * sizeof(Waypoint));
        for (int i = 0; i < this->currentSizeValue; ++i) {
            newPath[i] = this->pathValue[i];
        }
        if (this->pathValue != nullptr) {
            operator delete(this->pathValue);
        }
        this->pathValue = newPath;
    }

    for (int i = 0; i < other.currentSizeValue; ++i) {
        this->pathValue[i] = other.pathValue[i];
    }
    this->currentWaypointValue = other.currentWaypointValue;
    this->currentSizeValue = other.currentSizeValue;
    return *this;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AB60
int Path::insertAtCurrent(const Waypoint& wp) {
    if (this->currentSizeValue > 1000) {
        return 0;
    }

    Waypoint* newPath = (Waypoint*)operator new((this->currentSizeValue + 1) * sizeof(Waypoint));
    newPath[0] = wp;
    for (int i = 0; i < this->currentSizeValue; ++i) {
        newPath[i + 1] = this->pathValue[i];
    }

    if (this->pathValue != nullptr) {
        operator delete(this->pathValue);
    }
    this->pathValue = newPath;
    this->currentSizeValue = this->currentSizeValue + 1;
    return 1;
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

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADA0
void Path::killPath() {
    this->currentSizeValue = 0;
    this->currentWaypointValue = 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADC0
int Path::numberOfWaypoints() const {
    return this->currentSizeValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADE0
void Path::setTimeStamp(ulong ts) {
    this->timeStampValue = ts;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AE70
Waypoint* Path::waypoint(int index) const {
    if (this->pathValue != nullptr && index >= 0 && index < this->currentSizeValue) {
        return this->pathValue + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AEA0
Waypoint* Path::currentWaypoint() const {
    if (this->pathValue != nullptr && this->currentWaypointValue >= 0 &&
        this->currentWaypointValue < this->currentSizeValue) {
        return this->pathValue + this->currentWaypointValue;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AEC0
int Path::currentWaypointNumber() const {
    return this->currentWaypointValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AED0
void Path::setCurrentWaypointNumber(int index) {
    this->currentWaypointValue = index;
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
