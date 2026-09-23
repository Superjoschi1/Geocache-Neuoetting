#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ap_ssid = "Historisches Neuötting";
const char* ap_password = "Neuötting"; 

ESP8266WebServer server(80);

//html
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Quiz</title>
  <style>
    body {
      font-family: Arial;
      background: rgb(94, 94, 117);
      text-align: center;
      padding: 20px;
    }
    .box {
      background: white;
      padding: 20px;
      margin: 15px auto;
      border-radius: 10px;
      max-width: 400px;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
    }
    input {
      padding: 10px;
      margin-top: 10px;
      width: 80%;
      font-size: 16px;
    }
    button {
      padding: 10px 20px;
      margin-top: 15px;
      font-size: 16px;
      border: none;
      border-radius: 8px;
      background: #007BFF;
      color: white;
    }
    #result {
      font-size: 20px;
      margin-top: 20px;
    }
  </style>
</head>

<body>

<h1>Quiz</h1>

<div class="box">
 <p> Die Ursprünge von Alt- und neuötting reichen bis ins 8.-10Jh. zurück</p>
</div>

<div class="box">
  <p> 1. Die ursprünge des alten Öttings gehen auf das 8.-10.Jh zurück.
      Nach der Zerstörung im 10.Jh wurde Alt- und Neuötting bewusst getrennt aufgebaut.
      Dies Siedlung um Altötting konzetrierte sich auf die Wahlfahrt, während Neuötting als Handelsstadt aufgebaut wurde. </p>
</div>
<div class="box">
  <p>1. Mit was wurde in Neuötting gehandelt. </p>
  <input id="q1" placeholder="Antwort eingeben">
</div>
<div class="box">
  <p> Der Bau der Stadtpfarkirche St. Nikolaus wurde von 1410-1492 errichtet.
      Es habdelt sich um eine spätgothische Hallen Kirche.
  </p>
</div>


<div class="box">
  <p>2. Wie wird die Kirche noch genannt? </p>
  <input id="q2" placeholder="Antwort eingeben">
</div>
<div class="box">
  <p>Der Neuöttinger Bahnhof befinded sich im Ortsteil Eisenfelden und wurde 1871 in Betrieb genommen.
     von 1906 und 1930 war der Neuöttinger Bahnhof mit dem Altöttinger mit einem Verkehrsmittel.
  </p>
</div>

<div class="box">
  <p>3. Mit welchem Verkehrsmittel </p>
  <input id="q3" placeholder="Antwort eingeben">
</div>
<div class="box">
  <p>4. Neuötting entwickelte sich ab 13Jh zu einem wichigem Handelszentrum, das von den bayrischen herzögen gefördert wurde.</p>
</div>
<div class="box">
  <p>4. Wie hies das Herschergeschlecht</p>
  <input id="q4" placeholder="Antwort eingeben">
</div>
<div class="box">
  <p>5. Die Anfänge von Alt- und Neuötting im 8.-10.Jh waren gemeinsam. Wie wurde die Stadt früher auf Latein genannt?</p>
  <input id="q5" placeholder="Antwort eingeben">
</div>
<button onclick="checkAnswers()">Antworten prüfen</button>

<div id="result"></div>

<script>
function checkAnswers() {
  let score = 0;

  let a1 = document.getElementById("q1").value;
  let a2 = document.getElementById("q2").value;
  let a3 = document.getElementById("q3").value;
  let a4 = document.getElementById("q4").value;
  let a5 = document.getElementById("q5").value;

  if (a1 === "Salz") score++;
  if (a1 === "Getreide") score++;
  if (a2 === "Dom des Inntals") score++;
  if (a2 === "Dom") score++;
  if (a3 === "Dampfstrasenbahn") score++;
  if (a3 === "Dampfstraßenbahn") score++;
  if (a4 === "Wittelsbacher") score++;
  if (a4 === "Die Wittelbacher") score++;
  if (a5 === "Autingas") score++;
  if (a5 === "Oettinga") score++;
  if (score === 5) {
  document.getElementById("result").innerHTML =
    "Koordinaten: 123Xy kauf mir elektronik";
} else {
  document.getElementById("result").innerHTML =
    "Du hast " + score + " von 5 richtig!";
}
}
</script>

</body>
</html>
)rawliteral";


void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

void setup() {
  Serial.begin(115200);

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
