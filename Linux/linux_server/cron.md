(daemon to execute scheduled commands)

`crontab -e`

dann ganz unten:
@reboot /home/nf/run.sh

(ganzen Pfad angeben ist wichtig!)
___________________
run.sh:
``` bash
#!/bin/sh

echo "hi"
```

___________________

gucken ob an ist:
`sudo systemctl status cron.service`

anmachen:
`sudo systemctl enable cron.service`
