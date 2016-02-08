
class Bird{
  
  float size;
  float xPos, yPos;
  float xSpeed, ySpeed;
  float feather;
  
  //setup
  Bird(){
    size = 1;
    //feather = color(random(100, 255));
    
  }
  
   void giveBirth(){//draw
   
   xPos = mouseX;
   yPos = mouseY;
   xSpeed = random(-2, 2);
   ySpeed = random(-2, 2);
 }
  
  void update(){
    
    strokeWeight(2);
    stroke(0);
    fill(feather);
    line(xPos, yPos, xPos+(size*5), yPos - (size*5));
    line(xPos+(size*5), yPos - (size*5) ,xPos+(size*10), yPos);
    line(xPos+(size*10), yPos, xPos+(size*5), yPos-(size*3));
    line(xPos+(size*5), yPos-(size*3), xPos, yPos);
    feather = color(random(200), random(50), random(50));
    xPos +=xSpeed;
    yPos -=ySpeed;
    
    if (yPos > 600){
      yPos = 0;
    }
    if (yPos < 0){
      yPos = 600;
    }
    
    if (xPos > 600){
      xPos = 0;
    }
    if (xPos < 0){
      xPos = 600;
    }
    
  }
  
}