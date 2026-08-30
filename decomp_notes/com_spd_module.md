# com_spd source module

Source module: `C:\\msdev\\work\\age1_x1\\com_spd.cpp`.

The module now owns all 27 normal PDB owners in address and source order.
The compiler-facing source is `src/com_spd.cpp`.
The normal declarations are in `include/com_spd.h`.

The old wrapper, context header, and 27 fragment files were removed.
The translation-unit entry is `com_spd`.
The module metadata lists all 27 owners.

## Validation

The pre-migration grouped audit found 26 registered exact owners.
AnalyzeGameSpeed was unregistered and escaped its original boundary.

The final post-migration grouped audit is `build/audits/com_spd_final4/report.txt`.
It found 26 registered owners and one included accepted-drift owner.
Twenty-six owners report `MATCH` with zero positional diff.
AnalyzeGameSpeed reports a 214-byte mismatch over 455 original bytes.
Its rebuilt body is 450 bytes and uses an 0x8 frame instead of 0xC.
It has zero relocation target mismatches and zero boundary escapes.

AnalyzeGameSpeed remains `accepted_drift`.
Its old 31-probe source record is summarized below.
The module does not claim exactness for this owner.

The final PDB packet is `build/tu_packets/com_spd_final3/com_spd_cpp/packet.txt`.
It confirms 27 normal owners, 26 registered exact owners, and source order.

The final translation-unit entry registers the 26 exact owners.
AnalyzeGameSpeed remains included but unregistered as an accepted-drift owner.

A `TChat*` spelling for the unused handler field was tested.
It changed AnalyzeGameSpeed to a boundary escape, so the proven `void*` spelling remains.

GetLatencyInfo and GetMachineSpeedInfo now use natural string calls.
Both still report `MATCH` in the complete module.
The destructor uses a natural `delete` expression and still reports `MATCH`.

The focused grouped check does not prove semantic equivalence for accepted drift.
Further exact work needs a new source or compiler-context lead for AnalyzeGameSpeed.

## AnalyzeGameSpeed matching record

The prior worker recorded these results before module migration:

- A raw communication cursor gave 419 differing bytes, size 442 versus 455,
  and frame 0x8 versus 0xC.
- Explicit aliases, register hints, and donor standard-library context did not
  improve the result.
- A latency cursor beside the player index reduced the difference to 235 bytes.
- Canonical handler fields and call ABIs restored the correct field ownership.
- Reversing the minimum and maximum declarations selected the wrong registers.
- The best unresolved result at that stage had 235 differing bytes, size 448,
  and frame 0xC. All four calls had the correct target identity.
- SyncTurn and the frame local restored the 0xC frame and branchless absolute
  differences. The result reached 162 differing bytes and size 456.
- Initializing the index before the latency cursor reduced the difference to 154
  bytes. Product order, output aliases, and total-turn forms did not help.
- Array-index terminal stores were codegen-identical. The natural dereference
  stores were kept.
- Follow-up probes tested direct and split total-turn expressions, product order,
  output aliases, receiver aliases, and ABI widths. They stayed at 154 bytes.
- A full Com_hand context changed the frame to 0x8 and widened the difference
  to 214 bytes. It was rejected.
- The exact direct calls are IsHost, IsPlayerHuman, SetFutureSpeedChange, and
  SendSpeedChange. Their ownership and ABI are correct.
- The pre-migration accepted-drift source used the authentic handler fields and
  helper ABIs. Its remaining differences were register coloring and one-byte size.

The context gate proved the PDB module, lines 451-577, class owner, body range
00432DE0-00432FA6, field anchors, and four direct call targets.
## Policy cleanup

`GetRecommendedBufferFrames` now uses typed indexing into `ActualLatency`.
It differs by one byte at `00432D52`. Its status is `scratch`, and its exact
owner registration was removed.

`AnalyzeGameSpeed` now indexes its latency arrays directly. Its status was
already `accepted_drift`.

The grouped policy audit matched all 25 registered exact owners. It found no
comparison errors.

## Interface correction

All `RGE_Communications_Speed` fields are private. The public method list has
33 methods in PDB order. `AdjustLocalSpeed` is protected and follows that list.

The source reads `TCommunications_Handler::current_turn` and
`PlayerOptions.CommandTurnIncrement` in `AdjustLocalSpeed` and
`AnalyzeGameSpeed`.  `TCommunications_Handler` now grants friendship only to
`RGE_Communications_Speed`; this preserves the direct, source-backed access
without making either field public.

The registered group compiles with `python tools/build_function.py --va
00432620 --force`.  Representative owner `00432620` reports `MATCH` and
`0.0000%`.  DirectPlay headers and the import library were restored from the
tracked provider files.  No `basegame.h` change was needed.

## Rebased integration proof

The fresh grouped proof is `build/candidate_tus/com_spd_integration_proof`.
All 25 registered exact owners report `MATCH` and `0.0000%`. The two
unregistered rows remain the recorded scratch and accepted-drift results.
