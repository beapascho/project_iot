# Sistema de Monitoramento de Temperatura e Umidade com ESP32 e MQTT

Este projeto consiste em um protótipo funcional de monitoramento ambiental utilizando um sensor DHT22 para temperatura e umidade, um módulo relé como atuador e comunicação com a internet via protocolo MQTT. Ele exemplifica uma aplicação básica de IoT (Internet das Coisas), sendo útil para ambientes que exigem controle climático automatizado.

---

## Componentes Utilizados

- ESP32 DevKit V1
- Sensor DHT22 (Temperatura e Umidade)
- Módulo Relé 5V
- LED (atuador visual)
- Resistor 220Ω
- Jumpers
- Simulador Wokwi (https://wokwi.com)

---

## Descrição do Funcionamento

O ESP32 realiza leituras periódicas dos dados do sensor DHT22. Se a **temperatura ultrapassar 26°C**, um **relé é acionado**, ligando um LED (atuador).

Além disso, os dados são **enviados via protocolo MQTT** para um broker público, permitindo monitoramento remoto.

### Regras de decisão:
- `Temperatura > 26°C` → ativa o relé.
- `Temperatura <= 26°C` → desativa o relé.

### Tópicos MQTT utilizados:
- `misandro/temperature`
- `misandro/humidity`
- `misandro/relay`

---

##  Como Rodar o Projeto

1. Acesse o simulador em [Wokwi](https://wokwi.com/projects).
2. Abra o arquivo `monitoramento_mqtt.ino` no ambiente de simulação.
3. O ESP32 se conecta ao Wi-Fi (rede "Wokwi-GUEST").
4. Os dados são lidos, exibidos no console serial e enviados via MQTT.
5. Um LED será acionado via relé caso a temperatura exceda 26°C.

---

## Broker MQTT Utilizado

- **Servidor:** `test.mosquitto.org`
- **Porta:** `1883`
- **Protocolo:** MQTT v3.1
- **Cliente:** ESP32Client (identificação no código)

---

## Referências

- MQTT. [http://mqtt.org](http://mqtt.org)
- Wokwi IoT Simulator. [https://wokwi.com](https://wokwi.com)
- Biblioteca PubSubClient para ESP32 MQTT
- Biblioteca DHT para leitura de sensores de umidade/temperatura
- ODS 13 – Ação contra a mudança global do clima

---

> Desenvolvido como parte do projeto final da disciplina de Sistemas Embarcados, com foco em aplicações de IoT e MQTT.
