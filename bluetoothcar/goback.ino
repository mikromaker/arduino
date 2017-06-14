//L293D
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

int command = 0; // stop

//This will run only one time.
void setup(){
    Serial.begin(9600);
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
     
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  
}


void loop(){
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    command = Serial.read(); // Reads the data from the serial port
   }
   if (command == '1') {
      analogWrite(motorPin1, 0);
      analogWrite(motorPin2, 180);
      analogWrite(motorPin3, 180);
      analogWrite(motorPin4, 0);
      delay(1000); 
      analogWrite(motorPin1, 0);
      analogWrite(motorPin2, 0);
      analogWrite(motorPin3, 0);
      analogWrite(motorPin4, 0);
      command = 0;
   }
   else if (command == '2') {
      analogWrite(motorPin1, 180);
      analogWrite(motorPin2, 0);
      analogWrite(motorPin3, 0);
      analogWrite(motorPin4, 180);
      delay(1000);   
      analogWrite(motorPin1, 0);
      analogWrite(motorPin2, 0);
      analogWrite(motorPin3, 0);
      analogWrite(motorPin4, 0); 
      command = 0;
   } 

}
