/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/gpio.h>

/* Early pad configuration */
static const struct pad_config uart_gpio_table[] = {
	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1), /* UART2_RXD */
	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1), /* UART2_TXD */
};

void bootblock_mainboard_early_init(void)
{
	if (CONFIG(INTEL_LPSS_UART_FOR_CONSOLE))
		gpio_configure_pads(uart_gpio_table, ARRAY_SIZE(uart_gpio_table));
}
