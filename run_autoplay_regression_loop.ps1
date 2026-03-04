param(
    [int]$Iterations = 5,
    [int]$TimeoutSec = 45
)

$ErrorActionPreference = "Stop"

$distDir = Join-Path $PSScriptRoot "dist"
$exePath = Join-Path $distDir "empiresx.exe"
$logPath = Join-Path $distDir "decomp_debug.log"

if (-not (Test-Path $exePath)) {
    throw "Missing executable: $exePath"
}

$results = @()
$env:AOE_AUTOPLAY_SP_RANDOM_START = "1"

for ($i = 1; $i -le $Iterations; $i++) {
    if (Test-Path $logPath) {
        $removed = $false
        for ($attempt = 0; $attempt -lt 10 -and -not $removed; $attempt++) {
            try {
                Remove-Item $logPath -Force
                $removed = $true
            } catch {
                Start-Sleep -Milliseconds 200
            }
        }
    }

    $proc = Start-Process -FilePath $exePath -WorkingDirectory $distDir -PassThru
    $exited = $proc.WaitForExit($TimeoutSec * 1000)
    if (-not $exited) {
        Stop-Process -Id $proc.Id -Force -ErrorAction SilentlyContinue
        Start-Sleep -Milliseconds 700
    }

    $startedGame = $false
    $wmDestroy = $false
    $gameDtor = $false
    $fatalSurface = $false
    if (Test-Path $logPath) {
        $log = Get-Content $logPath -Raw
        $startedGame = $log -match "create_game_screen: success"
        $wmDestroy = $log -match "received WM_DESTROY"
        $gameDtor = $log -match "TRIBE_Game::~TRIBE_Game: destructor start"
        $fatalSurface = $log -match "check_paint: CheckSurfaces returned fatal|TDrawSystem::CheckSurfaces fatal"
    }

    $pass = $startedGame -and -not $wmDestroy -and -not $gameDtor -and -not $fatalSurface
    $result = [PSCustomObject]@{
        Iteration    = $i
        Exited       = $exited
        ExitCode     = if ($exited) { $proc.ExitCode } else { $null }
        StartedGame  = $startedGame
        WmDestroy    = $wmDestroy
        GameDtor     = $gameDtor
        FatalSurface = $fatalSurface
        Pass         = $pass
    }
    $results += $result
    Write-Output ("iter={0} exited={1} started={2} destroy={3} dtor={4} fatalSurface={5} pass={6}" -f `
        $result.Iteration, $result.Exited, $result.StartedGame, $result.WmDestroy, $result.GameDtor, $result.FatalSurface, $result.Pass)
}

Write-Output ""
$results | Format-Table -AutoSize

$failed = @($results | Where-Object { -not [bool]$_.Pass })
$failCount = $failed.Count
if ($failCount -gt 0) {
    Write-Error "Autoplay regression loop failed in $failCount / $Iterations iteration(s)."
    exit 1
}

Write-Output "Autoplay regression loop passed."
exit 0
