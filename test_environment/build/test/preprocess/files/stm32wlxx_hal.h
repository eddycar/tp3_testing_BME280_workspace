typedef enum

{

  HAL_OK = 0x00,

  HAL_ERROR = 0x01,

  HAL_BUSY = 0x02,

  HAL_TIMEOUT = 0x03

} HAL_StatusTypeDef;









typedef struct

{

  volatile uint32_t CR1;

  volatile uint32_t CR2;

  volatile uint32_t OAR1;

  volatile uint32_t OAR2;

  volatile uint32_t TIMINGR;

  volatile uint32_t TIMEOUTR;

  volatile uint32_t ISR;

  volatile uint32_t ICR;

  volatile uint32_t PECR;

  volatile uint32_t RXDR;

  volatile uint32_t TXDR;

} I2C_TypeDef;











typedef struct

{

  uint32_t Timing;







  uint32_t OwnAddress1;





  uint32_t AddressingMode;





  uint32_t DualAddressMode;





  uint32_t OwnAddress2;





  uint32_t OwnAddress2Masks;







  uint32_t GeneralCallMode;





  uint32_t NoStretchMode;





} I2C_InitTypeDef;









typedef enum

{

  HAL_UNLOCKED = 0x00,

  HAL_LOCKED = 0x01

} HAL_LockTypeDef;

typedef enum

{

  HAL_I2C_STATE_RESET = 0x00U,

  HAL_I2C_STATE_READY = 0x20U,

  HAL_I2C_STATE_BUSY = 0x24U,

  HAL_I2C_STATE_BUSY_TX = 0x21U,

  HAL_I2C_STATE_BUSY_RX = 0x22U,

  HAL_I2C_STATE_LISTEN = 0x28U,

  HAL_I2C_STATE_BUSY_TX_LISTEN = 0x29U,



  HAL_I2C_STATE_BUSY_RX_LISTEN = 0x2AU,



  HAL_I2C_STATE_ABORT = 0x60U,

  HAL_I2C_STATE_TIMEOUT = 0xA0U,

  HAL_I2C_STATE_ERROR = 0xE0U



} HAL_I2C_StateTypeDef;

typedef enum

{

  HAL_I2C_MODE_NONE = 0x00U,

  HAL_I2C_MODE_MASTER = 0x10U,

  HAL_I2C_MODE_SLAVE = 0x20U,

  HAL_I2C_MODE_MEM = 0x40U



} HAL_I2C_ModeTypeDef;











typedef struct __I2C_HandleTypeDef

{

  I2C_TypeDef *Instance;



  I2C_InitTypeDef Init;



  uint8_t *pBuffPtr;



  uint16_t XferSize;



  volatile uint16_t XferCount;



  volatile uint32_t XferOptions;





  volatile uint32_t PreviousState;



  HAL_StatusTypeDef(*XferISR)(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);





  HAL_LockTypeDef Lock;



  volatile HAL_I2C_StateTypeDef State;



  volatile HAL_I2C_ModeTypeDef Mode;



  volatile uint32_t ErrorCode;



  volatile uint32_t AddrEventCount;



  volatile uint32_t Devaddress;



  volatile uint32_t Memaddress;



} I2C_HandleTypeDef;





HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,

                                          uint16_t Size, uint32_t Timeout);

HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,

                                         uint16_t Size, uint32_t Timeout);
