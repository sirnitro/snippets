#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Create an instance of the SSD1306 display
#define SCREEN_WIDTH 128  // Change according to your OLED screen
#define SCREEN_HEIGHT 64  // Change according to your OLED screen
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9200);

  // Initialize the OLED display
  if(!display.begin(SSD1306_PAGEADDR, 0x3C)) {  // Change 0x3C to your display's I2C address if different
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);  // Infinite loop if display initialization fails
  }
  
  // Clear the display buffer
  display.clearDisplay();

  // Display text on the screen
  display.setTextSize(1);  // Set text size to 1 (small)
  display.setTextColor(SSD1306_WHITE);  // Set text color to white
  display.setCursor(0,0);  // Set cursor position (0,0)
  display.println(F("Hello, world!"));
  
  // Draw shapes
  display.drawLine(0, 16, SCREEN_WIDTH, 16, SSD1306_WHITE); // Draw a horizontal line
  display.drawRect(10, 30, 50, 20, SSD1306_WHITE); // Draw a rectangle
  display.drawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, SSD1306_WHITE); // Draw a circle

  // Display the content on the screen
  display.display();
}

void loop() {
  // Add any code that you want to repeatedly execute
}

