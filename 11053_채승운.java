import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int N = sc.nextInt();
        int[] v = new int[N+1];
        int[] dp = new int[N+1];
        
        for(int i=1; i<=N; i++) { // 입력
        	v[i] = sc.nextInt();
        }
        
        /* N개 종류의 카드팩 중 N개 카드를 구매했을 때 금액이 최대가 되어야 한다.
        이때 N번째 카드팩은 N개 카드를 가지고 있다.
        N=1일 때 당연히 v[1]
        N=2일 때 v[1]*2 / v[2]
        // 둘 중 큰 것
        N=3일 때 v[1]*3 / v[2]+v[1] / v[3]
        // 이때 이미 1~2번째 사이에는 대소관계가 결정된 상태, 3번째랑만 비교하면 됨
        N=4일 때, v[1]*4 / v[2]+v[1]*2 / v[2]*2 / v[3]+v[1] / v[4] 
        이때 이미 1~4번째는 대소관계 결정된 상태 단지 1~4까지 차례대로 
        카드팩을 더해주며 대조하면 됨.
        
        */
        dp[1] = v[1]; // 1개는 당연히 첫 번째 카드가 최대이다.
        
        for(int i=1; i<=N; i++) {
        	for(int j=1; j<=i; j++) {
        		dp[i] = Math.max(dp[i], v[j]+dp[i-j]);
        	}
        }

        System.out.println(dp[N]);
    } 
}