#include<bits/stdc++.h>
using namespace std;

class Array
{
private :
    string *s;
    int length = 0;
    int capacity = 32;
public :

    Array()
    {
        this->s = new string[capacity];
    }


    Array(int n)
    {
        capacity = 2*n;
        this->s = new string[capacity];
    }

    Array(string a[],int length)
    {
        this->length = length;
        capacity  = 2*length;
        this->s = new string[capacity];
        for(int i = 0; i<this->length ; i++ )
        {
            s[i] = a[i];
        }
    }

    string* getArray()
    {
        return s;
    }

    string getAnElement(int i)
    {
        if(i>=length)
        {
            cout<<"Index is out of bound"<<endl;
            return "";
        }
        return s[i];
    }

    void add(string str)
    {
        if(length == capacity)
        {
            resize();
        }
        s[length++] = str;
    }

    void add(int i, string str)
    {
        //if(i<length) s[i] = str;
        //else cout<<"Index out of bound"<<endl;
        if(length == capacity)resize();
        string temp = s[i];
        s[i] = str;
        for(int j = length ; j>=i+2  ; j--)s[j] = s[j-1];
        s[i+1] = temp;
        length++;

    }

    void remove(string str)
    {
        int count = 0;
        for(int i = 0 ; i<length ; i++)
        {
            if(str == s[i])
            {
                s[i] = "";
                count++;
            }
            else
            {
                s[max(i-count,0)] = s[i];
                //s[i] = "";
            }
        }
        length -= count;
    }
    int getLength()
    {
        return length;
    }

    bool isEmpty()
    {
        if(length == 0)return true;
        return false;
    }

    void resize()
    {
        string temp[length];
        for(int i = 0; i<length ; i++ )temp[i] = s[i];
        delete[] s;
        capacity = 2*(length+1);
        s = new string[capacity];
        for(int i = 0; i<length ; i++ )s[i] = temp[i];
    }



    void findIndex(string str, int a[])
    {
        int count = 0;
        for(int i = 0 ; i<length ; i++)
        {
            if(s[i]==str)
            {
                a[++count] = i;
            }
        }
        a[0] = count;
    }

    void subArray(int start, int end, string a[])
    {
        if(start<0 || end >= length || start>end )
        {
            cout<<"Invalid Index"<<endl;
            return ;
        }
        for(int i = start ; i<=end ; i++)a[i-start]=s[i];
    }

    void merge(string a[],int length_of_a, string b[],int length_of_b)
    {
        int n = length_of_a + length_of_b;
        delete[] s;
        length = n;
        capacity = 2*n;
        s = new string[capacity];
        int j=0,k=0;
        for(int i = 0 ; i<n ; i++)
        {
            if(j == length_of_a)
            {
                s[i] = b[k++];
                continue;
            }
            if(k == length_of_b)
            {
                s[i] = a[j++];
                continue;
            }
            if(a[j]<=b[k])s[i]=a[j++];
            else s[i] = b[k++];
        }
    }

    ~Array()
    {
        delete[] s;
    }

};
