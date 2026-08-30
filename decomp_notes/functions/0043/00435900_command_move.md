# Function notes: 00435900 `command_move`

Module notes: `decomp_notes/Command_module.md`.

## Recovered attempt history

<!-- recovered:45e9a0b060feaa1adda3 -->
### `target-session` `build/target_sessions/00435900_command_move.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 layout; result=MATCH; diff=0; shape=100.0: Tested a typed compact master-name view at +8 for integer move logging.
```
<!-- end-recovered:45e9a0b060feaa1adda3 -->

<!-- recovered:5b7793e529114e48f9bb -->
### `5835ec86ae37` `src/scratch/00435900_command_move.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00435900 RGE_Command::command_move
// PDB: Command.cpp lines 1586-1628
// Modeled after matched command_stop packet-copy/log/submit topology.
// 2026-05-31: Probed guard order, src locals/register hints, int-vs-float x/y, typed packet,
// top-declared locals, and a 240-variant lab over local/store/class surfaces. Competitive
// variants collapse to the same 192B shifted-alignment basin: VC5 colors arr in EBP and
// size in EDI, while the original colors arr in EDI and size in EBP.
```
<!-- end-recovered:5b7793e529114e48f9bb -->
