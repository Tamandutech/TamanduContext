// Include lib:
#include "TamanduContext.hpp"
#include <Arduino.h>

Tamandu::Context<int> *context;

void setup() {
  // Initialize serial interface
  Serial.begin(9600);

  context = new Tamandu::Context<int>("test");
}

void loop() {
  context->set(10);
  delay(1000);
}
