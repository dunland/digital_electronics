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

### mit dolphin ssh-Verbindung starten:
`fish://username@ipAddress`

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

## nginx

### nginx installation

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

## SSL einrichten

1. 
``` bash
openssl req -new -newkey rsa:2048 -nodes -out wandwurm.fun.csr -keyout wandwurm.fun.key

You are about to be asked to enter information that will be incorporated  
into your certificate request.  
What you are about to enter is what is called a Distinguished Name or a DN.  
There are quite a few fields but you can leave some blank  
For some fields there will be a default value,  
If you enter '.', the field will be left blank.  
-----  
Country Name (2 letter code) [AU]:DE  
State or Province Name (full name) [Some-State]:Bremen  
Locality Name (eg, city) []:Bremen  
Organization Name (eg, company) [Internet Widgits Pty Ltd]:David Unland Mediengestaltung  
Organizational Unit Name (eg, section) []:  
Common Name (e.g. server FQDN or YOUR name) []:wandwurm.fun  
Email Address []:email@davidunland.de  
  
Please enter the following 'extra' attributes  
to be sent with your certificate request  
A challenge password []:!Uglanmin2  
An optional company name []:David Unland Mediengestaltung
```

2. key bei strato hochladen
3. certificates herunterladen und kombinieren:
   `cat cert_wandwurm.fun.crt intermediate_wandwurm.fun.crt root_wandwurm.fun.crt > ca-fullchain.crt`
4. [nginx einrichten](https://nginx.org/en/docs/http/configuring_https_servers.html)
