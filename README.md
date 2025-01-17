# Accident Detection and IoT Alert System Using Arduino and NodeMCU

This project implements an **Accident Detection and IoT Alert System** that uses an Arduino Uno with a GY-61 accelerometer sensor to monitor sudden acceleration changes and detect potential accidents. The danger status is communicated to a NodeMCU, which sends real-time updates to a cloud server for monitoring and alerts.

## Features
- **Accident Detection**: Detects sudden acceleration changes on X, Y, and Z axes.
- **I2C Communication**: Sends danger status from Arduino to NodeMCU.
- **IoT Integration**: Updates danger status to a cloud server (e.g., ThingSpeak).
- **WiFi Connectivity**: NodeMCU connects to the internet to enable real-time data transmission.

## Components Used
1. **Arduino Uno**
2. **NodeMCU ESP8266**
3. **GY-61 Accelerometer Sensor**
4. Jumper Wires and Breadboard
5. Power Supply

## Prerequisites
- Arduino IDE installed.
- ESP8266 WiFi library installed in Arduino IDE.
- ThingSpeak account or compatible IoT cloud platform.

## Getting Started

### Clone the Repository
```bash
git clone https://github.com/sushmagowda12/Accident-Detection-and-IoT-Alert-System-Using-Arduino-and-NodeMCU.git
```

### Arduino Setup
1. Open the `arduino_code.ino` file in the Arduino IDE.
2. Connect the Arduino Uno to your computer.
3. Upload the code to the Arduino Uno.

### NodeMCU Setup
1. Open the `nodemcu_code.ino` file in the Arduino IDE.
2. Replace the placeholders for WiFi SSID, password, API key, and cloud server URL with your details.
3. Connect the NodeMCU to your computer.
4. Upload the code to the NodeMCU.

### Hardware Connections
#### GY-61 Accelerometer Sensor to Arduino Uno
- **X-axis**: Connect to Arduino A0
- **Y-axis**: Connect to Arduino A1
- **Z-axis**: Connect to Arduino A2
- **VCC**: Connect to Arduino 5V
- **GND**: Connect to Arduino GND

#### I2C Connections between Arduino Uno and NodeMCU
- **Arduino SDA**: Connect to NodeMCU D2
- **Arduino SCL**: Connect to NodeMCU D1
- **GND**: Connect a common ground between Arduino and NodeMCU

### Cloud Integration
- Sign up for a cloud platform (e.g., ThingSpeak).
- Create a channel and obtain the API key.
- Replace the API key and server URL in the NodeMCU code.

## Usage
1. Power up the system.
2. Monitor the serial output on both Arduino and NodeMCU for status updates.
3. View real-time danger status updates on the cloud platform.

## Repository Structure
```plaintext
/Accident-Detection-and-IoT-Alert-System-Using-Arduino-and-NodeMCU
├── arduino_code.ino       # Arduino code for accident detection
├── nodemcu_code.ino       # NodeMCU code for IoT integration
├── README.md              # Project documentation
```

## Contribution
Contributions are welcome! Feel free to fork this repository and submit pull requests.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments
- Inspired by IoT-based accident detection systems.
- Special thanks to the open-source community for libraries and resources.
