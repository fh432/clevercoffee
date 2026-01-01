# CleverCoffee
(formerly Rancilio PID)

<div align="center">
<img src="https://img.shields.io/github/actions/workflow/status/rancilio-pid/clevercoffee/main.yml?branch=master">
<img src="https://img.shields.io/github/last-commit/rancilio-pid/clevercoffee/master"><br>
<a href="https://ko-fi.com/clevercoffee" target="_blank" style="color: black; text-decoration: none;">Buy Me a Coffee at ko-fi.com</a>
</div>

# About

This project implements a PID controller for stable and accurate temperature control, originally for Rancilio Silvia espresso machines but also includes support for Gaggia and Quickmill machines. Others can easily be added or are already compatible.

Additional features include:

* shot timer
* pre-infusion (wip: reduced initial pressure using a dimmer for the pump)
* brew by weight (using weight cells, no support for external scales yet)
* brew by time
* pressure monitoring

The hardware has a small footprint and can easily fit into most smaller espresso machines. The original wiring of the machine (mostly) remains and is only extended. The machine can be easily reversed to the original state after the conversion.

The project has been in active development and supported for 4 years with continuous improvements. Hundreds of machines have been converted to PID control already.

You can find our project website here: [Clever Coffee Website](https://clevercoffee.de).

This software is Open Source: free of charge for you and customizable to your personal needs.

We recommend you have a look at the manual before starting a build, you can find the german one [here](https://rancilio-pid.github.io/ranciliopid-handbook/). It is currently being reworked to include all the latest features. The english one is sadly still very outdated but will also be updated soon.

## Chat and Support
You will find more information, discussions, and support on our [Discord](https://discord.gg/Kq5RFznuU4) server.
If you want to be part of the project and help with development of hardware, software and documentation you will also find the right channels there.
**Please keep in mind that we primarily give support for our own pcbs. We may not be able to help with any hardware solutions that are not based on our own pcbs.**
**Please do not offer any kind of pcb derivatives of our design or own developments without contacting us before.**

Video tutorial on how to flash the firmware (a little outdated but mostly still valid):<br>
https://youtu.be/KZPjisOEcQ4

## Version
With Version 3.3.0 we bring the last major release with support for ESP8266 and ESP32.
There will only be bug fix releases for ESP8266 from there on. 
Further development, with new features, will only be done for ESP32.
"master" branch contains the current development only for esp32.
"master-esp8266" branch contains last version for ESP8266 and ESP32.

## What is possible after installation into your espresso machine?
 * Control of the brew temperature with an accuracy of up to +/- 0,1°.
 * Reaches the target temperature within 5 to 10 minutes after switching on (you should, however, wait a bit longer, e.g. 20 min depending on the machine to heat up the group head etc.)
 * Set PID parameters and monitor current temperature and heater output on a web page hosted on the ESP controller
 * Separate PID for steam mode with own parameters and target temperature (can be enabled in the web interface/MQTT or using the steam switch)
 * Automatically brew by set time including pre-infusion timing.
 * Automatically brew by weight when scale components are built in.
 * Possible to change brew and steam switches to push buttons. Brew push button then has two actions: short press for brew, long press to flush.
 * Allows brew switch detection (e.g. for the shot timer) by using an optocoupler module when deciding not to control the pump from the ESP ([details](https://rancilio-pid.github.io/ranciliopid-handbook/de/customization/brueherkennung.html#konfiguration-der-erkennung)).
* MQTT (IoT) support to monitor and manipulate all important parameters.
 * Choose from multiple designs for the display (including vertical), possibility to integrate custom designs
 * Over-The-Air updates of the firmware (WiFi)

User feedback and suggestions for further development of the software are most welcome.
You are welcome to help us in our mission to make better espresso. :)

Thanks to every single supporter!

Ausgabe Debug level nach Vollausbau:
===================================
...
[00:43:35]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:43:35]   DEBUG HW Brew detected
[00:43:35]    INFO Resetting standby timer to 30 minutes
[00:43:35]   DEBUG new machineState: PID Normal -> Brew
[00:43:35]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:43:35]    INFO Preinfusion
[00:43:35]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:43:37]    INFO Preinfusion pause
[00:43:42]    INFO Brew started
[00:43:45]   DEBUG Enabled PID again after delay
[00:43:52]   DEBUG Reconnected, last message ID was: 1537899
[00:43:56]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:43:56]    INFO Brew stopped manually
[00:43:56]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:43:56]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:43:58]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:43:59]    INFO Shot time: 21.1 s
[00:43:59]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:43:59]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:00]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:44:00]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:00]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:44:07]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:44:07]   DEBUG HW Brew detected
[00:44:07]    INFO Resetting standby timer to 30 minutes
[00:44:07]   DEBUG new machineState: PID Normal -> Brew
[00:44:07]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:07]    INFO Preinfusion
[00:44:07]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:44:09]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:44:09]    INFO Brew stopped manually
[00:44:09]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:44:09]   DEBUG Enabled PID again after delay
[00:44:09]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:12]    INFO Shot time:  2.0 s
[00:44:12]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:44:12]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:12]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:44:12]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:44:17]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:44:17]   DEBUG HW Brew detected
[00:44:17]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:44:17]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:17]    INFO Preinfusion
[00:44:17]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:44:19]    INFO Preinfusion pause
[00:44:24]    INFO Brew started
[00:44:26]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:44:26]    INFO Brew stopped manually
[00:44:26]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:44:26]   DEBUG Enabled PID again after delay
[00:44:26]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:28]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:44:29]    INFO Shot time:  9.1 s
[00:44:29]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:44:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:31]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:44:36]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:44:36]   DEBUG HW Brew detected
[00:44:36]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:44:36]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:36]    INFO Preinfusion
[00:44:36]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:44:38]    INFO Preinfusion pause
[00:44:43]    INFO Brew started
[00:44:46]   DEBUG Enabled PID again after delay
[00:44:54]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:44:54]    INFO Brew stopped manually
[00:44:54]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:44:54]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:57]    INFO Shot time: 18.2 s
[00:44:57]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:44:57]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:44:57]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:44:57]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:45:01]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:45:01]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:02]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:45:02]   DEBUG HW Brew detected
[00:45:02]    INFO Resetting standby timer to 30 minutes
[00:45:02]   DEBUG new machineState: PID Normal -> Brew
[00:45:02]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:02]    INFO Preinfusion
[00:45:02]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:45:04]    INFO Preinfusion pause
[00:45:09]    INFO Brew started
[00:45:12]   DEBUG Enabled PID again after delay
[00:45:24]    INFO Standby time remaining: 29 minutes
[00:45:29]    INFO Brew stopped
[00:45:29]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:45:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:29]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:45:29]    INFO Brew stopped manually
[00:45:29]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:45:32]    INFO Shot time: 27.0 s
[00:45:32]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:45:32]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:32]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:45:32]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:45:32]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:32]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:45:32]   DEBUG HW Brew detected
[00:45:32]    INFO Resetting standby timer to 30 minutes
[00:45:32]   DEBUG new machineState: PID Normal -> Brew
[00:45:32]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:32]    INFO Preinfusion
[00:45:32]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:45:34]    INFO Preinfusion pause
[00:45:38]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:45:38]    INFO Brew stopped manually
[00:45:38]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:45:38]   DEBUG Enabled PID again after delay
[00:45:38]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:41]    INFO Shot time:  6.3 s
[00:45:41]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:45:41]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:41]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:45:45]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:45:53]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:45:54]   DEBUG HW Brew detected
[00:45:54]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:45:54]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:54]    INFO Preinfusion
[00:45:54]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:45:56]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:45:56]    INFO Brew stopped manually
[00:45:56]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:45:56]   DEBUG Enabled PID again after delay
[00:45:56]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:59]    INFO Shot time:  2.0 s
[00:45:59]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:45:59]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:45:59]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:45:59]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:46:04]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:46:04]   DEBUG HW Brew detected
[00:46:04]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:46:04]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:46:04]    INFO Preinfusion
[00:46:04]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:46:06]    INFO Preinfusion pause
[00:46:11]    INFO Brew started
[00:46:13]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:46:13]    INFO Brew stopped manually
[00:46:13]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:46:13]   DEBUG Enabled PID again after delay
[00:46:13]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:46:16]    INFO Shot time:  9.2 s
[00:46:16]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:46:16]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:46:24]    INFO Standby time remaining: 29 minutes
[00:46:29]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:46:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:46:32]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:46:48]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:46:56]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:46:56]   DEBUG HW Brew detected
[00:46:56]    INFO Resetting standby timer to 30 minutes
[00:46:56]   DEBUG new machineState: PID Normal -> Brew
[00:46:56]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:46:56]    INFO Preinfusion
[00:46:56]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:46:58]    INFO Preinfusion pause
[00:47:03]    INFO Brew started
[00:47:06]   DEBUG Enabled PID again after delay
[00:47:12]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:47:12]    INFO Brew stopped manually
[00:47:12]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:47:12]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:14]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:47:15]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:47:15]    INFO Shot time: 16.2 s
[00:47:15]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:47:15]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:21]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:47:21]   DEBUG HW Brew detected
[00:47:21]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:47:21]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:21]    INFO Preinfusion
[00:47:21]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:47:23]    INFO Preinfusion pause
[00:47:28]    INFO Brew started
[00:47:30]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:47:30]    INFO Brew stopped manually
[00:47:30]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:47:30]   DEBUG Enabled PID again after delay
[00:47:30]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:33]    INFO Shot time:  9.1 s
[00:47:33]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:47:33]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:33]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:47:33]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:47:46]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:47:46]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:46]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:47:46]   DEBUG HW Brew detected
[00:47:46]    INFO Resetting standby timer to 30 minutes
[00:47:46]   DEBUG new machineState: PID Normal -> Brew
[00:47:46]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:46]    INFO Preinfusion
[00:47:46]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:47:47]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:47:47]    INFO Brew stopped manually
[00:47:47]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:47:47]   DEBUG Enabled PID again after delay
[00:47:47]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:50]    INFO Shot time:  1.0 s
[00:47:50]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:47:50]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:50]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:47:50]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:47:54]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:47:54]   DEBUG HW Brew detected
[00:47:54]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:47:54]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:47:54]    INFO Preinfusion
[00:47:54]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:47:56]    INFO Preinfusion pause
[00:48:01]    INFO Brew started
[00:48:04]   DEBUG Enabled PID again after delay
[00:48:04]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:48:04]    INFO Brew stopped manually
[00:48:04]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:48:04]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:07]    INFO Shot time: 10.1 s
[00:48:07]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:48:07]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:07]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:48:07]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:48:12]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:48:12]   DEBUG HW Brew detected
[00:48:12]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:48:12]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:12]    INFO Preinfusion
[00:48:12]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:48:14]    INFO Preinfusion pause
[00:48:19]    INFO Brew started
[00:48:22]   DEBUG Enabled PID again after delay
[00:48:24]    INFO Standby time remaining: 29 minutes
[00:48:27]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:48:27]    INFO Brew stopped manually
[00:48:27]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:48:27]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:28]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:48:30]    INFO Shot time: 15.8 s
[00:48:30]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:48:30]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:37]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:48:37]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:53]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:48:54]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:48:54]   DEBUG HW Brew detected
[00:48:54]    INFO Resetting standby timer to 30 minutes
[00:48:54]   DEBUG new machineState: PID Normal -> Brew
[00:48:54]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:48:54]    INFO Preinfusion
[00:48:54]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:48:56]    INFO Preinfusion pause
[00:49:01]    INFO Brew started
[00:49:04]   DEBUG Enabled PID again after delay
[00:49:10]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:49:10]    INFO Brew stopped manually
[00:49:10]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:49:10]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:13]    INFO Shot time: 16.2 s
[00:49:13]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:49:13]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:13]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:49:13]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:49:19]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:49:19]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:24]    INFO Standby time remaining: 29 minutes
[00:49:25]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:49:25]   DEBUG HW Brew detected
[00:49:25]    INFO Resetting standby timer to 30 minutes
[00:49:25]   DEBUG new machineState: PID Normal -> Brew
[00:49:25]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:25]    INFO Preinfusion
[00:49:25]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:49:27]    INFO Preinfusion pause
[00:49:32]    INFO Brew started
[00:49:34]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:49:34]    INFO Brew stopped manually
[00:49:34]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:49:34]   DEBUG Enabled PID again after delay
[00:49:34]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:37]    INFO Shot time:  9.1 s
[00:49:37]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:49:37]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:37]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:49:37]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:49:41]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:49:41]   DEBUG HW Brew detected
[00:49:41]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:49:41]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:41]    INFO Preinfusion
[00:49:41]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:49:43]    INFO Preinfusion pause
[00:49:48]    INFO Brew started
[00:49:50]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:49:50]    INFO Brew stopped manually
[00:49:50]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:49:50]   DEBUG Enabled PID again after delay
[00:49:50]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:53]    INFO Shot time:  9.1 s
[00:49:53]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:49:53]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:49:53]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:49:54]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:50:06]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:50:06]   DEBUG HW Brew detected
[00:50:06]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:50:06]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:06]    INFO Preinfusion
[00:50:06]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:50:08]    INFO Preinfusion pause
[00:50:13]    INFO Brew started
[00:50:16]   DEBUG Enabled PID again after delay
[00:50:26]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:50:26]    INFO Brew stopped manually
[00:50:26]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:50:26]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:29]    INFO Shot time: 20.7 s
[00:50:29]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:50:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:29]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:50:30]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:50:31]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:50:31]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:38]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:50:38]   DEBUG HW Brew detected
[00:50:38]    INFO Resetting standby timer to 30 minutes
[00:50:38]   DEBUG new machineState: PID Normal -> Brew
[00:50:38]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:38]    INFO Preinfusion
[00:50:38]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:50:39]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:50:39]    INFO Brew stopped manually
[00:50:39]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:50:39]   DEBUG Enabled PID again after delay
[00:50:39]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:40]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:50:42]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:50:42]    INFO Shot time:  1.0 s
[00:50:42]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:50:42]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:43]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:50:43]   DEBUG HW Brew detected
[00:50:43]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:50:43]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:43]    INFO Preinfusion
[00:50:43]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:50:45]    INFO Preinfusion pause
[00:50:50]    INFO Brew started
[00:50:52]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:50:52]    INFO Brew stopped manually
[00:50:52]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:50:52]   DEBUG Enabled PID again after delay
[00:50:52]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:55]    INFO Shot time:  9.1 s
[00:50:55]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:50:55]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:50:59]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:51:08]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:51:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:51:16]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:51:24]    INFO Standby time remaining: 29 minutes
[00:51:33]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:51:33]   DEBUG HW Brew detected
[00:51:33]    INFO Resetting standby timer to 30 minutes
[00:51:33]   DEBUG new machineState: PID Normal -> Brew
[00:51:33]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:51:33]    INFO Preinfusion
[00:51:33]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:51:35]    INFO Preinfusion pause
[00:51:40]    INFO Brew started
[00:51:41]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:51:41]    INFO Brew stopped manually
[00:51:41]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:51:41]   DEBUG Enabled PID again after delay
[00:51:41]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:51:41]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:51:44]    INFO Shot time:  7.8 s
[00:51:44]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:51:44]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:51:58]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:51:58]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:52:33]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:52:35]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:52:35]   DEBUG HW Brew detected
[00:52:35]    INFO Resetting standby timer to 30 minutes
[00:52:35]   DEBUG new machineState: PID Normal -> Brew
[00:52:35]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:52:35]    INFO Preinfusion
[00:52:35]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:52:37]    INFO Preinfusion pause
[00:52:42]    INFO Brew started
[00:52:45]   DEBUG Enabled PID again after delay
[00:53:02]    INFO Brew stopped
[00:53:02]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:53:02]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:02]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:53:02]    INFO Brew stopped manually
[00:53:02]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:53:05]    INFO Shot time: 27.0 s
[00:53:05]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:53:05]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:05]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:53:05]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:17]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:53:22]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:53:22]   DEBUG HW Brew detected
[00:53:22]    INFO Resetting standby timer to 30 minutes
[00:53:22]   DEBUG new machineState: PID Normal -> Brew
[00:53:22]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:22]    INFO Preinfusion
[00:53:22]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:53:24]    INFO Preinfusion pause
[00:53:29]    INFO Brew started
[00:53:31]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:53:31]    INFO Brew stopped manually
[00:53:31]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:53:31]   DEBUG Enabled PID again after delay
[00:53:31]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:34]    INFO Shot time:  9.1 s
[00:53:34]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:53:34]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:53:34]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:53:34]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:53:47]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:53:47]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:04]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:54:04]   DEBUG HW Brew detected
[00:54:04]    INFO Resetting standby timer to 30 minutes
[00:54:04]   DEBUG new machineState: PID Normal -> Brew
[00:54:04]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:04]    INFO Preinfusion
[00:54:04]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:54:06]    INFO Preinfusion pause
[00:54:11]    INFO Brew started
[00:54:14]   DEBUG Enabled PID again after delay
[00:54:14]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:54:14]    INFO Brew stopped manually
[00:54:14]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:54:14]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:17]    INFO Shot time: 10.1 s
[00:54:17]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:54:17]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:17]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:54:17]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:54:24]    INFO Standby time remaining: 29 minutes
[00:54:29]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:54:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:38]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:54:38]   DEBUG HW Brew detected
[00:54:38]    INFO Resetting standby timer to 30 minutes
[00:54:38]   DEBUG new machineState: PID Normal -> Brew
[00:54:38]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:54:38]    INFO Preinfusion
[00:54:38]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:54:40]    INFO Preinfusion pause
[00:54:45]    INFO Brew started
[00:54:48]   DEBUG Enabled PID again after delay
[00:55:05]    INFO Brew stopped
[00:55:05]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:55:05]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:05]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:55:05]    INFO Brew stopped manually
[00:55:05]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:55:08]    INFO Shot time: 27.0 s
[00:55:08]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:55:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:08]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:55:08]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:55:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:08]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:55:08]   DEBUG HW Brew detected
[00:55:08]    INFO Resetting standby timer to 30 minutes
[00:55:08]   DEBUG new machineState: PID Normal -> Brew
[00:55:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:08]    INFO Preinfusion
[00:55:08]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:55:10]    INFO Preinfusion pause
[00:55:15]    INFO Brew started
[00:55:18]   DEBUG Enabled PID again after delay
[00:55:24]    INFO Standby time remaining: 29 minutes
[00:55:35]    INFO Brew stopped
[00:55:35]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:55:35]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:35]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:55:35]    INFO Brew stopped manually
[00:55:35]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:55:38]    INFO Shot time: 27.0 s
[00:55:38]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:55:38]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:38]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:55:38]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:55:45]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:56:02]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:56:02]   DEBUG HW Brew detected
[00:56:02]    INFO Resetting standby timer to 30 minutes
[00:56:02]   DEBUG new machineState: PID Normal -> Brew
[00:56:02]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:02]    INFO Preinfusion
[00:56:02]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:56:04]    INFO Preinfusion pause
[00:56:07]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:56:07]    INFO Brew stopped manually
[00:56:07]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:56:07]   DEBUG Enabled PID again after delay
[00:56:07]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:10]    INFO Shot time:  4.7 s
[00:56:10]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:56:10]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:10]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:56:10]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:56:11]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:56:11]   DEBUG HW Brew detected
[00:56:11]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:56:11]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:11]    INFO Preinfusion
[00:56:11]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:56:13]    INFO Preinfusion pause
[00:56:18]    INFO Brew started
[00:56:21]   DEBUG Enabled PID again after delay
[00:56:26]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:56:26]    INFO Brew stopped manually
[00:56:26]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:56:26]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:28]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:56:29]    INFO Shot time: 14.5 s
[00:56:29]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:56:29]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:36]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:56:36]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:56:54]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:57:10]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:57:10]   DEBUG HW Brew detected
[00:57:10]    INFO Resetting standby timer to 30 minutes
[00:57:10]   DEBUG new machineState: PID Normal -> Brew
[00:57:10]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:10]    INFO Preinfusion
[00:57:10]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:57:11]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:57:11]    INFO Brew stopped manually
[00:57:11]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:57:11]   DEBUG Enabled PID again after delay
[00:57:11]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:14]    INFO Shot time:  0.6 s
[00:57:14]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:57:14]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:14]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:57:14]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:57:24]    INFO Standby time remaining: 29 minutes
[00:57:26]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:57:26]   DEBUG HW Brew detected
[00:57:26]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:57:26]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:26]    INFO Preinfusion
[00:57:26]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:57:27]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:57:27]    INFO Brew stopped manually
[00:57:27]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:57:27]   DEBUG Enabled PID again after delay
[00:57:27]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:30]    INFO Shot time:  1.0 s
[00:57:30]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:57:30]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:30]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:57:30]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:57:47]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:57:47]   DEBUG HW Brew detected
[00:57:47]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:57:47]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:57:47]    INFO Preinfusion
[00:57:47]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:57:49]    INFO Preinfusion pause
[00:57:54]    INFO Brew started
[00:57:57]   DEBUG Enabled PID again after delay
[00:58:00]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:58:00]    INFO Brew stopped manually
[00:58:00]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:58:00]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:02]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:58:03]    INFO Shot time: 13.0 s
[00:58:03]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:58:03]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:12]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:58:12]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:19]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:58:24]    INFO Standby time remaining: 28 minutes
[00:58:27]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:58:27]   DEBUG HW Brew detected
[00:58:27]    INFO Resetting standby timer to 30 minutes
[00:58:27]   DEBUG new machineState: PID Normal -> Brew
[00:58:27]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:27]    INFO Preinfusion
[00:58:27]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:58:28]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:58:28]    INFO Brew stopped manually
[00:58:28]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:58:28]   DEBUG Enabled PID again after delay
[00:58:28]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:31]    INFO Shot time:  1.0 s
[00:58:31]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:58:31]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:31]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:58:35]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:58:52]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:58:52]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:59]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:58:59]   DEBUG HW Brew detected
[00:58:59]    INFO Resetting standby timer to 30 minutes
[00:58:59]   DEBUG new machineState: PID Normal -> Brew
[00:58:59]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:58:59]    INFO Preinfusion
[00:58:59]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:59:01]    INFO Preinfusion pause
[00:59:06]    INFO Brew started
[00:59:08]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:59:08]    INFO Brew stopped manually
[00:59:08]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:59:08]   DEBUG Enabled PID again after delay
[00:59:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:11]    INFO Shot time:  9.1 s
[00:59:11]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:59:11]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:11]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[00:59:13]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:59:24]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[00:59:24]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:32]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:59:32]   DEBUG HW Brew detected
[00:59:32]    INFO Resetting standby timer to 30 minutes
[00:59:32]   DEBUG new machineState: PID Normal -> Brew
[00:59:32]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:32]    INFO Preinfusion
[00:59:32]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:59:34]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:59:34]    INFO Brew stopped manually
[00:59:34]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:59:34]   DEBUG Enabled PID again after delay
[00:59:34]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:35]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:59:36]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[00:59:37]    INFO Shot time:  1.9 s
[00:59:37]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:59:37]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:53]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[00:59:53]   DEBUG HW Brew detected
[00:59:53]   DEBUG new machineState: Brew Detection Trailing -> Brew
[00:59:53]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:53]    INFO Preinfusion
[00:59:53]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[00:59:54]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[00:59:54]    INFO Brew stopped manually
[00:59:54]   DEBUG new machineState: Brew -> Shot Timer After Brew
[00:59:54]   DEBUG Enabled PID again after delay
[00:59:54]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:57]    INFO Shot time:  1.0 s
[00:59:57]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[00:59:57]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[00:59:57]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[00:59:59]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:00:16]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:00:16]   DEBUG HW Brew detected
[01:00:16]   DEBUG new machineState: Brew Detection Trailing -> Brew
[01:00:16]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:00:16]    INFO Preinfusion
[01:00:16]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:00:18]    INFO Preinfusion pause
[01:00:23]    INFO Brew started
[01:00:24]    INFO Standby time remaining: 29 minutes
[01:00:26]   DEBUG Enabled PID again after delay
[01:00:33]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:00:33]    INFO Brew stopped manually
[01:00:33]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:00:33]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:00:34]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[01:00:36]    INFO Shot time: 17.2 s
[01:00:36]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:00:36]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:00:41]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[01:00:41]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:00:43]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:00:51]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:00:51]   DEBUG HW Brew detected
[01:00:51]    INFO Resetting standby timer to 30 minutes
[01:00:51]   DEBUG new machineState: PID Normal -> Brew
[01:00:51]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:00:51]    INFO Preinfusion
[01:00:51]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:00:53]    INFO Preinfusion pause
[01:00:58]    INFO Brew started
[01:01:01]   DEBUG Enabled PID again after delay
[01:01:08]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:01:08]    INFO Brew stopped manually
[01:01:08]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:01:08]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:11]    INFO Shot time: 17.2 s
[01:01:11]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:01:11]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:11]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[01:01:11]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:01:16]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[01:01:16]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:16]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:01:16]   DEBUG HW Brew detected
[01:01:16]    INFO Resetting standby timer to 30 minutes
[01:01:16]   DEBUG new machineState: PID Normal -> Brew
[01:01:16]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:16]    INFO Preinfusion
[01:01:16]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:01:18]    INFO Preinfusion pause
[01:01:23]    INFO Brew started
[01:01:24]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:01:24]    INFO Brew stopped manually
[01:01:24]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:01:24]   DEBUG Enabled PID again after delay
[01:01:24]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:27]    INFO Shot time:  8.1 s
[01:01:27]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:01:27]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:27]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[01:01:27]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:01:40]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:01:40]   DEBUG HW Brew detected
[01:01:40]   DEBUG new machineState: Brew Detection Trailing -> Brew
[01:01:40]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:01:40]    INFO Preinfusion
[01:01:40]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:01:42]    INFO Preinfusion pause
[01:01:47]    INFO Brew started
[01:01:50]   DEBUG Enabled PID again after delay
[01:01:57]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:01:57]    INFO Brew stopped manually
[01:01:57]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:01:57]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:00]    INFO Shot time: 17.9 s
[01:02:00]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:02:00]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:05]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[01:02:05]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:05]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[01:02:15]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:02:23]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:02:23]   DEBUG HW Brew detected
[01:02:23]    INFO Resetting standby timer to 30 minutes
[01:02:23]   DEBUG new machineState: PID Normal -> Brew
[01:02:23]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:23]    INFO Preinfusion
[01:02:23]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:02:24]    INFO Standby time remaining: 29 minutes
[01:02:25]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:02:25]    INFO Brew stopped manually
[01:02:25]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:02:25]   DEBUG Enabled PID again after delay
[01:02:25]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:28]    INFO Shot time:  2.0 s
[01:02:28]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:02:28]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:28]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle
[01:02:28]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:02:33]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:02:33]   DEBUG HW Brew detected
[01:02:33]   DEBUG new machineState: Brew Detection Trailing -> Brew
[01:02:33]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:33]    INFO Preinfusion
[01:02:33]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:02:35]    INFO Preinfusion pause
[01:02:40]    INFO Brew started
[01:02:43]   DEBUG Enabled PID again after delay
[01:02:49]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:02:49]    INFO Brew stopped manually
[01:02:49]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:02:49]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:52]    INFO Shot time: 15.9 s
[01:02:52]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:02:52]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:02:56]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[01:02:58]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[01:02:58]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:03:07]   DEBUG brewSwitchState = kBrewSwitchIdle; waiting for brew switch input
[01:03:20]   DEBUG brewSwitchState = kBrewSwitchBrew; brew switch short pressed - start Brew
[01:03:20]   DEBUG HW Brew detected
[01:03:20]    INFO Resetting standby timer to 30 minutes
[01:03:20]   DEBUG new machineState: PID Normal -> Brew
[01:03:20]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:03:20]    INFO Preinfusion
[01:03:20]   DEBUG disabled PID, waiting for 0 seconds before enabling PID again
[01:03:22]   DEBUG brewSwitchState = kBrewSwitchBrewAbort: brew switch short pressed - stop brew
[01:03:22]    INFO Brew stopped manually
[01:03:22]   DEBUG new machineState: Brew -> Shot Timer After Brew
[01:03:22]   DEBUG Enabled PID again after delay
[01:03:22]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:03:22]   DEBUG brewSwitchState = kBrewSwitchReset: brew switch released - go to kBrewSwitchIdle 
[01:03:24]    INFO Standby time remaining: 29 minutes
[01:03:25]    INFO Shot time:  1.9 s
[01:03:25]   DEBUG new machineState: Shot Timer After Brew -> Brew Detection Trailing
[01:03:25]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:03:45]   DEBUG new machineState: Brew Detection Trailing -> PID Normal
[01:03:45]   DEBUG new PID-Values: P=135.0  I=1.1  D=72.9
[01:05:24]    INFO Standby time remaining: 27 minutes
[01:07:24]    INFO Standby time remaining: 25 minutes
[01:08:24]    INFO Standby time remaining: 24 minutes
[01:09:24]    INFO Standby time remaining: 23 minutes
[01:10:24]    INFO Standby time remaining: 22 minutes
[01:12:24]    INFO Standby time remaining: 20 minutes
