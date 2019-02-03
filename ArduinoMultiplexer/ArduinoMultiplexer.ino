
#define loopDelay 10

//val = 8 -> 0000001000
//Grafei tin timi val stin exodo (D9 - D0)
void WriteVal(unsigned int val){
  unsigned int temp = val;
  unsigned int musk = 1;
  
  for (int i=0; i<10; i++){
    digitalWrite(i,temp & musk);
    temp = temp >> 1;
  }
}

//Get the Number of the mux input D12 D11 D10
unsigned int GetInputNum(){
  unsigned int sum = 0;
  
  sum = digitalRead(12) * 4 + digitalRead(11) * 2 + 
    digitalRead(10);
    
  return sum;
}

//Output the value of the selected sensor
void Out(){ 
    WriteVal((unsigned int) analogRead(GetInputNum()));
}

void setup() {      

  //Output of the Multiplexer  
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);  
  
  //Input of the Multiplexer
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}


void loop() {
  Out();
  delay(loopDelay);
}
