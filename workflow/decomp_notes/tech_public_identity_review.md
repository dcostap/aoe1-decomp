# Tech public identity and compiler review

## Behavior

No game was run. The July executable remains the behavior oracle.
Original public symbols resolve all 33 Tech entry identities.
The original PDB hash is `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

Reproduce the ownership evidence with cvdump `-m`, `-seccontrib`, and `-p` on `orig/age1_x1.pdb`.
The module and contribution records are:

```text
0027 ".\Release\tech.obj"
0027 0001:0010A840 00001C17 60500020
0027 0003:000086C0 00000024 40400040
0027 0004:00009F74 00000051 C0300040
```

Section 1 starts at VA `00401000`. Its Tech contribution covers `0050B840` through `0050D456`, inclusive.
Every reviewed public function lies at a known entry inside that contribution.
The exact names are preserved in `config/original_owner_symbol_overrides.txt`.
Missing procedure and line records remain missing. They do not negate these independent public and contribution records.

## Source

The natural owner remains `src/tech.cpp`; no duplicate or wrapper was added.
An explicit `/Od` compiler profile reproduces 29 complete function bodies with their original symbols.
This supports an unoptimized compiler route. It does not explain the four remaining source differences.
The first closure exposed a header-route selection bug in the audit, not a compiler failure.
The corrected audit checks each header function only in its designated emission module.

The public signature of tech_cost uses six short references, not six short pointers.
The January map independently uses the identical decorated signature in `tech.obj`.
The older counterpart is `0047D20C`; its layout and behavior remain reference evidence only.
The complete query is `build/references/tech_cost_public.json` and its text companion.

The July getter at `0050C2FA` checks the signed short index, including the original inclusive upper limit.
It returns minus one outside that range. Otherwise it loads the help field through the 60-byte Tech_Tree entry.
The source retains the original off-by-one condition and does not add pointer guards.

## Bytes

Preserved `/Od` baseline state: `822da0c9f2f6e48290fe93f540e3c0efca55dda49a2da3f6b510a7ba08ccdc71`.
Run event: `f024956fe8fd0da3b2c7446bd4a24b71f5639f34cca0416c86c0bf38e6577cb3`.
The 57-byte getter reports `MATCH`, `0.0000%`.
The full 33-function module audit reports 29 local matches, three byte differences, and one missing expected symbol.
The three differences are 33 bytes at `0050CA9E`, 22 at `0050CC25`, and 28 at `0050CE68`.
The missing symbol belongs to the incorrect pointer signature at `0050C730`.

## Integration

The registry now supplies one explicit recipe and original symbol per Tech function.
All 33 entries remain scratch pending source review. No byte score automatically promotes them.
The unoptimized recipe replaces the executable-only fallback build route.
The cause of the remaining local placement differences still requires experiments; it is not an established compiler-context explanation.

## Reference signature repair

The integrated declaration and definition now use six short references.
All four callers pass the same output locations in the same order.
The source retains output writes, narrow conversions, overlap effects, and the final third-cost assignment.
Changed shared file: `include/tech.h`.
Changed modules: `src/tech.cpp`, `src/tplayer.cpp`, and `src/scr_game.cpp`.

State `solo-tech-cost-references` preserves the repair and its module check.
The target now emits its original symbol, but retains 27 positional byte differences.
The 14-module header closure checks 592 functions.
Of 502 matching claims, 499 pass; three retain existing reference-evidence gaps.
Event `e5fab214095848e69c5e9d92ea8f428499dfda8d765a6d9721d93b88458b6a0c` preserves the complete closure report.

## Natural source variants

The lab tested all six orders of the three ordinary local declarations under `/Od` and `/O2`.
Its first run exposed a tool defect: the lab ignored the configured compiler profile.
The repaired tool freezes the configured response file before compilation.
Three regression tests cover Tech, a header emitter, and subsequent response-file changes.

The repeated `/Od` cases emit 878 bytes, with either 16 or 27 positional differences.
The `/O2` cases emit 559 bytes and fail the size invariant.
No case matches. No declaration-only variant was integrated.
Event `18e6b0dc040d1540e607378ab14446c9cb7b8b8df99ab144cd3c591785a7e83f` preserves the complete corrected lab.
The first, incorrect-profile lab remains preserved as tool-defect evidence.
