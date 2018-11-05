#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class ojek
{
	public:
		char pilih[1];
		void login();
	private:
		void output(int a, int b, int c, int d, int e);
		int info[5], i, a, b, c, d, driver[5], tjarak;
		void process(int jarak, int kendaraan);
		void input();
		void error();
		char username[5], password[5];
};


void ojek::login()
{
	cout<<"====================================LOGIN===================================="<<endl;
	cout<<"Username : ";
	cin>>username;
	cout<<"Password : ";
	cin>>password;
	
	if ((strcmp(username, "aleg")==0) && (strcmp(password, "yones")==0))
		input();
	else
		error();
}
void ojek::input()
{
	cout<<"==========================OJEK ONLINE=========================="<<endl;
	cout<<"Masukkan jarak tujuan dengan tempat Anda (km) : ";
	cin>>info[0];
	cout<<"1. Motor"<<endl;
	cout<<"2. Mobil"<<endl;
	cout<<"3. Taksi"<<endl;
	cout<<"Masukkan jenis kendaraan : ";
	cin>>info[1];
	process(info[0], info[1]);
}

void ojek::process(int jarak, int kendaraan)
{
	tjarak=0;
	//0=jarak, 1=kendaraan, 2=biaya, 3=waktu perjalanan, 4=driver
	driver[0] = 1;
	driver[1] = 2;
	driver[2] = 3;
	driver[3] = 4;
	driver[4] = 5;	
	info[4] = driver[rand()%5];
	
	info[0] = jarak;
	info[1] = kendaraan;
	if (info[1]==1)
	{
		info[2] = 4000;
		info[3] = 2;
	}
	else if(info[1]==2)
	{
		info[2] = 6000;
		info[3] = 3;
	}
	else if (info[1]==3)
	{
		info[2] = 8000;
		info[3] = 3;
	}
	else
	{
		info[2] = 0;
		info[3] = 0;
	}
	
	switch(info[2])
	{
		case 0:
			cout<<"Pilih kendaraan sesuai angka"<<endl;
			break;
		
		default:
			if (info[0]>0 && info[0]<30)
			{
				info[2]*=info[0];
				for (i=0; i<info[0]; i++)
				{
					tjarak+=info[3];
				}
				info[3] = tjarak;
				output(info[0], info[1], info[2], info[3], info[4]);
			}
			
			else
				cout<<"Jarak harus 1-30 km"<<endl;			
	}	
}

void ojek::output(int a, int b, int c, int d, int e)
{
	cout<<"==============================================================="<<endl;
	cout<<"Rincian Pemesanan "<<endl;
	cout<<"Jarak tujuan Anda : "<<a<<" km"<<endl;
	
	
	if (b==1)
		cout<<"Kendaraan Anda : motor"<<endl;
	else if (b==2)
		cout<<"Kendaraan Anda : mobil"<<endl;
	else 
		cout<<"Kendaraan Anda : Taksi"<<endl;
		
		
	cout<<"Biaya Anda : "<<c<<endl;
	
	if (d>=60)
	{
		cout<<"Estimasi waktu perjalanan Anda : "<<d/60<<" jam "<< d%60<<" menit"<<endl;
	}
	
	else
		cout<<"Estimasi waktu perjalanan Anda : "<<d<<" menit"<<endl;
		
	if (e==1)
		cout<<"Driver Anda : Bp. Saptono";
	else if(e==2)
		cout<<"Driver Anda : Bp. Hendro";
	else if(e==3)
		cout<<"Driver Anda : Bp. Kusumo";
	else if(e==4)
		cout<<"Driver Anda : Bp. Yanto";
	else
		cout<<"Driver Anda : Bp. Ahmad Nurodin";
		
	cout<<endl;
}

void ojek::error()
{
	cout<<"Username dan password salah"<<endl;
}

int main()
{
	ojek hitung;
	do
	{
		hitung.login(); 
		cout<<"Kembali ke menu ? (y/n) : ";
		cin>>hitung.pilih;
	}
	while(strcmp(hitung.pilih, "y") == 0);
}
