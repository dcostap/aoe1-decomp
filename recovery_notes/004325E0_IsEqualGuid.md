# 004325E0 `TCommunications_Sessions::IsEqualGuid`

The source now compares the canonical Windows `GUID` fields in order:
`Data1`, `Data2`, `Data3`, and `Data4[0]` through `Data4[7]`. It uses no raw
pointer aliasing.

The natural typed form is not an exact claim. The current VC5 build reports a
125-byte positional difference and remains `scratch`. It is not registered as
an exact translation-unit owner.
