#include <ESP8266WiFi.h> // Importa a Biblioteca ESP8266WiFi
#include <PubSubClient.h> // Importa a Biblioteca PubSubClient


//****************************************
//  Dispositivo de Controle de Iluminação
//  Sub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Liga Lampada, Se (Comando == 0) Desliga Lampada
//  Pub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Respota "On", Se (Comando == 0) Respota "Off"
//****************************************


#define TOPICO_SUB_1  "/uema/carga/0101"
#define TOPICO_SUB_2  "/uema/carga/0102"
#define TOPICO_SUB_3  "/uema/carga/0103"
#define TOPICO_SUB_4  "/uema/carga/0104"


#define TOPICO_PUB_1  "/uema/res/0101"
#define TOPICO_PUB_2  "/uema/res/0102"
#define TOPICO_PUB_3  "/uema/res/0103"
#define TOPICO_PUB_4  "/uema/res/0104"


// MUDAR SENHA WIFI (SSID) PASSWORD

const char* SSID = "UEMA-COROATA";        // Nome da Minha rede Wifi
const char* PASSWORD  = "Uemacrt20";   // Senha da Minha rede Wifi



//IP E PORTA DO SERVIDOR MQTT
const char* BROKER_MQTT = "34.229.145.165";  // Endereço do Servidor Broker;
int BROKER_PORT = 1883;                         // Porta do Servidor

// USUARIO E SENHA DO SERVIDOR MQTT

const char* User_MQTT = "autohome";             // Usuario MQTT
const char* Pass_MQTT = "comida05";             // Senha MQTT


// PINOS DO RELE
int Rele1 = 16;
int Rele2 = 14;
int Rele3 = 12;
int Rele4 = 13;

int Contagem = 0;

WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient

void mqtt_callback(char* topic, byte* payload, unsigned int length);

void setup() {
  // put your setup code here, to run once:
  InitPinos();    //Inicializar os Pinos
  InitSerial();   // Inicializar a comunicação serial
  initWiFi();     //Inicializar a comunicação wifi
  initMQTT();     //Inicializar a comunicação mqtt

}


void loop() {
  // put your main code here, to run repeatedly:
//func_Teste();
verificaConexaoWIFIMQTT();    //Verifica Conexão WIFI MQTT
MQTT.loop();
//delay(1000);
}
