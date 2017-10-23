int fsrPin = 0;     
int fsrReading;     
 
void setup(void) {
  Serial.begin(9600);   
}
 
void loop(void) {
  fsrReading = analogRead(fsrPin);  
 
  Serial.print("Analog reading = ");
  Serial.print(fsrReading);     
 
  if (fsrReading < 500) {
    Serial.println(" - No pressure");
  } else if (fsrReading < 800) {
    Serial.println(" - Light touch");
  } else if (fsrReading < 800) {
    Serial.println(" - Light squeeze");
  } else if (fsrReading < 1000) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }
  delay(1000);
} 
