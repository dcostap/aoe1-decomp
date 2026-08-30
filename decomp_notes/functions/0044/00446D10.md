# Function notes: 00446D10 `operator[]`

Module notes: `decomp_notes/dstring.md`.

## Recovered attempt history

<!-- recovered:97b23bd5cec5fe62a2a3 -->
### `8d5bfd4ccae9` `src/scratch/00446D10_operator.cpp:1-55`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tried char* return with if(index<0||length<index+1) and return base+index; still loaded arg into edx
// tried the exact `-1 < index && index + 1 <= length` spelling; still loaded arg into edx
// tried the inverted fail-return form; still loaded arg into edx
// tried a named base temp; still loaded arg into edx
// tried a named index temp; still loaded arg into edx
// tried split fail checks instead of one combined condition; no register change
// tried `register int index`; still loaded arg into edx
// tried char& return with `*this->stringValue` fallback; signature turned out wrong for this packet
// tried `return *(index + this->stringValue);`; still loaded arg into edx
// tried `return index[this->stringValue];`; still loaded arg into edx
// tried `return *(&this->stringValue[0]);` and `return *(&index[this->stringValue]);`; still loaded arg into edx
// tried a `char* result;` temp with if/else assignment; still loaded arg into edx
// tried a custom /O1 rsp; build shape broke on size mismatch, rolled back
// tried flipping the success return to `index + this->stringValue`; VC5 still loaded arg into edx
// tried the full char& rewrite in both declaration and definition; VC5 still loaded arg into edx
// Probe A tried: `*(index + this->stringValue)`; still loaded arg into edx
// Probe B tried: `*(this->stringValue + index)`; still loaded arg into edx
// tried a named length temp; VC5 still loaded the arg into edx and moved the length load earlier
// tried a named reference for the success return; VC5 still loaded arg into edx
// tried split fail checks again in the correct char& form; VC5 still loaded arg into edx
// tried explicit address-of on the indexed lvalue; still loaded arg into edx
// tried the array-ref spelling `index[this->stringValue]`; still loaded arg into edx
// tried a named reference to that array-ref result; still loaded arg into edx
// tried a named reference from explicit pointer-add; VC5 still loaded arg into edx
// tried a named bound temp `bound = index + 1`; VC5 still loaded arg into edx and split the fail path
// tried a delayed base temp after the checks; VC5 still loaded arg into edx
// tried a plain named result with `this->stringValue[index]`; VC5 still loaded arg into edx
// tried delayed base + named result; VC5 still loaded arg into edx
// tried a dummy TU with neighboring DString accessors in the same source file; still loaded arg into edx
// tried a single merged pointer ternary under one final dereference; still loaded arg into edx
// kept the merged-pointer idea and switched to `-1 < index && index + 1 <= length`; compare/jump shape changed, but VC5 still loaded arg into edx
// tried a fuller DString declaration context with the inventory layout and nearby method declarations; rebuilt the same as the merged-pointer success-form probe and still loaded arg into edx
// tried parameter normalization `if (bad) index = 0; return this->stringValue[index];`; fail path became `xor edx,edx`, but VC5 still loaded arg into edx
// tried ternary on the integer offset inside the array subscript; this was the closest so far: entry `mov eax,[esp+4]`, `test eax,eax`, `lea edx,[eax+1]`, `cmp esi,edx`, but VC5 still inserted `mov edx,eax` before `mov eax,[ecx]`
// tried a local `i = index` with normalization; kept the eax entry load but added `mov edx,eax` and `inc eax`
// tried `if/else` offset assignment into a local; same near-match shape as the offset ternary
// tried split `else if` normalization on the parameter; still loaded arg into edx
// tried success-first then fallback-to-zero forms; still loaded arg into edx
// tried normalized pointer-add returns; still loaded arg into edx
// tried a base temp with normalized index; kept the eax entry load but pulled the base into edx early and added extra pushes
// tried two separate `if` normalizations on the parameter; still loaded arg into edx
// tried the offset ternary through explicit dereference; same near-match shape as the offset ternary array form
// tried a local `i` with split checks; still added `mov edx,eax` and `inc eax`
// tried the normalized-parameter family with `long` fields; no change
// tried `off` locals with ternary / `if (bad)` assignment; either the same near-match shape or the same `mov edx,eax` / `inc eax` variant
// tried assigning the parameter from a ternary before indexing; VC5 collapsed back to the edx-carried normalization shape
// tried nested ternaries and staged assignments; codegen got worse with setcc/and patterns or extra pushes
// tried fail-return `this->stringValue[index = 0]`, direct `goto fail` returns, and comma-side-effect forms; they either stayed in the edx-loaded family or the near-match offset-ternary family
// tried `register` locals and `char&` references on the offset-ternary form; same near-match shape
// tried `#pragma optimize("t", on)`, `#pragma optimize("g", on)`, and `#pragma optimize("y", on)` around the best offset-ternary form; no change
// tried round-5 final-expression probes: `*(off + base)`, `*(base + off)`, `off[base]`, `&this->stringValue[0]` bases, and `*(char**)(&this->stringValue)` indirection; every direct `off`-based form collapsed to the same near-match with `mov edx,eax`
// tried pointer-ternary and pointer-temp forms where both arms were explicit `0 + base` / `index + base`; those all fell back to the old edx-loaded family
// leaving this in scratch because exhaustive probing only produced two stable families: an edx-carried normalization shape, or a near-match offset-ternary / offset-pointer-add shape that still inserts `mov edx,eax` and lengthens the fail jump
// kept the direct member + offset-selection array form because it is the closest known source: it preserves the eax entry load and the `index + 1` compare basin
// remaining mismatch is localized to the final success-path bridge-through-edx and slightly longer fail jump, so this looks like codegen/context drift rather than unresolved logic
```
<!-- end-recovered:97b23bd5cec5fe62a2a3 -->
