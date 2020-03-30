
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream> 
#include<process.h> 
#include<iomanip>
#include<conio.h>
using namespace std;
/*{
	
	cin>>ch;
}*/
class book
{
	
	char *bno ;
	char *bname; 
	char *aname; 
	
  public :
  	        book()
	{
		bno = new char[20];
		bname = new char[20];
		aname = new char [20];
	}
  	    void create_book()
  	    {
  	    	cout<<"\n enter the book number :";
  	    	cin>>bno;
  	    	cout<<"\n enter the book name :";
  	    	fflush(stdin);
  	    	gets(bname);
  	    	
  	    	cout<<"\n enter the author name :";
  	    	fflush(stdin);
  	    	gets(aname);
  	    	cout<<"-----------------------------------------------";
		}
		void display_book()
		{
			cout<<"\n book no : "<<bno;
			cout<<"\n book name :";
			puts(bname);
			cout<<"\n Author name :";
			puts(aname);
			
		}
		void modify_book()
		{
		    cout<<"\n enter the book number :";
  	    	cin>>bno;
  	    	cout<<"\n enter the book name :";
  	    	fflush(stdin);
  	    	gets(bname);
  	    	
  	    	cout<<"\n enter the author name :";
  	    	fflush(stdin);
  	    	gets(aname);
		}
		char * retbno()
		{
			return bno;
		}
		void show()
		{
			cout<<endl<<"Book Number : "<<bno;
			cout<<endl<<" Book Name :"<<bname;
			cout<<endl<<" Author name "<<aname;
			cout<<"-------------------------------------------------------------------";
			cout<<endl;
			
		}
		~book()
		{
			delete [] bno;
			delete [] bname;
			delete [] aname;
		}
};
class student
{
	
	char *admno;
	char *stname;
	char *setbno ;
	int token;
	public :
		student()
		{
			admno = new char[20];
			stname = new char [20];
			setbno = new char [20];
		}
	void createstd()
	{
		cout<<"enter the admission number";
		cin>>admno;
		cout<<"enter the studentname";
		fflush(stdin);
		gets(stname);
		token=0;
		setbno[0]='\0';
		cout<<"\n\n student record created..";
	}
	void displaystd()
	{
		cout<<" \n\tthe admission number :"<<admno;
		cout<<" \n\tThe studentname :";
		puts(stname);
		cout<<"\n\tNo of books issued :"<<token;
		if(token==1)
		{
			cout<<"Book number : "<<setbno;
		}
	}
	void modifystd()
	{
	  	cout<<"\n\tenter the admission number";
		cin>>admno;
		cout<<"\n\t enter the studentname";
		fflush(stdin);
		gets(stname);
	
	}
	char * retadmno()
	{
		return admno;
	}
	char * retstbno()
	{
		return setbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{ token=1;
	}
	void rsttoken()
	{
		token=0;
	}
	void getstbno(char t[])
	{
		strcpy(setbno,t);
	}
	void show()
	{
			cout<<endl<<" Token "<<token<<endl;
		printf("admission number= %s \n",admno);
	    printf(" student name = %s \n",stname);
	
		cout<<endl;
		cout<<"----------------------------------------------------------------------";
	}
	~student()
	{
		delete [] admno;
		delete [] stname;
		delete [] setbno;
	}
};
fstream fp,fp1;
book *bk = new book();
student *st = new student();

void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
	
		bk->create_book();
		fp.write((char*)bk,sizeof(book));
		cout<<"\n do you want to add another record : ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	fp.close();
}
void write_student()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		
		st->createstd();
		fp.write((char*)st,sizeof(student));
		cout<<"\n do you want to add another record : ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	fp.close();
}
void display_b(char n[])
{
	
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)bk,sizeof(book)))
	{
		if(strcmpi(bk->retbno(),n)==0)
		{
			bk->display_book();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"book does not exist";
	getch();
}

void display_s(char n[])
{
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)st,sizeof(student)))
	{
		if(strcmpi(st->retadmno(),n)==0)
		{
			st->displaystd();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"student does not exist";
	getch();
}
void modifyb()
{
	char n[6];
	int found=0;
	cout<<"\n\t modify record ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)bk,sizeof(book)) && found==0) 
	{
	    if(strcmpi(bk->retbno(),n)==0) 
		{
		    bk->display_book();
	        cout<<"\n\t modify book record";
        	cout<<"\n\t enter the new details of the book : "<<endl;
         	bk->modify_book();
         	int pos=-1 * sizeof(bk);
	        fp.seekp(pos,ios::cur);
	        fp.write((char*)bk,sizeof(book));
	        cout<<"\n\t\t record updated :";
	        found=1;
	   }
    }
    fp.close();
    if(found==0)
    {
    	cout<<"\t\t records not found : ";
	}
	getch();
}
void modifys()
{
	char n[6];
	int found=0;
	
	cout<<"\t\t enter the student no : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)st,sizeof(student)) && found==0)
	{
		if(strcmpi(st->retadmno(),n)==0)
		{
			st->displaystd();
			cout<<"\n\t\tmodify student record ";
			cout<<"\n\t enter the new details of the student : ";
			st->modifystd();
			int pos=-1* sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char *) st,sizeof(student));
			cout<<"\t\t record updated : ";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		cout<<"\t\t records not found : ";
	}
	
}
void deleteb()
{
	char n[6];
	//int flag =0;
	cout<<"\n\n\n\tDELETE book.."; 
	cout<<"\n\nEnter the book  You Want To Delete : "; 
	cin>>n; 
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	 fp2.open("Temp.dat",ios::out);
					  
	fp.seekg(0,ios::beg);
      while(fp.read((char*)bk,sizeof(book)))
       {
		   if(strcmpi(bk->retbno(),n)!=0)
            fp2.write((char*)st,sizeof(book));
	   } 
		fp2.close();
	     fp.close();
		 remove("book.dat");
	     rename("Temp.dat","book.dat"); 
		 cout<<"\n\n\tRecord Deleted ..";
		getch();
				
	
}
void deletes()
{
	char n[6];
		int flag=0;
			 
			cout<<"\n\n\n\tDELETE STUDENT..."; 
			cout<<"\n\nEnter The admission no. of the Student You Want To Delete : "; 
			cin>>n; 
			fp.open("student.dat",ios::in|ios::out);
			fstream fp2;
			 fp2.open("Temp.dat",ios::out);
					  
			fp.seekg(0,ios::beg);
            while(fp.read((char*)st,sizeof(student)))
           {
		       if(strcmpi(st->retadmno(),n)!=0)
                  fp2.write((char*)st,sizeof(student));
		        else flag=1;
		    } 
		     	fp2.close();
			    fp.close();
			     remove("student.dat");
			    rename("Temp.dat","student.dat"); 
			    if(flag==1) 
			    cout<<"\n\n\tRecord Deleted ..";
			    else
				 cout<<"\n\nRecord not found";
				 cin.get();
				
}
void showallstd()
{
	fp.open("student.dat",ios::in);
	if(!fp)
	{
		cout<<"record not found ";
		getch();
		
		
	}
	//cout<<"admission no\t\t\tname\t\t\tbookissued\n";
	cout<<"----------------------------------------------------------------------";
	while(fp.read((char*)st,sizeof(student)))
	{
		cout<<"qwerty";
		st->show();
	}
	fp.close();
}
void showallb()
{
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"record not found : ";
		getch();
	}
	//cout<<"Booknumber bookname \t\t\t authorname";
	while(fp.read((char *)bk,sizeof(book)))
	{
		cout<<"qwerty";
		bk->show();
	}
	fp.close();
}
void book_issue()
{
//	student st1;
	char sno[10],bno[10];
	int found=0,flag=0;
	cout<<"\n\n enter the student admission number : ";
	//fflush(stdin);
	cin>>sno;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);

	while(fp.read((char *)st,sizeof(student)) && found==0)
	{
	  
		if(strcmpi(st->retadmno(),sno)==0)
		{
			found=1;
			if(st->rettoken()==0)
			{
				cout<<"\n\n enter the book no : ";
				cin>>bno;
				while(fp1.read((char*)bk,sizeof(book)) && flag==0)
				{
					if (strcmpi(bk->retbno(),bno)==0)
					{
						bk->display_book();
						flag=1;
						st->addtoken();
						st->getstbno(bk->retbno());
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)st,sizeof(student));
						cout<<"\n\n\t book issued succefully : ";
						
					}
				}
				if(flag==0)
				cout<<" Book does not exist ";
			}
			else
			cout<<"book is not yet return";
		}
	}
	if(found==0)
	cout<<" Student record does not exist.. ";
	fp.close();
	fp1.close();
	
}
void book_deposit()
{
	//student st1=st;
	char sno[10],bno[10];
	int found=0,flag=0,day,fine;
	cout<<"\n\n Book Deposit ";
	cout<<"\n enter the student admission number :";
	cin>>sno;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char *)st,sizeof(student)) && found==0);
	{
		//cout<<"qwerty";
		if(strcmpi(st->retadmno(),sno)==0)
		{
			found=1;
			if(st->rettoken()==1)
			{
				
				
				while(fp1.read((char *)bk,sizeof(bk)) && flag==0)
				{
					if(strcmpi(bk->retbno(),st->retstbno())==0)
					{
						bk->display_book();
						flag=1;
						cout<<" time for which the book is kept : ";
						cin>>day;
						if(day>15)
						{
							fine=(day-15)*1;
							cout<<" fine == "<<fine;
						}
						st->rsttoken();
						int pos= -1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char *)st,sizeof(student));
						cout<<"\n\t Book deposited successfully ";
					}
				}
				if(flag==0)
				{
					cout<<"\n no book ";
				}
			}
			else
			cout<<"no book issued";
		}
	}
	if(found==0)
	cout<<" student does not exist ";
	fp.close();
	fp1.close();
}
void admin_menu()
 { 
    int ch2; 
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n 1 : add book";
	cout<<"\n 2 : show book" ;
	cout<<"\n3 : modify book";
	cout<<"\n 4 : delete book";
	cout<<"\n 5 : show specific book ";
	cout<<"\n 6: add student record";
	cout<<"\n 7 : show student record";
	cout<<"\n 8 : modify student record";
	cout<<"\n 9 : delete student record";
	cout<<"\n 10: show specific student";
	cout<<"\n 11 : back to the main menu"<<endl;
	cout<<" enter your choice [1-11]";
		  cin>>ch2;
		   switch(ch2)
		    { 
			 case 1:
			   write_book();
			   break; 
			case 2:
			  showallb();
			  break; 
			case 3:
			    modifyb();
			    break;
			 case 4:
			    deleteb();
				break;
			 case 5: 
			    char t[10];
				cout<<" \n\t\tenter the book number "; 
				cin>>t;
				display_b(t);
			    break;
			case 6 :
				    write_student();
				    break;
			 case 7:
			    showallstd();
				break;
			 case 8:
			   { 
			      modifys(); 
				   break;
			    }
			 case 9:
			      deletes();
				  break;
			 case 10: 
			       char  l[10];
				    
					cout<<"\n\n\tPlease Enter The Admission No. ";
					 cin>>l;
					  display_s(l);
				   break; 
			case 11: 
			       return;
		     default:
			         cout<<"\a";
		} 
		admin_menu();
 } 
int main() 
{ 
     char ch;
      cout<<"\n\t\t\t\t LIBRARY MANAGEMENT SYSTEM \t\t\t ";
      cout<<" ";
	   do 
	    { 
		  
		   cout<<"\n\n\n\tMAIN MENU"<<endl;
		   cout<<"\n\n\t 01. BOOK ISSUE"<<endl;
	      cout<<"\n\n\t02. BOOK DEPOSIT"<<endl;
			cout<<"\n\n\t03. ADMINISTRATOR MENU"<<endl;
		 cout<<"\n\n\t04. EXIT";
		  cout<<"\n\n\tPlease Select Your Option (1-4) ";
		   ch=getche();
		    switch(ch)
			 {
			  case '1':
			        
					   book_issue();
					    break; 
			 case '2':
			           book_deposit();
					    break;
			case '3':
						 admin_menu();
						  break;
			 case '4':
			          exit(0);
			 default :
			            cout<<"\a";
			 } 
		}while(ch!='4');
	
		delete bk;
		delete st;
 }
