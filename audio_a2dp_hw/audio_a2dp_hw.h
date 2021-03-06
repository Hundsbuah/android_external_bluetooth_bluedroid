/******************************************************************************
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *  Copyright (c) 2013, Linux Foundation. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/*****************************************************************************
 *
 *  Filename:      audio_a2dp_hw.h
 *
 *  Description:
 *
 *****************************************************************************/

#ifndef AUDIO_A2DP_HW_H
#define AUDIO_A2DP_HW_H

/*****************************************************************************
**  Constants & Macros
******************************************************************************/

#define A2DP_AUDIO_HARDWARE_INTERFACE "audio.a2dp"
#define A2DP_CTRL_PATH "/data/misc/bluedroid/.a2dp_ctrl"
#define A2DP_DATA_PATH "/data/misc/bluedroid/.a2dp_data"

#define AUDIO_STREAM_DEFAULT_RATE          44100
#define AUDIO_STREAM_DEFAULT_FORMAT        AUDIO_FORMAT_PCM_16_BIT
#define AUDIO_STREAM_DEFAULT_CHANNEL_FLAG  AUDIO_CHANNEL_OUT_STEREO
#define AUDIO_STREAM_OUTPUT_BUFFER_SZ      (8*512)
#define AUDIO_SKT_DISCONNECTED             (-1)

typedef enum {
    A2DP_CTRL_CMD_NONE,
    A2DP_CTRL_CMD_CHECK_READY,
    A2DP_CTRL_CMD_CHECK_STREAM_STARTED,
    A2DP_CTRL_CMD_START,
    A2DP_CTRL_CMD_STOP,
    A2DP_CTRL_CMD_SUSPEND,
    A2DP_CTRL_GET_AUDIO_CONFIG,
    A2DP_CTRL_SET_AUDIO_CONFIG,
} tA2DP_CTRL_CMD;

typedef enum {
    A2DP_CTRL_ACK_SUCCESS,
    A2DP_CTRL_ACK_FAILURE,
    A2DP_CTRL_ACK_INCALL_FAILURE /* Failure when in Call*/
} tA2DP_CTRL_ACK;


/*****************************************************************************
**  Type definitions for callback functions
******************************************************************************/

/*****************************************************************************
**  Type definitions and return values
******************************************************************************/

/*****************************************************************************
**  Extern variables and functions
******************************************************************************/

/*****************************************************************************
**  Functions
******************************************************************************/

inline bool is_supported_sample_rate(uint32_t sample_rate) {
    return sample_rate == 8000  || sample_rate == 12000 || sample_rate == 16000 ||
           sample_rate == 24000 || sample_rate == 32000 || sample_rate == 48000 ||
           sample_rate == 11025 || sample_rate == 22050 || sample_rate == 44100;
}

inline bool is_supported_channel_count(uint8_t channel_count) {
    return channel_count == 1 || channel_count == 2;
}

inline bool is_supported_bit_depth(uint8_t bit_per_sample) {
    return bit_per_sample == 16;
}

/*****************************************************************************
**
** Function
**
** Description
**
** Returns
**
******************************************************************************/

#endif /* A2DP_AUDIO_HW_H */

