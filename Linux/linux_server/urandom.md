11.06.2023:

# - BENUTZER:
    root passwort:

    benutzer leidi erstellt: adduser leidi
    passwort:

    root priviliges erteilt: usermod -aG sudo leidi

    Es wäre sicherer SSH mit Key einzurichten, anstatt ein PW zu benutzen


# - FIREWALL UWF:
##  Firewall UWF installiert:
    sudo apt install ufw

##  available applications anzeigen:
    ufw app list

##  SSH verbindung erlauben, damit man sich nächstes mal wieder verbinden kann:
    ufw allow OpenSSH

##  firewall anmachen:
    ufw enable

##  status abfragen:
    ufw status


# - curl installiert:
    sudo apt install curl
    - CURL: command line tool that enables data transfer over various network protocols.


# - GOLANG:
# -- Installation:
     curl -LO https://dl.google.com/go/go1.20.5.linux-amd64.tar.gz

###  verify the tarball:
     sha256sum go1.20.5.linux-amd64.tar.gz

###  extract download archive:
     sudo tar -xvf go1.20.5.linux-amd64.tar.gz -C /usr/local
    - (/usr/local/go wäre die offiziell von golang empfohlene location)

# -- creating go workspace:
###  two directories:
    - src: contains Go source files; source files are used by the Go compiler to create
   an executable binary file
    - bin: contains executables built and installed by the Go tools

###  create the directory structure for the Go workspace:
     mkdir -p $HOME/go/{bin,src}

###  $GOPATH zu ~/.profile hinzugefügt:
     export GOPATH=$HOME/go

###  /bin to PATH in ~/.profile hinzugefügt, sodass ein Go Programm von überall
###  kompiliert werden kann:
     export PATH=$PATH:$GOPATH/bin

###  /usr/local/go/bin zu $PATH in ~/.profile hizugefügt, damit alle Go tools
###  überall auf dem server zur verfügung stehen:
     export PATH=$PATH:$GOPATH/bin:/usr/local/go/bin


# - NGINX:
## -- Installation:
      sudo apt update
      sudo apt install nginx

## -- einrichten:
      sudo ufw app list
### - allow traffic on port 80:
      sudo ufw allow 'Nginx HTTP'
      sudo ufw status

## -- checking web server:
### - systemctl status nginx
### - IP des servers herausfinden:
      ip a
   oder
      curl -4 icanhazip.com
### - ip im browser eingeben und man kriegt die Nginx landing page

## -- Managing Nginx:
### - stop the web server:
      sudo systemctl stop nginx
### - start the webserver when its stopped:
      sudo systemctl start nginx
### - webserver stoppen und wieder starten:
      sudo systemctl restart nginx
### - reload Nginx ohne restart (z.B. nach configuration changes):
      sudo systemctl reload nginx
### - wenn nginx nicht automatisch nach serverstart angehen soll:
      sudo systemctl disable nginx
### - wenn nginx starten soll, sobald der server hochgefahren wird:
      sudo systemctl enable nginx

## -- important directories and files:
### - /var/www/html: the web content (default: nginx landing page)

### - /etc/nginx: Nginx config dirextory
### - /etc/nginx/nginx.conf: main Nginx config file
### - /etc/nginx/sites-available/: the dirextory where per.site server blocks can be stored;
###    all server block config is don in this directory and then enabled by linking to the
###    sites-enabled directory
### - /etc/nginx/sites-enabled/: the directory where enabled per-site server blocks are
###   stored;
###   these are created by linking to config files found in the sites-available directory
### - /etc/nginx/snippets: the directory contains config fragments that can be included
###   elsewhre in the Nginx config

### - /var/log/nginx/access.log: every request the web server is recorded in the log file
### - /var/log/nginx/error.log: any Nginx errors will be recorded in this log


# - GO WEB APPLICATION BAUEN:
## -- create a sample go web application:
      mkdir $GOPATH/meine-go-app
      cd $GOPATH/meine-go-app
      vim main.go
   hier go code einfügen
      go build main.go

--------------------statt systemd unit file geht es auch mit TMUX!----------------------
## -- create a systemd unit file to keep the application running in the background even when
##    a user logs out of the server:
### - create a new file in /lib/systemd/system named meinegoapp.service:
      sudo vim /lib/systemd/system/meinegoapp.service
   mit folgedem Inhalt:
        [Unit]
        Description=meinegoapp

        [Service]
        Type=simple
        Restart=always
        RestartSec=5s
        ExecStart=/home/leidi/go/meine-go-app/main

        [Install]
        WantedBy=multi-user.target
### - start meinegoapp:
      sudo service meinegoapp start
      status überprüfen:
      sudo service meinegoapp status
-----------------------------------------------------------------------------------------


# - SETTING UP A REVERSE PROXY WITH NGINX: create an Nginx server block and set up an Nginx
#   reverse proxy to expose the application to the internet
## -- change the working directory to the Nginx sites-available directory:
      cd /etc/nginx/sites-available
   create a new file with the name of the domain:
      sudo vim urandom.digital
   mit folgendem Inhalt:
        server {
            server_name urandom.digital www.urandom.digital;

            location / {
                proxy_pass http://localhost:9990;
            }
         }
## -- create a symlink of this Nginx config in the sites-enabled folder:
      sudo ln -s /etc/nginx/sites-available/urandom.digital /etc/nginx/sites-enabled/urandom.digital
   reload the Nginx configurations:
      sudo nginx -s reload

======================================================================================
# - SSH key: sodass man kein PW braucht um auf den Server zu kommen
    ssh-keygen
    ssh-copy-id leidi@urandom.digital
   dann ist es schon fertig, aber so lange man den Passwortzugang für SSH nicht abschaltet, könnten Angreifer immernoch brute-forcen


# - GIT:
    sudo apt install git
    git config --global user.name "Leidenfrostie"
    git config --global user.email "naturfleisch@web.de"
    git config -l
=---mit tokens ist scheiße, weil man dann bei jedem push ein token braucht------------
=---also lieber mit key regeln--------------------------------------------------------
   token auf github erstellen
   stats repo geklont:
    git clone https://github.com/Leidenfrostie/stats.git
   name: Leidenfrostie
   passwort: erstelltes token
-------------------------------------------------------------------------------------=
   ssh schlüssel mit github verbinden:
## - gucken, ob schon einer auf dem PC vorhanden ist:
     ls -al ~/.ssh
## - schlüssel generieren:
     ssh-keygen -t ed25519 -C "email_von_github_login"
     eval "$(ssh-agent -s)"
     ssh-add ~/.ssh/id_ed25519
## - schlüssel anzeigen:
     cat ~/.ssh/id_ed25519.pub
     kopieren und beim github account hinzufügen


# - MATPLOTLIB:
    sudo apt install python3-matplotlib


# - TMUX:
    sudo apt install tmux
    tmux new -s stats
    go run main.go
    Ctrl+b d

~~~~~~~~~das hier klappt noch nicht~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# - SSL:
## - prüfen ob openssl installiert ist:
     command -v openssl
   ansonsten installieren
## - CSR erstellen:
     openssl req -new -newkey rsa:2048 -nodes -out urandom.digital.csr -keyout urandom.digital.key
   Common name: urandom.digital
## - CSR anzeigen und kopieren und bei strato eingeben:
     cat urandom.digital.csr
## - speichere Zertifikat in ca.crt
   speichere Intermediate-Zertifikat in ca-int.crt
   speichere Root-CA-Zertifikat in ca-root.crt
## - erstelle fullchain:
     cat ca.crt ca-int.crt ca-root.crt >ca-fullchain.crt
## - erstelle ssl systemgruppe:
     sudo groupadd -r sslcert
   gib nginx Rechte:
     sudo usermod -a -G sslcert nginx DAS HIER KLAPT NICHT
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# - PASSWORT MIT NGINX VORSCHALTEN:
## - creating password file:
     sudo sh -c "echo -n 'leidi:' >> /etc/nginx/.htpasswd"
     sudo sh -c "openssl passwd -apr1 >> /etc/nginx/.htpasswd"
   iop890()/
   kann man für mehrere benutzer wiederholen; anzeigen lassen mit:
     cat /etc/nginx/.htpasswd
## - configuring nginx pw authentification:
     sudo vim /etc/nginx/sites-enabled/stats.urandom.digital
       auth_basic "Restricted Content";
       auth_basic_user_file /etc/nginx/.htpasswd;
   dort einfügen wo das passwort abgefragt werden soll
## - nginx neu starten:
     sudo systemctl restart nginx

...............................KLAPPT NICHT.....................................

# - NODEJS WEBSOCKET
     sudo apt install nodejs
     sudo apt install npm
## - im neuen Projektordner:
     npm init
     npm install ws
## - server.js:
const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', (ws) => {
  ws.on('message', (message) => {
    console.log('Received message:', message);
  });

  ws.send('Welcome to the Websocket server!');
});
## - innerhalb der http direktive in /etc/nginx/nginx.conf:
server {
    listen 80;

    location /websocket {
        proxy_pass http://localhost:8080;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "Upgrade";
    }
}
## - nginx neu starten:
     sudo systemctl nginx restart

## - Clientseite index.html:
<!DOCTYPE html>
<html>
<head>
  <title>Websocket Example</title>
</head>
<body>
  <script>
    // Hier kommt der JavaScript-Code
    const socket = new WebSocket('ws://deine-domain/websocket');

    // Event-Handler für Verbindungsereignisse
    socket.onopen = function () {
      console.log('Websocket connection established.');

      // Sende eine Nachricht an den Server
      socket.send('Hello Server!');
    };

    socket.onmessage = function (event) {
      // Verarbeite empfangene Nachrichten
      console.log('Received message:', event.data);
    };

    socket.onclose = function () {
      console.log('Websocket connection closed.');
    };
  </script>
</body>
</html>
...............................................................................
