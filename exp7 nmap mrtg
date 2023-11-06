nmap

list scan
nmap -sL www.geeksforgeeks.com

ping sweep
nmap -sP www.geeksforgeeks.com

disable ARP ping
nmap -sn www.geeksforgeeks.com –disable-arp-ping

TCP SYN Ping
nmap -PS www.geeksforgeeks.com 

TCP ACK Ping
nmap -sA www.geeksforgeeks.com

ICMP Echo Ping
nmap -PE www.geeksforgeeks.com

UDP Ping
nmap  -sU www.geeksforgeeks.com

IP Protocol Ping
nmap -v -PO www.geeksforgeeks.com

ARP Ping
nmap -PR www.geeksforgeeks.com

Traceroute
nmap -sn –traceroute www.geeksforgeeks.com


==================================================================================================================


for mrtg

1.Installing:
sudo apt-get install mrtg

2.Create a Configuration File:
MRTG uses configuration files to specify the devices you want to monitor and how the data should be graphed. You'll need to create a configuration file (e.g., mrtg.cfg) with entries for each device you want to monitor.
Here's a sample entry for monitoring a router with the IP address 192.168.1.1 using SNMP (Simple Network Management Protocol):

Target[routergateway]: public@192.168.1.1
MaxBytes[routergateway]: 12500000
Title[routergateway]: Router Gateway Traffic
PageTop[routergateway]: <h1>Router Gateway Traffic</h1>

3.Run MRTG:
Once you have your configuration file set up, you can run MRTG to start monitoring the specified devices and generating graphs.
To run MRTG manually, use the following command:
mrtg /path/to/mrtg.cfg

4.Schedule MRTG (Optional):
To continuously monitor your network, it's common to schedule MRTG to run at regular intervals using a cron job. This way, it will collect data and update the graphs automatically.
For example, to update MRTG every 5 minutes, add a line to your crontab like this:
*/5 * * * * /usr/bin/mrtg /path/to/mrtg.cfg




