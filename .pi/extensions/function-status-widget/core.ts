import { readdir, readFile } from "node:fs/promises";
import { join } from "node:path";

export const FUNCTION_STATUSES = [
	"matching",
	"accepted_drift",
	"verified_logic",
	"scratch",
	"unresolved",
] as const;

export type FunctionStatus = (typeof FUNCTION_STATUSES)[number];

export const SPECIAL_CATEGORIES = [
	"padding",
	"compiler_generated",
	"parent_owned",
	"toolchain",
	"asm_special",
] as const;

export type SpecialCategory = (typeof SPECIAL_CATEGORIES)[number];

export type FunctionStats = {
	statusCounts: Record<FunctionStatus, number>;
	specialCounts: Record<SpecialCategory, number>;
	total: number;
	unknownStatusCount: number;
	readErrorCount: number;
	registryFileCount: number;
};

type ParsedRegistry = Pick<FunctionStats, "statusCounts" | "total" | "unknownStatusCount">;

const MANIFESTS: ReadonlyArray<readonly [SpecialCategory, string]> = [
	["padding", "padding_only_functions.txt"],
	["compiler_generated", "compiler_generated_functions.txt"],
	["parent_owned", "parent_owned_fragments.txt"],
	["toolchain", "toolchain_supplied_functions.txt"],
	["asm_special", "asm_special_functions.txt"],
];

function emptyStatusCounts(): Record<FunctionStatus, number> {
	return {
		matching: 0,
		accepted_drift: 0,
		verified_logic: 0,
		scratch: 0,
		unresolved: 0,
	};
}

function emptySpecialCounts(): Record<SpecialCategory, number> {
	return {
		padding: 0,
		compiler_generated: 0,
		parent_owned: 0,
		toolchain: 0,
		asm_special: 0,
	};
}

function isRecord(value: unknown): value is Record<string, unknown> {
	return typeof value === "object" && value !== null;
}

function isFunctionStatus(value: string): value is FunctionStatus {
	return (FUNCTION_STATUSES as readonly string[]).includes(value);
}

export function parseRegistryStatuses(text: string): ParsedRegistry {
	const parsed: unknown = JSON.parse(text);
	const functions = isRecord(parsed) && isRecord(parsed.functions) ? parsed.functions : {};
	const statusCounts = emptyStatusCounts();
	let total = 0;
	let unknownStatusCount = 0;

	for (const value of Object.values(functions)) {
		total += 1;
		const status = isRecord(value) && typeof value.status === "string" ? value.status : undefined;
		if (status && isFunctionStatus(status)) statusCounts[status] += 1;
		else unknownStatusCount += 1;
	}

	return { statusCounts, total, unknownStatusCount };
}

export function countManifestEntries(text: string): number {
	return text
		.split(/\r?\n/)
		.filter((line) => {
			const trimmed = line.trim();
			return trimmed.length > 0 && !trimmed.startsWith("#");
		})
		.length;
}

function throwIfAborted(signal?: AbortSignal): void {
	if (!signal?.aborted) return;
	const error = new Error("Function status scan aborted");
	error.name = "AbortError";
	throw error;
}

async function findRegistryFiles(root: string, signal?: AbortSignal): Promise<string[]> {
	const pending = [root];
	const files: string[] = [];

	while (pending.length > 0) {
		throwIfAborted(signal);
		const directory = pending.pop()!;
		const entries = await readdir(directory, { withFileTypes: true });
		for (const entry of entries) {
			const path = join(directory, entry.name);
			if (entry.isDirectory()) pending.push(path);
			else if (entry.isFile() && entry.name.endsWith(".json")) files.push(path);
		}
	}

	return files.sort();
}

export async function scanFunctionStats(cwd: string, signal?: AbortSignal): Promise<FunctionStats> {
	const registryFiles = await findRegistryFiles(join(cwd, "config", "functions"), signal);
	const statusCounts = emptyStatusCounts();
	const specialCounts = emptySpecialCounts();
	let total = 0;
	let unknownStatusCount = 0;
	let readErrorCount = 0;

	const registryResults = await Promise.all(
		registryFiles.map(async (path): Promise<ParsedRegistry | undefined> => {
			try {
				throwIfAborted(signal);
				const result = parseRegistryStatuses(await readFile(path, "utf8"));
				throwIfAborted(signal);
				return result;
			} catch (error) {
				if (error instanceof Error && error.name === "AbortError") throw error;
				readErrorCount += 1;
				return undefined;
			}
		}),
	);

	for (const result of registryResults) {
		if (!result) continue;
		total += result.total;
		unknownStatusCount += result.unknownStatusCount;
		for (const status of FUNCTION_STATUSES) statusCounts[status] += result.statusCounts[status];
	}

	const manifestResults = await Promise.all(
		MANIFESTS.map(async ([category, filename]) => {
			try {
				throwIfAborted(signal);
				const count = countManifestEntries(await readFile(join(cwd, "config", filename), "utf8"));
				throwIfAborted(signal);
				return [category, count] as const;
			} catch (error) {
				if (error instanceof Error && error.name === "AbortError") throw error;
				readErrorCount += 1;
				return [category, 0] as const;
			}
		}),
	);

	for (const [category, count] of manifestResults) specialCounts[category] = count;

	return {
		statusCounts,
		specialCounts,
		total,
		unknownStatusCount,
		readErrorCount,
		registryFileCount: registryFiles.length,
	};
}
