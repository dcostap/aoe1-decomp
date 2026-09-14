"""Run a worker on a private Windows desktop. Never switch the user's desktop."""
from __future__ import annotations

import argparse
import ctypes as C
from ctypes import wintypes as W
import json
import msvcrt
import os
from pathlib import Path
import subprocess
import time
import uuid


class STARTUPINFO(C.Structure):
    _fields_ = [('cb', W.DWORD), ('lpReserved', W.LPWSTR), ('lpDesktop', W.LPWSTR),
                ('lpTitle', W.LPWSTR), ('dwX', W.DWORD), ('dwY', W.DWORD),
                ('dwXSize', W.DWORD), ('dwYSize', W.DWORD), ('dwXCountChars', W.DWORD),
                ('dwYCountChars', W.DWORD), ('dwFillAttribute', W.DWORD), ('dwFlags', W.DWORD),
                ('wShowWindow', W.WORD), ('cbReserved2', W.WORD), ('lpReserved2', C.c_void_p),
                ('hStdInput', W.HANDLE), ('hStdOutput', W.HANDLE), ('hStdError', W.HANDLE)]


class PROCESS_INFORMATION(C.Structure):
    _fields_ = [('hProcess', W.HANDLE), ('hThread', W.HANDLE),
                ('dwProcessId', W.DWORD), ('dwThreadId', W.DWORD)]


class BASIC_LIMIT(C.Structure):
    _fields_ = [('process_time', C.c_int64), ('job_time', C.c_int64), ('flags', W.DWORD),
                ('min_working', C.c_size_t), ('max_working', C.c_size_t), ('active', W.DWORD),
                ('affinity', C.c_size_t), ('priority', W.DWORD), ('scheduling', W.DWORD)]


class JOB_LIMIT(C.Structure):
    _fields_ = [('basic', BASIC_LIMIT), ('io', C.c_uint64 * 6),
                ('process_memory', C.c_size_t), ('job_memory', C.c_size_t),
                ('peak_process', C.c_size_t), ('peak_job', C.c_size_t)]


def bind(dll, name, result, args):
    function = getattr(dll, name)
    function.restype, function.argtypes = result, args
    return function


def run(command, cwd: Path, log: Path, timeout: float):
    if log.exists() or log.with_suffix('.json').exists():
        raise ValueError('Hidden worker log already exists. Use a new path.')
    kernel = C.WinDLL('kernel32', use_last_error=True)
    user = C.WinDLL('user32', use_last_error=True)
    create_desktop = bind(user, 'CreateDesktopW', W.HANDLE,
                          [W.LPCWSTR, W.LPCWSTR, C.c_void_p, W.DWORD, W.DWORD, C.c_void_p])
    close_desktop = bind(user, 'CloseDesktop', W.BOOL, [W.HANDLE])
    close = bind(kernel, 'CloseHandle', W.BOOL, [W.HANDLE])
    create_job = bind(kernel, 'CreateJobObjectW', W.HANDLE, [C.c_void_p, W.LPCWSTR])
    set_job = bind(kernel, 'SetInformationJobObject', W.BOOL, [W.HANDLE, C.c_int, C.c_void_p, W.DWORD])
    assign = bind(kernel, 'AssignProcessToJobObject', W.BOOL, [W.HANDLE, W.HANDLE])
    create = bind(kernel, 'CreateProcessW', W.BOOL, [W.LPCWSTR, W.LPWSTR, C.c_void_p, C.c_void_p,
                  W.BOOL, W.DWORD, C.c_void_p, W.LPCWSTR, C.POINTER(STARTUPINFO), C.POINTER(PROCESS_INFORMATION)])
    resume = bind(kernel, 'ResumeThread', W.DWORD, [W.HANDLE])
    wait = bind(kernel, 'WaitForSingleObject', W.DWORD, [W.HANDLE, W.DWORD])
    exit_code = bind(kernel, 'GetExitCodeProcess', W.BOOL, [W.HANDLE, C.POINTER(W.DWORD)])
    terminate = bind(kernel, 'TerminateProcess', W.BOOL, [W.HANDLE, W.UINT])
    open_input = bind(user, 'OpenInputDesktop', W.HANDLE, [W.DWORD, W.BOOL, W.DWORD])
    object_info = bind(user, 'GetUserObjectInformationW', W.BOOL,
                       [W.HANDLE, C.c_int, C.c_void_p, W.DWORD, C.POINTER(W.DWORD)])
    def input_desktop():
        handle = open_input(0, False, 1)
        if not handle:
            return None
        try:
            buffer, needed = C.create_unicode_buffer(256), W.DWORD()
            return buffer.value if object_info(handle, 2, buffer, C.sizeof(buffer), C.byref(needed)) else None
        finally:
            close_desktop(handle)
    identity = uuid.uuid4().hex
    name = 'AoE1Harness-' + identity
    desktop = create_desktop(name, None, None, 0, 0x01ff, None)
    if not desktop:
        raise C.WinError(C.get_last_error())
    job = None
    process = PROCESS_INFORMATION()
    started = time.monotonic()
    report = {'desktop': name, 'command': command, 'switched_desktop': False,
              'log': str(log.resolve()), 'returncode': None,
              'input_desktop_before': input_desktop()}
    try:
        job = create_job(None, None)
        limits = JOB_LIMIT()
        limits.basic.flags = 0x2000  # JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE
        if not job or not set_job(job, 9, C.byref(limits), C.sizeof(limits)):
            raise C.WinError(C.get_last_error())
        environment = dict(os.environ, AOE1_HARNESS_DESKTOP=name, AOE1_HARNESS_RUN_ID=identity)
        block = C.create_unicode_buffer('\0'.join(f'{k}={v}' for k, v in sorted(environment.items())) + '\0\0')
        log.parent.mkdir(parents=True, exist_ok=True)
        with log.open('xb') as stream, open(os.devnull, 'rb') as stdin:
            out_handle, in_handle = msvcrt.get_osfhandle(stream.fileno()), msvcrt.get_osfhandle(stdin.fileno())
            os.set_handle_inheritable(out_handle, True)
            os.set_handle_inheritable(in_handle, True)
            startup = STARTUPINFO()
            startup.cb, startup.lpDesktop, startup.dwFlags = C.sizeof(startup), name, 0x100
            startup.hStdInput, startup.hStdOutput, startup.hStdError = in_handle, out_handle, out_handle
            line = C.create_unicode_buffer(subprocess.list2cmdline(command))
            if not create(command[0], line, None, None, True, 0x08000404, block, str(cwd),
                          C.byref(startup), C.byref(process)):
                raise C.WinError(C.get_last_error())
            if not assign(job, process.hProcess):
                terminate(process.hProcess, 1)
                raise C.WinError(C.get_last_error())
            if resume(process.hThread) == 0xffffffff:
                raise C.WinError(C.get_last_error())
            # The job owns the worker and all game/helper descendants, including on timeout.
            result = wait(process.hProcess, int(timeout * 1000))
            if result != 0:
                raise TimeoutError('Hidden worker exceeded its deadline or its process wait failed.')
            code = W.DWORD()
            if not exit_code(process.hProcess, C.byref(code)):
                raise C.WinError(C.get_last_error())
            report['returncode'] = code.value
            return code.value
    except Exception as error:
        report['error'] = str(error)
        raise
    finally:
        if job:
            close(job)
        if process.hProcess:
            wait(process.hProcess, 5000)
        for handle in (process.hThread, process.hProcess):
            if handle:
                close(handle)
        close_desktop(desktop)
        import registry_state
        registry_state.cleanup('Software\\AoE1Harness\\' + identity)
        report['duration'] = time.monotonic() - started
        report['input_desktop_after'] = input_desktop()
        log.with_suffix('.json').write_text(json.dumps(report, indent=2) + '\n')
        print(f'Hidden worker: {log}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--log', type=Path, required=True)
    parser.add_argument('--timeout', type=float, default=60)
    parser.add_argument('command', nargs=argparse.REMAINDER)
    args = parser.parse_args()
    command = args.command[1:] if args.command[:1] == ['--'] else args.command
    if not command or not 0 < args.timeout <= 86400:
        parser.error('Supply a worker command and a positive timeout of at most 86400 seconds.')
    return run(command, Path.cwd(), args.log, args.timeout)


if __name__ == '__main__':
    raise SystemExit(main())
