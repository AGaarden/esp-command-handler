#include <Arduino.h>
#include "CommandHandler.h"

// This is for testing lol
int lol(){
  printf("lol\n");
  return 0;
}

// This is also for testing lmao
int lmao(){
  printf("lmao\n");
  return 0;
}

void setup() {
  Serial.begin(115200);
  while(!Serial) {}

  AddCommand("lolCom", lol);
  AddCommand("lmaoCom", lmao);
  delay(200);
}

void loop() {
  RunCommand("lol");
  WaitForCommand();
}