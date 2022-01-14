# QGIS

## Georeferencing

1. Raster > Georeferencer GDAL (activate via Plugin Manager)
2. open raster
3. select points and enter coordinates or choose from map
4. "start georeferencing"
5. select referencing algorithm and layer name

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