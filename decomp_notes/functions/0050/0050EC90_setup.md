# Function notes: 0050EC90 `setup`

## Earlier notes from `decomp_notes/functions/0050/0050EC90_setup.md`

This section is historical. Use the status query for current state.

## 0050EC90 setup

PDB owner: `tm_co_ob.cpp:111-148`.

Body: `[0050EC90,0050ED90)`.

The function reads three cost records. It uses the `id` parameter home for each cost flag and the unused `sounds` parameter home for the last scan value. It then stores that low byte in `button_location`.

The two armor scans preserve the executable's record order and maximum updates.
