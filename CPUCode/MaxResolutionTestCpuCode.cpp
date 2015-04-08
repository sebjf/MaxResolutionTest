#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{

	printf("Running on DFE.\n");

	max_file_t *maxfile = MaxResolutionTest_init();
	max_engine_t *engine = max_load(maxfile, "*");
	max_actions_t* act = max_actions_init(maxfile, NULL);

	max_set_uint64t(act,"MaxVideoSignalKernel","HSyncPolarity",1);
	max_set_uint64t(act,"MaxVideoSignalKernel","VSyncPolarity",1);
	max_set_uint64t(act,"MaxResolutionTestKernel","pattern",0);


	max_run(engine, act);

	printf("Press n key to exit...");

	while(getchar() != 'n')
	{

	}

	max_unload(engine);

	printf("Done.\n");
	return 0;
}
