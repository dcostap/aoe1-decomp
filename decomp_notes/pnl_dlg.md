# pnl_dlg.cpp module recovery

The PDB assigns five source-ordered normal owners to `TDialogPanel`.
The direct module uses `src/pnl_dlg.cpp` and `include/pnl_dlg.h`.

The source has no wrapper, fragment include, copied panel hierarchy, context
macro, or raw layout cursor.

Candidate validation matched the constructor, short setup overload, destructor,
focus forwarder, and generated deleting destructor.

`00473C80` remains scratch. It differs by 213 bytes and crosses the old
boundary.

The natural code preserves setup calls, color ordering, modal updates, and
parent-child updates. Exact repair continues on this canonical source.

The wave20 full audit reports 196 differing bytes for `00473D60 setup`. That
row is now scratch and is no longer registered as exact.

Current worker validation uses compiler fingerprint
`15644a73fea490943cb0bf33bcc702ae10109ebea9391b04331512ba592ef3e0`.
Natural `00473D60` remains `MISMATCH`, 196 bytes, 209/211 bytes, with seven
ordered calls aligned. Natural `00473C80` remains `MISMATCH`, 214 bytes,
229/219 bytes, with eight ordered calls aligned. An unused `pnl_sld.h` include
made `00473C80` exact in state
`3b4674109d639855ad0e177ca40142629135951b5e111e62041509e4fddbbaab`, but it
is compiler-context evidence only and is not retained in source.
