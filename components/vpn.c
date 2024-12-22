/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <unistd.h>

#include "../slstatus.h"
#include "../util.h"

const char *
vpn_status(const char *path)
{
	if (access(path, F_OK) == 0) {
		return bprintf("");
	} else {
		return bprintf("");
	}
}
