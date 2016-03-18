#MIDTERM

------------------------------

###ISSUE/WHAT TO UPDATE:

The reason I call draw1() inside draw() instead of calling draw() within draw(), is not because of laziness or that I didn't understand the code. I did this as it was the only way I could figure out to get the result I wanted for my midterm. Believe it or not, I spent A LOT of time creating this code. I also thought that this was a sort of recursion, as we called seed2 within seed1 in one of your examples.
Since the midterm I have been trying to do what I now know is real recursion. Calling draw() within itself. And this is what I will do in the updated code. I still have problems though. I narrowed it down, and the problem is that everytime draw is called in ofApp.cpp or Wave.cpp, r2 is set back to the number it is set at in the call function. To explain easier:

in ofApp.cpp:

wave.draw(0, 0, 0.1, 2.0);

in Wave.cpp:

draw(x, y, z, 2.0);

As I am calling r2++; in the draw loop everytime, r2 increases to 3.0. But then it stops there. As if it is set back to 2.0 every time. I don't understand why.



------------------------------

