# 00461910 TMusic_System constructor

The original source is `music.cpp`, lines 52 through 59.

The constructor initializes the music state. It copies an optional path. It then opens the device.

A source-order probe found the required store order. It stores the sound driver, instance, and window in that order. An explicit path branch and one common `open_device` call gave the prior exact result.
