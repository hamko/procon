#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
 
LL n, a[112345];
bool zero_flag = false;
LL sum, res, ans, a_c[112345];
 
int main()
{
	in >> n;
	rep(i, n) { in >> a[i]; }
 
	std::copy(a, a + n, a_c);
	{
		if (a[0] == 0)
		{
			zero_flag = true;
			++res;
			a[0] = 1;
		}
		if (a[0] < 0)
		{
			res += abs(a[0]) * 2;
			a[0] *= -1;
		}
		sum = a[0];
		rep(i, n)
		{
			if (i == n - 1) { break; }
			if (sum <= 0 && sum + a[i + 1] <= 0)
			{
				LL want = abs(sum) + 1;
				res += abs(want - a[i + 1]);
				a[i + 1] = want;
			}
			else if (sum >= 0 && sum + a[i + 1] >= 0)
			{
				LL want = -(sum + 1);
				res += abs(a[i + 1] - want);
				a[i + 1] = want;
			}
			sum += a[i + 1];
		}
	}
	ans = res; res = 0;
	std::copy(a_c, a_c + n, a);
	{
		if (zero_flag)
		{
			++res;
			a[0] = -1;
		}
		if (a[0] > 0)
		{
			res += abs(a[0]) * 2;
			a[0] *= -1;
		}
		sum = a[0];
		rep(i, n)
		{
			if (i == n - 1) { break; }
			if (sum <= 0 && sum + a[i + 1] <= 0)
			{
				LL want = abs(sum) + 1;
				res += abs(want - a[i + 1]);
				a[i + 1] = want;
			}
			else if (sum >= 0 && sum + a[i + 1] >= 0)
			{
				LL want = -(sum + 1);
				res += abs(a[i + 1] - want);
				a[i + 1] = want;
			}
			sum += a[i + 1];
		}
	}
	ans = std::min(ans, res);
 
	out << ans << std::endl;
	return 0;
}
