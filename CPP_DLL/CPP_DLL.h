// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CPPDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CPPDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CPPDLL_EXPORTS
#define CPPDLL_API __declspec(dllexport)
#else
#define CPPDLL_API __declspec(dllimport)
#endif
#include <cstdint>

extern "C" void CPPDLL_API GaussianFilter(BYTE*, int, int, int, int, int);
