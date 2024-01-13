/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../slstatus.h"
#include "../util.h"

const char *
mpd_track(const char *path)
{
	FILE *fp;
	const unsigned short N = 128;
	char track[N];
	char state[16];

	if (!(fp = fopen(path, "r")))
		return NULL;

	if (fgets(track, N, fp) == NULL || fscanf(fp, "%s", state) != 1)
	{
		fclose(fp);
		return NULL;
	}

	fclose(fp);

	// otherwise statusbar will show a weird symbol
	track[strlen(track)-1] = '\0';

	if (strcmp(state, "[playing]") == 0)
		return bprintf("%s ", track);

	if (strcmp(state, "[paused]") == 0)
		return bprintf("%s ", track);

	return NULL;
}
