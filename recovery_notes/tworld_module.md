# TWorld.cpp source module

`src/tworld.cpp` owns all 30 normal PDB bodies from `tworld.cpp`, in source
and address order. The module uses `include/tworld.h` and canonical RGE,
TRIBE, Scenario, Map, Player, and communications owners.

The three scratch bodies remain honest natural reconstructions:
`0052EAC0`, `0052EF30`, and `005303F0`. Their bodies compile in the complete
module and keep the known behavior and call surfaces. They are not exact-owner
claims.

The seven accepted-drift bodies retain their reviewed status. Exact owners are
registered only for the 20 matching bodies. The old prefix and phase wrappers
are migration scaffolds and must not be restored.

The unified source uses typed fields, canonical globals, named string data,
standard CRT declarations, and structured control flow. It has no absolute
address expressions or C-style casts.
