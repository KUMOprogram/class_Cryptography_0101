#include <iostream>
#include <stdbool.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Beta
{
	private:
		string code1;
		string code2;
		string realletter;
	public:
		Beta(string& xrealletter, string& xcode1, string& xcode2);
		string& getrealletter();
		string& getcode1();
		string& getcode2();
		void setrealletter(string& xrealletter);
		void setcode1(string& xcode1);
		void setcode2(string& xcode2);
};

Beta::Beta(string& xrealletter, string& xcode1, string& xcode2)
{
	realletter = xrealletter;
	code1 = xcode1;
	code2 = xcode2;
}

string& Beta::getrealletter()
{
	return realletter;
}

string& Beta::getcode1()
{
	return code1;
}

string& Beta::getcode2()
{
	return code2;
}

void Beta::setrealletter(string& xrealletter)
{
	realletter = xrealletter;
}

void Beta::setcode1(string& xcode1)
{
	code1 = xcode1;
}

void Beta::setcode2(string& xcode2)
{
	code2 = xcode2;
}

void menudio();
void fill_beta(vector <Beta>& beta, string realletter, string code1, string code2);
void print_beta(vector <Beta>& beta);
void cryptbeta(vector <Beta>& beta,string& speakfool);
void decryptbeta(vector <Beta>& beta,string& speakfool);

int main()
{
system("color f1");
	int choice;
	string speakfool, CPPbug;
	vector <Beta> beta;
	fill_beta(beta,"a","00000000","00000001");
	fill_beta(beta,"b","00000010","00000011");
	fill_beta(beta,"c","00000100","00000110");
	fill_beta(beta,"d","00000111","00001000");
	fill_beta(beta,"e","00001100","00001110");
	fill_beta(beta,"f","00001111","00010000");
	fill_beta(beta,"g","00011000","00011100");
	fill_beta(beta,"h","00011110","00011111");
	fill_beta(beta,"i","00100000","00110000");
	fill_beta(beta,"j","00111000","00111100");
	fill_beta(beta,"k","00111110","00111111");
	fill_beta(beta,"l","01000000","01100000");
	fill_beta(beta,"m","01110000","01111000");
	fill_beta(beta,"n","01111100","01111110");
	fill_beta(beta,"o","01111111","10000000");
	fill_beta(beta,"p","11000000","11100000");
	fill_beta(beta,"q","11110000","11111000");
	fill_beta(beta,"r","11111100","11111110");
	fill_beta(beta,"s","11111111","00000101");
	fill_beta(beta,"t","00001011","00001001");
	fill_beta(beta,"u","00010011","00010001");
	fill_beta(beta,"v","00100011","00100001");
	fill_beta(beta,"w","01000011","01000001");
	fill_beta(beta,"x","10000011","10000001");
	fill_beta(beta,"y","00010101","10101010");
	fill_beta(beta,"z","01010101","00101010");
	fill_beta(beta," ","11000000","11011011");
	
	while(true)
	{
		menudio();
		cin>>choice;
		cout<<endl;
		
		if (choice == 1)
		{
        print_beta(beta);
		}

    if (choice == 2)
		{
			getline(cin,CPPbug);
			cout<<" Give a text to encrypt: ";
			getline(cin,speakfool);
			
			cryptbeta(beta,speakfool);
		}

    if (choice == 3)
		{
            getline(cin,CPPbug);
			cout<<" Give a text to decrypt: ";
			getline(cin,speakfool);

			decryptbeta(beta,speakfool);
		}

    if (choice == 0)
		{
			break;
		}

		if ((choice != 0)&&(choice != 1)&&(choice != 2)&&(choice != 3))
		{
			cout<<"WRONG CHOICE!"<<endl<<endl;
		}
	
	system("pause");
	}
system("pause");
}

void menudio()
{
	system("cls");
	cout<<endl;
	cout<<" Show Beta -------------------- 1"<<endl;
	cout<<" Encrypt ---------------------- 2"<<endl;
	cout<<" Decrypt ---------------------- 3"<<endl;
	cout<<" Close ------------------------ 0"<<endl;
	cout<<" Choice: ";
}

void fill_beta(vector <Beta>& beta, string realletter, string code1, string code2)
{
	Beta newbeta(realletter,code1,code2);
	newbeta.setrealletter(realletter);
	newbeta.setcode1(code1);
	newbeta.setcode2(code2);
	
	beta.push_back(newbeta);
}

void print_beta(vector <Beta>& beta)
{
	for (int i = 0; i < beta.size(); ++i)
	{
		cout<<" "<<beta[i].getrealletter()<<" --> "<<beta[i].getcode1()<<" , "<<beta[i].getcode2()<<endl;
	}
	cout<<endl;
}

void cryptbeta(vector <Beta>& beta,string& speakfool)
{
  srand(time(0));
	cout<<" Encrypted text: ";
	
	for (int j = 0; j < speakfool.size(); ++j)
	{
		_Bool flag = 0;
		int r = rand();
		r=(r%2)+1;
		for (int i = 0; i < beta.size(); ++i)
		{
			if(speakfool[j] == beta[i].getrealletter()[0])
			{
				if (r == 1)
				{
                    cout<<beta[i].getcode1();
					flag = 1;
				}
				else if (r == 2)
				{
                    cout<<beta[i].getcode2();
					flag = 1;
				}
			}
		}
		if (!flag)
		{
			cout<<speakfool[j];
		}
	}
	cout<<endl<<endl;
}

void decryptbeta(vector <Beta>& beta,string& speakfool)
{
  cout<<" Decrypted text: ";
    
  string letters_8 = "";
  for (int j = 0; j < speakfool.size(); ++j)
  {
		  if ((speakfool[j] == '0')||(speakfool[j] == '1'))
		  {
	        letters_8 += speakfool[j];
			    if (letters_8.size() == 8)
			    {
				      for (int i = 0; i < beta.size(); ++i)
				      {
					        if(letters_8.find(beta[i].getcode1())!=string::npos)
					        {
						          cout<<beta[i].getrealletter();
					        }
					
					        if(letters_8.find(beta[i].getcode2())!=string::npos)
        					{
        						  cout<<beta[i].getrealletter();
        					}
				      }
            	letters_8 = "";
			    }
		  }
		  else
		  {
			    cout<<speakfool[j];
		  }
	}
  cout<<endl<<endl;
}
