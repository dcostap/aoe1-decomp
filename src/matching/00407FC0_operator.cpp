// The original packet preserves the BaseItem operator== decorated identity.
// The reviewed symbol override lets the checker validate this natural wrapper.
class BaseItem;

int __cdecl operator==(BaseItem const& lhs, BaseItem const& rhs);

int __cdecl operator!=(BaseItem const& lhs, BaseItem const& rhs) {
    return !operator==(lhs, rhs);
}
