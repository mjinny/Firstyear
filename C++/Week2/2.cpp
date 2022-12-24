/*=====================================   
Italian Woods Furniture Company
=====================================
Enter P for pine, O for oak or M for mahogany : M
How many tables do you want : 3

Wood Selected	No of tables		Total cost
------------------		---------------		------------
Mahogany		3			$930

Thank you for visiting us.
=====================================
*/
#include<iostream>
using namespace std;
int main(){
    int pine = 100, oak=225, mahogany=310,piece,total_cost;
    char ch;
    string wood;

    for(int i=0;i<50;i++)
        cout<<"=";
    cout<<endl;
    cout<<"Italian Woods Furniture Company"<<endl;
    for(int i=0;i<50;i++)
        cout<<"=";
    cout<<endl;
    cout<<"Enter P for pine, O for oak, or M for mahogany: ";
    cin>>ch;
    cout<<"How many tables do you want: ";
        cin>>piece;
    switch(ch)
    {
        case 'P':{
            total_cost= piece*pine;
            wood = "Pine";
            break;
        }
        case 'O':{
            total_cost = piece*oak;
            wood = "Oak";
            break;
        }
        case 'M':{
            total_cost = piece*mahogany;
            wood = "Mahogany";
            break;
        }
    
        default:
        cout<<"Wrong entry.";
        break;
    }
    cout<<endl;
    cout<<"Wood Selected\tNo. of tables\tTotal cost"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<15;j++)
            cout<<"-";
            cout<<"\t";
    }
    cout<<endl;
    cout<<wood<<"\t\t"<<piece<<"\t\t"<<"$"<<total_cost<<endl;
    cout<<endl;
    cout<<"Thankyou for visiting us."<<endl;
    
    for(int i=0;i<50;i++)
    cout<<"=";
    return 0;
}
