#include<bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &st)
{
    int temp;
    stack<int> s;
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        if(s.empty() || s.top() <= temp)
            s.push(temp);
        else
        {
            while(!s.empty() && s.top() > temp)
            {
                st.push(s.top());
                s.pop();
            }
            s.push(temp);
        }
    }
    while(!s.empty())
    {
        st.push(s.top());
        s.pop();
    }
}
int main()
{
    stack<int> myStack;
    int N;
    cout<<"Enter number of elements for stack... ";
    cin>>N;
    cout<<"Enter "<<N<<" elements...\n";
    int temp;
    while(N--)
    {
        cin>>temp;
        myStack.push(temp);
    }
    sortStack(myStack);
    cout<<"Stack after sorting is:\n";
    while(!myStack.empty())
    {
        cout<<myStack.top()<<' ';
        myStack.pop();
    }
    cout<<endl;
    return 0;
}