import processing.serial.*;

Serial myPort;

PImage logo;

int bgcolor = 0;

void setup() {
  // setting color mode
  size(1,1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  
  // load image
  logo = loadImage("https://brandslogos.com/wp-content/uploads/images/large/arduino-logo-1.png");
  surface.setSize(logo.width, logo.height);
  
  // show available serial ports
  println("Avaiable serial ports:");
  println(Serial.list());
  
  // create serial object
  myPort = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  // reading arduino data from serialport
  if(myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  } 
  // set and display image background
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
