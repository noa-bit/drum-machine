import processing.serial.*;
import processing.net.*;

/*

1. Ta emot rå data från Arduino (BPM) genom serial
2. Skicka till servern
3. Ta emot rå data (väntar oss 3 värden) från server

*/

Serial myPort;
String serialLine;

String serverIP = "130.229.129.19"; // IP att koppla upp till
int serverPort = 5204;
Client clientNode;

float x; // Data att skickas
float rx = 0, ry = 0, rz = 0; // Data att tas emot

void setup() {
  String portName = Serial.list()[5];
  myPort = new Serial(this, portName, 9600);
  clientNode = new Client(this, serverIP, serverPort);
  println("Connecting to server " + serverIP + ":" + serverPort);
}

void draw() {
  if (clientNode == null || !clientNode.active()) {
    delay(1000);
    println("Trying to reconnect to server...");
    clientNode = new Client(this, serverIP, serverPort);
    return;
  }
  if (myPort.available() > 0) {
    serialLine = myPort.readStringUntil('\n');
    if (serialLine != null) {
      serialLine = serialLine.trim();
      String[] parts = serialLine.split(" ");
      if (parts.length == 60) {
        try {
          x = float(parts[0]);
          
          clientNode.write(x + "\n");
          
        } catch (Exception e) {
          println("Error parsing serial line: " + serialLine);
        }
      } else {
        println("Unexpected serial data: " + serialLine);
      }
    }
  }
}

void clientEvent(Client c) {
  String line = c.readStringUntil('\n');

  if (line != null) {
    line = trim(line);
    String[] parts = split(line, ' ');

    if (parts.length == 3) {
      try {
        rx = float(parts[0]);
        ry = float(parts[1]);
        rz = float(parts[2]);

        println("Received: X=" + rx + " Y=" + ry + " Z=" + rz);

      } catch (Exception e) {
        println("Receive parse error: " + line);
      }
    }
  }
}