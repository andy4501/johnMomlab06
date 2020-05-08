#include<Keypad.h>
#define NOTE_ 0
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define KEY_ROWS 4 // 按鍵模組的列數
#define KEY_COLS 4 // 按鍵模組的行數
const byte potPin = A0;
int val;
int led=11;
// 依照行、列排列的按鍵字元（二維陣列）
char keymap[KEY_ROWS][KEY_COLS] = {
{'F', 'B', '7', '3'}, {'E','A','6', '2'},
{'D', '9', '5', '1'}, {'C', '8', '4','0'}
};
char ch,index;
byte colPins[KEY_COLS] = {2,3,4,5}; // 按鍵模組，行 1~4 接腳。
byte rowPins[KEY_ROWS] = {6,7,8,9}; // 按鍵模組，列 1~4 接腳。
const byte Buzzer = 10;
int SoundLeng;
char song_tone;
const int rhythm=200;

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS,
KEY_COLS);
int notes4[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4};
float
song[]={1,1,2,1,3,1,1,1,1,1,2,1,3,1,1,1,3,1,4,1,5,1,0,1,3,1,4,1,5,1,0,1,5,0.5,6,0.5,5,0.5,
4,0.5,3,1,1,1,5,0.5,6,0.5,5,0.5,4,0.5,3,1,1,1,1,1,5,1,1,1,0,1,1,1,5,1,1,1,0,1,-1};
void setup(){
pinMode(Buzzer,OUTPUT);
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop(){
  val = analogRead(potPin);
  Serial.println(val);

  if (val <= 500)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
// 透過 Keypad 物件的 getKey()方法讀取按鍵的字元
char key = myKeypad.getKey();

if (key){ // 若有按鍵被按下…
Serial.println(key); // 顯示按鍵的字元
if(key >= '0' && key <= '7'){
tone (Buzzer,notes4[key-'0'],300);
}}
if (Serial.available()){
ch = Serial.read();
if( ch == 'S' || ch == 's'){
index = 0;
while(1){
song_tone = song[index];
index ++;
SoundLeng = song[index]*rhythm;
index++;
if(song[index] == -1){
break;
}
else if (song_tone == 0){
delay(SoundLeng*1.3);
}
else{
tone ( Buzzer,notes4[song_tone],SoundLeng);
delay(SoundLeng*1.3);
}
}
}
}}
