# 00462EA0 RGE_Object_List destructor

The cleanup loop reads `list->next`, frees that node, then writes it to `list`.

Keep this sequence. Do not replace it with a normal node-free loop.
