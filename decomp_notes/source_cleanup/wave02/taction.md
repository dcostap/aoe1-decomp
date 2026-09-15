# TACTION.cpp source-cleanup report

## Module and commits

- Module: `src/taction.cpp`
- Worker slot: 35
- Source registry: `config/functions/src/taction.cpp.json`
- Header owner: owner 04, `include/taction.h`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `99bf26e41ba7628dae428e84c95e7f40298dd5ae`
- Final full hash for the cleaned source: `99bf26e41ba7628dae428e84c95e7f40298dd5ae`
- The report is a later report-only commit. The delivery response gives that commit hash.
- Changed files:
  - `src/taction.cpp`
  - `decomp_notes/source_cleanup/wave02/taction.md`

The source registry lists five normal functions. It sets the module flags to `gx`.
All five registry entries were `matching` before this name-only cleanup.

## PDB inspection

Evidence came from `inventory/pdb/scoped_symbols.json` and the five function
inventories. The PDB source is `C:\msdev\work\age1_x1\TACTION.cpp` and the
PDB object module is `.\\Release\\TACTION.obj`.

| VA | Function | PDB parameters | PDB locals/statics | PDB registers | Result |
| --- | --- | --- | --- | --- | --- |
| `004D38E0` | `TRIBE_Action::TRIBE_Action(int, RGE_Action_Object*, int)` | `infile` (`int`, `+0x4`), `obj_in` (`RGE_Action_Object*`, `+0x8`), `do_setup` (`int`, `+0xc`) | None | `this` in `ecx`, `TRIBE_Action*` | Recovered all three names |
| `004D3980` | `TRIBE_Action::TRIBE_Action(RGE_Action_Object*, int)` | `obj_in` (`RGE_Action_Object*`, `+0x4`), `do_setup` (`int`, `+0x8`) | None | `this` in `ecx`, `TRIBE_Action*` | Recovered both names |
| `004D39E0` | `TRIBE_Action::setup(int, RGE_Action_Object*)` | `infile` (`int`, `+0x4`), `obj_in` (`RGE_Action_Object*`, `+0x8`) | None | `this` in `ecx`, `TRIBE_Action*` | Recovered both names |
| `004D3A00` | `TRIBE_Action::setup(RGE_Action_Object*)` | `obj_in` (`RGE_Action_Object*`, `+0x4`) | None | `this` in `ecx`, `TRIBE_Action*` | Recovered the name |
| `004D3A10` | `TRIBE_Action::create_action_list(RGE_Action_Object*)` | `obj_in` (`RGE_Action_Object*`, `+0x4`) | None | `this` in `ecx`, `TRIBE_Action*` | Recovered the previously unnamed parameter |

The PDB has no function statics or procedure-scoped locals for these five
functions. The compiler-generated vector deleting destructor at `004D3950`
is not a handwritten owner and is not registered in this source module.

The inventory confirms the original boundaries and direct targets. The first
constructor calls `RGE_Action::RGE_Action` at `00407460` and `setup` at
`004D39E0`. The second constructor calls the base constructor at `004074C0`
and `setup` at `004D3A00`. `create_action_list` allocates `0x0c` bytes and
calls `TRIBE_Action_List::TRIBE_Action_List` at `004D0150`.

## Name recovery

Recovered original PDB names:

- `mode` -> `infile` in the three-argument constructor and the two-argument `setup`.
- `object` -> `obj_in` in the three-argument constructor and both constructors' setup calls.
- `doSetup` -> `do_setup` in both constructors.
- The unnamed `create_action_list` parameter is now `obj_in`.

No invented local or parameter names were needed. No public function, class,
member, global, type, scope, or ABI name changed. The `obj_in` parameter in
`create_action_list` remains unused because the original body constructs the
list from `this->obj`.

There are no uncertain reused-stack-slot mappings. The PDB records map each
source parameter directly to one stack slot.

## Constants, resources, and comments

No constants were replaced. The cleanup preserves the zero arguments, the
`do_setup != 0` tests, the allocation size `0x0c`, call order, casts, and
`this->obj` access. No new constant declaration is requested.

This module has no resource IDs, resource lookup calls, strings, language
selection, or resource arithmetic. Therefore no per-ID text, missing block,
empty slot, language, lookup path, purpose, or proposed cleanup name applies.
No missing or empty resource entry is claimed. No resource extraction was run.

No source comments were added. These five wrappers have no non-obvious
lifetime, unit, sentinel, or compatibility fact that needs a source comment.

## Evidence hashes

- `inventory/pdb/scoped_symbols.json`: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- `inventory/functions/004D/004D38E0_TRIBE_Action.txt`: `44ae9a608b03b11fd8e18f3c864d937929cef7468db092f9356e1aadaa2cba7d`
- `inventory/functions/004D/004D3980_TRIBE_Action.txt`: `63e97246474b11a5e8de9e26eda78076477359bcf58df4ee1ff9f484eca6fa11`
- `inventory/functions/004D/004D39E0_setup.txt`: `7b267a790b1f49c72de356b80374d99e0896f86500e5f4c2b65aaf2e8e31c2e8`
- `inventory/functions/004D/004D3A00_setup.txt`: `76c63567f2b29d985539ee5d8a5c5580fb83cc1fd9551554a11f63a1d9866146`
- `inventory/functions/004D/004D3A10_create_action_list.txt`: `d4adc00e774e27563745bfb35e110da12af9d180b012a15985ea89e69d300283`
- Original `XPack/empiresx.exe`: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Preserved baseline `taction.obj`: `baa0afac0cc0b9b8b27fe9cab9c6a29225526d8abed411f491bd2c247b00db8d`
- Preserved baseline `empiresx.exe`: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Code-generation risks and shared requests

The source change only changes parameter identifiers and gives one unused
parameter its recovered PDB name. It does not change types, declarations,
storage, expressions, evaluation order, control flow, calls, literals, or
layout. The output is expected to remain unchanged, but no compiler or object
comparison was run.

Request to owner 04: name the parameters in `include/taction.h` with the same
recovered spellings: `infile`, `obj_in`, and `do_setup` for the constructors and
`setup` overloads, plus `obj_in` for `create_action_list`. This request changes
only declaration readability. This worker did not edit the header.

No request is needed for `include/resource_ids.h` or `include/game_globals.h`.

## Validation and unresolved questions

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, game, or runtime command was run.

No function-specific mapping question remains. The header parameter names are
pending owner 04 review. Final validation must still compare generated code,
program data, relocations, and call targets with the preserved baseline.
