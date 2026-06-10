**STM32 CAN Driver (Register-Level)**



&#x20;📌 ***Project Overview***

This project is a register-level CAN driver developed for STM32 microcontrollers without using HAL or LL libraries. It demonstrates deep understanding of CAN protocol, embedded systems, and peripheral programming.



\---



&#x20;**Objective**

To design and implement a CAN driver that supports initialization, message transmission, reception, filtering, interrupts, and error handling using direct register access.



\---



&#x20;**⚙️ Features**

\- Register-level CAN initialization

\- Bit timing configuration

\- Standard and Extended frame support

\- Message transmission using mailboxes

\- Message reception using FIFO

\- Acceptance filter configuration

\- Interrupt-driven communication

\- Error handling (Bus-Off, ACK, CRC, Bit errors)

\- Loopback testing support



\---



&#x20;**CAN Architecture**



Application Layer  

↓  

CAN Driver APIs  

↓  

CAN Registers (STM32 CAN Peripheral)  

↓  

CAN Controller  

↓  

CAN Transceiver  

↓  

CAN Bus  



\---



**CAN Transmission Flow**



Application → CAN\_Transmit()  

→ Select Mailbox  

→ Load CAN ID  

→ Load DLC  

→ Load Data  

→ Set TX Request  

→ Arbitration  

→ Transmission  

→ ACK Received  

→ TX Complete  



\---



&#x20;**CAN Reception Flow**



CAN Bus → CAN Controller  

→ FIFO Receive  

→ Check Identifier  

→ Read Data Registers  

→ Store in Buffer  

→ Notify Application  



\---



&#x20; **APIs**



*| API | Description |*

|-----|-------------|

| CAN\_Init() | Initializes CAN peripheral |

| CAN\_Start() | Starts CAN communication |

| CAN\_Transmit() | Sends CAN message |

| CAN\_Receive() | Receives CAN message |

| CAN\_ConfigFilter() | Configures acceptance filters |

| CAN\_EnableInterrupt() | Enables CAN interrupts |

| CAN\_GetError() | Returns error status |



\---



&#x20; **Bit Timing Formula**



Baud Rate depends on CAN clock and timing segments:



Baud Rate = CAN Clock / (Prescaler × (1 + BS1 + BS2))



\---



&#x20;**Testing**



\- Loopback mode testing

\- Node-to-node communication

\- CAN analyzer verification



\---



&#x20;**Hardware Used**



\- STM32 Microcontroller (F1/F4 series)

\- CAN Transceiver (MCP2551 / SN65HVD230)

\- 120Ω termination resistor



\---



&#x20;**📁 Project Structure**



STM32\_CAN\_Driver/

├── Inc/

├── Src/

├── Docs/

├── README.md



\---



