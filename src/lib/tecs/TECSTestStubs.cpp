// Minimal stubs satisfying TECS.cpp link requirements in unit test builds.
// PX4_WARN calls in TECS.cpp are only reached on invalid dt; they are never
// triggered by the closed-loop tests which always pass dt = 0.02 s.

#include <cstdarg>
#include <cstdio>

extern "C" __attribute__((visibility("default")))
void px4_log_modulename(int /*level*/, const char * /*module*/, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}
