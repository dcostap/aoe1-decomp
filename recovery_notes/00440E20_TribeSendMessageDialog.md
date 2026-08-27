# `00440E20` `TribeSendMessageDialog::~TribeSendMessageDialog`

The source belongs to `dlg_smsg.cpp`, lines 249-267. It now lives in the
natural module source `src/dlg_smsg.cpp`.

The final bank source used typed member cleanup and indexed loops. The exact
result required the natural virtual destructor and the `/GX` module flags.
Earlier pointer-only declarations and typed cursor casts did not change the
output. The old raw fastcall wrapper was removed during migration.
