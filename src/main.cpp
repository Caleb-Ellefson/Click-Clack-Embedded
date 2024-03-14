
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include <motor_functions.h>

// initialize the stepper library
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

// ---------------------Wifi Config ---------------------
//CXNK0081AFFD
//Mac Miller
const char* ssid = "CXNK0081AFFD";
const char* password = "Mac Miller";
const char* serverName = "http://192.168.1.33:5100/api";

//"http://192.168.1.33:5100/api"
//---------------------------------------------------------------
//miliseconds 
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

bool toggleSwitch = false;
String switchStatus;


void setup() {
  WiFi.begin(ssid, password);
  //Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print('.');
  }
  Serial.begin(9600);
  stepper_begin(5000, 4500, 500);
  Serial.println("");
  Serial.print("Connected to Wifi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Your timer is set to: ");
  Serial.print(timerDelay);
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // ACTUAL GET REQUEST
  http.begin(client, serverName);
  int httpResponseCode = http.GET();
  String payload = "{}"; 
  
  if (httpResponseCode > 0) {
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    //Serial.print("Error code: ");
    //Serial.println(httpResponseCode);
  }
  // Free mem
  http.end();
  return payload;
}

void loop() {

  if ((millis() - lastTime) > timerDelay) {
    if(WiFi.status()== WL_CONNECTED){
      //CALL GET REQUEST
      switchStatus = httpGETRequest(serverName);
      //Serial.println("Response received:");
      JSONVar myObject = JSON.parse(switchStatus);
  
      // JSON.typeof(jsonVar) can be used to get the type of the var -- PARSES DATA FROM HTTP GET
      if (JSON.typeof(myObject) == "undefined") {
        //Serial.println("Parsing input failed!");
        return;
      }
      //Serial.print("JSON object = ");
      //Serial.println(myObject);
      lastTime = millis();
     //TAKE JSON DATA AND BREAK UP INTO VARIABLES 
     JSONVar switch_status = myObject["data"];
     toggleSwitch = switch_status["isOn"];
     //Serial.print(toggleSwitch);
    }
  }


  
  Serial.println("---------------------------------------------------");
  Serial.print("Sensor: ");
  Serial.print(digitalRead(hall_sensor));
  Serial.println();
  Serial.print("Index: ");
  Serial.println(time_index);

  move_once();
  delay(3000);
}
