#include "../include/path.h"
#include <iostream.h>
#include <math.h>

extern float DAT_00570e40;


Path::Path(int max_size)
{
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

    if (max_size == 0 || max_size >= 0) {
        maxSizeValue = max_size;
        Waypoint* new_path = (Waypoint*)operator_new(max_size << 4);
        int i = 0;
        if (currentSizeValue > 0) {
            int off = 0;
            Waypoint* dst = new_path;
            do {
                dst->x = *(float*)((char*)pathValue + off);
                dst->y = *(float*)((char*)pathValue + off + 4);
                dst->z = *(float*)((char*)pathValue + off + 8);
                dst->facetToNextWaypoint =
                    *(unsigned char*)((char*)pathValue + off + 12);
                ++i;
                ++dst;
                off += 16;
            } while (i < currentSizeValue);
        }
        if (pathValue) {
            operator_delete(pathValue);
        }
        pathValue = new_path;
    }
}

Path::~Path()
{
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
}

ostream& __cdecl operator<<(ostream& os, const Path& path)
{
    for (int i = 0; i < path.currentSizeValue; i++) {
        ostream* out = &os;
        float value;
        out = &out->operator<<("(");
        value = path.pathValue[i].x;
        out = &out->operator<<(value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].y;
        out = &out->operator<<(value);
        out = &out->operator<<(", ");
        value = path.pathValue[i].z;
        out = &(out->operator<<(value) << ", ");
        os << (int)path.pathValue[i].facetToNextWaypoint << ") ";
    }
    return os;
}

Path Path::operator+(const Path& other) const
{
    Path newPath(maxSizeValue + other.maxSizeValue);
    int i = 0;
    if (0 < currentSizeValue) {
        do {
            newPath.insertAtEnd(pathValue[i]);
            i++;
        } while (i < currentSizeValue);
    }
    int j = 0;
    if (other.currentSizeValue > 0) {
        do {
            newPath.insertAtEnd(other.pathValue[i]);
            i++;
            j++;
        } while (j < other.currentSizeValue);
    }
    return newPath;
}

Path& Path::operator=(const Path& other)
{
    if (maxSizeValue < other.maxSizeValue) {
        setMaxSize(other.maxSizeValue);
    }
    for (int i = 0; i < other.currentSizeValue; i++) {
        pathValue[i].x = other.pathValue[i].x;
        pathValue[i].y = other.pathValue[i].y;
        pathValue[i].z = other.pathValue[i].z;
        pathValue[i].facetToNextWaypoint =
            other.pathValue[i].facetToNextWaypoint;
    }
    currentWaypointValue = other.currentWaypointValue;
    currentSizeValue = other.currentSizeValue;
    return *this;
}

int Path::operator==(const Path& other) const
{
    int i = 0;
    if (currentSizeValue <= 0) {
        return 1;
    }
    for (; i < currentSizeValue; i++) {
        if (other.pathValue[i].x != pathValue[i].x ||
            other.pathValue[i].y != pathValue[i].y ||
            other.pathValue[i].z != pathValue[i].z ||
            other.pathValue[i].facetToNextWaypoint !=
                pathValue[i].facetToNextWaypoint) {
            return 0;
        }
    }
    return 1;
}

int Path::insertAtCurrent(const Waypoint& wp)
{
    if (currentSizeValue > 1000) {
        return 0;
    }
    Waypoint* new_path =
        (Waypoint*)operator_new((currentSizeValue + 1) * 16);
    new_path[0].x = wp.x;
    new_path[0].y = wp.y;
    new_path[0].z = wp.z;
    new_path[0].facetToNextWaypoint = wp.facetToNextWaypoint;
    for (int i = 0; i < currentSizeValue; i++) {
        new_path[i + 1].x = pathValue[i].x;
        new_path[i + 1].y = pathValue[i].y;
        new_path[i + 1].z = pathValue[i].z;
        new_path[i + 1].facetToNextWaypoint =
            pathValue[i].facetToNextWaypoint;
    }
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
    pathValue = new_path;
    currentSizeValue++;
    return 1;
}

int Path::insertAtEnd(Waypoint wp)
{
    if (currentSizeValue == maxSizeValue) {
        maxSizeValue += maxSizeValue;
        Waypoint* new_path =
            (Waypoint*)operator_new(maxSizeValue * 16);
        for (int i = 0; i < currentSizeValue; i++) {
            new_path[i].x = pathValue[i].x;
            new_path[i].y = pathValue[i].y;
            new_path[i].z = pathValue[i].z;
            new_path[i].facetToNextWaypoint =
                pathValue[i].facetToNextWaypoint;
        }
        if (pathValue != 0) {
            operator_delete(pathValue);
        }
        pathValue = new_path;
    }
    pathValue[currentSizeValue].x = wp.x;
    pathValue[currentSizeValue].y = wp.y;
    pathValue[currentSizeValue].z = wp.z;
    pathValue[currentSizeValue].facetToNextWaypoint = wp.facetToNextWaypoint;
    currentSizeValue++;
    return 1;
}

int Path::contains(const Waypoint& wp) const
{
    for (int i = 0; i < currentSizeValue; i++) {
        if (floor(pathValue[i].x) == floor(wp.x) &&
            floor(pathValue[i].y) == floor(wp.y)) {
            return 1;
        }
    }
    return 0;
}

void Path::killPath()
{
    currentSizeValue = 0;
    currentWaypointValue = 0;
}

const int Path::maxNumberOfWaypoints() const
{
    return maxSizeValue;
}

const int Path::numberOfWaypoints() const
{
    return currentSizeValue;
}

unsigned long Path::timeStamp() const
{
    return timeStampValue;
}

void Path::setTimeStamp(unsigned long value)
{
    timeStampValue = value;
}

float Path::length() const
{
    float total = 0.0f;
    if (currentSizeValue > 1) {
        Waypoint* waypoint = pathValue + 1;
        int remaining = currentSizeValue - 1;
        do {
            // The first z term uses the previous x value.
            total += sqrtf((waypoint[0].x - waypoint[-1].x) *
                               (waypoint[0].x - waypoint[-1].x) +
                           (waypoint[0].y - waypoint[-1].y) *
                               (waypoint[0].y - waypoint[-1].y) +
                           (waypoint[0].z - waypoint[-1].x) *
                               (waypoint[0].z - waypoint[-1].z));
            ++waypoint;
        } while (--remaining != 0);
    }
    return total;
}

const Waypoint& Path::start() const
{
    return startValue;
}

const Waypoint& Path::goal() const
{
    return goalValue;
}

const Waypoint* Path::waypoint(int index) const
{
    if (pathValue != 0 && index > -1 && index < currentSizeValue) {
        return pathValue + index;
    }
    return 0;
}

Waypoint* Path::currentWaypoint() const
{
    int index;

    if (pathValue != 0) {
        index = currentWaypointValue;
        if (index > -1 && index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}

const int Path::currentWaypointNumber() const
{
    return currentWaypointValue;
}

void Path::setCurrentWaypointNumber(int value)
{
    currentWaypointValue = value;
}

const Waypoint* Path::nextWaypoint() const
{
    int index;

    if (pathValue != 0 && currentWaypointValue > -1) {
        index = currentWaypointValue + 1;
        if (index < currentSizeValue) {
            return pathValue + index;
        }
    }
    return 0;
}

const Waypoint* Path::previousWaypoint() const
{
    int next_index;

    if (pathValue != 0) {
        next_index = currentWaypointValue + 1;
        if (next_index > 0 && currentWaypointValue < currentSizeValue) {
            return pathValue + currentWaypointValue - 1;
        }
    }
    return 0;
}

const Waypoint* Path::firstWaypoint() const
{
    if (pathValue != 0 && currentSizeValue > 0) {
        return pathValue;
    }
    return 0;
}

const Waypoint* Path::lastWaypoint() const
{
    if (pathValue != 0 && currentSizeValue > 0) {
        return pathValue + currentSizeValue - 1;
    }
    return 0;
}

void Path::initToStart()
{
    currentWaypointValue = 0;
}

void Path::initToEnd()
{
    currentWaypointValue = currentSizeValue - 1;
}

int Path::moveToNextWaypoint()
{
    int index;

    index = currentSizeValue - 1;
    if (currentWaypointValue < index) {
        currentWaypointValue = currentWaypointValue + 1;
        return 1;
    }
    currentWaypointValue = index;
    return 0;
}

int Path::moveToLastWaypoint()
{
    if (currentWaypointValue > 0) {
        currentWaypointValue = currentWaypointValue - 1;
        return 1;
    }
    return 0;
}

float Path::distanceToNextWaypoint() const
{
    float result = DAT_00570e40;
    Waypoint* path = pathValue;

    if (path != 0) {
        int current = currentWaypointValue;
        if (current >= 0 && current < currentSizeValue - 1) {
            result = sqrt((path[current + 1].x - path[current].x) *
                              (path[current + 1].x - path[current].x) +
                          (path[current + 1].y - path[current].y) *
                              (path[current + 1].y - path[current].y) +
                          (path[current + 1].z - path[current].z) *
                              (path[current + 1].z - path[current].z));
        }
    }
    return result;
}
