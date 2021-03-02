void initMQTT() 
{
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(mqtt_callback); 
}


void mqtt_callback(char* topic, byte* payload, unsigned int length){

  
  String msg;
  

        //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    } 

    if (msg == "1")
    {
       digitalWrite(Rele1, HIGH);
    }else if (msg == "2"){
      digitalWrite(Rele1, LOW);
    }else if (msg == "3"){
      digitalWrite(Rele2, HIGH);
    }else if (msg == "4"){
      digitalWrite(Rele2, LOW);
    }else if (msg == "restart"){
      ESP.reset();
    }

    Serial.print("Mensagem Recebida: ");
    Serial.println(msg);
}
