#include "../include/path.h"
#include <iostream.h>
#include <math.h>

extern float g_path_zero_length;


Path::Path(int v) {
    timeStampValue = 0;
    pathValue = 0;
    maxSizeValue = 0;
    currentSizeValue = 0;
    currentWaypointValue = 0;
    startValue.x = 0;
    startValue.y = 0;
    startValue.z = 0;
    goalValue.x = 0;
    goalValue.y = 0;
    goalValue.z = 0;

    if (v == 0 || v >= 0) {
        maxSizeValue = v;
        Waypoint* new_path = (Waypoint*)::operator new(v << 4);
        int i = 0;
        if (currentSizeValue > 0) {
            Waypoint* dst = new_path;
            for (; i < currentSizeValue; ++i) {
                dst[i].x = pathValue[i].x;
                dst[i].y = pathValue[i].y;
                dst[i].z = pathValue[i].z;
                dst[i].facetToNextWaypoint =
                    pathValue[i].facetToNextWaypoint;
            }
        }
        if (pathValue) {
            ::operator delete(pathValue);
        }
        pathValue = new_path;
    }
}

Path::~Path() {
    if (pathValue != 0) {
        ::operator delete(pathValue);
    }
}

ostream& __cdecl operator<<(ostream& out, const Path& p) {
    for (int i = 0; i < p.currentSizeValue; i++) {
        ostream* stream = &out;
        float value;
        stream = &stream->operator<<("(");
        value = p.pathValue[i].x;
        stream = &stream->operator<<(value);
        stream = &stream->operator<<(", ");
        value = p.pathValue[i].y;
        stream = &stream->operator<<(value);
        stream = &stream->operator<<(", ");
        value = p.pathValue[i].z;
        stream = &(stream->operator<<(value) << ", ");
        out << (int)p.pathValue[i].facetToNextWaypoint << ") ";
    }
    return out;
}

Path Path::operator+(const Path& p) const {
    Path newPath(maxSizeValue + p.maxSizeValue);
    int i = 0;
    if (0 < currentSizeValue) {
        do {
            newPath.insertAtEnd(pathValue[i]);
            i++;
        } while (i < currentSizeValue);
    }
    int j = 0;
    if (p.currentSizeValue > 0) {
        do {
            newPath.insertAtEnd(p.pathValue[i]);
            i++;
            j++;
        } while (j < p.currentSizeValue);
    }
    return newPath;
}

Path& Path::operator=(const Path& p) {
    if (maxSizeValue < p.maxSizeValue) {
        setMaxSize(p.maxSizeValue);
    }
    for (int i = 0; i < p.currentSizeValue; i++) {
        pathValue[i].x = p.pathValue[i].x;
        pathValue[i].y = p.pathValue[i].y;
        pathValue[i].z = p.pathValue[i].z;
        pathValue[i].facetToNextWaypoint =
            p.pathValue[i].facetToNextWaypoint;
    }
    currentWaypointValue = p.currentWaypointValue;
    currentSizeValue = p.currentSizeValue;
    return *this;
}

int Path::operator==(const Path& p) const {
    for (int i = 0; i < currentSizeValue; i++) {
        Waypoint* path = pathValue + i;
        Waypoint* other_path = p.pathValue + i;
        if (path->x != other_path->x || path->y != other_path->y || path->z != other_path->z ||
            path->facetToNextWaypoint != other_path->facetToNextWaypoint) {
            return 0;
        }
    }
    return 1;
}

int Path::insertAtCurrent(const Waypoint& w) {
    if (currentSizeValue > 1000) {
        return 0;
    }
    Waypoint* new_path = (Waypoint*)::operator new((currentSizeValue + 1) * 16);
    new_path[0].x = w.x;
    new_path[0].y = w.y;
    new_path[0].z = w.z;
    new_path[0].facetToNextWaypoint = w.facetToNextWaypoint;
    for (int i = 0; i < currentSizeValue; i++) {
        new_path[i + 1].x = pathValue[i].x;
        new_path[i + 1].y = pathValue[i].y;
        new_path[i + 1].z = pathValue[i].z;
        new_path[i + 1].facetToNextWaypoint =
            pathValue[i].facetToNextWaypoint;
    }
    if (pathValue != 0) {
        ::operator delete(pathValue);
    }
    pathValue = new_path;
    currentSizeValue++;
    return 1;
}

int Path::insertAtEnd(Waypoint w) {
    if (currentSizeValue == maxSizeValue) {
        maxSizeValue += maxSizeValue;
        Waypoint* new_path = (Waypoint*)::operator new(maxSizeValue * 16);
        for (int i = 0; i < currentSizeValue; i++) {
            new_path[i].x = pathValue[i].x;
            new_path[i].y = pathValue[i].y;
            new_path[i].z = pathValue[i].z;
            new_path[i].facetToNextWaypoint =
                pathValue[i].facetToNextWaypoint;
        }
        if (pathValue != 0) {
            ::operator delete(pathValue);
        }
        pathValue = new_path;
    }
    pathValue[currentSizeValue].x = w.x;
    pathValue[currentSizeValue].y = w.y;
    pathValue[currentSizeValue].z = w.z;
    pathValue[currentSizeValue].facetToNextWaypoint = w.facetToNextWaypoint;
    currentSizeValue++;
    return 1;
}

int Path::contains(const Waypoint& w) const {
    for (int i = 0; i < currentSizeValue; i++) {
        if (floor(pathValue[i].x) == floor(w.x) && floor(pathValue[i].y) == floor(w.y)) {
            return 1;
        }
    }
    return 0;
}

void Path::killPath() {
    currentSizeValue = 0;
    currentWaypointValue = 0;
}

const int Path::maxNumberOfWaypoints() const {
    return maxSizeValue;
}

const int Path::numberOfWaypoints() const {
    return currentSizeValue;
}

unsigned long Path::timeStamp() const {
    return timeStampValue;
}

void Path::setTimeStamp(unsigned long v) {
    timeStampValue = v;
}

float Path::length() const {
    float total = 0.0f;
    if (currentSizeValue > 1) {
        Waypoint* waypoint = pathValue + 1;
        int remaining = currentSizeValue - 1;
        do {
            // The first z term uses the previous x value.
            total += sqrtf((waypoint[0].x - waypoint[-1].x) * (waypoint[0].x - waypoint[-1].x) +
                           (waypoint[0].y - waypoint[-1].y) * (waypoint[0].y - waypoint[-1].y) +
                           (waypoint[0].z - waypoint[-1].x) * (waypoint[0].z - waypoint[-1].z));
            ++waypoint;
        } while (--remaining != 0);
    }
    return total;
}

const Waypoint& Path::start() const {
    return startValue;
}

const Waypoint& Path::goal() const {
    return goalValue;
}

const Waypoint* Path::waypoint(int w) const {
    if (pathValue != 0 && w > -1 && w < currentSizeValue) {
        return pathValue + w;
    }
    return 0;
}

Waypoint* Path::currentWaypoint() const {
    int index;

    if (pathValue != 0) {
        index = currentWaypointValue;
        if (index > -1 && index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}

const int Path::currentWaypointNumber() const {
    return currentWaypointValue;
}

void Path::setCurrentWaypointNumber(int v) {
    currentWaypointValue = v;
}

const Waypoint* Path::nextWaypoint() const {
    int index;

    if (pathValue != 0 && currentWaypointValue > -1) {
        index = currentWaypointValue + 1;
        if (index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}

const Waypoint* Path::previousWaypoint() const {
    int next_index;

    if (pathValue != 0) {
        next_index = currentWaypointValue + 1;
        if (next_index > 0 && currentWaypointValue < currentSizeValue) {
            return pathValue + currentWaypointValue - 1;
        }
    }
    return 0;
}

const Waypoint* Path::firstWaypoint() const {
    if (pathValue != 0 && currentSizeValue > 0) {
        return pathValue;
    }
    return 0;
}

const Waypoint* Path::lastWaypoint() const {
    if (pathValue != 0 && currentSizeValue > 0) {
        return pathValue + currentSizeValue - 1;
    }
    return 0;
}

void Path::initToStart() {
    currentWaypointValue = 0;
}

void Path::initToEnd() {
    currentWaypointValue = currentSizeValue - 1;
}

int Path::moveToNextWaypoint() {
    int index;

    index = currentSizeValue - 1;
    if (currentWaypointValue < index) {
        currentWaypointValue = currentWaypointValue + 1;
        return 1;
    }
    currentWaypointValue = index;
    return 0;
}

int Path::moveToLastWaypoint() {
    if (currentWaypointValue > 0) {
        currentWaypointValue = currentWaypointValue - 1;
        return 1;
    }
    return 0;
}

float Path::distanceToNextWaypoint() const {
    float result = g_path_zero_length;
    Waypoint* path = pathValue;

    if (path != 0) {
        int current = currentWaypointValue;
        if (current >= 0 && current < currentSizeValue - 1) {
            result = sqrt((path[current + 1].x - path[current].x) * (path[current + 1].x - path[current].x) +
                          (path[current + 1].y - path[current].y) * (path[current + 1].y - path[current].y) +
                          (path[current + 1].z - path[current].z) * (path[current + 1].z - path[current].z));
        }
    }
    return result;
}
