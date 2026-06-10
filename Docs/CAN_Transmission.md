\# CAN Transmission  -II



\## 📌 Overview

CAN transmission is the process of sending data frames from one CAN node to another over the CAN bus using the STM32 CAN peripheral.



Transmission is handled through \*\*mailboxes\*\* inside the CAN controller.



\---



\## 🧠 CAN Transmission Concept



STM32 CAN has \*\*3 transmit mailboxes\*\*:



\- TX mailbox 0

\- TX mailbox 1

\- TX mailbox 2



Each mailbox can hold one CAN message.



\---



\## 🔄 Transmission Flow



Application Layer  

↓  

Load CAN Frame  

↓  

Select Free Mailbox  

↓  

Set Identifier (Std/Ext)  

↓  

Set Data Length (DLC)  

↓  

Load Data Bytes  

↓  

Request Transmission (TXRQ)  

↓  

Arbitration on CAN Bus  

↓  

Transmission Success  

↓  

ACK Received  



\---



\## ⚙️ Steps in Register Level



\### 1. Check Free Mailbox

Check TME bits in CAN\_TSR register.



\---



\### 2. Set Identifier



For Standard ID:

\- Use STDID field



For Extended ID:

\- Use EXTID field



\---



\### 3. Set Frame Type

\- Data Frame

\- Remote Frame



Controlled using RTR bit.



\---



\### 4. Set Data Length (DLC)

Maximum 8 bytes for classical CAN.



\---



\### 5. Load Data into Data Registers



Data is split into:



\- Data Low Register (DATA0–DATA3)

\- Data High Register (DATA4–DATA7)



\---



\### 6. Request Transmission



Set TXRQ bit in mailbox register.



This starts transmission process.



\---



\## 🔄 Arbitration Process



If multiple nodes transmit:



\- Lower ID = Higher priority

\- Bit-by-bit arbitration occurs

\- Non-dominant nodes stop transmitting



\---



\## 📡 Transmission Complete



Check:



\- RQCP (Request Complete)

\- TXOK (Transmission OK)



in CAN\_TSR register.



\---



\## 📌 Key Registers Used



\- CAN\_TIR → Identifier + TX Request

\- CAN\_TDTxR → DLC + control bits

\- CAN\_TDLxR → Data Low

\- CAN\_TDHxR → Data High

\- CAN\_TSR → Status Register



\---



\## 🎯 Summary



CAN transmission in STM32 uses mailbox-based hardware buffering where messages are loaded into registers and sent automatically based on bus arbitration rules.

