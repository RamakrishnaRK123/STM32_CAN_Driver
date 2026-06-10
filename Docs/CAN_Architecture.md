\# CAN Architecture  -- I





\## 📌 Overview

Controller Area Network (CAN) is a multi-master serial communication protocol designed for reliable real-time communication in automotive and embedded systems.



It allows multiple ECUs (nodes) to communicate without a central controller.



\---



\## 🧠 CAN System Architecture



The CAN system consists of 3 main blocks:



\### 1. CAN Controller (Inside MCU)

\- Handles CAN protocol logic

\- Message formatting

\- Arbitration

\- Error detection

\- Located inside STM32 MCU



\---



\### 2. CAN Transceiver

\- Converts digital signals to differential signals

\- Interfaces MCU with physical CAN bus

\- Examples: MCP2551, SN65HVD230



\---



\### 3. CAN Bus

\- Two-wire differential bus (CAN\_H, CAN\_L)

\- Shared communication medium

\- Uses termination resistors (120Ω)



\---



\## 🔄 Complete CAN Communication Flow



Application Layer

↓

CAN Driver (Software APIs)

↓

CAN Registers (STM32 Peripheral)

↓

CAN Controller (Hardware Logic)

↓

CAN Transceiver

↓

CAN Bus

↓

Other Nodes (ECUs)



\---



\## 📡 Node Communication Model



Each node contains:



\- Microcontroller

\- CAN Controller

\- CAN Transceiver



All nodes are equal (multi-master system)



\---



\## ⚙️ Key Features of CAN



\- Message-based communication (not address-based)

\- Multi-master architecture

\- Priority-based arbitration

\- Error detection \& fault confinement

\- High reliability in noisy environments



\---



\## 🚗 Applications



\- Automotive ECUs

\- Electric Vehicles (BMS, VCU)

\- Industrial automation

\- Robotics

\- Medical systems



\---



\## 🎯 Summary



CAN architecture is designed for robust, real-time communication between distributed embedded systems using a shared differential bus and priority-based arbitration.

