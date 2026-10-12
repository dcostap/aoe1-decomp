# `taicrule.cpp` wave 03 cleanup report

## Delivery

- Module: `src/taicrule.cpp`
- Branch: `cleanup/staging-20260915-116`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `9056ef3731fd7561c183bb38b75b9c142160c662`
- Changed files: `src/taicrule.cpp`; this report
- Assigned header: `include/taicrule.h` (read only; owner 13 controls it)
- Registry: `config/functions/src/taicrule.cpp.json`
- PDB source: `C:\msdev\work\age1_x1\taicrule.cpp`

The source commit contains the source cleanup. The report commit follows it.
The delivery response gives the full report commit hash.

## Evidence reviewed

I used these direct main-root evidence files:

- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/taicrule.cpp.json`
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- Original packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/`
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  - SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Preserved baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Preserved baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/taicrule.obj`
  - SHA256 `e048283262b557e4f2d1cdb68c0674f3ba65cc0a9ae87b0203d691640b0343d6`

I inspected all five registry-selected packets:

- `004D68D0_CombatRuleSystem.txt` — SHA256
  `e5e39d73d799bba9c502ecfdb9800c9a626a5ee6a9504504f1ea839d99f34cc5`
- `004D6900_CombatRuleSystem.txt` — SHA256
  `ca85d7000a1b757634457fb6b9f0a4365ea0e248dfc61d0fe4eabaa9c483155a`
- `004D6910_loadRules.txt` — SHA256
  `b54daa7e55bda889556ebd27827c9e93a8f92feccaf65b1d7683686f4bfbe748`
- `004D6AA0_bestUnitTypeToAttack.txt` — SHA256
  `b75ff522b53562bb117ce90f45902c27059da8e3f53385fbc93f5e14ed6a020c`
- `004D6AB0_bestUnitTypeToDefendAgainst.txt` — SHA256
  `d0f0815da7b05c802b77fd03a14335bf77777c8ded263b60b8cd06a77f93bbe7`

The packets prove the five source boundaries, calls, line spans, and direct
assembly. The class header supports the 0x9C8-byte object and 2500-byte table.

## Original-name recovery coverage

The registry selects five normal procedures. Every procedure has a scoped PDB
record. Each record has `this` in `ecx` with type `CombatRuleSystem*`.

| VA | Function | Scoped PDB names and result |
| --- | --- | --- |
| `004D68D0` | `CombatRuleSystem::CombatRuleSystem` | No stack names. The source has no local names. |
| `004D6900` | `CombatRuleSystem::~CombatRuleSystem` | No stack names. The source has no local names. |
| `004D6910` | `CombatRuleSystem::loadRules` | Parameter `rName` (`char*`) at `+0x4`. Locals `temp` (`char[256]`), `commentTemp2` (`char`), `commentTemp1` (`char`), `targetUnitType` (`int`), `unitIndex` (`int`), and `rating` (`int`). The source now uses every one of these recovered names. |
| `004D6AA0` | `CombatRuleSystem::bestUnitTypeToAttack` | Parameter `tType` (`int`) at `+0x4`. The source now names the parameter `tType`. |
| `004D6AB0` | `CombatRuleSystem::bestUnitTypeToDefendAgainst` | Parameter `tType` (`int`) at `+0x4`. The source now names the parameter `tType`. |

The `loadRules` mapping follows the packet assembly. The first parsed integer
is `rating`, and the code checks it against 0 and 50. The second is `unitIndex`,
which forms the table offset. The third is `targetUnitType`, which is stored as
a byte. The two comment bytes map to `commentTemp1` and `commentTemp2` in
scan order. The PDB type and use agree for every mapping.

The source changes recover these original names:

- `filename` became `rName` from the `004D6910` parameter record.
- `line` became `temp` from the `004D6910` `char[256]` record.
- `a` became `unitIndex` from its table-index use and the PDB record.
- `b` became `targetUnitType` from its byte-store use and the PDB record.
- `c` became `rating` from its range-check use and the PDB record.
- `c1` became `commentTemp1` from the first `%c` destination.
- `c2` became `commentTemp2` from the second `%c` destination.
- The unnamed attack parameter became `tType` from the `004D6AA0` PDB record.
- The unnamed defend parameter became `tType` from the `004D6AB0` PDB record.

`FILE* f` has no scoped PDB stack or register name. The packet shows its file
handle in `ESI`, but that does not establish a source name. The source keeps
`f`. It is not claimed as an original or invented rename. No declaration was
reshaped to force a stack-slot mapping.

The nearby `004D68E0` scalar deleting destructor is compiler generated. It has
no handwritten source owner. It was not edited.

## Constants, resources, and comments

No numeric constant changed. The source keeps the original values and types for
`256`, `2500`, `50`, `'2'`, `'/'`, `0`, and `-1`. No established symbol proved a
better replacement. No resource lookup occurs in this module. No resource ID,
DLL, language, text, fallback path, or resource request applies.

No source comment was added. The null check after `strcmp` is preserved. The
source does not repair that original fault order. No comment was needed because
the recovered names explain the local behavior without adding a new claim.

## Code-generation and behavior-sensitive review

The source changes are identifier recovery and presentation only. They do not
change types, declaration scope, storage duration, class layout, ABI symbols,
casts, expression order, calls, literals, function boundaries, or control flow.
The local declaration order remains `temp`, `f`, the three integer locals, and
the two comment bytes. The source keeps the existing `FILE*` declaration and
all existing statements.

The opening brace now follows the `loadRules` signature. The local declarations
are split for readability. These changes can alter debug line records. The
registry already marks `loadRules` as `accepted_drift`; this cleanup does not
reopen that result. No generated-code comparison was run.

## Shared-file requests and unresolved questions

I did not edit `include/taicrule.h`. No type, layout, ABI, or shared constant
request is needed. Owner 13 may align its declaration-only parameter spellings
with the recovered source names if desired:

```cpp
int loadRules(char* rName);
int bestUnitTypeToAttack(int tType);
int bestUnitTypeToDefendAgainst(int tType);
```

The header's current parameter names do not affect the source definition or ABI.
No root-owned header request exists. No resource mapping request exists. The
only unresolved mapping is the source name of `FILE* f`, as noted above. No
other unresolved question remains.

## Validation and limits

I reviewed the complete Git diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, runtime harness, or resource extraction was run.
