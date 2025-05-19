# ESP32 MQTT over TLS Secure Communication

## Overview

This project demonstrates a secure and reliable MQTT communication system using an ESP32 microcontroller connecting to an MQTT broker over **TLS-encrypted channels**. The ESP32 publishes data securely to the broker, ensuring confidentiality and integrity of IoT data in transit.

The implementation includes:

- Connecting the ESP32 to a WiFi hotspot
- Establishing a secure MQTT connection on port 8883 using TLS and CA certificate authentication
- Publishing data securely to an MQTT topic
- Real-time data transfer verified with Mosquitto broker and client

---

## Motivation

In IoT applications, security is a major concern due to sensitive data being transmitted wirelessly over public or private networks. This project addresses the need for **secure communication protocols** by implementing MQTT over TLS on a resource-constrained device like the ESP32. This ensures:

- Encrypted data transmission protecting against eavesdropping  
- Authentication of MQTT broker to prevent man-in-the-middle attacks  
- Secure, scalable communication suitable for industrial and commercial IoT deployments

---

## Key Features

- **WiFi connection management:** Connects ESP32 to a specified hotspot with error handling.
- **TLS-based security:** Uses CA root certificate to verify the MQTT broker’s identity.
- **MQTT Client:** Publishes messages to a designated topic `esp32/input` securely.
- **Certificate management:** Integrates PEM-encoded CA certificate directly in code for easy deployment.
- **Robust reconnection:** Automatically reconnects to MQTT broker if connection is lost.
- **Serial Interface:** Reads input from serial terminal and publishes it to the MQTT broker in real-time.

---

## Technology Stack

| Component               | Details                              |
|------------------------|------------------------------------|
| Microcontroller         | ESP32 Dev Kit                      |
| Programming Language    | C++ (Arduino framework)             |
| MQTT Broker             | Mosquitto (running on Laptop)      |
| Communication Protocols | MQTT over TLS (port 8883)           |
| Security                | TLS 1.2 with CA certificate verification |
| Development Environment | Visual Studio Code, Arduino IDE     |

---

## Setup Instructions

1. **Configure WiFi credentials**  
   Update `ssid` and `password` in the source code to your WiFi hotspot.

2. **Set MQTT Broker IP and Port**  
   Update `mqtt_server` with your broker IP (e.g., laptop IP) and port `8883` for secure connection.

3. **Add CA Certificate**  
   Insert your MQTT broker’s root CA certificate in PEM format inside the source code (`ca_cert` variable).

4. **Upload code to ESP32**  
   Use Arduino IDE or PlatformIO to compile and flash the firmware.

5. **Run Mosquitto Broker with TLS**  
   Setup Mosquitto with TLS on your laptop to accept secure MQTT connections.

6. **Subscribe and Publish**  
   Use `mosquitto_sub` command line or MQTT clients to verify message publishing and subscribing.

---

## Challenges Faced

- Managing certificate formatting for embedding in code
- Ensuring stable WiFi and MQTT connections with automatic reconnect
- Debugging TLS handshake errors on resource-limited ESP32 hardware
- Configuring Mosquitto broker with valid certificates on Windows environment

---

## Future Improvements

- Implement MQTT message subscriptions on ESP32 for bidirectional communication  
- Integrate additional security layers such as mutual TLS authentication  
- Develop a user-friendly OTA update mechanism for secure firmware upgrades  
- Expand project to support multiple topics and QoS levels for reliability  
- Port the solution to other microcontrollers or edge devices

---

## Why This Project Matters

Secure communication is fundamental for any connected IoT system, especially in industrial automation, smart homes, and healthcare monitoring. This project provides a **hands-on practical implementation** of security protocols on an embedded device, demonstrating not only coding skills but also strong understanding of networking and cybersecurity concepts.

---

## Contact

Feel free to reach out for any collaboration or questions:  
**LinkedIn:**  https://www.linkedin.com/in/chinmaybhat25
Vanity URL name LinkedIn

**Email:** chinmaybhat1904@gmail.com

---

*Powered by ESP32, MQTT, and TLS encryption — Securing the future of IoT.*

