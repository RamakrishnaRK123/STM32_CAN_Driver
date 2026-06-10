#include "can.h"
#include "can_reg.h"

/*=========================================================

* GET ERROR STATUS REGISTER
  *=========================================================*/

uint32_t CAN_GetError(void)
{
return CAN1->ESR;
}

/*=========================================================

* GET TRANSMIT ERROR COUNTER
  *=========================================================*/

uint8_t CAN_GetTEC(void)
{
return (uint8_t)((CAN1->ESR >> 16) & 0xFF);
}

/*=========================================================

* GET RECEIVE ERROR COUNTER
  *=========================================================*/

uint8_t CAN_GetREC(void)
{
return (uint8_t)((CAN1->ESR >> 24) & 0xFF);
}

/*=========================================================

* CHECK BUS OFF STATE
  *=========================================================*/

uint8_t CAN_IsBusOff(void)
{
if(CAN1->ESR & CAN_ESR_BOFF)
{
return 1;
}

```
return 0;
```

}

/*=========================================================

* CLEAR ERRORS
  *=========================================================*/

void CAN_ClearError(void)
{
/* Read ESR to acknowledge errors */
volatile uint32_t temp;

```
temp = CAN1->ESR;

(void)temp;
```

}

/*=========================================================

* BUS OFF RECOVERY
  *=========================================================*/

void CAN_BusOffRecovery(void)
{
if(CAN_IsBusOff())
{
CAN_Stop();

```
    CAN_Start();
}
```

}

/*=========================================================

* DEFAULT CALLBACKS
  *=========================================================*/

**attribute**((weak))
void CAN_TxCompleteCallback(void)
{
}

**attribute**((weak))
void CAN_RxCallback(CAN_Frame_t *rxFrame)
{
(void)rxFrame;
}

**attribute**((weak))
void CAN_ErrorCallback(uint32_t error)
{
(void)error;
}
