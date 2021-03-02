void func_Teste(){
  Contagem ++;
  Serial.print("Contagem : ");
  Serial.println(Contagem);

 boolean statusRele = digitalRead(Rele1);
 digitalWrite(Rele1, !statusRele);
 digitalWrite(Rele2, statusRele);
 MQTT.publish(TOPICO_PUB, "Piscou", true);
}
