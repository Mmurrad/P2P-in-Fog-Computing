/*
 * client.cc
 *
 *  Created on: Jun 14, 2023
 *      Author: w10165927
 */
// HI
#include<omnetpp.h>

std::string resource_type[6] = {"a", "b", "c", "d", "e", "f"};

char res_type = 'b';
int resource_code = 17;
int logical_add = 201;
int c_count=0;
std::string message= "hi";


//Client

class client: public cSimpleModule{
    cMessage *cmsg;
    int limit;
    virtual void initialize();
    public: void handleConditon(char res_type);
    virtual void handleMessage(cMessage *cmsg);
};

Define_Module(client);

void client::initialize(){
    EV <<"client initialize" <<"\n";
    cmsg = new cMessage("client_message");
    limit = par("lmt");

    scheduleAt(simTime()+dblrand(), cmsg->dup());
    EV <<"client initialize complete" <<"\n";
}

void client::handleMessage(cMessage *cmsg)
{
    EV << "client handle message initialize"<<"\n";
    cModule *targetc;
    cmsg = new cMessage("client_message");

    if(c_count==0)
    {
        if(res_type == 'a')
        {
            if(logical_add == 101 && (resource_code == 1 ||  2||  3|| 4|| 5))
            {
                targetc = getParentModule()->getSubmodule("Fog");
            }
            else if(logical_add == 102 && (resource_code == 6||  7||  8|| 9|| 10))
            {
                targetc = getParentModule()->getSubmodule("Fog1");
            }
            else if(logical_add == 103 && (resource_code == 11||  12||  13|| 14|| 15))
            {
                targetc = getParentModule()->getSubmodule("Fog2");
            }
            else
            {
                targetc = getParentModule()->getSubmodule("Server");
            }
        }
        else if(res_type == 'b')
        {
            if(logical_add == 201 && (resource_code == 16||  17||  18|| 19|| 20))
            {
                targetc = getParentModule()->getSubmodule("Fog3");
            }
            else if(logical_add == 202 && (resource_code == 21 ||  22||  23|| 24|| 25))
            {
                targetc = getParentModule()->getSubmodule("Fog4");
            }
            else if(logical_add == 203 && (resource_code == 26||  27||  28|| 29|| 30))
            {
                targetc = getParentModule()->getSubmodule("Fog5");
            }
            else
            {
                targetc = getParentModule()->getSubmodule("Server");
            }
        }
        c_count++;
    }
    else
    {
        targetc = getParentModule()->getSubmodule("Client");
    }
    sendDirect(cmsg, targetc, "radioIn");
    scheduleAt(simTime()+dblrand(), cmsg->dup());
}


//Fog

class fog: public cSimpleModule{
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(fog);

void fog::initialize(){
    EV <<"Fog initialize" <<"\n";
    msg = new cMessage("fog_RTS");

    scheduleAt(simTime()+dblrand(), msg->dup());
    EV <<"Fog initialize complete" <<"\n";
}
void fog::handleMessage(cMessage *msg)
{
    EV << "Fog handle message initialize"<<"\n";
    cModule *target;
    msg = new cMessage("fog_RTS");
    target = getParentModule()->getSubmodule("Fog1");

    sendDirect(msg, target, "radioIn");
    scheduleAt(simTime()+dblrand(), msg->dup());
}

//Fog1

class fog1: public cSimpleModule{
    cMessage *msg1;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg1);
};

Define_Module(fog1);

void fog1::initialize(){
    EV <<"Fog1 initialize" <<"\n";
    msg1 = new cMessage("fog1_RTS");

    scheduleAt(simTime()+dblrand(), msg1->dup());
    EV <<"Fog1 initialize complete" <<"\n";
}
void fog1::handleMessage(cMessage *msg1)
{
    EV << "Fog1 handle message initialize"<<"\n";
    cModule *target1;
    msg1 = new cMessage("fog1_RTS");
    target1 = getParentModule()->getSubmodule("Fog2");

    sendDirect(msg1, target1, "radioIn");
    scheduleAt(simTime()+dblrand(), msg1->dup());
}

//Fog2
class fog2: public cSimpleModule{
    cMessage *msg2;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg2);
};

Define_Module(fog2);

void fog2::initialize(){
    EV <<"Fog2 initialize" <<"\n";
    msg2 = new cMessage("fog2_RTS");

    scheduleAt(simTime()+dblrand(), msg2->dup());
    EV <<"Fog2 initialize complete" <<"\n";
}
void fog2::handleMessage(cMessage *msg2)
{
    EV << "Fog2 handle message initialize"<<"\n";
    cModule *target2;
    msg2 = new cMessage("fog2_RTS");
    target2 = getParentModule()->getSubmodule("Server");

    sendDirect(msg2, target2, "radioIn");
    scheduleAt(simTime()+dblrand(), msg2->dup());
}


//Fog3

class fog3: public cSimpleModule{
    cMessage *msg3;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg3);
};

Define_Module(fog3);

void fog3::initialize(){
    EV <<"Fog3 initialize" <<"\n";
    msg3 = new cMessage("fog3_RTS");

    scheduleAt(simTime()+dblrand(), msg3->dup());
    EV <<"Fog3 initialize complete" <<"\n";
}
void fog3::handleMessage(cMessage *msg3)
{
    EV << "Fog3 handle message initialize"<<"\n";
    cModule *target3;
    msg3 = new cMessage("fog3_RTS");
    target3 = getParentModule()->getSubmodule("Fog4");

    sendDirect(msg3, target3, "radioIn");
    scheduleAt(simTime()+dblrand(), msg3->dup());
}

//Fog4

class fog4: public cSimpleModule{
    cMessage *msg4;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg4);
};

Define_Module(fog4);

void fog4::initialize(){
    EV <<"Fog4 initialize" <<"\n";
    msg4 = new cMessage("fog4_RTS");

    scheduleAt(simTime()+dblrand(), msg4->dup());
    EV <<"Fog4 initialize complete" <<"\n";
}
void fog4::handleMessage(cMessage *msg4)
{
    EV << "Fog4 handle message initialize"<<"\n";
    cModule *target4;
    msg4 = new cMessage("fog4_RTS");
    target4 = getParentModule()->getSubmodule("Fog5");

    sendDirect(msg4, target4, "radioIn");
    scheduleAt(simTime()+dblrand(), msg4->dup());
}

//Fog5

class fog5: public cSimpleModule{
    cMessage *msg5;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg5);
};

Define_Module(fog5);

void fog5::initialize(){
    EV <<"Fog5 initialize" <<"\n";
    msg5 = new cMessage("fog5_RTS");

    scheduleAt(simTime()+dblrand(), msg5->dup());
    EV <<"Fog5 initialize complete" <<"\n";
}
void fog5::handleMessage(cMessage *msg5)
{
    EV << "Fog5 handle message initialize"<<"\n";
    cModule *target5;
    msg5 = new cMessage("fog5_RTS");
    target5 = getParentModule()->getSubmodule("Server");

    sendDirect(msg5, target5, "radioIn");
    scheduleAt(simTime()+dblrand(), msg5->dup());
}

//int main()
//{
//    client s;
//    s.handleConditon('a');
//    return 0;
//}

