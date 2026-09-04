import { describe, expect, test } from "bun:test";
import { countManifestEntries, parseRegistryStatuses } from "./core.ts";
import { formatScratchActivity, ONE_HOUR_MS, restoreScratchEvents, summarizeScratchEvents } from "./events.ts";

describe("function status parsing", () => {
	test("counts the supported statuses and reports unknown entries", () => {
		const result = parseRegistryStatuses(JSON.stringify({
			functions: {
				one: { status: "matching" },
				two: { status: "scratch" },
				three: { status: "accepted_drift" },
				four: { status: "future_status" },
				five: {},
			},
		}));

		expect(result.total).toBe(5);
		expect(result.statusCounts.matching).toBe(1);
		expect(result.statusCounts.scratch).toBe(1);
		expect(result.statusCounts.accepted_drift).toBe(1);
		expect(result.unknownStatusCount).toBe(2);
	});

	test("ignores blank and comment lines in manifests", () => {
		expect(countManifestEntries("# heading\n\n00400000 reason\n symbol\n")).toBe(2);
	});

	test("restores valid decrease events and summarizes the last hour", () => {
		const now = 1_000_000;
		const events = restoreScratchEvents([
			{ type: "custom", customType: "other", data: { timestamp: now, matches: 9 } },
			{ type: "custom", customType: "aoe1-scratch-decrease", data: {
				timestamp: now - 2 * ONE_HOUR_MS,
				previousCount: 10,
				currentCount: 8,
				matches: 2,
			} },
			{ type: "custom", customType: "aoe1-scratch-decrease", data: {
				timestamp: now - 30 * 60_000,
				previousCount: 8,
				currentCount: 6,
				matches: 2,
			} },
			{ type: "custom", customType: "aoe1-scratch-decrease", data: {
				timestamp: now,
				previousCount: 6,
				currentCount: 5,
				matches: 1,
			} },
		]);

		expect(events).toHaveLength(3);
		expect(summarizeScratchEvents(events, now)).toEqual({
			totalEvents: 3,
			totalMatches: 5,
			lastHourEvents: 2,
			lastHourMatches: 3,
		});
	});

	test("formats total and hourly scratch exits", () => {
		expect(formatScratchActivity({
			totalEvents: 4,
			totalMatches: 1_234,
			lastHourEvents: 2,
			lastHourMatches: 7,
		})).toBe("scratch exits 1,234 · 7/hr");
	});
});
