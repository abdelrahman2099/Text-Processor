#include <bits/stdc++.h>

using namespace std;
void Read(char filename[],string& x)
{
    fstream file;
    char read1;
    file.open(filename,ios::in);
    while(file.get(read1)){
        x+=read1;
    }
    file.close();
}
void counter(char filename[]){
    string x="";
    int l=0,k=0;
    Read(filename,x);
    for (int i=1;i<x.length();i++){
        if ((x[i]==' '&&x[i-1]!=' ')||(x[i]=='\n'&&x[i-1]!=' '))
            l++;
        if(!(x[i]==' '||x[i]=='\n'))
            k++;
    }
    l++;
    k++;
    cout<<"the number of words is "<<l<<" and the number of characters is"<<k<<endl;
}
void Search(char filename[],string y1)
{
        bool q=false;
        string x="",y="",z="";
        Read(filename,x);
        for(int i=0;i<y1.length();i++){
            y+=tolower(y1[i]);
        }
        for (int i=0;i<x.length();i++){
            if(x[i]==' '||x[i]=='\n'){
                if (y==z){
                    q=true;
                    break;
                }
                z="";
            }
            else{
                z+=tolower(x[i]);
            }
        }
        if(y==z){
            q=true;
        }
        if(q==true)
            cout<<"Word is found in the file :)\n";
        else
            cout<<"Word is not found in the file :(\n";

}
void Empty(char filename[])
{
    fstream file;
    file.open(filename,ios::out);
    file.close();
}
void Add(char filename[],string x)
{
    fstream file;
    file.open(filename,ios::app);
    file<<x;
    file.close();
}
void Replace(char filename[],string a,string d)
{
    fstream file;
    string x="",y="",z="",y2="";
    Read(filename,x);
    for(int i=0;i<a.length();i++){
        y+=tolower(a[i]);
    }
    for (int i=0;i<x.length();i++){
        if(x[i]==' '||x[i]=='\n'){
            if (y==z){
                z=d;
            }
            y2 += z;
            y2 += x[i];
            z="";
        }
        else{
            z+=tolower(x[i]);
        }}
    y2 += z;
    file.open(filename,ios::out);
    file<<y2;
    file.close();
}
void Upper(char filename[])
{
    fstream file;
    string x="",y="";
    Read(filename,x);
    for(int i=0;i<x.length();i++){
        y += toupper(x[i]);
    }
    file.open(filename,ios::out);
    file<<y;
    file.close();
}
void Lower(char filename[])
{
    fstream file;
    string x="",y="";
    Read(filename,x);
    for(int i=0;i<x.length();i++){
        y += tolower(x[i]);
    }
    file.open(filename,ios::out);
    file<<y;
    file.close();
}
void AddF(char filename[],char anotherfile[])
{
    string x="";
    fstream file;
    file.open(filename,ios::app);
    Read(anotherfile,x);
    file<<x;
    file.close();
}
void Encrypt(char filename[])
{
    fstream file;
    string x="",y="";
    Read(filename,x);
    char a[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
                };
    char b[]= {'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m',
                'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'
                };
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<56; j++){
            if (x[i]==a[j]){
                y+=b[j];
                break;
            }
        }
        if (i!=(y.length())-1){
            y+=x[i];
        }
    }
    file.open(filename,ios::out);
    file<<y;
    file.close();
}
void Decrypt(char filename[])
{
    fstream file;
    string x="",y="";
    Read(filename,x);
    char a[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
                };
    char b[]= {'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m',
                'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'
                };
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<56; j++){
            if (x[i]==b[j]){
                y+=a[j];
                break;
            }
        }
        if (i!=(y.length())-1){
            y+=x[i];
        }
    file.open(filename,ios::out);
    file<<y;
    file.close();
    }
}
int main()
{
    while(true){
    string x="",y1="",y="";
    fstream file;
    char filename[1000],read1,anotherfile[1000],read[1000];
    cout<<"Ahlan ya user ya hbibi.\nWhat do you like to do today?\n1- Load an existing file\n2- Create a new file\n";
    cout<<"3- Display file content\n4- Save the loaded text to the same file again or different one\n";
    cout<<"5-Count the words and the characters in the file\n6-Search for a word in a file\n7-Empty file content\n";
    cout<<"8-add more content to the end of the file\n9-replace a word in the file with another word\n";
    cout<<"10- turn all characters to uppercase\n11- turn all characters to lowercase\n";
    cout<<"12- Add another file to the end of the current file\n13- Encrypt and decrypt the file\nE- End\n>>";
    string n;
    while(true){
        cin>>n;
        if (n=="1"||n=="2"||n=="3"||n=="4"||n=="5"||n=="6"||n=="7"||n=="8"||n=="9"||n=="10"||n=="11"||n=="12"||n=="13"||n=="E")
            break;
        else
            cout<<"choose from 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 or 10 or 11 or 12 or 13 or E\n>>";
    }
    if (n=="1"){
        cout<<"Enter the file name to load\n>>";
        enter1:cin.ignore();
        cin.getline(filename,1000);
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
    }
    else if (n=="2"){
        cout<<"Enter the file name to create\n>>";
        cin.ignore();
        cin.getline(filename,1000);
        file.open(filename,ios::out);
        file.close();
    }
    else if (n=="3"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        while(file.getline(read,1000)){
            cout<<read<<endl;
        }
        file.close();
    }
    else if (n=="4"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        cin.ignore();
        cout<<"Enter the file name to save loaded content in it\n>>";
        cin.getline(anotherfile,1000);
        while(file.get(read1)){
            x+=read1;
        }
        file.close();

        if(anotherfile==filename)
            cout<<"saved in the same file.";
        else{
            file.open(anotherfile,ios::out);
            file<<x;
            file.close();
        }
    }
    else if (n=="5"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        counter(filename);
    }
    else if (n=="6"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        cout<<"Enter the word : ";
        cin>>y1;
        Search(filename,y1);
    }
    else if (n=="7"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        Empty(filename);
    }
    else if (n=="8"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        cout<<"please start writing "<<endl;
        string x;
        cin.ignore();
        getline(cin,x);
        Add(filename,x);
    }
    else if (n=="9"){
        string a,d;
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        cout<<"enter the word u want to change"<<endl;
        cin>>a;
        cout<<"enter new word"<<endl;
        cin>>d;
        Replace(filename,a,d);
    }
    else if (n=="10"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        Upper(filename);
    }
    else if (n=="11"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        Lower(filename);
    }
    else if (n=="12"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        cout<<"Enter the name of the another file :";
        cin.ignore();
        cin.getline(anotherfile,1000);
        AddF(filename,anotherfile);
    }
    else if (n=="13"){
        file.open(filename,ios::in);
        if(file.fail()){
            cout<<"File open error!\nEnter the name again\n<<";
            goto enter1;
        }
        file.close();
        string q;
        bool isOpen=true;
        cout<<"\nWhat do you like to do today? \n1- Cipher a message \n2- Decipher a message \n>> ";
        while (isOpen)
        {
        cin>>q;
        if (q=="1"||q=="2")
            isOpen=false;
        else
            cout<<"choose from 1 or 2 \n>>";
        }
        if (q == "1"){
            Encrypt(filename);
        }
        else if (q=="2"){
            Decrypt(filename);
        }
    }
    else if (n=="E"){
     return 0;
    }
    }
}
