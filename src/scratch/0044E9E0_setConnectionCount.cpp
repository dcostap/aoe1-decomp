// 0044E9E0 InfluenceMap::setConnectionCount
// PDB: infmap.cpp:394-458, 498 bytes
// Attempt log:
// - baseline: reconstructed the row scan and eight-direction switch from the
//   executable, but used explicit gotos and raw row-address arithmetic.
// - natural typed reconstruction: named the complete InfluenceMap layout,
//   restored ordinary validation and loops, and kept the switch fall-through
//   effects shown by the original dispatch table.
// - hoisted xOffset and signed direction % 2 reproduce the 0x24 frame,
//   remainder sequence, and most switch block placement.
// - count-pointer, declaration-order, and virtual-surface probes did not move
//   codegen. Remaining drift starts at saved-this placement and local slots.
// - an explicit vfptr donor surface was codegen-neutral. Restored the natural
//   virtual class surface because raw vptr modeling adds no evidence.
// - donor declaration order with abs parity improved positional drift by 7
//   bytes but lost exact blocks; restored the cleaner signed-parity form.
// - fresh TU lead: hoisted direction to function scope to match the original
//   EBP loop state and switch-arm placement; emitted code was unchanged, so
//   restored the clean typed loop source.
// - named xSize/ySize after the negative from checks moved the first mismatch
//   no bytes, improved positional diff by 1 byte, but lost block alignment;
//   restored the clean typed source.
// - named rows, xReference, and yReference in the inner-loop preheader;
//   this moved the saved-this slot to [esp+10h] and reduced positional diff
//   from 479 to 346 bytes, but the remaining block-shape drift is unresolved.
// - removed the explicit self alias while retaining the named rows and
//   coordinate references; codegen was unchanged, so restored the clean alias.
// - original local evidence confirms the typed switch behavior: case 0 and
//   case 7 share the y decrement; cases 1/2, 3/4, and 5/6 use cold arms. A
//   numeric common-label probe used an unsupported source label and was dropped.
// - fresh declaration-order, loop-form, scope, and switch-label probes either
//   stayed in the same basin or lost the clean result. The natural typed source
//   remains pinned; exact switch layout and register coloring need new donor or
//   compiler-context evidence.
// - this pass moved rowIndex into the inner preheader and changed its
//   assignment to a declaration initializer; both emitted the same 346-byte
//   mismatch. A direct from.y <= to.y guard moved the y load and worsened the
//   result to 355 bytes, so it was restored. Direct this member expressions
//   changed one setup hunk but kept the 346-byte result; the alias is retained.
// - ownership review confirms InfluenceMap offsets +0x04, +0x08, +0x0C,
//   +0x10, +0x18, and +0x20, plus the XYPoint reference ABI, from exact donors
//   and the target assembly. No shared declarations were changed.
// - this pass tested direct y-reference reads, persistent row and coordinate
//   locals, outer do/while form, and declaration order. Most stayed at 346.
//   Caching to.y changed the frame to 0x28 and worsened the result to 367.
// - direct rowValue reads reached 345 bytes but lost exact blocks. A source
//   switch label matching the cold arms reached 353 bytes and improved shape.
//   Both forms were restored because they are not smaller exact sources.
// - duplicating the natural case-0 and case-7 y updates let VC5 merge their
//   common tail. It also moved the other switch arms to the exact cold layout.
//   Shape rose from 84.66% to 91.23%, with a 345-byte positional mismatch.
// - explicit rowIndex and neighborRow variables were compiler shadows. Their
//   removal was codegen-neutral. The typed indexed source is authoritative.
// - a 42-variant declaration-order lab produced two nonexact code groups. A
//   four-form typed row-expression lab produced one nonexact code group.
//   Function-scope references, register, direct fields, and block-local offset
//   forms stayed in the 345-byte basin. Using abs(direction) widened the body.
// - final blocker: the target stores self at [esp+10h] and its scaled row at
//   [esp+14h]. The rebuild swaps those homes. The target keeps scaled
//   yReference in ECX and rows at [esp+1Ch]; the rebuild swaps those roles.
//   This changes the preheader by four bytes and shifts all later addresses.
// - fresh exact-finish pass: removing the yReference local and rereading the
//   typed member in both row accesses reduced the mismatch from 345 to 8
//   bytes. The natural source then matched all non-stack bytes, CFG shape,
//   frame, owner symbol, boundary, and the target's zero-call set.
// - exact-finish reduction tested plain, const, reference, top-scope, and
//   inner-scope self aliases; row and xOffset scopes; row-index naming; loop
//   spelling; and the donor object-header surface. These either duplicated
//   the 8-byte result or widened the body. The reduced typed source is kept.
// - final validation: fresh grouped bytes remain an 8-byte stack-home swap.
//   Original self homes are [esp+10h] and row offset [esp+14h]. VC5 emits
//   those homes in reverse. The target has no direct or indirect calls.
// Accepted-drift audit: do not promote. The current source matches the
// executable's rowValue, xReferencePointValue, and yReferencePointValue read
// order. The remaining mismatch is only the compiler's stack-home choice.
// Invalid object storage keeps the executable fault order documented here.

typedef unsigned char uchar;

#ifndef INFMAP_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};
#endif

#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    virtual ~InfluenceMap();                  // +0x00 virtual surface
    int xSizeValue;                           // +0x04
    int ySizeValue;                           // +0x08
    int xReferencePointValue;                 // +0x0C
    int yReferencePointValue;                 // +0x10
    uchar* valueValue;                        // +0x14
    uchar** rowValue;                         // +0x18
    int coverageCountValue;                   // +0x1C
    int connectionCountValue;                // +0x20
    uchar unchangeableLimitValue;             // +0x24

    int setConnectionCount(const XYPoint& from, const XYPoint& to,
                           int minimum, int edgeHorizontal, int edgeVertical,
                           int allDirections);
};
#endif

int InfluenceMap::setConnectionCount(const XYPoint& from, const XYPoint& to,
                                     int minimum, int edgeHorizontal,
                                     int edgeVertical, int allDirections)
{
    InfluenceMap* self = this;

    self->connectionCountValue = 0;

    if (from.x < 0 || from.y < 0 || from.x >= self->xSizeValue ||
        from.y >= self->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= self->xSizeValue || to.y >= self->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        int y = from.y;
        if (y <= to.y) {
            uchar** rows = self->rowValue;
            int xOffset = x - self->xReferencePointValue;
            do {
                if (rows[y - self->yReferencePointValue]
                                      [xOffset] >= minimum) {
                    int neighborX = x;
                    int neighborY = y;

                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                            // BINARY NOTE: VC5 merges this suffix with case 7.
                            --neighborY;
                            break;
                        case 1:
                        case 2:
                            ++neighborX;
                            break;
                        case 3:
                        case 4:
                            ++neighborY;
                            break;
                        case 5:
                        case 6:
                            --neighborX;
                            break;
                        case 7:
                            --neighborY;
                            break;
                        }

                        if (allDirections || (direction % 2) != 0) {
                            if (neighborX >= 0 && neighborX < self->xSizeValue &&
                                neighborY >= 0 && neighborY < self->ySizeValue) {
                                if (rows[neighborY - self->yReferencePointValue]
                                                   [neighborX - self->xReferencePointValue] >= minimum) {
                                    ++self->connectionCountValue;
                                }
                            } else if ((edgeHorizontal == 1 && (direction % 2) == 1) ||
                                       (edgeVertical == 1 && (direction % 2) == 0)) {
                                ++self->connectionCountValue;
                            }
                        }
                    }
                }
                ++y;
            } while (y <= to.y);
        }
    }

    return self->connectionCountValue;
}
