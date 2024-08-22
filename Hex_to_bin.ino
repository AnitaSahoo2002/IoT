int led=2;
String bin="";

void setup(){
  Serial.begin(9600);
  Serial.println("Enter A Hex Character (0-9, A-F)");
  pinMode(led,OUTPUT);
}

void loop(){
  if(Serial.available()>0){
    char hexChar=Serial.read();
    int hexValue=0;
    if(hexChar>='0'&&hexChar<='9'){
      hexValue=hexChar-'0';
    } else if(hexChar>='A'&&hexChar<='F'){
      hexValue=hexChar-'A'+10;
    }
    bin=""; 
    while(hexValue!=0){
      int d=hexValue%2;
      bin=String(d)+bin;
      hexValue = hexValue / 2;
    }
    while(bin.length()<4){
      bin="0"+bin;
    }
    Serial.print("Binary representation: ");
    Serial.println(bin);
    for(int i=0;i<bin.length();i++){
      if(bin.charAt(i)=='1'){
        digitalWrite(led,LOW);  
      } else {
        digitalWrite(led,HIGH); 
      }
      delay(2000); 
    }
    delay(2000); 
    digitalWrite(led,HIGH);
  }
}
