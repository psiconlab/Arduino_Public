# Arduino
Arduino-based experiments and MIDI controllers. 

These sketches are designed to be used with Arduino sensors connected to an Arduino Uno. Connect the Arduino to a PC via USB.

Hairless MIDI serial and LoopBe need to be installed on the PC. 

Hairless MIDI deals with the serial data. LoopBe allows this data to be fed to music software.

[Hairless MIDI Serial to MIDI Bridge] (http://projectgus.github.io/hairless-midiserial/)

[LoopBe1 - Virtual MIDI driver](http://nerds.de/en/loopbe1.html)

## Files
### pot_midi_x4
Arduino sketch that reads analog values from 4 potentiometers and converts these values to serial MIDI data. 
