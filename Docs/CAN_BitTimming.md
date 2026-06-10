\# CAN Bit Timing --- IV



\## 📌 Overview

Bit timing defines how each bit on the CAN bus is formed in time. It ensures synchronization between all nodes on the bus.



Correct bit timing is critical for reliable CAN communication.



\---



\## 🧠 CAN Bit Structure



Each CAN bit is divided into segments:



\- Synchronization Segment (SYNC\_SEG)

\- Propagation Segment (PROP\_SEG)

\- Phase Segment 1 (PHASE\_SEG1)

\- Phase Segment 2 (PHASE\_SEG2)



\---



\## ⚙️ Bit Time Formula



Bit Time = 1 / Baud Rate



In CAN controller:



Baud Rate = CAN Clock / (Prescaler × Total Time Quanta)



Where:



Total Time Quanta = 1 + BS1 + BS2



\---



\## 📌 CAN Bit Timing Parameters



\### 1. Prescaler (BRP)

\- Divides CAN clock

\- Controls time quantum (TQ)



\---



\### 2. BS1 (Bit Segment 1)

\- Used for propagation delay + phase adjustment



\---



\### 3. BS2 (Bit Segment 2)

\- Used for resynchronization



\---



\### 4. SJW (Synchronization Jump Width)

\- Maximum adjustment allowed for clock drift



\---



\## 🔄 Example Calculation



Assume:



\- CAN Clock = 36 MHz

\- Prescaler = 9

\- BS1 = 8 TQ

\- BS2 = 7 TQ



Total TQ = 1 + 8 + 7 = 16



Bit Rate = 36 MHz / (9 × 16)  

Bit Rate = 250 kbps



\---



\## 🧠 Why Bit Timing is Important



\- Ensures all nodes are synchronized

\- Handles propagation delay in long wires

\- Prevents data collision errors

\- Maintains stable communication



\---



\## 📡 Real World Impact



Incorrect bit timing leads to:



\- Bus errors

\- Missing messages

\- Node disconnection (Bus-Off state)



\---



\## 📌 Registers Used (STM32)



\- CAN\_BTR Register



Fields:

\- BRP (Baud Rate Prescaler)

\- TS1 (Time Segment 1)

\- TS2 (Time Segment 2)

\- SJW (Sync Jump Width)



\---



\## 🎯 Summary



Bit timing defines the exact timing structure of a CAN bit. It ensures all nodes on the CAN network communicate reliably using synchronized sampling points.

