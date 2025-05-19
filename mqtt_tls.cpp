#include WiFi.h
#include WiFiClientSecure.h
#include PubSubClient.h

 WiFi credentials
const char ssid = Nande Beka;
const char password = chin2004;

 MQTT broker details
const char mqtt_server = 192.168.93.5;   Your laptop's IPv4 address
const int mqtt_port = 8883;   Secure MQTT port

 CA Certificate (From your own Mosquitto setup)
const char ca_cert =
-----BEGIN CERTIFICATE-----n
MIIDCTCCAfGgAwIBAgIULDXXF+wXkeqSgOXuUse8tlKUwg0wDQYJKoZIhvcNAQELn
BQAwFDESMBAGA1UEAwwJTXlMb2NhbENBMB4XDTI1MDUxNzEzMzE1N1oXDTMwMDUxn
NjEzMzE1N1owFDESMBAGA1UEAwwJTXlMb2NhbENBMIIBIjANBgkqhkiG9w0BAQEFn
AAOCAQ8AMIIBCgKCAQEAsJjtvwNARg6UzctdQ+Rs7WzBjUcNDelzJhfU2GYRnTQCn
g0dI3i6xs2Tq2U1RQrfrDZZE6xJ9JgoB+QJfxvaVkxWV6ttrMlJuQrRaSC4kn
tI7wM7gYEfv4VnkTJIwJMwFFBkxkYvUrnOiJ5HONyGptAJwqei6w6smZnz5agVIn
yLibb0yymLQtR4xJfGz7CM8vAjcULe5xpwrETJaoIbOG0eDkWxZyqmyznBcymvGn
90fhsMGl9gcZzgC0dJAsWa0gVPi2QpJFHkxFdEJAXD3RXGr2ychsGoQpbEr5KMOn
uCMWzEP9oxPTVi3fegSwvEbxsaux9j5G7pZdGjeDQIDAQABo1MwUTAdBgNVHQ4En
FgQU2GX9DfwOlqZIN3Efj7i02hU4PIswHwYDVR0jBBgwFoAU2GX9DfwOlqZIN3Efn
j7i02hU4PIswDwYDVR0TAQHBAUwAwEBzANBgkqhkiG9w0BAQsFAAOCAQEAMOuln
um47nLZS3LauzdkPzNMniX6Ee16tKnavxzSwLIq4iZ7eL4z0+n2lx4G9frl96drn
bJivvZFA5TNatZnvYfL6vZ+nBrlIQnqqGSZF4dqFzn5NCoRIwxYhFBXwD5cDgGLn
kZbm4r5yRreUOW2sz0DxbaphEucGZEUagObwr0kf+rQ+6P5DE9IThnHxJwB526qn
IDwEc9cFjiwfcZ1UDkyj0P6iUb6S7xBbgmWlsIlnq5ftO54+NGkC+ZjdU1eUUn10n
hjXtRqqDMNRwLIcOdPNhbpbAnbBhmltUvu3Lon8Zt3M9+euwVAkvpLMYhLIH7nKn
G94wh9FcR8f75BWhxw==n
-----END CERTIFICATE-----n;

 Create secure WiFi and MQTT clients
WiFiClientSecure espClient;
PubSubClient client(espClient);

 Function to connect to WiFi
void setup_wifi() {
  Serial.println(Connecting to WiFi...);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(.);
  }
  Serial.println(nWiFi Connected!);
}

 Function to connect to MQTT broker securely
void reconnect() {
  while (!client.connected()) {
    Serial.println(Connecting to MQTT...);
    if (client.connect(ESP32Client)) {   No username or password
      Serial.println(Connected to MQTT Broker!);
    } else {
      Serial.print(Failed. Error Code );
      Serial.println(client.state());
      delay(5000);
    }
  }
}

 Setup Function
void setup() {
  Serial.begin(115200);
  setup_wifi();
  espClient.setCACert(ca_cert);   Load CA Certificate for TLS
  client.setServer(mqtt_server, mqtt_port);
}

 Loop Function
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (Serial.available()) {
    String message = Serial.readStringUntil('n');   Read input from Serial Monitor
    message.trim();   Remove trailing newline or spaces

    if (message.length()  0) {
      Serial.println(Sending  + message);
      client.publish(esp32input, message.c_str());   Publish to MQTT topic
    }
  }
}
