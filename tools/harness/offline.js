// Automated menu tests cannot create game network sockets. No firewall rules change.
// Keep Frida's own transport working; this is a test profile, not a security sandbox.
const socketHooks = new Set();
const socketCallbacks = [];
const agentSocketThreads = new Set();
const socketObserver = Process.attachModuleObserver({
    onAdded(module) {
        if (!['ws2_32.dll', 'wsock32.dll'].includes(module.name.toLowerCase())) return;
        try {
            const setError = new NativeFunction(module.getExportByName('WSASetLastError'),
                'void', ['int'], 'stdcall');
            for (const name of ['socket', 'WSASocketA', 'WSASocketW']) {
                const address = module.findExportByName(name);
                if (!address || socketHooks.has(address.toString())) continue;
                const signature = name === 'socket' ? ['int', 'int', 'int'] :
                    ['int', 'int', 'int', 'pointer', 'uint', 'uint'];
                const original = new NativeFunction(address, 'uint', signature, 'stdcall');
                const callback = new NativeCallback(function (...args) {
                    const thread = Process.getCurrentThreadId();
                    const caller = Process.findModuleByAddress(this.returnAddress);
                    if (agentSocketThreads.has(thread) || (caller && /frida/i.test(caller.name))) {
                        const nested = agentSocketThreads.has(thread);
                        agentSocketThreads.add(thread);
                        try { return original(...args); }
                        finally { if (!nested) agentSocketThreads.delete(thread); }
                    }
                    send({kind:'network-blocked', api:name, caller:caller ? caller.name : null});
                    setError(10013); // WSAEACCES
                    this.lastError = 10013;
                    return 0xffffffff; // INVALID_SOCKET on the pinned 32-bit target
                }, 'uint', signature, 'stdcall');
                socketCallbacks.push(callback);
                Interceptor.replace(address, callback);
                socketHooks.add(address.toString());
                send({kind:'network-hook', module:module.name, api:name});
            }
        } catch (error) {
            send({kind:'ui-error', error:'Cannot install offline network profile: ' + error});
        }
    }
});
send({kind:'network-profile', mode:'offline'});
