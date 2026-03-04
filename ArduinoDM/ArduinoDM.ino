int Data[60];
int inByte = 0;
char buffer[40];
int index = 0;
int value = 0;
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);

  // Analog inputs
  pinMode(A0, INPUT); // BPM
  pinMode(A1, INPUT); // SWING
  pinMode(A2, INPUT); // TOTAL STEPS
  pinMode(A3, INPUT); // CH STEPS
  pinMode(A4, INPUT); // HITS
  pinMode(A5, INPUT); // OFFSET
  pinMode(A6, INPUT); // VOL / CUTOFF
  pinMode(A7, INPUT); // PAN / RESO
  pinMode(A8, INPUT); // SAMPLE / RANDOM

  // Digital inputs
pinMode(2, INPUT_PULLUP);   // BANK
pinMode(4, INPUT_PULLUP);   // FX SWITCH
pinMode(6, INPUT_PULLUP);   // ONOFF

pinMode(7, INPUT_PULLUP);   // ROTARY 1
pinMode(8, INPUT_PULLUP);  // ROTARY 2
pinMode(9, INPUT_PULLUP);  // ROTARY 3
pinMode(10, INPUT_PULLUP);  // ROTARY 4
pinMode(11, INPUT_PULLUP);  // ROTARY 5
pinMode(12, INPUT_PULLUP);  // ROTARY 6
}

void loop()
{
    index = 0;
  do
  {
    buffer[index] = Serial.read();
    if(buffer[index]!=-1) index = index + 1;
  }
  while(buffer[index-1]!=32);
  value = atoi(buffer);
  if (value == 100) {
    digitalWrite(5, 255);
  }
  if (value == 255) {
    digitalWrite(6, 255);
  }
  if (value == 0) {
    digitalWrite(5, 0);
    digitalWrite(6, 0);
  }
  
  Data[0] = !digitalRead(7);

  // Global controls (flyttade +1)
  Data[1] = map(analogRead(A0), 0, 1023, 60, 350); // BPM
  Data[2] = map(analogRead(A1), 0, 1023, 0, 100); // SWING
  Data[3] = map(analogRead(A2), 0, 1023, 1, 16); // TOTAL STEPS
  Data[5] = digitalRead(2); // BANK

  // ============================
  // ROTARY 1 (Pin 9)
  // ============================
  if (digitalRead(9) == HIGH)
  {
    Data[6] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[7] = map(analogRead(A4), 0, 1023, 0, Data[6]);
    int maxOffset = max(Data[7] - 1, 0);
	Data[8] = map(analogRead(A5), 0, 1023, 0, maxOffset);
    
    if (digitalRead(4) == HIGH)
    {
      Data[9]  = map(analogRead(A6), 0, 1023, 0, 2);
      Data[10] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[11] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[12] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[13] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[14] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // ROTARY 2 (Pin 10)
  // ============================
  if (digitalRead(10) == HIGH)
  {
    Data[15] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[16] = map(analogRead(A4), 0, 1023, 0, Data[15]);
    int maxOffset = max(Data[16] - 1, 0);
	Data[17] = map(analogRead(A5), 0, 1023, 0, maxOffset);


    if (digitalRead(4) == HIGH)
    {
      Data[18] = map(analogRead(A6), 0, 1023, 0, 2);
      Data[19] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[20] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[21] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[22] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[23] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // ROTARY 3 (Pin 11)
  // ============================
  if (digitalRead(11) == HIGH)
  {
    Data[24] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[25] = map(analogRead(A4), 0, 1023, 0, Data[24]);
    int maxOffset = max(Data[25] - 1, 0);
	Data[26] = map(analogRead(A5), 0, 1023, 0, maxOffset);


    if (digitalRead(4) == HIGH)
    {
      Data[27] = map(analogRead(A6), 0, 1023, 0, 2);
      Data[28] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[29] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[30] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[31] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[32] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // ROTARY 4 (Pin 12)
  // ============================
  if (digitalRead(12) == HIGH)
  {
    Data[33] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[34] = map(analogRead(A4), 0, 1023, 0, Data[33]);
    int maxOffset = max(Data[34] - 1, 0);
	Data[35] = map(analogRead(A5), 0, 1023, 0, maxOffset);


    if (digitalRead(4) == HIGH)
    {
      Data[36] = map(analogRead(A6), 0, 1023, 0, 2);
      Data[37] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[38] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[39] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[40] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[41] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // ROTARY 5 (Pin 13)
  // ============================
  if (digitalRead(13) == HIGH)
  {
    Data[42] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[43] = map(analogRead(A4), 0, 1023, 0, Data[42]);
    int maxOffset = max(Data[43] - 1, 0);
	Data[44] = map(analogRead(A5), 0, 1023, 0, maxOffset);


    if (digitalRead(4) == HIGH)
    {
      Data[45] = map(analogRead(A6), 0, 1023, 0, 2);
      Data[46] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[47] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[48] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[49] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[50] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // ROTARY 6 (Pin 14)
  // ============================
  if (digitalRead(14) == HIGH)
  {
    Data[51] = map(analogRead(A3), 0, 1023, 0, Data[3]);
    Data[52] = map(analogRead(A4), 0, 1023, 0, Data[51]);
    int maxOffset = max(Data[52] - 1, 0);
	Data[53] = map(analogRead(A5), 0, 1023, 0, maxOffset);


    if (digitalRead(4) == HIGH)
    {
      Data[54] = map(analogRead(A6), 0, 1023, 0, 2);
      Data[55] = map(analogRead(A7), 0, 1023, 0, 2);
      Data[56] = map(analogRead(A8), 0, 1023, 1, 3);
    }
    else
    {
      Data[57] = map(analogRead(A6), 0, 1023, 0, 15000);
      Data[58] = map(analogRead(A7), 0, 1023, 0, 4);
      Data[59] = map(analogRead(A8), 0, 1023, 0, 50);
    }
  }

  // ============================
  // Print all values
  // ============================
  for (int i = 0; i < 60; i++)
  {
    Serial.print(Data[i]);
    Serial.print(" ");
  }
  Serial.println("");

  delay(150);
}
