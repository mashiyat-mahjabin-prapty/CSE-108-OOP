
                }
                else if (prices[mid] < money[i])
                {
                    low = mid+1;
                    if (prices[mid+1] > money[i])
                    {
                        index = mid;