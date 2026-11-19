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

## Validación óptica — 19/11/2026

Tras enfrentar correctamente el L-53F3C y el BPW40 se repitió la medida diferencial, tomando el valor medio de diez lecturas con el LED apagado y encendido:

\[
\Delta ADC = ADC_{\mathrm{sin\ IR}} - ADC_{\mathrm{con\ IR}}
\]

| Iluminación | Haz libre (\(\Delta ADC\)) | Haz bloqueado (\(\Delta ADC\)) | Margen dentro del ensayo |
|---|---:|---:|---:|
| Lámpara | 3378–3385 | 323–638 | 2740 |
| Luz ambiental doméstica | 3917–3924 | 391–604 | 3313 |
| Oscuridad | 3913–3916 | 319–739 | 3174 |

Las cifras son intervalos anotados durante el ensayo, no una estadística de varios días. La menor lectura libre registrada fue 3378 y la mayor bloqueada 739; el margen conservador al comparar todas las condiciones es por tanto \(3378-739=2639\) cuentas ADC.

Con iluminación ambiental, los valores brutos de la prueba fueron: `Sin IR = 4093–4095` y `Con IR = 171–177` con el haz libre; al bloquear el haz, `Con IR = 3491–3704`. En parte de las medidas el canal `Sin IR` alcanza el máximo de la escala (4095).

Se proponen umbrales con histéresis: bloquear si \(\Delta ADC<1500\), declarar libre si \(\Delta ADC>2500\), mantener el estado en medio. Estos umbrales **aún no están implementados en el firmware del repositorio**.

El código actual tarda aproximadamente 1,6 s por ciclo de medida (sin contar pequeños tiempos adicionales). Esto puede hacer que se pierdan interrupciones rápidas, de modo que todavía no se ha validado el paso real de personas.

## Pruebas pendientes

- Reducir el tiempo entre mediciones e implementar la detección por estados con histéresis.
- Registrar distancia, velocidad de paso, repeticiones y falsos disparos.
- Probar luz solar directa y funcionamiento continuo.
- Integrar avisos al móvil y diseñar la PCB.

Informes: [circuitos y cálculos](../docs/circuitos_y_calculos.tex), [registro de avances](../docs/registro_de_avances.tex) y [validación inicial del sensor](../docs/informe_validacion_sensor_ir.tex).
