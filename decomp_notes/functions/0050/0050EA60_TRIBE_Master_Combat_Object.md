# Function notes: 0050EA60 `TRIBE_Master_Combat_Object`

## Earlier notes from `decomp_notes/functions/0050/0050EA60_TRIBE_Master_Combat_Object.md`

This section is historical. Use the status query for current state.

## 0050EA60 TRIBE_Master_Combat_Object

PDB owner: `tm_co_ob.cpp:44-47`.

The file constructor calls the file base constructor with a zero setup flag. It calls the derived file setup when `do_setup` is nonzero.

The executable has an exception frame. The module keeps `/GX` in its response file.
