#ifdef SDWSM_EXPORTS
#define SDWSM_API __declspec(dllexport)
#else
#define SDWSM_API __declspec(dllimport)
#endif