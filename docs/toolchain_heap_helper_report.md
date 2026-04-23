# Toolchain CRT heap helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/00550BE0_heap_init.txt`
- `inventory/functions/0055/00550C17_FUN_00550c17.txt`
- `inventory/functions/0055/00550C57_FUN_00550c57.txt`
- `inventory/functions/0055/00550C66_FUN_00550c66.txt`
- `inventory/functions/0055/00550C90_sbh_new_region.txt`
- `inventory/functions/0055/005513B0_sbh_resize_block.txt`

## Goal

Audit the CRT small-block heap neighborhood and classify only the entries supported by
high-confidence runtime evidence.

## High-confidence conclusions

### 1) The named small-block heap routines are toolchain/runtime code

This neighborhood is clearly CRT heap-management machinery.

Strong evidence:

- named entrypoints such as `__heap_init`, `___sbh_new_region`, `___sbh_release_region`,
  `___sbh_decommit_pages`, `___sbh_find_block`, `___sbh_free_block`,
  `___sbh_alloc_block`, `___sbh_alloc_block_from_page`, and `___sbh_resize_block`
- direct use of `HeapCreate`, `HeapAlloc`, `HeapDestroy`, `VirtualAlloc`, and `VirtualFree`
- state names in listing excerpts like `__crtheap` and `___small_block_heap`
- no PDB source information

This is standard VC CRT allocator internals, not project-authored gameplay code.

### 2) `FUN_00550c17` is hidden `__heap_term`

High-confidence evidence:

- the listing excerpt directly labels the body `__heap_term`,
- it walks `___small_block_heap`, frees committed regions with `VirtualFree`,
- and destroys `__crtheap` with `HeapDestroy`.

Strict conclusion:

- toolchain-supplied,
- safest classified by exact VA region because the inventory name is still `FUN_...`.

### 3) `FUN_00550c57` and `FUN_00550c66` are hidden threshold accessors for the same CRT heap system

High-confidence evidence:

- listing excerpt labels:
  - `FUN_00550c57` as `__get_sbh_threshold`
  - `FUN_00550c66` as `__set_sbh_threshold`
- both operate on `___sbh_threshold`
- both are immediately adjacent to `__heap_term` and `___sbh_new_region`
- both have no signs of game-specific logic

Strict conclusion:

- toolchain-supplied,
- safest classified by exact VA region.

## Applied classification

Added toolchain-supplied region:

- `00550C17-00550C8D`
  - hidden `__heap_term`
  - hidden `__get_sbh_threshold`
  - hidden `__set_sbh_threshold`

## Exact-name additions

This pass also adds safe exact-name CRT entries to the manifest generator:

- `__heap_init`
- `_set_new_handler`
- `_query_new_handler`
- `__callnewh`

## Bottom line

This neighborhood is unequivocally CRT heap/runtime machinery.

Strict classification:

- named heap/runtime entrypoints -> `toolchain_supplied` by exact name
- hidden adjacent helpers -> `toolchain_supplied` by exact VA region
