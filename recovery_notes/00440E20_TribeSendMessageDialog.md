# `00440E20` `TribeSendMessageDialog::~TribeSendMessageDialog`

The source belongs to `dlg_smsg.cpp`, lines 249-267. It now lives in the
natural module source `src/dlg_smsg.cpp`.

The natural source now deletes each child through its typed member and uses
the indexed cleanup loops. It also deletes the shape through ordinary `delete`.

The cleanup change is intentional. The current module check differs by 226
bytes and escapes the original boundary twice. The owner is scratch again.
The generated destructor at `00440E00` still matches its 30-byte body.
