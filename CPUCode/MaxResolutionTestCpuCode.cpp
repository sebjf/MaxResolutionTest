#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{

	printf("Running on DFE. v0.4 single link words\n");

	max_file_t *maxfile = MaxResolutionTest_init();
	max_set_max_runnable_timing_score(maxfile, 16123321);

	max_engine_t *engine = max_load(maxfile, "*");
	max_actions_t* act = max_actions_init(maxfile, NULL);


	max_set_uint64t(act,"MaxVideoSignalKernel","HSyncPolarity",1);
	max_set_uint64t(act,"MaxVideoSignalKernel","VSyncPolarity",1);

	max_set_uint64t(act,"MaxResolutionTestKernel","pattern",0);
	max_set_uint64t(act,"MaxResolutionTestKernel","r",127);
	max_set_uint64t(act,"MaxResolutionTestKernel","g",60);
	max_set_uint64t(act,"MaxResolutionTestKernel","b",0);


	max_run(engine, act);

	printf("Press n key to exit...");

	while(getchar() != 'n')
	{

	}

	max_unload(engine);

	printf("Done.\n");
	return 0;
}
