int motionPin = 2;  
int ledPin = 13;    
volatile bool motionDetected = false;  

void motionISR() {
    motionDetected = true;  
}

void setup() {
    pinMode(motionPin, INPUT);  
    pinMode(ledPin, OUTPUT);    
    Serial.begin(9600);         

    attachInterrupt(digitalPinToInterrupt(motionPin), motionISR, RISING);
}

void loop() {
    if (motionDetected) {  
        digitalWrite(ledPin, HIGH); 
        Serial.println("Motion detected! LED ON");
        
        delay(1000); 

        digitalWrite(ledPin, LOW); 
        Serial.println("LED OFF");

        motionDetected = false; 
    }
}
