from __future__ import annotations

import argparse
import hashlib
import json
import re
import shutil
import subprocess
from pathlib import Path

from common import BUILD_DIR, edit_diff_metrics, load_toolchain, repo_path, tool_env


IL_SUFFIXES = ("in", "ex", "gl", "sy")
IL_PATH_RE = re.compile(r"\s-il\s+([^\s'`]+)", re.IGNORECASE)
PRINTABLE_RE = re.compile(rb"[ -~]{3,}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compile with VC5 and retain the C1XX-to-C2 IL streams."
    )
    parser.add_argument("source", type=Path, help="C or C++ source to compile.")
    parser.add_argument("--label", required=True, help="Output directory label.")
    parser.add_argument(
        "--rsp",
        type=Path,
        default=Path("config/flags/default.rsp"),
        help="Compiler response file. Default: config/flags/default.rsp",
    )
    parser.add_argument(
        "--compare",
        type=Path,
        help="Prior capture directory to compare with this capture.",
    )
    return parser.parse_args()


def file_summary(path: Path, include_strings: bool) -> dict[str, object]:
    data = path.read_bytes()
    summary: dict[str, object] = {
        "path": str(path),
        "size": len(data),
        "sha256": hashlib.sha256(data).hexdigest(),
    }
    if include_strings:
        summary["printable_strings"] = [
            match.group().decode("ascii") for match in PRINTABLE_RE.finditer(data)
        ]
    return summary


def stream_diff(left: bytes, right: bytes) -> dict[str, int]:
    shared = min(len(left), len(right))
    edit = edit_diff_metrics(left, right)
    return {
        "left_size": len(left),
        "right_size": len(right),
        "changed_shared_bytes": sum(left[i] != right[i] for i in range(shared)),
        "size_delta": len(right) - len(left),
        "edit_diff_bytes": int(edit["edit_diff_bytes"]),
        "edit_equal_bytes": int(edit["edit_equal_bytes"]),
        "edit_insert_bytes": int(edit["edit_insert_bytes"]),
        "edit_delete_bytes": int(edit["edit_delete_bytes"]),
        "edit_replace_bytes": int(edit["edit_replace_bytes"]),
    }


def main() -> None:
    args = parse_args()
    source = args.source.resolve()
    rsp = repo_path(args.rsp).resolve()
    if not source.is_file():
        raise SystemExit(f"Missing source: {source}")
    if not rsp.is_file():
        raise SystemExit(f"Missing response file: {rsp}")

    output_dir = BUILD_DIR / "vc5_ir" / args.label
    output_dir.mkdir(parents=True, exist_ok=True)
    obj_path = output_dir / "candidate.obj"

    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    command = [
        str(cl_path),
        f"@{rsp}",
        "/Bk",
        "/Bd",
        f"/Fo{obj_path}",
        str(source),
    ]
    result = subprocess.run(
        command,
        capture_output=True,
        text=True,
        env=tool_env(toolchain),
    )
    compiler_text = result.stdout + result.stderr
    (output_dir / "compiler.txt").write_text(compiler_text, encoding="utf-8")
    if result.returncode != 0:
        raise SystemExit(compiler_text or f"CL failed with status {result.returncode}")

    match = IL_PATH_RE.search(compiler_text)
    if match is None:
        raise SystemExit("VC5 did not report its intermediate IL path.")

    il_base = Path(match.group(1))
    streams: dict[str, dict[str, object]] = {}
    for suffix in IL_SUFFIXES:
        source_stream = Path(f"{il_base}{suffix}")
        if not source_stream.is_file():
            raise SystemExit(f"Missing retained IL stream: {source_stream}")
        destination = output_dir / f"candidate.{suffix}"
        shutil.copyfile(source_stream, destination)
        source_stream.unlink()
        streams[suffix] = file_summary(destination, include_strings=suffix != "ex")

    report: dict[str, object] = {
        "source": str(source),
        "response_file": str(rsp),
        "command": command,
        "compiler_output": compiler_text,
        "streams": streams,
    }

    if args.compare is not None:
        compare_dir = args.compare.resolve()
        comparisons: dict[str, dict[str, int]] = {}
        for suffix in IL_SUFFIXES:
            left_path = compare_dir / f"candidate.{suffix}"
            right_path = output_dir / f"candidate.{suffix}"
            if not left_path.is_file():
                raise SystemExit(f"Missing comparison stream: {left_path}")
            comparisons[suffix] = stream_diff(
                left_path.read_bytes(), right_path.read_bytes()
            )
        report["comparison"] = {
            "left": str(compare_dir),
            "streams": comparisons,
        }

    report_path = output_dir / "report.json"
    report_path.write_text(json.dumps(report, indent=2), encoding="utf-8")

    print(f"Captured VC5 IL: {output_dir}")
    for suffix in IL_SUFFIXES:
        summary = streams[suffix]
        print(f"  {suffix}: {summary['size']} bytes {str(summary['sha256'])[:12]}")
    if "comparison" in report:
        print("Comparison:")
        comparison = report["comparison"]
        assert isinstance(comparison, dict)
        comparison_streams = comparison["streams"]
        assert isinstance(comparison_streams, dict)
        for suffix in IL_SUFFIXES:
            item = comparison_streams[suffix]
            print(
                f"  {suffix}: changed={item['changed_shared_bytes']} "
                f"edit={item['edit_diff_bytes']} size_delta={item['size_delta']:+d}"
            )
    print(f"Wrote {report_path}")


if __name__ == "__main__":
    main()
