# Sistema de Monitoramento com ESP32 e MQTT

Este projeto é um sistema de monitoramento e acionamento automático baseado em IoT, utilizando ESP32, sensor de temperatura e umidade DHT22, módulo relé e protocolo MQTT. Ele simula uma automação que aciona um atuador (relé) com base na temperatura lida, publicando os dados em um broker MQTT.

## Objetivo

Demonstrar um sistema funcional que:
- Lê temperatura e umidade em tempo real com sensor DHT22;
- Publica os dados via protocolo MQTT para um broker público;
- Aciona um relé automaticamente quando a temperatura ultrapassa 26°C.

## Componentes Utilizados

- ESP32 Dev Module
- Sensor DHT22
- Módulo Relé 1 canal
- LED (simulando um atuador, como uma bomba ou ventilador)
- Protoboard virtual no simulador Wokwi

## Simulação Online

Você pode visualizar e testar o projeto no simulador Wokwi:
[Acessar Projeto Wokwi](https://wokwi.com/projects/401183893347235841)

## Comunicação MQTT

- **Broker:** test.mosquitto.org
- **Porta:** 1883 (sem TLS)
- **Tópicos:**
  - `misandro/temperature` → Publica a temperatura em °C
  - `misandro/humidity` → Publica a umidade relativa do ar
  - `misandro/relay` → Publica o estado do relé ("ON" ou "OFF")

##  Funcionamento

1. O ESP32 conecta-se à rede Wi-Fi Wokwi.
2. Lê os dados do DHT22.
3. Publica os dados nos tópicos MQTT.
4. Se a temperatura for maior que 26°C, o relé é ativado (LED acende).
5. Todo o processo se repete a cada 10 segundos.

##  Código Fonte

O código está no arquivo `main.ino`, usando as bibliotecas:
- `WiFi.h`
- `PubSubClient.h`
- `DHT.h`

##  Fluxograma de Funcionamento

[Início]
↓
[Ler sensor DHT22]
↓
[Conectar ao Wi-Fi]
↓
[Conectar ao broker MQTT]
↓
[Se temperatura > 26°C?]
→ Sim → [Liga relé]
→ Não → [Desliga relé]
↓
[Publica dados MQTT]
↓
[Delay 10 segundos]
↓
[Reinicia ciclo]


##  Vídeo Demonstrativo

Assista ao vídeo do projeto com explicação completa:  
[![YouTube Video](https://img.youtube.com/vi/KsDPerIBySY/0.jpg)](https://www.youtube.com/watch?v=KsDPerIBySY)

## Organização do Projeto

- `main.ino`: código principal do ESP32
- `README.md`: este arquivo com descrição geral
- Diagrama de montagem no Wokwi
- Links para vídeo e artigo no PDF entregue

## Referências

- https://wokwi.com/
- https://mqtt.org/
- [Biblioteca DHT](https://github.com/adafruit/DHT-sensor-library)
- [Biblioteca PubSubClient](https://pubsubclient.knolleary.net/)

## ✍️ Autoria

Beatriz Paschoal, Julia Pacheco Moreira
Universidade Presbiteriana Mackenzie – 2025
