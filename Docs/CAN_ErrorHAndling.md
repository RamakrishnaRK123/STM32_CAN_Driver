\# CAN Error Handling -- V



\## 📌 Overview

CAN has a strong built-in error detection and fault confinement mechanism to ensure reliable communication in noisy environments.



STM32 CAN peripheral automatically detects and manages errors using error counters and status states.



\---



\## 🧠 Types of CAN Errors



\### 1. Bit Error

\- Transmitted bit does not match bus level



\### 2. Stuff Error

\- More than 5 consecutive bits without opposite polarity



\### 3. CRC Error

\- CRC mismatch in received frame



\### 4. Form Error

\- Violation of fixed frame format



\### 5. Acknowledgment Error

\- No ACK received from other nodes



\---



\## 🔄 Error Handling Flow



Error Detected  

↓  

Error Counter Increases  

↓  

Error Frame Generated  

↓  

Message Retransmission  

↓  

State Transition (Error Active / Passive / Bus-Off)



\---



\## ⚙️ CAN Error States



\### 1. Error Active

\- Normal working state

\- Can send active error frames



\### 2. Error Passive

\- High error count

\- Node becomes less active

\- Uses passive error frames



\### 3. Bus-Off State

\- Severe error condition

\- Node disconnected from bus

\- Transmission disabled



\---



\## 📡 Error Counters



STM32 maintains:



\- TEC (Transmit Error Counter)

\- REC (Receive Error Counter)



\---



\## 📌 Bus-Off Recovery



Steps:



1\. Enter Bus-Off state

2\. Stop transmission

3\. Wait for recovery condition

4\. Reset CAN peripheral or software recovery

5\. Reinitialize CAN



\---



\## ⚙️ STM32 Error Registers



\- CAN\_ESR → Error Status Register

\- CAN\_RF0R / RF1R → FIFO status

\- CAN\_TSR → Transmission status



\---



\## 🔄 Automatic Error Handling Features



\- Automatic retransmission

\- Error frame generation

\- Fault confinement mechanism

\- Bus-off recovery support



\---



\## 🎯 Summary



CAN error handling ensures robust communication by detecting faults, isolating faulty nodes, and maintaining network stability even in harsh electrical environments.

