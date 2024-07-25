const int led=10;
const int BU1=2;
const int BU2=12;
const int BUZ=13;
char BYTE;

void setup() {
  
  pinMode(BU1,INPUT_PULLUP);
  pinMode(BU2,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pinMode(BUZ,OUTPUT);
  Serial.begin(9600);
  digitalWrite(led,LOW);
  
}

void loop() {
  
 if ((digitalRead(BU2)==HIGH)&& ( digitalRead(BU1)==HIGH ))
  {
   Serial.write('0');
   delay(500);
  }
 else
 {
     if (digitalRead(BU1)==LOW)
     {
       Serial.write('1');
       delay(500);
     } 
    
      if (digitalRead(BU2)==LOW)
     {
       Serial.write('2');
       delay(500);
     }  
 }  
 
   
   if (Serial.available()>0)
   {
     BYTE = Serial.read();  //lire un evenement de SDL
     
     if (BYTE=='1') //en cas de collision 
     {
       digitalWrite(led,HIGH); //allumer la led 
       tone(BUZ,400,500);
       delay(1000);
     
     }
     else 
     {
       digitalWrite(led,LOW);                                        
     }
   }
   else 
     {
       digitalWrite(led,LOW);                                        
     }
}
