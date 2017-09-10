#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

class String
{
    char *mdata;
public:
    String();
    ~String();
    String(const char *data);
    String(const String &other);
    String operator+(const String &other);
    String &operator=(const String &other);
    int cmp(String str1, String str2);
    friend ostream& operator<<(ostream&, String&);
};

String::String()
{
    mdata=new char[1];
    mdata[0]='\0';
}

String::~String()
{
    delete[] mdata;
    mdata=NULL;
    cout<<"killed"<<endl;
}

String::String(const char *data)
{
    if(data==NULL)
    {
        mdata=new char[1];
        mdata[0]='\0';
    }
    else
    {
        mdata=new char[strlen(data)+1];
        strcpy(mdata, data);
    }
}

String::String(const String& other)
{
    mdata=new char[strlen(other.mdata)+1];
    strcpy(mdata, other.mdata);
}

String String::operator+(const String &other)
{
    String ret;
    delete[] ret.mdata;
    ret.mdata=new char[strlen(mdata)+strlen(other.mdata)+1];
    strcpy(ret.mdata, mdata);
    strcat(ret.mdata, other.mdata);
    return ret;
}

ostream &operator<<(ostream &output, String &str)
{
    int len=strlen(str.mdata);
    for(int i=0; i<len; i++)
        output<<str.mdata[i];
    return output;
}

String& String::operator=(const String &other)
{
    if(this==&other)
        return *this;
    delete[] mdata;
    mdata=new char[strlen(other.mdata)+1];
    strcpy(mdata, other.mdata);
    return *this;
}

int String::cmp(String str1, String str2)
{
    return strcmp(str1.mdata, str2.mdata);
}

int main()
{
    String str;
    String str1="abc", str2="123";
    String sum=str1+str2;
    cout<<sum<<endl;
    String *p=new String();
    String str3="zxc";
    str1=str3;
    cout<<str1<<endl;
    return 0;
}
