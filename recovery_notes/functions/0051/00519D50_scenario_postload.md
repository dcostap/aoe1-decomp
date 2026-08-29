# Recovery journal: 00519D50 `scenario_postload`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `matching`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

The PDB module is `tplayer.cpp`; the living owner is `src/tplayer.cpp`.
The owning class is `TRIBE_Player`. The body is `00519D50-00519D94` (69
bytes), after `TRIBE_Gaia::random_start` at `00519D40`. The next source-order
function is outside this body.

The natural source is now in the original-like source order:

```cpp
void TRIBE_Player::scenario_postload(int first, long* second, float third) {
    RGE_Player::scenario_postload(first, second, third);
    if (0.0 < this->attributes[50]) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
}
```

## Current mismatch

There is no current mismatch. Focused validation reports `MATCH`, `0.0000%`,
69/69 bytes, no frame, one saved register (`esi`), two equal calls, three of
three safely masked relocations, the original boundary, and the owning symbol
`?scenario_postload@TRIBE_Player@@UAEXHPAJM@Z`.

## Recovered attempt history

- The initial natural body used `attributes[0]` and `mutualExploredMask`.
  The assembly proves the guard reads the attributes pointer at `+0x50` and
  element `+0xC8`, which is `attributes[50]`.
- Meaningful target check `probe-001-behavior`: after changing the guard to
  `attributes[50]`, the body remained 69 bytes with two equal calls, but
  differed by two bytes at `+0x34`. The rebuilt store used `[this+0xD0]`.
- The class layout identifies `allied_LOS_Enable` at `+0x100`. Replacing the
  wrong `mutualExploredMask` store with `allied_LOS_Enable` produced the exact
  body.
- Final focused check: `MATCH`, `0.0000%`, 69/69 bytes, 21/21 instructions,
  100% shape and block coverage, two equal calls, zero wrong targets, and
  three of three safely masked relocations.
- The grouped `tplayer` audit included 103 normal functions. It found 65
  registered-owner matches and two exact but unregistered functions, including
  this target. The other 36 included functions remain unrelated grouped,
  accepted-drift, boundary, or relocation work.

## Rejected approaches

The prior raw-offset candidate used an artificial `info` pointer and a fake
`mutual_allies_loaded` field. It is not retained. Named existing fields and
the proven attributes array produce the same exact bytes without overlays or
manual layout declarations.

## Open questions

Registration and status promotion remain coordinator work. This worker made
no status or registration change.

## Next useful approaches

No further codegen work is needed for this function. The coordinator can review
the exact source and the unregistered-owner audit row for promotion.

## Worker updates

- `wave20-tplayer`: Recovered the proven `attributes[50]` guard and
  `allied_LOS_Enable` store. Focused and grouped validation are exact. The
  session is pinned and released after this journal update.
