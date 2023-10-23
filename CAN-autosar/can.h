#ifndef __CAN_H__
#define __CAN_H__

#include "main.h"
#include "stm32f10x_can.h"

typedef struct
{
	uint8_t SJW;
	uint8_t BS1;
	uint8_t BS2;
	uint8_t Prescaler;
	uint32_t FilterMaskId;
	uint32_t FilterId;
	uint8_t TxBufferId;
	uint8_t RxBufferId;
} Can_ConfigType;

typedef uint8_t Std_ReturnType;

#define E_OK ((Std_ReturnType)0x00U)
#define E_NOT_OK ((Std_ReturnType)0x01U)

typedef uint16_t CAN_HwHandleType;
typedef uint16_t PduIdType;
typedef uint32_t Can_IdType;

typedef struct
{
	PduIdType swPduHandle;
	uint8_t length;
	Can_IdType id;
	uint8_t *sdu;
} Can_PduType;


Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);
Std_ReturnType Can_Read(Can_HwHandleType Hrh, const Can_PduType *PduInfo);
	
typedef struct {
	// TODO: not done!!
	uint16 vendorID;
	uint16 moduleID;
	uint8  instanceID;

	uint8 sw_major_version;    /**< Vendor numbers */
	uint8 sw_minor_version;    /**< Vendor numbers */
	uint8 sw_patch_version;    /**< Vendor numbers */

	uint8 ar_major_version;    /**< Autosar spec. numbers */
	uint8 ar_minor_version;    /**< Autosar spec. numbers */
	uint8 ar_patch_version;    /**< Autosar spec. numbers */
} Std_VersionInfoType;

#endif