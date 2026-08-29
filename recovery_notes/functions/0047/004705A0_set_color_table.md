# 004705A0 `RGE_Player::set_color_table`

## Current source

`src/player.cpp` owns this body in the complete `player.cpp` module. The
current source is:

```cpp
void RGE_Player::set_color_table(unsigned char param) {
    this->color_table = this->world->color_tables[param];
}
```

The source is natural and uses the canonical `RGE_Player` and `RGE_Game_World`
headers. It reads `world` at `+0x3C`, reads `color_tables` at world `+0x64`,
indexes with the low byte of `param`, and stores `color_table` at `+0x108`.
The original owner is `player.cpp`, lines 1415-1417.

## Binary facts

The original body is 27 bytes and has seven instructions:

```text
004705A0  mov edx,[ecx+3Ch]
004705A3  mov eax,[esp+4]
004705A7  and eax,0FFh
004705AC  mov edx,[edx+64h]
004705AF  mov eax,[edx+eax*4]
004705B2  mov [ecx+108h],eax
004705B8  ret 4
```

The current natural source emits the same seven operations and the same
control flow, but it colors the world chain through `EAX` and the index/value
chain through `EDX`:

```text
004705A0  mov eax,[ecx+3Ch]
004705A3  mov edx,[esp+4]
004705A7  and edx,0FFh
004705AD  mov eax,[eax+64h]
004705B0  mov edx,[eax+edx*4]
004705B3  mov [ecx+108h],edx
004705B9  ret 4
```

This adds one byte to the immediate `and` form. The rebuilt body is 28 bytes,
so it reaches one byte past the original boundary. The owner symbol matches.
There are no calls or relocations.

## Tested natural hypotheses

All checks used the pinned Player flags and the complete `src/player.cpp`
translation unit. Every tested form emitted the same 28-byte body. The tests
therefore identify one code-generation basin, not an exact repair.

- Omit explicit `this` qualification.
- Use a local byte index.
- Use the historical `PlayerColorIndex` byte aggregate.
- Bind a local `RGE_Game_World*` receiver.
- Bind a local `RGE_Color_Table**` table array.
- Stage receiver, table array, and selected table locals.
- Use a member reference for `color_table`.
- Use pointer addition, including reversed operand order.
- Use address addition from `color_tables[0]`.
- Cast the index to `unsigned int`.
- Cast the index to `int`.
- Express the low-byte mask in the source.
- Normalize `param` with a byte assignment.
- Normalize `param` with compound masking.
- Bind a reference to the `color_tables` member.
- Use unary `+param` for integral promotion.
- Initialize the byte aggregate in its declaration.
- Name a pointer to the selected table slot.

A variant family tested eleven equivalent forms in one full-source lab. It
produced one group: 11/11 forms emitted 28 bytes with the same register
colors. No form passed the size gate.

The historical isolated wrapper used the same direct operation and an older
local layout. It does not provide a natural source form that changes the
canonical module basin.

## Validation

Target check after restoring the clean natural source:

- `MISMATCH`, 20 differing bytes, 71.4286 percent.
- Original/rebuilt size: 27/28.
- Original/rebuilt instructions: 7/7.
- Frame and saved registers: none/none.
- Calls: 0/0.
- Relocations: 0 mismatches.
- Boundary escapes: 1.
- Diagnostic class: `PARTIAL_REGISTER_RECOLOR`.

Fresh complete-module validation used the registered Player owners and the
compiler-generated deleting destructor. It found 104/105 registered exact
owners. The target is the only registered mismatch. The generated destructor
also matched. The full report is under `build/player_tu_validation/report.txt`.

## Open blocker

No natural source form tested under the canonical header migration restores the
original EAX/EDX colors. The remaining difference appears to be a VC5 register
allocation basin change caused by the migrated translation-unit context. Do not
retain aliases, volatility, pragmas, assembly, or raw offsets only to steer
registers.

Useful next evidence is an authentic pre-migration source or compiler-context
comparison. The direct natural source is restored and remains the clean
unresolved reconstruction.
