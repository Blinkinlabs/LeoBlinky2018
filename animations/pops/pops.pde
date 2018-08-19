
// Note: Render three times, once for each section below

//// DIS
//static final int pixelsWidth = 7;
//static final int pixelsHeight = 2;

//static final int randomSeed = 1;
//static final int noiseSeed = 1;

//// ORI
//static final int pixelsWidth = 7;
//static final int pixelsHeight = 2;

//static final int randomSeed = 14;
//static final int noiseSeed = 14;

// ENT
static final int pixelsWidth = 9;
static final int pixelsHeight = 2;

static final int randomSeed = 23;
static final int noiseSeed = 23;

static final int scale = 1;

static int frameRate = 60;
static int seconds = 10;


void setup() {
  surface.setSize(pixelsWidth*scale, pixelsHeight*scale);
  //size(500,500);
  frameRate(frameRate);

  randomSeed(randomSeed);
  noiseSeed(noiseSeed);

  noiseDetail(7,.4);
}

float phase = 0;
float noiseScale = .70;
float scaleY = 1.1;
float phaseSpeed = .04;

void draw() {
  if(frameCount > seconds*frameRate) {
    exit();
  }
  
  background(0);
  frameRate(50);
  
  pushMatrix();
  translate(scale/2, scale/2);
  scale(scale);

  for(int x = 0; x < pixelsWidth; x++) {
    for(int y = 0; y < pixelsHeight; y++) {
      float radialPosA = sin(map(x,0,pixelsWidth, 0,2*PI))*(1+y*scaleY);
      float radialPosB = cos(map(x,0,pixelsWidth, 0,2*PI))*(1+y*scaleY);
      
      float brightness = map(noise(radialPosA*noiseScale,radialPosB*noiseScale,phase),.2,.8,0,.8);
//      println(brightness);

      if(random(1) > .99) {
        brightness = 1;
      }
      
//      stroke(brightness*255, brightness*50, brightness*100);
      stroke(brightness*255);
      point(x,y);
    }
  }
  popMatrix();
  
  float increment = phaseSpeed+noise(phase)/15;
  phase += increment;
  
  //stroke(255,255);
  //text(increment,50,50);
  
  saveFrame("line-######.png");
}