
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
  frameRate(frameRate);

  randomSeed(randomSeed);
  noiseSeed(noiseSeed);

  noiseDetail(7,.4);
}

float phase = 0;
float phaseSpeed = .12;

float crawlers = 1.25;

void draw() {
  //if(frameCount > seconds*frameRate) {
  //  exit();
  //}
  if(phase > 2*PI) {
    exit();
  }
  
  background(0);
  frameRate(50);
  
  pushMatrix();
  translate(scale/2, scale/2);
  scale(scale);

  for(int x = 0; x < pixelsWidth; x++) {
    for(int y = 0; y < pixelsHeight; y++) {
      float brightness;
      
      if(y == 0) {
        brightness = pow(map(sin(phase + map(x,0,pixelsWidth,0,crawlers*2*PI)),-1,1,0,1),1);
      }
      else {
        brightness = pow(map(sin(phase - PI - map(x,0,pixelsWidth,0,crawlers*2*PI)),-1,1,0,1),1);
      }
      
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