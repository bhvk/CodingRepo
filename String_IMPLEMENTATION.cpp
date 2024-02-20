//string
//https://www.geeksforgeeks.org/how-to-create-a-custom-string-class-in-c-with-basic-functionalities/

#include <iostream>
#include <utility>
#include <cstring>
#define CIN

using namespace std;

class String{
private:
    // char* buff = nullptr;
    // unsigned int len = 0;
    char* buff;
    unsigned int len;

public:
    // String(char* res, unsigned int l) : buff(res), len(l){
    //     cout<<"Parameterized Constructor called"<<endl;
    // }

    //Constructors
    String(): buff(nullptr), len(0){
        cout<<"DEFAULT CTOR"<<endl;
    }
    String(const char* str){
        // uint16_t l = strlen(str);
        // buff = new char[l+1];
        len = strlen(str);
        buff = new char[len+1];
        strcpy(buff, str);
        // len = l;
        cout<<"PARAMETERIZED CTOR"<<endl;
    }
    //****** Copy Semantics ******//
    //----Copy Ctor----//
    String(const String& other){
        this->len = other.len;
        buff = new char[this->len+1];
        strcpy(this->buff, other.buff);
        cout<<"COPY CTOR"<<endl;
    }

    //----Copy Assignment Operator----//
    String& operator=(const String& other){
        
        /*Forgot next 3 lines, initially I blindly copied the copy ctor here*/
        if(this != &other){
            cout<<"COPY ASSIGNMENT OPERATOR"<<endl;
            if(this->buff) //remove pre-existing string sitting at this buffer
                delete [] buff;

            this->len = other.len;
            buff = new char[this->len+1];
            strcpy(this->buff, other.buff);
        }
        return *this;
    }
    //******Move Semantics ******//
    //----Move Ctor----//
    String(String&& other){
        this->buff = other.buff;
        this->len = other.len;
        other.len = 0;
        other.buff = nullptr;
        cout<<"MOVE CONSTRUCTOR"<<endl;
    }
    //----Move Assignment----//
    String& operator=(String&& other){
        this->buff = other.buff;
        this->len = other.len;
        other.len = 0;
        other.buff = nullptr;
        cout<<"MOVE ASSIGNMENT OPERATOR"<<endl;
        return *this;
    }
    //******Destructor******//
    ~String(){
        if(this->buff){
            delete[] buff;
            this->buff = nullptr;
        }
        cout<<"DESTRUCTOR"<<endl;
    }

    //******Functions******//
    unsigned int Length(){
        return len;
    }
    
    //FRIENDS
    friend ostream& operator<<(ostream& out, const String& str);
#ifdef CIN    
    friend istream& operator>>(istream& in, const String& str);
#endif  
};
//-------------------FRIEND FUNCTIONS------------------------

ostream& operator<<(ostream& out, const String& str){
    out<<str.buff;
    return out;
}
#ifdef CIN
istream& operator>>(istream& in, String& str){
    // if(this->buff)
    //     delete[] buff;
    char *buff = new char[1000];
    // memset(&buff[0], 0, sizeof(buff)); //this was on geeksforgeeks
    // memset(buff, 0, sizeof(buff));
    memset(buff, 0, 1000*sizeof(buff[0]));
    in >> buff;

    str = String(buff);
    delete[] buff;
    // strcpy(str.buff, buff);
    return in;
    
}
#endif

//-------------------------------------------
int main()
{
    String x = "HELLO G"; //PARAMETERIZED !
    String y;
    String z = "DOMI"; //PARAMETERIZED !
    cout<<"Len of X = "<<x.Length()<<endl;
    cout<<"Len of Y = "<<y.Length()<<endl;

    String d = x; //copy constructor 

    y = x; //copy assignement operator
    // x = x; //copy assignement operator
    
    String p = std::move(z); //move Ctor
    cout<<"Z len = "<<z.Length()<<endl;
    
    String t;
    t = std::move(p); //move assignment operator
    
    cout<<"T len = "<<t.Length()<<endl;
    cout<<"P len = "<<p.Length()<<endl;

    cout<<"String x = "<<x<<", t = "<<t<<endl;
    String q;
    cin>>q;
    cout<<"String q = "<<q<<endl;
    //destructor to becalled for : x,y,z,d,t,p,q
}
