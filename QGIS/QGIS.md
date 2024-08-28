## Georeferencing

1. Raster > Georeferencer GDAL (activate via Plugin Manager)
2. open raster
3. select points and enter coordinates or choose from map
4. "start georeferencing"
5. select referencing algorithm and layer name

## Tricks & Workarounds

select multiple features from multiple layers:
```python
sql = '"Wertung"=2' #Adjust this
for layer in QgsProject.instance().mapLayers().values(): #For all layers added to the map
    processing.run("qgis:selectbyexpression", {'INPUT':layer,'EXPRESSION':sql,'METHOD':0}) #Select by query
```


## Plugins 

### DEMto3D

2021-10-10

(intstallable via QGIS Plugin Manager)

**Usage:**

Raster->DEMto3D:  
--> **Error**:

```
2021-10-10T11:23:08     WARNING    Traceback (most recent call last):
              File "/home/dunland/.local/share/QGIS/QGIS3/profiles/default/python/plugins/DEMto3D/DEMto3D.py", line 116, in run
              demto3d_dlg = DEMto3D_dialog.DEMto3DDialog(self.iface)
              File "/home/dunland/.local/share/QGIS/QGIS3/profiles/default/python/plugins/DEMto3D/DEMto3D_Dialog/DEMto3D_dialog.py", line 113, in __init__
              self.get_raster_properties()
              File "/home/dunland/.local/share/QGIS/QGIS3/profiles/default/python/plugins/DEMto3D/DEMto3D_Dialog/DEMto3D_dialog.py", line 373, in get_raster_properties
              self.cell_size = self.layer.rasterUnitsPerPixelX()
             AttributeError: 'NoneType' object has no attribute 'rasterUnitsPerPixelX'
```

## Scripting

- **Tutorials:** https://www.qgistutorials.com/en/index.html#python-scripting-pyqgis
- **QGIS Python API**: https://qgis.org/pyqgis/master/index.html
- Python API changes with QGIS 3: https://raw.githubusercontent.com/qgis/QGIS/master/doc/porting_processing.dox
- **Python API:** [Creating scripts and running them from the toolbox](https://docs.qgis.org/3.34/en/docs/user_manual/processing/console.html#creating-scripts-and-running-them-from-the-toolbox)

- Processing > Toolbox > Scripts > Create New Script from Template

**[[QGIS processing algorithms]]**:
``` python
for alg in QgsApplication.processingRegistry().algorithms():
        print(alg.id(), "->", alg.displayName())
```

**Get info on processing algorithms:**
1. QGIS > Plugins > Python-Console öffnen
2. `processing.algorithmHelp("native>mergevectorlayers")`

### Run custom script in console:

``` python
processing.run("script:processmapping", {
'INPUT_LAYERS': [
'/home/dav/Documents/2024-06-05_Vogelkartierung/Daten/bios 2024 Berensch Qfield Export/BV Tag Dg 1.gpkg',
'/home/dav/Documents/2024-06-05_Vogelkartierung/Daten/bios 2024 Berensch Qfield Export/BV Tag Dg 2.gpkg',
'/home/dav/Documents/2024-06-05_Vogelkartierung/Daten/bios 2024 Berensch Qfield Export/BV Tag Dg 3.gpkg',
'/home/dav/Documents/2024-06-05_Vogelkartierung/Daten/bios 2024 Berensch Qfield Export/BV Tag Dg 4.gpkg',
'/home/dav/Documents/2024-06-05_Vogelkartierung/Daten/bios 2024 Berensch Qfield Export/BV Tag Dg 5.gpkg'],
'OUTPUT_FOLDER': '/home/dav/Documents/2024-06-05_Vogelkartierung/Arten',
'EZR_TABLE': '/home/dav/Documents/2024-06-05_Vogelkartierung/Erfassungszeiträume/EZR_alle.csv',
'FIELD' : 'Art',
'EZR_FIELD' : 'Art_kurz' # wie in Tabelle EZR_alle.csv
})
```

### Errors

>Feature could not be written to /home/dav/Documents/2024-06-05_Vogelkartierung/Arten/Art_St.gpkg: Feature creation error (OGR error: failed to execute insert : UNIQUE constraint failed: Art_St.fid)
Could not write feature into OUTPUT

**Solution**
``` python
# Reset feature IDs to ensure they are unique 
reproject_result = processing.run("native:reprojectlayer", { 
'INPUT': merged_layer, 'TARGET_CRS': merged_layer.crs().authid(), 'OUTPUT': 'memory:' 
}) 
# Get the reprojected (ID reset) layer 
reprojected_layer = reproject_result['OUTPUT']
```

### Map Layers

- **add layer to map:** `QgsProject.instance().addMapLayer(layer)`
- **Remove Layers from Map:** `QgsProject.instance().removeMapLayer(layer)`