int analogPin = 14;     // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;           // variable to store the value read

#define M1 34
#define M2 66
#define FINGERS 5

struct FingerFeedback {
  int pin;
  FingerFeedback(int pin) {
    this->pin = pin;

  }
  int val() {
    return analogRead(this->pin);
  }
  
};

struct Glove{
  int m1,m2;
  FingerFeedback** fingers;
  
  union{
    int data[5];
    char buff[5*2];  
  } BUFFER;

  Glove(int pins[]){
    this->m1 = M1; 
    this->m2 = M2;
    fingers = new FingerFeedback*[FINGERS];
    for(int i = 0; i < FINGERS; i++){
      fingers[i] = new FingerFeedback(pins[i]);
    }
  }

  void sendData(){
    Serial.write(this->m1);
    Serial.write(this->m2);
    for(int i = 0; i < FINGERS; i++){
      BUFFER.data[i] = this->fingers[i]->val();  
    }
    Serial.write(BUFFER.buff, FINGERS*sizeof(int));
  }
};

Glove* glove;

void setup()
{
  Serial.begin(115200);              //  setup serial

  int pins[] = {14,15,16,17,18};
  glove = new Glove(pins);
  
}

void loop()
{
  
  glove->sendData();
}
