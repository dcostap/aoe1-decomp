# `dstring.cpp` source-cleanup report

## Commits and scope

- Module: `src/dstring.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `986fab8535da9f9b3cb9546de4bd759e07545e62`
- Branch: `cleanup/staging-20260915-195`
- Changed files: `src/dstring.cpp`; this report.
- Header owner: `include/dstring.h` remains unchanged.
- Registry: `config/functions/src/dstring.cpp.json`; build flags `gx_no_fpo`.
- The registry assigns 50 normal PDB functions to this source module.

Evidence uses these absolute main-tree paths:

- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dstring.cpp.json`
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  (SHA-256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`)
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/`.
  The exact `<VA>_*.txt` packet for every VA in the coverage list below was inspected.
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  (SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`)
- Preserved baseline object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/dstring.obj`
  (SHA-256 `75d2d7db2f03893f3640efb1bf662dda942f0d55546580fbbf0eb860c881f276`)

The local extraction records are under this worktree's ignored `build/dstring_evidence/`:
`pdb_records.json` contains all 50 scoped records, and `packet_asm.txt` contains the
packet metadata and original assembly for all 50 registry VAs. No original asset was copied.

## Original-name recovery coverage

I inspected the procedure-scoped PDB parameters, locals, registers, and types for
all 50 functions. The PDB records `this` in `ecx` for member functions. Names below
are recovered PDB names. A function marked “this only” has no source parameter or
named local record. Hidden `__$ReturnUdt` records are compiler return storage, not
source declarations.

- `004465D0` `DString::DString()`: this only.
- `00446620` copy constructor: parameter `d`.
- `00446690` `DString(const char*)`: parameter `s`.
- `00446700` destructor: this only.
- `00446710` `operator<<`: parameters `out`, `d`.
- `00446730` `operator>>`: parameters `in`, `d`; local `buffer`.
- `00446780` `DString::operator=(const char*)`: parameter `s`.
- `00446800` `DString::operator=(const DString&)`: parameter `d`.
- `00446880`, `004468E0`, `00446930` equality overloads: parameters `one`, `two`.
- `00446980`, `004469E0`, `00446A30` inequality overloads: parameters `one`, `two`.
- `00446A80`, `00446AE0`, `00446B30` less-than overloads: parameters `one`, `two`.
- `00446B80`, `00446BE0`, `00446C30` greater-than overloads: parameters `one`, `two`.
- `00446C80` `DString::operator+`: parameter `d`; local `newStr`.
- `00446D10` `DString::operator[]`: parameter `i`.
- `00446D30` conversion to `char*`: this only.
- `00446D40` `length`: this only.
- `00446D50` `index`: this only.
- `00446D60` `contains(DString)`: parameter `s`.
- `00446DE0` `contains(const char*)`: parameter `s`.
- `00446E00` `numWords`: this only.
- `00446E90` `word`: parameter `num`; local `rStr`.
- `00446FD0` `nextWord`: parameter `incIndex`; local `rStr`.
- `004470B0` `moveToFirstWord`: this only.
- `004470C0` `moveToNextWord`: this only.
- `00447140` `subString`: parameters `start`, `count`; local `rStr`.
- `004471F0` `append`: parameter `d`.
- `004472D0` `stripTrailing`: parameter `c`.
- `00447370` `stripLeading`: parameter `c`.
- `00447400` `asInt`: this only.
- `00447410` `asDouble`: this only.
- `00447420` `uppercase`: this only.
- `00447460` `asUppercase`: local `rStr`.
- `004474E0` `lowercase`: this only.
- `00447520` `asLowercase`: local `rStr`.
- `004475A0` `change`: parameters `o`, `n`.
- `004475D0` `DKeyString::DKeyString()`: this only.
- `00447620` two-argument `DKeyString` constructor: parameters `k`, `v`.
- `004476A0` `DKeyString` destructor: this only.
- `004476F0` `key`: this only.
- `00447710` `setKey`: parameter `k`.
- `00447760` `value`: this only.
- `00447780` `setValue`: parameter `v`.

The source restores all listed PDB parameter and local names. This includes the
mixed styles `incIndex`, `newStr`, and `rStr`, and the terse names `d`, `s`, `c`,
`o`, `n`, `k`, and `v`. The equality, inequality, ordering, stream, conversion,
word, substring, case, and DKeyString overloads retain their original function
symbols and source order.

## Locals and unresolved mappings

The PDB has no standalone local record for these source locals:

- `numWords`: `cached`, `index`, and the new cleanup name `in_word`.
- `word`: `word_count`, `index`, `in_word`, and `start`.
- `nextWord`: `i` and `start`.
- `subString`: `text` and `copied`.
- `append`: `i`, the new cleanup name `base_len`, and `text`.
- `stripTrailing`, `stripLeading`, `uppercase`, and `lowercase`: `index`.
- `change`: `i`.

The former descriptive names `inWord`, `wordCount`, and `baseLen` were not backed by
scoped PDB records. They became `in_word`, `word_count`, and `base_len` under the
snake_case rule for invented names. Existing concise locals remain unchanged. The
PDB records for `newStr` and `rStr` are direct evidence, so those mixed spellings
remain unchanged.

The hidden `__$ReturnUdt` records occur in UDT-returning procedures. They describe
ABI return storage and were not mapped to source locals. No reused stack slot was
used to force a declaration mapping. No type, scope, storage duration, declaration
order, or evaluation order changed.

## Source changes and packet evidence

The source changes only identifier spellings:

- Restore PDB parameter names in all applicable definitions.
- Restore PDB local `rStr` in `asUppercase` and `asLowercase`.
- Use `in_word`, `word_count`, and `base_len` for three unsupported descriptive
  locals.

I inspected the original assembly, source line span, boundary, and call structure
in the packet for every registry VA. The reviewed packet VA sequence is:

`004465D0`, `00446620`, `00446690`, `00446700`, `00446710`, `00446730`,
`00446780`, `00446800`, `00446880`, `004468E0`, `00446930`, `00446980`,
`004469E0`, `00446A30`, `00446A80`, `00446AE0`, `00446B30`, `00446B80`,
`00446BE0`, `00446C30`, `00446C80`, `00446D10`, `00446D30`, `00446D40`,
`00446D50`, `00446D60`, `00446DE0`, `00446E00`, `00446E90`, `00446FD0`,
`004470B0`, `004470C0`, `00447140`, `004471F0`, `004472D0`, `00447370`,
`00447400`, `00447410`, `00447420`, `00447460`, `004474E0`, `00447520`,
`004475A0`, `004475D0`, `00447620`, `004476A0`, `004476F0`, `00447710`,
`00447760`, `00447780`.

No call target, literal, control flow, cast, `this->` use, or executable statement
changed. Existing accepted-drift status for `append`, `uppercase`, and `lowercase`
was not changed.

## Constants, resources, and comments

No numeric constant, enum, SDK symbol, resource ID, or lookup was added or renamed.
No resource DLL was inspected because this module has no resource lookup. No runtime
resource file was copied or changed. No new source comment was needed. The existing
allocation, character classification, string, and stream calls remain unchanged.

## Shared-file request

The owner of `include/dstring.h` should update declaration-only parameter spellings
to match the recovered PDB names. Keep all types, calling conventions, public names,
layouts, and declaration order unchanged. The requested mappings are:

- `DString(const DString& d)` and `DString(const char* s)`.
- Stream operators: `out, d` and `in, d`.
- Assignment operators: `s` and `d`.
- All comparison overloads: `one, two`.
- `operator+(const DString& d)` and `operator[](int i)`.
- `contains` overloads: `s`; `word(int num)`; `nextWord(int incIndex)`.
- `subString(int start, int count)`; `append(DString d)`.
- `stripTrailing(char c)`; `stripLeading(char c)`; `change(char o, char n)`.
- The two-argument `DKeyString` constructor: `k, v`; `setKey(DString k)`;
  `setValue(DString v)`.

This request changes declaration names only. No shared constant or resource-ID request
is open.

## Code-generation effects, unresolved questions, and validation

The source diff changes identifier spelling only. It does not change types, layouts,
storage, source order, calls, literals, control flow, or symbol identity. A future
compiler may emit different debug names. No executable code or program-data effect
is expected from these edits by source inspection, but generated-output validation
remains required after integration.

The only open source question is whether the PDB-absent locals have period-source
names. The cleanup keeps them concise and does not claim them as recovered originals.
The header-name request remains with its assigned owner.

`git diff --check` passed during diff review. Compilation, matching, audits, and tests
were not run, as required for this cleanup wave.
