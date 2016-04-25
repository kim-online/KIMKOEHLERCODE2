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

Now let us create a cooler background, in the draw:
```
 ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    mesh.draw();
```    
By running through all these pixels we have created a lot of Vertices, a bit to much to process actually. Thus we have to resize the image. But don't worry, we are generating a mesh, not creating a HQ image. Add this to setup:
```
image.load("1.png");
image.resize(200, 200);
```
But we have to add some more code to put the points back in position again:
```
if (intensity >= intensityThreshold) {
    // We shrunk our image by a factor of 4, so we need to multiply our pixel
    // locations by 4 in order to have our mesh cover the openFrameworks window
    ofVec3f pos(x*4, y*4, 0.0);
    mesh.addVertex(pos);
    mesh.addColor(c);
}
```
Now that this sketch is easier to process, lets add som lines!

First add this to setup:
```
mesh.setMode(OF_PRIMITIVE_LINES); //Change from points to lines

mesh.enableIndices();
```
We now want to connect the lines. But not all of them, thus we put a threshold set by distance between all the points. You can change the threshold to connect more or less lines.
Add this after the last loop:
```
float connectionDistance = 30;
int numVerts = mesh.getNumVertices();
for (int a=0; a<numVerts; ++a) {
    ofVec3f verta = mesh.getVertex(a);
    for (int b=a+1; b<numVerts; ++b) {
        ofVec3f vertb = mesh.getVertex(b);
        float distance = verta.distance(vertb);
        if (distance <= connectionDistance) {
            // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
            // connected to form a line
            mesh.addIndex(a);
            mesh.addIndex(b);
        }
    }
}
```
Now your picture should look something like this!

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/3.png" height="400">

First step to make it 3D is to change the Z value of every point. In this example it is based on saturation. We are maping the saturation value to the Z value.
Add this in the first for loop:
```
if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x*4, y*4, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
```

Last step is to add a camera that we can change and look around in 3d with. Add this to the header file:
```	
	ofEasyCam easyCam;
```
Then update your draw() so it looks like this:
```
void ofApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            mesh.draw();
        ofPopMatrix();
    easyCam.end();
}
```
BAM ! It should look something like this now.

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/4.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/5.png" height="400">

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/6.png" height="400">

[Moving Mesh video demo](https://drive.google.com/open?id=0B7a_3eIMDihFSkY3aTNWdW1DUG8)

**Moving Mesh screenshots:**

<img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-1.png" height="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-2.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-3.png" width="400">  <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-4.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-5.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-6.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-7.png" width="400"> <img src="https://github.com/kim-online/KIMKOEHLERCODE2/blob/master/TUTORIAL-GENERATING-MESHES-FROM-IMAGE/IMAGES/2-8.png" width="400"> 
