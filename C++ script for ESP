#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ESP als Access Point konfigurieren
const char* ap_ssid = "GeocacheESP";
const char* ap_password = "12345678"; // mindestens 8 Zeichen

ESP8266WebServer server(80);

// HTML lokal auf dem ESP
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Geocache Neuötting</title>
</head>
<body>
  <h1>Geocache Neuötting</h1>
  <form id="myForm">
    <label>Frage 1:</label><br>
    <input type="text" id="q1"><br>
    <label>Frage 2:</label><br>
    <input type="text" id="q2"><br>
    <label>Frage 3:</label><br>
    <input type="text" id="q3"><br>
    <button type="button" onclick="checkAnswers()">Absenden</button>
  </form>
  <p id="result"></p>

  <script>
    function checkAnswers() {
      let score = 0;
      if(document.getElementById('q1').value == 'antwort1') score++;
      if(document.getElementById('q2').value == 'antwort2') score++;
      if(document.getElementById('q3').value == 'antwort3') score++;
      if(score == 3) {
        document.getElementById('result').innerHTML = "Alle Antworten richtig!";
      } else {
        document.getElementById('result').innerHTML = "Nicht alles richtig, nochmal versuchen.";
      }
    }
  </script>
</body>
</html>
)rawliteral";

// Root Request
void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

void setup() {
  Serial.begin(115200);

  // ESP als Access Point starten
  WiFi.softAP(ap_ssid, ap_password);
  Serial.print("Access Point gestartet! IP-Adresse: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP Server gestartet");
}

void loop() {
  server.handleClient();
}
