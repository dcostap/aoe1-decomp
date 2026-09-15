# `src/act_make.cpp` cleanup report

## Delivery

- Module: `src/act_make.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Initial source cleanup commit: `b5511ca6d957be5203454d7442c5e3886f207071`
- Presentation correction commit: `8dcd3a2b5789d911a9a23a1e12715c10648fa0db`
- Final source commit: `8dcd3a2b5789d911a9a23a1e12715c10648fa0db`
- Changed files:
  - `src/act_make.cpp`
  - `decomp_notes/source_cleanup/wave01/act_make.md`
- Header read but not changed: `include/act_make.h`

The source keeps the PDB source order for all five normal owners. The source
module is `C:\\msdev\\work\\age1_x1\\ACT_make.cpp`.

The full source commit sequence is
`b5511ca6d957be5203454d7442c5e3886f207071`, then
`8dcd3a2b5789d911a9a23a1e12715c10648fa0db`.

## Function coverage and names

| VA | Function | Name coverage and evidence |
| --- | --- | --- |
| `004049B0` | `RGE_Action_Make(int, RGE_Action_Object*)` | Renamed `param_1` to recovered `infile` and `param_2` to recovered `obj_in`. The PDB stack records at `+0x4` and `+0x8` give these names and types. |
| `00404A10` | `RGE_Action_Make(RGE_Action_Object*, RGE_Task*)` | Renamed both generated names to recovered `obj_in` and `task_in`. The PDB stack records at `+0x4` and `+0x8` give these names and types. |
| `00404A40` | `first_in_stack(unsigned char)` | Added recovered parameter name `first_time`. The PDB stack record at `+0x4` gives this name and type. The parameter remains unused. |
| `00404A70` | `set_state(unsigned char)` | Renamed `param_1` to recovered `new_state`. The PDB stack record at `+0x4` gives this name and type. |
| `00404A90` | `update()` | Renamed `old_attribute_amount` to recovered `pre_attribute`. The PDB local record gives `pre_attribute` at offset `-0x4`. The original listing stores the amount held before the update at `[ESP+0x14]`, then subtracts it from the post-call amount. The PDB local record gives `work` at offset `-0x8`; the existing `work` name was retained. |

The PDB register record names `this` in every normal owner. No register name
changed. The local `attribute_type` in `first_in_stack` has no PDB local
record. It is an existing inferred name, not a recovered original name. No
other declaration mapping is forced.

The compiler-generated vector-deleting destructor at `004049E0` and scalar
destructor tail jump at `00404A00` have no PDB source records. The source adds
no destructor body. The nearby `004049FE` thunk/padding record is also outside
handwritten source ownership.

## Constants, resources, and comments

No new constant or resource macro was added. Existing literals remain because
no shared declaration proves their effective type and meaning for this module:

- `0x15` is the action type used by `RGE_Action_List` case `21`.
- `6` and `1` are action states. No established state enum exists in the
  assigned headers.
- `0x24` indexes the owner attribute array. No established attribute-index
  symbol exists for this use.
- `0x7E` is a `RGE_Base_Game::notification` event code, not a direct string
  lookup. `TRIBE_Game::notification` handles it by playing sound `0x10` and
  adding the notification location.

Resource extraction checked the notification value, but it did not prove a
string mapping for this call:

- `runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`,
  language `0x0409`, ID `0x007E`, payload `10`.
- `runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`,
  ID `0x007E` missing.
- Original `XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`,
  ID `0x007E` missing.

The `10` payload is not used by the notification call as a string ID. No
resource name is proposed. No source comment was added. The code has no
comment need that names and types cannot address.

## Risk and open items

The source cleanup changes identifier spellings and presentation only. The
presentation correction moves opening braces and joins one signature line. It
does not change types, storage, declaration scope, statement order, calls,
casts, layout, or ABI symbols. The unused `first_time` name follows the PDB
without changing its use. The update still has the broad structural drift
recorded in `decomp_notes/act_make.md`. This cleanup does not attempt that
separate code-generation issue.

Header owner 01 should update `include/act_make.h` parameter names to match the
recovered PDB records:

```cpp
RGE_Action_Make(int infile, RGE_Action_Object* obj_in);
RGE_Action_Make(RGE_Action_Object* obj_in, RGE_Task* task_in);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
```

These are declaration-name changes only. They do not change the ABI. No
resource-ID request or root-owned header request is open.

Compilation, matching, audits, and tests were not run.
