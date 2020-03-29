#include "ros/ros.h"
#include "esercizio3/service.h"
#include "std_msgs/Int32.h"
#include <iostream>


using namespace std;

class valore {

	public :
	int one;
	int two;

};

            
int main (int argc, char **argv){

 ros::init(argc, argv, "nodo1");
 ros::NodeHandle n;
 ros::Rate loop_rate (10);
 ros::ServiceClient client= n.serviceClient<esercizio3::service>("service");

while (ros::ok()) {
 esercizio3::service srv;

std::stringstream ss;

valore number;

cout <<"Ecco i due numeri casuali : " <<endl;

number.one= rand()% 100 +1;
ss<<number.one;
srv.request.numbera=ss.str();

cout <<" First number  ----> " <<number.one <<endl;  
ss.str("");


number.two= rand()% 100 +1;

ss<<number.two;
srv.request.numberb=ss.str();

cout <<" Second number  ----> " <<number.two <<endl;

ss.str("");

if(client.call(srv)) {


 
cout<<"Sum of the two numbers : "; 
cout<< srv.response.sum<< "  "<<endl;

}

ros::spinOnce();
loop_rate.sleep();
}
return 0;

 

}

