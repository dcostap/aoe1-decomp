# Pnl_inp.cpp module merge

- PDB source: `C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp`.
- Source: `src/Pnl_inp.cpp`.
- Header: `include/Pnl_inp.h`.
- Packet: `build/source_reunification/packet/Pnl_inp_cpp`.

## Source order

The source keeps the 22 normal owners in PDB order:

`00476C10`, `00476CF0`, `00476D80`, `00476EE0`, `00476F20`, `00476F30`,
`00476FA0`, `00477220`, `004777C0`, `00477910`, `00477990`, `004779A0`,
`004779B0`, `004779D0`, `00477AF0`, `00477C90`, `00477CB0`, `00477E90`,
`00477EF0`, `00478010`, `00478150`, `004781A0`.

The normal source module owns `TInputPanel`, `TTextPanel`, and the module-local
panel declarations. The header contains the declarations and layout. The source
contains the function bodies.

The migration removes the old wrapper, per-function `.cpp` includes, context
macros, fallback declarations, and bank fragments. The nearby scalar deleting
destructor at `00476CD0` remains compiler-generated.

## Status

The packet lists 20 matching owners and two scratch owners:

- Scratch: `00476D80` (`setup`) and `00477220` (`key_down_action`).
- Matching: all other normal owners.

The source-shape migration does not claim grouped byte equality. Recheck exact
owners after module recovery.

## Check state

The old grouped registration was `Pnl_inp_cpp_authentic` with
`config/flags/group_009_gx.rsp`. The registered owner paths now point to the
merged source module. Compile and grouped exact checks remain follow-up work.
