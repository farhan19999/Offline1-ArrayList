#include "ArrayList.cpp"
int main()
{
    Array books;

    books.add("The adventure of hucklberry finn");
    books.add("The adventure of tintin");
    books.add("The Great Gatsby");

    cout<<books.getLength()<<endl;
    if(!books.isEmpty())
    {
        cout<<"The elements of books List : "<<endl;
        for(int i = 0; i<books.getLength() ; i++)
        {
            cout<<books.getArray()[i]<<endl;
        }
        cout<<endl;
    }
    Array t(6);
    string s1[3] = {"ehfiufufho",
                    "iufhewoh",
                    "sfhiuhf"
                   };

    string s2[3] = {"ewuugsufigf",
                    "uisdhsjdsfnfh",
                    "dijfjdfg"
                   };
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);

    cout<<"The elements of s1 :"<<endl;
    for(auto s: s1)cout<<s<<endl;

    cout<<endl;

    cout<<"The elements of s2 :"<<endl;
    for(auto s: s2)cout<<s<<endl;

    cout<<endl;

    t.merge(s1,3,s2,3);
    if(!t.isEmpty())
    {
        cout<<"After merging s1 and s2 and populating array list t :"<<endl;
        for(int i = 0; i<t.getLength() ; i++)
        {
            cout<<t.getAnElement(i)<<endl;
        }
        cout<<endl;
    }

    string s3[] = {"the",
                   "catcher",
                   "in",
                   "the",
                   "rye"
                  };


    Array a2(s3,5);
    int n[10];
    a2.findIndex("the", n);

    cout<<"Elements of a2 : "<<endl;
    for(int i = 0 ;i<a2.getLength() ; i++)cout<<a2.getAnElement(i)<<endl;
    cout<<endl;

    cout<<"Index of 'the' in a2 : ";
    for(int i = 1; i<=n[0] ;i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl<<endl;


    int start = 1;
    int end = 3;
    string subarray[end-start+1];
    a2.subArray(start, end, subarray) ;
    cout<<"Subarray containing elements of Index starting from "<<start<<" to "<<end<<" of a2 : "<<endl;
    for(int i = 0; i<3 ; i++ )cout<<subarray[i]<<endl;
    cout<<endl;

    string rs = "the";
    a2.remove(rs);
    cout<<"Elements of a2 after removing '" << rs <<"' : "<<endl;
    a2.add(2, "be");
    for(int i = 0 ;i<a2.getLength() ; i++)cout<<a2.getAnElement(i)<<endl;


    return 0;
}
