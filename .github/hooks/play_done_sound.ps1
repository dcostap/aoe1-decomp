# Plays .github/hooks/jobs_done.mp3 for Copilot hooks (Copilot CLI / VS Code hooks)

$ErrorActionPreference = 'SilentlyContinue'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$soundFile = Join-Path $scriptDir 'jobs_done.mp3'

function Invoke-FallbackBeep {
    [System.Console]::Beep(800, 200)
    [System.Console]::Beep(1000, 200)
    [System.Console]::Beep(1200, 350)
}

# Prevent double-fire (e.g., agentStop + sessionEnd in quick succession)
$stampPath = Join-Path $env:TEMP 'copilot_done_sound_lastplay.txt'
$nowTicks = [DateTimeOffset]::UtcNow.ToUnixTimeMilliseconds()
try {
    if (Test-Path -LiteralPath $stampPath) {
        $prev = (Get-Content -LiteralPath $stampPath -Raw).Trim()
        if ($prev -match '^\d+$') {
            $delta = [int64]$nowTicks - [int64]$prev
            if ($delta -ge 0 -and $delta -lt 1500) {
                Write-Output '{}'
                exit 0
            }
        }
    }
    Set-Content -LiteralPath $stampPath -Value $nowTicks -NoNewline
} catch {
    # ignore stamp errors
}

if (-not (Test-Path -LiteralPath $soundFile)) {
    Invoke-FallbackBeep
    Write-Output '{}'
    exit 0
}

# Use MCI (winmm.dll) to play mp3 without WPF/STA requirements.
$mciSource = @'
using System;
using System.Runtime.InteropServices;
using System.Text;

public static class WinMM
{
    [DllImport("winmm.dll", CharSet = CharSet.Unicode)]
    public static extern int mciSendString(string command, StringBuilder returnValue, int returnLength, IntPtr winHandle);

    public static void Send(string command)
    {
        mciSendString(command, null, 0, IntPtr.Zero);
    }
}
'@

try {
    Add-Type -TypeDefinition $mciSource -Language CSharp -ErrorAction Stop | Out-Null

    $alias = 'copilot_done'
    $escapedPath = $soundFile.Replace('"', '""')

    [WinMM]::Send("close $alias")
    [WinMM]::Send("open `"$escapedPath`" type mpegvideo alias $alias")
    # MCI volume is typically 0-1000
    [WinMM]::Send("setaudio $alias volume to 700")
    [WinMM]::Send("play $alias")

    # Keep the process alive briefly so the sound actually plays.
    Start-Sleep -Milliseconds 2000

    [WinMM]::Send("close $alias")
} catch {
    Invoke-FallbackBeep
}

# Hooks expect valid JSON on stdout in some runners.
Write-Output '{}'
