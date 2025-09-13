#include <Wire.h>

// Define OV7670 image size
#define WIDTH 160
#define HEIGHT 120

void setup() {
    Serial.begin(115200);
    initCamera();  // Initialize the OV7670 Camera
}

void loop() {
    captureImage();
}

// Function to Initialize OV7670
void initCamera() {
    Wire.begin();
    Serial.println("Camera Initialized.");
    
    // Configure OV7670 registers (this depends on your module)
    // Example: Set to grayscale mode
    Wire.beginTransmission(0x42); // OV7670 default I2C address
    Wire.write(0x12);  // Register for image format
    Wire.write(0x80);  // Set to grayscale mode
    Wire.endTransmission();
}

// Function to Capture Image and Send via Serial
void captureImage() {
    Serial.println("Sending image...");
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel = read_pixel();  // Read a single pixel from OV7670
            Serial.println(pixel);
        }
    }
}

// Function to Read a Pixel from OV7670 (Dummy Example)
int read_pixel() {
    return random(0, 256);  // Generate random grayscale values (Replace with actual OV7670 read code)
}
