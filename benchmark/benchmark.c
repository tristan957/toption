#include <string.h>

#include <glib.h>

#include "toption/toption.h"

#define ITERATIONS 10000

int
main(void)
{
	GTimer *timer = g_timer_new();
	g_timer_stop(timer);

	g_timer_start(timer);
	for (int i = 0; i < ITERATIONS; i++) {
		g_autofree int *x = g_malloc(sizeof(int));
		memcpy(x, &i, sizeof(int));
		g_assert(i == *x);
	}
	g_timer_stop(timer);

	gdouble elapsed = g_timer_elapsed(timer, NULL);
	g_print("Using a pointer as an optional type: %f\n", elapsed);

	g_timer_start(timer);
	for (int i = 0; i < ITERATIONS; i++) {
		TOption *o = t_option_from(i);
		g_assert(i == t_option_get_int(o));
		t_option_unref(o);
	}
	g_timer_stop(timer);

	elapsed = g_timer_elapsed(timer, NULL);
	g_print("Using a TOption as an optional type: %f\n", elapsed);

	return 0;
}
