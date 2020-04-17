# Arduino
Arduino-based experiments and MIDI controllers. 

These sketches are designed to be used with Arduino sensors connected to an Arduino Uno. Connect the Arduino to a PC via USB. 
Hairless MIDI serial and LoopBe need to be installed on the PC. Hairless MIDI deals with the serial data. LoopBe allows this data to be routed as a MIDI instrument into software. You'll need to include some libraries too - check the top of the code.

[Hairless MIDI Serial to MIDI Bridge] (http://projectgus.github.io/hairless-midiserial/)

[LoopBe1 - Virtual MIDI driver](http://nerds.de/en/loopbe1.html)

## Videos

Some videos of these in action here:<br>
https://www.youtube.com/watch?v=Sysc4m5WBRs&list=PLK97vHtT6kElv3KbduHqCx-dmEcHraSOI

## Files
### potentiometer_x4_to_MIDI
Arduino sketch that reads analog values from 4 potentiometers and converts these values to serial MIDI data. 

### accelerometer_to_MIDI
Arduino sketch that reads values from an MMA7361 accelerometer  and converts these values to serial MIDI data.

## Related

### Arduino_Ultrasonic_MIDI_Native 
Repository here : https://github.com/psiconlab/Arduino_Ultrasonic_MIDI_Native

### Arduino_Ultrasonic_MIDI
Repository here : https://github.com/psiconlab/Arduino_Ultrasonic_MIDI

## Links
[More info on sending serial MIDI data](http://little-scale.blogspot.co.uk/2011/08/simple-examples-of-sending-midi-data.html)
