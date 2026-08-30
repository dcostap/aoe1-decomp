# Function notes: 00462EA0 `~RGE_Object_List`

## Earlier notes from `decomp_notes/functions/0046/00462EA0_RGE_Object_List.md`

This section is historical. Use the status query for current state.

## 00462EA0 RGE_Object_List destructor

The cleanup loop reads `list->next`, frees that node, then writes it to `list`.

Keep this sequence. Do not replace it with a normal node-free loop.
