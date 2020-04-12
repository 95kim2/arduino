#define trigPin 14
#define echoPin 27
const int led[3] = {23, 21, 16}; //blue yellow, red
const int gnd = 17; // red gnd
int idx = 0, di = 1;


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++){
    pinMode(led[i], OUTPUT);
  }
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  
  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, LOW);   

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(115200); // Starts the serial communication
}

void loop() {
  // put your main code here, sto run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance= duration*0.034/2;
  int dly = (2*distance) * 20;

  Serial.println(distance);

  delay(dly);
  digitalWrite(led[idx], LOW);
  idx = idx+di;
  digitalWrite(led[idx], HIGH);

  if (idx == 2) di = -1;
  else if (idx == 0) di = 1;
}
