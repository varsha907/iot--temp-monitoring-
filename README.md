# ESP32 DHT11 Temperature Monitoring System 🌡️

A IoT-based environmental monitoring system that measures real-time temperature and humidity using an ESP32 and a DHT11 sensor, then publishes the data to ThingSpeak for cloud visualization.

## 🚀 Features
* **Live IoT Monitoring:** Continuous temperature and humidity tracking.
* **Cloud Visualization:** Real-time interactive graphs hosted on ThingSpeak.
* **Low Power Consumption:** Uses ESP32's efficient processing capabilities.
* **Wireless Data Logging:** Uploads data via Wi-Fi without needing a local server.

## 🛠️ Hardware Requirements
* **Microcontroller:** ESP32 development board.
* **Sensor:** DHT11 temperature and humidity sensor.
* **Connecting Wires:** Jumper wires.
* **Power Source:** Micro-USB cable.

## 💻 Tech Stack
* **Firmware Language:** C++ (Arduino IDE)
* **Cloud Platform:** ThingSpeak (IoT Analytics)
* **Libraries Used:** `DHT sensor library`, `WiFi.h`, `ThingSpeak.h`

## 📦 Circuit Diagram & Setup
Connect the DHT11 sensor to the ESP32 as follows:
* **VCC** ➡️ ESP32 **3.3V**
* **GND** ➡️ ESP32 **GND**
* **DATA** ➡️ ESP32 **GPIO 4** (or your preferred digital pin)

## 🚦 Installation & Configuration

### 1. ThingSpeak Setup
1. Sign up or log in to [ThingSpeak](https://thingspeak.com).
2. Create a **New Channel**.
3. Enable **Field 1** for Temperature and **Field 2** for Humidity.
4. Go to the **API Keys** tab and copy your **Write API Key** and **Channel ID**.

### 2. Software Installation
1. Open the **Arduino IDE**.
2. Install the required libraries via the Library Manager (`Ctrl + Shift + I`):
   * search and install **DHT sensor library** by Adafruit.
   * search and install **ThingSpeak** by MathWorks.
3. Clone or download this repository to your local machine.

### 3. Code Configuration
Open the project sketch file (`.ino`) and replace the placeholders with your network credentials and ThingSpeak keys:

```cpp
const char* SSID = "YOUR_WIFI_SSID";          // Your Wi-Fi Name
const char* PASSWORD = "YOUR_WIFI_PASSWORD";  // Your Wi-Fi Password

unsigned long myChannelNumber = 1234567;      // Your ThingSpeak Channel ID
const char* myWriteAPIKey = "YOUR_API_KEY";   // Your ThingSpeak Write API Key
```

### 4. Upload
1. Connect your ESP32 to your computer.
2. Select your specific ESP32 board and COM port under **Tools**.
3. Click **Upload** (`Ctrl + U`).
4. Open the **Serial Monitor** at `115200` baud rate to check the Wi-Fi connection and data transmission status.

## 📊 Dashboard View
Once data transmission begins, navigate to your **Private View** tab on your ThingSpeak channel to view the live charts plotting your environmental data.

## 📄 License
Distributed under the MIT License. See `LICENSE` for more information.
