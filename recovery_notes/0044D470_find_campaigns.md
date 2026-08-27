# 0044D470 find_campaigns

The function uses the standard `_finddata_t` and a 260-byte filename local.

Their declaration order preserves the 0x220-byte file-search work window.

The second campaign scan tests `_findnext` before it increments the index.
