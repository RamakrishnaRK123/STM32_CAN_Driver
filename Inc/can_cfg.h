#ifndef CAN_CFG_H
#define CAN_CFG_H

/*=========================================================

* CAN OPERATING MODES
  *=========================================================*/

#define CAN_NORMAL_MODE        0U
#define CAN_LOOPBACK_MODE      1U
#define CAN_SILENT_MODE        2U
#define CAN_SILENT_LOOPBACK    3U

/*=========================================================

* CAN BAUD RATES
  *=========================================================*/

#define CAN_BAUDRATE_125K      125000U
#define CAN_BAUDRATE_250K      250000U
#define CAN_BAUDRATE_500K      500000U
#define CAN_BAUDRATE_1M        1000000U

/*=========================================================

* CAN MAILBOX CONFIGURATION
  *=========================================================*/

#define CAN_TX_MAILBOXES       3U
#define CAN_RX_FIFOS           2U

/*=========================================================

* FILTER CONFIGURATION
  *=========================================================*/

#define CAN_MAX_FILTER_BANKS   28U

#define CAN_FILTER_FIFO0       0U
#define CAN_FILTER_FIFO1       1U

/*=========================================================

* DLC CONFIGURATION
  *=========================================================*/

#define CAN_MAX_DLC            8U

/*=========================================================

* DEFAULT CONFIGURATION
  *=========================================================*/

#define CAN_DEFAULT_PRESCALER  6U
#define CAN_DEFAULT_BS1        13U
#define CAN_DEFAULT_BS2        2U
#define CAN_DEFAULT_SJW        1U

/*=========================================================

* ERROR STATES
  *=========================================================*/

#define CAN_ERROR_ACTIVE       0U
#define CAN_ERROR_PASSIVE      1U
#define CAN_BUS_OFF            2U

/*=========================================================

* FEATURE ENABLE/DISABLE
  *=========================================================*/

#define CAN_ENABLE             1U
#define CAN_DISABLE            0U

/*=========================================================

* PROJECT VERSION
  *=========================================================*/

#define CAN_DRIVER_VERSION_MAJOR    1U
#define CAN_DRIVER_VERSION_MINOR    0U
#define CAN_DRIVER_VERSION_PATCH    0U

#endif
