# 0041B010 `RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite`

- PDB source: `asprite.cpp`, lines 170 to 199.
- Original size: 259 bytes.
- Flags: `config/flags/group_009_gx.rsp`.

The constructor uses the `RGE_Active_Sprite` base layout. It uses the
`RGE_Sprite` timing fields at offsets `0x68` and `0x6C`.

The local order is significant to the old exact build. It is `count`,
`tot_time`, `rnd`, then `frame_time`. `frame_time` keeps the product over the
integer conversion.

The module merge keeps the recovered body. The old fragment context and its
recovery comments are removed.
