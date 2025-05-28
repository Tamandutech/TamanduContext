// Include lib:
#include <Arduino.h>
#include "TamanduContext.hpp"

Tamandu::Context<int> *context = new Tamandu::Context<int>("test");

void setup() {
  // Initialize serial interface
  Serial.begin(9600);
}

void loop() {
  context->set(10);
  delay(1000);
}
