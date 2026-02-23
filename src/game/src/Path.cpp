#include "../include/Path.h"
#include <math.h>
#include <ostream>
#include <string.h>

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
        Waypoint* newPath = (Waypoint*)::operator new((size_t)capacity * sizeof(Waypoint));

        if (0 < this->currentSizeValue) {
            for (int i = 0; i < this->currentSizeValue; ++i) {
                newPath[i].x = this->pathValue[i].x;
                newPath[i].y = this->pathValue[i].y;
                newPath[i].z = this->pathValue[i].z;
                newPath[i].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
            }
        }

        if (this->pathValue != nullptr) {
            ::operator delete(this->pathValue);
        }
        this->pathValue = newPath;
    }
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A7F0
Path::~Path() {
    if (this->pathValue != nullptr) {
        ::operator delete(this->pathValue);
    }
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A8E0
Path Path::operator+(const Path& other) const {
    Path newPath(this->maxSizeValue + other.maxSizeValue);

    if (0 < this->currentSizeValue) {
        for (int i = 0; i < this->currentSizeValue; ++i) {
            newPath.insertAtEnd(this->pathValue[i]);
        }
    }

    if (0 < other.currentSizeValue) {
        for (int i = 0; i < other.currentSizeValue; ++i) {
            newPath.insertAtEnd(other.pathValue[i]);
        }
    }

    return newPath;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046A9E0
Path& Path::operator=(const Path& other) {
    int thisMax = this->maxSizeValue;
    int otherMax = other.maxSizeValue;

    if (thisMax < otherMax) {
        int add = otherMax;
        if (otherMax == 0) {
            add = thisMax;
        }

        this->maxSizeValue = thisMax + add;
        Waypoint* newPath = (Waypoint*)::operator new((size_t)this->maxSizeValue * sizeof(Waypoint));

        if (0 < this->currentSizeValue) {
            for (int i = 0; i < this->currentSizeValue; ++i) {
                newPath[i].x = this->pathValue[i].x;
                newPath[i].y = this->pathValue[i].y;
                newPath[i].z = this->pathValue[i].z;
                newPath[i].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
            }
        }

        if (this->pathValue != nullptr) {
            ::operator delete(this->pathValue);
        }
        this->pathValue = newPath;
    }

    if (0 < other.currentSizeValue) {
        for (int i = 0; i < other.currentSizeValue; ++i) {
            this->pathValue[i].x = other.pathValue[i].x;
            this->pathValue[i].y = other.pathValue[i].y;
            this->pathValue[i].z = other.pathValue[i].z;
            this->pathValue[i].facetToNextWaypoint = other.pathValue[i].facetToNextWaypoint;
        }
    }

    this->currentWaypointValue = other.currentWaypointValue;
    this->currentSizeValue = other.currentSizeValue;
    return *this;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AAE0
int Path::operator==(const Path& other) const {
    if (this->currentSizeValue < 1) {
        return 1;
    }

    for (int i = 0; i < this->currentSizeValue; ++i) {
        if (this->pathValue[i].x != other.pathValue[i].x || this->pathValue[i].y != other.pathValue[i].y) {
            return 0;
        }
        if (this->pathValue[i].z != other.pathValue[i].z) {
            return 0;
        }
        if (this->pathValue[i].facetToNextWaypoint != other.pathValue[i].facetToNextWaypoint) {
            return 0;
        }
    }

    return 1;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AB60
int Path::insertAtCurrent(const Waypoint& wp) {
    if (1000 < this->currentSizeValue) {
        return 0;
    }

    Waypoint* newPath = (Waypoint*)::operator new((size_t)(this->currentSizeValue + 1) * sizeof(Waypoint));
    newPath[0].x = wp.x;
    newPath[0].y = wp.y;
    newPath[0].z = wp.z;
    newPath[0].facetToNextWaypoint = wp.facetToNextWaypoint;

    if (0 < this->currentSizeValue) {
        for (int i = 0; i < this->currentSizeValue; ++i) {
            newPath[i + 1].x = this->pathValue[i].x;
            newPath[i + 1].y = this->pathValue[i].y;
            newPath[i + 1].z = this->pathValue[i].z;
            newPath[i + 1].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
        }
    }

    if (this->pathValue != nullptr) {
        ::operator delete(this->pathValue);
    }
    this->pathValue = newPath;
    this->currentSizeValue = this->currentSizeValue + 1;
    return 1;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AC10
int Path::insertAtEnd(Waypoint wp) {
    int maxSize = this->maxSizeValue;
    if (this->currentSizeValue == maxSize) {
        this->maxSizeValue = maxSize * 2;
        Waypoint* newPath = (Waypoint*)::operator new((size_t)(maxSize * 2) * sizeof(Waypoint));

        if (0 < this->currentSizeValue) {
            for (int i = 0; i < this->currentSizeValue; ++i) {
                newPath[i].x = this->pathValue[i].x;
                newPath[i].y = this->pathValue[i].y;
                newPath[i].z = this->pathValue[i].z;
                newPath[i].facetToNextWaypoint = this->pathValue[i].facetToNextWaypoint;
            }
        }

        if (this->pathValue != nullptr) {
            ::operator delete(this->pathValue);
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

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ACE0
int Path::contains(const Waypoint& wp) const {
    if (this->currentSizeValue < 1) {
        return 0;
    }

    for (int i = 0; i < this->currentSizeValue; ++i) {
        if (floor((double)this->pathValue[i].x) == floor((double)wp.x)) {
            if (floor((double)this->pathValue[i].y) == floor((double)wp.y)) {
                return 1;
            }
        }
    }

    return 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADA0
void Path::killPath() {
    this->currentSizeValue = 0;
    this->currentWaypointValue = 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADB0
int Path::maxNumberOfWaypoints() const {
    return this->maxSizeValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADC0
int Path::numberOfWaypoints() const {
    return this->currentSizeValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADD0
ulong Path::timeStamp() const {
    return this->timeStampValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADE0
void Path::setTimeStamp(ulong ts) {
    this->timeStampValue = ts;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046ADF0
float Path::length() const {
    float fVar1 = 0.0f;
    if (1 < this->currentSizeValue) {
        int remaining = this->currentSizeValue - 1;
        Waypoint* p = this->pathValue;
        do {
            const float dx = p[1].x - p[0].x;
            const float dy = p[1].y - p[0].y;
            const float dz = p[1].z - p[0].z;
            remaining = remaining - 1;
            fVar1 = sqrtf((dy * dy) + (dx * dx) + (dz * dz)) + fVar1;
            p = p + 1;
        } while (remaining != 0);
    }
    return fVar1;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AE50
const Waypoint& Path::start() const {
    return this->startValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AE60
const Waypoint& Path::goal() const {
    return this->goalValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AE70
const Waypoint* Path::waypoint(int idx) const {
    if (this->pathValue != nullptr && -1 < idx && idx < this->currentSizeValue) {
        return this->pathValue + idx;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AEA0
Waypoint* Path::currentWaypoint() const {
    int idx = this->currentWaypointValue;
    if (this->pathValue != nullptr && -1 < idx && idx < this->currentSizeValue) {
        return this->pathValue + idx;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AEC0
int Path::currentWaypointNumber() const {
    return this->currentWaypointValue;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AED0
void Path::setCurrentWaypointNumber(int idx) {
    this->currentWaypointValue = idx;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AEE0
const Waypoint* Path::nextWaypoint() const {
    int next = this->currentWaypointValue + 1;
    if (this->pathValue != nullptr && -1 < this->currentWaypointValue && next < this->currentSizeValue) {
        return this->pathValue + next;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF10
const Waypoint* Path::previousWaypoint() const {
    int idx = this->currentWaypointValue;
    if (this->pathValue != nullptr && idx != -1 && -1 < idx + 1 && idx < this->currentSizeValue) {
        return this->pathValue + idx - 1;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF40
const Waypoint* Path::firstWaypoint() const {
    Waypoint* p = this->pathValue;
    if (p == nullptr || this->currentSizeValue < 1) {
        p = nullptr;
    }
    return p;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF60
const Waypoint* Path::lastWaypoint() const {
    if (this->pathValue != nullptr && 0 < this->currentSizeValue) {
        return this->pathValue + this->currentSizeValue - 1;
    }
    return nullptr;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF80
void Path::initToStart() {
    this->currentWaypointValue = 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AF90
void Path::initToEnd() {
    this->currentWaypointValue = this->currentSizeValue - 1;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AFA0
int Path::moveToNextWaypoint() {
    int last = this->currentSizeValue - 1;
    if (this->currentWaypointValue < last) {
        this->currentWaypointValue = this->currentWaypointValue + 1;
        return 1;
    }
    this->currentWaypointValue = last;
    return 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AFC0
int Path::moveToLastWaypoint() {
    if (0 < this->currentWaypointValue) {
        this->currentWaypointValue = this->currentWaypointValue - 1;
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: path.cpp.decomp @ 0x0046AFE0
float Path::distanceToNextWaypoint() const {
    float dist = 0.0f;
    if (this->pathValue != nullptr && -1 < this->currentWaypointValue &&
        this->currentWaypointValue < (this->currentSizeValue - 1)) {
        Waypoint* cur = this->pathValue + this->currentWaypointValue;
        const float dx = this->pathValue[this->currentWaypointValue + 1].x - cur->x;
        const float dy = cur[1].y - cur->y;
        const float dz = cur[1].z - cur->z;
        dist = sqrtf((dz * dz) + (dy * dy) + (dx * dx));
    }
    return dist;
}

std::ostream& operator<<(std::ostream& os, const Path& path) {
    for (int i = 0; i < path.currentSizeValue; ++i) {
        const Waypoint& wp = path.pathValue[i];
        os << "(" << wp.x << ", " << wp.y << ", " << wp.z << ") " << (uint)wp.facetToNextWaypoint << "\n";
    }
    return os;
}
