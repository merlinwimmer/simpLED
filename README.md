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

## Extending Apps

The content displayed on simpLED is generated by Apps. An App is a class, the simpLED-Firmware has an Array with instances of those App-Classes. Every App is derived from the base class "App", this class gives every App class a name attribute and predefines all the import functions (see below) in case a derived App class does not have one of this functions but it is called.

#### Every App needs to have the following functions:

- void refresh()
  - draws something on the simpLED-Matrix, gets called in every iteration of the main loop.
- String get()
  - returns the attributes of the apps important for a new initialization (so not other variables that are only needed for the operation of the app, like iterators) in the format of a cmd (but only the parameters, no a/a)
- void set(String parameters[])
  - Sets the classes attributes to the parameters, a standart order of parameters must be defined

Apart from that, every derived App class needs to have a Constructor and can have any other attributes or functions that it needs to operate.

[UML-Diagram of OOP](https://drive.google.com/file/d/12Vmn2gUaWqmgGh9unAtZD7WNStvrPoy0/view?usp=sharing)