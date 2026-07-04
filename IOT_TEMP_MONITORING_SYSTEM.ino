#include<WiFi.h>
#include"ThingSpeak.h"
#include"DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN ,DHTTYPE);


const char* ssid="YOUR_WIFI_SSID_HERE";
const char* password="YOUR_WIFI_PASSWORD_HERE";
WiFiClient client;

unsigned long myChannelNumber = 0000000;
const char* myWriteAPIKey="YOUR_THINGSPEAK_WRITE_KEY";

//Timer Varaibles
unsigned long lastTime=0;
unsigned long timerDelay=30000;


//variable to hold temperature reading
float temperatureC;
float Humidity;



void setup() {
  Serial.begin(9600);//initailize Serial
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);//initializze thingspeak
 dht.begin();
  }

void loop() {
  // put your main code here, to run repeatedly:
 if((millis()-lastTime)>timerDelay){


    if(WiFi.status()!=WL_CONNECTED){
      Serial.print("Attempting to  connect");
      while(WiFi.status()!=WL_CONNECTED){
        WiFi.begin(ssid,password);
        delay(5000);

      }
      Serial.println("\n Connected.");

    }

    delay(2000);
 
 // Reading temperature or humidity takes 250 miliseconds!
  //sensor radings may also be upto 2 seconds 'old'

  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);


  //check if any reads failed and exit early (to try again)
  if(isnan(h)||isnan(t)||isnan(f))
  {
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }
  else
  {
    ThingSpeak.setField(1,h);
    ThingSpeak.setField(2,t);
    int x=ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
    if(x==200){
      Serial.println("channel updated successful");

    }

    else{
      Serial.println("problem updating channel .Http error code"+String(x));

    }

    lastTime=millis();
  }
    Serial.print(F("Humidity:"));
    Serial.print(h);
    Serial.print(F("% Temperature: "));
    Serial.print(t);
    Serial.print(F("Degree celsious"));
    Serial.print(f);
    Serial.println(F("F"));
  



}


}
