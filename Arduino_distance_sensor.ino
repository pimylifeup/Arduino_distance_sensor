/*
 * Full tutorial and explanation at pimylifeup.com
 */
 
int trigger_pin = 2;
int echo_pin = 3;
long distance, pulse_duration;
 
void setup() {

  //Start serial output
  Serial.begin (9600);
  
  //Set pinMode
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  //Set the trigger pin to low
  digitalWrite(trigger_pin, LOW);
}
 
void loop() {
  
  //Set pin to high for 10 microseconds
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
 
  //Check the echo pin for when it goes high and save the time it took in microseconds)
  pulse_duration = pulseIn(echo_pin, HIGH);
 
  // Convert the time into a distance (cm)
  // Math: distance = ( (duration) * (speed of sound in cm per microsecond 0.0343 / 2)
  distance = round(pulse_duration * 0.0171);

  //convert the time into a distance (inches)
  // Math: distance = ( (duration) * (speed of sound in inches per microsecond 0.01350 / 2)
  //distance = round(pulse_duration/0.00675);
  
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  delay(500);
}
