/*
 * W2 Challenge - Team Robutts :) 
 * LED colour transition pattern: fade in and fade out
 * 
 * Two types of writing: 
 *  - Analog - control the voltage
 *  - Digital - anything below a certain threshold = 0, anything above is a 1
 *    which is good for communicating between the arduino and computer
 *    
 * Using the analog here can let us control the intensity of light!
 */

int led_pin = 9;        // LED PWM pin
int intensity = 0;      // Current brightness of the LED
int fade = 5;           // Increment to reduce/increase intensity

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);

  // Set up serial output
  // Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Change intensity of LED
  analogWrite(led_pin, intensity);

  // Increment intensity
  intensity = intensity + fade;

  // Reverse direction of the intensity once it's reached max/min intensity
  if (intensity <= 0 || intensity >= 255) {
    fade = -fade;
  }

  // Use delay to mimic a fading effect
  delay(50);
}
