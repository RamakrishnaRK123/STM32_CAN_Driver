\# CAN Filtering    -VI



\## 📌 Overview

CAN filtering allows the CAN controller to accept only required messages and reject unwanted messages. This reduces CPU load and improves system efficiency.



\---



\## 🧠 Why Filtering is Required



In a CAN network:



\- Multiple nodes share the same bus

\- Every node receives all messages

\- Not every message is relevant



Filtering ensures only useful messages are stored in FIFO.



\---



\## ⚙️ Filter Modes



\### 1. Mask Mode



Uses:



\- Filter ID

\- Filter Mask



Comparison:



Received ID AND Mask

=

Filter ID AND Mask



Only matching bits are checked.



\---



\### 2. List Mode



Stores a list of valid CAN IDs.



Example:



\- ID 0x100

\- ID 0x200

\- ID 0x300



Only these IDs are accepted.



\---



\## 📡 Filter Scale



\### 16-bit Scale



Stores more filter entries.



\---



\### 32-bit Scale



Supports full CAN identifier comparison.



\---



\## 🔄 Filter Configuration Flow



Enter Filter Init Mode

↓

Select Filter Bank

↓

Select Mask/List Mode

↓

Select 16-bit/32-bit Scale

↓

Configure Filter ID

↓

Assign FIFO

↓

Activate Filter



\---



\## 📌 FIFO Assignment



Accepted messages can be routed to:



\- FIFO0

\- FIFO1



depending on filter configuration.



\---



\## 📌 Registers Used



\- CAN\_FMR

\- CAN\_FA1R

\- CAN\_FS1R

\- CAN\_FM1R

\- CAN\_FiR1

\- CAN\_FiR2



\---



\## 🎯 Summary



CAN filtering prevents unwanted messages from entering receive FIFOs and allows efficient message handling using hardware-level filtering.

