# Independent review: 0045AE50 TMousePointer

Verdict: **APPROVE (evidence-only result)**

Reviewer: `sa-debf0d9c-r1`
Workflow: matching with reviewers
Worker: `sa-c06cf53d-r1`
Review event: `32d5d9f4b76c4844ab16e9ff6c0ef1fd`
Worktree: `C:/Projects/my_decomps/aoe1_queue_slot_7`
Base and current HEAD: `f73f295fed1113d057c8f7dc68d719c273d38805`
Scope: `src/Mouseptr.cpp`, constructor `0045AE50` only

## Reviewed inputs

- State: `1df5be6c94121e90ff55b2107329e36c8037dbd1c4295bc02b103dbdd05e87ce`.
- Worker run event: `bf213ef992b792bff4131065a52d1fc0b491a7ac8474373ac9bad05eeb0f1de8`.
- Worker report event: `6504751e3af401d0fa928819bd2d0bb12baef32f85adb7b69d2e29f4d66e12a1`.
- Target checkpoint: `20260905T204057.467224Z-390ecbdcc2d15fd46f4c1557ea54bbe1ac4161cf62ce96f169bfbc0c41d82f5f`.
- Compiler input fingerprint: `39bff9686acd6041f8fee0b1a6dc3abef56a956ae1b31b07a7259077cd3ffebf`.
- Source hash: `390ecbdcc2d15fd46f4c1557ea54bbe1ac4161cf62ce96f169bfbc0c41d82f5f`.
- Worker state name: `sa-c06cf53d-r1-0045AE50-baseline`.

The state has one meaningful probe: a fresh assignment baseline. It has no
retained source experiment, candidate patch, exact proposal, or accepted-drift
proposal. The source hash in the state equals the current source hash and the
pinned clean-source checkpoint.

## Proposal decisions

- **Source integration: APPROVE as evidence-only.** Keep the existing natural
  source. Do not add a source change.
- **Status: APPROVE leaving `0045AE50` as `scratch`.** The target is not exact
  and the available evidence does not prove accepted drift.
- **Experiment preservation: APPROVE.** Preserve state `1df5...`, its run and
  report events, referenced objects, and this review. The worker records all
  state and event IDs created in this work period.

## Behavior

The original is a 417-byte `__thiscall` constructor for `TMousePointer`. The
PDB-scoped record proves only `ecx TMousePointer* this` and entry parameter
`+0x4 int MouseModeIn`. It proves no local alias or function static.

The original writes the class fields shown by the dossier. It clears the four
words at `save_rect +0xBC`, copies the zero rectangle to `mouse_rect`,
`cursor_rect`, `new_save_rect`, and `restore_rect`, and leaves
`restore_rect.left` zero. It clears the scalar state and surface pointers,
sets `save_x` and `save_y` to `-32767`, stores the mode at `+0x5C`, sets
`cursor_file_id` to `-1`, clears `cursor_file[0]`, and clears sixteen cursor
pointers with `rep stosd`. It makes one direct `debug_timeGetTime` call with
line `100`, subtracts `36`, and stores `LastDrawTime`. It then clears
`save_area_valid` and `LastddError`.

There is no allocation, vptr write, destructor call, EH frame, or other direct
call. Fault behavior outside the observed execution path is unknown. No
runtime harness or malformed-object test was supplied, so this review does not
approve accepted drift.

## Source and field/layout evidence

`inventory/types/dumps/TMousePointer.txt` gives the reference 0x254 layout:
52 four-byte fields or arrays, six `RECT` objects beginning at `+0xBC`, the
surface pointers at `+0x11C`, and `cursor_file_id` at `+0x250`. The dossier
reports the same fixed size with no offset conflict. `include/Mouseptr.h`
expresses this layout and asserts `sizeof(TMousePointer) == 0x254`.
Neighboring exact `TMousePointer` methods provide additional code-generation
support for the shared declaration and offsets.

The constructor uses typed `RECT` members and a typed `RECT*` alias for the
canonical `save_rect` member. It uses no raw offset, manual vtable, fake ABI,
inline assembly, or artificial volatility. The source is natural and matches
the observed field effects. The generated inventory is reference evidence,
not by itself proof of every source expression.

## Bytes

The worker's authoritative run reports:

- `MISMATCH`, 210 positional differing bytes (50.3597%), 31 spans;
- original/rebuilt size 417/417 and instructions 109/109;
- shape similarity 63.30%, edit difference 198 bytes;
- first mismatch `+000D`, VA `0045AE5D`;
- no frame in either body and saved registers `ebx/esi/edi` in both;
- rebuilt owner `??0TMousePointer@@QAE@H@Z`, owner validation `match`;
- one aligned direct call, target-count gap zero, cleanup eight;
- two of two relocations safely masked, no target mismatch, and no boundary
  escape.

Independent validation with
`python tools/check_function.py --va 0045AE50 --no-build --detail full --call-map --stack-map --block-map-differences`
reproduced the same result. It remains `MISMATCH`; therefore no exact claim is
possible. The strict difference begins in the initial `RECT` store and copy
schedule. The diagnostic class `COPY_OR_FILL_LOWERING` is not equivalence
proof.

## Restoration and closure

`git diff` shows no tracked source, header, flag, registry, inventory, test, or
function-note change from this review or the worker. Current hashes for
`src/Mouseptr.cpp`, `include/Mouseptr.h`, `config/flags/gx.rsp`, and the
Mouseptr registry equal the recorded inputs. `target_session.py status` marks
the pinned clean source as current. No target or dependency candidate patch was
found.

The worker closure artifact uses the same input fingerprint and reports one
compiled `mouseptr` group with 24 normal functions: 20 matching results, three
accepted-drift observations (`0045B560`, `0045BA60`, `0045BE80`), and the
constructor grouped mismatch. It reports no compile errors, relocation target
mismatches, boundary escapes, or changed matching neighbors.

I also ran:

```text
python tools/audit_translation_unit_functions.py --group mouseptr --jobs 1 --output-dir build/review_sa-c06cf53d
```

The fresh report at `build/review_sa-c06cf53d/report.txt` has the same input
fingerprint and the same 20/3/1 closure categories. All 20 matching neighbors
remain `MATCH`; the three accepted-drift owners remain unchanged.

The function note, module note, target session, state manifest, run event, and
closure reports were reviewed. The module note contains historical migration
results; current status comes from the registry and fresh closure report. No
note correction is needed for this evidence-only disposition.

## Integration

Keep `src/Mouseptr.cpp` unchanged. Keep `0045AE50` in `scratch`. Do not add an
exact-match or accepted-drift status proposal. Preserve the worker state and
artifacts before worktree reuse. The remaining supported question is the VC5
initial `RECT` store/copy scheduling basin. Revisit only with new source,
layout, ownership, or compiler-context evidence.

Unknowns are the exact original local aliases, source statement order, and
fault behavior outside the observed call path. These unknowns do not block the
requested evidence-only disposition.
