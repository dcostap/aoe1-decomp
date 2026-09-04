# Function status widget

This project-local Pi extension shows function recovery counts above the prompt.

The widget refreshes every 10 seconds. Set
`PI_AOE1_FUNCTION_STATUS_INTERVAL_MS` to change the interval. Values use
milliseconds. The extension clamps the value to 1,000 to 300,000 milliseconds.

Commands:

- `/function-status-refresh` refreshes the counts now.
- `/function-status-widget on|off|toggle` controls the widget.
- `/scratch_notifications on|off|toggle|status|test` controls or tests the scratch taunt.

The line names the five normal statuses. Wide terminals also show the five
excluded corpus categories. Narrow terminals show the normal statuses first.
Regions are not counted as functions.

When scratch notifications are enabled, a decrease in the scratch count plays
`taunt-20.mp3`. The file is taunt 20, "I just got some... satisfaction!", from
the [Age of Empires Series Wiki Taunt page](https://ageofempires.fandom.com/wiki/Taunt).
The notification includes the local time in `HH:MM` format.

Each decrease is stored in the current Pi session with its timestamp, old
count, new count, and number of matched functions. The notification also shows
the number of matched functions per hour during the last 60 minutes.
