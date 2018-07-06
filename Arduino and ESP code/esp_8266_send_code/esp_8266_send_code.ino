#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server;

char* ssid = "mapping";              //enter the wifi network id
char* password = "mapping1234";          // enter the wifi network password
char f='1';
char b='2';
char l='3';
char r='4';
char s='5';
char a='6';
char c='7';

void setup() {
  
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println(WiFi.localIP());
  server.on("/forward", on1);
  server.on("/backward", on2);
  server.on("/left", on3);
  server.on("/right", off1);
  server.on("/stop", off2);
  server.on("/start",start);
  server.on("/end",end1);
  server.begin();

}

void loop() {
  server.handleClient();
}
void on1() {
  Serial.print(f);
   server.send(200, "text/plain", "moving forward");
}
void on2() {
  Serial.print(b);
   server.send(200, "text/plain", "moving backward");
}
void on3() {
  Serial.print(l);
   server.send(200, "text/plain", "moving left");
}
void off1() {
  Serial.print(r);
   server.send(200, "text/plain", "moving right");
}
void off2() {
  Serial.print(s);
   server.send(200, "text/plain", "stopping");
}
void start(){
  Serial.print(a);
  server.send(200, "text/plain", "starting");
}
void end1(){
Serial.print(c);
server.send(200, "text/plain", "ending");
}
