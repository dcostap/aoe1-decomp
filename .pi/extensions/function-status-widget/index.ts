import type { ExtensionAPI, ExtensionContext } from "@earendil-works/pi-coding-agent";
import {
	scanFunctionStats,
	type FunctionStats,
} from "./core.ts";
import {
	functionStatusErrorWidgetComponent,
	functionStatusWidgetComponent,
} from "./widget.ts";

export const WIDGET_ID = "aoe1-function-status";
export const DEFAULT_REFRESH_INTERVAL_MS = 10_000;
export const MIN_REFRESH_INTERVAL_MS = 1_000;
export const MAX_REFRESH_INTERVAL_MS = 300_000;

type TimerHandle = ReturnType<typeof setInterval>;

function refreshIntervalMs(): number {
	const configured = Number(process.env.PI_AOE1_FUNCTION_STATUS_INTERVAL_MS);
	if (!Number.isFinite(configured) || configured <= 0) return DEFAULT_REFRESH_INTERVAL_MS;
	return Math.min(MAX_REFRESH_INTERVAL_MS, Math.max(MIN_REFRESH_INTERVAL_MS, Math.round(configured)));
}

function errorMessage(error: unknown): string {
	return error instanceof Error ? error.message : String(error);
}

function isAbortError(error: unknown): boolean {
	return error instanceof Error && error.name === "AbortError";
}

class FunctionStatusWidgetRuntime {
	private enabled = true;
	private disposed = false;
	private timer: TimerHandle | undefined;
	private inFlight: AbortController | undefined;
	private pendingRefresh = false;
	private lastSignature: string | undefined;

	constructor(
		private readonly ctx: ExtensionContext,
		private readonly intervalMs: number,
	) {}

	start(): void {
		this.timer = setInterval(() => this.requestRefresh(), this.intervalMs);
		this.requestRefresh();
	}

	isEnabled(): boolean {
		return this.enabled;
	}

	setEnabled(enabled: boolean): void {
		if (this.disposed || this.enabled === enabled) return;
		this.enabled = enabled;
		if (!enabled) {
			this.pendingRefresh = false;
			this.inFlight?.abort();
			this.clearWidget();
			return;
		}
		this.requestRefresh();
	}

	refreshNow(): boolean {
		if (this.disposed || !this.enabled) return false;
		this.requestRefresh();
		return true;
	}

	dispose(): void {
		if (this.disposed) return;
		this.disposed = true;
		this.enabled = false;
		if (this.timer) clearInterval(this.timer);
		this.timer = undefined;
		this.pendingRefresh = false;
		this.inFlight?.abort();
		this.clearWidget();
	}

	private requestRefresh(): void {
		if (this.disposed || !this.enabled) return;
		if (this.inFlight) {
			this.pendingRefresh = true;
			return;
		}
		void this.refresh();
	}

	private async refresh(): Promise<void> {
		if (this.disposed || !this.enabled || this.inFlight) return;
		const controller = new AbortController();
		this.inFlight = controller;
		try {
			const stats = await scanFunctionStats(this.ctx.cwd, controller.signal);
			if (!this.disposed && this.enabled && !controller.signal.aborted) this.setStatsWidget(stats);
		} catch (error) {
			if (!isAbortError(error) && !this.disposed && this.enabled) this.setErrorWidget(errorMessage(error));
		} finally {
			if (this.inFlight === controller) this.inFlight = undefined;
			if (this.pendingRefresh && !this.disposed && this.enabled) {
				this.pendingRefresh = false;
				this.requestRefresh();
			}
		}
	}

	private setStatsWidget(stats: FunctionStats): void {
		const signature = JSON.stringify(stats);
		if (signature === this.lastSignature) return;
		this.lastSignature = signature;
		try {
			this.ctx.ui.setWidget(
				WIDGET_ID,
				(_tui, theme) => functionStatusWidgetComponent(stats, theme),
				{ placement: "aboveEditor" },
			);
		} catch {
			// The session can switch while a refresh is reading the registry.
		}
	}

	private setErrorWidget(message: string): void {
		const signature = `error:${message}`;
		if (signature === this.lastSignature) return;
		this.lastSignature = signature;
		try {
			this.ctx.ui.setWidget(
				WIDGET_ID,
				(_tui, theme) => functionStatusErrorWidgetComponent(message, theme),
				{ placement: "aboveEditor" },
			);
		} catch {
			// The session can switch while a refresh is reading the registry.
		}
	}

	private clearWidget(): void {
		try {
			this.ctx.ui.setWidget(WIDGET_ID, undefined);
		} catch {
			// The session can switch before its old UI context is disposed.
		}
		this.lastSignature = undefined;
	}
}

export default function functionStatusWidget(pi: ExtensionAPI): void {
	let runtime: FunctionStatusWidgetRuntime | undefined;

	pi.on("session_start", (_event, ctx) => {
		runtime?.dispose();
		runtime = undefined;
		if (!ctx.hasUI || ctx.mode !== "tui") return;
		runtime = new FunctionStatusWidgetRuntime(ctx, refreshIntervalMs());
		runtime.start();
	});

	pi.on("session_shutdown", () => {
		runtime?.dispose();
		runtime = undefined;
	});

	pi.registerCommand("function-status-refresh", {
		description: "Refresh the function status widget now",
		handler: async (_args, ctx) => {
			if (!runtime) {
				if (ctx.hasUI) ctx.ui.notify("Function status widget is unavailable in this mode", "warning");
				return;
			}
			runtime.refreshNow();
			if (ctx.hasUI) ctx.ui.notify("Function status refresh queued", "info");
		},
	});

	pi.registerCommand("function-status-widget", {
		description: "Enable, disable, or toggle the function status widget",
		handler: async (args, ctx) => {
			if (!runtime) {
				if (ctx.hasUI) ctx.ui.notify("Function status widget is unavailable in this mode", "warning");
				return;
			}
			const action = args.trim().toLowerCase();
			if (action && action !== "on" && action !== "off" && action !== "toggle") {
				if (ctx.hasUI) ctx.ui.notify("Usage: /function-status-widget [on|off|toggle]", "warning");
				return;
			}
			const enabled = action === "on" ? true : action === "off" ? false : !runtime.isEnabled();
			runtime.setEnabled(enabled);
			if (ctx.hasUI) ctx.ui.notify(`Function status widget ${enabled ? "enabled" : "disabled"}`, "info");
		},
	});
}
