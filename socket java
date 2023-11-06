Program –
// SimpleServer.java: A simple server program.
import java.net.*;

import java.io.*;
public class SimpleServer {
public static void main(String args[]) throws IOException {
// Register service on port 1254
ServerSocket s = new ServerSocket(1254);
Socket s1=s.accept(); // Wait and accept a connection
// Get a communication stream associated with the socket
OutputStream s1out = s1.getOutputStream();
DataOutputStream dos = new DataOutputStream (s1out);
// Send a string!
dos.writeUTF(“Hi there”);
// Close the connection, but not the server socket
dos.close(); s1out.close(); s1.close(); }}
// SimpleClient.java: A simple client program.
import java.net.*;
import java.io.*;
public class SimpleClient {
public static void main(String args[]) throws IOException {
// Open your connection to a server, at port 1254
Socket s1 = new Socket(“localhost”,1254);
// Get an input file handle from the socket and read the input
InputStream s1In = s1.getInputStream();
DataInputStream dis = new DataInputStream(s1In);

String st = new String (dis.readUTF());
System.out.println(st);
// When done, just close the connection and exit
dis.close();
s1In.close();
s1.close();
}}
Output –
java SimpleServer
java SimpleClient
Hi there
Program –
// UDPServer.java: A simple UDP server program.
import java.net.*;
import java.io.*;
public class UDPServer {
public static void main(String args[]){
DatagramSocket aSocket = null;
if (args.length &lt; 1) {
System.out.println(“Usage: java UDPServer &lt;Port Number&gt;”);
System.exit(1);
}
try {

int socket_no = Integer.valueOf(args[0]).intValue();
aSocket = new DatagramSocket(socket_no);
byte[] buffer = new byte[1000];
while(true) {
DatagramPacket request = new DatagramPacket(buffer,
buffer.length);
aSocket.receive(request);
DatagramPacket reply = new DatagramPacket(request.getData(),
request.getLength(),request.getAddress(),
request.getPort());
aSocket.send(reply);
} }
catch (SocketException e) {
System.out.println(“Socket: ” + e.getMessage());
}
catch (IOException e) {
System.out.println(“IO: ” + e.getMessage());
} finally {
if (aSocket != null)
aSocket.close();
}
}}
// UDPClient.java: A simple UDP client program.

import java.net.*;
import java.io.*;
public class UDPClient {
public static void main(String args[]){
// args give message contents and server hostname
DatagramSocket aSocket = null;
if (args.length &lt; 3) {
System.out.println(
“Usage: java UDPClient &lt;message&gt; &lt;Host name&gt; &lt;Port number&gt;”);
System.exit(1);
try {
aSocket = new DatagramSocket();
byte [] m = args[0].getBytes();
InetAddress aHost = InetAddress.getByName(args[1]);
int serverPort = Integer.valueOf(args[2]).intValue();
DatagramPacket request =
new DatagramPacket(m, args[0].length(), aHost, serverPort);
aSocket.send(request);
byte[] buffer = new byte[1000];
DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
aSocket.receive(reply);
System.out.println(“Reply: ” + new String(reply.getData())); }
catch (SocketException e) {

System.out.println(“Socket: ” + e.getMessage()); }
catch (IOException e) {
System.out.println(“IO: ” + e.getMessage()); }
finally {
if (aSocket != null)
aSocket.close();
} }}
Output –
Java UDPServer
Java UDPClient
Hi there
