#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<sstream>
using namespace std;

int id;
class bus
{
    fstream fp;
    char seat[8][4][10];
    string uname;
    int rup1,rup2,s_no;
    string pass;
    string from,to;
public:
    void password()
    {
        char ch;
        ch = getch();
        int flag1=0;
        while(ch != 13)
        { if(ch==8)
          {
            for(int i=0;i<flag1;i++)
            cout<<"\b \b";
            pass.erase();
            flag1=0;
          }
        else
          {   pass.push_back(ch);
              cout <<'*';
              flag1++;
          }
          ch = getch();
        }
    }
    void vline(char ch)
    {
      for (int i=80;i>0;i--)
      cout<<ch;
    }
    int show(int b)
    {
            string sent,line;
            if(b>=1000&&b<1006)
            {

                for(int i=0;i<8;i++)
                {   for(int i=0;i<8;i++)
                    {   for(int j=0;j<4;j++)
                        {
                            strcpy(seat[i][j],"-----");
                        }
                    }
                }
                opennn(b,&fp);
                while(getline(fp,line))
                {
                    istringstream wrd(line);
                    for(int f=1;wrd>>sent;f++)
                    {
                        if(f==1)
                            s_no=stoi(sent);
                        if(f==2)
                            strcpy(seat[s_no/4][(s_no%4)-1],sent.c_str());
                    }
                }
                fp.close();
                 //over
                int k=1;
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        cout.width(2);
                        cout<<k<<".";
                        cout.width(10);
                        cout<<seat[i][j];
                        //cout.fill(' ');
                        cout<<"\t";
                        k++;
                    }
                    cout<<"\n";
                }
                return(0);
            }
            else
            {
                cout<<"Invalid bus number...press enter to try again......\n";
                return 1;
            }
    }
    void openn(int bus_no,fstream* temp)
    {
        switch(bus_no)
        {
            case 1000: temp->open("1000.txt",ios::in);break;
            case 1001: temp->open("1001.txt",ios::in);break;
            case 1002: temp->open("1002.txt",ios::in);break;
            case 1003: temp->open("1003.txt",ios::in);break;
            case 1004: temp->open("1004.txt",ios::in);break;
            case 1005: temp->open("1005.txt",ios::in);break;
            default:cout<<"error";break;
        }
    }
    void opennn(int bus_no,fstream* temp)
    {
        switch(bus_no)
        {
            case 1000: temp->open("2000.txt",ios::in);break;
            case 1001: temp->open("2001.txt",ios::in);break;
            case 1002: temp->open("2002.txt",ios::in);break;
            case 1003: temp->open("2003.txt",ios::in);break;
            case 1004: temp->open("2004.txt",ios::in);break;
            case 1005: temp->open("2005.txt",ios::in);break;
            default:cout<<"Invalid bus number..\nPress enter to continue......";break;
        }
    }
    void op_app(int bus_no,fstream* temp)
    {
        switch(bus_no)
        {
            case 1000: temp->open("2000.txt",ios::out|ios::app);break;
            case 1001: temp->open("2001.txt",ios::out|ios::app);break;
            case 1002: temp->open("2002.txt",ios::out|ios::app);break;
            case 1003: temp->open("2003.txt",ios::out|ios::app);break;
            case 1004: temp->open("2004.txt",ios::out|ios::app);break;
            case 1005: temp->open("2005.txt",ios::out|ios::app);break;
            default:cout<<"error";break;
        }
    }
    void signup()
    {
            fstream cur_fp;
            pass.erase();
            cout<<"\t\t\t ---------\n\t\t\t| SIGN UP |\n\t\t\t ---------\n\n";
            cur_fp.open("hello.txt",ios::out|ios::app);
            cur_fp<<"#";
            cout<<"\t\t\t\b\bUsername: ";
            cin>>uname;
            cur_fp<<uname;
            cur_fp<<" <";
            cout<<"\t\t\t\b\bPassword: ";
            password();
            cur_fp<<pass<<"> \n";
            cur_fp.close();
    }
    bool login(bool *ptr)
    {   //login
        fstream cur_fp;
        string user_orig,pass_orig,line;
        id=0;
        pass.erase();
        cout<<"\t\t\t --------\n\t\t\t| LOG IN |\n\t\t\t --------\n\n";
        cout<<"\t\t\t\b\bUsername: ";
        cin>>uname;
        cout<<"\t\t\t\b\bPassword: ";
        password();
        cur_fp.open("hello.txt",ios::in);
        int flag1=0;
        while(getline(cur_fp,line))
        {
            size_t pos1=line.find("#");
            size_t pos2=line.find("<");
            int len=pos2-pos1-2;
            user_orig.assign(line,pos1+1,len);
            id++;
            if(user_orig==uname)
            {
                size_t pos1=line.find("<");
                size_t pos2=line.find(">");
                int len=pos2-pos1-1;
                pass_orig.assign(line,pos1+1,len);

                if(pass_orig==pass)
                {
                    flag1++;
                    break;
                }
            }
          }
        if(flag1==1)
            {
                    *ptr=1;
                    cout<<"\n\nAccess granted..\nPress enter to continue.....";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    cur_fp.close();
                    return 1;
            }
        else
        {
            cout<<"\n\nAccess Denied....";
            return 0;
        }
    }
    int enquiry()
    {
            fstream fp;
            string line,wrd,markk,sent,wrd1,wrd2;
            cout<<"\n\t\t\t -------------\n\t\t\t| BUS ENQUIRY |\n\t\t\t -------------\n\n";
            cout<<"\t\t\tFrom: ";
            cin>>from;
            cout<<"\t\t\tTo: ";
            cin>>to;
            bool milgya = 0;
            for(int i=1000;i<1006;i++)
            {
                string line,arr,dep;
                bool from_flag=0;
                bool to_flag = 0;
                openn(i,&fp);
                while(getline(fp,line))
                {
                    if(line.find(from)!=string::npos)
                    {
                        from_flag = 1;
                        istringstream wrd(line);
                        for(int f=1;wrd>>markk;f++)
                        {
                             if(f==2)
                                  rup1=stoi(markk);
                             if(f==3)
                                  arr=markk;
                             if(f==4)
                                  dep=markk;
                        }
                    }
                    if(from_flag == 1)
                    {
                        if(line.find(to)!=string::npos)
                        {
                            to_flag = 1;
                            milgya = 1;
                            istringstream wrd(line);
                            for(int f=1;wrd>>markk;f++)
                                if(f==2)
                                {
                                    rup2=stoi(markk);
                                }
                        }
                    }
                }
               fp.close();
               if(to_flag == 1)
                {
                    cout<<"\n\n"<<"BUS NO.: "<<i<<"\tROUTE: ";
                    openn(i,&fp);
                    while(getline(fp,sent))
                    {
                        istringstream wrd(sent);
                        for(int f=1;wrd>>markk;f++)
                            if(f==1)
                            {
                            cout<<markk<<" ";
                            }
                    }
                    cout<<"\n\t\tARRIVAL: "<<arr<<"\tDEPARTURE: "<<dep<<"\t  FARE: "<<rup2-rup1<<"/-\n";
                    vline('*');
                    fp.close();
                    fp.open("ticket.txt",ios::out);
                    fp<<rup2-rup1;
                    fp.close();
                }
            }
            if(milgya==0)
            {
                cout<<"\nNo bus available for this route....\nPress enter to continue......";
                cin.ignore();
                cin.get();
                return(1);
            }
            else
            {
                return 0;
            }
    }
    void bhist()
    {
        fstream fp;
        string line,num;
        int y,g=0;
        fp.open("id.txt",ios::in);
        while(getline(fp,line))
        {
            istringstream wrd(line);
            for(int f=1;wrd>>num;f++)
            {
                if(f==1)
                {
                    if(stoi(num)==id)
                    { g++;
                        for(y=1;wrd>>num;y++)
                        {
                                if(y==1)
                                    cout<<" NAME: "<<num;
                                if(y==2)
                                    cout<<"\tBUS NO.: "<<num;
                                if(y==3)
                                    cout<<"\tFROM: "<<num;
                                if(y==4)
                                    cout<<"\tTO: "<<num;
                                if(y==5)
                                    cout<<"\tFARE: "<<num<<"/-\n";
                        }
                      vline('-');
                      cout<<"\n";
                    }
                }
            }
        }
        if(g==0)
        {
            cout<<"\n\t\t\tNo bookings yet....";
        }
        getch();
    }
    void book(int b)
    {
             fstream fp;
             int l=0;
             string name,line,sent,date;
             int s_no,fare;
             char seat[8][4][10];
             if(b>=1000&&b<1006)
             {
               show(b);
             for(int i=0;i<8;i++)
             {
                for(int j=0;j<4;j++)
                {
                    strcpy(seat[i][j],"-----");
                }
            }
            opennn(b,&fp);
            }
            else
            {
                opennn(b,&fp);
                goto finish;
            }
            while(getline(fp,line))
            {   istringstream wrd(line);
                for(int f=1;wrd>>sent;f++)
                {
                    if(f==1)
                        s_no=stoi(sent);
                    if(f==2)
                        strcpy(seat[s_no/4][(s_no%4)-1],sent.c_str());
                }
            }
            fp.close();
            seat:
            int num;
            cout<<"\n\nEnter number of seats to be booked: ";
            cin>>num;
            for(int i=1;i<=num;i++)
            {

            cout<<"\nEnter seat number: ";
            cin>>s_no;
            if(s_no>32)
            {
                cout<<"We only have 32 seats...\nEnter valid seat number....\n\n";
                goto seat;
            }
            else
            {     if (strcmp(seat[s_no/4][(s_no%4)-1],"-----")==0)
                  { cout<<"Enter passangers name: ";
                    cin>>name;
                    op_app(b,&fp);
                    fp<<s_no<<" ";
                    fp<<name<<endl;
                    fp.close();
                    cout<<endl<<endl;
                    cout<<"TICKET:-\n\n";
                    vline('*');
                    fp.open("ticket.txt",ios::in);
                    fp>>fare;
                    fp.close();
                    cout<<"\nNAME: "<<name<<"\tBUS NO.: "<<b<<"\tSEAT NO.: "<<s_no<<"\nFROM: "<<from<<"\tTO: "<<to<<"\tFARE: "<<fare<<"/-"<<"\n";
                    vline('*');
                    cout<<endl;
                    fp.open("id.txt",ios::out|ios::app);
                    fp<<"\n"<<id<<" "<<name<<" "<<b<<" "<<from<<" "<<to<<" "<<fare;
                    fp.close();
                  }
                  else
                  {
                      cout<<"This seat is already booked...";
                      cout<<"Choose another seat.....";
                      goto seat;
                  }
            }
            }
            finish:
            getch();
       }
};
int main()
{   bus obj;
    int k,h,bus_no,m;
    bool decision=0;
    while(1)
    {   system("cls");
        cout<<"\t\t\t ==============================\n";
        cout<<"\t\t\t| ONLINE TICKET BOOKING SYSTEM |\n";
        cout<<"\t\t\t ==============================\n\n";
        cout<<"\t\t\t1. Sign_up\n\t\t\t2. Log_in\n\t\t\t3. Exit\n\n\t\t\tChoose an option: ";
        cin>>k;
        system("cls");
        switch(k)
        {
            case 1:obj.signup();break;
            case 2:obj.login(&decision);
            if(decision==1)
            {
                    bfirst:
                    system("cls");
                    cout<<"\n\t\t\tChoose the desirable option:\n\n";
                    cout<<"\t\t\t1. Bus Enquiry\n\t\t\t2. Booking history\n\t\t\t3. Log_out\n\t\t\t4. Exit\n\n\t\t\tChoose an option: ";
                    cin>>h;
                    system("cls");
                    switch(h)
                    {
                        case 1:m=0;
                               m=obj.enquiry();
                               if(m==1)
                                  {
                                   goto bfirst;
                                  }
                               else
                               {   sfirst:
                                   cout<<"\n\n\t\t\t1. Book now\n\t\t\t2. Show available seats\n\t\t\t3. Log_out\n\t\t\t4. Exit\n\n\t\t\tChoose an option: ";
                                   cin>>h;
                                   system("cls");
                                   switch(h)
                                   {
                                       case 1:  cout<<"\n\t\t\t ---------\n\t\t\t| BOOKING |\n\t\t\t ---------\n\n";
                                                cout<<"\t\t   Enter bus no.: ";
                                                cin>>bus_no;
                                                cout<<endl;
                                                obj.book(bus_no);
                                                goto bfirst;

                                       case 3:decision=0;break;
                                       case 2: {int p=0;
                                                cout<<"\n\t\t\tSEAT MATRIX\n\t\t\t-----------\n\n";
                                                cout<<"\t\t   Enter bus number: ";
                                                cin>>bus_no;
                                                cout<<endl;
                                                p=obj.show(bus_no);
                                                cin.ignore();
                                                cin.get();
                                                if(p==0)
                                                    goto sfirst;
                                                else
                                                    goto bfirst;
                                                }
                                       case 4:exit(0);break;
                                   }
                               }
                        case 2:cout<<"\t\t\tBOOKING HISTORY\n\t\t\t---------------\n\n";
                               obj.bhist();
                               goto bfirst;
                        case 3:decision=0;break;
                        case 4:exit(0);
                        default:cout<<"Wrong choice...\npress enter to retry.....";getch();
                                goto bfirst;
                    }
            }
            else
            {           cout<<"\npress enter to retry...";
                        cin.ignore();
                        cin.get();
            };
            break;
            case 3:exit(0);
            default:cout<<"Wrong choice...\npress enter to retry.....";getch();break;
        }
    }
    cin.get();
}
