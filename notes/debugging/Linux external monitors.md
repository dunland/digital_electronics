- grober Unterschied zwischen AMD und Intel!

**identify GPU:**
`lscpi`
- **AMD**: Use the same `lspci` command to identify AMD GPUs. Look for lines mentioning "VGA compatible controller" or "3D controller."
- **Intel**: Intel integrated GPUs are often part of the CPU. You can check the output of `lspci` for integrated graphics controllers.

**show installed driver:**
``` bash
dunland@P14s:~$ sudo ubuntu-drivers devices
== /sys/devices/virtual/dmi/id ==
modalias : dmi:bvnLENOVO:bvrR1BET75W(1.44):bd06/13/2023:br1.44:efr1.44:svnLENOVO:pn20Y10002GE:pvrThinkPadP14sGen1:rvnLENOVO:rn20Y10002GE:rvrSDK0J40697WIN:cvnLENOVO:ct10:cvrNone:skuLENOVO_MT_20Y1_BU_Think_FM_ThinkPadP14sGen1:
vendor   : Lenovo
model    : product_version
driver   : oem-sutton.newell-adam-meta - third-party free
```


