searching for "ubuntu intel nvidia optimus" → [askubuntu](https://askubuntu.com/questions/1232211/nvidia-optimus-on-20-04-switching-to-intel-gpu-works-on-ubuntu-mate-but-not-on) 
→ mentions `prime-select`
... requires `nvidia-prime`
→ search for "ubuntu nvidia prime" → [How to Install Nvidia Driver on Ubuntu 20.04](https://linoxide.com/linux-how-to/how-to-install-nvidia-driver-on-ubuntu/)
... mentions `hwinfo`: `sudo apt install hwinfo`
`sudo hwinfo --gfxcard --short` to ensure that NVidia GPU is in my system..
`sudo apt install nvidia-prime`
`sudo prime-select query` → "nvidia"
`lspci -k` lists kernel modules for pci:

	```
		01:00.0 VGA compatible controller: NVIDIA Corporation GK107GLM [Quadro K1000M] (rev a1)
			Subsystem: Lenovo GK107GLM [Quadro K1000M]
			Kernel driver in use: nouveau
			Kernel modules: nvidiafb, nouveau
	```

[using NVIDIA GPU as the primary GPU](https://wiki.debian.org/NVIDIA%20Optimus#Using_NVIDIA_GPU_as_the_primary_GPU): insert to xorg.conf settings as mentioned

**... works!!**
