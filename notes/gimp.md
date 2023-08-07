# GIMP

## Export Layers

Plugin "Export Layers" wird benötigt:

1. clone https://github.com/khalim19/gimp-plugin-export-layers
2. Dateien einrichten wie hier beschrieben: https://khalim19.github.io/gimp-plugin-export-layers/sections/Installation.html


Filters --> Python-Fu --> Console ... **nicht verfügbar...**

--> how to install Python-Fu?

- `pip3 install pgimp` ... **Error!**
- `pip install pgimp` ... **Error**

3. GIMP mit flatpak updaten: https://www.gimp.org/downloads/

``` bash
flatpak install https://flathub.org/repo/appstream/org.gimp.GIMP.flatpakref 
flatpak run org.gimp.GIMP//stable 
flatpak update 
reboot
```

jetzt gibt es sogar einen Dialog unter File --> Export Layers.. ✓


