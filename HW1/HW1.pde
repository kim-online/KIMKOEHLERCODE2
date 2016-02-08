int amount = 30;
Bird [] birds;

void setup(){
  size(600, 600);
  
  birds = new Bird[amount];
  
  for(int i=0; i<amount; i++){
   birds[i] = new Bird();
  }
}

void draw(){
  background(255);
  for(int i=0; i<amount; i++){
    if (mousePressed){
    birds[i].giveBirth();
    }
  
  birds[i].update();
    for(int j=i; j<amount; j++)
    {
      if(i!=j)
      {
        float distance = dist(birds[i].xPos,birds[i].yPos,birds[j].xPos,birds[j].yPos);
        if(distance<=10)
        {
          birds[i].xSpeed = random(-2, 2);
          birds[i].ySpeed = random(-2, 2);
          birds[j].xSpeed = random(-2, 2);
          birds[j].ySpeed = random(-2, 2);
        }
      }
    }
  }
  
 
}