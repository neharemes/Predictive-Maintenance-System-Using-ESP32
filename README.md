# Predictive Maintenance System Using ESP32

**An IoT-Based Approach to Real-Time Motor Condition Monitoring and Fault Detection**

---

## 1. Project Overview

The Predictive Maintenance System Using ESP32 is an embedded IoT-based solution developed to monitor the operational condition of a DC motor by analysing critical parameters such as temperature, current consumption, and vibration.

The system integrates multiple sensors with an ESP32 microcontroller to acquire and process motor operating data. By evaluating variations in these parameters, the system aims to identify abnormal operating conditions and support early fault detection.

The project demonstrates the application of embedded systems, sensor interfacing, and Internet of Things (IoT) technologies in industrial equipment monitoring and predictive maintenance.

## 2. Project Objectives

- Develop a real-time motor condition monitoring system.
- Monitor temperature, current consumption, and vibration.
- Identify abnormal motor operating conditions.
- Implement an embedded monitoring and fault detection mechanism.
- Explore IoT-based remote monitoring for industrial applications.
- Improve equipment reliability and minimise unexpected downtime.

## 3. System Architecture

The proposed system follows a sensor-based monitoring architecture. Multiple sensors acquire operational parameters from the DC motor, while the ESP32 acts as the central processing unit responsible for collecting and analysing the sensor data.

The system architecture consists of the following major units:

- **Sensing Unit:** Acquires temperature, current, and vibration data from the motor.
- **Processing Unit:** Uses the ESP32 to process sensor readings and evaluate operating conditions.
- **Motor Control Unit:** Provides motor switching and control based on the implemented control logic.
- **Monitoring Unit:** Supports system status monitoring and IoT-based communication, where implemented.

### 3.1 Block Diagram

The block diagram illustrates the overall functional architecture of the proposed system and the interaction between the sensing units, ESP32 microcontroller, motor control mechanism, and monitoring interface.

The sensor units continuously monitor the motor's operating parameters and provide corresponding signals to the ESP32 for processing and condition evaluation.

[View Block Diagram (PDF)](./Predictive-Maintenance-System-Using-ESP32/Block_diagram/block_diagram.pdf)

### 3.2 Circuit Diagram

The circuit diagram represents the hardware implementation and electrical interconnections of the system. It illustrates the interfacing of the ESP32 with the temperature, current, and vibration sensors, along with the motor control circuitry and power supply.

It provides an overview of the hardware connections required for acquiring sensor data and controlling the motor.

[View Circuit_diagram(PDF)]
(Predictive-Maintenance-System-Using-ESP32/Circuit_diagram/circuit_diagram.pdf)
## 4. Hardware Components

| Component | Function |
|---|---|
| ESP32 | Main microcontroller for data acquisition and processing |
| ACS712 Current Sensor | Measures motor current consumption |
| DS18B20 Temperature Sensor | Measures motor temperature |
| SW-420 Vibration Sensor | Detects motor vibrations |
| DC Gear Motor | Equipment under monitoring |
| Relay / Motor Driver | Motor switching and control, as implemented |
| Power Supply | Provides electrical power to the system |

## 5. Software and Technologies

- **Programming Language:** Embedded C/C++
- **Development Environment:** Arduino IDE
- **Microcontroller Platform:** ESP32
- **Communication Technology:** Wi-Fi
- **IoT Platform:** Blynk, where implemented
- **Sensor Interfacing:** Temperature, current, and vibration sensing

## 6. Working Methodology

The system operates through the following stages:

1. **Data Acquisition:** The sensors monitor the motor's temperature, current consumption, and vibration.
2. **Data Transmission:** The acquired sensor readings are provided to the ESP32 microcontroller.
3. **Data Processing:** The ESP32 processes the collected sensor data.
4. **Condition Monitoring:** The readings are evaluated to identify abnormal operating conditions.
5. **Fault Detection:** Potential motor abnormalities are identified using the implemented monitoring logic.
6. **Alert and Control:** Appropriate alerts and motor-control responses are initiated according to the system implementation.

## 7. Repository Structure

The repository is organised into separate directories for source code, circuit documentation, system architecture, project photographs, results, and technical documentation.

```text
Predictive-Maintenance-System-Using-ESP32/
│
├── Code/
│   └── predictive_maintenance
│       └── predictive_maintenance.ino
│ 
│
├── Circuit_diagram/
│   └── circuit_diagram.pdf
│
├── Block_diagram/
│   └── block_diagram.pdf
│
├── Images/
│   └── project_setup.jpeg
│
├── Results/
│   └── output_screenshots/
│
├── Documentation/
│   └── mini_roject_report.pdf
│
└── README.md
```

## 8. Applications

- Industrial motor condition monitoring
- Predictive maintenance of industrial equipment
- Early detection of abnormal operating conditions
- Industrial Internet of Things (IIoT)
- Embedded monitoring and automation systems

## 9. Future Enhancements

- Integration of machine learning algorithms for intelligent fault prediction.
- Cloud-based storage and analysis of sensor data.
- Historical performance monitoring and trend analysis.
- Advanced fault classification and diagnosis.
- Enhanced remote monitoring and automated maintenance alerts.

## 10. Project Information

| Category | Details |
|---|---|
| Project Title | Predictive Maintenance System Using ESP32 |
| Project Type | B.Tech Mini Project |
| Domain | Embedded Systems and Internet of Things |
| Microcontroller | ESP32 |
| Department | Electronics and Communication Engineering |

---

**Academic Project | Electronics and Communication Engineering**
