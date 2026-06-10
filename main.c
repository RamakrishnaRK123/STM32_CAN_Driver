#include "can.h"
#include "can_cfg.h"

int main(void)
{
CAN_Config_t canConfig;

```
CAN_FilterConfig_t filterConfig;

CAN_Frame_t txFrame;

CAN_Frame_t rxFrame;

/* Configure CAN */

canConfig.baudrate  = CAN_BAUDRATE_500K;
canConfig.prescaler = 6;
canConfig.bs1       = 13;
canConfig.bs2       = 2;
canConfig.sjw       = 1;

/* Initialize CAN */

CAN_Init(&canConfig);

/* Configure Filter */

filterConfig.filter_id   = 0x123 << 21;
filterConfig.filter_mask = 0x7FF << 21;
filterConfig.fifo_number = CAN_FILTER_FIFO0;

CAN_ConfigFilter(&filterConfig);

/* Enable Interrupts */

CAN_EnableInterrupt();

/* Start CAN */

CAN_Start();

/* Prepare TX Frame */

txFrame.id         = 0x123;
txFrame.id_type    = CAN_STD_ID;
txFrame.frame_type = CAN_DATA_FRAME;

txFrame.dlc = 8;

txFrame.data[0] = 0x11;
txFrame.data[1] = 0x22;
txFrame.data[2] = 0x33;
txFrame.data[3] = 0x44;
txFrame.data[4] = 0x55;
txFrame.data[5] = 0x66;
txFrame.data[6] = 0x77;
txFrame.data[7] = 0x88;

/* Transmit */

CAN_Transmit(&txFrame);

while(1)
{
    if(CAN_Receive(&rxFrame) == CAN_OK)
    {
        /* Process Received Data */
    }

    if(CAN_IsBusOff())
    {
        CAN_BusOffRecovery();
    }
}
```

}
