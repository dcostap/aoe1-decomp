# Function notes: 0050EB60 `setup`

## Earlier notes from `decomp_notes/functions/0050/0050EB60_setup.md`

This section is historical. Use the status query for current state.

## 0050EB60 setup

PDB owner: `tm_co_ob.cpp:73-107`.

Body: `[0050EB60,0050EC85)`.

The function calls the base setup, sets `master_type`, and reads three six-byte cost records. It then reads build points, building ID, and button location.

When `save_game_version >= DAT_0057677c`, it reads `orig_pierce_armor` and returns. Older data computes piercing armor and base armor from the armor records.
