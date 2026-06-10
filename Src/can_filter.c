#include "can.h"
#include "can_reg.h"

/*=========================================================

* CONFIGURE FILTER
  *=========================================================*/

void CAN_ConfigFilter(CAN_FilterConfig_t *filter)
{
/* Enter Filter Initialization Mode */
CAN1->FMR |= (1U << 0);

```
/* Disable Filter Bank 0 */
CAN1->FA1R &= ~(1U << 0);

/* 32-bit Filter Scale */
CAN1->FS1R |= (1U << 0);

/* Mask Mode */
CAN1->FM1R &= ~(1U << 0);

/* Assign FIFO */
if(filter->fifo_number == 1)
{
    CAN1->FFA1R |= (1U << 0);
}
else
{
    CAN1->FFA1R &= ~(1U << 0);
}

/* Filter ID */
CAN1->FilterRegister[0].FR1 =
    filter->filter_id;

/* Filter Mask */
CAN1->FilterRegister[0].FR2 =
    filter->filter_mask;

/* Enable Filter */
CAN1->FA1R |= (1U << 0);

/* Exit Filter Initialization Mode */
CAN1->FMR &= ~(1U << 0);
```

}

/*=========================================================

* ENABLE FILTER
  *=========================================================*/

void CAN_EnableFilter(uint8_t bank)
{
CAN1->FA1R |= (1U << bank);
}

/*=========================================================

* DISABLE FILTER
  *=========================================================*/

void CAN_DisableFilter(uint8_t bank)
{
CAN1->FA1R &= ~(1U << bank);
}
