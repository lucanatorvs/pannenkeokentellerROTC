#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

int x = 0;

/* todo:
 * file withe diferend ssid's and paswords to check
 * save the curent valu
 * add 7seg disp suport
 */

void connectToWifi() {
  Serial.print("Connecting to: "); //uncomment next line to show SSID name
  Serial.println(ssid);
  WiFi.mode(WIFI_STA); // SETS TO STATION MODE!
  WiFi.begin(ssid, password);
  Serial.println(" ");// print an empty line
  Serial.print("Attempting to connect: ");

  //try to connect for 10 seconds
  int i = 20;
  while (WiFi.status() != WL_CONNECTED && i >= 0) {
    digitalWrite(D3, HIGH);
    delay(500);
    digitalWrite(D3, LOW);
    delay(500);
    Serial.print(i);
    Serial.print(", ");
    i--;
  }
  Serial.println(" ");// print an empty line

  //print connection result
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected.");
    Serial.println(" ");// print an empty line
    Serial.print("NodeMCU ip address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed - check your credentials or connection");
    for (int i = 0; i < 20; i++) {
      Serial.println("Connection failed - check your credentials or connection");
      digitalWrite(D3, HIGH);
      delay (100);
      digitalWrite(D3, LOW);
      delay (100);
    }

  }
}

void setup() {
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, OUTPUT);
  Serial.begin(76800);
  while (!Serial) {
  }

  connectToWifi();

  Serial.println("going not to sleep!!!!");
}

void loop() {

  while (digitalRead(D2)) {
    while (digitalRead(D2)) {
      //Serial.println("not posting");
      delay(5);
    }
    delay(25);
  }




  Serial.println(digitalRead(D2));
  digitalWrite(D3, HIGH);

  x++;

  String httpaderes = "http://ip.or.server.aderes:port/hoeveelhijd/";
  String httpaderesmetvar = httpaderes + x;

  HTTPClient http;
  http.begin(httpaderesmetvar);
  //http.addHeader("Content-Type", "text/plain");
  /*int httpCode = */http.POST("pannnnnennnnkoekkken");
  //String payload = http.getString();
  //http.writeToStream(&Serial);
  http.end();

  digitalWrite(D3, HIGH);

  Serial.println("posted");

  while (!digitalRead(D2)) {
    while (!digitalRead(D2)) {
      //Serial.println("not posting");
      delay(5);
    }
    delay(25);
  }

  digitalWrite(D3, LOW);

}
