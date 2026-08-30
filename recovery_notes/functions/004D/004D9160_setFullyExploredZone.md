# 004D9160 `setFullyExploredZone`

## Current source model

The function uses the canonical `TribeInformationAIModule` layout.
It calls `md->object(param_1)`. A non-null object supplies its current zone.
The function stores `(unsigned char)param_2` in `fullyExploredZoneValue[zone]`.
The source uses direct member access and a local `unsigned char zone`.

## Binary facts

- Original body: 59 bytes and 17 instructions.
- The body has two direct calls: `object` then `currentZone`.
- The null guard and return boundary match the original.
- The original store is `mov [ecx+esi+308h],dl`.
- The current build emits the equivalent `mov [esi+ecx+308h],dl`.

## Validation

A fresh current-module check reports 58 equal bytes and one changed byte:

- Original offset `+0x32`: `31`.
- Rebuilt offset `+0x32`: `0e`.
- Class: `CONSISTENT_REGISTER_RECOLOR`.
- Owner, size, frame, calls, relocations, CFG, and boundaries match.

The current source is natural and behavior-equivalent. Direct checks with pointer
aliases, explicit member qualification, an explicit base pointer, pointer
arithmetic, and an unsigned integer zone did not improve the SIB byte.
Direct parameter reassignment changed the instruction shape and was rejected.

An older isolated legacy-context check matched. That context used a foreign
`TribeMainDecisionAIModule` view. The current module note rejects that layout.
Do not restore that context or add a carrier to force the old encoding.

## Result and next step

Result: natural reconstruction with one-byte code-generation drift.

The mismatch is a narrow accepted-drift candidate. The calls, targets, order,
arguments, guard, store, and fault order remain equal. The coordinator must
review any accepted-drift status. A later grouped audit should confirm that
registered `taiinfmd` neighbors remain unchanged.
