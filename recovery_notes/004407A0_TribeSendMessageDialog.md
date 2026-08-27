# `004407A0` `TribeSendMessageDialog::TribeSendMessageDialog`

The source belongs to `C:\\msdev\\work\\age1_x1\\dlg_smsg.cpp`, lines 66-244.
The natural source is `src/dlg_smsg.cpp`.

The reconstruction uses the typed dialog, panel, player, world, and shape
surfaces from the module header. It preserves the four radio setup calls, the
player scan, the language buffer base, and the original failure returns.

The module header places `master_player_id` at `RGE_Player+0x105` and
`color_table` at `RGE_Player+0x108`. The constructor and draw assembly prove
these offsets.

The constructor uses `/GX` from
`config/flags/004407A0_TribeSendMessageDialog.rsp`. Its accepted-drift result
before migration was 1,615 bytes versus 1,623 bytes, with a 0x80 frame and 50
ordered calls. The natural module build is currently 1,610 bytes. The
remaining difference is the radio-array register basin: the executable loads
the radio array base into EBP, while the clean source uses EBX.

Earlier probes tested initializer order, shape guards, radio aliases and
cursors, parent casts, zero spellings, register hints, headers, and the full
factory virtual surface. They did not find a natural source form for the EBP
basin. The buffer-base correction improved strict drift by two bytes and is
retained.
