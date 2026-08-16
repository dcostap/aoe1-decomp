class BaseItem;

int __cdecl operator==(BaseItem const& lhs, BaseItem const& rhs);

int __cdecl operator!=(BaseItem const& lhs, BaseItem const& rhs) {
    return !operator==(lhs, rhs);
}
