# PushDaBox
This is a simple puzzle game I made with SDL. You have to Push a box to a goal location but enemies might be getting in your way. You can click on them to make them go away but they will spawn again at a random spawn location! Also, moves you make will impact the end result so you might get into situations that you can't get out of so think things through.

## Build Instructions
You will need the SDL libraries for C++ in order to compile the code. Once you get those libraries set up for your work environment then simply run:
```
cmake .
make
./PushDaBox
```

## Video Demo
https://youtu.be/0l6k7ZXmyfA

## Cool features of this project
- I have written a JSON Serialisation and Deserialisation library for C++ that was used for this porject. This exists under src/JsonLib
- I also have implementations of shortest paths algorithms.
- The code design is pretty neat with Domain logic abstracted away and config files used to store temporary data.

### note
The code I have written mostly belongs in src/PushDaBox, src/MusicLib, src/JsonLib any other C++ code was provided by the University of Nottingham as this was a submission for a university project.
