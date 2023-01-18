#include <Arduino.h>
#include "CommandHandler.h"

// This is for testing lol
int lol(String test){
  printf("lol\n");
  return 0;
}

// This is also for testing lmao
int lmao(String test){
  printf("lmao\n");
  return 0;
}

// Third tester and Stuff
int stuff(String test){
  printf("Stuff\n");
  return 0;
}

void setup() {
  Serial.begin(115200);
  while(!Serial) {}

  AddCommand("lolCom", lol);
  AddCommand("lmaoCom", lmao);
  AddCommand("Stuff", stuff);
  delay(200);
}

void loop() {
  RunCommand("Stuff", "");
  WaitForCommand();
}