# Function notes: 00441650 `~TribeSendQuickMessageDialog`

## Earlier notes from `decomp_notes/functions/0044/00441650_TribeSendQuickMessageDialog.md`

This section is historical. Use the status query for current state.

## `00441650` `TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog`

The source belongs to `dlg_smsg.cpp`, lines 532-535. It now lives in
`src/dlg_smsg.cpp`.

The natural destructor deletes the edit and title panels. The exact result
requires `/GX`, which preserves the observed exception-handling frame.
