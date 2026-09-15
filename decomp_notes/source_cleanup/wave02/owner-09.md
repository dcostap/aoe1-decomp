# Owner 09 object support cleanup

## Scope

- Group: object support
- Integration branch: `cleanup/staging-20260915-73`
- Common base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Reviewed pre-ledger head: `63a9b5f131980c3363093102be9c3ad025ea9477`
- Sources: `ani_obj`, `dpl_obj`, `misl_obj`, `mst_play`, `obj_list`, `t_tre_ob`, `tm_co_ob`, and `tm_tre_o`
- Owner headers: the eight matching module headers under `include/`

All source results remain reviewed but unvalidated.

## Worker and integration ledger

Each worker started from the common base above.

| Module | Worker | Worker head | Worker commits | Integrated commits |
| --- | --- | --- | --- | --- |
| `ani_obj` | `sa-8dba77e9` | `60960ce037765a5b2a33840d53ceb37e555ba81a` | `60960ce037765a5b2a33840d53ceb37e555ba81a` | `e2d261227117c8cd1a9784da7b20abd32b1a2bd3` |
| `dpl_obj` | `sa-4a6351ee` | `1a1fdfb1b49513e4f537c2623994cd80fc8e7166` | `fe8f045787e24b1b0e3d71093bd20e7772015111`, `6a37505c54a8bc6507195bc62ab165e1cd069bd2`, `01519a497f253d227525c5297bee1f734c948664`, `924bfa7b9fa0f715818a7af51fee8d12d0c74a2c`, `1a1fdfb1b49513e4f537c2623994cd80fc8e7166` | `30ef9e660bc1a2b8d3c42ed1623f629858d456d1`, `21dbd02fff91fd03194732633cca30a2a702bba6`, `89896561270f5bc9f33ae11638fe1ab11376579f`, `e9dc50cd5f64c8457dd4f380e0d010846f048cc7`, `63a9b5f131980c3363093102be9c3ad025ea9477` |
| `misl_obj` | `sa-c8483713` | `ca19bf4fd1b997b98304d6b7b0638d2ee1468eb4` | `f441095319a3eaf0afb70bffe8efb9f307b7b988`, `776f3792e1c1db0e9b4baac210579c7f1e63a1b3`, `ca19bf4fd1b997b98304d6b7b0638d2ee1468eb4` | `a5766b553bcf1d545190bb5af62e6013712770e3`, `295a91138f4fe3a78478213891ead3530a6f0e8d`, `525c051209c16e20b3c884ea05107c2099e6e4b2` |
| `mst_play` | `sa-508e8dd6` | `47153fc0da17f350fe72675191f19315f6431ca4` | `404c5ae46a6d9cdeccaabde8fdccc474bba9071e`, `47153fc0da17f350fe72675191f19315f6431ca4` | `8f171accf70ec61a80734d38ef3e22628161dd17`, `3558f5d8acfa3af75f728504affc51c8769885c6` |
| `obj_list` | `sa-b6c043fe` | `5faf4b73ee81e5388a18ebfad491017bab8d4ddd` | `5a7fdc9ed62feccf56e1b80dcc1b1aab8dcd87da`, `f2950dc5afc5cbf7a223bf82849668cb75d1059a`, `5faf4b73ee81e5388a18ebfad491017bab8d4ddd` | `6165bf22f2897d21b078291e952b65ed89363938`, `295886c709b2d5fae9b29c3e9352d96b0f385906`, `851c20b0a14e8482ec1382434ed7c0fc067e6d84` |
| `t_tre_ob` | `sa-9765b9a0` | `3976fd30e2ca5f452dbc8a957dd987480436eff3` | `42fbc0dcc7b5c4b1965aec9800a62e13d3837ec4`, `3976fd30e2ca5f452dbc8a957dd987480436eff3` | `b04283a73c97261f47f9adb98e8ca226726eb302`, `ddab9a1530de992395bf36dc1c58d7cf69670145` |
| `tm_co_ob` | `sa-860ef223` | `5f785ef61bb31107f813d8920516df90e260f7e8` | `b4b519fc44306fa380166c8b2903632415c7ce5a`, `5f785ef61bb31107f813d8920516df90e260f7e8` | `7d4853dbd23a8df31acc7a45769566abcae4e076`, `923e6da5fcd3c7ab7f1043fdaddd149f8558718e` |
| `tm_tre_o` | `sa-d1683c85` | `19de7fe720397b1b8b282d88bd36da1745f52676` | `2a8e3fafee1050bd115c6fbd7a12264d208e401d`, `19de7fe720397b1b8b282d88bd36da1745f52676` | `d02dafc380991349dec21e3b8cb289737ea79765`, `7e5c5cca0ff6d731efb0c9472226ecbe613a60ad` |

Owner header commit: `bbda14d8cb5026148b5d6450a6f018affda5df76`.

## Name mappings

All listed recovered names come from procedure-scoped PDB records.

- `ani_obj`: restored `tobj`, `obj_owner`, `infile`, `gworld`, `outfile`, `obj`, `work_obj`, `action_type`, `attack_flag`, and `caller`.
- `dpl_obj`: restored parameter names and the mixed-style names `theObj`, `UMV_addr`, `Unified_Map_Value`, `TLast_Map_Value`, and `TObject_ids`.
- `dpl_obj`: added clear local names such as `new_node`, `map_addr`, `map_value`, `check_value`, and `owner_id`.
- `misl_obj`: restored `tobj`, `obj_owner`, `infile`, `gworld`, `outfile`, `launcher`, `target`, `in_range`, `delta`, `x1`, `x2`, and `check_list`.
- `mst_play`: restored file names, `obj_type`, and the safe `temp_*` mappings in the text constructor.
- `obj_list`: restored all recorded drawing, search, state, file, distance, and result names.
- `t_tre_ob`: restored `tobj`, `obj_owner`, `infile`, `gworld`, `do_setup`, and `new_object_state`.
- `tm_co_ob`: restored constructor, setup, modification, save, and object-owner parameter names.
- `tm_tre_o`: restored `other_object`, `infile`, `in_id`, and `owner`.

The owner headers now use supported PDB parameter names. No header type or declaration order changed.

## Review findings and corrections

I read every complete worker diff and report against the common base.

The first `dpl_obj` result did not use 1TBS for all definitions. I resumed the same worker.

The correction added commits `924bfa7b9fa0f715818a7af51fee8d12d0c74a2c` and `1a1fdfb1b49513e4f537c2623994cd80fc8e7166`.

The accepted result uses 1TBS. It also updates its report for the formatting change.

The combined review found no edits outside assigned sources, reports, and owner headers.

The combined header review found name-only declaration changes. It found no type, layout, value, macro, or symbol changes.

The source review found identifier and formatting changes only. It found no new helpers, assembly, structural rewrites, or resource substitutions.

`git diff --check` passed for each accepted worker head. It also passed for the combined group diff.

## Unresolved evidence

- `ani_obj`: the PDB does not name five existing `update` locals.
- `dpl_obj`: `save` has reused `outfile` and `long_val` storage roles. The source mapping remains unchanged.
- `dpl_obj`: the PDB `x` record in `perform_doppleganger_checks` uses reused storage. The loop name remains `i`.
- `misl_obj`: several clear traversal locals have no PDB names. The `x2` stack home also has reuse evidence.
- `mst_play`: `finish_init` has an `obj_type` stack record with a conflicting source type. The existing `int temp` remains.
- `obj_list`: many traversal and sorting locals have no PDB names. Existing descriptive names remain.
- `tm_co_ob`: `temp_flag` and `temp_button_location` overlap parameter homes. The unusual existing aliases remain.
- `tm_tre_o`: decompiler exception slots have no source-local PDB mapping.

Opaque object-type and mask literals remain numeric. The checked evidence did not prove shared names for them.

## Requests

No shared resource-ID request is pending. These modules contain no resource lookup changes.

No cross-group header request is pending. Owner 09 applied all supported name-only header changes.

## Validation status

No compiler, build, matching, audit, test, or game command ran.

Evidence inspection and full Git diff review ran. Final executable validation remains pending at the root stage.
