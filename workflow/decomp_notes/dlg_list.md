# dlg_list.cpp module recovery

The PDB assigns six source-ordered normal owners to `TListDialog`.
The direct module uses `src/dlg_list.cpp` and `include/dlg_list.h`.

The source has no wrapper, fragment include, copied base layout, context macro,
or raw field cursor. It uses canonical dialog, panel, button, list, and
scrollbar owners.

The canonical Panel_ez declaration keeps PDB overload order. The long button
overload comes before the character overload. The text overloads are integer,
character-array, then character.

Candidate validation matched five normal owners and the generated destructor.
`0043EF80` remains scratch. It differs by three bytes, without a relocation
mismatch or boundary escape. The mismatch is a direct result of the PDB-proven
overload order. The source remains natural.
