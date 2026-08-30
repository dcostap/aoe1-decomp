from __future__ import annotations

import argparse
import csv
import re
from dataclasses import dataclass
from pathlib import Path

from common import REPO_ROOT, ensure_dir, repo_path, slugify_name
from generate_type_reference import parse_types


CLASS_START_RE = re.compile(r"^class\s+([A-Za-z_][A-Za-z0-9_:]*)(?:\s*:\s*public\s+([A-Za-z_][A-Za-z0-9_:]*))?\s*\{$")
STATIC_ASSERT_RE = re.compile(r'^static_assert\(sizeof\(([^)]+)\)\s*==\s*(0x[0-9A-Fa-f]+),')
VIRTUAL_SLOT_RE = re.compile(r"vt\[(\d+)\]\s*\((0x[0-9A-Fa-f]+)\)")
METHOD_NAME_RE = re.compile(r"(operator[^\s(]+|[~A-Za-z_][A-Za-z0-9_]*)\s*\(")
QUALIFIED_METHOD_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_:]*)::(~?[A-Za-z_][A-Za-z0-9_]*)")


@dataclass(frozen=True)
class LayoutType:
    name: str
    base: str
    size_bytes: int
    size_hex: str
    kind: str


@dataclass(frozen=True)
class DonorMethod:
    kind: str
    method_name: str
    declaration: str
    slot_index: int | None
    slot_hex: str
    confidence: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class DonorClass:
    name: str
    donor_header: str
    base: str
    donor_size_hex: str
    class_confidence: str
    class_evidence: tuple[str, ...]
    methods: tuple[DonorMethod, ...]


def donor_include_root() -> Path:
    return (REPO_ROOT.parent / "aoe1" / "src" / "game" / "include").resolve()


def load_layout_types() -> dict[str, LayoutType]:
    source_path = repo_path("inventory") / "types" / "all_types_reference.h"
    lines = source_path.read_text(encoding="utf-8", errors="replace").splitlines()
    result: dict[str, LayoutType] = {}
    for entry in parse_types(lines):
        if entry["kind"] != "class":
            continue
        name = str(entry["name"])
        result[name] = LayoutType(
            name=name,
            base=str(entry["base"] or ""),
            size_bytes=int(entry["size_bytes"]),
            size_hex=str(entry["size_hex"]),
            kind=str(entry["kind"]),
        )
    return result


def build_packet_method_index() -> set[tuple[str, str]]:
    packet_root = repo_path("inventory") / "functions"
    qualified: set[tuple[str, str]] = set()
    for packet_path in sorted(packet_root.rglob("*.txt")):
        text = packet_path.read_text(encoding="utf-8", errors="replace")
        for match in QUALIFIED_METHOD_RE.finditer(text):
            qualified.add((match.group(1), match.group(2)))
    return qualified


def declaration_name(class_name: str, declaration: str) -> str:
    match = METHOD_NAME_RE.search(declaration)
    if match is None:
        raise ValueError(f"Could not determine method name from declaration: {declaration}")
    name = match.group(1)
    if name == class_name or name == f"~{class_name}":
        return name
    return name


def normalize_declaration(line: str) -> str:
    declaration = line.split("//", 1)[0].strip()
    if declaration.endswith(";"):
        declaration = declaration[:-1].rstrip()
    return declaration


def parse_donor_class(
    class_name: str,
    donor_header: str,
    donor_base: str,
    donor_size_hex: str,
    body_lines: list[str],
    layout: LayoutType,
    packet_methods: set[tuple[str, str]],
) -> DonorClass:
    class_evidence: list[str] = ["layout-class", "donor-header"]
    if donor_base and donor_base == layout.base:
        class_evidence.append("layout-base-match")
    elif donor_base or layout.base:
        class_evidence.append("layout-base-mismatch")

    if donor_size_hex and donor_size_hex.lower() == layout.size_hex.lower():
        class_evidence.append("layout-size-match")
    elif donor_size_hex:
        class_evidence.append("layout-size-mismatch")

    if "layout-size-match" in class_evidence and "layout-base-mismatch" not in class_evidence:
        class_confidence = "high"
    else:
        class_confidence = "medium"

    methods: list[DonorMethod] = []
    for raw_line in body_lines:
        line = raw_line.strip()
        if not line or line.startswith("//"):
            continue
        if "(" not in line or ");" not in line:
            continue

        declaration = normalize_declaration(line)
        if not declaration:
            continue
        method_name = declaration_name(class_name, declaration)

        slot_index: int | None = None
        slot_hex = ""
        slot_match = VIRTUAL_SLOT_RE.search(line)
        evidence: list[str] = ["donor-header"]
        if slot_match:
            slot_index = int(slot_match.group(1))
            slot_hex = slot_match.group(2).upper()
            evidence.append("donor-slot")

        if (class_name, method_name) in packet_methods:
            evidence.append("packet-qualified-name")

        if slot_index is not None:
            evidence.append("layout-class")
            if class_confidence == "high" and "packet-qualified-name" in evidence:
                confidence = "high"
            else:
                confidence = "medium"
            kind = "virtual"
        elif method_name == class_name:
            kind = "ctor"
            confidence = "medium" if "packet-qualified-name" in evidence and class_confidence == "high" else "low"
        elif method_name == f"~{class_name}":
            kind = "dtor"
            confidence = "medium" if "packet-qualified-name" in evidence and class_confidence == "high" else "low"
        else:
            kind = "helper"
            confidence = "medium" if "packet-qualified-name" in evidence and class_confidence == "high" else "low"

        methods.append(
            DonorMethod(
                kind=kind,
                method_name=method_name,
                declaration=declaration,
                slot_index=slot_index,
                slot_hex=slot_hex,
                confidence=confidence,
                evidence=tuple(evidence),
            )
        )

    methods.sort(key=lambda item: (0 if item.slot_index is not None else 1, item.slot_index or 0, item.method_name))
    return DonorClass(
        name=class_name,
        donor_header=donor_header,
        base=donor_base,
        donor_size_hex=donor_size_hex.upper(),
        class_confidence=class_confidence,
        class_evidence=tuple(class_evidence),
        methods=tuple(methods),
    )


def parse_donor_headers(layout_types: dict[str, LayoutType], packet_methods: set[tuple[str, str]]) -> list[DonorClass]:
    include_root = donor_include_root()
    if not include_root.exists():
        raise FileNotFoundError(f"Donor include root not found: {include_root}")

    classes: list[DonorClass] = []
    for header_path in sorted(include_root.glob("*.h")):
        lines = header_path.read_text(encoding="utf-8", errors="replace").splitlines()
        index = 0
        while index < len(lines):
            start_match = CLASS_START_RE.match(lines[index].strip())
            if start_match is None:
                index += 1
                continue

            class_name = start_match.group(1)
            donor_base = start_match.group(2) or ""
            body_start = index + 1
            body_end = body_start
            while body_end < len(lines) and lines[body_end].strip() != "};":
                body_end += 1
            if body_end >= len(lines):
                break

            donor_size_hex = ""
            probe = body_end + 1
            while probe < len(lines) and not lines[probe].strip():
                probe += 1
            if probe < len(lines):
                size_match = STATIC_ASSERT_RE.match(lines[probe].strip())
                if size_match and size_match.group(1) == class_name:
                    donor_size_hex = size_match.group(2)

            layout = layout_types.get(class_name)
            if layout is not None:
                donor_header = str(header_path.relative_to(include_root.parent.parent.parent))
                classes.append(
                    parse_donor_class(
                        class_name,
                        donor_header,
                        donor_base,
                        donor_size_hex,
                        lines[body_start:body_end],
                        layout,
                        packet_methods,
                    )
                )

            index = body_end + 1

    classes.sort(key=lambda item: item.name)
    return classes


def build_reference_header(classes: list[DonorClass], layout_types: dict[str, LayoutType]) -> str:
    lines = [
        "#pragma once",
        "// Generated by tools\\generate_class_interface_reference.py.",
        "// Read-only best-effort class interface reference.",
        "// This is a confidence-tagged donor layer, not the compiler-facing source of truth.",
        "",
    ]

    for entry in classes:
        layout = layout_types[entry.name]
        lines.append(f"// Class: {entry.name}")
        lines.append(f"// DonorHeader: {entry.donor_header}")
        lines.append(f"// ClassConfidence: {entry.class_confidence}")
        lines.append(f"// ClassEvidence: {', '.join(entry.class_evidence)}")
        base = f" : public {layout.base}" if layout.base else ""
        lines.append(f"class {entry.name}{base} {{")
        lines.append("public:")
        if not entry.methods:
            lines.append("};")
        else:
            for method in entry.methods:
                suffix = ""
                if method.slot_index is not None:
                    suffix = f" // vt[{method.slot_index}] ({method.slot_hex})"
                lines.append(
                    f"    {method.declaration}; // confidence: {method.confidence}; evidence: {', '.join(method.evidence)}{suffix}"
                )
            lines.append("};")
        lines.append(f'static_assert(sizeof({entry.name}) == {layout.size_hex.upper()}, "Reference size mismatch");')
        lines.append("")

    return "\n".join(lines)


def write_class_packets(classes: list[DonorClass], layout_types: dict[str, LayoutType], packet_root: Path) -> None:
    ensure_dir(packet_root)
    for entry in classes:
        layout = layout_types[entry.name]
        packet_lines = [
            f"Class: {entry.name}",
            f"DonorHeader: {entry.donor_header}",
            f"LayoutBase: {layout.base or '<none>'}",
            f"DonorBase: {entry.base or '<none>'}",
            f"LayoutSizeBytes: {layout.size_bytes}",
            f"LayoutSizeHex: {layout.size_hex.upper()}",
            f"DonorSizeHex: {entry.donor_size_hex or '<none>'}",
            f"ClassConfidence: {entry.class_confidence}",
            f"ClassEvidence: {', '.join(entry.class_evidence)}",
            f"MethodCount: {len(entry.methods)}",
            "",
            "=== Methods ===",
        ]
        if not entry.methods:
            packet_lines.append("<none>")
        else:
            for method in entry.methods:
                slot_part = f" vt[{method.slot_index}] {method.slot_hex}" if method.slot_index is not None else ""
                packet_lines.append(
                    f"{method.kind}:{slot_part} confidence={method.confidence} :: {method.declaration}; :: evidence={', '.join(method.evidence)}"
                )

        packet_path = packet_root / f"{slugify_name(entry.name)}.txt"
        packet_path.write_text("\n".join(packet_lines) + "\n", encoding="utf-8")


def write_csv(classes: list[DonorClass], csv_path: Path) -> None:
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "class_name",
                "donor_header",
                "class_confidence",
                "class_evidence",
                "method_kind",
                "method_name",
                "declaration",
                "slot_index",
                "slot_hex",
                "method_confidence",
                "method_evidence",
            ],
        )
        writer.writeheader()
        for entry in classes:
            for method in entry.methods:
                writer.writerow(
                    {
                        "class_name": entry.name,
                        "donor_header": entry.donor_header,
                        "class_confidence": entry.class_confidence,
                        "class_evidence": ",".join(entry.class_evidence),
                        "method_kind": method.kind,
                        "method_name": method.method_name,
                        "declaration": method.declaration,
                        "slot_index": "" if method.slot_index is None else method.slot_index,
                        "slot_hex": method.slot_hex,
                        "method_confidence": method.confidence,
                        "method_evidence": ",".join(method.evidence),
                    }
                )


def main() -> None:
    argparse.ArgumentParser(
        description="Generate class interface references from layout and donor evidence."
    ).parse_args()

    layout_types = load_layout_types()
    packet_methods = build_packet_method_index()
    classes = parse_donor_headers(layout_types, packet_methods)

    inventory_root = repo_path("inventory") / "classes"
    dumps_root = inventory_root / "dumps"
    ensure_dir(inventory_root)

    reference_header_path = inventory_root / "all_class_interfaces_reference.h"
    csv_path = inventory_root / "all_class_interfaces.csv"

    reference_header_path.write_text(build_reference_header(classes, layout_types), encoding="utf-8")
    write_csv(classes, csv_path)
    write_class_packets(classes, layout_types, dumps_root)

    print(f"Wrote {reference_header_path}")
    print(f"Wrote {csv_path}")
    print(f"Wrote {len(classes)} class interface packets under {dumps_root}")


if __name__ == "__main__":
    main()
