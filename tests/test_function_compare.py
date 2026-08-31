import sys
from pathlib import Path
from types import SimpleNamespace

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

import function_compare  # noqa: E402


def test_grouped_compare_uses_resolved_parent_extent(monkeypatch) -> None:
    symbol = SimpleNamespace(name="?target@@YAXXZ", index=1, section_number=1)
    section = SimpleNamespace(data=b"\x90" * 10, relocations=[])
    obj = SimpleNamespace(symbols=[])
    observed = {}

    monkeypatch.setattr(
        function_compare,
        "function_record_by_va",
        lambda _va: {"name": "target", "size_bytes": "4"},
    )
    monkeypatch.setattr(
        function_compare, "select_configured_symbol", lambda _obj, _va, _module: symbol
    )
    monkeypatch.setattr(
        function_compare, "function_symbol_section", lambda _obj, _symbol: section
    )
    monkeypatch.setattr(
        function_compare,
        "_original_artifacts",
        lambda _va: (b"\x90" * 10, {"ranges": []}),
    )

    def fake_extent(_data, expected_size, _targets):
        observed["expected_size"] = expected_size
        return {
            "comparison_size": expected_size,
            "has_code_overflow": False,
            "boundary_escape_offsets": [],
        }

    monkeypatch.setattr(function_compare, "extraction_extent", fake_extent)
    monkeypatch.setattr(
        function_compare,
        "compatible_relocation_masks",
        lambda original, rebuilt, _relocations, _va, _ranges: (
            original,
            rebuilt,
            {"target_mismatches": []},
        ),
    )
    monkeypatch.setattr(
        function_compare,
        "byte_diff_metrics",
        lambda _original, _rebuilt: {
            "result": "MATCH",
            "diff_bytes": 0,
            "diff_percent": 0.0,
        },
    )
    monkeypatch.setattr(
        function_compare,
        "owning_function_symbol_validation",
        lambda _name, _symbol, _expected: {"status": "match"},
    )

    result = function_compare.compare_object_function(
        obj, 0x00401000, {}, "?target@@YAXXZ"
    )

    assert observed["expected_size"] == 10
    assert result["original_size"] == 10
    assert result["rebuilt_size"] == 10
    assert result["boundary_escape_offsets"] == []
    assert result["result"] == "MATCH"
