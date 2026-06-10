#include "can.h"
#include "can_reg.h"

/*=========================================================

* ENABLE ALL INTERRUPTS
  *=========================================================*/

void CAN_EnableInterrupt(void)
{
CAN1->IER |=
(
CAN_IER_TMEIE  |
CAN_IER_FMPIE0 |
CAN_IER_FMPIE1 |
CAN_IER_ERRIE
);
}

/*=========================================================

* DISABLE ALL INTERRUPTS
  *=========================================================*/

void CAN_DisableInterrupt(void)
{
CAN1->IER &=
~(
CAN_IER_TMEIE  |
CAN_IER_FMPIE0 |
CAN_IER_FMPIE1 |
CAN_IER_ERRIE
);
}

/*=========================================================

* ENABLE TX INTERRUPT
  *=========================================================*/

void CAN_EnableTxInterrupt(void)
{
CAN1->IER |= CAN_IER_TMEIE;
}

/*=========================================================

* ENABLE RX INTERRUPT
  *=========================================================*/

void CAN_EnableRxInterrupt(void)
{
CAN1->IER |= CAN_IER_FMPIE0;
}

/*=========================================================

* ENABLE ERROR INTERRUPT
  *=========================================================*/

void CAN_EnableErrorInterrupt(void)
{
CAN1->IER |= CAN_IER_ERRIE;
}

/*=========================================================

* DISABLE TX INTERRUPT
  *=========================================================*/

void CAN_DisableTxInterrupt(void)
{
CAN1->IER &= ~CAN_IER_TMEIE;
}

/*=========================================================

* DISABLE RX INTERRUPT
  *=========================================================*/

void CAN_DisableRxInterrupt(void)
{
CAN1->IER &= ~CAN_IER_FMPIE0;
}

/*=========================================================

* DISABLE ERROR INTERRUPT
  *=========================================================*/

void CAN_DisableErrorInterrupt(void)
{
CAN1->IER &= ~CAN_IER_ERRIE;
}

/*=========================================================

* TX ISR
  *=========================================================*/

void CAN_TX_IRQHandler(void)
{
CAN_TxCompleteCallback();
}

/*=========================================================

* RX FIFO0 ISR
  *=========================================================*/

void CAN_RX0_IRQHandler(void)
{
CAN_Frame_t rxFrame;

```
CAN_Receive(&rxFrame);

CAN_RxCallback(&rxFrame);
```

}

/*=========================================================

* RX FIFO1 ISR
  *=========================================================*/

void CAN_RX1_IRQHandler(void)
{
CAN_Frame_t rxFrame;

```
CAN_Receive(&rxFrame);

CAN_RxCallback(&rxFrame);
```

}

/*=========================================================

* STATUS CHANGE ERROR ISR
  *=========================================================*/

void CAN_SCE_IRQHandler(void)
{
CAN_ErrorCallback(CAN_GetError());
}
