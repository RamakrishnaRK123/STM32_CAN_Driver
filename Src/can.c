#include "can.h"
#include "can_reg.h"

/*=========================================================

* CAN INITIALIZATION
  *=========================================================*/

void CAN_Init(CAN_Config_t *config)
{
/* Request Initialization Mode */
CAN1->MCR |= CAN_MCR_INRQ;

```
/* Wait for Initialization Acknowledge */
while(!(CAN1->MSR & CAN_MSR_INAK));

/* Configure Bit Timing Register */
CAN1->BTR = 0;

CAN1->BTR |= ((config->sjw - 1U) << 24);
CAN1->BTR |= ((config->bs1 - 1U) << 16);
CAN1->BTR |= ((config->bs2 - 1U) << 20);
CAN1->BTR |= ((config->prescaler - 1U));
```

}

/*=========================================================

* START CAN
  *=========================================================*/

void CAN_Start(void)
{
CAN1->MCR &= ~CAN_MCR_INRQ;

```
while(CAN1->MSR & CAN_MSR_INAK);
```

}

/*=========================================================

* STOP CAN
  *=========================================================*/

void CAN_Stop(void)
{
CAN1->MCR |= CAN_MCR_INRQ;

```
while(!(CAN1->MSR & CAN_MSR_INAK));
```

}

/*=========================================================

* RESET CAN
  *=========================================================*/

void CAN_Reset(void)
{
CAN_Stop();
}

/*=========================================================

* CHECK FREE TX MAILBOX
  *=========================================================*/

uint8_t CAN_GetTxMailboxFree(void)
{
if(CAN1->TSR & CAN_TSR_TME0)
return 1;

```
if(CAN1->TSR & CAN_TSR_TME1)
    return 1;

if(CAN1->TSR & CAN_TSR_TME2)
    return 1;

return 0;
```

}

/*=========================================================

* TRANSMIT FRAME
  *=========================================================*/

uint8_t CAN_Transmit(CAN_Frame_t *txFrame)
{
uint8_t mailbox;

```
if(CAN1->TSR & CAN_TSR_TME0)
    mailbox = 0;
else if(CAN1->TSR & CAN_TSR_TME1)
    mailbox = 1;
else if(CAN1->TSR & CAN_TSR_TME2)
    mailbox = 2;
else
    return CAN_ERROR;

CAN1->sTxMailBox[mailbox].TIR =
    (txFrame->id << 21);

CAN1->sTxMailBox[mailbox].TDTR =
    txFrame->dlc;

CAN1->sTxMailBox[mailbox].TDLR =
    (txFrame->data[3] << 24) |
    (txFrame->data[2] << 16) |
    (txFrame->data[1] << 8)  |
    (txFrame->data[0]);

CAN1->sTxMailBox[mailbox].TDHR =
    (txFrame->data[7] << 24) |
    (txFrame->data[6] << 16) |
    (txFrame->data[5] << 8)  |
    (txFrame->data[4]);

/* Transmission Request */
CAN1->sTxMailBox[mailbox].TIR |= 1U;

return CAN_OK;
```

}

/*=========================================================

* RX PENDING COUNT
  *=========================================================*/

uint8_t CAN_GetRxPending(void)
{
return (CAN1->RF0R & CAN_RF0R_FMP0_MASK);
}

/*=========================================================

* RECEIVE FRAME
  *=========================================================*/

uint8_t CAN_Receive(CAN_Frame_t *rxFrame)
{
uint32_t low;
uint32_t high;

```
if(CAN_GetRxPending() == 0)
    return CAN_ERROR;

rxFrame->id =
    (CAN1->sFIFOMailBox[0].RIR >> 21);

rxFrame->dlc =
    (CAN1->sFIFOMailBox[0].RDTR & 0x0F);

low = CAN1->sFIFOMailBox[0].RDLR;
high = CAN1->sFIFOMailBox[0].RDHR;

rxFrame->data[0] = low;
rxFrame->data[1] = low >> 8;
rxFrame->data[2] = low >> 16;
rxFrame->data[3] = low >> 24;

rxFrame->data[4] = high;
rxFrame->data[5] = high >> 8;
rxFrame->data[6] = high >> 16;
rxFrame->data[7] = high >> 24;

CAN1->RF0R |= CAN_RF0R_RFOM0;

return CAN_OK;
```

}

/*=========================================================

* FIFO RELEASE
  *=========================================================*/

void CAN_ReleaseFIFO0(void)
{
CAN1->RF0R |= CAN_RF0R_RFOM0;
}

void CAN_ReleaseFIFO1(void)
{
CAN1->RF1R |= CAN_RF1R_RFOM1;
}
