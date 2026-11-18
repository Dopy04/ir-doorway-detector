# Medidas registradas durante las pruebas iniciales

Montaje: ESP32-S3 N16R8, LED IR L-53F3C, BC337 y BPW40. Alimentación del circuito: 3,3 V. Los datos son medidas del prototipo en protoboard; no se ha ensayado todavía el sistema completo en la puerta.

## Driver del LED IR

| Comprobación | Medida |
|---|---:|
| GPIO4 con salida HIGH | aproximadamente 3,3 V |
| Colector de BC337 respecto a GND, HIGH fijo | 0,009 V |
| Caída en resistencia serie de 180 Ω | aproximadamente 2,16 V |
| Corriente calculada: 2,16 V / 180 Ω | 12 mA |

La corriente de 12 mA está calculada a partir de la caída de tensión medida. No es una lectura directa en serie del amperímetro.

## Receptor BPW40

| Condición | ADC (12 bits) |
|---|---:|
| Iluminación habitual de la habitación | 3940–3945 |
| Mano interpuesta en la zona del haz | 4057–4067 |
| Receptor totalmente tapado | 4095 |

Al principio la lectura se quedaba fija en 4095 por la polaridad invertida del fototransistor. Tras corregirla, el ADC respondió a la luz. Estos valores se obtuvieron antes de confirmar una orientación óptica correcta y no demuestran todavía una detección fiable del paso.

## Pruebas pendientes

- Alinear emisor y receptor; repetir con haz libre y bloqueado.
- Registrar ADC con emisor apagado y encendido, y calcular su diferencia.
- Comprobar otras condiciones de luz y varias distancias.
- Definir un criterio de detección y medir falsos avisos.

Ver [el informe de circuitos](../docs/circuitos_y_calculos.tex) y [el registro de avances](../docs/registro_de_avances.tex).
