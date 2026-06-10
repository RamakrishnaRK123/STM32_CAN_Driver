#ifndef CAN_REG_H
#define CAN_REG_H

#include <stdint.h>

/*=========================================================
 * CAN BASE ADDRESS
 *=========================================================*/

#define CAN1_BASE_ADDR    0x40006400U

/*=========================================================
 * CAN TX MAILBOX
 *=========================================================*/

typedef struct
{
    volatile uint32_t TIR;
    volatile uint32_t TDTR;
    volatile uint32_t TDLR;
    volatile uint32_t TDHR;
}CAN_TxMailBox_t;

/*=========================================================
 * CAN RX MAILBOX
 *=========================================================*/

typedef struct
{
    volatile uint32_t RIR;
    volatile uint32_t RDTR;
    volatile uint32_t RDLR;
    volatile uint32_t RDHR;
}CAN_RxMailBox_t;

/*=========================================================
 * CAN FILTER REGISTER
 *=========================================================*/

typedef struct
{
    volatile uint32_t FR1;
    volatile uint32_t FR2;
}CAN_FilterRegister_t;

/*=========================================================
 * CAN REGISTER MAP
 *=========================================================*/

typedef struct
{
    volatile uint32_t MCR;        /* 0x00 */
    volatile uint32_t MSR;        /* 0x04 */
    volatile uint32_t TSR;        /* 0x08 */

    volatile uint32_t RF0R;       /* 0x0C */
    volatile uint32_t RF1R;       /* 0x10 */

    volatile uint32_t IER;        /* 0x14 */
    volatile uint32_t ESR;        /* 0x18 */
    volatile uint32_t BTR;        /* 0x1C */

    uint32_t RESERVED0[88];

    CAN_TxMailBox_t sTxMailBox[3];

    CAN_RxMailBox_t sFIFOMailBox[2];

    uint32_t RESERVED1[12];

    volatile uint32_t FMR;
    volatile uint32_t FM1R;
    uint32_t RESERVED2;

    volatile uint32_t FS1R;
    uint32_t RESERVED3;

    volatile uint32_t FFA1R;
    uint32_t RESERVED4;

    volatile uint32_t FA1R;

    uint32_t RESERVED5[8];

    CAN_FilterRegister_t FilterRegister[28];

}CAN_RegDef_t;

/*=========================================================
 * CAN1 PERIPHERAL
 *=========================================================*/

#define CAN1 ((CAN_RegDef_t *)CAN1_BASE_ADDR)

/*=========================================================
 * MCR BITS
 *=========================================================*/

#define CAN_MCR_INRQ      (1U << 0)
#define CAN_MCR_SLEEP     (1U << 1)
#define CAN_MCR_TXFP      (1U << 2)
#define CAN_MCR_RFLM      (1U << 3)
#define CAN_MCR_NART      (1U << 4)
#define CAN_MCR_AWUM      (1U << 5)
#define CAN_MCR_ABOM      (1U << 6)

/*=========================================================
 * MSR BITS
 *=========================================================*/

#define CAN_MSR_INAK      (1U << 0)
#define CAN_MSR_SLAK      (1U << 1)

/*=========================================================
 * TSR BITS
 *=========================================================*/

#define CAN_TSR_RQCP0     (1U << 0)
#define CAN_TSR_TXOK0     (1U << 1)

#define CAN_TSR_TME0      (1U << 26)
#define CAN_TSR_TME1      (1U << 27)
#define CAN_TSR_TME2      (1U << 28)

/*=========================================================
 * RF0R BITS
 *=========================================================*/

#define CAN_RF0R_FMP0_MASK    (0x03U)
#define CAN_RF0R_RFOM0        (1U << 5)

/*=========================================================
 * RF1R BITS
 *=========================================================*/

#define CAN_RF1R_FMP1_MASK    (0x03U)
#define CAN_RF1R_RFOM1        (1U << 5)

/*=========================================================
 * ESR BITS
 *=========================================================*/

#define CAN_ESR_EWGF      (1U << 0)
#define CAN_ESR_EPVF      (1U << 1)
#define CAN_ESR_BOFF      (1U << 2)

/*=========================================================
 * IER BITS
 *=========================================================*/

#define CAN_IER_TMEIE     (1U << 0)
#define CAN_IER_FMPIE0    (1U << 1)
#define CAN_IER_FMPIE1    (1U << 4)
#define CAN_IER_ERRIE     (1U << 15)

#endif