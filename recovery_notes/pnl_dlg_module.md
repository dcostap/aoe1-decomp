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
