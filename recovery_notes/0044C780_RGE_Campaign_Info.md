# 0044C780 RGE_Campaign_Info constructor

The null path calls `strcpy(name, "")`.

This preserves the shipped inline empty-string copy.

The campaign fields use the reviewed gameinfo layout.
