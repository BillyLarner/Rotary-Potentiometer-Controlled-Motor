int In1Pin = 10;                                                //Assigns pin 10 the value In1Pin
int In2Pin = 9;                                                 //Assigns pin 9 the value In2Pin
int Enable1Pin = 11;                                            //Assigns pin 11 the value Enable1Pin
bool RotationDir;                                               //Creates a variable for the motors direction
int RotationSpeed;                                              //Creates an interger to retain the motors direction

void setup() {
  pinMode (In1Pin, OUTPUT);                                     //Sets pin10 to OUTPUT
  pinMode (In2Pin, OUTPUT);                                     //Sets pin9 to OUTPUT
  pinMode (Enable1Pin, OUTPUT);                                 //Sets Pin11 to OUTPUT
}

void loop() {
  int potenVal = analogRead (A0);                               //Convers the analog signal of the rotary potentiometer to a digital signal
  RotationSpeed = potenVal - 512;                               //Takes the value of the potentiometer and compares it 512, if the value if the potentiometer exceeds 512 the motor will turn clockwise, if it is less than 512 it will rotate counterclockwise
    if (potenVal > 512)
      RotationDir = true;
    else
      RotationDir = false;
  RotationSpeed = abs(potenVal - 512);                          //Controls the speed of the motor by determining how far the current potentiometer value is from 512, the further the value is the faster the motor will rotate
  driveMotor (RotationDir,map(RotationSpeed, 0, 512, 0, 255));  //Controls the direction and speed of the motor
}

void driveMotor (bool dir, int speed) {
  if (RotationDir) {                                            //controls the direction the motor will rotate
    digitalWrite (In1Pin, HIGH);
    digitalWrite (In2Pin, LOW);
  }
  else {
    digitalWrite (In1Pin, LOW);
    digitalWrite (In2Pin, HIGH);
  }
  analogWrite(Enable1Pin, constrain(speed, 0 , 255));           //Controls the speed the motor rotates
}