/*  Author: Altug KAYA          Date: 10.08.2015
 *
 *  Description:  A code for Keyes microphone module for Arduino UNO platform.
 *  There has been two microphone modules. It is because instead of detecting 
 *  sound, they detect the change of the volume of the sound. So, this code's 
 *  purpose is fixing the given hardware. 
 
 *  It was designed to rapidly changing sounds. That's why two microphones were 
 *  used. If user moves the source of the sound or the microphones, LEDs will
 *  light up more accurately with respect to the rhythm of the sound.
*/


int micPin1 = A0; //  pin that the mic1 is attached to
int micPin2 = A5;//  pin that the mic2 is attached to
int micVal1 = 0;//  the mic value
int micVal2 = 0;//  the mic value
int currPin = A0;//  For determination whether the first or the second mic
int Before_currVal = 0;//For comparison
int After_currVal = 0;//For comparison

const int LED_DELAY = 100;
const int VALUE_DELAY = 10;

int LEDPins[] = {3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  for(int i = 0; i < sizeof(LEDPins); i++)
    pinMode(LEDPins[i], OUTPUT);
  Serial.begin(9600);  //for test the input value initialize serial
}

void loop() {
  micVal1 = analogRead(micPin1);  // read pin value
  Serial.print("R ");  //  for debugging  
  Serial.println(micVal1);  //  for debugging
  delay(VALUE_DELAY);
  micVal2 = analogRead(micPin2);
  Serial.print("L ");  //  for debugging
  Serial.println(micVal2);  //  for debugging
  
  if( micVal1 > micVal2 )
    currPin = micPin1;
  else if ( micVal1 < micVal2 )
    currPin = micPin2;
  else
    currPin = micPin1;  /*  It is not possible to be the exact same value. 
    It is just for perfect coding by handling all cases  */
    
  Before_currVal = analogRead(currPin);
  Serial.print("CB ");  //  Current Before
  Serial.println(Before_currVal);
  delay(VALUE_DELAY);
  After_currVal = analogRead(currPin);
  Serial.print("CA ");  //  Current After
  Serial.println(After_currVal);
  Serial.print("ABS ");  //  Prints the absulute value
  Serial.println( abs(Before_currVal - After_currVal) );  //  Prints the absulute value
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  
  switch ( abs(Before_currVal - After_currVal) ){
    case 0:
    break;
    
    case 1:
    for(int i = 0; i < 1; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    case 2:
    for(int i = 0; i < 2; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    case 3 ... 4:
    for(int i = 0; i < 4; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    case 5:
    for(int i = 0; i < 5; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    case 6:
    for(int i = 0; i < 6; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    case 7 ... 10:
    for(int i = 0; i < 7; i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
    
    default:
    for(int i = 0; i < sizeof(LEDPins); i++)
      digitalWrite(LEDPins[i], HIGH);
    break;
  }
  
  delay(LED_DELAY);  //Turning on delay
  
  switch ( abs(Before_currVal - After_currVal) ){
    case 0:
    break;
    
    case 1:
    for(int i = 0; i < 1; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    case 2:
    for(int i = 0; i < 2; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    case 3 ... 4:
    for(int i = 0; i < 4; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    case 5:
    for(int i = 0; i < 5; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    case 6:
    for(int i = 0; i < 6; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    case 7 ... 10:
    for(int i = 0; i < 7; i++)
      digitalWrite(LEDPins[i], LOW);
    break;
    
    default:
    for(int i = 0; i < sizeof(LEDPins); i++)
      digitalWrite(LEDPins[i], LOW);
    break;
  }
  
  delay(VALUE_DELAY);  //Turning off delay
}
