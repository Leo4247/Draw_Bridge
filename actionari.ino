// Motor connections
int enA = 9;
int in1 = 13;
int in2 = 12;
//laser detector
#define sensor 7
#define internal_led 13
int value = 0;

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(internal_led, OUTPUT);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void loop() {
    
    value = digitalRead(sensor);
// transforma != in == pt detectarea laser pe care o vrem noi
    if (value == HIGH){
      directionControl();
    }
}
void directionControl() {
    // Set motor to maximum speed (dictated by enA)
    // PWM value ranges from 0 to 255
    analogWrite(enA, 255);

    // Turn on motor for 5 seconds (5000ms)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(5000);

    // Turn off motor for 5 seconds (5000ms while boat passes)
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(5000);

    // Turn motor the other way for 5 seconds (5000ms)
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(5000);
	
    // Turn off motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
