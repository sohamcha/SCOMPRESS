// SCOMPRESS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;


struct dictnode {
    char val;
    int index;
    struct dictnode *prev;
    struct dictnode *next;
};

typedef struct dictnode node;




string find(node *head,int n)
{
     node *temp=head;
     string str;
     while(temp!=NULL)
     {
         if(temp->index==n)
         break;
         temp=temp->next;
         }
         if(temp==NULL)
          cout<<"\nWORD NOT PRESENT ";
         else
         {
             cout<<endl;
             while(temp!=NULL)
             {
             str.insert(0,1,temp->val);               // Very Crucial !!!!!!  Reversing the Word from dictionary to correct Order.
             temp=temp->prev;
             }
             cout<<str;
             return str;
         }
        
         }



node * initdict(node *head)
{
    node *temp,*temp1;
    int value=97;
    head = new node;
    head->index=0;
    head->prev=head->next=NULL;
    head->val=value++;
    temp1=head;
    for(int i=1;i<26;i++)
    {
        temp = new node;
        temp->index=i;
        temp->prev=NULL;
        temp->val=value++;
        temp1->next=temp;
        temp1=temp;
    }
    temp1->next=NULL;
    return head;
}


void showdict(node *head)
{
     node *temp=head;
     while(temp!=NULL)
     {
                      cout<<endl<<temp->index<<" : "<<temp->val;
                      temp=temp->next;
                      }
                      }
                      


void close(fstream *f1,fstream *f2)
{
    f1->close();
    f2->close();
}


int getindex(node *p)
{
    return p->index;
}


node *gettail(node *head)
{
     node *tmp=head;
     while(tmp->next!=NULL)
     tmp=tmp->next;
     return tmp;
     }


void insval(node *head,char c)
{
     node *tail,*temp;
     tail=gettail(head);
     temp = new node;
        temp->index=(tail->index)+1;
        temp->prev=NULL;
        temp->val=c;
        temp->next=NULL;
        tail->next=temp;
        }



node * search(node *head,char c)
{
    node *temp=head;
    while(temp!=NULL)
    {
                     if(temp->val==c)
                     {
                                     return temp;
                                     }
                                     temp=temp->next;
                                     }
                                     return temp;
                                     }




node * searchprev(node *head,string *str)
{
int length,i;
char cur,prev,tmp;
node *temp=head,*prevs,*retn=NULL;
length=str->length();
cout<<"\nCHECKING "<<*str;
if(length==1)
{
prevs=search(head,(*str)[0]);
return prevs;
}
else
{
    i=length-1;
    cur=(*str)[i];
    while(temp!=NULL)
    {
        if((temp->val==cur)&&(temp->prev!=NULL))
        {
             retn = temp;
             while(i>0)
             {
               i--;
               temp=temp->prev;
               if((temp!=NULL)&&(temp->val==(*str)[i]))
               continue;
               else
               {
                   i=length-1;
                   temp=retn;
                   break;
                   }
                   }
             if((i==0)&&(temp->prev==NULL))    //  NEW CLAUSE ADDED ---> Requires Checking !!!!
                   return retn;
             else                              //  NEW CLAUSE ADDED  ----->  Requires checking
             {
                 i=length-1;
                 temp=retn;
             }
              }
                   temp=temp->next;
                   }
                   return temp;
                   }
                   }
            
                
void showwords(node *head)
{
     string str;
     node *temp=head,*start;
     while(temp!=NULL)
     {
          start=temp;
          while(start!=NULL)
          {
              // cout<<start->val;
               str.insert(0,1,start->val);
               start=start->prev;
               }
               cout<<endl<<str;
               str.erase();
               temp=temp->next;
               }
               }           


void strinsert(string p,node *head)
{
    node *temp,*tail,*prevs;
    node * search(node *,char); 
    string *tmp;
    int i=0,j=0,k=0,check=1;
    
    cout<<"\nSIZE OF STRING : "<<p.length();   // upto here ----> Then Breaks  <----  ( Now Doesn't )
    tail=gettail(head);
    tmp=new string;
    while(i<p.length())
    {
       tmp->push_back(p[i]);
       if(searchprev(head,tmp)==NULL)                     // searchprev() returns the pointer to the last character if string is present. Else NULL.
       {
           temp = new node;
           temp->index=(tail->index)+1;
           temp->val=p[i];
           tmp->resize((tmp->length())-1);
           temp->prev=searchprev(head,tmp);          // <----- searchprev() returns the pointer to the last character here
           temp->next=NULL;
           tail->next=temp;
           tail=temp;
           tmp->erase();
           tmp->push_back(p[i]);                // As the next interation will have the last character of previous string
          // showwords(head);                      // <----- FOR DEBUGGING
           }
           i++;
           }
           }  
            



string * getpermutation(string s1)
{
    void lexisort(string *,int);
    int k=0;
    int size=s1.length();
    char temp;
    string *sarray = new string[size];
    sarray[k++]=s1;
    while(k<size)                    // index changed back to < from <=
    {
        temp=s1[0];
        s1.erase(0,1);
        s1.push_back(temp);
        sarray[k++]=s1;
       
    
    }
    
  /*  for(int i=0;i<k;i++)                          // for debugging
        cout<<sarray[i]<<endl;   */                     // ------>  WORKING FINE  <-------    Verified
    
 
    lexisort(sarray,size);
    
    for(int i=0;i<k;i++)                          // for debugging
        cout<<sarray[i]<<endl;                            // ------>  WORKING FINE  <-------     Verified
    
    return(sarray);

}




void lexisort(string *tosort,int size)
{
       int i=0,j=0,n;
       string temp;
       for(j=1;j<size;j++)
       {
       for(i=0;i<size-j;i++)
       {    
       if(tosort[i].compare(tosort[i+1])>=0)
       {
         temp=tosort[i];
         tosort[i]=tosort[i+1];
         tosort[i+1]=temp;
         }
         }
         }
        
           
      
}
               




int _tmain(int argc, _TCHAR* argv[])
{
	
   node *head=NULL,*prev,*tail,*temp;
   fstream file,file2;
   string filename,tempstring,*finalstring,*sortedstring,insstring,finalstr,numstring;
   int NO_OF_CHUNKS,i=0,j=0,count=0,present,rle=0,flag=0,searchval;        
   long size,CHUNK_SIZE;
   char *buffer,ch,c;
   float orisize,cursize;
   
   
   int choice;

   cout<<"***** SCOMPRESS - the General Purpose Compression Tool ( V 0.5 Alpha DATED : 7/17/2011 Compiled in VC++ 2010 / .NEt 4 ) ***** \n\n - Soham Chakraborty \n\n";
   
   cout<<"ENTER YOUR CHOICE : \n1)Compress File\n2)Decompress File\n3)About the Program\n4)File Info\n5)Exit\n\n";
   
   
   do
   {
   cin>>choice;
   
   
   if(choice==3)
   {
   
       cout<<"This is an Alpha release of a General Purpose Compression Tool using the Burrows-Wheeler Transformation and then employing Both LZW Compression Algorithm and the RUN Length Encoding Algorithm as a HomeBrew project by SOHAM CHAKRABORTY.\nHe needs your support. Please do so by Using This. It is totally Free to use and Distribute.\n";
   }
   
   
   if(choice==4)
   {
        cout<<"Enter the Filename for the operation with extension ";
       
        cin>>filename;
        
        file.open(filename,ios::in | ios::out);

        size = file.tellg();
       
        file.seekg(0,ios::end);
       
        size = -1 * (size - file.tellg());
       
        orisize = (float)size;
        
        file.seekg(0,ios::beg);
       
        cout<<"\nTHE FILE SIZE IS : "<<size<<" Bytes ";
   
        file.close();
   }
   if(choice==1)
   {
       cout<<"Enter the Filename for the operation with extension ";
       
       cin>>filename;
       
       file.open(filename,ios::in | ios::out);
      // file2.open("REDUNDANT-File.txt",ios::out);
       
       if(file.is_open())
       {
       
           
       size = file.tellg();
       
       file.seekg(0,ios::end);
       
       size = -1 * (size - file.tellg());
       
       orisize = size;
       
       file.seekg(0,ios::beg);
       
       cout<<"\nTHE FILE SIZE IS : "<<size<<" Bytes ";
       
      /*  cout<<"ENTER THE CHUNK SIZE to Fragment the File ";               // CHUNK Algo. was a Bitch !!!!!
       
       cin>>CHUNK_SIZE;  
       
       NO_OF_CHUNKS = (size/CHUNK_SIZE)+1;   */
       
       
               
       }        
              
               
           else
           cout<<"\nUNABLE TO OPEN FILE ";
   
      
     
       file.close();
        i=j=0;
        
        cout<<"\n\nWHICH COMPRESSION METHOD : \n1)RLE - Run Length Encoding\n2)LZW - Lempel Ziv Welch\n\n";
        cin>>rle;

        if(rle==2)                       //  LZW STARTING
        {
        head=initdict(head);     // To Initialize the dictionary            
        
        cout<<"\nEnter the EOF Character used in your FILE to be included in Dictionary and Any Special Characters present";
        
        do
        {
        cin>>ch;
        insval(head,ch);                                           
        cout<<"\nEnter Another one ??? y/n ";
        cin>>ch;
        j++;
        }while(ch!='n'); 

                                //   New Experimental Additions
        insval(head,32);                          //   NEWLINE is NOT WORKING   
        j++;

        insval(head,'`');       //   New Addition for NEWLINE    (7.15.2011)
        j++;                       
        
        cout<<endl<<"NOW Opening Files for TEXT COMPRESSION : ";
        
        system("PAUSE");
        
      //  file.open("REDUNDANT-File.txt",ios::in|ios::out);                           // For Compression Ratio performance testing  ----> Observation : Performance is lower if Burrows Wheeler Transform is applied to LZW
        
        file.open(filename,ios::in|ios::out);
        
        file2.open("OUTPUT-LZW.txt",ios::out);
        
        cout<<"\nFILES OPENED \n";
        
        tempstring.erase();
        
        tail=gettail(head);
        
        while(file.good())
        {
            file.get(ch);
          
            if(ch==10)
                ch='`';                               // (7.15.2011)

            tempstring.push_back(ch);
            
            prev=searchprev(head,&tempstring);
            
            if(prev==NULL)
            {
                temp = new node;
            
                temp->index=(tail->index)+1;
                
                temp->val=ch;
                
                tempstring.resize(tempstring.length()-1);
                
                prev=searchprev(head,&tempstring);
                
                temp->prev=prev;          // <----- searchprev() returns the pointer to the last character here
                
                temp->next=NULL;
                
                tail->next=temp;
                
                tail=temp;
                
                if(prev->index<(26+j))
                file2<<prev->val;
                else
                {
                 file2<<prev->index;
                 file2<<'$';                     //  $ is the INDEX DELIMITER
                }
                
                tempstring.erase();
                
                tempstring.push_back(ch);
            }
               
       }
   
        tempstring.resize(tempstring.length()-1);       
        cout<<"\nFINAL STR : "<<tempstring;      
           if(tempstring.length()==1)
                     file2<<tempstring[0];
                 
           if(tempstring.length()>1)
                 {
                     prev=searchprev(head,&tempstring);
                    // cout<<"The VALUE IS : "<<prev->val;
                     file2<<prev->index;
                 }  
        }                                            //   LZW ENDING

        else
        {
            
       file.open(filename,ios::in|ios::out);
       file2.open("REDUNDANT-File.txt",ios::out);     
       buffer = new char[size];                                //  RLE STARTING
       while(file.good())
       {
           file.get(c);
           if(c==10)
           buffer[i++]='`';                          // file.get(buffer[i++]);  (7.15.2011)
           else
               buffer[i++]=c;
       }

      // size = i-1;     //  NEW ACTUAL STRING SIZE
     
           for(count=0;count<i-1;count++)           //  SIZE CHANGED TO i-1   (7.15.2011)
           tempstring.append(1,buffer[j++]);
           tempstring.append(1,'~');                     // ' ~ ' IS THE MODIFIED EOF for This ALGO
                                                    //  tempstring[i].erase((tempstring[i].length())-1,1);   // Only for NewLine within sentense
           cout<<"\nLength of Temporary String = SIZE + 1 = "<<tempstring.length()<<endl;
            
            
            sortedstring=getpermutation(tempstring);   // gets the lexicographic sorted strings of circular permutation
            
          /*  for(int p=0;p<tempstring[i].length();p++)                 // ------->  Working Fine  <-------  Verified
                cout<<endl<<sortedstring[p];      */               
            
            
            cout<<"\nSIZE of Sorted String : "<<sortedstring->length();
            for(j=0;j<tempstring.length();j++)
            file2 << sortedstring[j][tempstring.length()-1];          //final check                                           // buffer[j]=sortedstring[j][tempstring[i].length()-1];   // needs checking                                           
            size = tempstring.length();
            cout<<"\nResetting Memory ";
            memset(buffer,0,sizeof(buffer));
           // delete[] buffer;
          //  buffer = new char[size];         // USED MEMSET  (7.15.2011)
                
       

        cout<<endl<<"\nCOMPLETED Creating REDUNDANT DATA FILE.\n\nProceeding to Create COMPRESSED FILE ";    
        system("PAUSE");
        close(&file,&file2);
       
         i=j=0;
            
            
            cout<<endl<<"\nNOW Opening Files for TEXT COMPRESSION : ";
        
            system("PAUSE");
        
            file.open("REDUNDANT-File.txt",ios::in|ios::out);
         
            file2.open("OUTPUT-RLE.txt",ios::out);

            tempstring.erase();

            count=0;

            while(file.good())
            {
                file.get(ch);
                tempstring.push_back(ch);
            }
            tempstring.resize(tempstring.size()-1);
            
            cout<<"\nFile COPIED to Temporary String .\n\nRUNNING RLE : ";
            system("PAUSE");

            while(i<tempstring.length())
            {
                ch=tempstring[i];
                while((tempstring[i]==ch)&&(i<tempstring.length()))
                {
                    count++;
                    i++;
                    if(i==tempstring.length())
                        break;
                }
                file2<<ch;
                if(count>1)
                file2<<count;
                count=0;
            }

            cout<<"\nRLE Completed.\n";
            system("PAUSE");
            
             }   
        
        
        
        
        
        
                 cout<<"\nTHE COMPRESSION PROCESS is COMPLETED. \n\nThe Output can be Obtained from OUTPUT-RLE.txt or OUTPUT-LZW.txt ";
                 tempstring.erase();
                 system("PAUSE");
                 close(&file,&file2);
                 system("del REDUNDANT-File.txt");

                  if(rle==1)
                  file.open("OUTPUT-RLE.txt",ios::in | ios::out);
                  else
                  file.open("OUTPUT-LZW.txt",ios::in | ios::out);

                  size = file.tellg();
       
                  file.seekg(0,ios::end);
        
                  size = -1 * (size - file.tellg());
       
                  cursize = (float)size;
        
                  file.seekg(0,ios::beg);
       
                  cout<<"\nTHE COMPRESSION RATIO IS : "<<((cursize/orisize)*100)<<" % "<<endl;
   
                  file.close();

                  system("PAUSE");

 }


 if(choice==2)
 {
     cout<<"\nEnter the FILENAME with Extension to Decompress : ";
     cin>>filename;
     file.open(filename,ios::out|ios::in);
     file2.open("ORIGINAL-FILE.txt",ios::out);
     cout<<"\nNow CHOOSE the Type of Compression Method used to Compress the FILE : \n1)RLE - Run Length Encoding\n2)LZW - Lempel Ziv Welch  ";
     cin>>rle;

        size = file.tellg();
       
        file.seekg(0,ios::end);
       
        size = -1 * (size - file.tellg());
       
        file.seekg(0,ios::beg);
       
        cout<<"\nTHE FILE SIZE IS : "<<size<<" Bytes ";

        system("PAUSE");

        if(rle==1)
        {
            cout<<"\n\nRUNNING RLE DECODING . . . . \n";
            system("PAUSE");

            while(file.good())
            {
                file.get(ch);
                tempstring.push_back(ch);
            }
            tempstring.resize(tempstring.size()-1);
            
            //cout<<tempstring;           // for debugging
            
            insstring.erase();
            finalstr.erase();
            i=j=0;
            
            while(i<tempstring.length())
          {
          ch=tempstring[i++];
          if(i<tempstring.length())
          {
          while(((tempstring[i]>47)&&(tempstring[i]<58))&&(i<tempstring.length()))
          {
              insstring.push_back(tempstring[i]);
              i++;
              flag=1;
            if(i==tempstring.length())
            break;   
            }
          }
            if(flag==1)
            {
            count=atoi(insstring.c_str());
           // cout<<"\nNo. of occurence of "<<ch<<" is "<<count;
            for(j=0;j<count;j++)
            finalstr.push_back(ch);
            flag=0;
            }
            else
            finalstr.push_back(ch);
            insstring.erase();
            
            }

                                                 
            cout<<"\nINVERSE RLE COMPLETED . . . . ";
            system("PAUSE");
         
         //   cout<<endl<<"Final String : "<<finalstr;

            cout<<"\nNow Proceeding to Inverse Burrows Wheeler Transform . . . . ";
            system("PAUSE");                                                                 //  <-----  BUG FIXED
            cout<<"\nPLEASE WAIT . . . . .\n";
            i=j=0;

            finalstring=new string[finalstr.length()];
            while(j<finalstr.length())
            {
            for(i=0;i<finalstr.length();i++)
                finalstring[i].insert(0,1,finalstr[i]);
            lexisort(finalstring,finalstr.length());
            j++;
            }

            for(i=0;i<finalstr.length();i++)
            {
                if(finalstring[i][finalstr.length()-1]=='~')
                    break;
            }

            cout<<"\nThe Original File has the contents : "<<finalstring[i];
            finalstring[i].resize(finalstring[i].length()-1);
            
            
            for(int k=0;k<finalstring[i].length();k++)            //  NEW CODE ADDED FOR ENABLING NEWLINES    (7.15.2011)
            {
                if(finalstring[i][k] == '`')
                    finalstring[i][k] = '\n';
            }
            
            
            file2 << finalstring[i];
            cout<<"\nWRITING COMPLETED . . .  Please Check the ORIGINAL-FILE.txt for Decrypted File. Thank you for using . \n\n";
            system("PAUSE");

            close(&file,&file2);
        }


        else
        {
            cout<<"\n\nRUNNING Inverse LZW DECODING . . . . \n";
            system("PAUSE");
            
            head=initdict(head);     // To Initialize the dictionary
        
            cout<<"\nEnter the EOF Character used in your FILE to be included in Dictionary and Any Special Characters present";
        
        do
        {
        cin>>ch;
        insval(head,ch);                                           
        cout<<"\nEnter Another one ??? y/n ";
        cin>>ch;
        j++;
        }while(ch!='n');    

                                //   New Experimental Additions
        insval(head,32);                          // (OLD NEWS) --->  NEWLINE is NOT WORKING   
        j++;

        insval(head,'`');          //  FOR ENABLING NEWLINE   (7.15.2011)
        j++;
        
        cout<<endl<<"NOW Opening Files for TEXT DECOMPRESSION : \n";
        
        system("PAUSE");
            

            insstring.erase();
            finalstr.erase();
            i=j=0;

            tail=gettail(head);
        
            while(file.good())
            {
                file.get(ch);
                finalstr.push_back(ch);
            }
            finalstr.resize(finalstr.length()-1);
            
            cout<<"\nFILE CONTENTS : "<<endl<<finalstr<<endl;
            system("PAUSE");
            while(i<finalstr.length())
        {
            
            ch=finalstr[i];
           
            if(flag==0)
            {
            if((ch>48)&&(ch<58))
            {
                while(true)
                {
               
                ch=finalstr[i];
                numstring.push_back(ch);
                i++;
                
                  if(finalstr[i]=='$')
                {
                    ch=finalstr[i-1];
                    break;
                }
                
                if(i>=finalstr.length())
                {
                    i--;
                    ch=finalstr[i];
                    break;
                }
  
                }

                searchval=atoi(numstring.c_str());
                cout<<"\nCURRENT SEARCHVAL : "<<searchval;
                if(tail->index>=searchval)
                insstring = find(head,searchval);
                else
                    {       
                        cout<<"\nSearchVal : "<<searchval<<" OUT OF BOUNDS\n";
                        insstring = tempstring;
                        insstring.push_back(tempstring[0]);
                    }
                        
                                                               
                numstring.erase();
                flag=1;
                cout<<"INSSTRING : "<<insstring<<endl;
            }
            }
            
            if(flag==0)
            tempstring.push_back(ch);
            
            else
            {
                cout<<"\nSize of Insstring : "<<insstring.length();
                tempstring.push_back(insstring[j++]);
                ch=insstring[j-1];
                if(j==insstring.length())
                {
                   j=0;
                   flag=0;
                   insstring.erase();
                   cout<<"\nINSSTRING ERASED ";
                }
            }
            prev=searchprev(head,&tempstring);
            
            if(prev==NULL)
            {
                temp = new node;
            
                temp->index=(tail->index)+1;
                
                temp->val=ch;
                
                tempstring.resize(tempstring.length()-1);
                
                prev=searchprev(head,&tempstring);
                
                temp->prev=prev;          // <----- searchprev() returns the pointer to the last character here
                
                temp->next=NULL;
                
                tail->next=temp;
                
                tail=temp;
                
                cout<<"\n NEW TAIL INDEX : "<<tail->index;
                
                for(int k=0;k<tempstring.length();k++)            //  NEW CODE ADDED FOR ENABLING NEWLINES   (7.15.2011)
            {
                if(tempstring[k] == '`')
                   tempstring[k] = '\n';
            }
                
                file2<<tempstring;
              /*  else
                file2<<prev->index;   */            // <-----  This part was for Encoding
                
                tempstring.erase();
                
                tempstring.push_back(ch);
            }
               
            if(flag==0)
            i++;
            }

            cout<<"\nFinal Remaining String is : "<<tempstring;
                 for(int k=0;k<tempstring.length();k++)            //  NEW CODE ADDED FOR ENABLING NEWLINES   (7.15.2011)
            {
                if(tempstring[k] == '`')
                   tempstring[k] = '\n';
            }
            file2<<tempstring;

            cout<<"\nWRITING COMPLETED . . .  Please Check the ORIGINAL-FILE.txt for Decrypted File. Thank you for using . \n\n";
            system("PAUSE");

            close(&file,&file2);
            
           
        
            }


 }

}while(choice!=5);
   
return 0;

}
