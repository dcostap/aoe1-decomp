# `00441840` `TribeSendQuickMessageDialog::handle_mouse_down`

The source belongs to `dlg_smsg.cpp`, lines 596-604. It now lives in
`src/dlg_smsg.cpp`.

The handler keeps the outside-panel hit test, dispatches the chat input action
with code 1, and forwards inside clicks to the `TEasy_Panel` base method.
