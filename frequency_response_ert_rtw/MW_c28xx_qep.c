#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "frequency_response.h"
#include "frequency_response_private.h"

void config_QEP_eQEP2(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint)
{
  EALLOW;
  CpuSysRegs.PCLKCR4.bit.EQEP2 = 1U;
  EDIS;
  EALLOW;                              /* Enable EALLOW*/

  /* Enable internal pull-up for the selected pins */
  GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0U; /* Enable pull-up on GPIO54 (EQEP2A)*/
  GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0U; /* Enable pull-up on GPIO55 (EQEP2B)*/
  GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0U; /* Enable pull-up on GPIO57 (EQEP2I)*/

  /* Configure eQEP-2 pins using GPIO regs*/
  GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1U;/* Configure GPIO54 as EQEP2A*/
  GpioCtrlRegs.GPBGMUX2.bit.GPIO54 = 1U;
  GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1U;/* Configure GPIO55 as EQEP2B*/
  GpioCtrlRegs.GPBGMUX2.bit.GPIO55 = 1U;
  GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 1U;/* Configure GPIO57 as EQEP2I*/
  GpioCtrlRegs.GPBGMUX2.bit.GPIO57 = 1U;
  EDIS;
  EQep2Regs.QPOSINIT = pcInitialvalue; /*eQEP Initialization Position Count*/
  EQep2Regs.QPOSMAX = pcmaximumvalue;  /*eQEP Maximum Position Count*/
  EQep2Regs.QUPRD = unittimerperiod;   /*eQEP Unit Period Register*/
  EQep2Regs.QWDPRD = watchdogtimer;    /*eQEP watchdog timer Register*/
  EQep2Regs.QDECCTL.all = qdecctl;   /*eQEP Decoder Control (QDECCTL) Register*/
  EQep2Regs.QEPCTL.all = qepctl;       /*eQEP Control (QEPCTL) Register*/
  EQep2Regs.QPOSCTL.all = qposctl;
                            /*eQEP Position-compare Control (QPOSCTL) Register*/
  EQep2Regs.QCAPCTL.all = qcapctl;   /*eQEP Capture Control (QCAPCTL) Register*/
  EQep2Regs.QEPCTL.bit.FREE_SOFT = 2U; /*unaffected by emulation suspend*/
  EQep2Regs.QPOSCMP = comparevalue;    /*eQEP Position-compare*/
  EQep2Regs.QEINT.all = qeint;         /*eQEPx interrupt enable register*/
}
