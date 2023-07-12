/*
 * fog.cc
 *
 *  Created on: Jun 21, 2023
 *      Author: w10165927
 */

#include<omnetpp.h>

//Client1

class fog_client1: public cSimpleModule{
    cMessage *cmsg1;
    virtual void initialize();
    virtual void handleMessage(cMessage *cmsg1);
};

Define_Module(fog_client1);

void fog_client1::initialize(){
    EV <<"client1 initialize" <<"\n";
    cmsg1 = new cMessage("RTS");

    scheduleAt(simTime()+dblrand(), cmsg1->dup());
    EV <<"client1 initialize complete" <<"\n";
}
void fog_client1::handleMessage(cMessage *cmsg1)
{
    EV << "client1 handle message initialize"<<"\n";
    cModule *targetc1;
    cmsg1 = new cMessage("RTS");
    targetc1 = getParentModule()->getSubmodule("Server");

    sendDirect(cmsg1, targetc1, "radioIn");
    scheduleAt(simTime()+dblrand(), cmsg1->dup());
}



