Questions:
 

Q1) Solution
Enter commands in terminal and see. If no idea then put -h in front of them

Q2) Solution
Cisco Packet Tracer download and check if there is any help guide in it

Q3) Solution
Wireshark basic commands like start and stop are just buttons on its UI, so its easy. PARTIALLY EXECUTED TOH MIL HI JAYEGA

Q4) Solution
<<<<<<<>>>>>>>>>>
Q5) Solution
<<<<<<<>>>>>>>>>>


Q6) Solution
Just type “nmap” command in terminal, it will give you all different options on how to use it, along with examples
A good usage example would be “nmap -iL file.txt” and before this, create a file having one or more IP addresses/domain names.

Q7) Solution
TCP
Server code:

import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific host and port
host = 'localhost'  # Change to your desired host or use an empty string for all available interfaces
port = 12345  # Change to your desired port
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(5)

print(f"Server is listening on {host}:{port}")

while True:
	# Accept a connection from a client
	client_socket, client_address = server_socket.accept()

	print(f"Connected to {client_address}")

	while True:
    	# Receive data from the client
    	data = client_socket.recv(1024)
    	if not data:
        	break  # No more data from the client

    	# Echo the received data back to the client
    	client_socket.send(data)

	# Close the client socket
	client_socket.close()

# Close the server socket
server_socket.close()

Client Code:

import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_host = 'localhost'  # Change to the server's host
server_port = 12345  # Change to the server's port
client_socket.connect((server_host, server_port))

while True:
	message = input("Enter a message (or 'exit' to quit): ")
	if message.lower() == 'exit':
    	break

	# Send the message to the server
	client_socket.send(message.encode())

	# Receive and print the echoed message from the server
	data = client_socket.recv(1024)
	print(f"Server says: {data.decode()}")

# Close the client socket
client_socket.close()

Q8) Solution
UDP

Server Code:
import socket

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 12345)
server_socket.bind(server_address)

print("Server is listening on {}:{}".format(*server_address))

while True:
	# Receive data from the client
	data, client_address = server_socket.recvfrom(1024)
	print("Received data from {}:{}".format(*client_address))
	print("Data received: {}".format(data.decode()))

	# Send a response back to the client
	response = "Hello, client!"
	server_socket.sendto(response.encode(), client_address)


Client Code:
import socket
# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address and port
server_address = ('localhost', 12345)
message = "Hello, server!"

# Send data to the server
client_socket.sendto(message.encode(), server_address)
print("Sent data to {}:{}".format(*server_address))

# Receive a response from the server
response, server_address = client_socket.recvfrom(1024)
print("Received response from {}:{}".format(*server_address))
print("Response: {}".format(response.decode()))

# Close the socket 
client_socket.close()
Q9) Solution
First use the following commands
sudo apt update
sudo apt install vsftpd
sudo systemctl start vsftpd
sudo systemctl enable vsftpd
This will setup the FTP server
After the above steps, you can use the following code

from ftplib import FTP

# Replace with your FTP server details
ftp_server = "10.0.2.15" #You can put your system’s IP address here (find using ifconfig)
ftp_username = "ladkaonubuntu" #You can put default user ID and pass of the system
ftp_password = "LocalLadka@hubuntu"

# Connect to the FTP server
ftp = FTP(ftp_server)
ftp.login(ftp_username, ftp_password)

# List directory contents
print("Directory listing:")
ftp.retrlines('LIST')

# Upload a file to the server
local_file = "file_to_upload.txt"
remote_file = "uploaded_file.txt"
with open(local_file, 'rb') as file:
	ftp.storbinary(f'STOR {remote_file}', file)

# Download a file from the server
downloaded_file = "downloaded_file.txt"
with open(downloaded_file, 'wb') as file:
	ftp.retrbinary(f'RETR {remote_file}', file.write)

# Close the FTP connection
ftp.quit()

print(f"{remote_file} uploaded and {downloaded_file} downloaded.")

Q10) Solution
https://phoenixnap.com/kb/telnet-linux
Use the following commands to install telnet server
Sudo apt install telnetd -y
sudo systemctl status inetd (Checks if telnet is installed properly by running it)
sudo ufw allow 23/tcp (allows port 23 through firewall on remote machine by running)
Sudo ufw reload
Now the telnet is allowed thru firewall
After this, ensure that Telnet is installed on both machines.
Now to perform REMOTE LOGIN, Follow these steps
telnet [remote_machine_IP]
Make sure that telnet is installed on both machines and port 23 is allowed through the firewall on the remote machine.
When prompted, enter the account username and password to log in to the system. After logging in, you can operate the other machine remotely.


Q11) Solution
i) View current routing table
netstat -r

ii) Add and Delete Routes
To add a route, you can use the route command with the add option. For example, to add a route to network 192.168.1.0 via gateway 192.168.0.1 on the interface eth0:
sudo route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1 dev eth0

To delete a route, use the route command with the del option. For example, to delete the route to network 192.168.1.0:
sudo route del -net 192.168.1.0

iii) change default gateway
First, you need to delete the existing default gateway using the route command with the del option
sudo route del default
Then, add a new default gateway using the route command with the add option. For example, to set the default gateway to 192.168.0.1:
sudo route add default gw 192.168.0.1

 
Q12) Solution
It is covered in Cisco Packet Tracer
Follow these steps
Class A Network:
●	Class A networks have IP addresses in the range 1.0.0.0 to 126.255.255.255.
●	A subnet mask of 255.0.0.0 is typically used for Class A networks.
Class B Network:
●	Class B networks have IP addresses in the range 128.0.0.0 to 191.255.255.255.
●	A subnet mask of 255.255.0.0 is typically used for Class B networks.
Router Configuration:
1.	Connect the Router:
○	Physically connect the router to your network. Ensure that it's powered on and properly connected to the devices.
2.	Access the Router Configuration Interface:
○	Open a web browser and enter the router's IP address in the address bar. The router's IP address is usually 192.168.0.1, 192.168.1.1, or something similar. Check the router's manual for the exact IP address.
3.	Log In to the Router:
○	You'll be prompted to log in. Enter the router's username and password. The default login credentials are often found in the router's manual. If they've been changed, use the updated credentials.
4.	Configure LAN Settings:
○	In the router's configuration interface, navigate to the LAN settings.
○	Assign an IP address within the Class A range (e.g., 10.0.0.1) to the router for the Class A network.
5.	Configure DHCP (Optional):
○	You can enable the router's DHCP server to automatically assign IP addresses to devices in the network.
Class A Network Devices:
●	For devices in the Class A network, set their IP addresses manually or enable DHCP.
Class B Network Devices:
●	Configure devices in the Class B network with IP addresses within the Class B range (e.g., 172.16.0.1).
Routing:
●	The router should be able to route traffic between the Class A and Class B networks, as routers operate at the network layer and can route traffic between different subnets.
Firewall and Security:
●	Implement firewall rules and security measures on the router to control and secure traffic between the networks.
Please note that the specific steps may vary depending on the make and model of your router and your network requirements. Refer to your router's documentation for detailed instructions on configuring LAN settings, DHCP, and routing.


Q13) Solution
It is covered in Cisco Packet Tracer
Follow these steps
Note: Class A networks are typically large and may not be suitable for a small local network. You can use a smaller subnet of the Class A range for your local network, which provides more IP addresses.
1.	Plan Your Network:
○	Determine the size of your network, the number of devices you need to connect, and the IP address range you want to allocate within the Class A range.
2.	Choose a Switch:
○	Select a network switch that suits your requirements. The choice depends on the number of devices you plan to connect, network speed, and any specific features you need.
3.	Connect Devices to the Switch:
○	Physically connect your devices (computers, printers, etc.) to the switch using Ethernet cables.
4.	Assign IP Addresses:
○	Configure the devices in your network to use IP addresses from your chosen Class A range. For example, you can assign IP addresses like 10.0.0.1, 10.0.0.2, 10.0.0.3, and so on.
5.	Set Subnet Mask:
○	Configure the subnet mask for the devices to define the network range. In a Class A network, the subnet mask would typically be 255.0.0.0, which allows for a large number of host addresses.
6.	Test Connectivity:
○	Ensure that devices on your network can communicate with each other by pinging between devices to test connectivity.
7.	Consider DHCP (Optional):
○	If you have a large number of devices and want to automate IP address allocation, you can set up a DHCP server within your network to dynamically assign IP addresses to devices.
Here's an example of how to set a static IP address on a device (Linux-based device) connected to your Class A network:
bash
sudo ifconfig eth0 10.0.0.2 netmask 255.0.0.0 up

In this example, the device is assigned the IP address 10.0.0.2 with a subnet mask of 255.0.0.0 on the "eth0" network interface.
Remember that when setting up a Class A network, you have a very large IP address range at your disposal, so be mindful of IP address allocation and the potential for IP address conflicts.
Please adapt the steps based on your specific network configuration, devices, and requirements.

Q14) Solution
FTP installation covered in FTP wala QN
Telnet installation covered in Telnet wala QN
SSH installation:
sudo apt update
sudo apt install openssh-server
sudo systemctl enable ssh
sudo systemctl start ssh
sudo systemctl status ssh
After this,
1.	Firewall Configuration (if necessary): If you are running a firewall on your Ubuntu server (e.g., UFW), make sure to allow incoming SSH traffic. By default, the SSH server listens on port 22. You can use the following command to allow SSH traffic:
sudo ufw allow 22/tcp
2.	If you are using a different port for SSH, replace 22 with the appropriate port number.
3.	Access Your SSH Server: You can now access your Ubuntu server using SSH from another machine. Use the following command on the client machine to connect to the server:
ssh username@server_ip_or_hostname
Replace username with your username on the server and server_ip_or_hostname with the IP address or hostname of your Ubuntu server.
You'll be prompted to enter your user password on the server.

Q15) Solution
1.	Open Wireshark: After installation, open Wireshark from your applications menu or by running wireshark in your terminal.
2.	Load the pcap File:
○	In the Wireshark window, click on "File" in the top menu.
○	Select "Open" to load a pcap file from your local file system.
○	Browse to the location of your pcap file and select it.
3.	View Packet Capture:
○	Once you've loaded the pcap file, Wireshark will start displaying the captured packets in the main window.
○	You will see a list of packets, each with information such as the source and destination IP addresses, port numbers, and the protocol used.
4.	Analyze Packets:
○	You can click on any packet in the list to view more details in the packet details pane at the bottom of the window.
○	You can expand various protocol layers to inspect the contents and details of each packet.
○	Wireshark provides detailed information about the selected packet, including the protocol used, packet header information, and the raw data.
5.	Apply Filters (Optional):
○	You can use display filters to narrow down the packets displayed based on specific criteria. Enter a filter expression in the display filter box at the top.
○	For example, you can filter packets by IP address, protocol, port number, etc.
6.	Export Data (Optional):
○	You can export specific packets or the entire capture in various formats. Go to "File" > "Export Packet Dissections" to save packet data to a file.
7.	Color Coding:
○	Wireshark uses color coding to help you identify different types of packets. Green is typically used for TCP traffic, while blue is used for UDP, and so on.
8.	Follow TCP Stream (Optional):
○	You can right-click on a packet and select "Follow" > "TCP Stream" to view the full conversation between the source and destination for a specific TCP connection.
9.	Statistics and Analysis (Optional):
○	Wireshark provides various statistical and analysis tools to help you gain insights into the captured network traffic. You can access these tools from the "Statistics" menu.




