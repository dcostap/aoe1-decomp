from __future__ import annotations

import argparse
import hashlib
import json
import statistics
import subprocess
import sys
import time
from pathlib import Path

try:
    import psutil
except ImportError as error:  # pragma: no cover - host setup failure
    raise SystemExit("benchmark_query_project_status.py requires psutil") from error


REPO_ROOT = Path(__file__).resolve().parents[1]
QUERY_SCRIPT = REPO_ROOT / "tools" / "query_project_status.py"
QUERY_CASES = {
    "single_va": ["--va", "00401000", "--paths", "--notes", "--leases"],
    "single_va_session": ["--va", "00405620", "--paths", "--notes", "--leases"],
    "single_va_json": ["--va", "00401000", "--json"],
    "target_queue": [
        "--unclaimed", "--normal", "--no-blockers", "--unleased", "--smallest",
        "--triage", "--work-history", "--leases", "--limit", "12",
    ],
    "scratch_diff": ["--scratch", "--sort", "diff", "--limit", "30"],
    "name_search": ["--query", "set_picture", "--normal", "--paths"],
    "normal_summary": ["--summary", "--normal"],
    "remaining_json": ["--remaining", "--normal", "--smallest", "--limit", "30", "--json"],
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Benchmark deterministic query_project_status.py workloads."
    )
    parser.add_argument("--repeat", type=int, default=3, help="Timed runs per case (default: 3).")
    parser.add_argument(
        "--concurrency", type=int, default=16,
        help="Concurrent single-VA processes (default: 16; 0 disables).",
    )
    parser.add_argument(
        "--case", action="append", choices=sorted(QUERY_CASES),
        help="Run only this case. Repeat the option for more cases.",
    )
    parser.add_argument("--output", type=Path, help="Also write the JSON result to this path.")
    return parser.parse_args()


def wait_measured(processes: list[subprocess.Popen[bytes]]) -> tuple[float, int]:
    started = time.perf_counter()
    peak_rss = 0
    monitored = [psutil.Process(process.pid) for process in processes]
    while any(process.poll() is None for process in processes):
        total_rss = 0
        for process in monitored:
            try:
                total_rss += process.memory_info().rss
            except (psutil.AccessDenied, psutil.NoSuchProcess):
                pass
        peak_rss = max(peak_rss, total_rss)
        time.sleep(0.005)
    for process in processes:
        return_code = process.wait()
        if return_code:
            raise RuntimeError(f"query failed with exit code {return_code}: {process.args}")
    return time.perf_counter() - started, peak_rss


def command_for(arguments: list[str]) -> list[str]:
    return [sys.executable, str(QUERY_SCRIPT), *arguments]


def benchmark_case(arguments: list[str], repeat: int) -> dict[str, object]:
    command = command_for(arguments)
    output = subprocess.run(command, cwd=REPO_ROOT, check=True, capture_output=True).stdout
    times: list[float] = []
    peaks: list[int] = []
    for _ in range(repeat):
        process = subprocess.Popen(
            command, cwd=REPO_ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL
        )
        elapsed, peak_rss = wait_measured([process])
        times.append(elapsed)
        peaks.append(peak_rss)
    return {
        "command": arguments,
        "output_sha256": hashlib.sha256(output).hexdigest(),
        "output_bytes": len(output),
        "times_s": [round(value, 4) for value in times],
        "median_s": round(statistics.median(times), 4),
        "minimum_s": round(min(times), 4),
        "peak_rss_mib": round(max(peaks) / (1024 * 1024), 1),
    }


def benchmark_concurrency(count: int) -> dict[str, object]:
    command = command_for(QUERY_CASES["single_va_session"])
    processes = [
        subprocess.Popen(command, cwd=REPO_ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        for _ in range(count)
    ]
    elapsed, peak_rss = wait_measured(processes)
    return {
        "processes": count,
        "wall_s": round(elapsed, 4),
        "throughput_per_s": round(count / elapsed, 2),
        "peak_aggregate_rss_mib": round(peak_rss / (1024 * 1024), 1),
    }


def main() -> None:
    args = parse_args()
    if args.repeat <= 0:
        raise SystemExit("--repeat must be positive")
    if args.concurrency < 0:
        raise SystemExit("--concurrency must be zero or positive")
    selected = args.case or list(QUERY_CASES)
    result: dict[str, object] = {
        name: benchmark_case(QUERY_CASES[name], args.repeat) for name in selected
    }
    if args.concurrency:
        result["concurrent_single_va"] = benchmark_concurrency(args.concurrency)
    text = json.dumps(result, indent=2, sort_keys=True) + "\n"
    print(text, end="")
    if args.output:
        output = args.output if args.output.is_absolute() else REPO_ROOT / args.output
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(text, encoding="utf-8")


if __name__ == "__main__":
    main()
