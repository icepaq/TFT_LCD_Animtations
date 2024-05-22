// Wednesday May 22, 2024
// Author: ChatGPT
// Co-Author: icepaq

#include <TFT_eSPI.h>  // Include the graphics library

TFT_eSPI tft = TFT_eSPI();  // Create an instance of the library

const int radius = 50;    // Radius of the circle
const int numLines = 12;  // Number of lines in the loader
const int lineLength = 20; // Length of each line
const int lineWidth = 6;  // Width of each line
const int spinSpeed = 1000; // Speed of spinning (higher values for slower spin)

void setup() {
  tft.init();               // Initialize the display
  tft.setRotation(1);       // Set display rotation
  tft.fillScreen(TFT_BLACK); // Clear the screen
}

void loop() {
  int centerX = tft.width() / 2;  // Center X of the circle
  int centerY = tft.height() / 2; // Center Y of the circle

  unsigned long currentTime = millis();
  float offset = float(currentTime % spinSpeed) / spinSpeed; // Calculate the offset

  for (int i = 0; i < numLines; i++) {
    // Calculate the brightness of the line based on the offset
    uint8_t brightness = 255 * ((offset + float(i) / numLines) - int(offset + float(i) / numLines));

    // Calculate the start and end points of the line
    float angle = 2 * PI * i / numLines;
    int xStart = centerX + (radius - lineLength) * cos(angle);
    int yStart = centerY + (radius - lineLength) * sin(angle);
    int xEnd = centerX + radius * cos(angle);
    int yEnd = centerY + radius * sin(angle);
    
    // Draw the wide line
    tft.drawWideLine(xStart, yStart, xEnd, yEnd, lineWidth, tft.color565(brightness, brightness, brightness));
  }
  
  // Small delay to control the speed of the animation
  delay(33);
  
  // Clear the screen for the next frame
  // tft.fillScreen(TFT_BLACK);
}
