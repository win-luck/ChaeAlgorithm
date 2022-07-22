import java.util.*;

public class Main {
    public static int[][] d;
    public static int INF=100000000;
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt(); // 유저와 친구관계의 수 입력
        d = new int[N+1][N+1];
              
        for(int i=0; i<d.length; i++) {
        	Arrays.fill(d[i], INF);
        	// 최초에 모두가 연결되어 있지 않으므로 INF
        }
        
        for(int a=1; a<=M; a++) {
        	int x = sc.nextInt();
        	int y = sc.nextInt();
        	d[x][y] = 1;
        	d[y][x] = 1;
        	// 연결되면 "1단계"를 의미함.
        }
        
       for(int k=1; k<=N; k++) {
    	   for(int i=1; i<=N; i++){
	           	for(int j=1; j<=N; j++) {
	           		if(d[i][j] > d[i][k] + d[k][j]) {
	           			d[i][j] = d[i][k] + d[k][j];
	           		}
	           	}
           }
       } // 플로이드 워셜 알고리즘
       
       int[] sum = new int[N+1];
       int min = Integer.MAX_VALUE; // 케빈베이컨 작은사람을 찾기위한 변수들
       int minindex = -1;
       
        for(int i=1; i<=N; i++) {
        	for(int j=1; j<=N; j++) {
        		sum[i] += d[i][j]; // i번 친구의 베이컨지수 계싼
        	}
        	if(sum[i] < min) { // 최솟값을 가진 친구를 찾는 과정
        		min = sum[i];
        		minindex = i;
        	}
        }
        System.out.println(minindex);
    }
}