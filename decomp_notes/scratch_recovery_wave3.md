# Scratch recovery wave 3

## Scope

The final accepted-drift audit leaves 67 scratch functions.
The final report classifies 17 as boundary problems and 50 as grouped mismatches.
This wave starts with ownership and boundary recovery.
It then processes behavior-risk and ordinary mismatch targets.

Do not reduce the scratch count without proof.
A completed target must become natural exact source, approved accepted drift,
a proved corpus reclassification, or a documented unresolved result.

Base commit: `c17a9da2c`.

Reference report:
`build/validation/final-accepted-drift-wave2/report.json`.

## Boundary batch

| Module | Targets |
| --- | --- |
| `basegame` | `0041E920 setup_graphics_system` |
| `com_q` | `00431D30 GetSpecificItem` |
| `m_co_obj` | `00450450 setup` |
| `pnl_scbr` | `0047AB20 set_tab_pos` |
| `point` | `0047E5D0 rotateXYByFacet` |
| `taiinfmd` | `004D6BB0`, `004DE600`, `004DEA80`, `004E2D10` |
| `taitacmd` | `004F57C0`, `00502310`, `00503070` |
| `taiuaimd` | `00504750 processNotify` |
| `tplayer` | `00518090 setupMinoan` |
| `view` | `00533AF0`, `00533E10` |
| `world` | `00542750 new_game` |

The `spanlist` assignment runs beside this batch because `DecodeLine` has a proved malformed-write counterexample.
Each module assignment includes every other scratch owner in that natural source file.

## Decision rules

1. Prove the original owner and boundary before byte tuning.
2. Review complete behavior before source edits.
3. Preserve malformed-input, exception, fault, and return-address effects.
4. Integrate exact source only when the form is natural and closure-safe.
5. Approve drift only after complete observable behavior proof.
6. Keep a documented scratch result when a real gap remains.
7. Preserve all experiments, including failed and rejected states.

## Later batches

After boundary integration, rank the remaining grouped mismatches as follows:

1. Proved corruption, exception, return-address, or dispatch risks.
2. Small natural exact candidates with complete behavior evidence.
3. Large control-flow and construction recoveries.
4. Ordinary scheduling differences with unresolved linked identities.

Run affected closures after each integration group.
Run whole-project validation after shared changes settle.

## Integrated results

- `0047E5D0 XYZ::rotateXYByFacet` is now `matching`.
  A natural expression reduction matches all 147 bytes and removes two boundary escapes.
- `0047E530 XYZ::operator+` remains scratch because invalid-reference fault order differs.
- `004BDEA0 AddShape`, `004BEAD0 DecodeLine`, and `004BEB10 take_snapshot` remain scratch.
  The unchecked DecodeLine write can corrupt differently ordered saved-register slots.
  No caller contract excludes the counterexample.
