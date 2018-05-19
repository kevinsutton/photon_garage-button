#include "InternetButton.h"

// Declare Local Variables
InternetButton b = InternetButton();
bool rainbow_mode = false;

void setup() {
  Serial.begin(115200);

  b.begin();
  b.setBrightness(50);
  initializeDoorLeft();
  initializeDoorMiddle();
  initializeDoorRight();
  initializeUnused();

  // notifyDoorLeftOpen();
  // initializeDoorLeft();
  // notifyDoorMiddleOpen();
  // initializeDoorMiddle();
  // notifyDoorRightOpen();
  // initializeDoorRight();

  // Subscribe to Garage Door Events
  Particle.subscribe("DOOR_LEFT", eventDoorLeft, MY_DEVICES);
  Particle.subscribe("DOOR_MIDDLE", eventDoorMiddle, MY_DEVICES);
  Particle.subscribe("DOOR_RIGHT", eventDoorRight, MY_DEVICES);

  // Define Cloud variables
  // Particle.variable("DOOR_LEFT", sd1);
  // Particle.variable("DOOR_MIDDLE", sd2);
  // Particle.variable("DOOR_RIGHT", sd3);

  // Define Cloud Functions
  // Particle.function("triggerDoor", triggerDoor);
  // Particle.function("checkDoorStatus", checkDoorStatus);
}

void loop() {
  // // If this calls for a full spectrum situation, let's go rainbow!
  //   if(b.allButtonsOn()) {
  //       // Publish the event "allbuttons" for other services like IFTTT to use
  //       Particle.publish("allbuttons",NULL, 60, PRIVATE);
  //       b.rainbow(5);
  //       rainbow_mode = true;
  //
  //       // If all buttons are on, don't try to process
  //       // the individual button responses below.  Just return.
  //       return;
  //   }
  //
  //   // If we are not in rainbow mode anymore, turn the LEDs off
  //   if (rainbow_mode == true) {
  //       b.allLedsOff();
  //       rainbow_mode = false;
  //   }
  //
  //   // Process individual buttons and LED response
  //   if (b.buttonOn(1)) {
  //       b.ledOn(12, 255, 0, 0); // Red
  //       // Publish the event "button1" for other services like IFTTT to use
  //       Particle.publish("button1",NULL, 60, PRIVATE);
  //       delay(500);
  //   }
  //   else {
  //       b.ledOn(12, 0, 0, 0);
  //   }
  //
  //   if (b.buttonOn(2)) {
  //       b.ledOn(3, 0, 255, 0); // Green
  //       // Publish the event "button2" for other services like IFTTT to use
  //       Particle.publish("button2",NULL, 60, PRIVATE);
  //       delay(500);
  //   }
  //   else {
  //       b.ledOn(3, 0, 0, 0);
  //   }
  //
  //   if (b.buttonOn(3)) {
  //       b.ledOn(6, 0, 0, 255); // Blue
  //       // Publish the event "button3" for other services like IFTTT to use
  //       Particle.publish("button3",NULL, 60, PRIVATE);
  //       delay(500);
  //   }
  //   else {
  //       b.ledOn(6, 0, 0, 0);
  //   }
  //
  //   if (b.buttonOn(4)) {
  //       b.ledOn(9, 255, 0, 255); // Magenta
  //       // Publish the event "button4" for other services like IFTTT to use
  //       Particle.publish("button4",NULL, 60, PRIVATE);
  //       delay(500);
  //   }
  //   else {
  //       b.ledOn(9, 0, 0, 0);
  //   }
  //
  //   if(b.allButtonsOff()) {
  //       // Do something here when all buttons are off
  //   }
}

int relayOff(String command){
  // Ritual incantation to convert String into Int
  char inputStr[64];
  command.toCharArray(inputStr,64);
  int i = atoi(inputStr);

  // Respond
  return 1;
}

int initializeDoorLeft() {
  // Set default state of LEDs for Left Door
  b.ledOn(1, 255, 128, 0); // Orange
  b.ledOn(2, 255, 128, 0); // Orange
  b.ledOn(3, 255, 128, 0); // Orange

  return 1;
}

int initializeDoorMiddle() {
  // Set default state of LEDs for Left Door
  b.ledOn(5, 0, 255, 0); // Green
  b.ledOn(6, 0, 255, 0); // Green
  b.ledOn(7, 0, 255, 0); // Green

  return 1;
}

int initializeDoorRight() {
  // Set default state of LEDs for Left Door
  b.ledOn(9, 255, 255, 0); // Yellow
  b.ledOn(10, 255, 255, 0); // Yellow
  b.ledOn(11, 255, 255, 0); // Yellow

  return 1;
}

int initializeUnused() {
  // Set default state of LEDs for Left Door
  b.ledOn(4, 255, 255, 255); // White
  b.ledOn(8, 255, 255, 255); // White

  return 1;
}

int notifyDoorLeftOpen() {
  for (int i=0; i <= 5; i++){
    // Toggle Middle LED to RED
    b.ledOn(1, 255, 128, 0); // Orange
    b.ledOn(2, 255, 0, 0); // Red
    b.ledOn(3, 255, 128, 0); // Orange
    delay(100);

    // Switch Colors
    b.ledOn(1, 255, 0, 0); // Orange
    b.ledOn(2, 255, 128, 0); // Red
    b.ledOn(3, 255, 0, 0); // Orange
    delay(100);
  }

  //End in Open State
  b.ledOn(1, 255, 128, 0); // Orange
  b.ledOn(2, 255, 0, 0); // Red
  b.ledOn(3, 255, 128, 0); // Orange

  return 1;
}

int notifyDoorMiddleOpen() {
  for (int i=0; i <= 5; i++){
    // Toggle Middle LED to RED
    b.ledOn(5, 0, 255, 0); // Green
    b.ledOn(6, 255, 0, 0); // Red
    b.ledOn(7, 0, 255, 0); // Green
    delay(100);

    // Switch Colors
    b.ledOn(5, 255, 0, 0); // Red
    b.ledOn(6, 0, 255, 0); // Green
    b.ledOn(7, 255, 0, 0); // Red
    delay(100);
  }

  //End in Open State
  b.ledOn(5, 0, 255, 0); // Green
  b.ledOn(6, 255, 0, 0); // Red
  b.ledOn(7, 0, 255, 0); // Green

  return 1;
}

int notifyDoorRightOpen() {
  for (int i=0; i <= 5; i++){
    // Toggle Middle LED to RED
    b.ledOn(9, 255, 255, 0); // Yellow
    b.ledOn(10, 255, 0, 0); // Red
    b.ledOn(11, 255, 255, 0); // Yellow
    delay(100);

    // Switch Colors
    b.ledOn(9, 255, 0, 0); // Red
    b.ledOn(10, 255, 255, 0); // Yellow
    b.ledOn(11, 255, 0, 0); // Red
    delay(100);
  }

  //End in Open State
  b.ledOn(9, 255, 255, 0); // Yellow
  b.ledOn(10, 255, 0, 0); // Red
  b.ledOn(11, 255, 255, 0); // Yellow

  return 1;
}

void eventDoorLeft(const char *event, const char *data)
{
  if (strcmp(data,"OPEN")==0) {
    // Garage Door is OPEN, Notify
    notifyDoorLeftOpen();
  }
  else if (strcmp(data,"CLOSED")==0) {
    // Garage Door is CLOSED, Reset
    initializeDoorLeft();
  }
  else {
    // if the data is something else, don't do anything.
    // Really the data shouldn't be anything but those two listed above.
  }
}

void eventDoorMiddle(const char *event, const char *data)
{
  if (strcmp(data,"OPEN")==0) {
    // Garage Door is OPEN, Notify
    notifyDoorMiddleOpen();
  }
  else if (strcmp(data,"CLOSED")==0) {
    // Garage Door is CLOSED, Reset
    initializeDoorMiddle();
  }
  else {
    // if the data is something else, don't do anything.
    // Really the data shouldn't be anything but those two listed above.
  }
}

void eventDoorRight(const char *event, const char *data)
{
  if (strcmp(data,"OPEN")==0) {
    // Garage Door is OPEN, Notify
    notifyDoorRightOpen();
  }
  else if (strcmp(data,"CLOSED")==0) {
    // Garage Door is CLOSED, Reset
    initializeDoorRight();
  }
  else {
    // if the data is something else, don't do anything.
    // Really the data shouldn't be anything but those two listed above.
  }
}
