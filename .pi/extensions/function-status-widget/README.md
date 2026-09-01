# Function status widget

This project-local Pi extension shows function recovery counts above the prompt.

The widget refreshes every 10 seconds. Set
`PI_AOE1_FUNCTION_STATUS_INTERVAL_MS` to change the interval. Values use
milliseconds. The extension clamps the value to 1,000 to 300,000 milliseconds.

Commands:

- `/function-status-refresh` refreshes the counts now.
- `/function-status-widget on|off|toggle` controls the widget.

The line names the five normal statuses. Wide terminals also show the five
excluded corpus categories. Narrow terminals show the normal statuses first.
Regions are not counted as functions.
