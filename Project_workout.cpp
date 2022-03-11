#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int issue_date,issue_month,issue_year;
void printerid();
int main()
{
	string division,district,tehsil,Search,date_o_birth;
	char name[30],f_name[30],gender,address1[100],address2[100],absorb;
	int id_int[8]={1,2,3,5,6,0,0,1};
	char opt1, opt;
	int option;
	int i=0;
	int v_int=12345600;
	int id_card[13],num;
	ifstream Data_geter;
	ofstream Data_entry;
		cout<<"\t\t\t _______________________________________________"<<endl;
		cout<<"\t\t\t|         ND softo version v1.0                 |"<<endl;
		cout<<"\t\t\t|	Mohammad Hassan ur Rehman               |"<<endl;
		cout<<"\t\t\t|_______________________________________________|"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	cout<<"Enter Today's Date with like dd mm yyyy"<<endl;
	cin>>issue_date>>issue_month>>issue_year;
		// Continuty in the voucher
		cout<<"1: For Voucher of old List"<<endl;
		cout<<"2: New Voucher List"<<endl;
		cin>>option;
		system("cls");
		if (option==1)
		{
			ifstream read_obj("Data.txt");
	string v_number,search,name,father_name,t_address,p_address,gender,id_card1,date_o_birth1;
	while (!read_obj.eof())
	{
		getline(read_obj,v_number);
		getline(read_obj,name);
		getline(read_obj,father_name);
		getline(read_obj,gender);
		getline(read_obj,date_o_birth1);
		getline(read_obj,t_address);
		getline(read_obj,p_address);
		getline(read_obj,id_card1);
	}
	id_int[6]=(v_number[13]-48);
	v_int+=(v_number[13]-48);
	v_int+=10;
	id_int[6]+=10;
	read_obj.close();
		}
		else
		{
			goto out;
		}
out:
	do
	{
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\t\tHome\t\tData Entry\t\tPrinting"<<endl;
		cout<<"\t\tEnter H";
		cout<<"\t\tEnter D";
		cout<<"\t\t\tEnter P"<<endl;
		cout<<"    ________________________________________________________________________________________"<<endl;
		cin>>opt;
		if (opt=='H'||opt=='h')
		{
			      cout<<"\t\t\t***********************************"<<endl;
			      cout<<"\t\t\t*    Mohammad Hassan ur Rehman    *\n"<<endl;
			      cout<<"\t\t\t*          CMS:021-18-0003        *\n"<<endl;
			      cout<<"\t\t\t***********************************"<<endl;
		}
		else if (opt=='d'||opt=='D')
		{
			v_int++;
			Data_entry.open("Data.txt", ios::app);
			Data_entry<<"\nPUNNAD"<<v_int<<endl;
			int bus=v_int;
			id_int[6]++;
			cout<<"<form/Entry>"<<endl;
			cout<<"Name"<<endl;
			cin.ignore();
			cin.get(name,29);
			Data_entry<<name<<endl;
			cout<<"Father Name"<<endl;
			cin.ignore();
			cin.get(f_name,29);
			Data_entry<<f_name<<endl;
			cin.ignore();
			cout<<"Gender"<<endl;
			cin.get(gender);
			Data_entry<<gender<<endl;
			cin.ignore();
			cout<<"Date of Birth"<<endl;
			getline(cin,date_o_birth);
			Data_entry<<date_o_birth<<endl;
			cout<<"Enter the Temporay Address"<<endl;
			cin.get(address1,99);
			Data_entry<<address1<<endl;
			cin.ignore();
			cout<<"Enter the Permnent Address"<<endl;
			cin.get(address2,99);
			Data_entry<<address2<<endl;
			cin.ignore();
			Data_geter.open("division.txt");
			id_card[0]=3;
			Data_geter.open("division list.txt");
			cout<<"Enter The Name of the division"<<endl;
			getline(cin,Search);
			while (!Data_geter.eof())
			{
					Data_geter>>num;
					Data_geter.get(absorb);
					getline(Data_geter,division);
					if (Search=="Bahawalpur")
					{
						id_card[1]=1;
					}
					else if(Search==division && Search!="Bahawalpur")
					{
						id_card[1]=num;
					}
			}
			Data_geter.close();
			Data_geter.open("District list.txt");
			cout<<"Enter the name of District"<<endl;
			getline(cin,Search);
			while (!Data_geter.eof())
			{
				Data_geter>>num;
				Data_geter.get(absorb);
				getline(Data_geter,district);
				if (Search==district)
				{
					id_card[2]=num;
					id_card[3]=0;
				}
			}
			Data_geter.close();
			Data_geter.open("Tehsil list.txt");
			cout<<"Enter the name of Tehsil"<<endl;
			getline(cin,Search);
			while (!Data_geter.eof())
			{
				Data_geter>>num;
				Data_geter.get(absorb);
				getline(Data_geter,tehsil);
				if (Search==tehsil)
				{
					id_card[4]=num;
				}
			}
			Data_entry<<id_card[0]<<id_card[1]<<id_card[2]<<id_card[3]<<id_card[4];
			int k=5;
			for (int i = 0; i <8; i++)
			{
					cout<<"You'r in nusted loop."<<endl;
					id_card[k]=id_int[i];
					Data_entry<<id_card[k];
					k++;
				
			}

			Data_geter.close();
			Data_entry.close();

			system("CLS");
			cout<<"			___________________________________"<<endl;
			cout<<"			* Your Data is Successfully Saved *"<<endl;
			cout<<"			___________________________________"<<endl;
			cout<<"your voucher is"<<endl;
			cout<<"\t\t_______________________________"<<endl;
			cout<<"\t\t       PUNNAD"<<v_int<<endl;
			cout<<"\t\t       "<<name<<endl;
			cout<<"\t\t       "<<f_name<<endl;
			cout<<"\t\t\t";
			for (int i = 0; i < 12; i++)
			{
				cout<<id_card[i];
			}
			cout<<endl;
			cout<<"\t\t   Total Amount "<<"Rs.800"<<endl;
			cout<<"\t\t  |||||||||||||||||||||||||||||"<<endl;
			cout<<"\t\t  |||||||||||||||||||||||||||||"<<endl;
		}
		else if (opt=='P'||opt=='p')
		{
			printerid();
		}
		cout<<"\t\t\t____________________________________"<<endl;
		cout<<"\t\t\t Press any key to go to main manu\n "<<endl;
		cout<<"\t\t\tEnter e to Log Out                  "<<endl;
		cout<<"\t\t\t____________________________________"<<endl;
		cin>>opt1;
		system("cls");
	}while(opt1!='e');
	cout<<"Loged Out"<<endl;
	cout<<"Press any key to exit..."<<endl;
	getch();
}
void printerid()
{
	string v_number,search,name,father_name,country="Pakistan",t_address,p_address,gender,id_card,date_o_birth;
	ifstream Data_prnt;
	cout<<"Enter the Voucher Number"<<endl;
	Data_prnt.open("Data.txt");
	cin.ignore();
	getline(cin,search);
	while (!Data_prnt.eof())
	{
		getline(Data_prnt,v_number);
		getline(Data_prnt,name);
		getline(Data_prnt,father_name);
		getline(Data_prnt,gender);
		getline(Data_prnt,date_o_birth);
		getline(Data_prnt,t_address);
		getline(Data_prnt,p_address);
		getline(Data_prnt,id_card);
		if (search==v_number)
		{
			cout<<"****************************************"<<endl;
			cout<<"Name                                    "<<endl;
			cout<<"    "<<name<<"                          "<<endl;
			cout<<"________________________________________"<<endl;
			cout<<"Father Name                             "<<endl;
			cout<<"    "<<father_name<<"                   "<<endl;
			cout<<"________________________________________"<<endl;
			cout<<"Gender       country of stay            "<<endl;
			cout<<gender<<"              |"<<country<<"               "<<endl;
			cout<<"________________________________________"<<endl;
			cout<<"Issue Date"<<"    |"<<"Expiry Date          "<<endl;
			cout<<issue_date<<" "<<issue_month<<" "<<issue_year<<"    |"<<issue_date<<" "<<issue_month<<" "<<issue_year+10<<endl;
			cout<<"****************************************"<<endl;
			cout<<"Temporary Address"<<endl;
			cout<<t_address<<endl;
			cout<<"Permanent Address"<<endl;
			cout<<p_address<<endl;
		}
	}

}
