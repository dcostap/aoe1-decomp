@echo off
setlocal
python "%~dp0tools\game.py" %*
exit /b %errorlevel%
