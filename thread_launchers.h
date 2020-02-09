#pragma once
#include "../global.h"

class thread_launcher_brook
{
public:
	gpu_data_xyz *data;

	thread_launcher_brook(gpu_data *data) : data(data) { };

	void operator()()
	{
		g->a->run_brook(data);
	};

};
