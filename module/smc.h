#ifndef __SMC_H__
#define __SMC_H__ 1

#include <IOKit/IOKitLib.h>
#include <Python.h>

kern_return_t open_smc(void);
kern_return_t close_smc(void);
double get_temperature(char *);

#endif // __SMC_H__
