const int LDR_PIN1 = A0; // LDR sensor pin
const int PIR_PIN = 2;  // PIR sensor pin
const int TRIGGER_PIN = 7; // Ultrasonic sensor trigger pin
const int ECHO_PIN = 6;    // Ultrasonic sensor echo pin
const int LIGHT_PIN = 5;   // Output pin to control the light (e.g., LED)
const int FAULT_PIN=8;
const int LDR_PIN2 = A1;
const int outputPin= 4;
int lightIntensity = 30;    // Initial light intensity (30%)
int maxDistance = 150;       // Maximum distance for light control (60 cm)

void setup() {
  pinMode(LDR_PIN1, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAULT_PIN, OUTPUT);
  pinMode(LDR_PIN2, INPUT);
  //pinMode(outputPin, OUTPUT);  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  int ldr1Value = analogRead(LDR_PIN1);
  //int pirValue = digitalRead(PIR_PIN);
  int pirValue = 1;
  int ldr2Value = analogRead(LDR_PIN2);
  int count=0;
  // Check if it's dark (LDR sensed low light)
  if (ldr1Value < 300) 
  {
    Serial.println("darkness");
    // If motion is detected, control the light intensity based on distance
    if (pirValue == HIGH) 
    {
      Serial.println("motion detected");      
      int distance = getDistance();
      Serial.print("distance : ");
      Serial.println(distance);
            
      lightIntensity = map(distance, 0, maxDistance, 100, 30); // Map distance to light intensity
      lightIntensity = constrain(lightIntensity, 30, 100);      // Ensure it's within bounds (30-100%)
    } 
    else 
    {
      Serial.println("motion not detected");      
      // No motion detected, reset the light intensity to 30%
      lightIntensity = 20;
    }
  } 
  else 
  {
    Serial.println("darkness");      
    // It's not dark, turn off the light
    lightIntensity = 0;
  }
  Serial.println(map(lightIntensity, 0, 100, 0, 255));      
  // Control the light based on the calculated intensity
  analogWrite(LIGHT_PIN, map(lightIntensity, 0, 100, 0, 255));
  
  // Debugging output
  Serial.print("Light Intensity (%): ");
  Serial.println(lightIntensity);
  // Check if LDR 1 detects darkness and LDR 2 experiences brightness
  if (ldr1Value < 200 && ldr2Value > 800) {
    digitalWrite(outputPin, HIGH);
    delay(10000); // Keep the output pin high for 10 seconds
    digitalWrite(outputPin, LOW);
  }  
  // Check if LDR 2 does not experience brightness for more than 24 hours
  unsigned long currentMillis = millis();
  static unsigned long lastBrightnessTime = 0;
  static boolean brightnessFlag = false;
  if (ldr2Value < 800) 
  {
    if (!brightnessFlag) 
    {
      lastBrightnessTime = currentMillis;
      brightnessFlag = true;
    }
    // Check if it's been more than 24 hours
    if (currentMillis - lastBrightnessTime >= 28800000UL) { // 24 hours in milliseconds
      digitalWrite(outputPin, HIGH);
      delay(10000); // Keep the output pin high for 10 seconds
      digitalWrite(outputPin, LOW);
      brightnessFlag = false; // Reset the flag
    }
  } 
  else 
  {
    brightnessFlag = false; // Reset the flag when brightness is detected
  }
  delay(500); // Delay for stability
  
}

int getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;
  
  return distance;
}
