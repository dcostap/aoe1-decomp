# Function notes: 0044D300 `~RGE_Game_Info`

## Earlier notes from `decomp_notes/functions/0044/0044D300_RGE_Game_Info.md`

This section is historical. Use the status query for current state.

## 0044D300 RGE_Game_Info destructor

The destructor uses natural `delete` expressions for each child. VC5 emits each
child destructor call before the scalar allocator call.

The campaign cleanup precedes the person cleanup.
