export const SCRATCH_EVENT_ENTRY = "aoe1-scratch-decrease";
export const ONE_HOUR_MS = 60 * 60 * 1_000;

export type ScratchDecreaseEvent = {
	timestamp: number;
	previousCount: number;
	currentCount: number;
	matches: number;
};

export type ScratchEventSummary = {
	totalEvents: number;
	totalMatches: number;
	lastHourEvents: number;
	lastHourMatches: number;
};

type SessionEntry = {
	type?: unknown;
	customType?: unknown;
	data?: unknown;
};

function isRecord(value: unknown): value is Record<string, unknown> {
	return typeof value === "object" && value !== null;
}

function isScratchDecreaseEvent(value: unknown): value is ScratchDecreaseEvent {
	if (!isRecord(value)) return false;
	return typeof value.timestamp === "number" && Number.isFinite(value.timestamp)
		&& typeof value.previousCount === "number" && Number.isFinite(value.previousCount)
		&& typeof value.currentCount === "number" && Number.isFinite(value.currentCount)
		&& typeof value.matches === "number" && Number.isFinite(value.matches)
		&& value.previousCount > value.currentCount && value.matches > 0;
}

export function restoreScratchEvents(entries: readonly SessionEntry[]): ScratchDecreaseEvent[] {
	return entries
		.filter((entry) => entry.type === "custom" && entry.customType === SCRATCH_EVENT_ENTRY)
		.map((entry) => entry.data)
		.filter(isScratchDecreaseEvent)
		.sort((left, right) => left.timestamp - right.timestamp);
}

export function summarizeScratchEvents(events: readonly ScratchDecreaseEvent[], now = Date.now()): ScratchEventSummary {
	const cutoff = now - ONE_HOUR_MS;
	let totalMatches = 0;
	let lastHourEvents = 0;
	let lastHourMatches = 0;

	for (const event of events) {
		totalMatches += event.matches;
		if (event.timestamp > cutoff && event.timestamp <= now) {
			lastHourEvents += 1;
			lastHourMatches += event.matches;
		}
	}

	return {
		totalEvents: events.length,
		totalMatches,
		lastHourEvents,
		lastHourMatches,
	};
}
