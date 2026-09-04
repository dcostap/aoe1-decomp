# Function status widget

This project-local Pi extension shows function recovery counts above the prompt.

The widget refreshes every 10 seconds. Set
`PI_AOE1_FUNCTION_STATUS_INTERVAL_MS` to change the interval. Values use
milliseconds. The extension clamps the value to 1,000 to 300,000 milliseconds.

Commands:

- `/function-status-refresh` refreshes the counts now.
- `/function-status-widget on|off|toggle` controls the widget.
- `/scratch_notifications on|off|toggle|status|test` controls or tests the scratch sound.

The line names the five normal statuses. Wide terminals also show the five
excluded corpus categories. Narrow terminals show the normal statuses first.
Regions are not counted as functions.

When width permits, the same line ends with the total number of scratch exits
and the number during the last hour. These counters are always active. The
sound setting does not control them.

When the scratch sound is enabled, a decrease in the scratch count plays
`taunt-20.mp3`. The file is taunt 20, "I just got some... satisfaction!", from
the [Age of Empires Series Wiki Taunt page](https://ageofempires.fandom.com/wiki/Taunt).

Each decrease is stored in the current Pi session with its timestamp, old
count, new count, and number of scratch exits.
