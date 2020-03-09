#include<ArduinoWebsockets.h>

const char* ssid = "Black Shock";
const char* password = "blackshock";
const char* websockets_server_host = "192.168.0.100";
const uint16_t websockets_server_port = 8080;

using namespace websockets;

WebsocketsClient client;

const int led = 23;