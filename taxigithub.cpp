#include <fstream>
#include <iostream>
#include <windows.h>  
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include <conio.h> 


using namespace std; 

//time_t tim=time(0);   // get time now
//struct tm*now=localtime(&tim);
  

/*typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;*/

int ID1,key=false,a,b,x,y,pin1,pin2,xd=0,flag=0;
double d=0,t=0;
float distA=0.0,distX=0.0;
char w,c[4],r[4],p='A',pos[20][50];

class valcust
{
	public:
	int IDS,trips;
	double disc;
};
void header();

class Cust:public valcust
{
	public:
	char name[20],addr[50],add[50],dest[50];
	int ID,age,typ;
	double totfr;
	long long cntno;
	void getdata();
	void putdata();
    void pin();
    void Bill(double,double);
}objs;
  
  void Cust::Bill(double tf, double t)
  {
  	system("cls");
    cout<<"\t\t------------------------------------------------\n";
  	cout<<"\t\t\t        THE TAXI COMPANY INC.               \n\n";
  	cout<<"\t\t\t               BILL\n";
  	cout<<"\t\t------------------------------------------------\n\n";
  	//cout<<"Day:"<<(now->tm_mday)<< "-" << (now->tm_mon + 1) << "-"<<(now->tm_year + 1900);
  	/*long time_t;
  	cout<<time_t;
	SYSTEMTIME st;
    GetSystemTime(&st);
	using namespace date;
  	using namesoace std::chrono;
  	cout<<"\t\tDate and time:\n";
  	cout<<"\t\t";
  	std::cout<<system_clock::now()<<"\n";*/
  	
  	time_t rawtime; //creates and object of the built in time function
    struct tm * timeinfo; 

    time( &rawtime ); //gets the time from the computer
    timeinfo = localtime( &rawtime ); //store that time here

    //it displays current date and time except time is frozen and not real time
    cout<< "\t\tTime and date of booking: "<<asctime (timeinfo)<< endl; 

  	cout<<"\n\n\t\tName: "<<name<<endl;
  	cout<<"\t\tID: "<<ID<<endl;
  	cout<<"\t\tDistance Travelled: "<<d<<"km"<<endl;
  	cout<<"\t\tTime taken: "<<ceil(t)<<" minutes"<<endl;
  	cout<<"\n\n\t\tTotal fare :Rs."<<ceil(tf/8)<<endl;
  	cout<<"\t\t-------------------------------------------------\n\n";
  	cout<<"\t\t\tHope you had a pleasant ride!\n";
  	cout<<"\t\t\t       Thank You!\n";
  	cout<<"\t\t--------------------------------------------------\n\n";
  	objs.trips++;
  }

fstream fin;

void Cust::getdata()
{
    srand(time(NULL));
	int no=0;
	long long cpy=0;
	cout<<"\nEnter Name:\n";
	cin.getline(name,20);
	cout<<"\nEnter Age:\n";
	f:cin>>age;
	if(age>100)
	{
               cout<<"\nEnter valid age\n";
               goto f;
               }
	cin.ignore();
	cout<<"\nEnter Address & Contact No. \n";
	cin.getline(addr,20);
	s:cin>>cntno;
	cpy=cntno;
	while(cpy>0)
	{
	cpy/=10;
	no++;
}
	if(no!=10)
	{
	cout<<"\nInvalid no.! Please enter a correct no.";
	no=0;
	goto s;
}
	cout<<"\nPlease wait...";
    _sleep(5000);
    if(flag==0)
    {
    ID=rand();
    cout<<"\n\nAccount created successfully!\nYour ID is "<<ID<<" which you can use to sign in."; 
   }
   else 
   flag=0;
}
void Cust::putdata()
{
	cout<<"Name:         "<<name;
	cout<<"\nID is:        "<<ID;
	cout<<"\nContact no.:  "<<cntno;
    cout<<"\nAge:          "<<age;
	cout<<"\nAddress:      "<<addr<<"\n";
}

void cardetails(int p)
{
	 
     system("cls");
     header();
     if(p==1)
	 cout<<"Base price is Rs 30(per km)\n\nMAX: 2 PEOPLE\n";
	 else if(p==2)
	 cout<<"Base price is Rs 45(per km)\n\nMAX: 3 PEOPLE\n";
	 else if(p==3)
	 cout<<"Base price is Rs 60(per km)\n\nMAX :4 PEOPLE\n";
	 else if(p==4)
	 cout<<"Base price is Rs 75(per km)\n\nMAX: 5 PEOPLE\n";
}

void book()
{
	
	fin.close();
	cin.ignore();
	objs.pin();
	
  //HANDLE  hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hConsole,200);
  
  system("cls");
  header();
  cout<<"\nEnter type of taxi\n";
  cout<<"1.MINI\n";
  cout<<"2.HATCHBACK\n";
  cout<<"3.SEDAN\n";
  cout<<"4.SUV\n";
  
  tt:cin>>objs.typ;
  if((objs.typ>5)||(objs.typ<0))
  {
  cout<<"Wrong choice!Enter a valid choice"<<endl;
  goto tt;
}
  cout<<"\nDo you want car details\nEnter yes or no (y/n))\n";
  cin>>w;
  if(w=='y')
  {
  	cardetails(objs.typ);

  }
 
}
int choice;
void Intro();
void dispcust()
{
	int choice;
	cout<<"\n\nWhat do you want to do?\n";
	pop:cout<<"1.Book a taxi\n2.Edit account details\n3.Exit\nEnter your choice\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		key=true;
		book();
		break;
		
		case 2:
                         if(::choice==1)
			{
				cout<<"The account details are being fed into our database. Updation will happen only after reopening the app";
				break;
			}
			//cout<<"This function is still under developement!";
			//goto zq;
		//objs.putdata();
		fin.close();
		fin.open("CUSTOMER.DAT",ios::in|ios::out|ios::binary);
	    //fin.seekg(0);
		while(fin.read((char*)&objs,sizeof(objs)))//!fin.eof();
		{
			if(ID1==objs.ID)
			{
				flag=1;
				fin.seekp(fin.tellg()-sizeof(objs));
				cin.ignore();
				objs.getdata();
				fin.write((char*)&objs,sizeof(objs));
				system("cls");
				header();
				cout<<"Account Edited successfully\n";
				goto pop;
				/*cout<<ID1;
				cout<<"Trip no."<<objs.trips;
				//xd=1;
		cout<<"\nFrom:";
		cout.write(objs.add,strlen(objs.add));
		cout<<"\nTo:";
		cout.write(objs.dest,strlen(objs.dest));
		cout<<"\nType of taxi:"<<objs.typ;
		cout<<"\nTotal fare was:Rs."<<objs.totfr;*/
	}
}
/*if(objs.trips==0)
cout<<"\nNo previous trips were made";*/
              //cin.ignore();
               zq:break;
	           case 3:
			   	exit(0);
				default:
					cout<<"Wrong choice!Please renter!";
					goto pop; 
					break;
	
}
}
void Intro()
{
	char found='n';
	int l=0;
	cout<<"\n\n1.Create new account\n2.Use to pre-existing account\n3.Exit\nEnter your choice (1,2 or 3)\n";
	cin>>choice;
	system("cls");
	header();
	switch(choice)
	{
		found='n';
		  //up:
		    case 1:
		  	fin.close();
			fin.open("CUSTOMER.DAT",ios::out|ios::app|ios::binary);
	        cout<<"Enter the following details \n";
	        cin.ignore();
	        objs.getdata();
	        //fin.seekg(48*l);
	        fin.write((char*)&objs,sizeof(objs));
	        //l++;
	        break;
			case 2:
				cout<<"Enter your ID \n";
				cin>>ID1;
				//fin.close();
				fin.open("CUSTOMER.DAT",ios::in|ios::binary);
				while(fin.read((char*)&objs,sizeof(objs)))//!fin.eof();
				{
					if((objs.ID==ID1)||(found=='y'))
					   {
                        objs.trips++;
                        if(objs.trips>3)
                        {
                                        objs.IDS=objs.ID;
                                        objs.disc=20;
                                        }
                                        system("cls");
                                        header();
					   	cout<<"Welcome!\n\n";
					   	objs.putdata();
					   	dispcust();
					   	found='y';
					   }
			    }
				if(found=='n')
				{
			    cout<<"Record not found \n OR \n You have already logged in from the same/different account.\nIf you havent logged in already,Create a new account now!\n";
				//found=y;
				//goto up;}
			}
					break;
					case 3:
					exit(0);
					default:
					cout<<"Wrong choice!";
					break;
				
	
     }
}


void fare(int s,double g,double t)// s is for type of cab|g is distance |t is time
{
	
	 int base;
	 if(s==1)
	 base=30;
	 else if(s==2)
	 base=45;
	 else if(s==3)
	 base=60;
	 else if(s==4)
	 base=75;
	 objs.totfr=((base+t*g)*2)-objs.disc;
	 objs.Bill(objs.totfr,t);
	 //cout<<"\nTotal fare is Rs "<<ceil(objs.totfr)<<endl<<"\nTime taken "<<ceil(t*4)<<" minutes\n";
	 }

int rh;
void Cust::pin()
{ 
  system("cls");
  header();
  rh++;
  cout<<"\nEnter the address of your current location \n";
  cin.getline(add,50);
  do
  {
  cout<<"\nPlease enter a valid pin code starting from 56 of your current location\n";
  cin>>pin1;
  b=pin1%100;
  pin1/=100;
  a=pin1%100;
   }while(pin1/100!=56);
  //cout<<a<<b;


  cin.ignore();
  cout<<"\nEnter the address of your destination \n";
  cin.getline(dest,50);
  do
  {
  cout<<"\nPlease enter a valid pin code starting from 56 of your destination\n";
  cin>>pin2;
  y=pin2%100;
  pin2/=100;
  x=pin2%100;
  }while(pin2/100!=56);
  
  //cout<<y<<x;
}

inline void header()
{
	cout<<"\t\t---------------------------------------------\n";
	cout<<"\t\t|          THE TAXI COMPANY INC.            |\n";
	cout<<"\t\t---------------------------------------------\n";
	cout<<"\t\t---------------------------------------------\n";
}

int main()
{
	/*for(int i=0;i<10;i++)
	{
		cout<<objs.add[i]<<endl;
		cout<<objs.dest[i]<<endl;
	}*/
   header();
   srand(time(NULL));
   int zxc; 
   char ch;
   cout<<"\n\nSign in!\n\nDon't have an account?Create one now!";
	do
	{
	Intro();
	//fin.close();
	fin.open("CUSTOMER.DAT",ios::in|ios::binary);
	/*cout<<"\nContents of file\n";
	fin.seekg(0);*/
	/*while(fin.read((char*)&objs,sizeof(objs)))
    objs.putdata();*/
    if(key==true)
    break;
    //cin.ignore();
    cout<<"\nDo you want to continue creating accounts?(y/n)";
	cin>>ch;
	system("cls");
	header();
	if((ch=='n')&&(choice==1||choice==2))
	{cout<<"The active account is the last accessed one.\nAll bookings will be made using the last created account.";
	cout<<"\n\nPlease change your account to the desired one before booking.";
	dispcust();
}
/*else if(ch=='y')
{
	Intro();
}*/
}
	while(ch=='y');
	if((key==true))
	{
    for(int i=0;i<20;i++)
  {
  	for(int j=0;j<50;j++)
  	pos[i][j]=' ';
}
  
  if(rand()%2==0)
  {
  system("color A");
  cout<<"No traffic!"<<endl;
}
  else if(rand()%3==0)
  {
  system("color 2");
  cout<<"Normal Traffic"<<endl;
  t=5;
}
  else if(rand()%5==0)
  {
  system("color E");
  cout<<"Moderate traffic"<<endl;
  t=10;
}
  else if(rand()%7==0)
  {
  system("color C");
  cout<<"Traffic's building up!"<<endl;
  t=15;
}
  else if(rand()%11==0)
  {
  j:system("color 4");
  cout<<"Heavy traffic!"<<endl;
  t=30;
}
else
goto j;
   for(int k=0;k<4;k++)
  {
  	r[k]=rand()%20;
  	c[k]=rand()%50; 
  	if(rand()%2==0)
    pos[r[k]][c[k]]=p;
    else if(rand()%3==0)
    pos[r[k]+2][c[k]]=p;
    else
    pos[r[k]][c[k]+2]=p;
    p++;
}
  for(int i=1;i<19;i++)
  {
  	for(int l=0;l<4;l++)
  	{
  		if(i==r[l])
  		{
  			for(int k=1;k<49;k++)
  			{
  				if(pos[i][k]!='*')
  				{
				pos[i-1][k]='-';
  				pos[i+1][k]='-';
  			    }
			  }
		  }
	  }
    }
  
   for(int i=1;i<49;i++)
  {
  	for(int l=0;l<4;l++)
  	{
  		if(i==c[l])
  		{
  			for(int k=1;k<19;k++)
  			{
  			    if(pos[k][i]!='*')
  				{
  				pos[k][i+1]='|';
  				pos[k][i-1]='|';
  			    }
			}
		  }
	  }
  }
  for(int o=1;o<19;o++)
  {
  	for(int p=1;p<49;p++)
  	{
  		if((pos[o+1][p]=='-')&&(pos[o-1][p]=='-')&&(pos[o][p+1]=='|')&&(pos[o][p-1]=='|'))
  		{
		pos[o+1][p]=' ';
		pos[o-1][p]=' ';
		pos[o][p+1]=' ';
		pos[o][p-1]=' ';
	    }
    } 
}
  pos[a][b]='@';
  pos[x][y]='X';
  for(int i=0;i<20;i++)
  {
  for(int j=0;j<50;j++)
  cout<<pos[i][j];
  cout<<endl;
  }
  //system("color 0");
  cout<<" KEY :\n\n";
  cout<<" @ - Your current location.\n";
  cout<<" X - Your Destination.\n";
  cout<<" Taxi's indicated by letters\n";
  cout<<"\nEnter the letter of the preffered taxi \n(Enter N if there are no taxi's available)\n";
  char taxi;
  cin>>taxi;
  if(taxi=='N')
  {
  cout<<"No taxi!The inconvenience is regretted.Please try again in a few minutes...";
  goto q;
}
  for(int k=1;k<4;k++)
  {
     if(pos[r[k]][c[k]]=p)
	 distA=fabs(r[k]-a)+fabs(c[k]-b);
	 }
	 d=(fabs(x-a)+fabs(y-b));
	 t+=(d*2);
	 system("cls"); 
	 header();
  //cout<<"The distance from the taxi is "<<distA<<endl;
  //cout<<"\nThe distance you are from the destination is "<<d;
  
  cout<<"\nYour taxi will arrive shortly...";
  _sleep(5000);
  int number;
    int k=0,l=0;
    srand(time(NULL));
    number=rand()%10;
    fstream dn;
    system("cls");
    header();
    cout<<"\n                DRIVER DETAILS       \n";
    char a[20];
    dn.open("Names.txt",ios::in);
	char str[200];
    while(dn>>str)
   {
    l++;
    if(l==number)
     {
    cout<<"\nDriver name : ";
    cout.write(str,strlen(str))<<endl;
    break;
     }
   }
    dn.close();
    dn.open("number.txt",ios::in);
    while(dn>>a)
    {
    	//dno.seekg(number);
	k++;
    if(k==number)
    {
    	cout<<"Driver number is : ";
        cout<<a<<" "<<endl;
        break;
    }
}
    
	

    dn.close();
  char ch1;
  cout<<"\nProceed to bill? (y/n)\n";
  xd++;
  cin>>ch1;
  if(ch1=='y')
  fare(objs.typ,d,t);
  
  //***Driver details***
  //cout<<"\n Thank you for choosing us!";
}
  q:getch();
  return 0;
}

