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


    Serial.print("Topico ");
    Serial.println(topic);
    Serial.print("Mensagem ");
    Serial.println(msg);


    if (strcmp(topic, TOPICO_SUB_1) == 0){
      if (msg == "0"){
        digitalWrite(Rele1 , 0);
        MQTT.publish(TOPICO_PUB_1, 0, false, "0");
        Serial.println("Desligou Rele 1");
      }else{
        digitalWrite(Rele1 , 1);
        MQTT.publish(TOPICO_PUB_1, 0, false, "1");
        Serial.println("Ligou Rele 1");
      }
    }else if (strcmp(topic, TOPICO_SUB_2) == 0){
      if (msg == "0"){
        digitalWrite(Rele2 , 0);
        Serial.println("Desligou Rele 2");
        MQTT.publish(TOPICO_PUB_2, 0, false, "1");
      }else{
        digitalWrite(Rele2 , 1);
        Serial.println("Ligou Rele 2");
        MQTT.publish(TOPICO_PUB_2, 0, false, "1");
      }
    }

}
