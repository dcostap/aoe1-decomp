"""The source wrapping pass keeps safe expression joins narrow."""
import importlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
joiner = importlib.import_module("join_wrapped_parens")


def test_control_condition_joins_when_short():
    source = """void check() {
    if (left_value &&
        right_value) {
        call();
    }
}
"""

    transformed, changes = joiner.transform(source, 125)

    assert changes == 1
    assert "if (left_value && right_value) {" in transformed


def test_other_control_conditions_join_when_short():
    for keyword in ("for", "switch", "while", "catch"):
        source = f"""void check() {{
    {keyword} (condition &&
              other_condition) {{
        call();
    }}
}}
"""

        transformed, changes = joiner.transform(source, 125)

        assert changes == 1, keyword
        assert f"{keyword} (condition && other_condition) {{" in transformed


def test_function_signature_stays_separate():
    source = """void check(
    int first,
    int second) {
}
"""

    transformed, changes = joiner.transform(source, 125)

    assert changes == 0
    assert transformed == source


def test_comment_line_is_not_joined_into_expression():
    source = """void check() {
    if (left_value &&
        // Keep this evidence line separate.
        right_value) {
        call();
    }
}
"""

    transformed, changes = joiner.transform(source, 125)

    assert changes == 0
    assert transformed == source


def test_column_limit_still_applies_to_control_conditions():
    source = """void check() {
    if (left_value &&
        right_value) {
    }
}
"""

    transformed, changes = joiner.transform(source, 30)

    assert changes == 0
    assert transformed == source
