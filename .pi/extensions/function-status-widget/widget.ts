import type { Theme } from "@earendil-works/pi-coding-agent";
import { truncateToWidth, visibleWidth } from "@earendil-works/pi-tui";
import type { FunctionStats } from "./core.ts";
import { formatScratchActivity, type ScratchEventSummary } from "./events.ts";

const numberFormat = new Intl.NumberFormat("en-US");

function count(value: number): string {
	return numberFormat.format(value);
}

function separator(theme: Theme): string {
	return theme.fg("dim", " · ");
}

function statusPart(theme: Theme, color: Parameters<Theme["fg"]>[0], value: number, label: string): string {
	return theme.fg(color, `${count(value)} ${label}`);
}

function normalLine(stats: FunctionStats, theme: Theme): string {
	const status = stats.statusCounts;
	const parts = [
		theme.fg("toolTitle", theme.bold(`Functions ${count(stats.total)}`)),
		statusPart(theme, "success", status.matching, "matching"),
		statusPart(theme, "accent", status.accepted_drift, "accepted drift"),
		statusPart(theme, "muted", status.verified_logic, "verified logic"),
		statusPart(theme, "warning", status.scratch, "scratch"),
		statusPart(theme, "error", status.unresolved, "unresolved"),
	];

	if (stats.unknownStatusCount > 0) {
		parts.push(statusPart(theme, "warning", stats.unknownStatusCount, "unknown"));
	}
	if (stats.readErrorCount > 0) {
		parts.push(statusPart(theme, "error", stats.readErrorCount, "read errors"));
	}
	return parts.join(separator(theme));
}

function detailedLine(stats: FunctionStats, theme: Theme): string {
	const special = stats.specialCounts;
	const parts = [
		normalLine(stats, theme),
		theme.fg("dim", "excluded"),
		statusPart(theme, "dim", special.padding, "padding-only"),
		statusPart(theme, "dim", special.compiler_generated, "compiler-generated"),
		statusPart(theme, "dim", special.parent_owned, "parent-owned"),
		statusPart(theme, "dim", special.toolchain, "toolchain"),
		statusPart(theme, "dim", special.asm_special, "asm-special"),
	];
	return parts.join(separator(theme));
}

function compactLine(stats: FunctionStats, theme: Theme): string {
	const status = stats.statusCounts;
	const parts = [
		theme.fg("toolTitle", theme.bold(`Fn ${count(stats.total)}`)),
		theme.fg("success", `✓${count(status.matching)} match`),
		theme.fg("accent", `≈${count(status.accepted_drift)} drift`),
		theme.fg("muted", `◆${count(status.verified_logic)} logic`),
		theme.fg("warning", `~${count(status.scratch)} scratch`),
		theme.fg("error", `!${count(status.unresolved)} unres`),
	];

	if (stats.unknownStatusCount > 0) parts.push(theme.fg("warning", `?${count(stats.unknownStatusCount)} unknown`));
	if (stats.readErrorCount > 0) parts.push(theme.fg("error", `!${count(stats.readErrorCount)} errors`));
	return parts.join(separator(theme));
}

function scratchActivityLine(summary: ScratchEventSummary, theme: Theme): string {
	return theme.fg("dim", formatScratchActivity(summary));
}

export function functionStatusLine(
	stats: FunctionStats,
	scratchSummary: ScratchEventSummary,
	theme: Theme,
	width: number,
): string {
	if (width <= 0) return "";
	const detailed = detailedLine(stats, theme);
	const normal = normalLine(stats, theme);
	const compact = compactLine(stats, theme);
	const activity = scratchActivityLine(scratchSummary, theme);
	for (const base of [detailed, normal, compact]) {
		const line = `${base}${separator(theme)}${activity}`;
		if (visibleWidth(line) <= width) return line;
	}
	if (visibleWidth(detailed) <= width) return detailed;
	const line = visibleWidth(normal) <= width ? normal : compact;
	return truncateToWidth(line, width, "…");
}

export function functionStatusWidgetComponent(
	stats: FunctionStats,
	scratchSummary: ScratchEventSummary,
	theme: Theme,
) {
	return {
		render(width: number): string[] {
			return [functionStatusLine(stats, scratchSummary, theme, width)];
		},
		invalidate(): void {},
	};
}

export function functionStatusErrorWidgetComponent(message: string, theme: Theme) {
	return {
		render(width: number): string[] {
			if (width <= 0) return [""];
			return [truncateToWidth(theme.fg("error", `Function status: ${message}`), width, "…")];
		},
		invalidate(): void {},
	};
}
