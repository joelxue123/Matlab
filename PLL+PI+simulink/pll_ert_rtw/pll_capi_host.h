#ifndef RTW_HEADER_pll_cap_host_h__
#define RTW_HEADER_pll_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} pll_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C"
{

#endif

  void pll_host_InitializeDataMapInfo(pll_host_DataMapInfo_T *dataMap, const
    char *path);

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_pll_cap_host_h__ */

/* EOF: pll_capi_host.h */
