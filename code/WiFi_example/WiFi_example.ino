/*
 * Programmer: Matas Noreika 26/05/22 17:15:31
 * Purpose:
 * Example program using ESP32 Arduino Core API WiFi library.
 * The following program will connect to a local network using the ssid and
 * password provided. The program will yield until a valid connection is
 * established. Upon successful connection it will send a HTTP POST request
 * using URL encoded query to bip.pollit.group/echo. The server will provide
 * on a get request the last POST message sent.
 * visible at: http://bip.pollit.group
*/

#include <WiFi.h> // built-in ESP Arduino core API for WiFi drivers
#define RESPONSE_TIMEOUT 5000 // 5 second timeout out for reading response

// ACCESS POINT(AP) CONFIGURATION
const char* ssid = "MGMD-ROUTER"; //enter the name of your WiFi SSID/name
const char* pass = "26069999"; //enter the password of your WiFi

// HOST SERVER CONGFIGURATION
// the domain of ther server we want to communicate with
const char* host = "192.168.1.192"; 
const int port = 3001; // standard HTTP port
const char* endpoint = "echo"; //the endpoint we will send a request at

// Function to handle reading response from server
void readResponse(NetworkClient* client){
  //retrieve current timer count (timout reference)
  unsigned long timeout = millis();

  //Handle unresponsive client
  while(client->available() == 0){
    //check if our response exceeded our RESPONSE_TIMEOUT
    if(millis() - timeout > RESPONSE_TIMEOUT){
      Serial.println("CLIENT TIMEOUT!");
      client->stop();
      return;
    }
  }

  //Handle the response packets
  //Will just print to serial monitor
  while(client->available()){
    String line = client->readStringUntil('\r');
    Serial.print(line);
  }

  Serial.printf("\nClosing Connection\n\n");

}

void setup() {
  //open Serial port via USB for debug (optional)
  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  //Attempt to connect to AP
  WiFi.begin(ssid, pass);

  //enter loop until connected
  //typically not good practise but will do for now
  while(WiFi.status() != WL_CONNECTED) {
    delay(500); // wait half a second
    Serial.print('.');
  }

  //print IP and status
  Serial.println("");
  Serial.println("Connected to AP.");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  //send a get request
  NetworkClient client;
  String footer = String(" HTTP/1.1\r\n") + "Host: " + String(host) + "\r\n" + "Connection: close\r\n\r\n";
  Serial.println("Connecting to host server...");
  //constantly wait until we connect to server
  //again its not great practise and should be handled without yielding
  while(!client.connect(host, port));
  Serial.println("Connected to server!");
  //write HTTP 1.1 GET request
  client.print("GET /echo" + footer);
  //read response
  readResponse(&client);

}

void loop() {

}
