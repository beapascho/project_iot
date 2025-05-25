#Sistema de Monitoramento Hídrico com IoT e Arduino

Este projeto consiste em um protótipo funcional para monitoramento e controle de recursos hídricos, utilizando sensores de pH, turbidez e fluxo de água, além de um atuador (bomba) controlado automaticamente. A proposta está alinhada com o ODS 6 da ONU, que visa garantir água potável e saneamento para todos.

---

##Componentes Utilizados

- Arduino Uno R3
- Sensor de pH (simulado por potenciômetro)
- Sensor de Turbidez (simulado por potenciômetro)
- Sensor de Fluxo de água (digital)
- Bomba de água (simulada por LED)
- Display LCD 16x2 (sem módulo I2C)
- Termistor TMP (não utilizado no código atual)
- Protoboard
- Jumpers diversos
- Resistores e potenciômetros

---

##Descrição do Funcionamento

O Arduino realiza a leitura dos sensores analógicos de pH e turbidez e, com base nesses valores, decide se a bomba deve ser acionada. Um sensor de fluxo também é utilizado para detectar passagem de água.

As leituras são exibidas em tempo real no LCD 16x2 e também enviadas via Serial para depuração.

### Regras de decisão:
- `pH < 500`
- `Turbidez > 400`
- `Fluxo == HIGH`

Se todas as condições forem verdadeiras, o pino digital D8 ativa a bomba.

---

##Como Rodar o Projeto

1. Abra o código em `Codigo/monitoramento_hidrico.ino` na Arduino IDE.
2. Verifique se as bibliotecas padrão estão instaladas (`LiquidCrystal`).
3. Faça as conexões de acordo com o diagrama em `Diagramas/fritzing-esquema.png`.
4. Carregue o código no Arduino.
5. Use o monitor serial a 9600 bps para depuração.

---

##Estrutura do Repositório

