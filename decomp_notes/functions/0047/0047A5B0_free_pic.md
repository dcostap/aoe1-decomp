# Function notes: 0047A5B0 `free_pic`

## Earlier notes from `decomp_notes/functions/0047/0047A5B0_free_pic.md`

This section is historical. Use the status query for current state.

## 0047A5B0 TPicturePanel::free_pic

### Exact source evidence before migration

The owner uses local `TPicture*` and `TShape*` aliases for the outer null
checks and destructor calls. It uses member access in the inner ownership
checks. This preserves the redundant null test and the saved pointer register
in VC5 output.

The function clears each pointer and then clears `own_pic`, even when no
object exists. Keep this order during later source recovery.
