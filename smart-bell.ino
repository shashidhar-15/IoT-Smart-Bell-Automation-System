#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include "RTClib.h"
// ===== WIFI AP =====
const char* ssid = "ABC";
const char* password = "123456789";
// ===== SERVER =====
WebServer server(80);
// ===== RTC =====
RTC_DS3231 rtc;
// ===== BUZZER =====
#define BUZZER 25
// ===== SCHEDULE =====
String setTime = "";
int setPattern = 0;
int lastMinute = -1;
// ===== HTML PAGE =====
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Smart Bell</title>
</head>
<body>
<h2>Set Bell Schedule</h2>
<form action="/set">
Time (HH:MM): <input type="text" name="time"><br><br>
Pattern:
<select name="pattern">
<option value="1">Single</option>
<option value="2">Double</option>
<option value="3">Long</option>
</select><br><br>
<input type="submit" value="Set">
</form>
</body>
</html>
)rawliteral";
// ===== BUZZER =====
void ringBell(int pattern) {
if (pattern == 1) {
digitalWrite(BUZZER, HIGH);
delay(300);
digitalWrite(BUZZER, LOW);
}
else if (pattern == 2) {
for (int i = 0; i < 2; i++) {
digitalWrite(BUZZER, HIGH);
delay(200);
digitalWrite(BUZZER, LOW);
delay(200);
}
}
else if (pattern == 3) {
digitalWrite(BUZZER, HIGH);
delay(800);
digitalWrite(BUZZER, LOW);
}
}
// ===== ROUTES =====
void handleRoot() {
server.send(200, "text/html", webpage);
}
void handleSet() {
setTime = server.arg("time");
setPattern = server.arg("pattern").toInt();
Serial.println("New Schedule Set:");
Serial.println(setTime);
server.send(200, "text/html", "<h3>Schedule Saved!</h3><a href='/'>Go Back</a>");
}
// ===== SETUP =====
void setup() {
Serial.begin(115200);
pinMode(BUZZER, OUTPUT);
Wire.begin();
if (!rtc.begin()) {
Serial.println("RTC not found");
while (1);
}
// ===== SET TIME ONCE (UNCOMMENT FIRST TIME ONLY) =====
rtc.adjust(DateTime(F( DATE ), F( TIME )));
// ===== START AP =====
WiFi.softAP(ssid, password);
Serial.println("AP Started");
Serial.print("IP Address: ");
Serial.println(WiFi.softAPIP());
// ===== SERVER ROUTES =====
server.on("/", handleRoot);
server.on("/set", handleSet);
server.begin();
}
// ===== LOOP =====
void loop() {
server.handleClient();
DateTime now = rtc.now();
char currentTime[6];
sprintf(currentTime, "%02d:%02d", now.hour(), now.minute());
Serial.println(currentTime);
if (setTime != "" && setTime == String(currentTime)) {
if (now.minute() != lastMinute) {
Serial.println("Bell Triggered!");
ringBell(setPattern);
lastMinute = now.minute();
}
}
delay(1000);
}