#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    bool flag = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    vector<long long> prices;
    vector<long long> money;
    long long n, q, temp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        prices.push_back(temp);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        money.push_back(temp);
    }

    long long index, val;
    sort(prices.begin(), prices.end());
    for (int i = 0; i < q; i++)
    {
        bool found = false;
        if (money[i] < prices[0])
        {
            index = -1;
        }
        else
        {
            long long high = n-1;
            long long low = 0;
            

            while (low <= high)
            {
                long long mid = (high + low) / 2;

                //cout << "Mid: " << mid << " Low: " << low << " High: " << high;
                if (prices[mid] > money[i])
                {
                    high = mid-1;
                }
                else if (prices[mid] < money[i])
                {
                    low = mid+1;
                }
                else{
                    index = mid;
                    found = true;
                    break;
                }
            }

            if (low == high) index = low;
            if(!found) index = (high+low)/2;
        }

        cout << index+1 << endl;
    }

    return 0;
}