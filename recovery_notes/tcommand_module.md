# tcommand module recovery

`src/tcommand.cpp` owns the 42 normal `tcommand.cpp` functions in PDB order.
`include/tcommand.h` owns `TRIBE_Command` and its wire records. The source
uses canonical Command, Player, World, object, action, Master Building, Effects,
and Status Message providers.

The source has no context header, wrapper, fragment include, copied foreign
class, manual vptr, or raw layout carrier.

## Current direct result

`build/tcommand_direct_preflight/result_exact30/report.json` reports 30 exact
owners. Every registered owner reports `MATCH` and `0.0000%`.

`0050A140 TRIBE_Command::do_command_explore` now matches in the direct source.
It is an exact owner.

The 29 other exact owners are:

- `00509720`, `00509770`, `00509910`, and `0050A010`;
- `0050A510`, `0050A730`, `0050A7B0`, `0050A7F0`, `0050A860`, `0050A8D0`,
  `0050A940`, and `0050A9B0`;
- `0050AB30`, `0050AC70`, `0050AD00`, `0050ADF0`, `0050AE40`, `0050AEE0`,
  `0050AF30`, and `0050AF80`; and
- `0050AFD0`, `0050B020`, `0050B0D0`, `0050B130`, `0050B190`, `0050B230`,
  `0050B290`, `0050B330`, and `0050B3E0`.

## Nonexact functions

Natural composition changes these owners. They stay `scratch`:

- `00509980`: one byte;
- `00509AF0`: one byte;
- `00509C60`: ambiguous overload selection in the observed report;
- `00509E10`: 11 bytes;
- `0050A1D0`: 363 bytes; and
- `0050A490`: one byte.

The six reviewed accepted-drift owners remain `accepted_drift`:
`0050A4C0`, `0050A6A0`, `0050A6E0`, `0050AA90`, `0050AD70`, and `0050AE80`.

`0050AA90` also has ambiguous overload selection in the observed report.

`0050A1D0` calls `RGE_Effects::do_effect(short, RGE_Player*)`. Original code
calls the Effects vslot at `+0x08`. Do not add `show_effect`.

## Provider facts

`TRIBE_Command` derives from the canonical `RGE_Command` class. `Command.h`
now has only its own records and class. `Command.cpp` includes provider headers
privately.

`00509C60` and `00509E10` use `TRIBE_Master_Building_Object`. The source gets
that type from `tm_b_obj.h`.

`0050A1D0` constructs `TRIBE_Screen_Status_Message` at `004B7140`. The source
uses `scr_stms.h`.
