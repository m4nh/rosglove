int analogPin = 14;     // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;           // variable to store the value read

struct FingerFeedback {
  int pin;
  FingerFeedback(int pin) {
    this->pin = pin;

  }
  int val() {
    return analogRead(this->pin);
  }
  void print(){
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(this->val());  
  }
};

FingerFeedback f1(14);
FingerFeedback f2(15);
FingerFeedback f3(16);
FingerFeedback f4(17);
FingerFeedback f5(18);
void setup()
{
  Serial.begin(115200);              //  setup serial

}

void loop()
{
  Serial.println("############");
  f1.print();
  f2.print();
  f3.print();
  f4.print();
  f5.print();
 


}
