# Save-check missile divergence and repair

## Observed result

The earlier recorded `save-check` run failed parity. Its trace report is
`build/runtime/traces-20260927T222151457247Z-00957913927f/report.json`.
It reports the first RNG call-site difference at record 4,034,042 and world
update 56,688. It reports the first state difference at update 56,694.

Paired call probes place an earlier numeric difference in missile object
`-280`. At probe update 56,650, both runs call
`RGE_Action_Missile::set_state(3)` and then `set_state(4)` for this missile.
The action target IDs are 9,099 and 9,185 in both runs. At entry to
`set_state(4)`, the original and rebuilt action fields agree apart from
process pointers. At the next action update, these stored fields differ:

| Field | Original | Rebuilt |
| --- | --- | --- |
| `velocity_x` | -0.5109829306602478 | -0.510982871055603 |
| `velocity_y` | 0.8118545413017273 | 0.8118544816970825 |
| `velocity_z` | -0.2824690043926239 | -0.2824689745903015 |
| `ballistic_acceleration` | -3.0620062351226807 | -3.0620057582855225 |

At probe update 56,687, the rebuilt run creates a trail sprite during
`RGE_Missile_Object::missile_move`. The original run creates trail sprites
at probe update 56,688. Before the next probed missile action in update
56,687, the rebuilt RNG count is three calls ahead. The two missile actions
and two `missile_move` calls per update still run in both versions. The probe
update field and the main trace world-update field do not use the same
boundary.

The missile's `trail_remainder` agrees at probe update 56,658. It first
differs at update 56,659 by about 0.0000004. Its difference grows to about
0.00971 at update 56,687. Both versions of
`RGE_Moving_Object::teleport` are byte-exact. That function adds the
remainder twice when it creates no trail object. This existing behavior
amplifies a small movement difference. Immediately before the different
trail creation, the original remainder is 0.307926685 and the rebuilt
remainder is 0.317637414. The next movement is about 0.0848 units. Its
sum with the rebuilt remainder passes the apparent 0.4 trail spacing;
the original sum does not. The next original remainder is 0.700747788;
the rebuilt remainder resets to 0.002531826.

The original `set_state` code stores the target velocity and the adjusted
speed in single-precision stack slots. Its adjustment division reads a
stored speed. The rebuilt code retains more values on the x87 stack and
divides by the retained speed. See the instruction pairs near original
`00404EF0` through `00404F83`, and the matching range in
`python tools/check_function.py --va 00404DB0 --range +0115-+01D7 --detail full`.
`set_state` has 247 original and 253 rebuilt instructions. Its result is
`MISMATCH`. `missile_move` has 60 instructions in each version and differs
in two float addition operand orders. Its result is also `MISMATCH`.
`RGE_Combat_Object::teleport` and `RGE_Moving_Object::teleport` both return
`MATCH` with zero positional byte differences.

The launch fields differ before the first RNG call-site difference. The
trail remainder then separates during flight and crosses the trail threshold
one update earlier. The later paired replay confirms that the launch
numeric difference caused this first RNG call-site difference.

## Repair

`src/act_misl.cpp` now casts the full sine-and-speed product to `float`.
The old source cast the sine result before multiplication. The new form
causes VC5 to store the product as a float. It also stores the adjusted
speed before division. The original code uses both float stores. A paired
flight probe found equal action velocity and acceleration words at launch
and at probe updates 56,651, 56,686, 56,687, and 56,688.

The complete `save-check` traced suite case passed for the candidate build.
Both the original and rebuilt runs exited successfully. The report is
`build/runtime/traces-20260927T233144057465Z-174440aa7cc6/report.json`.
The final source also has one comment that records the rounding reason.
Its full traced suite passed all three cases: `random-map-opening`,
`save-check`, and `saved-game-session-1`. The final report is
`build/runtime/traces-20260927T233824373008Z-11f90698461c/report.json`.

## Capture files

- Flight probes: `build/runtime/original-20260927T224801605510Z-599818e2e148/capture/report.json`
  and `build/runtime/rebuilt-20260927T224801643526Z-d5b440d96000/capture/report.json`.
- First call-site probes: `build/runtime/original-20260927T223615837926Z-5c0f0bfb2bfb/capture/report.json`
  and `build/runtime/rebuilt-20260927T223615862443Z-b37cf76eef22/capture/report.json`.
- Missile movement probes: `build/runtime/original-20260927T224221949705Z-ae07b60705ef/capture/report.json`
  and `build/runtime/rebuilt-20260927T224221951705Z-81a843c3d77c/capture/report.json`.
- Trail probes: `build/runtime/original-20260927T230003992011Z-dff2567736cc/capture/report.json`
  and `build/runtime/rebuilt-20260927T230004027302Z-a09270e69b1a/capture/report.json`.

The capture files are local build output. They are not tracked evidence.
This note retains the measured values and the path to each local capture.

The prior rebuilt diagnostic run ended with a replay update-count mismatch.
The repaired diagnostic run completed with the same final input, update,
time, and object counts as the original run. The corrected `set_state`
function remains a byte mismatch; do not change its registry status to
`matching`. Keep the existing trail update: the original binary proves it.

## Final validation limits

- Registry check: `validate_translation_units.py --no-build-checks` passed.
- Build: all 226 sources compiled and linked. The final build report is
  `build/executable/user/20260927T233630057825Z-3def6616d612/20260927T233630291819Z/report.json`.
- Changed-unit audit: five `matching` results and two observed nonmatching
  results. The owner audit found zero mismatches. Reports are under
  `build/validation/missile-fix-final-20260927/functions/` and
  `build/validation/missile-fix-final-20260927/owners.json`.
- Linked-image audit: 11,354 supported passes, zero supported failures, and
  47,842 unknown checks. The report is under
  `build/validation/missile-fix-final-20260927/dependencies/`.
- Automated tests: 995 passed, two skipped, and 31 subtests passed. The
  report is `build/validation/missile-fix-final-20260927/tests.xml`.
- The paced parity suite and the capture suite did not run. The three
  traced cases give bounded replay evidence, not whole-game parity.
