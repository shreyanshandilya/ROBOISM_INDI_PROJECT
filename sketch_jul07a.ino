const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int buzzer = 11;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(buzzer, OUTPUT);
}
void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);        
   digitalWrite(pingPin, LOW);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(9, OUTPUT);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.println("Done");
   Serial.print(inches);
   if (cm < 28) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(9,HIGH);
    tone(buzzer,100); // Send 1KHz sound signal... 
    delay(100);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(100);
   }
   else if (cm > 28 && cm < 56) {
    digitalWrite(2,LOW);
    digitalWrite(3, HIGH); 
    digitalWrite(9, HIGH);
    tone(buzzer, 500); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(500);     
    }
    
   else if (cm > 56 && cm < 74) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(9,HIGH);
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(800);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(800);  
   }
   
   else {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(9,LOW);
    }

   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
