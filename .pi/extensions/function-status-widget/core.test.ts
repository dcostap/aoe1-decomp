import { describe, expect, test } from "bun:test";
import { countManifestEntries, parseRegistryStatuses } from "./core.ts";

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
});
