## using Swapfile 

1. **Check Current Swap Usage**: Before making any changes, it's a good idea to check the current swap usage on your system. You can use the `free` command to do this:
	- `free -h`
2. **Disable Swap**: If you have an existing swapfile, you'll need to disable it before making changes:    
	- `sudo swapoff /swapfile`
3. **Delete Swapfile (Optional)**: If you're going to create a new swapfile, you can delete the existing one:
	- `sudo rm /swapfile`
4. **Create a New Swapfile**: You can create a new swapfile of the desired size. For example, to create a 4GB swapfile:
	- `sudo fallocate -l 4G /swapfile`
5. **Set Permissions**: Make sure only root can read and write to the swapfile:
	- `sudo chmod 600 /swapfile`
6. **Setup Swap Space**: Set up the swap space on the file:
	- `sudo mkswap /swapfile`
7. **Enable Swap**: Activate the new swapfile:
	- `sudo swapon /swapfile`
8. **Edit the fstab file**: You'll need to make changes to the `/etc/fstab` file to ensure the swapfile is used automatically on boot. Open the file with a text editor (e.g., `sudo nano /etc/fstab`) and add the following line at the end:
	- `/swapfile none swap sw 0 0`
9. **Enable Hibernation**: By default, hibernation might not be enabled in Kubuntu. You'll need to edit the `grub` configuration file to enable it. Open the `/etc/default/grub` file in a text editor with root privileges (e.g., `sudo nano /etc/default/grub`) and find the line that starts with `GRUB_CMDLINE_LINUX_DEFAULT`. Add `resume=/swapfile` to the end of the options within the quotes. It should look something like this:
	- `GRUB_CMDLINE_LINUX_DEFAULT="quiet splash resume=/swapfile"`
10. **Update GRUB**: After making changes to the GRUB configuration, you need to update GRUB:
	- `sudo update-grub`
11. **Testing Hibernation**: After completing the above steps, you can test hibernation by running:
    - `sudo systemctl hibernate`
    
These steps should help you adjust the size of your swapfile and enable hibernation on your Kubuntu system. Make sure to adjust the swapfile size according to your system's requirements.

## hibernate when laptop lid is closed

`sudo nano /etc/systemd/logind.conf`: `HandleLidSwitch=hibernate`