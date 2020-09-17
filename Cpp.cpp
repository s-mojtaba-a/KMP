#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void lps(const string &s, int arr[])
{
    int i = 0, j = 1, m = s.length();
    arr[0] = 0;
    while (j < m)
    {
        if (s[i] == s[j])
        {
            arr[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (!i)
            {
                arr[j] = 0;
                j++;
            }
            else
            {
                i = arr[i - 1];
            }
        }
    }
}

vector<int> kmp(const string &s1, const string &s2, int arr[])
{
    vector<int> ans;
    int n = s1.length(), m = s2.length();
    ans.reserve(n - m + 1);
    int i = 0, j = 0;
    while (j < n)
    {
        if (s1[j] == s2[i])
        {
            i++;
            j++;
        }
        else
        {
            if (i != 0)
                i = arr[i - 1];
            else
                j++;
        }
        if (i == m)
        {
            i = arr[i - 1];
            ans.push_back(j - m);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}


#### python impelemenation ### 
def lps(s):
    i = 0
    j = 0
    m = len(s)
    arr = [0]*m
    while j < m:
        if s[i] == s[j]:
            arr[j] = i+1
            i += 1
            j += 1
        else:
            if i == 0:
                arr[j] = 0
                j += 1
            else:
                i = arr[i-1]
    return(arr)


def kmp(s1, s2, arr):
    ans = []
    n = len(s1)
    m = len(s2)
    i = 0
    j = 0
    while j < n:
        if (s1[j] == s2[i]):
            i += 1
            j += 1
        else:
            if i != 0:
                i = arr[i-1]
            else:
                j += 1
        if i == m:
            i = arr[i-1]
            ans.append(j-m)
    return ans

