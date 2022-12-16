#include<iostream>
using namespace std;
class Types
{
public:
    virtual void Apple()=0;//Abstract Function
    virtual void Samsung()=0;//Abstract Function
    virtual void OnePlus()=0;//Abstract Function
    virtual void Google()=0;//Abstract Function
    virtual void Redmi()=0;//Abstract Function
};
class mobile_shop:public Types
{
public:
    int sr_no;
    string mobile_name;
    int price;
public:
    void Fields(){
        cout<<"Sr no.";
        cout<<"\tMobile Phone";
        cout<<"\tPrice";
    }
    void Apple(){
        sr_no=1;
        mobile_name="Iphone 13 ";
        price=60000;
        cout<<"1. ";
        cout<<"\tIphone 13 ";
        cout<<"\t60000";
    }
    void Samsung(){
        sr_no=2;
        mobile_name="Samsung Galaxy Fold ";
        price=50000;
        cout<<"2. ";
        cout<<"\tSamsung Galaxy Fold ";
        cout<<"\t50000";
    }
    void OnePlus(){
        sr_no=3;
        mobile_name="OnePlus Nord ";
        price=45000;
        cout<<"3. ";
        cout<<"\tOnePlus Nord ";
        cout<<"\t45000";
    }
    void Google(){
        sr_no=4;
        mobile_name="Google Pixel";
        price=60000;
        cout<<"4. ";
        cout<<"\t Google Pixel";
        cout<<"\t60000 ";
    }
    void Redmi(){
        sr_no=5;
        mobile_name="Redmi Note 16 Pro";
        price=40000;
        cout<<"5. ";
        cout<<"\tRedmi Note 16 Pro";
        cout<<"\t40000";
    }
public:
    void print_info()
    {
        Fields();
        cout<<"\n\n";
        Apple();
        cout<<"\n";
        Samsung();
        cout<<"\n";
        OnePlus();
        cout<<"\n";
        Google();
        cout<<"\n";
        Redmi();
    }
};

class Payment:public mobile_shop
{
public:
    float discount=0.0;
    string card_name_H="HDFC";
    string card_name_I="ICICI";
    string card_name_AE="AmericanExpress";
    string UPI_name_G="GPAY";
    string UPI_name_P="PAYTM";
    string UPI_name_B="BharatPe";
    void CC()
    {
        cout<<"\nChoose the credit you want to use ";
        cout<<"\n 1.HDFC(Premium) \n 2.ICICI gift card \n 3. American Express ";
    }
    void HDFC()
    {
        discount=0.2;
        cout<<"\nYou get a discount of 20% ";
    }
     void ICICI()
    {
        discount=0.15;
        cout<<"\nYou get a discount of 15% ";
    }
     void AmericanExpress()
    {
        discount=0.3;
        cout<<"\nYou get a discount of 30% ";
    }

    void UPI()
    {
        cout<<"\nChoose your UPI gateway ";
        cout<<"\n 1.GooglePay(GPAY) \n 2.PayTm(PAYTM) \n 3. BharatPe(Bharat)";
    }
    void GPAY()
    {
        discount=0.10;
        cout<<"\nYou get a discount of 10% ";
    }
    void Paytm()
    {
        discount=0.15;
        cout<<"\nYou get a discount of 15% ";
    }
     void BharatPe()
    {
        discount=0.05;
        cout<<"\nYou get a discount of 5% ";
    }

};
int main()
{
    mobile_shop mo;
    Payment pa;//Object Declaration
    mo.print_info();
    string ca=" ",U=" ";
    int pay=0;
    int ch=0,dec=0,cart=0;
    float final_discount=0.0;
      while(ch>=0){
              cout<<"\nEnter the Serial no. of the mobile phone that you'd like to buy";
              cin>>ch;
          switch(ch){
          case 1:
              mo.Apple();
              cout<<"\nIts Properties";
              break;
          case 2:
              mo.Samsung();
              cout<<"\nIts Properties";
              break;
          case 3:
              mo.OnePlus();
              cout<<"\nIts Properties";
              break;
          case 4:
              mo.Google();
              cout<<"\nIts Properties";
              break;
          case 5:
              mo.Redmi();
              cout<<"\nIts Properties";
              break;
        default:
              mo.price=0;
              cout<<"\nSelected phone is out of stock ";
              break;
        }
        cout<<"\nDo you want to add any more phones in your cart \n 1.Yes \n 2.No\n";
        cin>>dec;
        cart=cart+mo.price;
        if(dec==1){
         continue;
        }
        else{
            break;
        }
    }
    cout<<"Final CART PRICE is "<<cart;
    cout<<"\nChoose your method of payment ";
    cout<<"\n 1.Credit Card \n 2. UPI \n 3. Cash-On-Delivery(COD)\n";
    cin>>pay;
    switch(pay)
    {
    case 1:
        pa.CC();
        cout<<"\nType in your card name ";
        cin>>ca;
        if(ca==pa.card_name_H){
            pa.HDFC();
        }
        else if(ca==pa.card_name_I){
            pa.ICICI();
        }
        else if(ca==pa.card_name_AE){
            pa.AmericanExpress();
        }
        final_discount=cart*pa.discount;
        cout<<"\nYour Final Price now is "<<cart-final_discount;
        break;

    case 2:
        pa.UPI();
        cout<<"\nType in your UPI name ";
        cin>>U;
        if(U==pa.UPI_name_G){
            pa.GPAY();
        }
        else if(U==pa.UPI_name_P){
            pa.Paytm();
        }
        else if(U==pa.UPI_name_B){
            pa.BharatPe();
        }
        final_discount=cart*pa.discount;
        cout<<"\nYour Final Price now is "<<cart-final_discount;
        break;

    case 3:
        cout<<"\nYour Final Price is "<<cart;
        break;
    }
    cout<<"\nThank you for shopping with us\nHave a nice day ahead!!!";
}


