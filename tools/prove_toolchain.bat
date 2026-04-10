@echo off
setlocal
python "%~dp0probe_toolchain.py" %*
exit /b %ERRORLEVEL%
