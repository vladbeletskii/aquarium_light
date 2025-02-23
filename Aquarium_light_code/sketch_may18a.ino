#include "Classes.h"                  //My OOP

#include <EncButton.h>                //Encoder
EncButton<EB_TICK, A0, A1, A2> enc;

#include "GyverPWM.h"                 // PWM

#include <Wire.h>                     //Clock
#include "RTClib.h"
RTC_DS3231 rtc;

#include <EEPROM.h>                   //EEPROM

#include "SSD1306Ascii.h"             //Display
#include "SSD1306AsciiAvrI2c.h"
SSD1306AsciiAvrI2c oled;


const unsigned char logo [] PROGMEM = {
  0x00, 0xfe, 0xfe, 0xfe, 0x0e, 0x42, 0x7a, 0x7a, 0x3a, 0x82, 0xfe, 0x7e, 0x1e, 0xde, 0xde, 0x1e, 
	0x1e, 0xfe, 0xfe, 0x9e, 0xde, 0xde, 0x1e, 0xfe, 0xfe, 0x1e, 0x9e, 0xde, 0xde, 0x1e, 0xfe, 0xfe, 
	0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0xfe, 0xfe, 0xfe, 0x9e, 0x02, 0x7e, 0x7e, 0x7e, 0x06, 0xe2, 0xfe, 
	0x1e, 0xfe, 0xfe, 0xfe, 0x1e, 0xfe, 0xfe, 0x9e, 0xde, 0xde, 0x1e, 0x1e, 0xfe, 0x7e, 0x1e, 0xde, 
	0xde, 0x1e, 0x1e, 0xfe, 0x7e, 0x1e, 0xde, 0xde, 0x1e, 0x3e, 0xfe, 0x3e, 0x1e, 0xde, 0xde, 0x1e, 
	0xbe, 0xfe, 0x3e, 0x82, 0xca, 0xc2, 0x16, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0xfe, 0x7e, 0x1e, 0xe6, 0x86, 0x3e, 0xfe, 0xfe, 0xfe, 0xfe, 
	0x06, 0xb2, 0x9a, 0x82, 0x3e, 0x7e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 
	0x00, 0x7f, 0x7f, 0x61, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x60, 0x6e, 0x6f, 0x67, 0x60, 
	0x7f, 0x7f, 0x67, 0x6f, 0x6e, 0x60, 0x78, 0x7f, 0x03, 0x60, 0x6f, 0x6f, 0x61, 0x78, 0x7f, 0x67, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x60, 0x7c, 0x7f, 0x60, 
	0x64, 0x6f, 0x6f, 0x60, 0x7e, 0x7f, 0x63, 0x69, 0x6c, 0x66, 0x77, 0x7f, 0x7f, 0x60, 0x6e, 0x6f, 
	0x67, 0x60, 0x7f, 0x0f, 0x40, 0x6e, 0x6f, 0x67, 0x70, 0x7f, 0x77, 0x60, 0x6c, 0x6c, 0x6c, 0x7c, 
	0x7f, 0x77, 0x60, 0x6f, 0x6f, 0x63, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0xff, 0xf0, 0xfd, 0xfd, 0xfd, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0xfb, 0x3b, 0x3b, 0xb9, 0xbd, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0x07, 0xf1, 0xfd, 0xfd, 0x3d, 0x01, 0xf9, 0x3f, 0x0f, 0xef, 0xef, 0x0f, 
	0x8f, 0xff, 0x3f, 0x8f, 0xef, 0xef, 0x0f, 0x8f, 0xff, 0x1f, 0x81, 0xe5, 0xe1, 0x01, 0xcf, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x1f, 0x81, 0xdd, 0xdd, 0x9d, 0x3d, 0xfd, 0xff, 
	0x1f, 0x6f, 0x6f, 0x6f, 0x0f, 0xff, 0xff, 0x7f, 0x1f, 0xcf, 0x6f, 0x0f, 0xff, 0x7f, 0x0f, 0x6f, 
	0x6f, 0x6f, 0x0f, 0xff, 0x7f, 0x0f, 0xff, 0xff, 0x3f, 0x0f, 0xff, 0xff, 0x1f, 0x0f, 0x3f, 0x9f, 
	0xcf, 0xef, 0xff, 0x1f, 0xcf, 0xff, 0xff, 0x0f, 0xef, 0xff, 0x0f, 0xcf, 0xfd, 0xfd, 0x0d, 0xef, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xc7, 0x11, 0x39, 0xbc, 0x9e, 0xc0, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x60, 0x3f, 0xb9, 0x98, 0xe3, 0xff, 0x7f, 0x1f, 0xcf, 0x03, 0xff, 0xff, 0x00, 
	0x00, 0x7f, 0x7f, 0x70, 0x7e, 0x7f, 0x7f, 0x7f, 0x78, 0x7f, 0x07, 0x60, 0x73, 0x77, 0x73, 0x78, 
	0x7f, 0x7f, 0x70, 0x73, 0x73, 0x73, 0x78, 0x7f, 0x7b, 0x70, 0x73, 0x73, 0x71, 0x7c, 0x7f, 0x73, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x73, 0x70, 0x77, 0x77, 0x73, 0x79, 0x7c, 0x7f, 0x78, 
	0x70, 0x76, 0x76, 0x76, 0x7f, 0x7f, 0x73, 0x78, 0x7f, 0x7f, 0x70, 0x7e, 0x7f, 0x78, 0x72, 0x76, 
	0x76, 0x76, 0x7f, 0x7f, 0x70, 0x72, 0x77, 0x73, 0x60, 0x77, 0x7f, 0x73, 0x78, 0x7e, 0x7c, 0x71, 
	0x7f, 0x7f, 0x7b, 0x70, 0x77, 0x77, 0x71, 0x78, 0x7f, 0x79, 0x70, 0x77, 0x77, 0x70, 0x7c, 0x7f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x79, 0x7c, 0x7c, 0x7c, 0x7e, 0x70, 0x7f, 0x7f, 0x00
};

byte r = 0; 
byte c = 0 ;
int a = 0;

bool EncRHFlag;
bool EncLHFlag;
bool EncRFlag;
bool EncLFlag;
bool EncClFlag;
bool EncHFlag;
bool Enc2CFlag;
bool ChEncFlag;
bool AwakeFlag;
bool IsInter;
bool SecFlag;

bool NeedClearFlag;
bool ClearSavedFlafg;
bool ChInTimeFlag;

bool OverflowNeededFlag;
float BrlMult;

bool ChTimeFlag;
bool ChFlag;

int CurH;
int CurM;
int CurS;
int MemS;

int EstBrl;
int8_t MenuCount;
int8_t MenuCountM;
int8_t BrlIndMode;
int NOWBRL[4];
int NOWWBRL[] {0,0,0,0};
int EnotherBrl[4];
int MemCount;

Value ChNavPos1;
Value ChMenu;
Value Brl[8];
Value CurStrip;
Value WorkTimeSet;
Timer TR1;
Timer TR2;
Timer TR3;
Timer TRMin;
TimeVal T1(10,0,0);
TimeVal T2(20,0,0);
TimeVal RT(0,0,0);

void setup() {

TRMin.Reset();
ReadTimeEEPROM();

ChNavPos1.ValueParam(0, 3);
ChMenu.ValueParam(0, 2);
CurStrip.ValueParam(0, 4);
WorkTimeSet.ValueParam(0, 2);

for (int i = 0; i < 3; i++ ){Brl[i].ValueParam(0, 256);};
for (int i = 4; i < 7; i++ ){Brl[i].ValueParam(0, 256);};
Brl[3].ValueParam(0, 2);
Brl[7].ValueParam(0, 2);

oled.begin(&Adafruit128x32, 0x3C);
oled.setFont(Adafruit5x7);

Serial.begin (9600);
//Serial.println ("end setup");

pinMode(LED_BUILTIN, OUTPUT);

OverflowNeededFlag = 1;

pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

PWM_frequency(3, 40000, CORRECT_PWM);
PWM_frequency(9, 40000, CORRECT_PWM);
PWM_frequency(10,40000, CORRECT_PWM);

ReadBrlEEPROM ();

AwakeFlag = 1;


  for (byte b = 0; b < 4; b++) { // I'm expecting to occupy all the 4 rows of the display
    oled.setCursor (c,(r+b)); 
    for (byte i = 0; i < 128; i++) { // since I need to occupy all the 4 rows of the display, I divided the number of elements of the logo array (512) by 4. This is why I got 128.
      oled.ssd1306WriteRam(pgm_read_byte(&logo[a]));
      a++;
    }  
  }


delay(2500);

oled.clear();
}

void loop() {
  
  enc.tick();

  DateTime now = rtc.now();
  TR1.Get(now.second());
  TR2.Get(now.second());
  TR3.Get(now.second());
  TRMin.Get(now.second());

  CurH = now.hour();
  CurM = now.minute();
  CurS = now.second();//now.second();

  if (enc.leftH()) {EncRHFlag = 1; ChFlag = 1; IsInter = 1; TR2.Reset();};
  if (enc.rightH()) {EncLHFlag = 1; ChFlag = 1; IsInter = 1; TR2.Reset();};
  if (enc.left()) {EncRFlag = 1; ChFlag = 1; IsInter = 1; TR2.Reset();};
  if (enc.right()) {EncLFlag = 1; ChFlag = 1; IsInter = 1; TR2.Reset();};
  if (enc.click()) {EncClFlag = 1; IsInter = 1; TR2.Reset(); if (ChMenu.Count() == 1) ChFlag = 1;};
  if (enc.held()) {EncHFlag = 1; IsInter = 1; TR2.Reset();};
  if (enc.hasClicks(2)) {Enc2CFlag = 1; IsInter = 1; TR2.Reset();};

  MENUMGMT();
  
  if (MemS != CurS){MemS = CurS; SecFlag = 1;
   BrlMGMT();          //refreshes PWM every second
   OverflowIsNeeded(); //check the time for overflow
  };




}