- [public ssh key erstellt](https://www.strato.de/faq/server/ssh-keys-erstellen-um-sich-an-ihrem-strato-vps-vds-linux-anzumelden/) via `ssh-keygen` -> `/home/dav/.ssh/id_rsa.pub`
- ![[LinuxServerEinrichtung.png]]

## ssh-Vebrindung zum Server herstellen

- `ssh davidunland.de@ssh.strato.de`
- `ssh -i ~/.ssh/id_rsa root@82.165.34.144`
	- > connection timed out

`ssh -v root@82.165.34.144`

> `/etc/ssh/ssh_config.d/*.conf` matched no files

- `service ssh status` = `systemctl status ssh` zeigt ssh status (sollte **active** sein, sonst: ...)
- `systemctl enable --now ssh` **startet den ssh-service**
- `ufw allow ssh` configure firewall to allow ssh

!! **Firewall von strato musste ausgeschaltet werden.** !!

`ufw enable` *Firewall is active and enabled on system startup*

### ssh config file

example for `~/.ssh/config`:

``` bash
Host targaryen
    HostName 192.168.1.10
    User daenerys
    Port 7654
    IdentityFile ~/.ssh/targaryen.key

Host tyrell
    HostName 192.168.10.20

Host martell
    HostName 192.168.10.50

Host *ell
    user oberyn

Host * !martell
    LogLevel INFO

Host *
    User root
    Compression yes

```

## nginx installieren

`apt install nginx`
-> s. [[nginx]]

### mit domain verknüpfen

`/etc/nginx/sites-available/website` (selbst erstellt)

**config für IP:**

``` nano
 GNU nano 7.2                                       website *                                                 
server {  
       listen 80;  
       server_name 82.165.34.144;  
  
       root /home/proj/snakeJS_public_html;  
       location /.well-known/ {  
  
       }  
           
       location / {  
               proxy_pass http://localhost:3000;  
       }  
}
```

**config für domain:**

