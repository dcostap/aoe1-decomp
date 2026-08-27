# Random-map stack ABI packet

`rmm_base.cpp` owns `Map_Stack` and `RGE_Random_Map_Module`.

The original FPO symbols prove these protected signatures:

```cpp
void init_stack(Map_Stack&);
void deinit_stack(Map_Stack&);
void push_stack(Map_Stack&, long, long, float, float);
Map_Stack* pop_stack(Map_Stack&, long&, long&, float&);
unsigned char find_path(long, long, long&, long&, float*);
unsigned char find_path(Map_Stack&, long, long, long&, long&, float*);
```

Exact symbol addresses are:

- `00480CC0`: `init_stack`;
- `00480CF0`: `deinit_stack`;
- `00480D10`: `push_stack`;
- `00480DA0`: `pop_stack`;
- `00480FB0`: first `find_path` overload;
- `00481000`: stack-reference `find_path` overload.

Do not replace references with pointers.

The Terra 5 grouped checkpoint reported 21/21 exact RMM base owners and 2/2 exact rmm_shal owners.
The source modules remain held until clean owner-only RMM and Map headers land.
