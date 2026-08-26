// VA: 0046D830 PathingSystem::copyPath(int) (1114B)
// pathsys.cpp lines 2249-2421
//
// Attempt log:
// - Prior source was a raw PathSys/PathChecker scaffold and remained 10 bytes
//   short with mismatched helper surfaces.  This reconstruction restores the
//   named PathingSystem, RGE_Moving_Object, Path, Waypoint, and ManagedArray
//   ownership shown by the same-TU packet and exact donors.
// - The source keeps the executable's two-byte open-path coordinate, facet
//   mask/direction conversion, selected normal/exception Path, bounded neighbor
//   scan, inline ManagedArray::add, eight-way switch, and final insertion.
// - The typed candidate reaches the original 0x34 frame, 9/9 ordered calls,
//   33/33 conditional signals, and the original 1114-byte boundary.  The
//   final clean check is 14 positional bytes (1.2567%), with 99.07% shape
//   similarity and 91.98% exact-block coverage.  The remaining bytes are
//   map-index register-order drift in the first and repeated facet loads.
//   No call target or ownership mismatch remains.
// - Tested a natural typed facet-before-coordinate assignment order because
//   the target loads the facet before its floating-point coordinate stores;
//   it moved 25 positional bytes farther from the clean candidate and was
//   rolled back.  The clean x/y/z/facet order remains the best reconstruction.
// - Matched the neighbor-bound structure with incremented max and decremented
//   min values; this reduced the rebuilt size to the original 1114 bytes.
// - The normal-first path tests and maxX/maxY comparison direction reproduce
//   the original branch polarity.  Separate facetByte/currentFacet locals,
//   plus a sentinel assignment before the facet load, reduce the strict diff
//   to 14 bytes.  The reviewed objectGroupOnTile int& ABI is retained.
// - Row-pointer, flat-cursor, foo-order, call-local, aggregate-temp, and
//   declaration-scope variants did not improve the clean source.  Adding
//   standard headers reduced one diagnostic result to 12 bytes, but had no
//   donor-backed source evidence and was removed.  No exact result was found.
// - Exact-finish pass: 20 fresh probes tested typed row ownership, the proven
//   PathingSystem virtual surface, stdlib/math/stdio context, facet-mask scope,
//   comparison order, open-path cursor ownership, and local declaration order.
//   The stdlib plus loop-local mask form reached 12 bytes, but no variant was
//   exact.  The pinned 14-byte source is restored.
// - Fresh validation retains the original 0x34 frame, 1114-byte boundary,
//   9 ordered direct calls, 33 conditional signals, and the PathingSystem
//   owner symbol.  The residual is confined to two repeated map-index address
//   schedules.  The 14 bytes do not change calls, writes, predicates, cleanup,
//   or fault order.
// ACCEPTED DRIFT: The 14 bytes only reassociate the same three integer terms
// in two map-tile addresses. One repeated site also exchanges an independent
// EBP mask with the ordinary facet-byte load. Both builds read the same address
// and compare the same masked facet values. No call, write, predicate, cleanup,
// or fault order changes, and all later state is equal after each tile load.

#include <stddef.h>

#include "../../include/pathsys_context.h"

int PathingSystem::copyPath(int step)
{
    uchar previousFacet;

    {
        Path* path;
        if (this->currentObject->storePathInExceptionPath == 0)
            path = &this->currentObject->pathValue;
        else
            path = &this->currentObject->exceptionPathValue;
        path->killPath();
    }

    BYTEPoint currentPoint;
    currentPoint.x = this->MGP_openPaths[1].x;
    currentPoint.y = this->MGP_openPaths[1].y;
    int fooX = currentPoint.x;
    int fooY = currentPoint.y;
    previousFacet = 0xFF;
    uchar facetByte = this->facetValue[currentPoint.x][currentPoint.y];
    uchar currentFacet;
    if ((facetByte & 0xF8) == this->CurrentFacetMask)
        currentFacet = facetByte & 7;
    else
        currentFacet = 0xFF;

    RGE_Moving_Object* object = this->currentObject;
    Waypoint waypoint;
    waypoint.x = (float)fooX + this->currentXOffset;
    waypoint.y = (float)fooY + this->currentYOffset;
    waypoint.z = object->world_z;
    waypoint.facetToNextWaypoint = currentFacet;

    {
        Path* path = object->storePathInExceptionPath == 0
            ? &object->pathValue
            : &object->exceptionPathValue;
        path->initToStart();
    }

    do {
        if (this->initialTile.x == fooX && this->initialTile.y == fooY) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
            return 1;
        }

        if (currentFacet != previousFacet) {
            if (this->currentObject->storePathInExceptionPath == 0) {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
        }

        if (this->currentUnobstructibleGroupID != -1) {
            int minX = fooX - 1;
            int maxX = fooX + 1;
            if (minX < 0) {
                minX = 0;
                ++maxX;
            } else if (maxX >= this->xSizeValue) {
                --minX;
                maxX = this->xSizeValue - 1;
            }

            int minY = fooY - 1;
            int maxY = fooY + 1;
            if (minY < 0) {
                minY = 0;
                ++maxY;
            } else if (maxY >= this->ySizeValue) {
                --minY;
                maxY = this->ySizeValue - 1;
            }

            for (int tileX = minX; tileX <= maxX; ++tileX) {
                for (int tileY = minY; tileY <= maxY; ++tileY) {
                    int objectCountOnTile = 0;
                    int id = this->worldValue->objectGroupOnTile(
                        this->currentUnobstructiblePlayerID,
                        this->currentUnobstructibleGroupID,
                        tileX, tileY, objectCountOnTile);
                    if (id != -1)
                        this->currentUnobstructibles.add(id);
                }
            }
        }

        switch ((int)currentFacet) {
        case 0:
            currentPoint.x += (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 1:
            currentPoint.y += (uchar)step;
            break;
        case 2:
            currentPoint.x -= (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 3:
            currentPoint.x -= (uchar)step;
            break;
        case 4:
            currentPoint.x -= (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 5:
            currentPoint.y -= (uchar)step;
            break;
        case 6:
            currentPoint.x += (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 7:
            currentPoint.x += (uchar)step;
            break;
        }

        previousFacet = currentFacet;
        fooX = currentPoint.x;
        fooY = currentPoint.y;
        facetByte = this->facetValue[fooX][fooY];
        if ((facetByte & 0xF8) == this->CurrentFacetMask)
            currentFacet = facetByte & 7;
        else
            currentFacet = 0xFF;
        waypoint.x = (float)fooX + this->currentXOffset;
        waypoint.y = (float)fooY + this->currentYOffset;
        waypoint.facetToNextWaypoint = currentFacet;
    } while (true);
}
