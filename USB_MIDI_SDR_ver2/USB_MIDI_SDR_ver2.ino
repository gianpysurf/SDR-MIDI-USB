// *********************************************************************************
// USB MIDI SDR V 2 Controller per SDR Console
// Arduino Leonardo
// by Gianpietro Cocco - IZ6222SWL
// 06/10/2022
//
// **********************************************************************************

// MIDI Library - Version: 5.0.2
#include <MIDI.h>
#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();

bool PrintSerialEnabled = false;
int debounce = 200;
int lastAction = 0;

// Encoder 1 -- TUNE X10/X100 *************************************************
int encoder1_Pin1 = 2;
int encoder1_Pin2 = 3;
int lastValue_Encoder1 = 0;

// Button 1 -- X10/X100**************************************************
int  Button1_Pin = 4;
bool Button1_Pressed = false;
int  lastValue_Button1 = HIGH;

// Encoder 2 --TUNE Fine/Norm *************************************************
int encoder2_Pin1 = 5;
int encoder2_Pin2 = 6;
int lastValue_Encoder2 = 0;

// Button 2 --TUNE Fine/Norm**************************************************
int Button2_Pin = 7;
int Button2_Pressed = false;
int lastValue_Button2 = HIGH;

// Encoder 3 -- Tune 1 MHz*************************************************
int encoder3_Pin1 = 8;
int encoder3_Pin2 = 9;
int lastValue_Encoder3 = 0;

// Encoder 4 --Filtro Higt/Low *************************************************
int encoder4_Pin1 = 10;
int encoder4_Pin2 = 11;
int lastValue_Encoder4 = 0;

// Button 4 --Filtro Higt/Low**************************************************
int Button4_Pin = 12;
int Button4_Pressed = false;
int lastValue_Button4 = HIGH;

// Encoder 5 --Mode *************************************************
int encoder5_Pin1 = 22;
int encoder5_Pin2 = 23;
int lastValue_Encoder5 = 0;

// Led 1 ENCODER1**************************************************
int Led1_Pin = 19;
int lastValue_Led1 = LOW;

// Led 2 ENCODER2**************************************************
int Led2_Pin = 20;
int lastValue_Led2 = LOW;

// Led 3 ENCODER4**************************************************
int Led3_Pin = 21;
int lastValue_Led3 = LOW;

// Pot 1 -- VOLUME **************************************************
int Pot1_Pin = A0;
int lastValue_Pot1 = 0;



void setup() {

  if (PrintSerialEnabled)
  {
    Serial.begin (9600);
    Serial.println("Start...");
    Serial.println("");
  }
  else
    MIDI.begin(MIDI_CHANNEL_OMNI);

  // Encoder 1 *************************************************
  pinMode(encoder1_Pin1, INPUT_PULLUP);
  pinMode(encoder1_Pin2, INPUT_PULLUP);

  // Button 1 **************************************************
  pinMode(Button1_Pin, INPUT_PULLUP);

  // Encoder 2 *************************************************
  pinMode(encoder2_Pin1, INPUT_PULLUP);
  pinMode(encoder2_Pin2, INPUT_PULLUP);

  // Button 2 **************************************************
  pinMode(Button2_Pin, INPUT_PULLUP);

  // Encoder 3 *************************************************
  pinMode(encoder3_Pin1, INPUT_PULLUP);
  pinMode(encoder3_Pin2, INPUT_PULLUP);

 // Encoder 4 *************************************************
  pinMode(encoder4_Pin1, INPUT_PULLUP);
  pinMode(encoder4_Pin2, INPUT_PULLUP);

  // Button 4 **************************************************
  pinMode(Button4_Pin, INPUT_PULLUP);

  // Encoder 5 *************************************************
  pinMode(encoder5_Pin1, INPUT_PULLUP);
  pinMode(encoder5_Pin2, INPUT_PULLUP);

  // Led 1 **************************************************
  pinMode(Led1_Pin, OUTPUT);

  // Led 2 **************************************************
  pinMode(Led2_Pin, OUTPUT);

  // Led 3 **************************************************
  pinMode(Led3_Pin, OUTPUT);

  setCurrentPotValue();
  Test();
}

void loop() {

  // Lettura Encoder1 ***************************************
  ManageEncoder1();
  // Lettura Button1 ***************************************
  ManageButton1();
  // Lettura Encoder2 ***************************************
  ManageEncoder2();
  // Lettura Button2 ***************************************
  ManageButton2();
  // Lettura Encoder3 ***************************************
  ManageEncoder3();
 // Lettura Encoder4 ***************************************
  ManageEncoder4();
  // Lettura Button4 ***************************************
  ManageButton4();
  // Lettura Encoder5 ***************************************
  ManageEncoder5();
  // Lettura Pot1 ***************************************
  ManagePot1();
  
} // End Void

int ReadEncoder1()
{
  int valore = 0;
  int n = digitalRead(encoder1_Pin1);
  if ((lastValue_Encoder1 == HIGH) && (n == LOW))
  {
    if (digitalRead(encoder1_Pin2))
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Encoder1 = n;

  return valore;

}

int ReadButton1()
{
  int valore = 0;
  int n = digitalRead(Button1_Pin);
  if (lastValue_Button1 != n)
  {
    if (n == LOW)
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Button1 = n;

  return valore;
}

int ReadEncoder2()
{
  int valore = 0;
  int n = digitalRead(encoder2_Pin1);
  if ((lastValue_Encoder2 == HIGH) && (n == LOW))
  {
    if (digitalRead(encoder2_Pin2))
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Encoder2 = n;

  return valore;
}

int ReadButton2()
{
  int valore = 0;
  int n = digitalRead(Button2_Pin);
  if (lastValue_Button2 != n)
  {
    if (n == LOW)
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Button2 = n;

  return valore;
}

int ReadEncoder3()
{
  int valore = 0;
  int n = digitalRead(encoder3_Pin1);
  if ((lastValue_Encoder3 == HIGH) && (n == LOW))
  {
    if (digitalRead(encoder3_Pin2))
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Encoder3 = n;

  return valore;

}

int ReadEncoder4()
{
  int valore = 0;
  int n = digitalRead(encoder4_Pin1);
  if ((lastValue_Encoder4 == HIGH) && (n == LOW))
  {
    if (digitalRead(encoder4_Pin2))
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Encoder4 = n;

  return valore;

}
int ReadButton4()
{
  int valore = 0;
  int n = digitalRead(Button4_Pin);
  if (lastValue_Button4 != n)
  {
    if (n == LOW)
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Button4 = n;

  return valore;
}

int ReadEncoder5()
{
  int valore = 0;
  int n = digitalRead(encoder5_Pin1);
  if ((lastValue_Encoder5 == HIGH) && (n == LOW))
  {
    if (digitalRead(encoder5_Pin2))
      valore = 1;
    else
      valore = -1;
  }
  else
    valore = 0;

  lastValue_Encoder5 = n;

  return valore;

}

int ReadPot1()
{
  int val = map(analogRead(Pot1_Pin), 0, 1023, 0, 127);
  if (val > 127) val = 127;
  if (val < 0) val = 0;
  return val; 
}

// Lettura Encoder1 ******************************************************************************************
void ManageEncoder1()
{

  int valore_Encoder1 = ReadEncoder1();
  if (valore_Encoder1 != 0)
  {
    if (PrintSerialEnabled)
    {
      Serial.print("Encoder1: ");
      Serial.println(valore_Encoder1);
    }
    int ch1 = 0;
    if (lastValue_Led1 == LOW)
      ch1 = 80;
    else
      ch1 = 81;

    if (valore_Encoder1 == 1)
      SendMidi(ch1, 65, 1);
    else
      SendMidi(ch1, 63, 1);
  }
}

// Lettura Button1 ******************************************************************************************
void ManageButton1()
{
  int valore_Button1 = ReadButton1();
  if (valore_Button1 == 1  && !Button1_Pressed && (millis() - lastAction) > debounce)
  {
    Button1_Pressed = true;
    if (lastValue_Led1 == HIGH)
    {
      lastValue_Led1 = LOW;
    }
    else
    {
      lastValue_Led1 = HIGH;
    }
    digitalWrite(Led1_Pin, lastValue_Led1);

    if (PrintSerialEnabled)
    {
      Serial.print("Button1: ");
      Serial.print(valore_Button1);
      Serial.print(" - ");
      Serial.println(lastValue_Led1);
    }
    lastAction = millis();
  }
  else
    Button1_Pressed = false;

  //delay(100);
}

// Lettura Encoder2 ******************************************************************************************
void ManageEncoder2()
{

  int valore_Encoder2 = ReadEncoder2();
  if (valore_Encoder2!=0)
  {
    if (PrintSerialEnabled)
    {
      Serial.print("Encoder2: ");
      Serial.println(valore_Encoder2);
    }
	  int ch1 = 0;
	  if (lastValue_Led2==LOW)
		  ch1 = 82;
	  else
		  ch1 = 83;
		
	  if (valore_Encoder2==1)
		  SendMidi(ch1, 65, 1);
	  else
		  SendMidi(ch1, 63, 1);
  }
}

// Lettura Button2 ******************************************************************************************
void ManageButton2()
{
  int valore_Button2 = ReadButton2();
  if (valore_Button2==1  && !Button2_Pressed && (millis() - lastAction) > debounce)
	{
		Button2_Pressed = true;
		if (lastValue_Led2==HIGH)
		{
		  lastValue_Led2=LOW;
		}
		else
		{
		  lastValue_Led2=HIGH;
		}
		digitalWrite(Led2_Pin, lastValue_Led2);
		
		if (PrintSerialEnabled)
		{
		  Serial.print("Button2: ");
		  Serial.print(valore_Button2);
		  Serial.print(" - ");
		  Serial.println(lastValue_Led2);
		}
		lastAction = millis();
  }
  else
    Button2_Pressed = false;
    
  //delay(100);
}


// Lettura Encoder3 ******************************************************************************************
void ManageEncoder3()
{

  int valore_Encoder3 = ReadEncoder3();
  if (valore_Encoder3 != 0)
  {
    if (PrintSerialEnabled)
    {
      Serial.print("Encoder3: ");
      Serial.println(valore_Encoder3);
    }
    int ch1 = 0;
			  ch1 = 92;

    if (valore_Encoder3 == 1)
      SendMidi(ch1, 65, 1);
    else
      SendMidi(ch1, 63, 1);
  }
}



// Lettura Encoder4 ******************************************************************************************
void ManageEncoder4()
{

  int valore_Encoder4 = ReadEncoder4();
  if (valore_Encoder4 != 0)
  {
    if (PrintSerialEnabled)
    {
      Serial.print("Encoder4: ");
      Serial.println(valore_Encoder4);
    }
    int ch1 = 0;
	  if (lastValue_Led3==LOW)
		  ch1 = 93;
	  else
		  ch1 = 94;
    

    if (valore_Encoder4 == 1)
      SendMidi(ch1, 65, 1);
    else
      SendMidi(ch1, 63, 1);
  }
}

// Lettura Button4 ******************************************************************************************

void ManageButton4()
{
  int valore_Button4 = ReadButton4();
  if (valore_Button4 == 1  && !Button4_Pressed && (millis() - lastAction) > debounce)
  {
    Button4_Pressed = true;
    if (lastValue_Led3 == HIGH)
    {
      lastValue_Led3 = LOW;
    }
    else
    {
      lastValue_Led3 = HIGH;
    }
    digitalWrite(Led3_Pin, lastValue_Led3);

    if (PrintSerialEnabled)
    {
      Serial.print("Button4: ");
      Serial.print(valore_Button4);
      Serial.print(" - ");
      Serial.println(lastValue_Led3);
    }
    lastAction = millis();
  }
  else
    Button4_Pressed = false;

  //delay(100);
}

// Lettura Encoder5 ******************************************************************************************
void ManageEncoder5()
{

  int valore_Encoder5 = ReadEncoder5();
  if (valore_Encoder5 != 0)
  {
    if (PrintSerialEnabled)
    {
      Serial.print("Encoder5: ");
      Serial.println(valore_Encoder5);
    }
    int ch1 = 0;
		  ch1 = 95;
    

    if (valore_Encoder5 == 1)
      SendMidi(ch1, 65, 1);
    else
      SendMidi(ch1, 63, 1);
  }
}


// Lettura Pot1 ******************************************************************************************
void ManagePot1()
{
  int valorePot1 = ReadPot1();
  
  if (valorePot1 != lastValue_Pot1)
  {
    lastValue_Pot1 = valorePot1;
    
    if (PrintSerialEnabled)
    {
        Serial.print("Pot1: ");
        Serial.println(valorePot1);
    }
    SendMidi(89, valorePot1, 1);
  }
}

// Legge e imposta il valore corrente del Pot1
void setCurrentPotValue()
{
  lastValue_Pot1 = ReadPot1();
 
}

void Test()
{
  digitalWrite(Led1_Pin, HIGH);
  delay(250);
  digitalWrite(Led1_Pin, LOW);
  delay(250);
 
  digitalWrite(Led2_Pin, HIGH);
  delay(250);
  digitalWrite(Led2_Pin, LOW);
  delay(250);

   digitalWrite(Led3_Pin, HIGH);
  delay(250);
  digitalWrite(Led3_Pin, LOW);
  delay(250);

  digitalWrite(Led1_Pin, HIGH);
  digitalWrite(Led2_Pin, HIGH);
  digitalWrite(Led3_Pin, HIGH);
  delay(250);
  digitalWrite(Led1_Pin, LOW);
  digitalWrite(Led2_Pin, LOW);
  digitalWrite(Led3_Pin, LOW);
  delay(250);
}

// Invia i MIDI_Change as dispositivo *****************************************************************************************************************************
void SendMidi(int p1, int p2, int p3)
{
  if (!PrintSerialEnabled)
  {
    MIDI.sendControlChange(p1, p2, p3);
  }
}