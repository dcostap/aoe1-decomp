# 0044D300 RGE_Game_Info destructor

The destructor uses natural `delete` expressions for each child. VC5 emits each
child destructor call before the scalar allocator call.

The campaign cleanup precedes the person cleanup.
