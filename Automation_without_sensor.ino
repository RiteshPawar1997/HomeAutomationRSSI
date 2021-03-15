/*
  

*/
// Necessary Library for this project
#include <ESP8266WiFi.h>

//Name of the wifi network whom we are supposed to track
const char* SSID = "Idea4G Smartwifi HUB MW40CJ_D8C1";


//   Return RSSI(Received Signal Strength Indicator) or 0 if target SSID not found
int32_t getRSSI(const char* target_ssid) 
{
  byte available_networks = WiFi.scanNetworks();

  for (int network = 0; network < available_networks; network++) 
  {
    if (WiFi.SSID(network).compareTo(target_ssid) == 0) 
    {     //stringOne.compareTo(stringTwo) < 0
      return WiFi.RSSI(network);
    }
  }
  return 0;
}

void setup() 
{
  Serial.begin(115200);
  pinMode(D0, OUTPUT); //  Initialize the relay pin as an output.
}

void loop() 
{
  int32_t rssi = getRSSI(SSID);


  // For debugging purpose only
  Serial.print("Signal strength: ");
  Serial.print(rssi);
  Serial.println("dBm");

  if (rssi > (-50) && rssi != 0) // if rssi is greater then -70 dbm or it's 0 dbm, then the light will turn ON
  {
    digitalWrite(D0, LOW);
    Serial.println("ON");
  }
  else // else, the light will be turned OFF.
  {
    digitalWrite(D0, HIGH);
    Serial.println("OFF");
  }
}
