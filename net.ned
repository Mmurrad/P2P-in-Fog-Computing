//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package testproject;
//
// TODO documentation
//
simple server
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//

//
// TODO documentation
//
simple fog
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

simple fog1
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}
simple fog2
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
simple fog3
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
simple fog4
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
simple fog5
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}

simple client
{
    parameters:
        int lmt @display("i=device/wifilaptop;p=230,40") = default(2);
    gates:
        input radioIn @directIn;
}

//simple fog_client1
//{
//    @display("i=device/wifilaptop;p=230,40");
//    gates:
//        input radioIn @directIn;
//}

//
// TODO documentation
//
network Network
{
    @display("bgb=1182,429");
    submodules:
        Server: server {
            @display("p=523,45");
        }
        Fog: fog {
            @display("p=875,197");
        }
        Fog1: fog1 {
            @display("p=789,126");
        }
        Fog2: fog2 {
            @display("p=662,197");
        }
        Fog3: fog3 {
            @display("p=342,208");
        }
        Fog4: fog4 {
            @display("p=98,206");
        }
        Fog5: fog5 {
            @display("p=227,126");
        }
        Client: client {
            @display("p=779,341");
        }
}

