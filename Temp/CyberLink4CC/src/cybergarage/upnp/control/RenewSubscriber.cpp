/******************************************************************
*
*  CyberLink for C++
*
*  Copyright (C) Satoshi Konno 2002-2003
*
*  File: RenewSubscriber.cpp
*
*  Revision:
*
*  07/07/04
*    - first revision
*
******************************************************************/

#include <cybergarage/upnp/ControlPoint.h>

using namespace CyberLink;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constants
////////////////////////////////////////////////

const long RenewSubscriber::INTERVAL= 120;

////////////////////////////////////////////////
//  Thread
////////////////////////////////////////////////
  
void RenewSubscriber::run()  {
  ControlPoint *ctrlp = getControlPoint();
  long renewInterval = RenewSubscriber::INTERVAL * 1000;
  while (isRunnable() == true) {
      if(m_timeUtil.Wait(renewInterval)){
        ctrlp->renewSubscriberService();
      }
    
  }
}

bool RenewSubscriber::stop(){
    m_timeUtil.Stop();
    return Thread::stop();
}