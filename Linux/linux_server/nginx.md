NB SUBDOMAIN EINRICHTEN

auf strato:

- subdomain erstellen
- unter 'DNS-Verwaltung' muss das A-Record auf die Server-IP zeigen
________________________________________________________________________________

- für statische Webseite:

mkdir /var/www/meinesub.urandom.digital
vim /var/www/meinesub.urandom.digital/index.html

<h1>hi!</hi>

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

vim /etc/nginx/sites-available/meinesub.urandom.digital

server {
        listen 80;
        server_name nodejs.urandom.digital;
        root /var/www/nodejs.urandom.digital;
        index index.php index.html;
}

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

sudo ln -s /etc/nginx/sites-available/meinesub.urandom.digital /etc/nginx/sites-enabled

- check config:

sudo nginx -t

- nginx neu starten:

sudo systemctl restart nginx

________________________________________________________________________________

- mit nodejs:

mkdir ~/meinesub/main.js
vim ~/meinesub/main.js

const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
        res.statusCode = 200;
        res.setHeader('Content-Type', 'text/html');
        res.end('<h1>test moinchen</h1>');
});

server.listen(port, hostname, () => {
        console.log(`Server running at http://${hostname}:${port}/`);
});

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

tmux new -s meinwindow

node main.js

Ctrl+b, d

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

vim /etc/nginx/sites-available/meinesub.urandom.digital

server {
  server_name meinesub.urandom.digital www.meinesub.urandom.digital;

  location / {
    proxy_pass http://localhost:3000/;
  }
}

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

sudo ln -s /etc/nginx/sites-available/meinesub.urandom.digital /etc/nginx/sites-enabled

- check config:

sudo nginx -t

- nginx neu starten:

sudo systemctl restart nginx


________________________________________________________________________________
################################################################################
________________________________________________________________________________

NB: SSL

- in /etc/nginx/meine.webseite.com:

server {
  server_name meine.webseite.com;

  # in /home/ich/ liegt auch der ordner meine_webseite
  root /home/ich/meine_webseite_public_html;

  # die .well-known location ist dann für den certbot:
  location /.well-known/ {

  }

  location / {
    proxy_pass http://localhost:8091;
    # Passwort vorschalten:
    auth_basic "Restricted Content";
    auth_basic_user_file /etc/nginx/.htpasswd_meine_webseite;
  }

}

- Ordner in /home/ich/ anlegen: meine_webseite_public_html (in /home/ich/ liegt auch der ordner meine_webseite)
- in den Ordner eine index.html mit Inhalt "hallo" legen

- und dann:
sudo apt-get install python3-certbot-nginx
sudo certbot --nginx -d meine.webseite.com

- certbot legt dann mit let's encrypt alles nötige in /etc/nginx/meine.webseite.com ab

sudo nginx -t
sudo systemctl restart nginx
sudo systemctl status nginx

- falls alles Fehlerfrei läuft, aber die Seite nicht lädt:
  gucken, ob die Firewall https durchlässt:

sudo ufw status
