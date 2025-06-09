#include <stdio.h>

int main(){
	int tt;
	scanf("%d", &tt);
	while(tt--){
		int n, k;
		scanf("%d%d", &n, &k);
		int a[n];
		for(int i = 0;i<n;i++){
			scanf("%d", &a[i]);
		}
		int f = 1, ans = 1;
		for(int i = 0;i<n;i++){
			if(a[i] == 1){
			  if(!f){
			    ans = 0;
			    break;
			  }
				f = 0;
				i += k - 1;
			}
		}
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
