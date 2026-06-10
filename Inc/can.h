#ifndef CAN_H
#define CAN_H

#include <stdint.h>

/*=========================================================
 * CAN DEFINITIONS
 *=========================================================*/

#define CAN_STD_ID     0U
#define CAN_EXT_ID     1U

#define CAN_DATA_FRAME   0U
#define CAN_REMOTE_FRAME 1U

#define CAN_OK         1U
#define CAN_ERROR      0U

/*=========================================================
 * CAN FRAME STRUCTURE
 *=========================================================*/

typedef struct
{
    uint32_t id;          /* Standard/Extended Identifier */
    uint8_t id_type;      /* CAN_STD_ID / CAN_EXT_ID */
    uint8_t frame_type;   /* DATA / REMOTE */
    uint8_t dlc;          /* Data Length Code (0-8) */
    uint8_t data[8];      /* CAN Payload */
}CAN_Frame_t;

/*=========================================================
 * CAN CONFIGURATION STRUCTURE
 *=========================================================*/

typedef struct
{
    uint32_t baudrate;

    uint8_t sjw;

    uint8_t bs1;

    uint8_t bs2;

    uint16_t prescaler;

}CAN_Config_t;

/*=========================================================
 * FILTER CONFIGURATION
 *=========================================================*/

typedef struct
{
    uint32_t filter_id;

    uint32_t filter_mask;

    uint8_t fifo_number;

}CAN_FilterConfig_t;

/*=========================================================
 * ERROR STATUS STRUCTURE
 *=========================================================*/

typedef struct
{
    uint8_t tec;

    uint8_t rec;

    uint8_t bus_off;

    uint8_t error_passive;

    uint8_t error_warning;

}CAN_ErrorStatus_t;

/*=========================================================
 * DRIVER APIS
 *=========================================================*/

/* Initialization */
void CAN_Init(CAN_Config_t *config);

/* Start CAN Communication */
void CAN_Start(void);

/* Stop CAN Communication */
void CAN_Stop(void);

/* Reset CAN Peripheral */
void CAN_Reset(void);

/*=========================================================
 * TRANSMISSION APIS
 *=========================================================*/

uint8_t CAN_Transmit(CAN_Frame_t *txFrame);

uint8_t CAN_GetTxMailboxFree(void);

uint8_t CAN_IsTransmissionComplete(void);

/*=========================================================
 * RECEPTION APIS
 *=========================================================*/

uint8_t CAN_Receive(CAN_Frame_t *rxFrame);

uint8_t CAN_GetRxPending(void);

void CAN_ReleaseFIFO0(void);

void CAN_ReleaseFIFO1(void);

/*=========================================================
 * FILTER APIS
 *=========================================================*/

void CAN_ConfigFilter(CAN_FilterConfig_t *filter);

void CAN_EnableFilter(uint8_t bank);

void CAN_DisableFilter(uint8_t bank);

/*=========================================================
 * INTERRUPT APIS
 *=========================================================*/

void CAN_EnableInterrupt(void);

void CAN_DisableInterrupt(void);

void CAN_EnableTxInterrupt(void);

void CAN_EnableRxInterrupt(void);

void CAN_EnableErrorInterrupt(void);

void CAN_DisableTxInterrupt(void);

void CAN_DisableRxInterrupt(void);

void CAN_DisableErrorInterrupt(void);

/*=========================================================
 * ERROR HANDLING APIS
 *=========================================================*/

uint32_t CAN_GetError(void);

uint8_t CAN_GetTEC(void);

uint8_t CAN_GetREC(void);

uint8_t CAN_IsBusOff(void);

void CAN_ClearError(void);

void CAN_BusOffRecovery(void);

/*=========================================================
 * STATUS APIS
 *=========================================================*/

uint8_t CAN_IsInitialized(void);

uint8_t CAN_IsStarted(void);

uint8_t CAN_IsSleepActive(void);

/*=========================================================
 * CALLBACKS
 *=========================================================*/

void CAN_TxCompleteCallback(void);

void CAN_RxCallback(CAN_Frame_t *rxFrame);

void CAN_ErrorCallback(uint32_t error);

/*=========================================================
 * ISR HANDLERS
 *=========================================================*/

void CAN_TX_IRQHandler(void);

void CAN_RX0_IRQHandler(void);

void CAN_RX1_IRQHandler(void);

void CAN_SCE_IRQHandler(void);

#endif /* CAN_H */