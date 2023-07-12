/*
 * server.cc
 *
 *  Created on: Jun 14, 2023
 *      Author: w10165927
 */
#include<omnetpp.h>
int count =0;
class server: public cSimpleModule{
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};
Define_Module(server);
void server::initialize(){

}
void server::handleMessage(cMessage *msg)
{
    if(count ==0)
    {
        msg =  new cMessage("CTS");
        cModule *target5 =getParentModule()->getSubmodule("Client");
        sendDirect(msg, target5, "radioIn");
        count++;
    }

//    if(count ==0)
//    {
//        cModule *target = getParentModule()->getSubmodule("Fog");
//        sendDirect(msg, target, "radioIn");
//        count++;
//    }
//    else if(count==1){
//        cModule *target1 =getParentModule()->getSubmodule("Fog1");
//        sendDirect(msg, target1, "radioIn");
//        count++;
//    }
//    else if(count==2)
//    {
//        cModule *target2 =getParentModule()->getSubmodule("Fog2");
//        sendDirect(msg, target2, "radioIn");
//        count++;
//    }
//    else if(count == 3)
//    {
//        cModule *target3 =getParentModule()->getSubmodule("Fog3");
//        sendDirect(msg, target3, "radioIn");
//        count++;
//    }
//    else if(count == 4)
//    {
//        cModule *target4 =getParentModule()->getSubmodule("Fog4");
//        sendDirect(msg, target4, "radioIn");
//        count++;
//    }
//    else if(count == 5)
//    {
//        cModule *target5 =getParentModule()->getSubmodule("Fog5");
//        sendDirect(msg, target5, "radioIn");
//        count=0;
//    }
};




