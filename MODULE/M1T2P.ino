#define PIR_PIN 2
#define LED_PIN 13

bool motionDetected = false;

void motionISR();

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("System Ready!");

    attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionISR, RISING);
}

void loop() {
    if (motionDetected) {
        Serial.println("Motion Detected!");
        digitalWrite(LED_PIN, HIGH);
        delay(2000);
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED turned OFF.");
        motionDetected = false;
    }
}

void motionISR() {
    motionDetected = true;
}
