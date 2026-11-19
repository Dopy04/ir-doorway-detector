# Compilación de los informes

Los documentos se han escrito en LaTeX. Los esquemas están integrados con `circuitikz` y `tikz`, sin depender de imágenes externas. Todo el texto y los esquemas están en negro sobre blanco.

Desde esta carpeta, con una instalación de LaTeX que tenga los paquetes usados en los archivos:

```bash
latexmk -pdf -interaction=nonstopmode -halt-on-error circuitos_y_calculos.tex
latexmk -pdf -interaction=nonstopmode -halt-on-error registro_de_avances.tex
latexmk -pdf -interaction=nonstopmode -halt-on-error informe_validacion_sensor_ir.tex
```

También se pueden abrir los archivos `.tex` por separado en Overleaf.

El informe recoge medidas iniciales del prototipo. No sustituye la validación final de la barrera infrarroja ni es todavía un diseño de PCB listo para fabricar.
