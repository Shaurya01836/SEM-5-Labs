# EXPERIMENT 4

## Installation of Wireshark, tcpdump, etc. and Observe Data Transferred in Client-Server Communication Using UDP/TCP and Identify the UDP/TCP Datagram

---

# 1. Step Wireshark

## a. Download and Install Wireshark

* Go to the Wireshark website to download the version that is compatible with your operating system.
* Adhere to the website’s installation instructions.

## b. Begin Packet Capturing

* Open Wireshark and choose the network interface from which to begin collecting packets.
* The display filter in Wireshark. The display filter in Wireshark’s default configuration is a bar that sits right above the column display. Here is where we enter expressions to narrow down what we can see in a pcap file, be it Ethernet frames, IP packets, or TCP segments.
* There are several local interfaces available; please choose one.
* Press the Start button.
* In essence, you are recording and intercepting data packets as they pass through a network interface when you capture packets.

## c. Analyze Packets

* Wireshark will show packets as they come through the chosen interface in real time.To limit the packets that are shown based on parameters such as source, destination, protocol, etc., you can apply filters.

---

# 2. Step tcpdump

## Launch a Terminal or Command Prompt

* On Unix-based systems, open a terminal window. As an administrator, run the Command Prompt on Windows.

## Begin Packet Capturing

* In the first case, run dumpcap -i <interface>-w<output_file>, where <interface> is the network interface that you choose to start capturing from.

## View Captured Packets

* tcpdump will present captured packets in a readable format on the terminal window.
