# tcommand module recovery

`src/tcommand.cpp` owns the 42 normal `tcommand.cpp` functions in PDB order.
`include/tcommand.h` owns `TRIBE_Command` and its wire records. The source
uses canonical Command, Player, World, object, action, Master Building, Effects,
and Status Message providers.

The source has no context header, wrapper, fragment include, copied foreign
class, manual vptr, or raw packet buffer. Its wire records use natural alignment.
Each record has a size check. Variable packets locate serialized IDs after their
fixed typed header.

## Current direct result

`build/tcommand_complete_audit/result_submission_final/report.json`
checks all 42 normal owners. It reports 22 exact owners. Every registered owner
reports `MATCH` and `0.0000%`.

The exact owners are:

- `00509720`, `00509770`, `00509910`, `0050A010`, and `0050A140`;
- `0050A510`, `0050A730`, `0050A7B0`, `0050A7F0`, `0050A860`, `0050A8D0`,
  and `0050A940`;
- `0050AD00`, `0050ADF0`, `0050AE40`, `0050AEE0`, `0050AF30`, `0050AF80`,
  and `0050AFD0`; and
- `0050B0D0`, `0050B130`, and `0050B3E0`.

## Nonexact functions

Natural packet records change these owners. They stay `scratch`:

- `00509980`, `00509AF0`, `00509C60`, `00509E10`, `0050A1D0`, and `0050A490`;
  and
- `0050A9B0`, `0050AB30`, `0050AC70`, `0050B020`, `0050B190`, `0050B230`,
  `0050B290`, and `0050B330`; and
- `0050AA90`.

The module has no accepted-drift owner. `0050A4C0`, `0050A6A0`, `0050A6E0`,
`0050AA90`, `0050AD70`, and `0050AE80` are scratch. No durable localized
equivalence proof supports accepted drift. The grouped report has boundary
escapes for `0050AA90`, `0050AD70`, and `0050AE80`.

`0050A1D0` calls `RGE_Effects::do_effect(short, RGE_Player*)`. Original code
calls the Effects vslot at `+0x08`. Do not add `show_effect`.

## Provider facts

`TRIBE_Command` derives from the canonical `RGE_Command` class. `Command.h`
now has only its own records and class. `Command.cpp` includes provider headers
privately.

`00509C60` and `00509E10` use `TRIBE_Master_Building_Object`. The source gets
that type from `tm_b_obj.h`.

The explicit `00509C60` comparison in the release report is a 43-byte
mismatch. It remains scratch. An older isolated exact source used copied
provider types. It is not valid canonical evidence.

`00509980` and `00509AF0` install actions through `set_only_action`. That
virtual slot is `+0x208`. `RGE_Action_List` owns `add_action`.

`0050A1D0` constructs `TRIBE_Screen_Status_Message` at `004B7140`. The source
uses `scr_stms.h`.
