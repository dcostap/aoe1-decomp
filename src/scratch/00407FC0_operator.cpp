// Attempt log (sa-252ef273, 00407FC0): the natural BaseItem wrapper reproduces
// the 24-byte body and call shape. VC5 emits a decorated external operator==
// relocation, while the checker requires the original direct target identity.
// A C-linkage declaration changes that relocation to _== but does not solve it.
// Keep the natural C++ declaration until a supported symbol-binding method is
// available; do not replace this direct call with a helper or inline assembly.
class BaseItem;

int __cdecl operator==(BaseItem const& lhs, BaseItem const& rhs);

int __cdecl operator!=(BaseItem const& lhs, BaseItem const& rhs) {
    return !operator==(lhs, rhs);
}
