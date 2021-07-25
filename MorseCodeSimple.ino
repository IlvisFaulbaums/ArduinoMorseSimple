int led_pin=13;
int a = 0;
int i = 0;
String inputText = "";
char lettersSmall[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char lettersBig[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char numbers[] = {'0','1','2','3','4', '5', '6', '7','8','9'};
String lettersMorse[] = {"*-","-***","-*-*","-**","*","**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-","*--","-**-","-*--","--**"};
String numbersMorse[] = {"-----","*----","**---","***--","****-","*****","-****", "--***", "---**", "----*"};
void setup() {
pinMode(led_pin,OUTPUT);
Serial.begin(9600);
//Serial.println("Ievadi tekstu:");
}

void loop()

{
  if(Serial.available()){
    inputText = Serial.readStringUntil('\n');
    Serial.println(inputText);
    for (int j = 0; j < inputText.length(); j++) {
      for (int i = 0; i < 26; i++) {
        if(inputText.charAt(j)==lettersSmall[i]||inputText.charAt(j)==lettersBig[i]){
            Serial.println(lettersMorse[i]);
            convertToMorse(lettersMorse[i]);
            }
        }
        for (int n = 0; n < 9; n++){
                if(inputText.charAt(j)==numbers[n]){
          Serial.println(numbersMorse[n]);
          convertToMorse(numbersMorse[n]);
                }
        }
    }    
}


Serial.println("Ievadi tekstu:");
delay(2000);

}

void convertToMorse(String string) {
        for (int a = 0; a < string.length(); a++) {
            if(string.charAt(a)==('*')){
//                Serial.println("īss");  
                iss();              
            } else if(string.charAt(a)=='-'){
//                Serial.println("garš");
                garsh();
        }
    }        
}

void writeMorse(int d){
//  Serial.println(d);
  digitalWrite(led_pin,HIGH);
  delay(d);

  digitalWrite(led_pin,LOW);
  delay(d);
}

void iss(){
  writeMorse(150);
}

void garsh(){
  writeMorse(300);
}
