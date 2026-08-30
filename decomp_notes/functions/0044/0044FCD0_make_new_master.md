# Function notes: 0044FCD0 `make_new_master`

## Earlier notes from `decomp_notes/functions/0044/0044FCD0_make_new_master.md`

This section is historical. Use the status query for current state.

## 0044FCD0 `RGE_Master_Animated_Object::make_new_master`

- PDB source: `m_an_obj.cpp`, lines 119 to 121.
- Original size: 98 bytes.

The original allocates 0xBC bytes. It calls the copy constructor at 0044F9C0.

### Module merge

The fragment used a fallback `TRIBE_Master_Combat_Object` receiver when it
compiled alone. The merged source uses the PDB owner class. It removes that
fallback and its context macro.

The packet recorded a zero positional-byte count with a `MISMATCH` result.
The merged module now gives `Result: MATCH` and `0.0000%` through
`check_function.py`.
