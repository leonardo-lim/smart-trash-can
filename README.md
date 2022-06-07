# Smart Trash Can

This IoT-based website application project develops smart trash can that can detect user's hand to open the lid of the trash can and measure the volume of trash can with the help of ultrasonic sensors. The sensor results are then sent to the local web server to be displayed on the website.

## Installation Guide
1. Make sure you have Arduino, XAMPP, C++, and PHP installed
2. Start Apache server and MySQL on XAMPP
3. Start phpMyAdmin or open http://localhost/phpmyadmin on your browser
4. Create database with `smart-trash-can` name
5. Create a table with `sensor` name with two columns named `capacity` with type int and `status` with type boolean
6. Clone the repository in your XAMPP htdocs folder
  ```sh
   git clone https://github.com/leonardo-lim/smart-trash-can.git
  ```
7. Open `main.cpp` file with your Arduino application
8. Add all network information (SSID, password, host, IP address, local IP, gateway, subnet, primary DNS, and secondary DNS) based on your network connection
9. After the configuration is complete, upload the script into NodeMCU
9. Open http://localhost/smart-trash-can on your browser
10. Done, you can see the result updated in real time

## Components
* NodeMCU
* Ultrasonic Sensor
* Servo Motor
* Jumper Wires
* Breadboard

## Features
* Automatic Trash Can Lid Opener
* Trash Can Volume Detector
* Real Time Result Update on Website

## Technology
* PHP
* JavaScript
* HTML
* CSS
* Bootstrap

## DBMS
* MySQL