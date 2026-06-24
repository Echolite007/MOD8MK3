#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "frequency_response.h"
#include "frequency_response_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1U;

  /*-- Configure pin assignments for ePWM4 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1U; /* Configure GPIO6 as EPWM4A*/

  /*-- Configure pin assignments for ePWM5 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1U; /* Configure GPIO8 as EPWM5A*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;

  //Reassigning TBPRD register of linked ePWM4
  {
    volatile uint32_T tempRead = EPwm4Regs.TBPRD;
    EPwm4Regs.TBPRD = tempRead;
  }

  /* Enable TBCLK after the ePWM configurations */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
  /* Configuring EXTSYNCOUT source selection */
  EALLOW;
  SyncSocRegs.SYNCSELECT.bit.SYNCOUT = 0U;

  /* Configuring ePWM Sync in source selection */
  SyncSocRegs.SYNCSELECT.bit.EPWM4SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM7SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM10SYNCIN = 0U;
  EDIS;
}
