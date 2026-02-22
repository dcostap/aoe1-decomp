param(
    [Parameter(Mandatory = $true)]
    [string]$SrcDir,
    [Parameter(Mandatory = $true)]
    [string]$ObjDir,
    [Parameter(Mandatory = $true)]
    [string]$ResFile,
    [Parameter(Mandatory = $true)]
    [string]$ExcludeFile,
    [Parameter(Mandatory = $true)]
    [int]$RebuildAll
)

$excludeSet = @{}
if (Test-Path -LiteralPath $ExcludeFile) {
    foreach ($line in Get-Content -LiteralPath $ExcludeFile) {
        $entry = $line.Trim()
        if ($entry.Length -eq 0) { continue }
        if ($entry.StartsWith("#")) { continue }
        $excludeSet[$entry.ToLowerInvariant()] = $true
    }
}

$sources = Get-ChildItem -LiteralPath $SrcDir -File -Filter *.cpp | Sort-Object Name
$objectList = New-Object System.Collections.Generic.List[string]
$changedSources = New-Object System.Collections.Generic.List[string]

$sourceCount = 0
$excludedCount = 0
$shouldRebuildAll = ($RebuildAll -ne 0)

$objectList.Add($ResFile)

foreach ($src in $sources) {
    $sourceName = $src.Name.ToLowerInvariant()
    if ($excludeSet.ContainsKey($sourceName)) {
        $excludedCount++
        continue
    }

    $sourceCount++
    $objFile = Join-Path $ObjDir ($src.BaseName + ".obj")
    $objectList.Add($objFile)

    $needsCompile = $shouldRebuildAll
    if (-not $needsCompile) {
        if (-not (Test-Path -LiteralPath $objFile)) {
            $needsCompile = $true
        } else {
            $objWriteTime = (Get-Item -LiteralPath $objFile).LastWriteTimeUtc
            if ($src.LastWriteTimeUtc -gt $objWriteTime) {
                $needsCompile = $true
            }
        }
    }

    if ($needsCompile) {
        # Keep paths relative to avoid hitting cmd.exe environment length limits.
        $changedSources.Add((Join-Path $SrcDir $src.Name))
    }
}

# Emit changed sources as a response file to avoid Windows cmd.exe line-length limits.
$changedRspPath = Join-Path $ObjDir "changed_sources.rsp"
Set-Content -LiteralPath $changedRspPath -Value ($changedSources -join "`r`n") -Encoding ASCII

Write-Output ("OBJECT_LIST=" + ($objectList -join " "))
Write-Output ("CHANGED_SOURCES_RSP=" + $changedRspPath)
Write-Output ("SOURCE_COUNT=" + $sourceCount)
Write-Output ("CHANGED_COUNT=" + $changedSources.Count)
Write-Output ("EXCLUDED_COUNT=" + $excludedCount)
