/*
  FILE: uart.cpp
  Created on: April 28th, 2020, by Carlos Estay
  uart source file for STM32L476
  MODIFIED: 5/20/2022, by CarlosEstay
*/
#include "includes.h"

//-------------------------------------------------------------------Constructor
UART::UART()
{
//  dmaEnabled = false;
//  m_BridgedTo = (UART*)nullPort;//Have to cast to Avoid error
//  m_IsBridged = false;
//  m_Timeout = COMMAND_MODE_TIMEOUT; //This is to assure the timer is not zero by accident
}
//--------------------------------------------------------------------Destructor
UART::~UART()
{
  //dmaEnabled = false;
}
//--------------------------------------------------------------------------Init 
void UART::Init(UART_Id id, BaudRate br)
{
  m_UartId = id;                                //save UART enumeration
  m_BaudRate = br;
  p_Uart = (USART_TypeDef *) m_UartId;          //Get ctual UART peripheral address
  
  //Disable USART/UART to configure it
  p_Uart->CR1 &= ~(USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
  p_Uart->BRR = SYSTEM_CLOCK / m_BaudRate;      //Set Baud Rate
  p_Uart->CR3 |= USART_CR3_OVRDIS;              //Disable Overrun
 //Enable USART/UART, Tx and Rx
  p_Uart->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
  
//  //Initialize buffers for Uart
//  m_TxBuffer.init(COM_BUFFER_SIZE);
//  m_RxBuffer.init(COM_BUFFER_SIZE);
//    
//  //Attach receiving buffer
//  attachBufferArray(m_RxB, BufferType::Receive);
}
//--------------------------------------------------------------------Write Byte
void UART::WriteByte(uint8_t byte)
{
  while(!(p_Uart->ISR&USART_ISR_TXE));
  p_Uart->TDR = byte;  
}
//--------------------------------------------------Write null terminated string 
void UART::WriteString(const char* str)
{
  while(*str != 0)
  {
    WriteByte(*str++);
  }
}
//----------------------------------------Write null terminated characters array
void UART::WriteString(uint8_t* str)
{
  WriteString((const char*)str);
}
////-------------------------------------------------Attach a Buffer Array to Uart
//void UART::attachBufferArray(uint8_t* buffer, BufferType type)
//{
//  if(type == BufferType::Receive)
//  {
//    m_RxBuffer.setBufferArray(buffer);
//  }
//  else
//  {
//    m_TxBuffer.setBufferArray(buffer);
//  }
//}
////---------------------------------------------------------------------------ISR
//void UART::isr()
//{
//  uint32_t IIR = p_Uart->ISR;
//  
//  if(IIR & USART_ISR_RXNE)      //Rx
//  {
//    uint8_t ch = p_Uart->RDR;
//    addToRx(ch);
//  }
//  if(IIR & USART_ISR_FE)
//    p_Uart->ICR |= USART_ICR_FECF;
//  if(IIR & USART_ISR_ORE)
//    p_Uart->ICR |= USART_ICR_ORECF;  
//}
////--------------------------------------------------------------Add to RX Buffer
//void UART::addToRx(uint8_t data)
//{
//  m_Timer.isRunning()?m_Timer.reset():m_Timer.start();
//  switch(m_CommandMode)
//  {
//    
//  case CommandMode::Manual:
//    data = toupper(data);
//    if(data == '\b')
//    {
//      m_RxBuffer.backSpace();
//      writeString("\b \b\0");
//    }
//    else if(data == '\r')
//    {
//      m_CmdComplete = true;
//      writeString("\r\n\0");
//    }
//    else
//    {
//      writeByte(data);
//      m_RxBuffer.add<uint8_t>(data);
//    }
//    break;
//    
//  case CommandMode::NewLine:
//    if(data == '\r')
//    {
//      m_CmdComplete = true;
//      //if(cts) cts->clear();  //FLow control not yet implemented
//    }
//    else
//      m_RxBuffer.add<uint8_t>(data);
//    break;
//    
//  case CommandMode::Timeout:
//    m_RxBuffer.add<uint8_t>(data);
//    break;
//  } 
//}
////--------------------------------------------------------------Set Command Mode
//void UART::setCommandMode(CommandMode mode)
//{
//   m_CommandMode = mode;
//   
//   switch(m_CommandMode)
//   {
//      case CommandMode::NewLine:
//        m_Timeout = NEW_LINE_MODE_TIMEOUT;
//        break;
//      case CommandMode::Timeout:
//        m_Timeout = TIMEOUT_MODE_TIMEOUT;
//        break;
//      case CommandMode::Manual:
//        m_Timeout = COMMAND_MODE_TIMEOUT;
//    break;     
//   }
//}
////--------------------------------------------------------------Get Command Mode
//CommandMode UART::getCommnadMode()
//{
//  return m_CommandMode;
//}
////------------------------------------------------------------------Set Time Out
//void UART::setTimeOut(uint32_t timeOut)
//{
//  m_Timeout = timeOut;
//}
////--------------------------------------------------------Command complete check
//bool UART::IsCmdComplete()
//{
//  if(m_Timer.read() >= m_Timeout)
//  {
//    switch(m_CommandMode)
//    {
//    case CommandMode::Manual:
//      writeString("COMMAND MODE TIME OUT\r\n\0");
//      setCommandMode(CommandMode::NewLine);
//    case CommandMode::NewLine:
//      m_Timer.stopAndReset();
//      m_RxBuffer.clear();
//      break;
//    case CommandMode::Timeout:
//      m_Timer.stopAndReset();
//      m_CmdComplete = true;
//      break;
//    }
//  }
//  
//  if(m_CmdComplete)
//  {
//    m_CmdComplete = false;
//    return true;
//  }
//  return false;  
//}
////------------------------------------------------------------------------------
//void UART::setLocked(bool option)
//{
//  m_Locked = option;
//}
////------------------------------------------------------------------------------
//bool UART::getLocked()
//{
//  return m_Locked;
//}
//
////------------------------------------------------------------------------------
//BufferHandler* UART::getTxBuffer()
//{
//  return &m_TxBuffer;
//}
////------------------------------------------------------------------------------
//BufferHandler* UART::getRxBuffer()
//{
//  return &m_RxBuffer;
//}
////----------------------------------------------------------------------Flush Tx
//void UART::flushTx()
//{
//  if(!dmaEnabled)
//  {
//    writeString(m_TxBuffer.getPointer(0),m_TxBuffer.getLength());    
//  }
//
//  else
//  {
//    tx();      
//  }
//}
////----------------------------------------------Bridge port to other serial port
//void UART::setBridge(UART* port)
//{
//  m_BridgedTo = port;
//  setBridgeEnable(true);
//}
////-------------------------------------------------break port bridge if existing
//void UART::clearBridge()
//{
//  m_BridgedTo = (UART*)nullPort;//Have to cast to Avoid error
//  setBridgeEnable(false);
//}
////----------------------------------------------------Enable/DIsable port bridge
//void UART::setBridgeEnable(bool option)
//{
//  if(option)
//  {
//    m_IsBridged = true;   
//  }
//  else
//  {
//    m_IsBridged = false;
//  }
//}
////------------------------------------------------------------------------------
//UART* UART::bridgedTo()
//{
//  return m_BridgedTo;
//}
////------------------------------------------------------------------------------
//bool UART::isBridged()
//{
//  return m_IsBridged;
//}
////------------------------------------------------------------------------------
//void UART::writeString(uint8_t* str, uint16_t length)
//{
//  for(uint32_t i=0;i<length;i++)
//  {
//    while(!(p_Uart->ISR&USART_ISR_TXE));
//    p_Uart->TDR = str[i];
//  }
//  //m_TxBuffer.clear();  //This will cause hard fault(null) if TxBuffer Array is not added to the class 
//}
////**********************PRIVATE/PROTECTED METHODS*******************************
//void UART::tx()
//{
//  // DMA mode transmission goes here
//}
////---------------------------------------------------------DMA mode transmission



