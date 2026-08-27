# `00441650` `TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog`

The source belongs to `dlg_smsg.cpp`, lines 532-535. It now lives in
`src/dlg_smsg.cpp`.

The natural destructor deletes the edit and title panels. The exact result
requires `/GX`, which preserves the observed exception-handling frame.
