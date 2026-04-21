from __future__ import annotations

import csv
import json
import re
from pathlib import Path

from common import REPO_ROOT, load_functions


HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")
BUCKET_COLORS = {
    "matching": "#2e8b57",
    "scratch": "#7b68ee",
    "unclaimed": "#3f4a5a",
    "conflict": "#c0392b",
}


def default_header_notes() -> dict[str, str]:
    return {
        "STATUS": "",
        "FLAGS": "",
        "BLOCKER": "",
        "NOTE": "",
        "CLASS": "",
        "RISK": "",
        "WHY": "",
        "NEXT": "",
    }


def source_files(path: Path) -> dict[str, Path]:
    files: dict[str, Path] = {}
    if not path.exists():
        return files
    for child in sorted(path.iterdir()):
        if child.suffix.lower() not in {".c", ".cpp"}:
            continue
        files[child.stem] = child
    return files


def parse_header_notes(path: Path) -> dict[str, str]:
    notes = default_header_notes()
    if not path.exists():
        return notes

    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    for line in lines:
        stripped = line.strip()
        if not stripped:
            continue
        if not stripped.startswith("//"):
            break
        match = HEADER_NOTE_RE.match(stripped)
        if match is None:
            continue
        key = match.group(1)
        value = match.group(2).strip()
        if key not in notes:
            continue
        if key == "NOTE" and notes[key]:
            notes[key] = notes[key] + " | " + value
        else:
            notes[key] = value
    return notes


def rank_map(records: list[dict[str, str]], field: str) -> dict[str, int]:
    ordered = sorted(records, key=lambda row: (-int(row[field]), row["va"]))
    return {row["va"]: index + 1 for index, row in enumerate(ordered)}


def write_html_dashboard(rows: list[dict[str, str]]) -> Path:
    html_path = REPO_ROOT / "project_full_status.html"

    total_functions = len(rows)
    total_bytes = sum(int(row["size_bytes"]) for row in rows)
    matched_functions = sum(1 for row in rows if row["source_bucket"] == "matching")
    matched_bytes = sum(int(row["size_bytes"]) for row in rows if row["source_bucket"] == "matching")
    remaining_functions = total_functions - matched_functions
    remaining_bytes = total_bytes - matched_bytes

    bucket_order = ["matching", "scratch", "unclaimed", "conflict"]
    bucket_counts = {bucket: sum(1 for row in rows if row["source_bucket"] == bucket) for bucket in bucket_order}
    bucket_bytes = {
        bucket: sum(int(row["size_bytes"]) for row in rows if row["source_bucket"] == bucket)
        for bucket in bucket_order
    }

    groups: dict[str, dict[str, object]] = {}
    for row in rows:
        source_file = row["pdb_source_file"] or "(no pdb source file)"
        source_path = row["pdb_source_path"] or ""
        group = groups.setdefault(
            source_file,
            {
                "name": source_file,
                "path": source_path,
                "value": 0,
                "children": [],
            },
        )
        size_bytes = int(row["size_bytes"])
        group["value"] = int(group["value"]) + size_bytes
        group["children"].append(
            {
                "name": row["name"],
                "va": row["va"],
                "slug": row["slug"],
                "value": size_bytes,
                "asm_lines": int(row["asm_lines"]),
                "bucket": row["source_bucket"],
                "source_path": row["source_path"],
                "note": row["source_note"],
                "blocker": row["source_blocker"],
            }
        )

    group_list = sorted(groups.values(), key=lambda item: (-int(item["value"]), str(item["name"]).lower()))
    for group in group_list:
        group["children"] = sorted(
            group["children"], key=lambda item: (-int(item["value"]), str(item["va"]))
        )

    top_remaining = [
        {
            "va": row["va"],
            "name": row["name"],
            "size_bytes": int(row["size_bytes"]),
            "asm_lines": int(row["asm_lines"]),
            "source_bucket": row["source_bucket"],
            "remaining_size_rank": row["remaining_size_rank"],
            "pdb_source_file": row["pdb_source_file"] or "(no pdb source file)",
        }
        for row in sorted(
            (row for row in rows if row["is_remaining"] == "yes"),
            key=lambda row: (-int(row["size_bytes"]), row["va"]),
        )[:40]
    ]

    progress_functions = 0.0 if total_functions == 0 else (matched_functions / total_functions) * 100.0
    progress_bytes = 0.0 if total_bytes == 0 else (matched_bytes / total_bytes) * 100.0

    summary = {
        "totalFunctions": total_functions,
        "matchedFunctions": matched_functions,
        "remainingFunctions": remaining_functions,
        "totalBytes": total_bytes,
        "matchedBytes": matched_bytes,
        "remainingBytes": remaining_bytes,
        "progressFunctions": round(progress_functions, 2),
        "progressBytes": round(progress_bytes, 2),
        "bucketCounts": bucket_counts,
        "bucketBytes": bucket_bytes,
        "bucketColors": BUCKET_COLORS,
    }

    html_text = f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>aoe1-decomp status</title>
  <style>
    :root {{
      color-scheme: dark;
      --bg: #0f1217;
      --panel: #171b22;
      --panel-2: #1d2330;
      --text: #e7ecf3;
      --muted: #9eabbc;
      --border: #2b3443;
      --accent: #4ea1ff;
    }}
    * {{ box-sizing: border-box; }}
    body {{
      margin: 0;
      font-family: "Segoe UI", Arial, sans-serif;
      background: var(--bg);
      color: var(--text);
    }}
    .page {{
      max-width: 1680px;
      margin: 0 auto;
      padding: 24px;
    }}
    h1, h2, h3, p {{ margin-top: 0; }}
    .subtle {{ color: var(--muted); }}
    .grid {{
      display: grid;
      gap: 16px;
    }}
    .cards {{
      grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
      margin-bottom: 16px;
    }}
    .card {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 10px;
      padding: 14px 16px;
    }}
    .card .value {{
      font-size: 28px;
      font-weight: 700;
    }}
    .bar {{
      height: 12px;
      background: #222b39;
      border-radius: 999px;
      overflow: hidden;
      margin: 8px 0 16px;
      border: 1px solid var(--border);
    }}
    .bar > span {{
      display: block;
      height: 100%;
      background: linear-gradient(90deg, #2e8b57, #49b97d);
    }}
    .bucket-grid {{
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
      gap: 12px;
      margin-bottom: 18px;
    }}
    .bucket {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 10px;
      padding: 12px 14px;
      border-left: 8px solid #555;
    }}
    .bucket .count {{
      font-size: 22px;
      font-weight: 700;
    }}
    .layout {{
      display: grid;
      grid-template-columns: minmax(420px, 1.8fr) minmax(320px, 1fr);
      gap: 16px;
      align-items: start;
    }}
    .panel {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 10px;
      padding: 16px;
    }}
    #treemap {{
      position: relative;
      width: 100%;
      min-height: 780px;
      height: calc(100vh - 220px);
      background: var(--panel-2);
      border: 1px solid var(--border);
      border-radius: 8px;
      overflow: hidden;
      isolation: isolate;
    }}
    .node {{
      position: absolute;
      overflow: hidden;
      border: 1px solid rgba(255,255,255,0.08);
      transition: transform 80ms ease-out, filter 80ms ease-out, box-shadow 80ms ease-out;
      transform-origin: center center;
    }}
    .node.group {{
      background: rgba(255,255,255,0.04);
      cursor: zoom-in;
    }}
    .node.function {{
      color: #fff;
      font-size: 11px;
      line-height: 1.25;
      cursor: default;
    }}
    .node.function.openable {{
      cursor: pointer;
    }}
    .node-content {{
      padding: 6px;
      width: 100%;
      height: 100%;
      overflow: hidden;
      pointer-events: none;
      transition: opacity 140ms ease;
    }}
    .function .meta {{
      opacity: 0.85;
      font-size: 10px;
    }}
    .group-label {{
      position: absolute;
      left: 0;
      top: 0;
      z-index: 2;
      max-width: 100%;
      padding: 6px 8px;
      font-weight: 700;
      font-size: 12px;
      color: #d8e0ea;
      background: linear-gradient(180deg, rgba(0,0,0,0.38), rgba(0,0,0,0));
      pointer-events: none;
      transition: opacity 140ms ease;
    }}
    .group-label.compact {{
      padding: 4px 6px;
      font-size: 11px;
    }}
    .preview-content {{
      position: absolute;
      opacity: 1;
      pointer-events: auto;
      overflow: hidden;
    }}
    .node.group:hover,
    .node.function:hover {{
      z-index: 8;
      filter: brightness(1.08);
      box-shadow: inset 0 0 0 1px rgba(255,255,255,0.28), 0 6px 16px rgba(0,0,0,0.35);
    }}
    .node.group:hover {{
      transform: scale(1.006);
    }}
    .node.function:hover {{
      transform: scale(1.02);
    }}
    .node.tiny {{
      border-width: 0;
    }}
    .node.tiny:hover {{
      transform: none;
      box-shadow: inset 0 0 0 1px rgba(255,255,255,0.55), 0 0 0 1px rgba(0,0,0,0.45);
    }}
    .treemap-breadcrumb {{
      min-height: 18px;
      margin-bottom: 10px;
    }}
    .tooltip {{
      position: fixed;
      left: 0;
      top: 0;
      max-width: min(420px, calc(100vw - 16px));
      padding: 10px 12px;
      border-radius: 8px;
      background: rgba(10, 14, 20, 0.96);
      border: 1px solid rgba(255,255,255,0.12);
      box-shadow: 0 10px 28px rgba(0,0,0,0.45);
      color: var(--text);
      font-size: 12px;
      line-height: 1.35;
      pointer-events: none;
      opacity: 0;
      visibility: hidden;
      transition: opacity 40ms linear;
      z-index: 9999;
    }}
    .tooltip.visible {{
      opacity: 1;
      visibility: visible;
    }}
    .tooltip .title {{
      font-weight: 700;
      margin-bottom: 4px;
    }}
    .tooltip .muted {{
      color: var(--muted);
    }}
    .tooltip code {{
      color: #d7e6ff;
      font-family: Consolas, "Courier New", monospace;
    }}
    table {{
      width: 100%;
      border-collapse: collapse;
      font-size: 13px;
    }}
    th, td {{
      text-align: left;
      padding: 8px 6px;
      border-bottom: 1px solid var(--border);
      vertical-align: top;
    }}
    th {{ color: var(--muted); }}
    .legend {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px 14px;
      margin-bottom: 14px;
    }}
    .legend-item {{
      display: inline-flex;
      align-items: center;
      gap: 8px;
      color: var(--muted);
      font-size: 13px;
    }}
    .swatch {{
      width: 12px;
      height: 12px;
      border-radius: 3px;
      display: inline-block;
    }}
    @media (max-width: 1120px) {{
      .layout {{ grid-template-columns: 1fr; }}
      #treemap {{ height: 640px; min-height: 640px; }}
    }}
  </style>
</head>
<body>
  <div class="page">
    <h1>aoe1-decomp status</h1>
    <p class="subtle">Offline project dashboard generated from <code>inventory\\all_functions.csv</code>, source placement, per-function flags, and structured top comments.</p>

    <div class="grid cards">
      <div class="card"><div class="subtle">Total functions</div><div class="value">{summary["totalFunctions"]}</div></div>
      <div class="card"><div class="subtle">Matched</div><div class="value">{summary["matchedFunctions"]}</div></div>
      <div class="card"><div class="subtle">Remaining</div><div class="value">{summary["remainingFunctions"]}</div></div>
      <div class="card"><div class="subtle">Total bytes</div><div class="value">{summary["totalBytes"]:,}</div></div>
      <div class="card"><div class="subtle">Matched bytes</div><div class="value">{summary["matchedBytes"]:,}</div></div>
      <div class="card"><div class="subtle">Remaining bytes</div><div class="value">{summary["remainingBytes"]:,}</div></div>
    </div>

    <div class="panel">
      <h2>Progress</h2>
      <div class="subtle">By function count — {summary["progressFunctions"]:.2f}%</div>
      <div class="bar"><span style="width:{summary["progressFunctions"]:.2f}%"></span></div>
      <div class="subtle">By code size — {summary["progressBytes"]:.2f}%</div>
      <div class="bar"><span style="width:{summary["progressBytes"]:.2f}%"></span></div>
      <div class="bucket-grid" id="bucket-grid"></div>
    </div>

    <div class="panel" style="margin-top: 16px;">
      <h2>Treemap by original source file</h2>
      <p class="subtle">Groups use PDB-backed source filenames when available. Rectangles are sized by <code>size_bytes</code> and colored by current status.</p>
      <div class="legend" id="legend"></div>
      <div class="treemap-breadcrumb subtle" id="treemap-breadcrumb"></div>
      <div id="treemap"></div>
    </div>

    <div class="panel" style="margin-top: 16px;">
      <h2>Largest remaining functions</h2>
      <table>
        <thead>
          <tr>
            <th>VA</th>
            <th>Name</th>
            <th>File</th>
            <th>Bytes</th>
            <th>Status</th>
          </tr>
        </thead>
        <tbody id="remaining-body"></tbody>
      </table>
    </div>
    <div id="tooltip" class="tooltip"></div>
  </div>

  <script>
    const summary = {json.dumps(summary)};
    const groups = {json.dumps(group_list)};
    const remaining = {json.dumps(top_remaining)};

    function formatNumber(value) {{
      return new Intl.NumberFormat().format(value);
    }}

    function makeLegend() {{
      const legend = document.getElementById("legend");
      for (const [bucket, color] of Object.entries(summary.bucketColors)) {{
        const item = document.createElement("div");
        item.className = "legend-item";
        item.innerHTML = `<span class="swatch" style="background:${{color}}"></span>${{bucket}}`;
        legend.appendChild(item);
      }}
    }}

    function renderBuckets() {{
      const grid = document.getElementById("bucket-grid");
      const order = ["matching", "scratch", "unclaimed", "conflict"];
      for (const bucket of order) {{
        const card = document.createElement("div");
        card.className = "bucket";
        card.style.borderLeftColor = summary.bucketColors[bucket];
        card.innerHTML = `
          <div class="subtle">${{bucket}}</div>
          <div class="count">${{formatNumber(summary.bucketCounts[bucket])}}</div>
          <div class="subtle">${{formatNumber(summary.bucketBytes[bucket])}} bytes</div>
        `;
        grid.appendChild(card);
      }}
    }}

    function renderRemaining() {{
      const body = document.getElementById("remaining-body");
      for (const row of remaining) {{
        const tr = document.createElement("tr");
        tr.innerHTML = `
          <td><code>${{row.va}}</code></td>
          <td>${{row.name}}</td>
          <td>${{row.pdb_source_file}}</td>
          <td>${{formatNumber(row.size_bytes)}}</td>
          <td>${{row.source_bucket}}</td>
        `;
        body.appendChild(tr);
      }}
    }}

    function escapeHtml(value) {{
      return String(value ?? "")
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#39;");
    }}

    function normalizeTreemapItems(items, rect) {{
      const total = items.reduce((sum, item) => sum + item.value, 0);
      const area = rect.width * rect.height;
      if (total <= 0 || area <= 0) {{
        return [];
      }}
      return items
        .filter((item) => item.value > 0)
        .map((item) => {{
          return {{
            item,
            area: (item.value / total) * area,
          }};
        }})
        .sort((a, b) => b.item.value - a.item.value || String(a.item.name).localeCompare(String(b.item.name)));
    }}

    function worstRatio(row, shortSide) {{
      if (!row.length || shortSide <= 0) {{
        return Number.POSITIVE_INFINITY;
      }}
      const areas = row.map((entry) => entry.area);
      const sum = areas.reduce((total, value) => total + value, 0);
      const max = Math.max(...areas);
      const min = Math.min(...areas);
      if (min <= 0 || sum <= 0) {{
        return Number.POSITIVE_INFINITY;
      }}
      const sideSquared = shortSide * shortSide;
      return Math.max((sideSquared * max) / (sum * sum), (sum * sum) / (sideSquared * min));
    }}

    function placeTreemapRow(row, rect) {{
      const rowArea = row.reduce((sum, entry) => sum + entry.area, 0);
      // Squarify lays out strips along the shorter side.
      // In wide boxes that means vertical strips, not thin horizontal bands.
      const layoutHorizontal = rect.width < rect.height;
      const placed = [];

      if (layoutHorizontal) {{
        const rowHeight = rect.width > 0 ? rowArea / rect.width : 0;
        let x = rect.x;
        for (const entry of row) {{
          const width = rowHeight > 0 ? entry.area / rowHeight : 0;
          placed.push({{ item: entry.item, rect: {{ x, y: rect.y, width, height: rowHeight }} }});
          x += width;
        }}
        return {{
          placed,
          remaining: {{
            x: rect.x,
            y: rect.y + rowHeight,
            width: rect.width,
            height: Math.max(rect.height - rowHeight, 0),
          }},
        }};
      }}

      const rowWidth = rect.height > 0 ? rowArea / rect.height : 0;
      let y = rect.y;
      for (const entry of row) {{
        const height = rowWidth > 0 ? entry.area / rowWidth : 0;
        placed.push({{ item: entry.item, rect: {{ x: rect.x, y, width: rowWidth, height }} }});
        y += height;
      }}
      return {{
        placed,
        remaining: {{
          x: rect.x + rowWidth,
          y: rect.y,
          width: Math.max(rect.width - rowWidth, 0),
          height: rect.height,
        }},
      }};
    }}

    function squarify(items, rect) {{
      const working = normalizeTreemapItems(items, rect);
      const placements = [];
      let remaining = {{ ...rect }};
      let row = [];

      while (working.length) {{
        const candidate = working[0];
        const shortSide = Math.min(remaining.width, remaining.height);
        if (!row.length || worstRatio(row.concat(candidate), shortSide) <= worstRatio(row, shortSide)) {{
          row.push(candidate);
          working.shift();
          continue;
        }}
        const placed = placeTreemapRow(row, remaining);
        placements.push(...placed.placed);
        remaining = placed.remaining;
        row = [];
      }}

      if (row.length) {{
        const placed = placeTreemapRow(row, remaining);
        placements.push(...placed.placed);
      }}

      return placements;
    }}

    function addNode(parent, cssClass, rect, label, background) {{
      const node = document.createElement("div");
      node.className = `node ${{cssClass}}`;
      node.style.left = rect.x + "px";
      node.style.top = rect.y + "px";
      node.style.width = Math.max(rect.width, 0) + "px";
      node.style.height = Math.max(rect.height, 0) + "px";
      if (background) {{
        node.style.background = background;
      }}
      if (label) {{
        const content = document.createElement("div");
        content.className = "node-content";
        content.innerHTML = label;
        node.appendChild(content);
      }}
      parent.appendChild(node);
      return node;
    }}

    const tooltip = document.getElementById("tooltip");
    let activeGroupName = null;

    function moveTooltip(event) {{
      if (!tooltip.classList.contains("visible")) {{
        return;
      }}
      const pad = 14;
      const rect = tooltip.getBoundingClientRect();
      let left = event.clientX + pad;
      let top = event.clientY + pad;
      if (left + rect.width > window.innerWidth - 8) {{
        left = Math.max(8, event.clientX - rect.width - pad);
      }}
      if (top + rect.height > window.innerHeight - 8) {{
        top = Math.max(8, event.clientY - rect.height - pad);
      }}
      tooltip.style.left = left + "px";
      tooltip.style.top = top + "px";
    }}

    function showTooltip(content, event) {{
      tooltip.innerHTML = content;
      tooltip.classList.add("visible");
      moveTooltip(event);
    }}

    function hideTooltip() {{
      tooltip.classList.remove("visible");
    }}

    function bindTooltip(node, renderContent) {{
      node.addEventListener("mouseenter", (event) => {{
        showTooltip(renderContent(), event);
      }});
      node.addEventListener("mousemove", moveTooltip);
      node.addEventListener("mouseleave", hideTooltip);
    }}

    function groupTooltip(group) {{
      return `
        <div class="title">${{escapeHtml(group.name)}}</div>
        <div class="muted">${{escapeHtml(group.path || "(no PDB path)")}}</div>
        <div>${{formatNumber(group.value)}} bytes across ${{formatNumber(group.children.length)}} functions</div>
        <div class="muted">Click to zoom into this source file.</div>
      `;
    }}

    function functionTooltip(group, child) {{
      return `
        <div class="title"><code>${{escapeHtml(child.va)}}</code> ${{escapeHtml(child.name)}}</div>
        <div>${{formatNumber(child.value)}} bytes · ${{formatNumber(child.asm_lines)}} asm lines · ${{escapeHtml(child.bucket)}}</div>
        <div class="muted">${{escapeHtml(group.name)}}</div>
        <div class="muted">${{escapeHtml(child.source_path || "(no source file in repo)")}}</div>
        ${{child.note ? `<div>${{escapeHtml(child.note)}}</div>` : ""}}
        ${{child.blocker ? `<div><strong>BLOCKER:</strong> ${{escapeHtml(child.blocker)}}</div>` : ""}}
        ${{child.source_path ? `<div class="muted">Click to open this generated source file.</div>` : ""}}
      `;
    }}

    function toRepoFileUrl(relativePath) {{
      const normalized = String(relativePath || "").replace(/\\\\/g, "/");
      if (!normalized) {{
        return "";
      }}
      return new URL(normalized, window.location.href).href;
    }}

    function renderFunctionTiles(parent, group, rect, options = {{}}) {{
      const revealOnParentHover = Boolean(options.revealOnParentHover);
      const openSourceOnClick = Boolean(options.openSourceOnClick);
      const tiles = squarify(group.children, rect);
      for (const entry of tiles) {{
        const child = entry.item;
        const childRect = entry.rect;
        if (childRect.width < 2 || childRect.height < 2) {{
          continue;
        }}
        const bucketColor = summary.bucketColors[child.bucket] || "#555";
        const showLabel = childRect.width > 90 && childRect.height > 42;
        const compactNameLabel = !showLabel && childRect.width > 64 && childRect.height > 24;
        const compactLabel = !showLabel && !compactNameLabel && childRect.width > 50 && childRect.height > 18;
        const label = showLabel
          ? `<div>${{escapeHtml(child.va)}}</div><div>${{escapeHtml(child.name)}}</div><div class="meta">${{formatNumber(child.value)}} bytes</div>`
          : compactNameLabel
            ? `<div>${{escapeHtml(child.va)}}</div><div class="meta">${{escapeHtml(child.name)}}</div>`
          : compactLabel
            ? `<div>${{escapeHtml(child.va)}}</div>`
            : "";
        const node = addNode(parent, "function", childRect, label, bucketColor);
        if (revealOnParentHover) {{
          node.classList.add("preview-child");
        }}
        if (openSourceOnClick && child.source_path) {{
          node.classList.add("openable");
          node.addEventListener("click", (event) => {{
            event.stopPropagation();
            const url = toRepoFileUrl(child.source_path);
            if (url) {{
              window.open(url, "_blank", "noopener");
            }}
          }});
        }}
        if (childRect.width < 12 || childRect.height < 12) {{
          node.classList.add("tiny");
        }}
        bindTooltip(node, () => functionTooltip(group, child));
      }}
    }}

    function renderTreemap() {{
      const container = document.getElementById("treemap");
      const breadcrumb = document.getElementById("treemap-breadcrumb");
      container.innerHTML = "";
      container.onclick = (event) => {{
        if (event.target === container && activeGroupName !== null) {{
          activeGroupName = null;
          renderTreemap();
        }}
      }};
      const width = container.clientWidth;
      const height = container.clientHeight;
      const activeGroup = activeGroupName ? groups.find((group) => group.name === activeGroupName) : null;

      if (activeGroup) {{
        breadcrumb.textContent = `Viewing ${{activeGroup.name}} — click a function tile to open its current file, or click empty background to reset.`;
        renderFunctionTiles(container, activeGroup, {{ x: 0, y: 0, width, height }}, {{ openSourceOnClick: true }});
        return;
      }}

      breadcrumb.textContent = "Click a source-file tile to zoom. Hover any tile for immediate details.";
      const top = squarify(groups, {{ x: 0, y: 0, width, height }});
      for (const entry of top) {{
        const group = entry.item;
        const groupRect = entry.rect;
        if (groupRect.width < 3 || groupRect.height < 3) {{
          continue;
        }}
        const showGroupLabel = groupRect.width > 120 && groupRect.height > 34;
        const compactGroupLabel = !showGroupLabel && groupRect.width > 56 && groupRect.height > 18;
        const groupNode = addNode(
          container,
          "group",
          groupRect,
          "",
          "rgba(255,255,255,0.03)"
        );
        groupNode.classList.add("preview-group");
        if (groupRect.width < 14 || groupRect.height < 14) {{
          groupNode.classList.add("tiny");
        }}
        bindTooltip(groupNode, () => groupTooltip(group));
        groupNode.addEventListener("click", (event) => {{
          event.stopPropagation();
          activeGroupName = group.name;
          renderTreemap();
        }});

        if (showGroupLabel || compactGroupLabel) {{
          const overlay = document.createElement("div");
          overlay.className = `group-label${{compactGroupLabel && !showGroupLabel ? " compact" : ""}}`;
          overlay.innerHTML = showGroupLabel
            ? `<div>${{escapeHtml(group.name)}}</div><div class="meta">${{formatNumber(group.value)}} bytes</div>`
            : `<div>${{escapeHtml(group.name)}}</div>`;
          groupNode.appendChild(overlay);
        }}

        if (groupRect.width < 18 || groupRect.height < 18) {{
          continue;
        }}
        const childHost = document.createElement("div");
        childHost.className = "preview-content";
        childHost.style.left = "0px";
        childHost.style.top = "0px";
        childHost.style.width = groupRect.width + "px";
        childHost.style.height = groupRect.height + "px";
        groupNode.appendChild(childHost);
        renderFunctionTiles(
          childHost,
          group,
          {{ x: 0, y: 0, width: groupRect.width, height: groupRect.height }},
          {{ revealOnParentHover: true }}
        );
      }}
    }}

    makeLegend();
    renderBuckets();
    renderRemaining();
    renderTreemap();

    const treemapContainer = document.getElementById("treemap");
    if (window.ResizeObserver) {{
      const treemapResizeObserver = new ResizeObserver(() => {{
        renderTreemap();
      }});
      treemapResizeObserver.observe(treemapContainer);
    }} else {{
      window.addEventListener("resize", renderTreemap);
    }}
  </script>
</body>
</html>
"""

    html_path.write_text(html_text, encoding="utf-8")
    return html_path


def main() -> None:
    scratch_dir = REPO_ROOT / "src" / "scratch"
    matching_dir = REPO_ROOT / "src" / "matching"
    flags_dir = REPO_ROOT / "config" / "flags"
    scratch_files = source_files(scratch_dir)
    matching_files = source_files(matching_dir)

    records = load_functions()
    remaining_records: list[dict[str, str]] = []
    rows: list[dict[str, str]] = []

    for record in records:
        slug = record["slug"]
        scratch_path = scratch_files.get(slug)
        matching_path = matching_files.get(slug)

        present_paths = [path for path in (matching_path, scratch_path) if path is not None]
        if len(present_paths) > 1:
            source_bucket = "conflict"
            source_path = " | ".join(str(path.relative_to(REPO_ROOT)) for path in present_paths)
            note_path = scratch_path
        elif matching_path:
            source_bucket = "matching"
            source_path = str(matching_path.relative_to(REPO_ROOT))
            note_path = None
        elif scratch_path:
            source_bucket = "scratch"
            source_path = str(scratch_path.relative_to(REPO_ROOT))
            note_path = scratch_path
        else:
            source_bucket = "unclaimed"
            source_path = ""
            note_path = None

        custom_flags_path = flags_dir / f"{slug}.rsp"
        header_notes = parse_header_notes(note_path) if note_path is not None else default_header_notes()
        is_remaining = "yes" if source_bucket != "matching" else "no"

        row = {
            "va": record["va"],
            "name": record["name"],
            "slug": slug,
            "size_bytes": record["size_bytes"],
            "asm_lines": record["asm_lines"],
            "calling_convention": record["calling_convention"],
            "pdb_source_file": record.get("pdb_source_file", ""),
            "pdb_source_path": record.get("pdb_source_path", ""),
            "source_bucket": source_bucket,
            "source_path": source_path,
            "is_remaining": is_remaining,
            "remaining_size_rank": "",
            "remaining_asm_rank": "",
            "uses_custom_flags": "yes" if custom_flags_path.exists() else "no",
            "custom_flags_path": str(custom_flags_path.relative_to(REPO_ROOT)) if custom_flags_path.exists() else "",
            "source_status": header_notes["STATUS"],
            "source_flags_note": header_notes["FLAGS"],
            "source_blocker": header_notes["BLOCKER"],
            "source_note": header_notes["NOTE"],
            "source_class": header_notes["CLASS"],
            "source_risk": header_notes["RISK"],
            "source_why": header_notes["WHY"],
            "source_next": header_notes["NEXT"],
            "has_blocker": "yes" if header_notes["BLOCKER"] else "no",
        }
        rows.append(row)
        if is_remaining == "yes":
            remaining_records.append(record)

    size_ranks = rank_map(remaining_records, "size_bytes")
    asm_ranks = rank_map(remaining_records, "asm_lines")
    for row in rows:
        if row["is_remaining"] == "yes":
            row["remaining_size_rank"] = str(size_ranks[row["va"]])
            row["remaining_asm_rank"] = str(asm_ranks[row["va"]])

    output_path = REPO_ROOT / "project_full_status.csv"
    with output_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "va",
                "name",
                "slug",
                "size_bytes",
                "asm_lines",
                "calling_convention",
                "pdb_source_file",
                "pdb_source_path",
                "source_bucket",
                "source_path",
                "is_remaining",
                "remaining_size_rank",
                "remaining_asm_rank",
                "uses_custom_flags",
                "custom_flags_path",
                "source_status",
                "source_flags_note",
                "source_blocker",
                "source_note",
                "source_class",
                "source_risk",
                "source_why",
                "source_next",
                "has_blocker",
            ],
        )
        writer.writeheader()
        writer.writerows(rows)

    html_output_path = write_html_dashboard(rows)

    scratch_count = sum(1 for row in rows if row["source_bucket"] == "scratch")
    matching_count = sum(1 for row in rows if row["source_bucket"] == "matching")
    conflict_count = sum(1 for row in rows if row["source_bucket"] == "conflict")
    unclaimed_count = sum(1 for row in rows if row["source_bucket"] == "unclaimed")

    print(f"Wrote {output_path}")
    print(f"Wrote {html_output_path}")
    print(
        "Counts: "
        f"matching={matching_count} "
        f"scratch={scratch_count} "
        f"unclaimed={unclaimed_count} "
        f"conflict={conflict_count}"
    )


if __name__ == "__main__":
    main()
