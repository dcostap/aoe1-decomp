# scr_stms.cpp source recovery

The PDB module owns five `TRIBE_Screen_Status_Message` methods. The source
order is `004B7140`, `004B7330`, `004B7500`, `004B7560`, and `004B7580`.

The vector deleting destructor at `004B7310` is compiler generated. It has no
handwritten source body.

The screen header owns only `TRIBE_Screen_Status_Message`. It uses canonical
screen, panel, text, BaseGame, and global owners.

The constructors copy current panel metadata when callers supply the sentinel
pair. They select `scr2` or `scr3` when no info file exists. Both constructors
then create the message text panel.

The direct grouped check matches all five owners with zero byte differences,
zero relocation differences, and zero boundary escapes. The generated
vector-deleting destructor also matches.
