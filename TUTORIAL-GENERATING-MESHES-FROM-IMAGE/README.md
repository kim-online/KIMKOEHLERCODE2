##Tutorial: Generate Mesh from Image and Animate the Mesh
                                                            by Kim Koehler and Claire Hu

This tutorial is specifically for generating a mesh from and image, for basic information on generating Mesh please see [reference](http://openframeworks.cc/ofBook/chapters/generativemesh.html).

---------------------------------

In this tutorial we will generate a mesh from an Image. Please choose an image and follow along. This is the image we will generate our mesh from in this tutorial:

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/1.jpg" height="400">

Start by saving your picture to the data folder inside your openFrameworks project.

The first thing we will do in the code is changing the window size(int the main.cpp file) to match your picture, in our case:

```
ofSetupOpenGL(564,714,OF_WINDOW);
``
In your ofApp.h file add:
```
ofImage image;
```
Lastly, in your ofApp.cpp:
```
void ofApp::setup(){
    image.load("1.png");
}

void ofApp::draw(){
    image.draw(0,0);
}
```

When running this sketch, your picture should show up perfectly fitted in the window. Otherwise, you have failed and you are honestly a really bad coder.


<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/3.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/4.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/5.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/6.png" height="400">

[Moving Mesh demo](https://drive.google.com/open?id=0B7a_3eIMDihFSkY3aTNWdW1DUG8)
