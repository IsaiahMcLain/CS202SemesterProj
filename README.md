# CS-202-Semester-Project-F21
## Challenge Level Project - Partial

![.wav format](http://soundfile.sapp.org/doc/WaveFormat/wav-sound-format.gif)


# Contributors
| Author            | Contribution                                                                |
| ----------------- | ------------------------------------------------------------------ |
| -[Isaiah McLain](https://github.com/McLainIsaiah) | Frontend UI and program linking |
| -[Keaton Clark](https://github.com/Keaton-Clark) | Backend file i/o and file processing |
| -[Kurt Stumpf](https://github.com/1102-Stumpf-Kurt) | Made file i/o and UML Diagram |

# Challenges
The largest challenge of the backend was dealing with the 16 bit-width as the file needed to be read in 8 bit chunks and then converted to 16 bit. This was a roadblock for a significant portion of 
the project as we could not work on any of the other file processing until we knew what format the data was going to be in and how we were going to interact with it. 

The largest challenge for dealing with the frontend was handling user input and meeting the program flow requirements. Due to how the program flow is set up, it made it difficult to use while loops to have the program continue to run even when a user enters an incorrect input. If there was more time I would've researched more into handling incorrect user input. This is something to work on for the project in the future to make it run more smoothly. Due to errors and time it took to figure out why audio wasn't playing when echo was applied with other methods, the GUI portion of the project is nonfunctional however this will be worked on in the future as well with more time.

The largest challenge was trying to figure out how to properly read in a .wav and making sure that during the user unput a .wav file was corerectly checked and verfied and then passed to the user to then be run. Another was making sure that the Doxygen was correctly inplemented into the code, as working with doxygen was another learning process. 

# Issues
No known missing functionality in the backend processors.

Incorrect user input doesn't break program however program resets which isn't ideal. Found error when linking the program components together where echo cannot work with any other method. If echo is used on a file by itself it works correctly, however if another method is added to that audio file there will be no audio that plays. This is something to work on in the future of this progject as well. 

# UML Diagram


