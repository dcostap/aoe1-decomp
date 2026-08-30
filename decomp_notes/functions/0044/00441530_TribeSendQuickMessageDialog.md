# Function notes: 00441530 `TribeSendQuickMessageDialog`

## Earlier notes from `decomp_notes/functions/0044/00441530_TribeSendQuickMessageDialog.md`

This section is historical. Use the status query for current state.

## `00441530` `TribeSendQuickMessageDialog::TribeSendQuickMessageDialog`

The source belongs to `dlg_smsg.cpp`, lines 507-527. It now lives in
`src/dlg_smsg.cpp`.

The exact source stores `modeValue` in the constructor initializer list and
uses an explicit title-ID assignment in the two mode arms. This reproduces
the shipped EAX title-ID schedule while keeping ordinary period C++ source.
The original `/GX` flags remain the module flags.
