//******************
// CLASS: UART
//
// DESCRIPTION:
//  Created on: April 28th, 2020, by Carlos Estay
//  uart class for STM32L476
//
// MODIFIED: 5/20/2022, by CarlosEstay
//
// FILE: uart.h
//

#ifndef UART_H
#define UART_H

namespace UartSpace
{
  const uint32_t nullPort = 0;
  const uint32_t NEW_LINE_MODE_TIMEOUT = 2000;
  const uint32_t TIMEOUT_MODE_TIMEOUT = 10;
  const uint32_t COMMAND_MODE_TIMEOUT = 6000;
  const uint32_t NUMBER_OF_COM_PORTS = 3;

  enum UART_Id
  {
    LPUART_1 = LPUART1_BASE,
    USART_1 = USART1_BASE,      //Outside Communication
    USART_2 = USART2_BASE,      
    USART_3 = USART3_BASE,
    UART_4 = UART4_BASE,
    UART_5 = UART5_BASE
  };

  enum BaudRate
  {
      B_1200 = 1200,
      B_2400 = 2400,
      B_4800 = 4800,
      B_9600 = 9600,
      B_19200 = 19200,
      B_38400 = 38400,
      B_57600 = 57600,
      B_115200 = 115200,
      B_230400 = 230400,
      B_460800 = 460800,
      B_921600 = 921600  
  };

  enum BufferType
  {
    Send,
    Receive,
  };

  enum CommandMode
  {
    NewLine,
    Timeout,
    Manual  
  };
  
};




#include <ctype.h>
using namespace UartSpace;

class UART
{
public:
  UART();
  ~UART();
  void Init(UART_Id id, BaudRate br);
  void WriteByte(uint8_t byte);
  void WriteString(const char* str);
  void WriteString(uint8_t* str);
//  void attachBufferArray(uint8_t* buffer, BufferType type);
//  void isr();
//  void addToRx(uint8_t data);
//  void setCommandMode(CommandMode mode);
//  CommandMode getCommnadMode();
//  void setTimeOut(uint32_t timeOut);
//  bool IsCmdComplete();
//  void setLocked(bool option);
//  bool getLocked();
//  BufferHandler* getTxBuffer();
//  BufferHandler* getRxBuffer();
//  void flushTx();
//  void setBridge(UART* port);
//  void clearBridge();
//  void setBridgeEnable(bool option);
//  UART* bridgedTo();
//  bool isBridged();
//  void writeString(uint8_t* str, uint16_t length); 
  
private:
//  void tx();    
  UART_Id m_UartId;
  BaudRate m_BaudRate;
  USART_TypeDef* p_Uart;  
//  BufferHandler m_TxBuffer;
//  BufferHandler m_RxBuffer;  
//  uint8_t m_RxB[TMP_BUFFER_SIZE];
//  
//  bool m_CmdComplete;
//  bool dmaEnabled;
//  CommandMode m_CommandMode;
//  Stopwatch m_Timer;
//  uint32_t m_Timeout;
//  
//  UART* m_BridgedTo;
//  bool m_IsBridged;
//  bool m_Locked;
};

#endif /* UART_H */



