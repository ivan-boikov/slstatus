/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../slstatus.h"
#include "../util.h"

const char *
vpn_status(const char *unused)
{
	char state[32];

	if (pscanf("/sys/class/net/tun0/operstate", "%s", state) != 1)
		return bprintf("");

	return bprintf("");
}
