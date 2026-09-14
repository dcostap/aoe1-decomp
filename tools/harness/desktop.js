// Verify the game process desktop before resuming any game code.
'use strict';
rpc.exports = {
    desktop() {
        const user = Process.getModuleByName('user32.dll');
        const get = new NativeFunction(user.getExportByName('GetThreadDesktop'), 'pointer', ['uint'], 'stdcall');
        const info = new NativeFunction(user.getExportByName('GetUserObjectInformationW'),
            'int', ['pointer', 'int', 'pointer', 'uint', 'pointer'], 'stdcall');
        const name = Memory.alloc(1024);
        const needed = Memory.alloc(4);
        const handle = get(Process.getCurrentThreadId());
        if (handle.isNull() || !info(handle, 2, name, 1024, needed))
            throw new Error('Cannot identify the game desktop');
        return name.readUtf16String();
    }
};
