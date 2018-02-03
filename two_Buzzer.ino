
 int touchPin =5; // pin D1
 int Buzzer = 15; //pin D8
 int delay_t=1000;
 int counter=1;


// TONES  ==========================================
// Start by defining the relationship between 
//       note, period, &  frequency. 
#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 
// Define a special note, 'R', to represent a rest
#define  R     0

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerOut = 15;

 
void setup() 
{
 
  Serial.begin(9600); 
  pinMode(speakerOut,OUTPUT);
  pinMode(touchPin, INPUT);
  pinMode(Buzzer,OUTPUT);
}

// MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[], 
//  which sets each note's relative length (higher #, longer note) 
int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 


int melody1[] ={ C, C, b, b, b, g, g, g, e, a, R, C, a, a, a };
int beats1[] = {16, 16, 8, 8, 8, 32, 16, 8, 16, 8, 16, 8, 16, 8, 16};

int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;





// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}









 
void loop() 
{
  int touchValue = digitalRead(touchPin);
  if (touchValue == HIGH)
  {
   counter=counter+1; 
    Serial.println("TOUCHED");
    digitalWrite(Buzzer,HIGH);
    //delay(delay_t);
    delay(500);
    digitalWrite(Buzzer,LOW);
   
  
  }
  else
  {
    Serial.println("not touched");
  } 
  delay(500);
 
}
