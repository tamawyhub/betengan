/*
 * USART_CONFIG.h
 *
 * Created: 4/19/2021 12:04:21 PM
 *  Author: ahmed
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


#define DISABLED 0
#define ENABLED 1

#define MODE_ASYNC 0
#define MODE_SYNC_MASTER  1
#define MODE_SYNC_SLAVE 2
#define MODE_MSPI  3

#define NDATABITS_5 0
#define NDATABITS_6 1
#define NDATABITS_7 2
#define NDATABITS_8 3
#define NDATABITS_9 4

#define PARITY_NONE 0
#define PARITY_EVEN 1
#define PARITY_ODD  2

#define STOP_1 0
#define STOP_2 1

#define USART0_STATE ENABLED
#define USART1_STATE ENABLED
#define USART2_STATE ENABLED
#define USART3_STATE DISABLED

#if USART0_STATE==ENABLED
#define USART0_MODE MODE_ASYNC
#define USART0_RXEN ENABLED
#define USART0_TXEN ENABLED
#define USART0_BAUD 9600
#define USART0_NDATABITS NDATABITS_8
#define USART0_PARITY PARITY_NONE
#define USART0_STOP  STOP_1
#endif

#if USART1_STATE==ENABLED
#define USART1_MODE MODE_ASYNC
#define USART1_RXEN ENABLED
#define USART1_TXEN ENABLED
#define USART1_BAUD 9600
#define USART1_NDATABITS NDATABITS_8
#define USART1_PARITY PARITY_NONE
#define USART1_STOP  STOP_1
#endif

#if USART2_STATE==ENABLED
#define USART2_MODE MODE_ASYNC
#define USART2_RXEN DISABLED
#define USART2_TXEN DISABLED
#define USART2_BAUD 9600
#define USART2_NDATABITS NDATABITS_8
#define USART2_PARITY PARITY_NONE
#define USART2_STOP  STOP_1
#endif

#if USART3_STATE==ENABLED
#define USART3_MODE MODE_ASYNC
#define USART3_RXEN DISABLED
#define USART3_TXEN DISABLED
#define USART3_BAUD 9600
#define USART3_NDATABITS NDATABITS_8
#define USART3_PARITY PARITY_NONE
#define USART3_STOP  STOP_1
#endif


#endif /* USART_CONFIG_H_ */