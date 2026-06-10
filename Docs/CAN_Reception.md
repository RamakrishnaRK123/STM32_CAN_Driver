\# CAN Reception -- III



\## 📌 Overview

CAN reception is the process of receiving CAN messages from the bus and storing them inside the STM32 CAN receive FIFO.



The CAN peripheral automatically stores received frames after filtering.



\---



\## 🧠 CAN Reception Concept



STM32 has \*\*two receive FIFOs\*\*:



\- FIFO 0

\- FIFO 1



Each FIFO can store multiple CAN messages.



\---



\## 🔄 Reception Flow



CAN Bus  

↓  

CAN Transceiver  

↓  

CAN Controller  

↓  

Acceptance Filter Check  

↓  

FIFO Storage (FIFO0 / FIFO1)  

↓  

Interrupt Trigger (optional)  

↓  

Application Reads Data  



\---



\## ⚙️ Steps in Register Level



\### 1. Message Arrival

A CAN frame is detected on the bus.



\---



\### 2. Acceptance Filtering

The message ID is checked against filter configuration.



If match:

→ Message is accepted  

If not:

→ Message is discarded  



\---



\### 3. Store in FIFO



Message is stored in:



\- FIFO 0 or FIFO 1

\- Based on filter mapping



\---



\### 4. Check Pending Messages



Check:



\- FMP (FIFO Message Pending) bits in CAN\_RFxR register



\---



\### 5. Read Identifier



From:



\- CAN\_RIR register



Contains:

\- Standard ID

\- Extended ID

\- RTR bit



\---



\### 6. Read Data Length



From:



\- CAN\_RDTR register



Gives DLC (0–8 bytes)



\---



\### 7. Read Data Bytes



From:



\- CAN\_RDLR (Data Low)

\- CAN\_RDHR (Data High)



\---



\### 8. Release FIFO



After reading, release FIFO:



\- Set RFOM bit



This allows next message to enter FIFO.



\---



\## 📡 Interrupt-Based Reception (Optional)



If RX interrupt is enabled:



\- Interrupt triggers when message arrives

\- ISR reads FIFO automatically

\- Callback function processes data



\---



\## 📌 Key Registers Used



\- CAN\_RIR → Identifier

\- CAN\_RDTR → DLC

\- CAN\_RDL

