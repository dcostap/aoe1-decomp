# ASM corpus exploration report

Date: 2026-04-22

Scope explored:

- `inventory/functions/0056/00564157_FUN_00564157.txt` through the draw neighborhood
- `inventory/functions/0056/0056C680_ASMSet_Shadowing.txt` through `0056DB60_FUN_0056db60.txt`
- `orig/ghidra_decomp/bucket_056A.asm`
- packet Ghidra listing/decompiler excerpts for representative unnamed `FUN_` entries

## Goal

Decide which unnamed `FUN_` entries around the `_ASMDraw_*` neighborhood belong in the
handwritten-assembly corpus instead of the normal manual C/C++ decomp queue.

## Method

I treated an entry as high-confidence asm-corpus material when multiple pieces of
binary evidence agreed:

- no PDB source/line info,
- heavy use of shared draw-state globals at `0088C0xx`,
- indirect dispatch through jump/codelet tables such as `56A700`, `56AB00`, `56B400`, `56B500`, `56B540`, `56BA00`, `56BE00`, `56C200`, `56C600`,
- jumps into the middle of neighboring bodies / labels instead of normal function-call structure,
- nonsensical linear disassembly that clearly looks like table data rather than real C/C++ code,
- tight coupling to named handwritten-asm entrypoints `_ASMDraw_HLine` and `_ASMDraw_Sprite`.

## Conclusions

Yes: thoroughly exploring these unnamed `FUN_` entries is the right way to populate the
asm corpuses.

The exploration shows that the draw neighborhood is much larger than the first-pass
`0056A6DD` region. High-confidence handwritten-asm material spans three practical bands:

1. `00564157-0056B43F`
2. `0056C680-0056C7DF`
3. `0056C7E0-0056DBBA`

That is now reflected in `config/asm_special_regions.txt`.

## Main findings by region

### 1) `00564157-0056B43F` is asm codelet / dispatch-bank territory, not normal C++

High-confidence evidence:

- follow-up pass across `00564157-0056A019` found **170 additional unnamed packets**,
  all with no PDB source and all tail-jumping via `DAT_0088c044`.
- spot-checks from buckets `0564` through `0569` (for example `00564157`, `0056501B`,
  `00566045`, `00567FDE`, `0056802D`, `00568E6C`, `00569023`) all show the same
  draw-codelet shape: tiny fixed copy/xlate/mask fragments that mutate `ESI`/`EDI` and
  chain through `[88C044]` rather than normal call/return structure.
- `0056A01A_FUN_0056a01a`, `0056A0A6_FUN_0056a0a6`, `0056A10D_FUN_0056a10d`,
  `0056A188_FUN_0056a188`, and `0056A210_FUN_0056a210` are real tiny draw codelets.
  They operate directly on pixel bytes/words/dwords, use `EBX` as a translate-table base,
  apply mask/or state from `88C02C/88C030`, and tail-jump via `[88C044]`.
- From `0056A35D` onward the linear disassembly becomes obviously table-like / bad-data-like.
  Representative packets such as `0056A59D`, `0056A69D`, and `0056A6DD` decompile as garbage,
  show impossible control flow, and contain many embedded `0056xxxx` words.
- `0056A6DD_FUN_0056a6dd` is especially strong evidence: many xrefs land in the middle of it,
  and the tail references `switchdataD_0056b400`, `PTR_caseD_0_0056b410`,
  `PTR_caseD_0_0056b420`, and `PTR_caseD_0_0056b430`.
- `_ASMDraw_HLine` dispatches through `56A700`; the supporting tables and codelets live in this band.

Practical conclusion:

- this entire range belongs to the asm restoration lane,
- it should not be treated as normal one-function-one-`.cpp` work,
- and `0056A6DD` was only the most obvious visible tip of a much larger asm bank.

### 2) `0056C680-0056C7DF` is an asm setup/getter/padding micro-cluster

High-confidence evidence:

- Named asm entrypoints live here: `_ASMSet_Shadowing`, `_ASMSet_ShadowingEx`,
  `_ASMSet_Surface_Info`, `_ASMSet_Color_Xform`, `_ASMGet_Color_Xform`, `_ASMSet_Xlate_Table`.
- The unnamed neighbors are not normal C++ helpers. They are either padding-only pseudo-functions,
  hidden getter stubs, or alignment sleds adjacent to the asm API surface.
- `0056C7AD_FUN_0056c7ad` is especially informative: the listing excerpt labels the body as
  `_ASMGet_Xlate_Table`, even though the inventory function name is still `FUN_0056c7ad`.

Practical conclusion:

- all unnamed `FUN_` entries in this band should stay out of the normal C++ queue,
- but they are better treated as `asm_region` than as ordinary manual-match targets.

### 3) `0056C7E0-0056DBBA` is one large handwritten-asm draw interpreter neighborhood

High-confidence evidence:

- `_ASMDraw_HLine` and `_ASMDraw_Sprite` are the front-door entrypoints.
- The unnamed `FUN_` packets immediately below them are not independent C++ functions.
  They are restart labels, opcode handlers, scanline walkers, clipping helpers, and decoder stubs.
- Representative examples:
  - `0056CBAC_FUN_0056cbac`: main forward sprite interpreter/walker using `DAT_0088c03c`,
    `DAT_0088c044`, `DAT_0088c050`, `DAT_0088c054`, and jump tables near `56B400`.
  - `0056D64E_FUN_0056d64e`: second large interpreter/walker for the alternate traversal family.
  - `0056D2F9_FUN_0056d2f9`: outer scanline iteration / sprite-row setup loop.
  - `0056D40A_FUN_0056d40a`: alternate dispatcher using `56B540` and codelet tables such as
    `56B600`, `56BE00`, `56BA00`, `56C200`.
  - `0056DB60_FUN_0056db60`: shared opcode-length / skip decoder called by multiple helpers.
- Several smaller helpers just decode one opcode form, adjust `ESI`/`EDI`, then jump back into a
  shared interpreter label.
- Many packets jump into shared labels like `LAB_0056cc20`, `LAB_0056d420`, `LAB_0056d6c0`,
  or return through the shared continuation pointer in `DAT_0088c044`.
- This is classic handwritten-asm interpreter/codelet-bank structure, not a normal compiler-emitted
  C/C++ function neighborhood.

Practical conclusion:

- all unnamed `FUN_` packets in this band belong in the asm corpus,
- and the first-pass region ending at `0056D505` was too small.
- `0056D506` onward is still the same draw-interpreter family, not a new normal-C++ neighborhood.

## Classification appendix

### A. Codelets / dispatch-bank range: `00564157-0056B43F`

| Inventory entry | Conclusion |
|---|---|
| `00564157_FUN_00564157` | tiny asm draw codelet chaining through `DAT_0088c044` |
| `0056501B_FUN_0056501b` | asm draw codelet with mask/or globals and continuation jump |
| `00566045_FUN_00566045` | asm draw/xlate codelet using `EBX` table lookup and `DAT_0088c044` |
| `00567FDE_FUN_00567fde` | asm draw codelet bridge into the later `0568` bank |
| `0056802D_FUN_0056802d` | asm draw codelet in the `0568` bank |
| `00568E6C_FUN_00568e6c` | asm draw codelet in the `0568` bank |
| `00569023_FUN_00569023` | asm draw codelet in the `0569` bank |
| `0056A01A_FUN_0056a01a` | real asm draw/xlate codelet |
| `0056A0A6_FUN_0056a0a6` | real asm draw/xlate codelet |
| `0056A10D_FUN_0056a10d` | real asm draw/xlate codelet |
| `0056A188_FUN_0056a188` | real asm draw/xlate codelet |
| `0056A210_FUN_0056a210` | real asm draw/xlate codelet |
| `0056A2A7_FUN_0056a2a7` | bridge into mixed codelet/table territory; keep in asm region |
| `0056A35D_FUN_0056a35d` | misdisassembled table/codelet-bank data |
| `0056A387_FUN_0056a387` | misdisassembled table/codelet-bank data |
| `0056A3C7_FUN_0056a3c7` | misdisassembled table/codelet-bank data |
| `0056A407_FUN_0056a407` | misdisassembled table/codelet-bank data |
| `0056A447_FUN_0056a447` | misdisassembled table/codelet-bank data |
| `0056A487_FUN_0056a487` | misdisassembled table/codelet-bank data |
| `0056A4C7_FUN_0056a4c7` | misdisassembled table/codelet-bank data |
| `0056A59D_FUN_0056a59d` | misdisassembled table/codelet-bank data |
| `0056A5DD_FUN_0056a5dd` | misdisassembled table/codelet-bank data |
| `0056A61D_FUN_0056a61d` | misdisassembled table/codelet-bank data |
| `0056A65D_FUN_0056a65d` | misdisassembled table/codelet-bank data |
| `0056A69D_FUN_0056a69d` | misdisassembled table/codelet-bank data |
| `0056A6DD_FUN_0056a6dd` | draw dispatch/data bank; definitely not a normal function |

Note: table A is representative rather than exhaustive. The `00564157-0056A019`
prelude alone contributes 170 additional unnamed codelet packets with the same
high-confidence asm traits.

### B. Setup/getter/padding range: `0056C680-0056C7DF`

| Inventory entry | Conclusion |
|---|---|
| `0056C6B9_FUN_0056c6b9` | padding-only pseudo-function/alignment sled |
| `0056C711_FUN_0056c711` | padding-only pseudo-function/alignment sled |
| `0056C75D_FUN_0056c75d` | padding-only pseudo-function/alignment sled |
| `0056C777_FUN_0056c777` | padding-only pseudo-function/alignment sled |
| `0056C78B_FUN_0056c78b` | padding after `_ASMGet_Color_Xform`; keep in asm region |
| `0056C7AD_FUN_0056c7ad` | hidden getter stub; listing labels it `_ASMGet_Xlate_Table` |
| `0056C7C6_FUN_0056c7c6` | trailing alignment / boundary sludge before `_ASMDraw_HLine` |

### C. Draw-interpreter range: `0056C7E0-0056DBBA`

| Inventory entry | Conclusion |
|---|---|
| `0056CBAC_FUN_0056cbac` | main forward interpreter / clip walker |
| `0056CC03_FUN_0056cc03` | restart/helper entry into forward interpreter |
| `0056CC49_FUN_0056cc49` | short opcode handler in forward family |
| `0056CC6C_FUN_0056cc6c` | larger forward-family opcode/span handler |
| `0056CD0C_FUN_0056cd0c` | short opcode handler in forward family |
| `0056CD45_FUN_0056cd45` | larger forward-family opcode/span handler |
| `0056CDE6_FUN_0056cde6` | larger forward-family opcode/span handler |
| `0056CE99_FUN_0056ce99` | larger forward-family opcode/span handler |
| `0056CF39_FUN_0056cf39` | larger forward-family opcode/span handler |
| `0056CFC4_FUN_0056cfc4` | larger forward-family opcode/span handler |
| `0056D078_FUN_0056d078` | decoder adapter calling `FUN_0056db60` then re-entering forward interpreter |
| `0056D08E_FUN_0056d08e` | short opcode handler in forward family |
| `0056D0B1_FUN_0056d0b1` | short opcode handler in forward family |
| `0056D0CC_FUN_0056d0cc` | short opcode handler in forward family |
| `0056D0FB_FUN_0056d0fb` | short opcode handler in forward family |
| `0056D127_FUN_0056d127` | short opcode handler in forward family |
| `0056D159_FUN_0056d159` | short opcode handler in forward family |
| `0056D186_FUN_0056d186` | larger forward-family opcode/span handler |
| `0056D1D8_FUN_0056d1d8` | larger forward-family opcode/span handler |
| `0056D218_FUN_0056d218` | short forward-family helper |
| `0056D248_FUN_0056d248` | short forward-family helper |
| `0056D265_FUN_0056d265` | medium forward-family helper |
| `0056D2A4_FUN_0056d2a4` | decoder adapter calling `FUN_0056db60` then re-entering sprite interpreter |
| `0056D2F9_FUN_0056d2f9` | outer sprite-row loop / scanline setup walker |
| `0056D40A_FUN_0056d40a` | alternate dispatcher family |
| `0056D431_FUN_0056d431` | short opcode handler in alternate family |
| `0056D44C_FUN_0056d44c` | short opcode handler in alternate family |
| `0056D47B_FUN_0056d47b` | short opcode handler in alternate family |
| `0056D4A7_FUN_0056d4a7` | medium opcode/span handler in alternate family |
| `0056D4D9_FUN_0056d4d9` | short opcode handler in alternate family |
| `0056D506_FUN_0056d506` | short opcode handler in alternate family |
| `0056D558_FUN_0056d558` | short opcode handler in alternate family |
| `0056D598_FUN_0056d598` | short opcode handler in alternate family |
| `0056D5C8_FUN_0056d5c8` | short opcode handler in alternate family |
| `0056D5E5_FUN_0056d5e5` | medium opcode/span handler in alternate family |
| `0056D624_FUN_0056d624` | decoder adapter calling `FUN_0056db60` then re-entering alternate interpreter |
| `0056D64E_FUN_0056d64e` | main alternate interpreter / clip walker |
| `0056D6A4_FUN_0056d6a4` | secondary dispatcher / walker in alternate family |
| `0056D6E9_FUN_0056d6e9` | short alternate-family helper |
| `0056D70C_FUN_0056d70c` | larger alternate-family opcode/span handler |
| `0056D7AD_FUN_0056d7ad` | short alternate-family helper |
| `0056D7E5_FUN_0056d7e5` | larger alternate-family opcode/span handler |
| `0056D887_FUN_0056d887` | larger alternate-family opcode/span handler |
| `0056D93A_FUN_0056d93a` | larger alternate-family opcode/span handler |
| `0056D9DA_FUN_0056d9da` | larger alternate-family opcode/span handler |
| `0056DA65_FUN_0056da65` | larger alternate-family opcode/span handler |
| `0056DB16_FUN_0056db16` | decoder adapter calling `FUN_0056db60` then re-entering alternate interpreter |
| `0056DB2E_FUN_0056db2e` | shared row-advance / loop-termination helper |
| `0056DB59_FUN_0056db59` | padding-only pseudo-function/alignment sled |
| `0056DB60_FUN_0056db60` | shared opcode-length / skip decoder |

## Recommended repo policy outcome

1. Keep these entries out of the normal manual C/C++ queue.
2. Track them via `asm_special` / `asm_region`, not `unclaimed` normal work.
3. Prefer region-based exclusion for these neighborhoods rather than trying to curate a huge
   name list of unstable `FUN_` labels.
4. Preserve the named `_ASM*` front-door functions in `config/asm_special_functions.txt`.
5. Treat the unnamed neighbors as `asm_region` until there is a dedicated asm restoration lane.

## Bottom line

The unnamed `FUN_` packets around `_ASMDraw_HLine` / `_ASMDraw_Sprite` are not stray normal
C++ decomp targets. They are the surrounding handwritten-asm machinery: codelets, dispatch tables,
interpreter restarts, opcode handlers, scanline walkers, and decoder stubs.

So yes: exploring them and writing a conclusion report is exactly how the asm corpuses should be
populated, and the result here is strong enough to justify the larger region-based exclusions now in
`config/asm_special_regions.txt`.
