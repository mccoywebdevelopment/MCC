/* McCoy's Pizza delivery shop program #3: This program is designed to display
   area, volume. base cost, cost of one pizza, and the final cost of all pizzas
   which includes tax and delivery charge, if applicable*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    char shape,dough,cheese,delivery;
    double diameter,area,length,width,volume,sizeCrust,totalCheese,TotalCost,
    baseCost,onepizza;
    int pizzas,toppings;
    const double pie =3.14;


    cout<< "Welcome to Guiseppi's pizza shop."<<endl;
    cout<< "Do you want a round or rectangular pizza?"<<endl;
    cout<< "type 'r' for round, type 's' for rectangular" <<endl<<endl;
    cin>> shape;
    cout<<endl;

if (shape == 'r'){
    cout<< "Please enter the diameter of the pizza you want to order."<<endl;
    cout<<endl;
    cin>> diameter;
    cout<<endl;
    area=(pie*pow((diameter/2),2));
}
else{
    cout<< "Please enter the length."<<endl<<endl;
    cin >> length;
    cout<<endl;
    cout<< "Please enter the width."<<endl<<endl;
    cin>> width;
    cout<<endl;
    area=length*width;
}

    cout<< "How many topping do you want?"<<endl<<endl;
    cin>>toppings;
    cout<<endl;

    cout<< "What kind of dough do you want? "<<endl<<endl;
    cout<< "'c' for thin and crispy"<<endl;
    cout<< "'p' for pan"<<endl;
    cout<< "'h' for hand tossed "<<endl;
    cout<< "'t' for Texas toast"<<endl<<endl;
    cin >> dough;
    cout<<endl;

if (dough =='c'){
    volume=area*.1;
}
else if (dough == 'p'){
volume=area*.5;
}
else if (dough == 'h'){
    volume=area*.25;
}
else {
    volume=area*.9;
}



if (dough!= 'c'){
    cout << "Do you want cheezy crust? (y,n)"<<endl<<endl;
    cin>>cheese;
    cout<<endl;
    if (cheese == 'y'){
        if (shape=='r'){
            sizeCrust=2*pie*(diameter/2);
    }
    else{
            sizeCrust=2*(length+width);
    }
    totalCheese=.2*sizeCrust;
}
}
else{
    totalCheese=0;
}



baseCost=area*((.036)+(.025*toppings))+(.019*volume);
onepizza=(baseCost+totalCheese);

cout<<"How many pizzas do you want?"<<endl<<endl;
cin>>pizzas;
cout<<endl;
TotalCost=(baseCost+totalCheese)*pizzas;
TotalCost=TotalCost*(1+.07);


cout<< "Do you want the pizza delivered?(y/n)"<<endl<<endl;
cin>> delivery;
cout<<endl;

if (delivery== 'y')
    {
    if (TotalCost<10)
    {
        TotalCost+=3;
    }
    else if (TotalCost<=20)
    {
        TotalCost+=2;
    }
    else if (TotalCost<=30)
    {
        TotalCost+=1;
    }
    else
    {
        TotalCost+=0;
    }


}
cout<<"Area: "<<area<<"^2 inches"<<"| Volume: "<<volume<< " ^3 inches"
<<"| Base cost: $"<<baseCost<<"| Cost of one pizza: $"<<onepizza
<<endl<<" Total cost: $"<<TotalCost;
cout<<endl;
return 0;
}













