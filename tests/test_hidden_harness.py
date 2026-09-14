import ctypes
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))


@pytest.mark.skipif(sys.platform != 'win32', reason='Private desktop uses Windows APIs')
def test_worker_inherits_private_desktop(tmp_path):
    from hidden import run
    code = '''
import ctypes as c, os
u=c.WinDLL('user32'); k=c.WinDLL('kernel32')
u.GetThreadDesktop.restype=c.c_void_p
u.GetUserObjectInformationW.argtypes=[c.c_void_p,c.c_int,c.c_void_p,c.c_uint,c.c_void_p]
name=c.create_unicode_buffer(256); needed=c.c_uint()
h=u.GetThreadDesktop(k.GetCurrentThreadId())
assert u.GetUserObjectInformationW(h,2,name,c.sizeof(name),c.byref(needed))
assert name.value==os.environ['AOE1_HARNESS_DESKTOP']
print(name.value,flush=True)
'''
    log = tmp_path / 'worker.log'
    assert run([sys.executable, '-c', code], tmp_path, log, 15) == 0
    assert log.read_text().strip().startswith('AoE1Harness-')


@pytest.mark.skipif(sys.platform != 'win32', reason='Private desktop uses Windows APIs')
def test_deadline_kills_worker_descendants(tmp_path):
    from hidden import run, bind
    from ctypes import wintypes as W
    code = '''
import subprocess,sys,time
p=subprocess.Popen([sys.executable,'-c','import time;time.sleep(120)'])
print(p.pid,flush=True)
time.sleep(120)
'''
    log = tmp_path / 'timeout.log'
    with pytest.raises(TimeoutError):
        run([sys.executable, '-c', code], tmp_path, log, 2)
    pid = int(log.read_text().strip())
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    open_process = bind(kernel, 'OpenProcess', W.HANDLE, [W.DWORD, W.BOOL, W.DWORD])
    wait = bind(kernel, 'WaitForSingleObject', W.DWORD, [W.HANDLE, W.DWORD])
    close = bind(kernel, 'CloseHandle', W.BOOL, [W.HANDLE])
    handle = open_process(0x100000, False, pid)
    if handle:
        try:
            assert wait(handle, 1000) == 0
        finally:
            close(handle)


def test_direct_capture_requires_explicit_visible_permission(tmp_path, monkeypatch):
    from capture import capture
    monkeypatch.delenv('AOE1_HARNESS_DESKTOP', raising=False)
    with pytest.raises(ValueError, match='private desktop'):
        capture(tmp_path, 1)
