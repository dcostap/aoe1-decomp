# `campaign.cpp` source-cleanup report

## Delivery

- Module: `src/campaign.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `3f4317178392417903a58fa4364c02d9e16fc0be`
- Report commit: `dc55b87bb95d24da0f8733a172b01e7c56b426e4`
- Changed files:
  - `src/campaign.cpp`
  - `decomp_notes/source_cleanup/wave04/campaign.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\campaign.cpp`
- Registry: `config/functions/src/campaign.cpp.json`
- Header owner: group owner 26 owns `include/campaign.h`.

The source commit contains only the assigned source. The report is committed
as a separate assigned-file commit. The worker response reports the final
branch commit hash copied from Git.

## Evidence checked

I inspected all nine assigned procedure packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423230_RGE_Campaign.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423330_RGE_Campaign.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423480_RGE_Campaign.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004234B0_create_file.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423690_open_scenario.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423710_get_name.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423720_scenario_number.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423730_scenario_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004237A0_get_scenario_name.txt`

The packet hashes, in the same order, are:

- `d5fa3fcdcdbea22b32452550b903835f86ceb7260b0c0b248388bb3340e82913`
- `8fe37d0383dd75756d1c535a9598ecd0050376ba8faaa36af49ca54b581c58ba`
- `c19cc6cc5d50196d9c6deccb1ceb1faaed26dac89bdd2a254b3300824303af60`
- `e1fde5f1c08a4ab641a35807bdacc0f15a989ca84a48d9aa2733649d3b2aba07`
- `52a0df2f3d2be265a37af0a7017f7fc630abb3056602e4fee569de508fd8081d`
- `b0972551ed6161e587592e19bd19e811f2541676cfe066cf99fe00b1569ac910`
- `26e6f1d5a6da61546918719c2e4c89dc0122e629791a93a98e25fb8efe681936`
- `8da8b86ffbe4b4a7b04105ba3deac538d42140a46512b3a0060a2964a0d52099`
- `4283c92ef68d90aea166d12acf51c16b5323add6b02c9f93b8875d39c615c6bf`

The complete scoped-symbol inventory is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`,
SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The source map is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`,
SHA256 `aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
The original PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`,
SHA256 `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

I also inspected the original executable evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/campaign.cpp.asm`,
  SHA256 `cc81be3396e0f487349bb41fcf2039ee3552da587a03fafa06f4b6e4c78abf70`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/campaign.cpp.decomp`,
  SHA256 `79e4bcf99624e385acfd0d985ed32fd7592926401258093bec8f07b7d071532f`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The type evidence records `RGE_Campaign_Header` as `0x108` bytes and
`RGE_Scenario_Offset` as `0x208` bytes. It comes from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/RGE_Campaign_Header.txt`,
  SHA256 `a2e1b08360c13cab3fe541f29156e97bb81c454597f8a5d3aea88d2be049b006`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/RGE_Scenario_Offset.txt`,
  SHA256 `7675ce7f5bcd9509d1856721fcf9ee573f1a81b9a98464c520c674ba7e635120`.

## Complete PDB coverage and name recovery

The PDB packet covers every registered function in source order:

| VA | Function | PDB lines | Records | Names used in source |
| --- | --- | ---: | ---: | --- |
| `00423230` | `RGE_Campaign::RGE_Campaign(char*)` | 22-54 | 14 | `in_filename` |
| `00423330` | `RGE_Campaign::RGE_Campaign(char*, char*, long, char**, char**)` | 65-90 | 15 | `campaign_filename`, `campaign_name`, `scenario_num`, `scenarios`, `scenarios_name` |
| `00423480` | `RGE_Campaign::~RGE_Campaign()` | 94-100 | 5 | no parameters or locals |
| `004234B0` | `RGE_Campaign::create_file()` | 104-169 | 14 | `handle`, `index`, `current_offset`, `tempname` |
| `00423690` | `RGE_Campaign::open_scenario(long)` | 175-193 | 8 | `scenario` |
| `00423710` | `RGE_Campaign::get_name()` | 198-200 | 2 | no parameters or locals |
| `00423720` | `RGE_Campaign::scenario_number()` | 205-207 | 2 | no parameters or locals |
| `00423730` | `RGE_Campaign::scenario_info(char***)` | 212-223 | 7 | `scenario_names` |
| `004237A0` | `RGE_Campaign::get_scenario_name(long)` | 227-229 | 2 | `num` |

Every procedure also has the `this` register in `ecx`. No function static is
recorded for any assigned procedure.

The recovered original names are:

- `00423230`: `param1` became `in_filename`.
- `00423330`: `param1`, `param2`, `count`, `names`, and `filenames` became
  `campaign_filename`, `campaign_name`, `scenario_num`, `scenarios`, and
  `scenarios_name`.
- `004234B0`: `fd` became `handle`; `output_offset` became `index`.
  The PDB names `handle`, `index`, `current_offset`, and `tempname` match the
  file handle, serialized output offset, scenario index, and path buffer uses.
- `00423690`: `index` became `scenario`.
- `00423730`: `list` became `scenario_names`.
- `004237A0`: `index` became `num`.

The PDB records `index` and `current_offset` in `create_file` as `long`.
The existing source declarations are `int`. I preserved those declarations
in this naming and presentation pass. Their 32-bit width matches the existing
source behavior, but the source-type difference remains unresolved.

The PDB does not provide direct names for the existing `handle` local in the
first constructor, the `scenario_file`, `size`, and `buffer` locals in
`create_file`, the `h` local in `open_scenario`, or the `strings`, `i`, and
constructor-loop `i` locals. I retained those existing descriptive names and
did not force a stack-slot mapping. No new local name was invented.

## Constants, resources, comments, and formatting

I read the pinned VC5 headers before replacing file-I/O literals:

- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H`, SHA256
  `4ccffd15f6f3e0570a0e455f1ab6b8fc81d37dac647185ebcd1d2196052c74d2`,
  defines `_O_BINARY` as `0x8000`, `_O_WRONLY` as `0x0001`, `_O_CREAT` as
  `0x0100`, and `_O_TRUNC` as `0x0200`.
- `C:/Program Files (x86)/DevStudio/VC/Include/SYS/STAT.H`, SHA256
  `f3e310d37d7cb0ab758482054bc0ebe12391a8ab08ed2d832792412c0642d7c0`,
  defines `_S_IREAD` as octal `0000400` and `_S_IWRITE` as octal `0000200`.
- `C:/Program Files (x86)/DevStudio/VC/Include/STDIO.H`, SHA256
  `b8347d1031e2425177c047a69121adffa39d41932c38c95a45b71c1c59378652`,
  defines `SEEK_END` as `2` and `SEEK_SET` as `0`.

The source now uses `_O_BINARY` for binary opens. It uses
`_O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY` for the original `0x8301`
create mode. It uses `_S_IREAD | _S_IWRITE` for the original `0x180` mode.
It uses `SEEK_END` and `SEEK_SET` for the existing seek origins. These macros
preserve the original numeric values and argument types.

The source keeps `0x108` and `0x208` for serialized header and scenario-record
lengths. The type records above prove those lengths. It keeps the existing
casts, field accesses, call order, buffer sizes, sentinels, and file-failure
behavior.

No resource ID or resource lookup occurs in this module. No DLL was inspected,
so there are no resource hashes, language records, text records, or resource
mapping requests for this module.

The existing incomplete CRT/helper comment was completed. Function braces now
use 1TBS placement. No executable statement or declaration was reordered.

## Header requests and unresolved questions

Please route this non-blocking parameter-name request to the owner of
`include/campaign.h`:

- `RGE_Campaign(char* filename)` to `RGE_Campaign(char* in_filename)`.
- The five-parameter constructor to `campaign_filename`, `campaign_name`,
  `scenario_num`, `scenarios`, and `scenarios_name`.
- `open_scenario(long index)` to `open_scenario(long scenario)`.
- `scenario_info(char*** list)` to `scenario_info(char*** scenario_names)`.
- `get_scenario_name(long index)` to `get_scenario_name(long num)`.

These are declaration-name changes only. They do not change types, layouts,
calling conventions, decorated symbols, or interfaces. No resource-ID request
was made. The `create_file` local type difference noted above needs a separate
review if source-type restoration is required.

## Code-generation and validation limits

The edits change identifiers, include directives, macro spellings, comments,
brace placement, and wrapping. They do not change public symbols, function
boundaries, control flow, expression order, casts, storage, field layout, or
call targets. The new file-I/O macros expand to the original values. Final
compiler-output review is still required for code-generation proof.

Compilation, matching, audits, and tests were not run. I did not run a build,
validation command, or game. I reviewed the complete Git diff and ran only
non-build evidence inspection and `git diff --check`.
