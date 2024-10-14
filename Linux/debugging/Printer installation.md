## Print & Scan

### Canon iP 4900 Series einrichten mit gutenprint

1. Download driver from https://gimp-print.sourceforge.io/p_Download.php
2. `sudo ./configure`
	1. `sudo apt-get install libcups2-dev`
3. `sudo make`
4. `sudo make install`
5. `localhost:631` > Administration > Add Printer > ... Model: Canon iP4900 series - CUPS+Gutenprint v5.3.5-pre1 (en)
### CUPS
Common Unix Printing System

`localhost:631`
#### change Port

If CUPS (Common Unix Printing System) is using port 8000 on your localhost in Ubuntu and you want to change this port, you can follow these steps:

1. **Stop CUPS Service**: Before making any changes, stop the CUPS service to ensure that there are no active connections to the current port. Open a terminal and use the following command: 
- `sudo systemctl stop cups`

- **Edit Configuration File**: The CUPS configuration file can be found at `/etc/cups/cupsd.conf`. You will need administrative privileges to edit this file. Open the configuration file using a text editor like `nano` or `vim`:
- `sudo nano /etc/cups/cupsd.conf` 

- **Find and Update Port**: In the configuration file, search for the line that specifies the port CUPS is using. This line typically looks like:

`Listen localhost:8000`

Change the port number to the desired port, for example, let's say you want to change it to port 9000:

- `Listen localhost:9000`
   
- **Save and Close**: After making the changes, save the file and close the text editor.
   
- **Restart CUPS Service**: Restart the CUPS service to apply the changes:

- `sudo systemctl restart cups`
   
- **Check Status**: Verify that the CUPS service has started without any errors:

- `sudo systemctl status cups`   

Keep in mind that changing the port might require updating other configurations or services that interact with CUPS. For instance, if you have a firewall enabled, you might need to adjust its rules to allow traffic on the new port.

Additionally, if you're using CUPS for printer sharing across a network, clients will need to be updated with the new port information as well.

Remember to test the printing functionality after making these changes to ensure that everything is working as expected on the new port.

### Brother MFC-8520DN (Atelier)

1. Gerät auf der [Hersteller-Website](https://www.brother.de/support/mfc-8520dn/downloads) suchen und finden
2. Driver Install Tool dort herunterladen
> Step1. Download the tool.(linux-brprinter-installer-*.*.*-*.gz)
The tool will be downloaded into the default "Download" directory.  
(The directory location varies depending on your Linux distribution.)  
e.g. /home/(LoginName)/Download
Step2. Open a terminal window.
Step3. Go to the directory you downloaded the file to in the last step. By using the cd command.
e.g. cd Downloads
Step4. Enter this command to extract the downloaded file:
**Command: gunzip linux-brprinter-installer-*.*.*-*.gz**
e.g. gunzip linux-brprinter-installer-2.1.1-1.gz
Step5. Get superuser authorization with the "**su**" command or "**sudo su**" command.
Step6. Run the tool:
**Command: bash linux-brprinter-installer-*.*.*-* Brother machine name**  
e.g. bash linux-brprinter-installer-2.1.1-1 MFC-J880DW
Step7. The driver installation will start. Follow the installation screen directions.  
 When you see the message "Will you specify the DeviceURI ?",
 For USB Users: Choose N(No)  
 For Network Users: Choose Y(Yes) and DeviceURI number.
The install process may take some time. Please wait until it is complete.

✓ jetzt kann z.B. mithilfe von Skanlite gescannt werden!