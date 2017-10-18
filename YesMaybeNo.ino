int timeShowRandom = 1000;
int timeShowDecision = 3000;
int timeBlink = 50;
int buttonPin = 3;
 
int buttonPress = false;
int randomNumber;
int previousNo = 0;
int timePassed = 0;
 
void setup() {    

  pinMode(buttonPin, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
 
}
 
void getRandomNo() {
  int rand = random(10,13);
  if(rand == previousNo) {
    getRandomNo();
  } else {
    randomNumber = rand;
    previousNo = randomNumber;
  }
}
 
void loop() {
  if(digitalRead(buttonPin) == HIGH && buttonPress == false) {
     buttonPress = true;
  } if(buttonPress == true && timePassed <= timeShowRandom) {
    getRandomNo(); // Get random pin number
    digitalWrite(randomNumber, HIGH);
    delay(timeBlink);  
    digitalWrite(randomNumber, LOW);
    delay(timeBlink);  
    timePassed = timePassed + (timeBlink * 2);
  } else if(buttonPress == true) {
    digitalWrite(random(10,13), HIGH); 
    delay(timeShowDecision); // For x seconds
    buttonPress = false; // Set button to be enabled again
    timePassed = 0;
  } else {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }    
}
