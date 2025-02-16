#pragma once

#include "esphome/core/hal.h"

namespace esphome {
namespace sx127x {

enum SX127xReg : uint8_t {
  // Common registers
  REG_FIFO = 0x00,
  REG_OP_MODE = 0x01,
  REG_BITRATE_MSB = 0x02,
  REG_BITRATE_LSB = 0x03,
  REG_FDEV_MSB = 0x04,
  REG_FDEV_LSB = 0x05,
  REG_FRF_MSB = 0x06,
  REG_FRF_MID = 0x07,
  REG_FRF_LSB = 0x08,
  REG_PA_CONFIG = 0x09,
  REG_PA_RAMP = 0x0A,
  REG_DIO_MAPPING1 = 0x40,
  REG_DIO_MAPPING2 = 0x41,
  REG_VERSION = 0x42,
  // FSK/OOK registers
  REG_RX_CONFIG = 0x0D,
  REG_RSSI_THRESH = 0x10,
  REG_RX_BW = 0x12,
  REG_OOK_PEAK = 0x14,
  REG_OOK_FIX = 0x15,
  REG_OOK_AVG = 0x16,
  REG_AFC_FEI = 0x1A,
  REG_PREAMBLE_DETECT = 0x1F,
  REG_PREAMBLE_SIZE_MSB = 0x25,
  REG_PREAMBLE_SIZE_LSB = 0x26,
  REG_SYNC_CONFIG = 0x27,
  REG_SYNC_VALUE1 = 0x28,
  REG_SYNC_VALUE2 = 0x29,
  REG_SYNC_VALUE3 = 0x2A,
  REG_SYNC_VALUE4 = 0x2B,
  REG_SYNC_VALUE5 = 0x2C,
  REG_SYNC_VALUE6 = 0x2D,
  REG_SYNC_VALUE7 = 0x2E,
  REG_SYNC_VALUE8 = 0x2F,
  REG_PACKET_CONFIG_1 = 0x30,
  REG_PACKET_CONFIG_2 = 0x31,
  REG_PAYLOAD_LENGTH_LSB = 0x32,
  REG_FIFO_THRESH = 0x35,
  REG_IMAGE_CAL = 0x3B,
  // LoRa registers
  REG_FIFO_ADDR_PTR = 0x0D,
  REG_FIFO_TX_BASE_ADDR = 0x0E,
  REG_FIFO_RX_BASE_ADDR = 0x0F,
  REG_FIFO_RX_CURR_ADDR = 0x10,
  REG_IRQ_FLAGS_MASK = 0x11,
  REG_IRQ_FLAGS = 0x12,
  REG_NB_RX_BYTES = 0x13,
  REG_MODEM_STAT = 0x18,
  REG_PKT_SNR_VALUE = 0x19,
  REG_PKT_RSSI_VALUE = 0x1A,
  REG_RSSI_VALUE = 0x1B,
  REG_HOP_CHANNEL = 0x1C,
  REG_MODEM_CONFIG1 = 0x1D,
  REG_MODEM_CONFIG2 = 0x1E,
  REG_SYMB_TIMEOUT_LSB = 0x1F,
  REG_PREAMBLE_LEN_MSB = 0x20,
  REG_PREAMBLE_LEN_LSB = 0x21,
  REG_PAYLOAD_LENGTH = 0x22,
  REG_HOP_PERIOD = 0x24,
  REG_FIFO_RX_BYTE_ADDR = 0x25,
  REG_MODEM_CONFIG3 = 0x26,
  REG_FEI_MSB = 0x28,
  REG_FEI_MIB = 0x29,
  REG_FEI_LSB = 0x2A,
  REG_DETECT_OPTIMIZE = 0x31,
  REG_INVERT_IQ = 0x33,
  REG_DETECT_THRESHOLD = 0x37,
  REG_SYNC_WORD = 0x39,
};

enum SX127xOpMode : uint8_t {
  MOD_LORA = 0x80,
  ACCESS_FSK_REGS = 0x40,
  ACCESS_LORA_REGS = 0x00,
  MOD_OOK = 0x20,
  MOD_FSK = 0x00,
  ACCESS_LF_REGS = 0x08,
  ACCESS_HF_REGS = 0x00,
  MODE_CAD = 0x07,
  MODE_RX_SINGLE = 0x06,
  MODE_RX = 0x05,
  MODE_RX_FS = 0x04,
  MODE_TX = 0x03,
  MODE_TX_FS = 0x02,
  MODE_STDBY = 0x01,
  MODE_SLEEP = 0x00,
  MODE_MASK = 0x07,
};

enum SX127xPaConfig : uint8_t {
  PA_PIN_BOOST = 0x80,
  PA_PIN_RFO = 0x00,
  PA_MAX_POWER = 0x70,
};

enum SX127xPaRamp : uint8_t {
  CUTOFF_BR_X_2 = 0x40,
  CUTOFF_BR_X_1 = 0x20,
  GAUSSIAN_BT_0_3 = 0x60,
  GAUSSIAN_BT_0_5 = 0x40,
  GAUSSIAN_BT_1_0 = 0x20,
  SHAPING_NONE = 0x00,
  PA_RAMP_10 = 0x0F,
  PA_RAMP_12 = 0x0E,
  PA_RAMP_15 = 0x0D,
  PA_RAMP_20 = 0x0C,
  PA_RAMP_25 = 0x0B,
  PA_RAMP_31 = 0x0A,
  PA_RAMP_40 = 0x09,
  PA_RAMP_50 = 0x08,
  PA_RAMP_62 = 0x07,
  PA_RAMP_100 = 0x06,
  PA_RAMP_125 = 0x05,
  PA_RAMP_250 = 0x04,
  PA_RAMP_500 = 0x03,
  PA_RAMP_1000 = 0x02,
  PA_RAMP_2000 = 0x01,
  PA_RAMP_3400 = 0x00,
};

enum SX127xDioMapping1 : uint8_t {
  DIO0_MAPPING_00 = 0x00,
  DIO0_MAPPING_01 = 0x40,
  DIO0_MAPPING_10 = 0x80,
  DIO0_MAPPING_11 = 0xC0,
};

enum SX127xRxConfig : uint8_t {
  RESTART_ON_COLLISION = 0x80,
  RESTART_NO_LOCK = 0x40,
  RESTART_PLL_LOCK = 0x20,
  AFC_AUTO_ON = 0x10,
  AGC_AUTO_ON = 0x08,
  TRIGGER_NONE = 0x00,
  TRIGGER_RSSI = 0x01,
  TRIGGER_PREAMBLE = 0x06,
  TRIGGER_ALL = 0x07,
};

enum SX127xRxBw : uint8_t {
  RX_BW_2_6 = 0x17,
  RX_BW_3_1 = 0x0F,
  RX_BW_3_9 = 0x07,
  RX_BW_5_2 = 0x16,
  RX_BW_6_3 = 0x0E,
  RX_BW_7_8 = 0x06,
  RX_BW_10_4 = 0x15,
  RX_BW_12_5 = 0x0D,
  RX_BW_15_6 = 0x05,
  RX_BW_20_8 = 0x14,
  RX_BW_25_0 = 0x0C,
  RX_BW_31_3 = 0x04,
  RX_BW_41_7 = 0x13,
  RX_BW_50_0 = 0x0B,
  RX_BW_62_5 = 0x03,
  RX_BW_83_3 = 0x12,
  RX_BW_100_0 = 0x0A,
  RX_BW_125_0 = 0x02,
  RX_BW_166_7 = 0x11,
  RX_BW_200_0 = 0x09,
  RX_BW_250_0 = 0x01,
};

enum SX127xOokPeak : uint8_t {
  BIT_SYNC_ON = 0x20,
  BIT_SYNC_OFF = 0x00,
  OOK_THRESH_AVG = 0x10,
  OOK_THRESH_PEAK = 0x08,
  OOK_THRESH_FIXED = 0x00,
  OOK_THRESH_STEP_6_0 = 0x07,
  OOK_THRESH_STEP_5_0 = 0x06,
  OOK_THRESH_STEP_4_0 = 0x05,
  OOK_THRESH_STEP_3_0 = 0x04,
  OOK_THRESH_STEP_2_0 = 0x03,
  OOK_THRESH_STEP_1_5 = 0x02,
  OOK_THRESH_STEP_1_0 = 0x01,
  OOK_THRESH_STEP_0_5 = 0x00,
};

enum SX127xOokAvg : uint8_t {
  OOK_THRESH_DEC_16 = 0xE0,
  OOK_THRESH_DEC_8 = 0xC0,
  OOK_THRESH_DEC_4 = 0xA0,
  OOK_THRESH_DEC_2 = 0x80,
  OOK_THRESH_DEC_1_8 = 0x60,
  OOK_THRESH_DEC_1_4 = 0x40,
  OOK_THRESH_DEC_1_2 = 0x20,
  OOK_THRESH_DEC_1 = 0x00,
  OOK_AVG_RESERVED = 0x10,
};

enum SX127xAfcFei : uint8_t {
  AFC_AUTO_CLEAR_ON = 0x01,
};

enum SX127xPreambleDetect : uint8_t {
  PREAMBLE_DETECTOR_ON = 0x80,
  PREAMBLE_DETECTOR_OFF = 0x00,
  PREAMBLE_BYTES_1 = 0x00,
  PREAMBLE_BYTES_2 = 0x20,
  PREAMBLE_BYTES_3 = 0x40,
  PREAMBLE_BYTES_SHIFT = 0x05,
};

enum SX127xSyncConfig : uint8_t {
  AUTO_RESTART_PLL_LOCK = 0x80,
  AUTO_RESTART_NO_LOCK = 0x40,
  AUTO_RESTART_OFF = 0x00,
  PREAMBLE_55 = 0x20,
  PREAMBLE_AA = 0x00,
  SYNC_ON = 0x10,
  SYNC_OFF = 0x00,
};

enum SX127xPacketConfig1 : uint8_t {
  CRC_ON = 0x10,
  CRC_OFF = 0x00,
};

enum SX127xPacketConfig2 : uint8_t {
  CONTINUOUS_MODE = 0x00,
  PACKET_MODE = 0x40,
};

enum SX127xFifoThresh : uint8_t {
  TX_START_FIFO_EMPTY = 0x80,
  TX_START_FIFO_LEVEL = 0x00,
};

enum SX127xImageCal : uint8_t {
  AUTO_IMAGE_CAL_ON = 0x80,
  IMAGE_CAL_START = 0x40,
  IMAGE_CAL_RUNNING = 0x20,
  TEMP_CHANGE = 0x08,
  TEMP_THRESHOLD_20C = 0x06,
  TEMP_THRESHOLD_15C = 0x04,
  TEMP_THRESHOLD_10C = 0x02,
  TEMP_THRESHOLD_5C = 0x00,
  TEMP_MONITOR_OFF = 0x01,
  TEMP_MONITOR_ON = 0x00,
};

enum SX127xIrqFlags : uint8_t {
  RX_TIMEOUT = 0x80,
  RX_DONE = 0x40,
  PAYLOAD_CRC_ERROR = 0x20,
  VALID_HEADER = 0x10,
  TX_DONE = 0x08,
  CAD_DONE = 0x04,
  FHSS_CHANGE_CHANNEL = 0x02,
  CAD_DETECTED = 0x01,
};

enum SX127xModemCfg1 : uint8_t {
  BW_7_8 = 0x00,
  BW_10_4 = 0x10,
  BW_15_6 = 0x20,
  BW_20_8 = 0x30,
  BW_31_3 = 0x40,
  BW_41_7 = 0x50,
  BW_62_5 = 0x60,
  BW_125_0 = 0x70,
  BW_250_0 = 0x80,
  BW_500_0 = 0x90,
  CODE_RATE_4_5 = 0x02,
  CODE_RATE_4_6 = 0x04,
  CODE_RATE_4_7 = 0x06,
  CODE_RATE_4_8 = 0x08,
  IMPLICIT_HEADER = 0x01,
  EXPLICIT_HEADER = 0x00,
};

enum SX127xModemCfg2 : uint8_t {
  SPREADING_FACTOR_SHIFT = 0x04,
  TX_CONTINOUS_MODE = 0x08,
  RX_PAYLOAD_CRC_ON = 0x04,
  RX_PAYLOAD_CRC_OFF = 0x00,
};

}  // namespace sx127x
}  // namespace esphome
