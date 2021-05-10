# Single Button Keyboard
The goal for this is to make clicking and dragging easier for those that might have trouble doing that on a standard mouse. Press the button once and the mouse will press, press again and it will lift.

# Components
* Cherry MX (of your color choice), both PCB and panel mount work
* Keycap of your choice
* Arduino Pro Micro
* 3D printed enclosure (see stls directory)
* 22 AWG solid wire
* Micro USB cable
* 4 x #4-40 flat head screws, .25" long
* Piece of felt (optional)

# Needed Tools
* 3D printer (or access to one)
* Soldering iron
* Wire strippers
* Screw driver

# Theory of Operation
The keyboard uses an active low switch (an internal pullup resistor with the switch tied to ground) to trigger a change in state if enough time has passed since the last state toggle. When in a pressed state, the mouse button is held down, while in the unpressed state it is released. Debouncing is done through a simple delay calculation that can be tweaked if bouncing is detected.

# Assembly
* Press the switch into the square socket in the enclosure from the outside.
* Solder wires to one of the GND pins on the Pro Micro and another to the A3 pin. I recommend a few inches of wire, which can be trimmed after the Pro Micro is in place.
* Insert the micro USB end of the Pro Micro in the hole of the enclosure and snap the other end in place. Make sure to route the wires out through the gap in the socket for the Pro Micro.
* Solder the ends of the wire to the two terminals on the switch. It doesn't matter which one you connect each wire to, just make sure you don't connect them both to the same one.

# Programming
This project requires some way to flash the code to the Pro Micro. The easiest toolchain involves downloading the Arduino IDE and selecting the Leonardo board. You'll also need to select the port your Pro Micro is connected to, but there should only be one or two options. Resources for flashing the code are readily available on both Google and YouTube.
