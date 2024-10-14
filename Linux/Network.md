
## network adapter
`sudo apt install net-tools`

- `ifconfig` shows network adapter settings like IP address etc
- `ip show addr` shows ip addresses of adapter

## network devices

- `avahi-browse -a`  shows all network devices
- `nmap -sn 192.168.178.0/24` performs ping scan of all devices in local network -> list reachable devices

## show listening ports

- `sudo lsof -nP -iTCP -sTCP:LISTEN` mit PID

```
COMMAND   PID     USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
sshd      445     root    3u  IPv4  16434      0t0  TCP *:22 (LISTEN)
sshd      445     root    4u  IPv6  16445      0t0  TCP *:22 (LISTEN)
apache2   515     root    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
mysqld    534    mysql   30u  IPv6  17636      0t0  TCP *:3306 (LISTEN)
mysqld    534    mysql   33u  IPv6  19973      0t0  TCP *:33060 (LISTEN)
apache2   764 www-data    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
apache2   765 www-data    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
master    929     root   13u  IPv4  19637      0t0  TCP *:25 (LISTEN)
master    929     root   14u  IPv6  19638      0t0  TCP *:25 (LISTEN)
```

- `ss -natu` where The n option means don't translate addresses to names. The a options means show all (listening and non-listening) connections. The t option means TCP connections. The 'u' option means show UDP connections.
- `sudo ss -tunlp` 
- `netstat -apv`

    ```
        l – show only listening sockets
        t – show TCP connections
        n – show addresses in a numerical form
        u – show UDP connections
        p – show process id/program name
    ```

- `nmcli` (-c) shows network connections
- `traceroute [ipAdress]` shows the path packets take to reach a server

### ip sharing does not work

`iptables -S` hat gezeigt: `FORWARD DROP`.. nach **Deinstallation von Docker** hat alles wieder funktioniert!

## show incoming UDP

`tcpdump -i eth0 udp`