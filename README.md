# simpled
Smart Multifunctional LED-Matrix



## Commands:

#### The commands are constructed on an easy concept:

#### Every command consists at least one parameter, the parameters are seperated by a seperator character ( "/" ). 

#### The first parameter is the cmdType, it tells what the command is roughly about, the additional parameters contain specific preferences or specification of the command, as shown in the subitems of the following list:

- a: Editing, deleting, adding apps, getting info about apps
  - a: Add new app with appID n and given parameters
  - d: Delete app at place n
  - g: Get the cmd that contains all information about the app at place n
  - p: Get all the cmds of all the saved apps
  - s: Set app at place n to given parameters
  - w: swap the two apps at place n and place o
- n: Next app (Same functionality as the button on top of sipLED)
- p: Previous app
- b: Brightness   set to given byte (0-255)
- t: Time
  - s: Set system-time to given parameters
  - p: Print system-time