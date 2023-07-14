package main

import (
	"fmt"
)


func main() {
	var n, q, inp, mod, ans, l, r int64
	mod = 1000000007
	fmt.Scanf("%d %d", &n, &q)
	prefixSum := make([]int64, n+1, n+1)
	prefixSum[0] = 0
	for i:=int64(1); i<=n; i++{
		fmt.Scanf("%d", &inp)
		prefixSum[i] = (prefixSum[i-1]+(inp%mod))%mod
		if prefixSum[i] < 0 {
			prefixSum[i] = prefixSum[i] + mod
		}
	}

	for i:= int64(1); i<=q; i++ {
		fmt.Scanf("%d %d", &l, &r)
		ans = prefixSum[r]-prefixSum[l-1]
		if ans < 0 {
			ans = ans + mod
		}
		fmt.Printf("%d\n", ans)
	}
}
