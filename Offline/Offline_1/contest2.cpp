#include<bits/stdc++.h>
using namespace std;

void remove (int index, string &temp)
{
    string s;
    if (index == 0)
    {
        for (int i = 1; i < temp.length(); i++)
        {
            temp[i-1] = temp[i]; 
        }
    }
    temp.resize(temp.length()-1);    
}


int main()
{
    int tc;
    cin >> tc;
    
    for (int i = 1; i <= tc; i++)
    {
        string str;
        cin >> str;

        char current = 'I';
        bool noMove = false;

        while(str.length() != 0)
        {
            //cout << str << endl;
            if (noMove) break;
            if(str[0] == current && str[str.length()-1] == current)
            {
                if (str[1] == current)
                {
                    remove(0, str);
                }
                else if (str[str.length()-2] == current)
                {
                    remove(str.length()-1, str);
                }
                else
                {
                    remove(0, str);
                }
                current = (current=='I') ? 'O': 'I';
            }
            else if (str[0] == current)
            {
                remove(0, str);
                current = (current=='I') ? 'O': 'I';
            }
            else if (str[str.length()-1] == current)
            {
                remove(str.length()-1, str);
                current = (current=='I') ? 'O': 'I';
            }
            else
            {
                noMove = true;
                break;
            }    
        }
        if (str.length() == 0)
        {
            noMove = true;
        }
        if(noMove) 
        {
            current = (current=='I') ? 'O': 'I';
            cout << "Case #" << i << ": " << current << " " << str.length()+1 << endl; 
        }
    }
}