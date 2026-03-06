int Data[60];
int inByte = 0;


void setup()
{
  Serial.begin(9600);
  analogReadResolution(10);
  // Analog inputs
  pinMode(14, INPUT); // BPM
  pinMode(15, INPUT); // SWING
  pinMode(16, INPUT); // TOTAL STEPS
  pinMode(17, INPUT); // CH STEPS
  pinMode(18, INPUT); // HITS
  pinMode(19, INPUT); // OFFSET
  pinMode(20, INPUT); // VOL / CUTOFF
  pinMode(21, INPUT); // PAN / RESO
  pinMode(22, INPUT); // SAMPLE / RANDOM
  pinMode(23, INPUT); // CHAOS

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

  Data[0] = !digitalRead(6);
  if (analogRead(23) > 200) {  
    Data[59] = map(analogRead(23), 0, 1023, -25, 100);
  } //CHAOS
  else {
    Data[59] = 0;
  }
  Data[1] = map(analogRead(14), 1023, 0, 60, 350); // BPM
  Data[2] = map(analogRead(15), 1023, 0, 0, 100); // SWING
  Data[3] = map(analogRead(16), 1023, 0, 1, 16); // TOTAL STEPS
  Data[4] = digitalRead(2); // BANK

  // ============================
  // ROTARY 1 (Pin 9)
  // ============================
  if (digitalRead(7) == LOW)
  {
    Data[5] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[6] = map(analogRead(18), 1023, 0, 0, Data[5]);
    int maxOffset = max(Data[6] - 1, 0);
	Data[7] = map(analogRead(19), 1023, 0, 0, maxOffset);
    
    if (digitalRead(4) != LOW)
    {
      Data[8]  = map(analogRead(20), 1023, 0, 0, 1000);
      Data[9] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[10] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[11] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[12] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[13] = map(analogRead(22), 1023, 0, 0, 50);
    }
  }

  // ============================
  // ROTARY 2 (Pin 10)
  // ============================
  if (digitalRead(8) == LOW)
  {
    Data[14] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[15] = map(analogRead(18), 1023, 0, 0, Data[14]);
    int maxOffset = max(Data[15] - 1, 0);
	Data[16] = map(analogRead(19), 1023, 0, 0, maxOffset);


    if (digitalRead(4) != LOW)
    {
      Data[17] = map(analogRead(20), 1023, 0, 0, 1000);
      Data[18] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[19] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[20] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[21] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[22] = map(analogRead(22), 1023, 0, 0, 50);
    }
  }

  // ============================
  // ROTARY 3 (Pin 11)
  // ============================
  if (digitalRead(9) == LOW)
  {
    Data[23] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[24] = map(analogRead(18), 1023, 0, 0, Data[23]);
    int maxOffset = max(Data[24] - 1, 0);
	Data[25] = map(analogRead(19), 1023, 0, 0, maxOffset);


    if (digitalRead(4) != LOW)
    {
      Data[26] = map(analogRead(20), 1023, 0, 0, 1000);
      Data[27] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[28] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[29] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[30] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[31] = map(analogRead(22), 1023, 0, 0, 50);
    }
  }

  // ============================
  // ROTARY 4 (Pin 12)
  // ============================
  if (digitalRead(10) == LOW)
  {
    Data[32] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[33] = map(analogRead(18), 1023, 0, 0, Data[32]);
    int maxOffset = max(Data[33] - 1, 0);
	Data[34] = map(analogRead(19), 1023, 0, 0, maxOffset);


    if (digitalRead(4) != LOW)
    {
      Data[35] = map(analogRead(20), 1023, 0, 0, 1000);
      Data[36] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[37] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[38] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[39] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[40] = map(analogRead(22), 1023, 0, 0, 50);
    }
  }

  // ============================
  // ROTARY 5 (Pin 13)
  // ============================
  if (digitalRead(11) == LOW)
  {
    Data[41] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[42] = map(analogRead(18), 1023, 0, 0, Data[41]);
    int maxOffset = max(Data[42] - 1, 0);
	Data[43] = map(analogRead(19), 1023, 0, 0, maxOffset);


    if (digitalRead(4) != LOW)
    {
      Data[44] = map(analogRead(20), 1023, 0, 0, 1000);
      Data[45] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[46] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[47] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[48] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[49] = map(analogRead(22), 1023, 0, 0, 50);
    }
  }

  // ============================
  // ROTARY 6 (Pin 14)
  // ============================
  if (digitalRead(12) == LOW)
  {
    Data[50] = map(analogRead(17), 1023, 0, 0, Data[3]);
    Data[51] = map(analogRead(18), 1023, 0, 0, Data[50]);
    int maxOffset = max(Data[51] - 1, 0);
	Data[52] = map(analogRead(19), 1023, 0, 0, maxOffset);


    if (digitalRead(4) != LOW)
    {
      Data[53] = map(analogRead(20), 1023, 0, 0, 1000);
      Data[54] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[55] = map(analogRead(22), 1023, 0, 1, 3);
    }
    else
    {
      Data[56] = map(analogRead(20), 1023, 0, 0, 15000);
      Data[57] = map(analogRead(21), 1023, 0, 0, 1000);
      Data[58] = map(analogRead(22), 1023, 0, 0, 50);
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

  delay(200);
}
