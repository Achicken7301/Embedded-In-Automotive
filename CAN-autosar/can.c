#include "can.h"

void Can_Init(const Can_ConfigType *config)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    CAN_InitTypeDef CAN_InitStructure;
    CAN_FilterInitTypeDef CAN_FilterInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* CAN cell init */
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = DISABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = DISABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = DISABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;

    /* CAN Baudrate = 1MBps*/
    CAN_InitStructure.CAN_SJW = config->SJW;
    CAN_InitStructure.CAN_BS1 = config->BS1;
    CAN_InitStructure.CAN_BS2 = config->BS2;
    CAN_InitStructure.CAN_Prescaler = config->Prescaler;
    CAN_Init(CAN1, &CAN_InitStructure);

    CAN_FilterInitStructure.CAN_FilterNumber = 0;
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitStructure.CAN_FilterIdHigh = config->FilterId >> 16;
    CAN_FilterInitStructure.CAN_FilterIdLow = config->FilterId & 0xFFFF;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = config->FilterMaskId >> 16;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = config->FilterMaskId && 0xFFFF;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);
}

void CAN_DeInit(void)
{
    CAN_DeInit(CAN1);
}

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    CanTxMsg TxMessage;
    TxMessage.StdId = PduInfo->id;
    TxMessage.ExtId = 0x00;
    TxMessage.RTR = CAN_RTR_DATA;
    TxMessage.IDE = CAN_ID_STD;
    TxMessage.DLC = PduInfo->length;

    for (int i = 0; i < PduInfo->length; i++)
    {
        TxMessage.Data[i] = PduInfo->sdu[i];
    }

    if (CAN_Transmit(CAN1, &TxMessage) != CAN_TxStatus_Ok)
    {
        return E_NOT_OK;
    }
    return E_OK;
}

Std_ReturnType Can_Read(Can_HwHandleType Hrh, const Can_PduType *PduInfo)
{
    CanRxMsg RxMessage;

    if (CAN_MessagePending(CAN1, CAN_FIFO0) != 0)
    {
        CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);

        PduInfo->swPduHandle = Hrh;
        PduInfo->length = RxMessage.DLC;
        PduInfo->id = RxMessage.StdId;

        for (int i = 0; i < PduInfo->length; i++)
        {
            RxMessage.Data[i] = PduInfo->sdu[i];
        }
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}

void Can_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    versioninfo->vendorID;
    versioninfo->moduleID;
}

Std_ReturnType Can_SetBaudrate(
    uint8 Controller,
    uint16 BaudRateConfigID)