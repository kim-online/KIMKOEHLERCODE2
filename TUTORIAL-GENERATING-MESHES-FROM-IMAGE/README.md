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
```
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

Ok, lets start generating the mesh. In this case we choose to only create a mesh where there is bright colors. We do this by running through every pixel and then adding a threshold. 

Start by adding this to the ofApp.h:
```
  ofMesh mesh;
```
Then, in the ofApp.cpp file we do this:
```
void ofApp::setup(){
    image.load("1.png")

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();

    float intensityThreshold = 100.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getBrightness();
            if (intensity >= intensityThreshold) {
                ofVec3f pos(x, y, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }
}
void ofApp::draw(){
    ofBackground(0,0,255);
    mesh.draw(); 
}
```
<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2.png" height="400">

We choose to use a blue background because it makes it easier to see where the mesh is created. As you can see, it is only created where there are bright colors in the picture. There are other variables you can base your threshold on, in this case we are using getBrightness(), but you can use others like getHex(), getLightness(), getHue(), getSaturation() etc etc.

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/3.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/4.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/5.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/6.png" height="400">

[Moving Mesh video demo](https://drive.google.com/open?id=0B7a_3eIMDihFSkY3aTNWdW1DUG8)

**Moving Mesh screenshots:**

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-1.png" height="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-2.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-3.png" width="400">  <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-4.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-5.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-6.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-7.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-8.png" width="400"> 
