# Serial Communication to devices on Linux

## simple commands
- `socat stdio /dev/ttyUSB0` liest wiederholt Serial Output vom MCU aus
- `socat stdio /dev/ttyXXXX >> file.txt` continuously appends output to file
- [weitere Möglichkeiten der Anzeige von Serial Streams in Ubuntu](https://www.cyberciti.biz/hardware/5-linux-unix-commands-for-connecting-to-the-serial-console/)

## from StackOverflow
[How to send data to a serial port and see any answer? - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/117037/how-to-send-data-to-a-serial-port-and-see-any-answer)

> All devices on Unix are mapped to a device file, the serial ports would be `/dev/ttyS0` `/dev/ttyS1` ... .
> 
> First have a look at the permissions on that file, lets assume you are using `/dev/ttyS1`.
> 
> `ls -l /dev/ttyS1`
> 
> You will want read.write access, if this is a shared system then you should consider the security consequences of opening it up for everyone.
> 
>     chmod o+rw /dev/ttyS1
>     
> 
> A very simple crude method to write to the file, would use the simple `echo` command.
> 
>     echo -ne '\033[2J' > /dev/ttyS1
>     
> 
> and to read
> 
>     cat -v < /dev/ttyS1
>     
> 
> You can have cat running in one terminal, and echo in a 2nd.
> 
> If everything is gibberish, then baud rate, bit settings might need setting before you start sending. `stty` will do that. !! NOTE stty will use stdin as default file descriptor to affect.
> 
> Equivalent commands.
> 
>     stty 19200 < /dev/ttyS1
>     stty 19200 -F /dev/ttyS1
>     
> 
> This might be enough for you to script something and log ? Not sure what you are trying to achieve.
> 
> For a more interactive, remembers your default settings approach would be to use `minicom` it is just a program which does everything I've mentioned so far. (similar to hyperterminal in Windows, you might be familiar).
> 
> An intermediate solution, would use a terminal program like `screen` which will work on a serial device.
> 
>     screen /dev/ttyS1
>     
> 
> `man screen` `man minicom` `man stty` for more information
