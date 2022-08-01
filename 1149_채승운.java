import java.util.*;

public class Main {
	public static final int red = 0, green=1, blue=2;
	public static int[][] v;
	public static int[][] dp;
	// 색깔과 인덱스를 대응시켜 혼란 방지
	
	public static int sol(int N, int color) {
		/*
		 목표: dp[N]에서 빨강/파랑/초록 중 최솟값을 채택
		 서로 붙어있는 집은 같은 색깔을 가질 수 없기 때문에
		 Top-Down의 관점에서, dp[N][red]는 N번째가 빨강 -> N-1번째는 무조건 초록/파랑 + N번째 집의 빨강 값이다.	 
		*/	
		if(dp[N][color] == 0) { // 아직 색의 합계가 계산되지 않은 구간이라면 계산 돌입
			if(color == red) {
				dp[N][color] = Math.min(sol(N-1, green), sol(N-1, blue)) + v[N][color];
			} else if(color == green) {
				dp[N][color] = Math.min(sol(N-1, red), sol(N-1, blue)) + v[N][color];
			} else {
				dp[N][color] = Math.min(sol(N-1, green), sol(N-1, red)) + v[N][color];
			}	
		}
		
		return dp[N][color]; // 이미 계산되었다면 바로 반환
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int N = sc.nextInt();
        v = new int[N+1][3]; // 각 집의 칠하는 비용
        dp = new int[N+1][3]; // N번째 집까지 칠하는 비용의 합계, 최솟값이어야 함.
        
        for(int i=1; i<=N; i++) { // 입력
        	for(int j=red; j<=blue; j++) {
        		v[i][j] = sc.nextInt();
        		// N번째 집을 빨/초/파로 칠하는 비
        	}
        }
        
        dp[1][red] = v[1][red];
        dp[1][blue] = v[1][blue];
        dp[1][green] = v[1][green];
        // 초기값 설정
        
        int result = Math.min(sol(N, red), Math.min(sol(N,blue), sol(N, green)));
        // N번째 집이 빨/초/파인 경우를 나누어 그 중 최솟값 저장
        
        System.out.println(result);
    } 
}