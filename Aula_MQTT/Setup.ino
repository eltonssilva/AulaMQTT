void InitPinos(){
  pinMode(Rele1, OUTPUT);
  pinMode(Rele2, OUTPUT);
  digitalWrite(Rele1, LOW);
  digitalWrite(Rele2, LOW);
}


void InitSerial(){
  Serial.begin(115200);
}

void initWiFi(){
  delay(10);
  Serial.println("------Conexao WI-FI------");
  Serial.print("Conectando-se na rede: ");
  Serial.println(SSID);
  Serial.println("Aguarde");

  reconectWiFi();
}


void verificaConexaoWIFIMQTT(){
  reconectWiFi();
  reconnectMQTT(); // verifica conexão Mqtt
  
}

void reconectWiFi(){

  // Teste se ja esta conectado;

  if (WiFi.status() == WL_CONNECTED) return;

   WiFi.begin(SSID, PASSWORD);  // Conectar a rede Wifi

   while (WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
   }

   Serial.println();
   Serial.print("Conectado com sucesso na rede ");
   Serial.println(SSID);
   Serial.print("Meu IP: ");
   Serial.println(WiFi.localIP());
   
}

void reconnectMQTT(){

    //  String clientName = WiFi.macAddress();
      

  while(!MQTT.connected()){
    Serial.print("* Tentando se conectar ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);
    if (MQTT.connect("Elton123123", User_MQTT, Pass_MQTT)) 
        {
            Serial.println("Conectado com sucesso ao broker MQTT!");
            MQTT.subscribe(TOPICO_SUB_1); 
            MQTT.subscribe(TOPICO_SUB_2); 
            MQTT.subscribe(TOPICO_SUB_3); 
            MQTT.subscribe(TOPICO_SUB_4); 
        } 
   else
        {
            Serial.println("Falha ao reconectar no broker.");
            Serial.println("Havera nova tentatica de conexao em 2s");
            delay(2000);
        }
  }
}
