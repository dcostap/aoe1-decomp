# Function notes: 00430570 `get_weapon_range`

Module notes: `decomp_notes/com_obj_module.md`.

## Recovered attempt history

<!-- recovered:6ed05961750b9742bbe2 -->
### `target-session` `build/target_sessions/00430570_get_weapon_range.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Baseline isolated wrapper emitted pointer ABI; verify after authentic float-reference declaration.
probe 2 abi; result=MISMATCH; diff=2; shape=77.77777777777777: Authentic PDB ABI: virtual void get_weapon_range(float&, float&); module-local InnerObj fields are float.
probe 3 layout; result=MATCH; diff=0; shape=100.0: Virtual ABI requires a four-byte post-vptr gap so field_8 remains at binary offset 0x8. [same emitted code as probe 1]
probe 4 layout; result=MATCH; diff=0; shape=100.0: Canonical base ownership: getter reads this->master_obj at +0x8 and its float fields at +0x114/+0x140. [same emitted code as probe 3]
```
<!-- end-recovered:6ed05961750b9742bbe2 -->
