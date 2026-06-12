# IoT Based Smart Automatic Bell System

This project automates the bell ringing process using an ESP32 microcontroller and a web-based scheduling interface. Instead of manually operating a bell or relying on fixed timer circuits, users can configure bell timings through a web page and allow the system to handle the rest automatically.

The project was developed as an academic mini-project to explore IoT concepts, embedded web servers, RTC modules, and automation using ESP32.

## Features

* Web-based bell scheduling
* Automatic bell operation based on time
* ESP32 hosted web interface
* Real-time clock (RTC) integration
* Multiple bell patterns
* Wi-Fi communication
* Easy schedule modification without changing hardware

## Components Used

* ESP32 Development Board
* DS3231 RTC Module
* Buzzer
* Breadboard
* Jumper Wires
* USB Cable

## Software Used

* Arduino IDE
* ESP32 Board Package
* HTML
* CSS
* JavaScript
* Wi-Fi Access Point Mode

## How It Works

1. The ESP32 creates a Wi-Fi access point.
2. Users connect to the ESP32 network.
3. A web page is opened through the ESP32 web server.
4. Bell schedules are configured through the interface.
5. The ESP32 stores the timing information.
6. The RTC module continuously provides current time data.
7. When the current time matches a scheduled event, the buzzer is activated automatically.

The system can be updated at any time through the web interface without modifying the hardware setup.

## Hardware Overview

The system consists of three main sections:

* ESP32 acting as the controller and web server
* DS3231 RTC module for accurate time keeping
* Buzzer used as the bell output

The ESP32 communicates with the RTC through I2C and controls the buzzer through a GPIO pin.

## Results

The project was successfully tested with different schedules and bell patterns. The ESP32 accurately triggered the buzzer whenever the scheduled time matched the current RTC time.

The web interface allowed schedules to be updated easily, making the system more flexible than traditional timer-based bell systems.

## Learning Outcomes

Through this project, I gained practical experience with:

* ESP32 programming
* Embedded web servers
* HTTP communication
* RTC interfacing
* I2C communication
* IoT system design
* Scheduling and automation logic
* Hardware and software integration

## Future Improvements

* Mobile application support
* Relay-controlled electric bell
* Cloud synchronization
* Notification system
* Multiple device management
* Voice announcement functionality
