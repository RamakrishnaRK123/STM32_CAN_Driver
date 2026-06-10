\# CAN Interrupts --VII





\## 📌 Overview



CAN interrupts allow the CPU to respond immediately to CAN events without continuously polling status registers.



Interrupt-driven communication improves efficiency and reduces CPU utilization.



\---



\## 🧠 Types of CAN Interrupts



\### Receive Interrupt



Triggered when:



\- New message arrives in FIFO



\---



\### Transmit Interrupt



Triggered when:



\- Message transmission completes



\---



\### Error Interrupt



Triggered when:



\- CAN errors occur



\---



\### Wake-Up Interrupt



Triggered when:



\- CAN controller wakes from sleep mode



\---



\## 🔄 Interrupt Flow



CAN Event

↓

Interrupt Generated

↓

NVIC Receives Request

↓

ISR Executes

↓

Application Notified



\---



\## ⚙️ Receive Interrupt Flow



Message Received

↓

Stored in FIFO

↓

RX Interrupt Generated

↓

ISR Reads Message

↓

FIFO Released



\---



\## ⚙️ Transmit Interrupt Flow



Transmission Complete

↓

TXOK Set

↓

TX Interrupt Generated

↓

Mailbox Released



\---



\## ⚙️ Error Interrupt Flow



Error Detected

↓

Error Flags Updated

↓

Error Interrupt Generated

↓

Error Handler Executes



\---



\## 📌 Registers Used



\- CAN\_IER

\- CAN\_RF0R

\- CAN\_RF1R

\- CAN\_TSR

\- CAN\_ESR



\---



\## 🎯 Summary



Interrupts enable efficient CAN communication by allowing hardware events to trigger software processing automatically.

