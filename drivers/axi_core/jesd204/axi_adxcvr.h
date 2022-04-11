/***************************************************************************//**
 *   @file   axi_adxcvr.h
 *   @brief  Driver for the ADI AXI-ADXCVR Module.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2018(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/
#ifndef AXI_ADXCVR_H_
#define AXI_ADXCVR_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "xilinx_transceiver.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/
/**
 * @struct adxcvr
 * @brief ADI JESD204B/C AXI_ADXCVR Highspeed Transceiver Device structure.
 */
struct adxcvr {
	/** Device Name */
	const char *name;
	/** Base address */
	uint32_t base;
	/** Enable CPLL for the transceiver */
	bool cpll_enable;
	/** TX Enable */
	bool tx_enable;
	/** Enable LPM mode for the transceiver. Otherwise use DFE. */
	bool lpm_enable;
	/** Number of lanes */
	uint32_t num_lanes;
	/** Lane rate in KHz */
	uint32_t lane_rate_khz;
	/** Reference Clock rate */
	uint32_t ref_rate_khz;
	/** Select the PLL reference clock source to be forwarded to the OUTCLK
	 * MUX: 0-CPLL, 3-QPLL0.
	 */
	uint32_t sys_clk_sel;
	/** Controls the OUTCLKSEL multiplexer, controlling what will be
	 * forwarded to OUTCLK pin.
	 */
	uint32_t out_clk_sel;
	/** Structure holding the configuration of the Xilinx Transceiver. */
	struct xilinx_xcvr xlx_xcvr;
};

/**
 * @struct adxcvr
 * @brief ADI JESD204B/C AXI_ADXCVR Highspeed Transceiver Initialization
 *        structure.
 */
struct adxcvr_init {
	/** Device Name */
	const char *name;
	/** Base address */
	uint32_t base;
	/** Select the PLL reference clock source to be forwarded to the OUTCLK
	 * MUX: 0-CPLL, 3-QPLL0.
	 */
	uint32_t sys_clk_sel;
	/** Controls the OUTCLKSEL multiplexer, controlling what will be
	 * forwarded to OUTCLK pin.
	 */
	uint32_t out_clk_sel;
	/** Enable CPLL for the transceiver */
	bool cpll_enable;
	/** Enable LPM mode for the transceiver. Otherwise use DFE. */
	bool lpm_enable;
	/** Lane rate in KHz */
	uint32_t lane_rate_khz;
	/** Reference Clock rate */
	uint32_t ref_rate_khz;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
/** AXI ADXCVR DPR Port Read */
int32_t adxcvr_drp_read(struct adxcvr *xcvr,
			uint32_t drp_port,
			uint32_t reg,
			uint32_t *val);
/** AXI ADXCVR DPR Port Write */
int32_t adxcvr_drp_write(struct adxcvr *xcvr,
			 uint32_t drp_port,
			 uint32_t reg,
			 uint32_t val);
/** AXI ADXCVRS Status Read */
int32_t adxcvr_status_error(struct adxcvr *xcvr);
/** AXI ADXCVR Clock Enable */
int32_t adxcvr_clk_enable(struct adxcvr *xcvr);
/** AXI ADXCVR Clock Disable */
int32_t adxcvr_clk_disable(struct adxcvr *xcvr);
/** AXI ADXCVR Device Initialization */
int32_t adxcvr_init(struct adxcvr **ad_xcvr,
		    const struct adxcvr_init *init);
/** AXI ADXCVR Resources Deallocation */
int32_t adxcvr_remove(struct adxcvr *xcvr);
/** AXI ADXCVR Clock Set Rate */
int32_t adxcvr_clk_set_rate(struct adxcvr *xcvr,
			    uint32_t rate,
			    uint32_t parent_rate);
/** AXI ADXCVR Write */
int32_t adxcvr_write(struct adxcvr *xcvr, uint32_t reg_addr, uint32_t reg_val);
/** AXI ADXCVR Read */
int32_t adxcvr_read(struct adxcvr *xcvr, uint32_t reg_addr, uint32_t *reg_val);
#endif
