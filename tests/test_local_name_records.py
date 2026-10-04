from __future__ import annotations

import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import audit_local_name_records as audit
from coff import CoffObject, CoffRelocation, CoffSection


def stack(name, offset=-4, type_name="int"):
    return {"kind": "stack", "name": name, "offset": offset, "type_name": type_name}


def procedure(*rows, blocks=False):
    return {"stack_symbols": [r for r in rows if r["kind"] == "stack"],
            "register_symbols": [r for r in rows if r["kind"] == "register"],
            "has_blocks": blocks}


def test_exact_name_type_and_location():
    old = procedure(stack("quantity"))
    assert audit.compare_names(old, old)[0]["result"] == "confirmed"


def test_swap_is_a_conflict():
    old = procedure(stack("typeID", -0x160), stack("quantity", -0x15c))
    new = procedure(stack("quantity", -0x160), stack("typeID", -0x15c))
    rows = audit.compare_names(old, new)
    assert [r["result"] for r in rows] == ["conflict", "conflict"]
    assert rows[0]["rebuilt_at_location"]["name"] == "quantity"
    assert rows[0]["name_relation"] == "original_name_at_other_location"


@pytest.mark.parametrize("old,new", [
    (procedure(stack("x")), procedure()),
    (procedure(stack("x", type_name="")), procedure(stack("x"))),
    (procedure(stack("x")), procedure(stack("x", type_name="float"))),
    (procedure(stack("x"), stack("y")), procedure(stack("x"))),
    (procedure(stack("x")), procedure(stack("x"), stack("y"))),
    (procedure(stack("x"), stack("x", -8)), procedure(stack("x"))),
    (procedure(stack("x")), procedure(stack("x"), stack("x", -8))),
    (procedure(stack("x"), blocks=True), procedure(stack("x"))),
    (procedure(stack("x")), procedure(stack("x"), blocks=True)),
])
def test_uncertain_records_are_unknown(old, new):
    assert all(r["result"] == "unknown" for r in audit.compare_names(old, new))


def test_register_reuse_is_unknown_even_when_types_differ():
    old = procedure({"kind": "register", "name": "x", "register": "eax", "type_name": "int"},
                    {"kind": "register", "name": "y", "register": "eax", "type_name": "float"})
    new = procedure(old["register_symbols"][0])
    assert all(r["result"] == "unknown" for r in audit.compare_names(old, new))


def test_object_procedure_uses_relocation_owner():
    text = """
***** SECTION #2
(000000) S_GPROC32: [0000:00000000], Cb: 00000020, Type: 0x1000, A::f
(000040) S_BPREL32: [FFFFFFFC], Type: T_INT4(0074), quantity
(000060) S_END
***** SECTION #3
(000000) S_GPROC32: [0000:00000000], Cb: 00000020, Type: 0x1000, A::f
(000040) S_BPREL32: [FFFFFFFC], Type: T_REAL32(0040), size
(000060) S_END
"""
    obj = CoffObject([
        CoffSection(".debug$S", b"", [CoffRelocation(32, 1, 0xB, 4, "?f@A@@int")], index=2),
        CoffSection(".debug$S", b"", [CoffRelocation(32, 2, 0xB, 4, "?f@A@@float")], index=3),
    ], [])
    rows = audit.parse_object_records(text, obj)
    assert set(rows) == {"?f@A@@int", "?f@A@@float"}
    assert rows["?f@A@@int"]["stack_symbols"][0]["offset"] == -4
    assert rows["?f@A@@float"]["stack_symbols"][0]["type_name"] == "float"


def test_unproved_code_blocks_name_checks(monkeypatch):
    monkeypatch.setattr(audit, "compare_object_function", lambda *a: {"result": "MISMATCH"})
    row = audit.audit_function("00409430", {"status": "matching", "symbol": "f"},
                               {}, None, None, {}, {})
    assert row["result"] == "not_checked"
    assert row["variables"] == []


def test_nonmatching_function_is_not_checked(monkeypatch):
    def forbidden(*args):
        raise AssertionError("Do not attempt an exact name mapping for accepted drift")
    monkeypatch.setattr(audit, "compare_object_function", forbidden)
    row = audit.audit_function("00409430", {"status": "accepted_drift"},
                               {}, None, None, {}, {})
    assert row["result"] == "not_checked"


def test_extra_source_record_keeps_function_coverage_unknown(monkeypatch):
    monkeypatch.setattr(audit, "compare_object_function", lambda *a: {"result": "MATCH"})
    old = procedure(stack("quantity"))
    new = procedure(stack("quantity"), stack("end", -8, "BuildItem*"))
    row = audit.audit_function("00409430", {"status": "matching", "symbol": "f"},
                               {}, None, None, {"00409430": old}, {"f": new})
    assert row["result"] == "unknown"
    assert row["counts"] == {"confirmed": 1}
    assert row["source_only_records"][0]["name"] == "end"


def test_unique_register_name_swap_is_a_conflict():
    old = procedure({"kind": "register", "name": "quantity", "register": "esi", "type_name": "int"},
                    {"kind": "register", "name": "typeID", "register": "edi", "type_name": "int"})
    new = procedure({"kind": "register", "name": "typeID", "register": "esi", "type_name": "int"},
                    {"kind": "register", "name": "quantity", "register": "edi", "type_name": "int"})
    assert audit.compare_names(old, new)[0]["result"] == "conflict"


def test_object_scope_record_prevents_confirmation():
    text = """
***** SECTION #2
(000000) S_GPROC32: [0000:00000000], Cb: 00000020, Type: 0x1000, A::f
(000040) S_BPREL32: [FFFFFFFC], Type: T_INT4(0074), quantity
(000060) S_BLOCK32: [0000:00000000], Cb: 00000010, (none)
(000080) S_BPREL32: [FFFFFFF8], Type: T_INT4(0074), inner
(0000A0) S_END
(0000B0) S_END
"""
    obj = CoffObject([
        CoffSection(".debug$S", b"", [CoffRelocation(32, 1, 0xB, 4, "?f@A@@")], index=2),
    ], [])
    rebuilt = audit.parse_object_records(text, obj)["?f@A@@"]
    assert rebuilt["has_blocks"]
    old = procedure(stack("quantity"))
    assert audit.compare_names(old, rebuilt)[0]["result"] == "unknown"


def test_different_spelling_is_not_reported_as_an_original_name_swap():
    row = audit.compare_names(procedure(stack("quantity")), procedure(stack("entry_count")))[0]
    assert row["result"] == "different_spelling"
    assert row["name_relation"] == "different_spelling"


def test_different_spelling_is_a_separate_function_result(monkeypatch):
    monkeypatch.setattr(audit, "compare_object_function", lambda *a: {"result": "MATCH"})
    row = audit.audit_function("00409430", {"status": "matching", "symbol": "f"},
                               {}, None, None, {"00409430": procedure(stack("quantity"))},
                               {"f": procedure(stack("entry_count"))})
    assert row["result"] == "name_difference"
    assert row["counts"] == {"different_spelling": 1}


def test_repeated_original_spelling_does_not_prove_a_swap():
    old = procedure(stack("quantity"), stack("i", -8), stack("i", -12))
    new = procedure(stack("i"))
    assert audit.compare_names(old, new)[0]["result"] == "unknown"
